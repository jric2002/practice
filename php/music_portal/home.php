<?php
if (isset($_COOKIE["user"])) {
  if (isset($_GET["logout"])) {
    setcookie("user", "", time() - 3600);
    header("Location: ./index.php");
    exit();
  }
}
else {
  header("Location: ./index.php");
  exit();
}
include_once("./connection.php");
if (isset($_POST["search"])) {
  $sn = "%".$_POST["search"]."%";
  $query = $connection->prepare("SELECT songs.id, songs.title, artists.name, songs.duration, songs.location FROM songs JOIN artists ON songs.artist = artists.id WHERE songs.title LIKE ? OR artists.name LIKE ? LIMIT 10");
  $query->bind_param("ss", $sn, $sn);
  $query->execute();
  $r = $query->get_result();
  $r = $r->fetch_all(MYSQLI_ASSOC);
}
else {
  $query = "SELECT songs.id, songs.title, artists.name, songs.duration, songs.location FROM songs JOIN artists ON songs.artist = artists.id LIMIT 5";
  $r = $connection->query($query);
  $r = $r->fetch_all(MYSQLI_ASSOC);
}
// $query = "SELECT s.id, s.title, a.name, c.name, s.duration FROM songs s JOIN artists  a ON s.artist = a.id LEFT JOIN (SELECT c.song, a.name FROM collaborations c JOIN artists a ON c.feat = a.id) c ON c.song = s.id";
/* foreach ($r as $song) {
  print_r($song["title"]);
  echo "<br>";
} */
?>
<!DOCTYPE html>
  <html lang="es">
  <head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Spotify - Web Player</title>
    <meta name="author" content="Spotify"/>
    <meta name="author" content="Spotify es un servicio de música digital que te brinda acceso a millones de canciones sin anuncios."/>
    <meta name="keywords" content="Spotify, Music, Streaming, Songs, Artists"/>
    <link rel="icon" sizes="32x32" type="image/png" href="https://open.spotifycdn.com/cdn/images/favicon32.b64ecc03.png"/>
    <link rel="icon" sizes="16x16" type="image/png" href="https://open.spotifycdn.com/cdn/images/favicon16.1c487bff.png"/>
    <link rel="icon" href="https://open.spotifycdn.com/cdn/images/favicon.0f31d2ea.ico"/>
    <!-- CSS -->
    <link rel="stylesheet" type="text/css" href="./css/colors.css"/>
    <link rel="stylesheet" type="text/css" href="./css/home.css"/>
    <script defer type="text/javascript" src="./js/home.js"></script>
  </head>
  <body>
    <header class="header">
      <svg viewBox="0 0 1134 340" class="fwTMCeAaUoWDj9WcQbgy">
        <title>Spotify</title>
        <path fill="currentColor" d="M8 171c0 92 76 168 168 168s168-76 168-168S268 4 176 4 8 79 8 171zm230 78c-39-24-89-30-147-17-14 2-16-18-4-20 64-15 118-8 162 19 11 7 0 24-11 18zm17-45c-45-28-114-36-167-20-17 5-23-21-7-25 61-18 136-9 188 23 14 9 0 31-14 22zM80 133c-17 6-28-23-9-30 59-18 159-15 221 22 17 9 1 37-17 27-54-32-144-35-195-19zm379 91c-17 0-33-6-47-20-1 0-1 1-1 1l-16 19c-1 1-1 2 0 3 18 16 40 24 64 24 34 0 55-19 55-47 0-24-15-37-50-46-29-7-34-12-34-22s10-16 23-16 25 5 39 15c0 0 1 1 2 1s1-1 1-1l14-20c1-1 1-1 0-2-16-13-35-20-56-20-31 0-53 19-53 46 0 29 20 38 52 46 28 6 32 12 32 22 0 11-10 17-25 17zm95-77v-13c0-1-1-2-2-2h-26c-1 0-2 1-2 2v147c0 1 1 2 2 2h26c1 0 2-1 2-2v-46c10 11 21 16 36 16 27 0 54-21 54-61s-27-60-54-60c-15 0-26 5-36 17zm30 78c-18 0-31-15-31-35s13-34 31-34 30 14 30 34-12 35-30 35zm68-34c0 34 27 60 62 60s62-27 62-61-26-60-61-60-63 27-63 61zm30-1c0-20 13-34 32-34s33 15 33 35-13 34-32 34-33-15-33-35zm140-58v-29c0-1 0-2-1-2h-26c-1 0-2 1-2 2v29h-13c-1 0-2 1-2 2v22c0 1 1 2 2 2h13v58c0 23 11 35 34 35 9 0 18-2 25-6 1 0 1-1 1-2v-21c0-1 0-2-1-2h-2c-5 3-11 4-16 4-8 0-12-4-12-12v-54h30c1 0 2-1 2-2v-22c0-1-1-2-2-2h-30zm129-3c0-11 4-15 13-15 5 0 10 0 15 2h1s1-1 1-2V93c0-1 0-2-1-2-5-2-12-3-22-3-24 0-36 14-36 39v5h-13c-1 0-2 1-2 2v22c0 1 1 2 2 2h13v89c0 1 1 2 2 2h26c1 0 1-1 1-2v-89h25l37 89c-4 9-8 11-14 11-5 0-10-1-15-4h-1l-1 1-9 19c0 1 0 3 1 3 9 5 17 7 27 7 19 0 30-9 39-33l45-116v-2c0-1-1-1-2-1h-27c-1 0-1 1-1 2l-28 78-30-78c0-1-1-2-2-2h-44v-3zm-83 3c-1 0-2 1-2 2v113c0 1 1 2 2 2h26c1 0 1-1 1-2V134c0-1 0-2-1-2h-26zm-6-33c0 10 9 19 19 19s18-9 18-19-8-18-18-18-19 8-19 18zm245 69c10 0 19-8 19-18s-9-18-19-18-18 8-18 18 8 18 18 18zm0-34c9 0 17 7 17 16s-8 16-17 16-16-7-16-16 7-16 16-16zm4 18c3-1 5-3 5-6 0-4-4-6-8-6h-8v19h4v-6h4l4 6h5zm-3-9c2 0 4 1 4 3s-2 3-4 3h-4v-6h4z"></path>
      </svg>
      <form action=".<?php echo $_SERVER["PHP_SELF"]?>" method="post">
        <input type="search" name="search" class="search" id="search" placeholder="Buscar"/>
        <input type="submit" value="submit"/>
      </form>
      <div>
        <h1 class="user"><?php echo $_COOKIE["user"];?></h1>
        <a href="<?php echo ".".$_SERVER["PHP_SELF"]."?logout";?>">Cerrar sesión</a>
      </div>
    </header>
    <section class="songs">
      <?php foreach ($r as $song):?>
      <div class="card">
        <div class="metadata">
          <img src="./songs/<?php echo $song["location"]."/cover.jpg"?>" class="cover" alt="Cover"/>
          <div class="data">
            <!-- Title -->
            <h1 class="title" id="title"><?php echo $song["title"];?></h1>
            <!-- Author -->
            <h4 class="author" id="author"><?php echo $song["name"];?></h3>
            <p class="duration"><?php echo $song["duration"];?></p>
          </div>
        </div>
        <div class="play-song" name="<?php
          $song_path = glob("./songs/".$song["location"]."/*.mp3");
          $song_name = basename($song_path[0]);
          echo $song_name;
        ;?>" id="<?php
          echo $song["location"];
        ?>">
          <svg aria-hidden="true" focusable="false" data-prefix="fas" data-icon="play" class="svg-inline--fa fa-play fa-w-14" role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 448 512">
            <path fill="currentColor" d="M424.4 214.7L72.4 6.6C43.8-10.3 0 6.1 0 47.9V464c0 37.5 40.7 60.1 72.4 41.3l352-208c31.4-18.5 31.5-64.1 0-82.6z"></path>
          </svg>
        </div>
        <!-- Cover -->
      </div>
      <?php endforeach;?>
    </section>
    <!-- Media player -->
    <div class="media-player" id="media-player">
      <div class="info">
        <!-- Cover -->
        <img src="./img/cover-template.png" class="cover" id="cover" alt="Cover"/>
        <div class="data">
          <!-- Title -->
          <h1 class="song-name" id="song-name">Song</h1>
          <!-- Author -->
          <h4 class="artist" id="artist">Artist</h3>
        </div>
      </div>
      <div class="controls-general">
        <!-- Track -->
        <div class="track" id="track">
          <div class="progress" id="progress"></div>
        </div>
        <div class="duration">
          <p class="current-time" id="current-time">00:00:00</p>
          <p class="end-time" id="end-time">00:00:00</p>
        </div>
        <!-- Controls -->
        <div class="controls">
          <div class="previous" id="previous">
            <svg aria-hidden="true" focusable="false" data-prefix="fas" data-icon="backward" class="svg-inline--fa fa-backward fa-w-16" role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 512 512">
              <path fill="currentColor" d="M11.5 280.6l192 160c20.6 17.2 52.5 2.8 52.5-24.6V96c0-27.4-31.9-41.8-52.5-24.6l-192 160c-15.3 12.8-15.3 36.4 0 49.2zm256 0l192 160c20.6 17.2 52.5 2.8 52.5-24.6V96c0-27.4-31.9-41.8-52.5-24.6l-192 160c-15.3 12.8-15.3 36.4 0 49.2z"></path>
            </svg>
          </div>
          <div class="play" id="play">
            <svg aria-hidden="true" focusable="false" data-prefix="fas" data-icon="play" class="svg-inline--fa fa-play fa-w-14" role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 448 512">
              <path fill="currentColor" d="M424.4 214.7L72.4 6.6C43.8-10.3 0 6.1 0 47.9V464c0 37.5 40.7 60.1 72.4 41.3l352-208c31.4-18.5 31.5-64.1 0-82.6z"></path>
            </svg>
          </div>
          <div class="pause" id="pause">
            <svg aria-hidden="true" focusable="false" data-prefix="fas" data-icon="pause" class="svg-inline--fa fa-pause fa-w-14" role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 448 512">
              <path fill="currentColor" d="M144 479H48c-26.5 0-48-21.5-48-48V79c0-26.5 21.5-48 48-48h96c26.5 0 48 21.5 48 48v352c0 26.5-21.5 48-48 48zm304-48V79c0-26.5-21.5-48-48-48h-96c-26.5 0-48 21.5-48 48v352c0 26.5 21.5 48 48 48h96c26.5 0 48-21.5 48-48z"></path>
            </svg>
          </div>
          <div class="next" id="next">
            <svg aria-hidden="true" focusable="false" data-prefix="fas" data-icon="forward" class="svg-inline--fa fa-forward fa-w-16" role="img" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 512 512">
              <path fill="currentColor" d="M500.5 231.4l-192-160C287.9 54.3 256 68.6 256 96v320c0 27.4 31.9 41.8 52.5 24.6l192-160c15.3-12.8 15.3-36.4 0-49.2zm-256 0l-192-160C31.9 54.3 0 68.6 0 96v320c0 27.4 31.9 41.8 52.5 24.6l192-160c15.3-12.8 15.3-36.4 0-49.2z"></path>
            </svg>
          </div>
        </div>
        <!-- Volume -->
        <div class="volume">
          &nbsp;<input type="range" name="volume" id="volume" min="0" max="1" step="0.01"/>
        </div>
      </div>
    </div>
  </body>
</html>