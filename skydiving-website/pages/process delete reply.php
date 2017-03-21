<?php
session_start();

$reply=$_GET['id'];

include 'databaseconnect.php';

if ($_SESSION['userlevel']==3 || $_SESSION['userlevel']==4) {
mysql_query("DELETE FROM reply WHERE id='$reply'") or die(mysql_error());
header('Location: topic.php?id='.$_SESSION['topicid']);
} else {
header('Location: ../index.php');
}

?>

<html></html>
