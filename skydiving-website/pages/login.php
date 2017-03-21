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
  <div id="contentlogin">
  <div id="error">
  <?php
  if(isset($_SESSION['errorlogin'])) {
  if($_SESSION['errorlogin']=="on") {
  if(isset($_SESSION['errorlevel'])) {
  if($_SESSION['errorlevel']=="on") {
  echo "<p><b>ERROR: You have been temporarily banned. Wait a few days and then try again.</b></p>";
  }
  }
  if(isset($_SESSION['errorpassword'])) {
  if($_SESSION['errorpassword']=="on") {
  echo "<p><b>ERROR: You have entered an incorrect username or password.</b></p>";
  }
  }
  }
  }
  $_SESSION['errorlogin']="off";
  ?>
  </div><!--END ERROR-->

  <a href="create account.php">If you do not have an account, you can create one here.</a>
  <p>Enter your username and password to log in.</p>
  <form action="process login.php" method="post">
  <ol>
  <li>Username: <input size="20" maxlength="20" name="username" type="text" value="<?php echo $_SESSION['username']; ?>" /></li>
  <li>Password: <input size="20" maxlength="20" name="password" type="password" /></li>
  </ol>
  <input type="submit" value="Login"/>
  </form>
  </div><!--END CONTENT-->
</div><!--END MAIN-->

<?php
include 'footer.txt';
?>

</html>
