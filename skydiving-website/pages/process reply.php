<?php
session_start();

include 'databaseconnect.php';

$result=mysql_query("SELECT * FROM reply WHERE topic='".$_SESSION['topicid']."'") or die(mysql_error());
$row=mysql_fetch_array($result);

$_SESSION['reply']=mysql_real_escape_string($_POST['reply']);
$date=date("Y/m/d");
$time=time();

$_SESSION['errorreply']="off";

if (10>strlen($_SESSION['reply'])) {
$_SESSION['errorreply']="on";
}

if ($_SESSION['status']!="on") {
$_SESSION['errorreply']="off";
header('Location: ../index.php');
} else if ($row['creator']==$_SESSION['userid']) {
$_SESSION['errorreply']="off";
header ('Location: topic.php?id='.$_SESSION['topicid']);
} else if($_SESSION['errorreply']=="on") {
header('Location: topic.php?id='.$_SESSION['topicid']);
} else {
mysql_query("INSERT INTO reply(topic,creator,date,content,time) VALUES('".$_SESSION['topicid']."','".$_SESSION['userid']."','$date','".$_SESSION['reply']."','$time')") or die(mysql_error());
mysql_query("UPDATE topic SET lastreply='$time' WHERE id='".$_SESSION['topicid']."'") or die(mysql_error());
$_SESSION['errorreply']="off";
$_SESSION['reply']="";
header('Location: topic.php?id='.$_SESSION['topicid']);
}

?>

<html></html>
