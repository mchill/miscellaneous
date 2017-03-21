<?php
session_start();

$topic=$_GET['id'];

include 'databaseconnect.php';

if ($_SESSION['userlevel']==3 || $_SESSION['userlevel']==4) {
mysql_query("DELETE FROM topic WHERE id='$topic'") or die(mysql_error());
mysql_query("DELETE FROM reply WHERE topic='$topic'") or die(mysql_error());
header('Location: topic.php?id='.$SESSION['topicid']);
} else {
header('Location: ../index.php');
}

?>

<html></html>
