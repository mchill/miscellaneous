<?php
session_start();

if($_SESSION['userlevel']==4) {
$filename="emergency.txt";
$filename2="../emergency.txt";

$fh=fopen($filename,'w') or die("Can't open file");
$fh2=fopen($filename2,'w') or die("Can't open file");

$newcontent="<?php
\$_SESSION['emergency']=\"off\";
if (\$_SESSION['emergency']==\"on\") {
if (\$_SESSION['userlevel']!=4) {
header('Location: shutdown.php');
}
}
?>";

$newcontent2="<?php
\$_SESSION['emergency']=\"off\";
if (\$_SESSION['emergency']==\"on\") {
if (\$_SESSION['userlevel']!=4) {
header('Location: pages/shutdown.php');
}
}
?>";

fwrite($fh,$newcontent);
fwrite($fh2,$newcontent2);

fclose($fh);
fclose($fh2);

header ('Location: ../index.php');
} else {
header ('Location: ../index.php');
}
?>

<html></html>
