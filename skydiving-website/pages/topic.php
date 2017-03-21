<?php
session_start();
include 'emergency.txt';
$id=$_GET['id'];
$_SESSION['topicid']=$_GET['id'];

include 'databaseconnect.php';

$result=mysql_query("SELECT * FROM topic WHERE id='$id'") or die(mysql_error()); /*Gets topic data.*/
$row=mysql_fetch_array($result);

$result2=mysql_query("SELECT * FROM users WHERE id='".$row['creator']."'") or die(mysql_error()); /*Gets topic creator data.*/
$row2=mysql_fetch_array($result2);

$result3=mysql_query("SELECT * FROM reply WHERE topic='".$row['id']."'") or die(mysql_error()); /*Gets topic reply data.*/

$result4=mysql_query("SELECT * FROM reply WHERE topic='".$row['id']."'") or die(mysql_error()); /*Gets topic reply data.*/
$row4=mysql_fetch_array($result4);

if ($row['id']=="") {
header('Location: ../index.php');
}
?>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">

<html>

<?php
include 'header.txt';

echo "<div id=\"topictitle\"><h1>".$row['name']."</h1></div>";
?>

<div id="main">
  <div id="contenttopic">
  <?php
  echo "<div id=\"originalpost\">";
  if ($row['status']=="on" && (($_SESSION['username']==$row2['name']) || ($_SESSION['userlevel']==3 && $row2['level']!=4 && $row2['level']!=3) || ($_SESSION['userlevel']==4))) {
  echo "<div class=\"button\"><a href=\"process lock topic.php?id=".$_SESSION['topicid']."\">Lock Topic</a></div>";
  } else if ($row['status']=="off" && (($_SESSION['userlevel']==3 && $row2['level']!=4 && $row2['level']!=3) || ($_SESSION['userlevel']==4))) {
  echo "<div class=\"greenbutton\"><a href=\"process revive topic.php?id=".$_SESSION['topicid']."\">Revive Topic</a></div>";
  }
  if (($_SESSION['userlevel']==3 && $row2['level']!=4 && $row2['level']!=3) || ($_SESSION['userlevel']==4 && $row2['level']!=4)) {
  echo "<div class=\"button\"><a href=\"process delete topic.php?id=".$_SESSION['topicid']."\">Delete Topic</a></div>";
  }
  echo "<div class=\"postcreator\"><a href=\"user.php?name=".$row2['name']."\">".$row2['name']."</a></div>";
  echo "<div class=\"postdate\">".$row['date']."</div><div style=\"clear:both;\"></div>";
  echo "<div class=\"postcontent\">".$row['content']."</div></div>";

  while ($row3 = mysql_fetch_array($result3)) {
  $result5=mysql_query("SELECT * FROM users WHERE id='".$row3['creator']."'") or die(mysql_error());
  $row5=mysql_fetch_array($result5);
  echo "<div class=\"post\">";
  if (($_SESSION['userlevel']==3 && $row5['level']!=4 && $row5['level']!=3) || ($_SESSION['userlevel']==4)) {
  echo "<div class=\"button\"><a href=\"process delete reply.php?id=".$row3['id']."\">Delete Reply</a></div>";
  }
  echo "<div class=\"postcreator\"><a href=\"user.php?name=".$row5['name']."\">".$row5['name']."</a></div>";
  echo "<div class=\"postdate\">".$row3['date']."</div><div style=\"clear:both;\"></div>";
  echo "<div class=\"postcontent\">".$row3['content']."</div></div>";
  }

  if (isset($_SESSION['errorreply'])) {
  if ($_SESSION['errorreply']=="on") {
  echo "<div id=\"error\"><p><b>ERROR: Please make your reply longer.</b></p></div><!--END ERROR-->";
  }
  }
  $_SESSION['errorreply']="off";
  ?>

  <?php
  if (isset($_SESSION['status']) && $_SESSION['status']=="on") {
  $result6=mysql_query("SELECT * FROM reply WHERE topic='".$_SESSION['topicid']."' ORDER BY time DESC") or die(mysql_error());
  $row6=mysql_fetch_array($result6);
  if ($row6['creator']!=$_SESSION['userid'] && $row['status']=="on") {
  echo "<form action=\"process reply.php\" method=\"post\">
  <p>Reply: <textarea cols=\"97\" rows=\"6\" maxlength=\"1000\" name=\"reply\">".$_SESSION['reply']."</textarea></p>
  <input type=\"submit\" value=\"Reply\"/>
  </form>";
  }
  }
  ?>
  </div><!--END CONTENT-->
</div><!--END MAIN-->

<?php
include 'footer.txt';
?>

</html>
