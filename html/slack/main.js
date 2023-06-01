/* HEADER */
const menuBtn = document.getElementById("menu-btn");
const menu = document.getElementById("menu");
let a = 0;
menuBtn.addEventListener("click", function() {
  if (a == 0) {
    menu.classList.add("show");
    a = 1;
  }
  else {
    menu.classList.remove("show");
    a = 0;
  }
});