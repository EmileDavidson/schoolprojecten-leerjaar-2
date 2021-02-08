using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Random = UnityEngine.Random;

public class Coroutines : MonoBehaviour
{
    [SerializeField] private float fadeWaitTime;
    [SerializeField] private Renderer renderer;
    [SerializeField] private float moveTime;
    [SerializeField] private GameObject gameObject;
    // Start is called before the first frame update
    void Start()
    {
    }

    private void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space))
        {
            StartCoroutine(RandomlyMove());
        }
    }

    private IEnumerator Coroutine()
    {
        print("<color=green> Ik start nu de coroutine </color>");
        yield return new WaitForSeconds(.5f);
        print("<color=yellow> coroutine update </color>");
        yield return new WaitForSeconds(.5f);
        print("<color=red> coroutine einde </color>");
        yield return null;
    }
    
    private IEnumerator Coroutine1()
    {
        print("<color=green> Ik start nu de coroutine </color>");
        yield return new WaitForSeconds(.5f);
        for (int i = 0; i < 10; i++)
        {
            print("<color=yellow> coroutine update </color>");
            yield return new WaitForSeconds(.5f);
        }
        print("<color=red> coroutine einde </color>");
        yield return null;
    }

    private IEnumerator FadeIn()
    {
        print("<color=green> Ik start nu met fade </color>");
        for (float ft = 1f; ft >= 0; ft -= 0.1f)
        {
            Color c = renderer.material.color;
            c.a = ft;
            renderer.material.color = c;
            print("<color=yellow> Fading </color>");
            yield return new WaitForSeconds(fadeWaitTime);
        }
        print("<color=red> Stop fading </color>");
        yield return null;
    }

    IEnumerator RandomlyMove()
    {
        Vector3 Gotoposition = this.transform.position += new Vector3(Random.Range(0, 10), Random.Range(0, 10), Random.Range(0, 10));
        float elapsedTime = 0;
        float waitTime = 3f;
        Vector3 currentPos = gameObject.transform.position;
        
        while (elapsedTime < waitTime)
        {
            gameObject.transform.position = Vector3.Lerp(currentPos, Gotoposition, (elapsedTime / waitTime));
            elapsedTime += Time.deltaTime;
            yield return null;
        }  
        // Make sure we got there
        gameObject.transform.position = Gotoposition;
        yield return null;
    }
}
