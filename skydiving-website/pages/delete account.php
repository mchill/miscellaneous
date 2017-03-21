<?php
session_start();
include 'emergency.txt';

if ($_SESSION['status']!="on") {
header('Location: ../index.php');
}
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<html>

<?php
include 'header.txt';
?>

<div id="main">
  <div id="contentdeleteaccount">
  <h2>Are you sure that you want to delete your account?</h2>
  <form action="process delete account.php?name=<?php echo $_SESSION['username']; ?>" method="post">
  <input type="submit" value="Delete Account"/>
  </form>
  </div><!--END CONTENT-->
</div><!--END MAIN-->

<?php
include 'footer.txt';
?>

</html>
