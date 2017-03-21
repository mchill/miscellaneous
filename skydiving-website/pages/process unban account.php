<?php
session_start();

include 'databaseconnect.php';

$username=$_GET['name'];

$result=mysql_query("SELECT * FROM users WHERE name='$username'") or die(mysql_error());
$row=mysql_fetch_array($result);

if (($_SESSION['userlevel']==4 || $_SESSION['userlevel']==3) && $row['level']==0) {
mysql_query("UPDATE users SET level='2' WHERE name='$username'") or die(mysql_error());
header('Location: user.php?name='.$username);
} else {
header('Location: ../index.php');
}

?>

<html></html>
