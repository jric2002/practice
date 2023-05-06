class Card extends HTMLElement {
  constructor(id, title, artist) {
    super();
    this.id = id;
    this.title = title;
    this.artist = artist;
    this.attachShadow({mode: "open"});
  }
  static get styles() {
    return `
    :host {
      color: white;
      padding: 1rem;
    }
    .card {
      border-radius: 10px;
      display: flex;
      justify-content: flex-start;
      align-items: center;
      padding: 1rem;
    }
    .card:hover {
      background-color: var(--black-color-5);
    }
    /** Cover **/
    .card .cover {
      width: 50px;
      border-radius: 20px;
      box-shadow: 0 10px 20px 5px rgba(0, 0, 0, 0.75);
      margin: 1.25rem 0 1.75rem;
    }
    /** Title **/
    .card .data .title {
      margin: 1rem;
    }
    `;
  }
  connectedCallback() {
    this.render();
  }
  render() {
    this.shadowRoot.innerHTML = `
    <style type="text/css">${Card.styles}</style>
    <div class="card">
      <!-- Cover -->
      <img src="./img/cover.jpg" class="cover" alt="Cover"/>
      <div class="data">
        <!-- Title -->
        <h1 class="title" id="title">${this.title}</h1>
        <!-- Author -->
        <h4 class="author" id="author">${this.artist}</h3>
      </div>
    </div>
    `;
  }
}
window.customElements.define("song-card", Card);
const URL = "http://localhost/";
const BUTTON_SEARCH = document.getElementById("search");
async function requestPost(url, data = {}) {
  try {
    const RESPONSE = await fetch(url, {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify(data)
    });
    return RESPONSE.json();
  }
  catch(error) {
    return error;
  }
}
function getSongs() {
  requestPost(URL + "search", data = {
    song: BUTTON_SEARCH.value.toLowerCase()
  }).then(function(data) {
    console.log(data[0]);
    for (d of data) {
      card = new Card(d["id"], d["title"], d["name"]);
      RESULTADOS.appendChild(card);
    }
  });
}
getSongs();
const RESULTADOS = document.getElementById("resultados");
BUTTON_SEARCH.addEventListener("input", function() {
  RESULTADOS.innerHTML = "";
  getSongs();
});