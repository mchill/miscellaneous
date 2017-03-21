<?php
session_start();

include 'databaseconnect.php';

$_SESSION['topicname']=mysql_real_escape_string($_POST['topicname']);
$_SESSION['category']=mysql_real_escape_string($_POST['category']);
$_SESSION['topiccontent']=mysql_real_escape_string($_POST['topiccontent']);
$date=date("Y/m/d");
$time=time();

$_SESSION['errorcreatetopic']="off";
$_SESSION['errortopicname']="off";
$_SESSION['errortopiccontent']="off";

$result=mysql_query("SELECT * FROM topic WHERE name='".$_SESSION['topicname']."'") or die(mysql_error());
$row=mysql_fetch_array($result);

if(6>strlen($_SESSION['topicname'])) {
$_SESSION['errorcreatetopic']="on";
$_SESSION['errortopicname']="on";
}
if(20>strlen($_SESSION['topiccontent'])) {
$_SESSION['errorcreatetopic']="on";
$_SESSION['errortopiccontent']="on";
}

if ($_SESSION['status']!="on") {
$_SESSION['errorcreatetopic']="off";
header('Location: ../index.php');
} else if ($_SESSION['errorcreatetopic']=="on") {
header('Location: create topic.php');
} else {
mysql_query("INSERT INTO topic(category,name,creator,date,content,status,lastreply) VALUES('".$_SESSION['category']."','".$_SESSION['topicname']."','".$_SESSION['userid']."','$date','".$_SESSION['topiccontent']."','on','$time')") or die(mysql_error());
$result=mysql_query("SELECT * FROM topic WHERE name='".$_SESSION['topicname']."'") or die(mysql_error());
$row=mysql_fetch_array($result);
$_SESSION['topicname']="";
$_SESSION['category']="";
$_SESSION['topiccontent']="";
header('Location: topic.php?id='.$row['id']);
}

?>

<html></html>
