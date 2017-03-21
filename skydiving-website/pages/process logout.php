<?php
session_start();

if (isset($_SESSION['status']) && $_SESSION['status']="on") {
session_unset();
}

header('Location: ../index.php');

?>

<html></html>
