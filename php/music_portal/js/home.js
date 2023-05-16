/* Media player */
/** Playlist **/
const music = [
  {
    path: "./../music/Of Monsters And Men  Little Talks Official Video.mp3",
    title: "Little talks",
    album: "",
    genre: "",
    author: "Of Monsters And Men"
  },
  {
    path: "./../music/Of Monsters And Men  Mountain Sound Official.mp3",
    title: "Mountain Sound",
    album: "",
    genre: "",
    author: "Of Monsters And Men"
  }
];
/** Title **/
const TITLE = document.getElementById("title");
/** Author **/
const AUTHOR = document.getElementById("author");
/** Controls **/
const PREVIOUS = document.getElementById("previous");
const PLAY = document.getElementById("play");
const PAUSE = document.getElementById("pause");
const NEXT = document.getElementById("next");
const TRACK = document.getElementById("track");
const PROGRESS = document.getElementById("progress");
var id_music = 0;
var audio = new Audio(music[id_music].path);
TITLE.innerHTML = music[id_music].title;
AUTHOR.innerHTML = music[id_music].author;
PLAY.addEventListener("click", function() {
  audio.play()
  PLAY.classList.add("hide-button");
  PAUSE.classList.remove("hide-button");
});
PAUSE.classList.add("hide-button");
PAUSE.addEventListener("click", function() {
  PLAY.classList.remove("hide-button");
  PAUSE.classList.add("hide-button");
  audio.pause();
});
PREVIOUS.addEventListener("click", function() {
  audio.pause();
  audio.currentTime = audio.duration;
  id_music = (id_music == 0) ? 0 : (id_music - 1);
  audio = new Audio(music[id_music].path);
  audio.play()
  .then(function() {
    TITLE.innerHTML = music[id_music].title;
    AUTHOR.innerHTML = music[id_music].author;
    PLAY.classList.add("hide-button");
    PAUSE.classList.remove("hide-button");
    progress(audio, TRACK, PROGRESS);
  })
  .catch(function(error) {
    console.log(error);
  });
  audio.addEventListener("ended", function() {
    PLAY.classList.remove("hide-button");
    PAUSE.classList.add("hide-button");
  });
});
NEXT.addEventListener("click", function() {
  audio.pause();
  audio.currentTime = audio.duration;
  id_music = (id_music == (music.length - 1)) ? (music.length - 1) : (id_music + 1);
  audio = new Audio(music[id_music].path);
  audio.play()
  .then(function() {
    TITLE.innerHTML = music[id_music].title;
    AUTHOR.innerHTML = music[id_music].author;
    PLAY.classList.add("hide-button");
    PAUSE.classList.remove("hide-button");
    progress(audio, TRACK, PROGRESS);
  })
  .catch(function(error) {
    console.log(error);
  });
  audio.addEventListener("ended", function() {
    PLAY.classList.remove("hide-button");
    PAUSE.classList.add("hide-button");
  });
});
/** Track **/
function progress(audio, TRACK, PROGRESS) {
  TRACK.addEventListener("mousedown", function(event) {
    var x_track = event.offsetX;
    var y_track = event.offsetY;
    audio.currentTime = ((x_track * audio.duration) / TRACK.offsetWidth).toFixed(5);
    //PROGRESS.style.width = ((x_track * 100) / TRACK.offsetWidth).toString() + "%";
  });
  audio.addEventListener("timeupdate", function() {
    PROGRESS.style.width = ((audio.currentTime * 100) / audio.duration).toString() + "%";
    //console.log(PROGRESS.style.width);
  });
}
audio.addEventListener("ended", function() {
  PLAY.classList.remove("hide-button");
  PAUSE.classList.add("hide-button");
});
progress(audio, TRACK, PROGRESS);