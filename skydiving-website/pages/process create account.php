<?php
session_start();

include 'databaseconnect.php';

$_SESSION['createemail']=mysql_real_escape_string($_POST['createemail']);
$_SESSION['createusername']=mysql_real_escape_string($_POST['createusername']);
$_SESSION['createpassword']=mysql_real_escape_string($_POST['createpassword']);
$date=date("Y/m/d");

$_SESSION['errorcreateaccount']="off";
$_SESSION['errorusedusername']="off";
$_SESSION['errorusedemail']="off";
$_SESSION['erroruseremail']="off";
$_SESSION['errorusername']="off";
$_SESSION['errorpassword']="off";

$result=mysql_query("SELECT * FROM users WHERE name='".$_SESSION['createusername']."'") or die(mysql_error());
$row=mysql_fetch_array($result);
if ($row['name']!="") {
$_SESSION['errorcreateaccount']="on";
$_SESSION['errorusedusername']="on";
}

$result=mysql_query("SELECT * FROM users WHERE email='".$_SESSION['createemail']."'") or die(mysql_error());
$row=mysql_fetch_array($result);
if ($row['email']!="") {
$_SESSION['errorcreateaccount']="on";
$_SESSION['errorusedemail']="on";
}

if(1>strlen($_SESSION['createemail'])) {
$_SESSION['errorcreateaccount']="on";
$_SESSION['erroruseremail']="on";
}
if(6>strlen($_SESSION['createusername'])) {
$_SESSION['errorcreateaccount']="on";
$_SESSION['errorusername']="on";
}
if(6>strlen($_SESSION['createpassword'])) {
$_SESSION['errorcreateaccount']="on";
$_SESSION['errorpassword']="on";
}

if ($_SESSION['status']=="on") {
$_SESSION['errorcreateaccount']="off";
header('Location: ../index.php');
} else if($_SESSION['errorcreateaccount']=="on") {
header('Location: create account.php');
} else {
mysql_query("INSERT INTO users(name,password,email,date,level) VALUES('".$_SESSION['createusername']."','".$_SESSION['createpassword']."','".$_SESSION['createemail']."','$date','1')") or die(mysql_error());
$result=mysql_query("SELECT * FROM users WHERE name='".$_SESSION['createusername']."'") or die(mysql_error());
$row=mysql_fetch_array($result);
$to=$_SESSION['useremail'];
$subject="Email Confirmation";
$message="Welcome to Skyline Skydiving. To complete your account activation, go to this link.  http://hillm11.x10.mx/pages/accountactivation.php?id=".$row['id'];
$from="From: mchill7@hillm11.com/r/n";
mail ($to, $subject, $message, $from);
$_SESSION['allowaccountactivation']="on";
header('Location: accountactivation.php');
}

?>

<html></html>
