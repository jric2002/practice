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
    .resultados {
      color: white;
      padding: 1rem;
    }
    .resultados .card {
      background-color: var(--black-color-5);
      border-radius: 10px;
      display: flex;
      justify-content: flex-start;
      align-items: center;
      padding: 1rem;
    }
    .resultados .card .info {
      grid-area: info;
      width: 150px;
      display: flex;
      justify-content: center;
      align-items: center;
    }
    /** Cover **/
    .resultados .card .info .cover {
      width: 50px;
      border-radius: 20px;
      box-shadow: 0 10px 20px 5px rgba(0, 0, 0, 0.75);
      margin: 1.25rem 0 1.75rem;
    }
    /** Title **/
    .resultados .card .info .data .title {
      color: var(--white-color);
      margin: 1rem;
    }
    /** Author **/
    .resultados .card .info .data .author {
      color: var(--white-color);
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
        <h1 class="title" id="title">Title</h1>
        <!-- Author -->
        <h4 class="author" id="author">Author</h3>
      </div>
    </div>
    `;
  }
}

window.customElements.define("song-card", Card);
export { Card };