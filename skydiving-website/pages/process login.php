<?php
session_start();

include 'databaseconnect.php';

$_SESSION['username']=mysql_real_escape_string($_POST['username']);
$_SESSION['password']=mysql_real_escape_string($_POST['password']);

$_SESSION['errorlogin']="off";
$_SESSION['errorpassword']="off";
$_SESSION['errorlevel']="off";

$result=mysql_query("SELECT * FROM users WHERE name='".$_SESSION['username']."' AND password='".$_SESSION['password']."'") or die(mysql_error());
$row=mysql_fetch_array($result);


if ($_SESSION['status']=="on") {
header('Location: ../index.php');
} else if ($row['name']=="") {
$_SESSION['errorlogin']="on";
$_SESSION['errorpassword']="on";
header ('Location: login.php');
} else if ($row['level']==0) {
$_SESSION['errorlogin']="on";
$_SESSION['errorlevel']="on";
header ('Location: login.php');
} else {
$_SESSION['status']="on";
$_SESSION['userid']=$row['id'];
$_SESSION['useremail']=$row['email'];
$_SESSION['userdate']=$row['date'];
$_SESSION['userlevel']=$row['level'];
header ('Location: ../index.php');
}

?>

<html></html>
