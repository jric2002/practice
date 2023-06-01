<?php
  include_once("./header.php");
  if (!isset($_GET["page"])) {
    $_GET["page"] = "1";
  }
?>
<ul class="nav nav-pills">
  <li class="nav-item page-1">
    <a class="nav-link <?php if ($_GET["page"] == "1"): echo "active"; endif; ?>" href="./index.php?page=1">Page 1</a>
  </li>
  <li class="nav-item page-2">
    <a class="nav-link <?php if ($_GET["page"] == "2"): echo "active"; endif; ?>" href="./index.php?page=2">Page 2</a>
  </li>
  <li class="nav-item page-3">
    <a class="nav-link <?php if ($_GET["page"] == "3"): echo "active"; endif; ?>" href="./index.php?page=3">Page 3</a>
  </li>
</ul>
<?php
  if ($_GET["page"] == "1") {
    include_once("./page-1.php");
  }
  elseif ($_GET["page"] == "2") {
    include_once("./page-2.php");
  }
  else {
    include_once("./page-3.php");
  }
?>
<?php
  include_once("./footer.php");
?>