<?php
session_start();

include 'databaseconnect.php';

$username=$_GET['name'];

$result=mysql_query("SELECT * FROM users WHERE name='$username'") or die(mysql_error());
$row=mysql_fetch_array($result);

if (($_SESSION['userlevel']==4 && $row['level']!=4) || ($row['name']==$_SESSION['username'] && $_SESSION['userlevel']!=4)) {
mysql_query("DELETE FROM users WHERE name='$username'") or die(mysql_error());
mysql_query("DELETE FROM topic WHERE creator='".$row['id']."'") or die(mysql_error());
mysql_query("DELETE FROM reply WHERE creator='".$row['id']."'") or die(mysql_error());
if ($_SESSION['userid']==$row['id']) {
header('Location: process logout.php');
} else {
header('Location: ../index.php');
}
} else {
header('Location: ../index.php');
}

?>

<html></html>
