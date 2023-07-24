const game = document.getElementById("game");
const play = document.getElementById("play");
const play_board = document.getElementById("play-board");
const current_level_element = document.getElementById("current-level");
const score_element = document.getElementById("score");
const high_score_element = document.getElementById("high-score");
const game_over_element = document.getElementById("game-over");
const snake_speed_element = document.getElementById("snake-speed");
const pause_element = document.getElementById("pause");
const btn_main_menu = document.querySelectorAll("#btn-main-menu");
const btn_restart = document.querySelectorAll("#restart");
const main_menu = document.getElementById("main-menu");
const btn_play = document.getElementById("btn-play");
const btn_ajustes = document.getElementById("btn-ajustes");
const btn_how_to_play = document.getElementById("btn-how-to-play");
const btn_volver_atras = document.getElementById("btn-volver-atras");
const sub_menu_1 = document.getElementById("sub-menu-1");
const sub_menu_2 = document.getElementById("sub-menu-2");
const sub_menu_3 = document.getElementById("sub-menu-3");
const sub_menu_4 = document.getElementById("sub-menu-4");
const btn_levels = document.querySelectorAll(".level");
let game_over = true;
let stop_game = true;
let food_x, food_y;
let snake_x = 5, snake_y = 10;
let snake_body = [];
let velocity_snake = {
  "slow": 180,
  "normal": 120,
  "fast": 60
};
let current_velocity = velocity_snake[snake_speed_element.value];
let velocity_x = 0, velocity_y = 0;
let set_interval_id;
let score = 0;
let high_score = parseInt(localStorage.getItem("high-score") || 0);
high_score_element.innerHTML = `High Score: ${high_score}`;
let current_level = 1;
const levels = {
  1: {
    object_data: ``,
    collision: function() {},
    verifyFoodPosition: function() {}
  },
  2: {
    object_data: `<div class="wall" style="grid-area: 9 / 9 / 10 / 23"></div>
                  <div class="wall" style="grid-area: 21 / 9 / 22 / 23"></div>`,
    collision: function() {
      if (snake_x >= 9 && snake_x <= 22) {
        if ([9, 21].includes(snake_y)) {
          game_over = true;
        }
      }
    },
    verifyFoodPosition: function() {
      if (food_x >= 9 && food_x <= 22) {
        if ([9, 21].includes(food_y)) {
          return false;
        }
      }
      return true;
    }
  },
  3: {
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
    },
    verifyFoodPosition: function() {
      if (food_x >= 9 && food_x <= 22) {
        if ([6, 12, 18, 24].includes(food_y)) {
          return false;
        }
      }
      return true;
    }
  },
  4: {
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
    },
    verifyFoodPosition: function() {
      if (food_x >= 9 && food_x <= 22) {
        if ([6, 12, 18, 24].includes(food_y)) {
          return false;
        }
      }
      return true;
    }
  },
  5: {
    object_data: `<div class="wall" style="grid-area: 9 / 12 / 10 / 20"></div>
                  <div class="wall" style="grid-area: 8 / 6 / 24 / 7"></div>
                  <div class="wall" style="grid-area: 15 / 12 / 16 / 20"></div>
                  <div class="wall" style="grid-area: 8 / 25 / 24 / 26"></div>
                  <div class="wall" style="grid-area: 22 / 12 / 23 / 20"></div>`,
    collision: function() {
      if (snake_x >= 12 && snake_x <= 19) {
        if ([9, 15, 22].includes(snake_y)) {
          game_over = true;
        }
      }
      if (snake_y >= 8 && snake_y <= 23) {
        if ([6, 25].includes(snake_x)) {
          game_over = true;
        }
      }
    },
    verifyFoodPosition: function() {
      if (food_x >= 12 && food_x <= 19) {
        if ([9, 15, 22].includes(food_y)) {
          return false;
        }
      }
      if (food_y >= 8 && food_y <= 23) {
        if ([6, 25].includes(food_x)) {
          return false;
        }
      }
      return true;
    }
  }
};
const changeFoodPosition = function() {
  do {
    food_x = Math.floor(Math.random() * (29 - 2 + 1) + 2);
    food_y = Math.floor(Math.random() * (29 - 2 + 1) + 2);
  } while (levels[current_level].verifyFoodPosition() === false);
};
const handleGameOver = function() {
  clearInterval(set_interval_id);
  game_over_element.style.display = "flex";
  stop_game = true;
}
const snakeGame = function() {
  if (game_over) {
    return handleGameOver();
  }
  let html_markup = `<div class="food" style="grid-area: ${food_y} / ${food_x}"></div>`;
  html_markup += `<div class="wall" style="grid-area: 1 / 1 / 2 / 31"></div>`;
  html_markup += `<div class="wall" style="grid-area: 1 / 30 / 31 / 31"></div>`;
  html_markup += `<div class="wall" style="grid-area: 30 / 1 / 31 / 31"></div>`;
  html_markup += `<div class="wall" style="grid-area: 1 / 1 / 31 / 2"></div>`;
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
  if (snake_x <= 1 || snake_x > 29 || snake_y <= 1 || snake_y > 29) {
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
btn_main_menu.forEach((e, i, a) => {
  e.addEventListener("click", (event) => {
    main_menu.style.display = "flex";
    sub_menu_1.style.display = "flex";
    play.style.display = "none";
    game.style.backgroundImage = "url(./img/wallpaper-1.jpg)";
    game_over = true;
    stop_game = true;
    let bmm_attr = parseInt(e.getAttribute("nb"));
    if (bmm_attr === 2) {
      game_over_element.style.display = "none";
    }
    else if (bmm_attr === 3) {
      pause_element.style.display = "none";
    }
    clearInterval(set_interval_id);
  });
});
btn_restart.forEach((e, i, a) => {
  e.addEventListener("click", (event) => {
    clearInterval(set_interval_id);
    let bmm_attr = parseInt(e.getAttribute("nb"));
    if (bmm_attr === 1) {
      game_over_element.style.display = "none";
    }
    else if (bmm_attr === 2) {
      pause_element.style.display = "none";
    }
    snake_x = 5, snake_y = 10;
    snake_body = [];
    velocity_x = velocity_y = 0;
    score = 0;
    score_element.innerHTML = `Score: ${score}`;
    game_over = false;
    stop_game = false;
    changeFoodPosition();
    set_interval_id = setInterval(() => {
      if (!stop_game) {
        snakeGame();
      }
    }, current_velocity);
  });
});
btn_play.addEventListener("click", () => {
  sub_menu_1.style.display = "none";
  sub_menu_2.style.display = "flex";
  btn_volver_atras.style.display = "block";
});
btn_ajustes.addEventListener("click", () => {
  sub_menu_1.style.display = "none";
  sub_menu_3.style.display = "flex";
  btn_volver_atras.style.display = "block";
});
btn_how_to_play.addEventListener("click", () => {
  sub_menu_1.style.display = "none";
  sub_menu_4.style.display = "flex";
  btn_volver_atras.style.display = "block";
});
btn_volver_atras.addEventListener("click", () => {
  btn_volver_atras.style.display = "none";
  sub_menu_1.style.display = "flex";
  sub_menu_2.style.display = "none";
  sub_menu_3.style.display = "none";
  sub_menu_4.style.display = "none";
});
snake_speed_element.addEventListener("change", () => {
  current_velocity = velocity_snake[snake_speed_element.value];
});
btn_levels.forEach((e, i, a) => {
  e.addEventListener("click", (event) => {
    play.style.display = "block";
    sub_menu_2.style.display = "none";
    main_menu.style.display = "none";
    btn_volver_atras.style.display = "none";
    game.style.backgroundImage = "url(./img/wallpaper-2.jpg)";
    snake_x = 5, snake_y = 10;
    snake_body = [];
    velocity_x = velocity_y = 0;
    score = 0;
    game_over = false;
    stop_game = false;
    current_level = parseInt(e.getAttribute("level"));
    current_level_element.innerHTML = `Level: ${current_level}`;
    set_interval_id = setInterval(() => {
      if (!stop_game) {
        snakeGame();
      }
    }, current_velocity);
  });
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
  if (!game_over) {
    if (!stop_game) {
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
    }
    if (e.keyCode === 32) {
      if (!stop_game) {
        stop_game = true;
        pause_element.style.display = "flex";
      }
      else {
        stop_game = false;
        pause_element.style.display = "none";
      }
    }
  }
});