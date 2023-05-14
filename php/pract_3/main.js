const QUERY = document.getElementById("query");
const QUERY_BUTTON = document.getElementById("query-button");
const DELETE_BUTTON = document.getElementById("delete-button");
const QUERY_STRING = document.getElementById("query-string");
const RESPONSE = document.getElementById("response");
const URL = "http://localhost/";
async function requestPost(url = "", data = {}) {
  const response = await fetch(url, {
    method: "POST",
    headers: {
      "Content-Type": "application/json"
    },
    body: JSON.stringify(data)
  });
  return response.json();
}
QUERY_BUTTON.addEventListener("click", function() {
  let q = (QUERY.value).toString();
  QUERY_STRING.innerHTML = q;
  requestPost(URL + "/sql.php", {
    query: q
  }).then(r => {
    response.innerHTML = "";
    let i = 1;
    for (let d of r["data"]) {
      response.innerHTML += i.toString() + " REGISTRO<br/>";
      for (k in d) {
        response.innerHTML += "&nbsp;&nbsp;&nbsp;" + k + " -> " + d[k] + "</br>";
      }
      i++;
    }
  })
  .catch(error => {
    response.innerHTML = "Ha ocurrido un error";
    console.log(error);
  });
});