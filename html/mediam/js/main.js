/* HEADER */
const menuBtn = document.getElementById("menu-btn");
const menuIcon = document.getElementById("menu-icon");
const menu = document.getElementById("menu");

let a = 0;
menuBtn.addEventListener("click", function() {
  if (a == 0) {
    menu.classList.add("show");
    menuIcon.classList.remove("fa", "fa-bars");
    menuIcon.classList.add("fa", "fa-close");
    a = 1;
  }
  else {
    menu.classList.remove("show");
    menuIcon.classList.remove("fa", "fa-close");
    menuIcon.classList.add("fa", "fa-bars");
    a = 0;
  }
});

/* SECTIONS */
const wallpaper = document.getElementById("wallpaper");
let b = 1;
wallpaper.classList.add("image-1");
setTimeout(function() {
  wallpaper.classList.add("transition-animation");
}, 5000);
setInterval(function() {
  wallpaper.classList.remove("image-" + String(b));
  b++;
  if (b == 4) {
    b = 1;
  }
  wallpaper.classList.add("image-" + String(b));
}, 5000);