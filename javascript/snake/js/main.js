const play_board = document.getElementById("play-board");
const score_element = document.getElementById("score");
const high_score_element = document.getElementById("high-score");
const game_over_element = document.getElementById("game-over");
const btn_main_menu = document.getElementById("btn-main-menu");
const main_menu = document.getElementById("main-menu");
let game_over = false;
let stop_game = false;
let food_x, food_y;
let snake_x = 5, snake_y = 10;
let snake_body = [];
let velocity_x = 0, velocity_y = 0;
let set_interval_id;
let score = 0;
let high_score = parseInt(localStorage.getItem("high-score") || 0);
high_score_element.innerHTML = `High Score: ${high_score}`;
let current_level = 0;
const changeFoodPosition = function() {
  food_x = Math.floor(Math.random() * 30) + 1;
  food_y = Math.floor(Math.random() * 30) + 1;
};
const handleGameOver = function() {
  clearInterval(set_interval_id);
  game_over_element.style.display = "flex";

}
const levels = {
  0: {
    object_data: ``,
    collision: function() {}
  },
  1: {
    object_data: `<div class="wall" style="grid-area: 6 / 9 / 7 / 23"></div>
                  <div class="wall" style="grid-area: 12 / 9 / 13 / 23"></div>
                  <div class="wall" style="grid-area: 18/ 9 / 19 / 23"></div>
                  <div class="wall" style="grid-area: 24 / 9 / 25 / 23"></div>`,
    collision: function() {
      if (snake_x >= 9 && snake_x <= 22) {
        if ([6, 12, 18, 24].includes(snake_y)) {
          game_over = true;
        }
      }
    }
  }
}
const initGame = function() {
  if (game_over) {
    return handleGameOver();
  }
  let html_markup = `<div class="food" style="grid-area: ${food_y} / ${food_x}"></div>`;
  if (snake_x === food_x && snake_y === food_y) {
    changeFoodPosition();
    snake_body.push([food_x, food_y]);
    score++;
    if (score >= high_score) {
      high_score = score;
      localStorage.setItem("high-score", high_score);
      high_score_element.innerHTML = `High Score: ${high_score}`;
    }
    score_element.innerHTML = `Score: ${score}`;
  }
  for (let i = snake_body.length -1; i > 0; i--) {
    snake_body[i] = snake_body[i - 1];
  }
  snake_body[0] = [snake_x, snake_y];
  snake_x += velocity_x;
  snake_y += velocity_y;
  // Colisiones generales
  if (snake_x <= 0 || snake_x > 30 || snake_y <= 0 || snake_y > 30) {
    game_over = true;
  }
  // Colisiones del nivel actual
  levels[current_level].collision();
  html_markup += levels[current_level].object_data;
  for (let i = 0; i < snake_body.length; i++) {
    let s_part = (i === 0) ? "s-head" : "s-body";
    html_markup += `<div class="snake ${s_part}" style="grid-area: ${snake_body[i][1]} / ${snake_body[i][0]}"></div>`;
    if (i !== 0 && snake_body[0][1] === snake_body[i][1] && snake_body[0][0] === snake_body[i][0]) {
      game_over = true;
    }
  }
  play_board.innerHTML = html_markup;
};
changeFoodPosition();
set_interval_id = setInterval(() => {
  if (!stop_game) {
    initGame();
  }
}, 120);
btn_main_menu.addEventListener("click", () => {
  main_menu.style.display = "flex";
  stop_game = true;
});
document.addEventListener("keydown", (e) => {
  //w = 87
  //a = 65
  //s = 83
  //d = 68
  //ArrowUp = 38
  //ArrowLeft = 37
  //ArrowDown = 40
  //ArrowRight = 39
  // console.log(e);
  if ((e.keyCode === 87 || e.keyCode === 38) && velocity_y != 1) {
    velocity_x = 0;
    velocity_y = -1;
  }
  else if ((e.keyCode === 83 || e.keyCode === 40) && velocity_y != -1) {
    velocity_x = 0;
    velocity_y = 1;
  }
  else if ((e.keyCode === 65 || e.keyCode === 37) && velocity_x != 1) {
    velocity_x = -1;
    velocity_y = 0;
  }
  else if ((e.keyCode === 68 || e.keyCode === 39) && velocity_x != -1) {
    velocity_x = 1;
    velocity_y = 0;
  }
  else if (e.keyCode === 32) {
    if (!stop_game) {
      stop_game = true;
    }
    else {
      stop_game = false;
    }
  }
});