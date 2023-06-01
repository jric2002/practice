/* Radio */
const RADIO = document.getElementById("radio");

/** Change background **/
var image_number = 1;
var amount_images = 3;
var time_change = 1800; // Value in seconds
var time_in_milliseconds = time_change * 1000;
setTimeout(function() {
  RADIO.classList.add("image-transition");
}, 3000);
setInterval(function() {
  RADIO.classList.remove("image-" + image_number.toString());
  image_number += 1;
  if (image_number == (amount_images + 1)) {
    image_number = 1;
  }
  RADIO.classList.add("image-" + image_number.toString());
}, time_in_milliseconds);

/** Spotify - Player **/
/* window.onSpotifyIframeApiReady = (IFrameAPI) => {
  let element = document.getElementById('spotify-player');
  let options = {
    width: "300",
    height: "250",
    uri: "spotify:episode:7makk4oTQel546B0PZlDM5"
  };
  let callback = (EmbedController) => {
    document.querySelectorAll('ul#episodes > li > button').forEach(episode => {
      episode.addEventListener('click', () => {
        EmbedController.loadUri(episode.dataset.spotifyId);
        // click event handler logic goes here
      });
    });
  };
  IFrameAPI.createController(element, options, callback);
}; */
/** Audio **/
/*
const radio_station = {
  host: "127.0.0.1",
  port: 3000
};
// const url = "http://" + radio_station.host + ":" + (radio_station.port).toString() + "/live/audio";
const url = "https://radios.yanapak.org/music-life";
const audio = new Audio(url);
*/
/*** Controls ***/
/*
const PLAY = document.getElementById("play");
const PAUSE = document.getElementById("pause");
const VOLUME_UP = document.getElementById("volume-up");
const VOLUME_MUTE = document.getElementById("volume-mute");
const VOLUME_RANGE = document.getElementById("volume-range");
var volume_value = VOLUME_RANGE.value / VOLUME_RANGE.max;
PLAY.addEventListener("click", function() {
  PLAY.classList.add("hide-button");
  PAUSE.classList.remove("hide-button");
});
PAUSE.addEventListener("click", function() {
  PAUSE.classList.add("hide-button");
  PLAY.classList.remove("hide-button");
});
VOLUME_UP.addEventListener("click", function() {
  VOLUME_UP.classList.add("hide-button");
  VOLUME_RANGE.value = 0;
  audio.volume = 0;
  VOLUME_MUTE.classList.remove("hide-button");
});
VOLUME_MUTE.addEventListener("click", function() {
  VOLUME_MUTE.classList.add("hide-button");
  VOLUME_RANGE.value = volume_value * VOLUME_RANGE.max;
  audio.play();
  audio.volume = volume_value;
  VOLUME_UP.classList.remove("hide-button");
});
VOLUME_RANGE.addEventListener("change", function() {
  volume_value = parseFloat(VOLUME_RANGE.value / VOLUME_RANGE.max);
  audio.pause();
  audio.volume = volume_value;
  if (volume_value == 0) {
    VOLUME_UP.classList.add("hide-button");
    VOLUME_RANGE.value = 0;
    VOLUME_MUTE.classList.remove("hide-button");
  }
  else {
    VOLUME_MUTE.classList.add("hide-button");
    VOLUME_RANGE.value = volume_value * VOLUME_RANGE.max;
    VOLUME_UP.classList.remove("hide-button");
  }
});
*/