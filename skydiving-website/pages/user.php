<?php
session_start();
include 'emergency.txt';
$name=$_GET['name'];

include 'databaseconnect.php';

$result=mysql_query("SELECT * FROM users WHERE name='$name'") or die(mysql_error());
$row=mysql_fetch_array($result);

$result2=mysql_query("SELECT * FROM reply WHERE creator='".$row['id']."'") or die(mysql_error());
$row2=mysql_fetch_array($result2);

$result3=mysql_query("SELECT * FROM reply WHERE creator='".$row['id']."' ORDER BY id DESC") or die(mysql_error());

$result5=mysql_query("SELECT * FROM topic WHERE creator='".$row['id']."'") or die(mysql_error());

if ($row['id']=="") {
header('Location: ../index.php');
}
?>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">

<html>

<?php
include 'header.txt';
?>

<div id="main">
  <div id="contentuser">
  <?php
  if ($_SESSION['userlevel']==4 && $row['level']!=4) {
  echo "<div class=\"button\"><a href=\"process delete account.php?name=".$name."\">Delete ".$row['name']."'s Account</a></div>";
  }
  if (($_SESSION['userlevel']==3 && $row['level']!=4 && $row['level']!=3 && $row['level']!=0) || ($_SESSION['userlevel']==4 && $row['level']!=4 && $row['level']!=0)) {
  echo "<div class=\"button\"><a href=\"process ban account.php?name=".$name."\">Temporarily Ban ".$row['name']."'s Account</a></div>";
  }
  if (($_SESSION['userlevel']==3 || $_SESSION['userlevel']==4) && $row['level']==0) {
  echo "<div class=\"greenbutton\"><a href=\"process unban account.php?name=".$name."\">Un-Ban ".$row['name']."'s Account</a></div>";
  }
  if ($_SESSION['userlevel']==4 && $row['level']==3) {
  echo "<div class=\"button\"><a href=\"process downgrade account.php?name=".$name."\">Remove ".$row['name']."'s Moderator Title</a></div>";
  }
  if ($_SESSION['userlevel']==4 && $row['level']==2) {
  echo "<div class=\"greenbutton\"><a href=\"process upgrade account.php?name=".$name."\">Make ".$row['name']." a Moderator</a></div>";
  }

  echo "<h1>".$row['name']."</h1>";
  echo "<div id=\"userleftside\"><h4>Date of Account Creation:</h4>".$row['date'];

  echo "<h4>Recent Replies by ".$row['name'].":</h4><ol>";
  $counter=0;
  while (($row3 = mysql_fetch_array($result3)) && ($counter<10)) {
  $result4=mysql_query("SELECT * FROM topic WHERE id='".$row3['topic']."'") or die(mysql_error());
  $row4=mysql_fetch_array($result4);
  echo "<li>".$row4['name']."</li>";
  $counter++;
  }

  echo "</ol></div><div id=\"userrightside\"><h4>Topics Created by ".$row['name'].":</h4><ol>";
  while ($row5 = mysql_fetch_array($result5)) {
  echo "<li>".$row5['name']."</li>";
  }
  echo "</ol></div><div style=\"clear: both;\"></div>";
  ?>
  </div><!--END CONTENT-->
</div><!--END MAIN-->

<?php
include 'footer.txt';
?>

</html>
