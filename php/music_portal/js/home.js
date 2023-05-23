const PROTOCOL = window.location.protocol;
const HOSTNAME = window.location.hostname;
const PORT = (window.location.port == '') ? window.location.port : ":" + window.location.port;
const URL = PROTOCOL + "//" + HOSTNAME + PORT;
/* Media player */
/** Cover **/
const COVER = document.getElementById("cover");
/** Song name **/
const SONG_NAME = document.getElementById("song-name");
/** Artist **/
const ARTIST = document.getElementById("artist");
/** Play song **/
const PLAY_SONG = document.querySelectorAll(".play-song");
/** Controls **/
const PREVIOUS = document.getElementById("previous");
const PLAY = document.getElementById("play");
const PAUSE = document.getElementById("pause");
const NEXT = document.getElementById("next");
const TRACK = document.getElementById("track");
const PROGRESS = document.getElementById("progress");
const CURRENT_TIME = document.getElementById("current-time");
const END_TIME = document.getElementById("end-time");
const VOLUME = document.getElementById("volume");
var id_music = 0;
var audio = new Audio();
function playSong() {
  audio.play()
  PLAY.classList.add("hide-button");
  PAUSE.classList.remove("hide-button");
}
PLAY.addEventListener("click", playSong);
PAUSE.classList.add("hide-button");
PAUSE.addEventListener("click", function() {
  PLAY.classList.remove("hide-button");
  PAUSE.classList.add("hide-button");
  audio.pause();
});
NEXT.addEventListener("click", function() {
  audio.currentTime += 5
});
PREVIOUS.addEventListener("click", function() {
  audio.currentTime -= 5
});
function showButtonVolume(vol) {
  let vol_par = VOLUME.parentElement;
  vol = vol * 100;
  if (vol >= 75) {
    vol_par.insertAdjacentHTML("afterbegin", "<svg id=\"volume-1\" aria-hidden=\"true\" focusable=\"false\" data-prefix=\"fas\" data-icon=\"volume-up\" class=\"svg-inline--fa fa-volume-up fa-w-18\" role=\"img\" xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 576 512\"><path fill=\"currentColor\" d=\"M215.03 71.05L126.06 160H24c-13.26 0-24 10.74-24 24v144c0 13.25 10.74 24 24 24h102.06l88.97 88.95c15.03 15.03 40.97 4.47 40.97-16.97V88.02c0-21.46-25.96-31.98-40.97-16.97zm233.32-51.08c-11.17-7.33-26.18-4.24-33.51 6.95-7.34 11.17-4.22 26.18 6.95 33.51 66.27 43.49 105.82 116.6 105.82 195.58 0 78.98-39.55 152.09-105.82 195.58-11.17 7.32-14.29 22.34-6.95 33.5 7.04 10.71 21.93 14.56 33.51 6.95C528.27 439.58 576 351.33 576 256S528.27 72.43 448.35 19.97zM480 256c0-63.53-32.06-121.94-85.77-156.24-11.19-7.14-26.03-3.82-33.12 7.46s-3.78 26.21 7.41 33.36C408.27 165.97 432 209.11 432 256s-23.73 90.03-63.48 115.42c-11.19 7.14-14.5 22.07-7.41 33.36 6.51 10.36 21.12 15.14 33.12 7.46C447.94 377.94 480 319.54 480 256zm-141.77-76.87c-11.58-6.33-26.19-2.16-32.61 9.45-6.39 11.61-2.16 26.2 9.45 32.61C327.98 228.28 336 241.63 336 256c0 14.38-8.02 27.72-20.92 34.81-11.61 6.41-15.84 21-9.45 32.61 6.43 11.66 21.05 15.8 32.61 9.45 28.23-15.55 45.77-45 45.77-76.88s-17.54-61.32-45.78-76.86z\"></path></svg>");
  }
  else if (vol >= 25) {
    vol_par.insertAdjacentHTML("afterbegin", "<svg id=\"volume-2\" aria-hidden=\"true\" focusable=\"false\" data-prefix=\"fas\" data-icon=\"volume-down\" class=\"svg-inline--fa fa-volume-down fa-w-12\" role=\"img\" xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 384 512\"> <path fill=\"currentColor\" d=\"M215.03 72.04L126.06 161H24c-13.26 0-24 10.74-24 24v144c0 13.25 10.74 24 24 24h102.06l88.97 88.95c15.03 15.03 40.97 4.47 40.97-16.97V89.02c0-21.47-25.96-31.98-40.97-16.98zm123.2 108.08c-11.58-6.33-26.19-2.16-32.61 9.45-6.39 11.61-2.16 26.2 9.45 32.61C327.98 229.28 336 242.62 336 257c0 14.38-8.02 27.72-20.92 34.81-11.61 6.41-15.84 21-9.45 32.61 6.43 11.66 21.05 15.8 32.61 9.45 28.23-15.55 45.77-45 45.77-76.88s-17.54-61.32-45.78-76.87z\"></path> </svg>");
  }
  else if (vol >= 5) {
    vol_par.insertAdjacentHTML("afterbegin", "<svg id=\"volume-3\" aria-hidden=\"true\" focusable=\"false\" data-prefix=\"fas\" data-icon=\"volume-off\" class=\"svg-inline--fa fa-volume-off fa-w-8\" role=\"img\" xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 256 512\"> <path fill=\"currentColor\" d=\"M215 71l-89 89H24a24 24 0 0 0-24 24v144a24 24 0 0 0 24 24h102.06L215 441c15 15 41 4.47 41-17V88c0-21.47-26-32-41-17z\"></path> </svg>");
  }
  else {
    vol_par.insertAdjacentHTML("afterbegin", "<svg id=\"volume-4\" aria-hidden=\"true\" focusable=\"false\" data-prefix=\"fas\" data-icon=\"volume-mute\" class=\"svg-inline--fa fa-volume-mute fa-w-16\" role=\"img\" xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"0 0 512 512\"> <path fill=\"currentColor\" d=\"M215.03 71.05L126.06 160H24c-13.26 0-24 10.74-24 24v144c0 13.25 10.74 24 24 24h102.06l88.97 88.95c15.03 15.03 40.97 4.47 40.97-16.97V88.02c0-21.46-25.96-31.98-40.97-16.97zM461.64 256l45.64-45.64c6.3-6.3 6.3-16.52 0-22.82l-22.82-22.82c-6.3-6.3-16.52-6.3-22.82 0L416 210.36l-45.64-45.64c-6.3-6.3-16.52-6.3-22.82 0l-22.82 22.82c-6.3 6.3-6.3 16.52 0 22.82L370.36 256l-45.63 45.63c-6.3 6.3-6.3 16.52 0 22.82l22.82 22.82c6.3 6.3 16.52 6.3 22.82 0L416 301.64l45.64 45.64c6.3 6.3 16.52 6.3 22.82 0l22.82-22.82c6.3-6.3 6.3-16.52 0-22.82L461.64 256z\"></path> </svg>");
  }
}
showButtonVolume(parseFloat(VOLUME.value));
VOLUME.addEventListener("input", (event) => {
  audio.volume = event.target.value;
  let svg = (VOLUME.parentElement).getElementsByTagName("svg");
  svg[0].remove();
  showButtonVolume(event.target.value);
});
/** Get Time **/
function getTime(seconds) {
  let s = Math.ceil(seconds);
  let h = parseInt(s/3600);
  s = s % 3600;
  let m = parseInt(s/60);
  s = s % 60;
  h = (h < 10) ? "0" + h.toString() : h;
  m = (m < 10) ? "0" + m.toString() : m;
  s = (s < 10) ? "0" + s.toString() : s;
  let time = [h, m, s];
  return time.join(":");
}
/** Track **/
function progress(audio, TRACK, PROGRESS) {
  TRACK.addEventListener("mousedown", function(event) {
    var x_track = event.offsetX;
    var y_track = event.offsetY;
    audio.currentTime = ((x_track * audio.duration) / TRACK.offsetWidth).toFixed(5);
    //PROGRESS.style.width = ((x_track * 100) / TRACK.offsetWidth).toString() + "%";
  });
  audio.addEventListener("timeupdate", function() {
    CURRENT_TIME.innerHTML = getTime(audio.currentTime);
    PROGRESS.style.width = ((audio.currentTime * 100) / audio.duration).toString() + "%";
    //console.log(PROGRESS.style.width);
  });
}
audio.addEventListener("ended", function() {
  PAUSE.classList.add("hide-button");
  PLAY.classList.remove("hide-button");
});
PLAY_SONG.forEach(ps => {
  ps.addEventListener("click", function(event) {
    audio.pause();
    let song_path = URL + "/songs/" + ps.getAttribute("id") + "/" + ps.getAttribute("name");
    // console.log(encodeURI(song_path));
    audio = new Audio(encodeURI(song_path));
    playSong();
    progress(audio, TRACK, PROGRESS);
    data = (((ps.parentElement.children)[0].children)[1].children);
    END_TIME.innerHTML = data[2].textContent;
    COVER.src = "./songs/" + ps.getAttribute("id") + "/cover.jpg";
    SONG_NAME.innerHTML = data[0].textContent;
    ARTIST.innerHTML = data[1].textContent;
  });
});