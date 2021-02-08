using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Coroutines : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        StartCoroutine(Coroutine1());
    }

    public IEnumerator Coroutine()
    {
        print("<color=green> Ik start nu de coroutine </color>");
        yield return new WaitForSeconds(.5f);
        print("<color=yellow> coroutine update </color>");
        yield return new WaitForSeconds(.5f);
        print("<color=red> coroutine einde </color>");
        yield return null;
    }
    
    public IEnumerator Coroutine1()
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
}
