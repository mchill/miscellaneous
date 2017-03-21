<?php
session_start();
include 'emergency.txt';

if ($_SESSION['status']!="on") {
header('Location: ../index.php');
}
?>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">

<html>

<?php
include 'header.txt';
?>

<div id="main">
  <div id="contentcreatetopic">
  <div id="error">
  <?php
  if(isset($_SESSION['errorcreatetopic'])) {
  if($_SESSION['errorcreatetopic']=="on") {
  if(isset($_SESSION['errortopicname'])) {
  if($_SESSION['errortopicname']=="on") {
  echo "<p><b>ERROR: Please make your topic name longer.</b></p>";
  }
  }
  if(isset($_SESSION['errortopiccontent'])) {
  if($_SESSION['errortopiccontent']=="on") {
  echo "<p><b>ERROR: Please make your post longer.</b></p>";
  }
  }
  }
  }
  $_SESSION['errorcreatetopic']="off";
  ?>
  </div><!--END ERROR-->

  <form action="process create topic.php" method="post">
  <p id="nameform">Topic Name:<br /><input size="40" maxlength="20" name="topicname" type="text" value="<?php echo $_SESSION['topicname']; ?>" /></p>
  <p id="categoryform">
  Category:<br />
  <select name="category">
  <option <?php if($_SESSION['category']=="General") {echo "selected=\"yes\"";} ?>>General</option>
  <option <?php if($_SESSION['category']=="Fun") {echo "selected=\"yes\"";} ?>>Fun</option>
  <option <?php if($_SESSION['category']=="Site") {echo "selected=\"yes\"";} ?>>Site</option>
  </select>
  </p>
  <div style="clear:both;"></div>
  <p>Content: <textarea cols="97" rows="10" maxlength="50000" name="topiccontent"><?php echo $_SESSION['topiccontent']; ?></textarea></p>
  <input type="submit" value="Create Topic"/>
  </form>
  </div><!--END CONTENT-->
</div><!--END MAIN-->

<?php
include 'footer.txt';
?>

</html>
