<?php
session_start();
include 'emergency.txt';

include 'databaseconnect.php';
?>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">

<html>

<?php
include 'header.txt';
?>

<div id="main">
  <div id="contentforum">
  <?php
  if (isset($_SESSION['status'])) {
  if ($_SESSION['status']=="on") {
  echo "<h4><a href=\"create topic.php\">Create a topic.</a></h4>";
  }
  }
  ?>

  <h3>General</h3>
  <ol>
  <?php
  $result=mysql_query("SELECT * FROM topic WHERE category='General' ORDER BY lastreply DESC") or die(mysql_error());
  $counter=0;
  while (($row=mysql_fetch_array($result)) && ($counter<10)) {
  echo "<li><a href=\"topic.php?id=".$row['id']."\">".$row['name']."</a></li>";
  $counter++;
  }
  ?>
  </ol>
  <h3>Fun</h3>
  <ol>
  <?php
  $result=mysql_query("SELECT * FROM topic WHERE category='Fun' ORDER BY lastreply DESC") or die(mysql_error());
  $counter=0;
  while (($row=mysql_fetch_array($result)) && ($counter<10)) {
  echo "<li><a href=\"topic.php?id=".$row['id']."\">".$row['name']."</a></li>";
  $counter++;
  }
  ?>
  </ol>
  <h3>Site</h3>
  <ol>
  <?php
  $result=mysql_query("SELECT * FROM topic WHERE category='Site' ORDER BY lastreply DESC") or die(mysql_error());
  $counter=0;
  while (($row=mysql_fetch_array($result)) && ($counter<10)) {
  echo "<li><a href=\"topic.php?id=".$row['id']."\">".$row['name']."</a></li>";
  $counter++;
  }
  ?>
  </ol>
  </div><!--END CONTENT-->

  <div style="clear:both"></div>
</div><!--END MAIN-->

<?php
include 'footer.txt';
?>

</html>
