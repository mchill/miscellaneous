<?php
session_start();

include 'databaseconnect.php';

$topicid=$_GET['id'];

$result=mysql_query("SELECT * FROM topic WHERE id='$topicid'") or die(mysql_error());
$row=mysql_fetch_array($result);

$result2=mysql_query("SELECT * FROM users WHERE id='".$row['creator']."'") or die(mysql_error());
$row2=mysql_fetch_array($result2);

if ($row['id']=="") {
header('Location: ../index.php');
} else if ($_SESSION['userid']==$row['creator'] || $_SESSION['userlevel']==4 || ($_SESSION['userlevel']==3 && $row2['level']!=4 && $row2['level']!=3)) {
mysql_query("UPDATE topic SET status='off' WHERE id='".$row['id']."'") or die(mysql_error());
header('Location: topic.php?id='.$topicid);
} else {
header('Location: ../index.php');
}

?>

<html></html>
