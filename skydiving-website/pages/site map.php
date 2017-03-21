<?php
session_start();
include 'emergency.txt';
?>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">

<html>

<?php
include 'header.txt';
?>

<div id="main">
  <div id="contentsitemap">
  <p>
  <a href="../index.php">Home</a><br />
  <a href="about us.php">About Us</a><br />
  <a href="service information.php">Service Information</a><br />
  <a href="register.php">Register</a><br />
  <a href="receipt.php">Receipt</a> *<br />
  <a href="forum.php">Forum</a><br />
  <a href="create topic.php">Create Topic</a> *<br />
  <a href="contact us.php">Contact Us</a><br />
  <a href="privacy policy.php">Privacy Policy</a><br />
  <a href="terms of service.php">Terms of Service</a><br />
  <a href="login.php">Login</a> *<br />
  <a href="create account.php">Create Account</a> *<br />
  <a href="accountactivation.php">Account Activation</a> *<br />
  <a href="login.php">Log In</a> *<br />
  <a href="user.php?name=<?php echo $_SESSION['username']; ?>">User</a> *<br />
  <a href="delete account.php">Delete Account</a> *<br />
  <a href="site map.php">Site Map</a><br />
  <a href="shutdown.php">ShutDown</a> *<br />
  <br />
  * These pages can only be accessed under certain circumstances.<br />
  </p>
  </div><!--END CONTENT-->
</div><!--END MAIN-->

<?php
include 'footer.txt';
?>

</html>
