<?php
session_start(); /*Starts the session.*/

include 'databaseconnect.php';

$year=mysql_real_escape_string($_POST['year']); /*Gets user entries.*/
$month=mysql_real_escape_string($_POST['month']);
$day=mysql_real_escape_string($_POST['day']);
$time=mysql_real_escape_string($_POST['time']);
$name=mysql_real_escape_string($_POST['name']);
$phone=mysql_real_escape_string($_POST['phone']);
$email=mysql_real_escape_string($_POST['email']);
if ($month=="January") { /*Turns month entry into usable database form.*/
$month2="01";
} else if ($month=="February") {
$month2="02";
} else if ($month=="March") {
$month2="03";
} else if ($month=="April") {
$month2="04";
} else if ($month=="May") {
$month2="05";
} else if ($month=="June") {
$month2="06";
} else if ($month=="July") {
$month2="07";
} else if ($month=="August") {
$month2="08";
} else if ($month=="September") {
$month2="09";
} else if ($month=="October") {
$month2="10";
} else if ($month=="November") {
$month2="11";
} else if ($month=="December") {
$month2="12";
}
$cutoffdate1=date("Y/m/d",strtotime("+2 weeks")); /*Defines the dates used in processing.*/
$cutoffdate2=date("Y/m/d",strtotime("+1 years"));
$signupdate=$year."/".$month2."/".$day;

$_SESSION['year']=$year; /*Turns all user entries into session variables.*/
$_SESSION['month']=$month;
$_SESSION['day']=$day;
$_SESSION['time']=$time;
$_SESSION['name']=$name;
$_SESSION['phone']=$phone;
$_SESSION['email']=$email;

$_SESSION['errorregister']="off"; /*Turns off all errors.*/
$_SESSION['errordate1']="off";
$_SESSION['errordate2']="off";
$_SESSION['errordate3']="off";
$_SESSION['errorfull']="off";
$_SESSION['errorname']="off";
$_SESSION['errorphone']="off";
$_SESSION['erroremail']="off";

$result=mysql_query("SELECT * FROM registration WHERE year='$year' AND month='$month' AND day='$day' AND time='$time'") or die(mysql_error()); /*Gets the database entry that matches user entries.*/
$row=mysql_fetch_array($result);

if($signupdate<$cutoffdate1) { /*Adds error if the user is not allowed to sign up for the date chosen.*/
$_SESSION['errordate1']="on";
$_SESSION['errorregister']="on";
}
if($signupdate>$cutoffdate2) {
$_SESSION['errordate2']="on";
$_SESSION['errorregister']="on";
}
if($row['year']=="") { /*Adds error if the user-entered date does not exist. EX: February 31*/
$_SESSION['errordate3']="on";
$_SESSION['errorregister']="on";
}
if(1>strlen($name)) { /*Defines a minimum character requirement for text box user entries.*/
$_SESSION['errorname']="on";
$_SESSION['errorregister']="on";
}
if(7>strlen($phone)) {
$_SESSION['errorphone']="on";
$_SESSION['errorregister']="on";
}
if(1>strlen($email)) {
$_SESSION['erroremail']="on";
$_SESSION['errorregister']="on";
}

if ($row['status']=="full") { /*Determines if the date that the user registered for is available.*/
$_SESSION['errorfull']="on"; /*Adds error if date is not available.*/
header('Location: register.php'); /*Redirects to register page.*/
} else if($_SESSION['errorregister']=="on") { /*Redirects if any error has been turned on.*/
header('Location: register.php');
} else { /*If everything goes well, the user entries will be recorded in the database.*/
mysql_query("UPDATE registration SET status='full' WHERE year='$year' AND month='$month' AND day='$day' AND time='$time'") or die(mysql_error());
mysql_query("UPDATE registration SET name='$name' WHERE year='$year' AND month='$month' AND day='$day' AND time='$time'") or die(mysql_error());
mysql_query("UPDATE registration SET phone='$phone' WHERE year='$year' AND month='$month' AND day='$day' AND time='$time'") or die(mysql_error());
mysql_query("UPDATE registration SET email='$email' WHERE year='$year' AND month='$month' AND day='$day' AND time='$time'") or die(mysql_error());
$_SESSION['allowreceipt']="on"; /*Allows a one time access into the receipt page.*/
header('Location: receipt.php'); /*Redirects to receipt page.*/
}

?>

<html></html>
