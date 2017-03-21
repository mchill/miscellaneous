<?php
session_start();
include 'emergency.txt';

if ($_SESSION['status']=="on") {
header('Location: ../index.php');
}
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<html>

<?php
include 'header.txt';
?>

<div id="main">
  <div id="contentcreateaccount">
  <div id="error">
  <?php
  if(isset($_SESSION['errorcreateaccount'])) {
  if($_SESSION['errorcreateaccount']=="on") {
  if(isset($_SESSION['errorusedusername'])) {
  if($_SESSION['errorusedusername']=="on") {
  echo "<p><b>ERROR: Someone has already registered with this user name.</b></p>";
  }
  }
  if(isset($_SESSION['errorusedemail'])) {
  if($_SESSION['errorusedemail']=="on") {
  echo "<p><b>ERROR: Someone has already registered with this email address.</b></p>";
  }
  }
  if(isset($_SESSION['errorusername'])) {
  if($_SESSION['errorusername']=="on") {
  echo "<p><b>ERROR: Please enter a valid user name.</b></p>";
  }
  }
  if(isset($_SESSION['errorpassword'])) {
  if($_SESSION['errorpassword']=="on") {
  echo "<p><b>ERROR: Please enter a valid password.</b></p>";
  }
  }
  if(isset($_SESSION['erroruseremail'])) {
  if($_SESSION['erroruseremail']=="on") {
  echo "<p><b>ERROR: Please enter a valid email address.</b></p>";
  }
  }
  }
  }
  $_SESSION['errorcreateaccount']="off";
  ?>
  </div><!--END ERROR-->

  <a href="login.php">If you already have an account, login here.</a>
  <form action="process create account.php" method="post">
  <h3>Enter all of the following data to create your account.</h3>
  <p>Enter your complete email address.</p>
  <p>Email: <input size="20" maxlength="50" name="createemail" type="text" value="<?php echo $_SESSION['createemail']; ?>" /></p><br />
  <p>Create a user name that is between 6 to 20 characters long.</p>
  <p>Username: <input size="20" maxlength="20" name="createusername" type="text" value="<?php echo $_SESSION['createusername']; ?>" /></p><br />
  <p>Create a password that is between 6 to 20 characters long.</p>
  <p>Password: <input size="20" maxlength="20" name="createpassword" type="password" /></p>
  <input type="submit" value="Create Account"/>
  </form>
  </div><!--END CONTENT-->
  <div style="clear:both"></div>
</div><!--END MAIN-->

<?php
include 'footer.txt';
?>

</html>
