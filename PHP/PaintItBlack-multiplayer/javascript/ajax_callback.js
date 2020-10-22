let controlScript = "../PHP/jsonWrite.php";
let jsonFile = "../PHP/drawing.json";
let preloadJsonFile = "../PHP/preload.json";

function MakeAjaxCall(url, methodType) {
    let promiseObj = new Promise(function (resolve, reject) {
        console.log(url)

        let xmlHttp = new XMLHttpRequest();
        xmlHttp.open(methodType, url, true)
        xmlHttp.send();
        xmlHttp.onreadystatechange = function () {
            if (xmlHttp.readyState != 4) {
                // console.log("Bezig met ophalen");
                return;
            }
            if (xmlHttp.status != 200) {
                reject(xmlHttp);
                // console.log("er is iets fout gegaan")
                return;
            }
            // console.log("Succesvol");
            let serverResponse = xmlHttp.responseText;
            resolve(serverResponse);
        }
    });
    return promiseObj;
}

function errorHandler(statusCode){
    console.log("failed with status", status);
  }

function serverWriteJson(data) {
    // console.log("Updating server map");
    let drawingJsonString = JSON.stringify(data);
    let url = controlScript + "?put=" + drawingJsonString;
    MakeAjaxCall(url, "GET");
}

function serverGetJson() {
    MakeAjaxCall("../PHP/drawing.json", "GET").then(function (JSONresponse) {
        readJson(JSONresponse)
    });
}

function preload() {
  // hier komt jouw code
    MakeAjaxCall(preloadJsonFile, "GET").then(function (JSONresponse) {
        readJson(JSONresponse)
    });
}
