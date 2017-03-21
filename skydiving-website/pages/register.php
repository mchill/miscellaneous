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
  <div id="contentregister">
  <div id="error">
  <?php
  if(isset($_SESSION['errorregister'])) {
  if($_SESSION['errorregister']=="on") {
  if(isset($_SESSION['errorfull'])) {
  if($_SESSION['errorfull']=="on") {
  echo "<p><b>ERROR: Someone has already registered for this date and time.</b></p>";
  }
  }
  if(isset($_SESSION['errordate1'])) {
  if($_SESSION['errordate1']=="on") {
  echo "<p><b>ERROR: You may not register for this date anymore.</b></p>";
  }
  }
  if(isset($_SESSION['errordate2'])) {
  if($_SESSION['errordate2']=="on") {
  echo "<p><b>ERROR: You may not register for this date yet.</b></p>";
  }
  }
  if(isset($_SESSION['errordate3'])) {
  if($_SESSION['errordate3']=="on") {
  echo "<p><b>ERROR: The date that you have registered for does not exist.</b></p>";
  }
  }
  if(isset($_SESSION['errorname'])) {
  if($_SESSION['errorname']=="on") {
  echo "<p><b>ERROR: Please enter your full name.</b></p>";
  }
  }
  if(isset($_SESSION['errorphone'])) {
  if($_SESSION['errorphone']=="on") {
  echo "<p><b>ERROR: Please enter a valid phone number.</b></p>";
  }
  }
  if(isset($_SESSION['erroremail'])) {
  if($_SESSION['erroremail']=="on") {
  echo "<p><b>ERROR: Please enter your email address.</b></p>";
  }
  }
  }
  }
  $_SESSION['errorregister']="off";
  ?>
  </div><!--END ERROR-->
  <div id="registerinfo">
  <p>Before resistering, please read our <a href="service information.php">service information</a> page. You will find pricing and time details there. Also, be aware that you do not choose whether you are skydiving or riding in the registration process. We will determine that when you call to confirm your appointment.</p>
  <p>You must sign up for a day at least two weeks in advance, and at most one year in advance. All days and times are displayed, whether they are available or not. You will recieve an error if the day and time that you choose is already taken.</p>
  </div><!--END REGISTERINFO-->
  <div id="dropdownform">
  <ol>
  <li>
  <p>First, choose the year that you want to skydive.</p>
  <form method="post" action="process register.php">
  <select name="year">
  <option <?php if($_SESSION['year']=="2013") {echo "selected=\"yes\"";} ?>>2013</option>
  <option <?php if($_SESSION['year']=="2014") {echo "selected=\"yes\"";} ?>>2014</option>
  </select>
  </li>
  <li>
  <p>Second, choose the month that you want to skydive.</p>
  <select name="month">
  <option <?php if($_SESSION['month']=="January") {echo "selected=\"yes\"";} ?>>January</option>
  <option <?php if($_SESSION['month']=="February") {echo "selected=\"yes\"";} ?>>February</option>
  <option <?php if($_SESSION['month']=="March") {echo "selected=\"yes\"";} ?>>March</option>
  <option <?php if($_SESSION['month']=="April") {echo "selected=\"yes\"";} ?>>April</option>
  <option <?php if($_SESSION['month']=="May") {echo "selected=\"yes\"";} ?>>May</option>
  <option <?php if($_SESSION['month']=="June") {echo "selected=\"yes\"";} ?>>June</option>
  <option <?php if($_SESSION['month']=="July") {echo "selected=\"yes\"";} ?>>July</option>
  <option <?php if($_SESSION['month']=="August") {echo "selected=\"yes\"";} ?>>August</option>
  <option <?php if($_SESSION['month']=="September") {echo "selected=\"yes\"";} ?>>September</option>
  <option <?php if($_SESSION['month']=="October") {echo "selected=\"yes\"";} ?>>October</option>
  <option <?php if($_SESSION['month']=="November") {echo "selected=\"yes\"";} ?>>November</option>
  <option <?php if($_SESSION['month']=="December") {echo "selected=\"yes\"";} ?>>December</option>
  </select>
  </li>
  <li>
  <p>Third, choose the day that you want to skydive.</p>
  <select name="day">
  <option <?php if($_SESSION['day']=="01") {echo "selected=\"yes\"";} ?>>01</option>
  <option <?php if($_SESSION['day']=="02") {echo "selected=\"yes\"";} ?>>02</option>
  <option <?php if($_SESSION['day']=="03") {echo "selected=\"yes\"";} ?>>03</option>
  <option <?php if($_SESSION['day']=="04") {echo "selected=\"yes\"";} ?>>04</option>
  <option <?php if($_SESSION['day']=="05") {echo "selected=\"yes\"";} ?>>05</option>
  <option <?php if($_SESSION['day']=="06") {echo "selected=\"yes\"";} ?>>06</option>
  <option <?php if($_SESSION['day']=="07") {echo "selected=\"yes\"";} ?>>07</option>
  <option <?php if($_SESSION['day']=="08") {echo "selected=\"yes\"";} ?>>08</option>
  <option <?php if($_SESSION['day']=="09") {echo "selected=\"yes\"";} ?>>09</option>
  <option <?php if($_SESSION['day']=="10") {echo "selected=\"yes\"";} ?>>10</option>
  <option <?php if($_SESSION['day']=="11") {echo "selected=\"yes\"";} ?>>11</option>
  <option <?php if($_SESSION['day']=="12") {echo "selected=\"yes\"";} ?>>12</option>
  <option <?php if($_SESSION['day']=="13") {echo "selected=\"yes\"";} ?>>13</option>
  <option <?php if($_SESSION['day']=="14") {echo "selected=\"yes\"";} ?>>14</option>
  <option <?php if($_SESSION['day']=="15") {echo "selected=\"yes\"";} ?>>15</option>
  <option <?php if($_SESSION['day']=="16") {echo "selected=\"yes\"";} ?>>16</option>
  <option <?php if($_SESSION['day']=="17") {echo "selected=\"yes\"";} ?>>17</option>
  <option <?php if($_SESSION['day']=="18") {echo "selected=\"yes\"";} ?>>18</option>
  <option <?php if($_SESSION['day']=="19") {echo "selected=\"yes\"";} ?>>19</option>
  <option <?php if($_SESSION['day']=="20") {echo "selected=\"yes\"";} ?>>20</option>
  <option <?php if($_SESSION['day']=="21") {echo "selected=\"yes\"";} ?>>21</option>
  <option <?php if($_SESSION['day']=="22") {echo "selected=\"yes\"";} ?>>22</option>
  <option <?php if($_SESSION['day']=="23") {echo "selected=\"yes\"";} ?>>23</option>
  <option <?php if($_SESSION['day']=="24") {echo "selected=\"yes\"";} ?>>24</option>
  <option <?php if($_SESSION['day']=="25") {echo "selected=\"yes\"";} ?>>25</option>
  <option <?php if($_SESSION['day']=="26") {echo "selected=\"yes\"";} ?>>26</option>
  <option <?php if($_SESSION['day']=="27") {echo "selected=\"yes\"";} ?>>27</option>
  <option <?php if($_SESSION['day']=="28") {echo "selected=\"yes\"";} ?>>28</option>
  <option <?php if($_SESSION['day']=="29") {echo "selected=\"yes\"";} ?>>29</option>
  <option <?php if($_SESSION['day']=="30") {echo "selected=\"yes\"";} ?>>30</option>
  <option <?php if($_SESSION['day']=="31") {echo "selected=\"yes\"";} ?>>31</option>
  </select>
  </li>
  <li>
  <p>Fourth, choose the time that you want to skydive.</p>
  <select name="time">
  <option <?php if($_SESSION['time']=="8:00 am") {echo "selected=\"yes\"";} ?>>8:00 am</option>
  <option <?php if($_SESSION['time']=="10:00 am") {echo "selected=\"yes\"";} ?>>10:00 am</option>
  <option <?php if($_SESSION['time']=="1:00 pm") {echo "selected=\"yes\"";} ?>>1:00 pm</option>
  <option <?php if($_SESSION['time']=="3:00 pm") {echo "selected=\"yes\"";} ?>>3:00 pm</option>
  <option <?php if($_SESSION['time']=="5:00 pm") {echo "selected=\"yes\"";} ?>>5:00 pm</option>
  </select>
  </li>
  </ol>
  </div><!--END DROPDOWNFORM-->
  <div id="textform">
  <p>Enter all of the following information and click the submit button to finalize your registration.</p><br />
  <ol>
  <li><text>Name:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</text><input type="text" name="name" value="<?php echo $_SESSION['name']; ?>" /></li>
  <li><text>Phone Number:&nbsp;&nbsp;&nbsp;</text><input type="text" name="phone" value="<?php echo $_SESSION['phone']; ?>" /></li>
  <li><text>Email:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</text><input type="text" name="email" value="<?php echo $_SESSION['email']; ?>" /></li>
  </ol>
  <input type="submit" value="submit" />
  </div><!--END TEXTFORM-->
  </form>
  </div><!--END CONTENT-->

  <div style="clear:both"></div>
</div><!--END MAIN-->

<?php
include 'footer.txt';
?>

</html>
