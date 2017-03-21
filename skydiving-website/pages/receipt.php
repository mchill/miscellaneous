<?php
session_start();
include 'emergency.txt';

if (ISSET($_SESSION['allowreceipt'])) {
if ($_SESSION['allowreceipt']=="on") {
session_unset();
} else {
header ('Location: ../index.php');
}
} else {
header ('Location: ../index.php');
}
?>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">

<html>

<?php
include 'header.txt';
?>

<div id="main">
  <div id="contentreceipt">
  <?php
  echo "<p>You are registered to skydive or ride a helicopter on ".$_SESSION['month']." ".$_SESSION['day'].", ".$_SESSION['year'].". You are registered as ".$_SESSION['name'].", and your email address and phone number are ".$_SESSION['email']." and ".$_SESSION['phone'].".</p>";
  echo "<p>You must verify your registration within two weeks of your appointment, or this day if your appointment is within two weeks from now already. Otherwise, your information and registration will be deleted. To cancel your appointment, you must call our office. See our <a href=\"contact us.php\">contact us</a> page for more information.</p>";
  echo "<p>You are advised to print this page for documentation.</p>";
  ?>
  </div><!--END CONTENT-->

</div><!--END MAIN-->

<?php
include 'footer.txt';
$_SESSION['year']="";
$_SESSION['month']="";
$_SESSION['day']="";
$_SESSION['time']="";
$_SESSION['name']="";
$_SESSION['phone']="";
$_SESSION['email']="";
?>

</html>
