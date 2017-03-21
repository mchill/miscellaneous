<?php
session_start();
include 'databaseconnect.php';
include 'emergency.txt';
if ($_GET['id']=="") {
if (isset($_SESSION['allowaccountactivation'])) {
if ($_SESSION['allowaccountactivation']=="off") {
header('Location: ../index.php');
} else {
session_unset();
$message=1;
}
} else {
header('Location: ../index.php');
}
} else {
mysql_connect("localhost","root","1admin") or die(mysql_error());
mysql_select_db("skydiving") or die(mysql_error());
$result=mysql_query("SELECT * FROM users WHERE id='".$_GET['id']."'") or die(mysql_error());
$row=mysql_fetch_array($result);
if ($row['id']=="") {
header ('Location: ../index.php');
} else if ($row['level']!=1) {
header ('Location: ../index.php');
} else {
mysql_query("UPDATE users SET level='2' WHERE id='".$row['id']."'") or die(mysql_error());
$message=2;
}
}
?>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">

<html>

<?php
include 'header.txt';
?>

<div id="main">
  <div id="contentaccountactivation">
  <?php
  if ($message==1) {
  echo "<p>You have recieved an activation email. Please click the link given in the email to activate your account.</p><p>Until you do so, you will not have access to your account.</p>";
  } else if ($message==2) {
  echo "Congratulations, your account has been successfully activated. <a href=\"login.php\">Log in</a> to get started.";
  }
  ?>
  </div><!--END CONTENT-->
</div><!--END MAIN-->

<?php
include 'footer.txt';
session_unset();
?>

</html>
