<?php
session_start();
if ($_SESSION['emergency']=="on") {
} else {
header ('Location: ../index.php');
}
?>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">

<html>

<head>
<link href="style.css" rel="stylesheet" type="text/css" media="screen" />
<title>Skyline Skydiving</title>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1" />
</head>

<body style="background:black;">
<div id="contentshutdown">
  <h1>SHUTDOWN</h1>
  <p>The administrator has temporarily shut down the website. Please try again later.</p>
</div><!--END CONTENT-->
</body>

</html>
