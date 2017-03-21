<html>
<body>
<?php
include '../pages/databaseconnect.php';
mysql_query("CREATE TABLE reply(
id INT NOT NULL AUTO_INCREMENT,
PRIMARY KEY(id),
  topic VARCHAR(30),
  creator VARCHAR(30),
  date VARCHAR(30),
  content VARCHAR(1000),
  time INT)")
  or die(mysql_error());
echo "Table Created!";
?>
</body>
</html>
