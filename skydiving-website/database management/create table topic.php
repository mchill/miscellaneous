<html>
<body>
<?php
include '../pages/databaseconnect.php';
mysql_query("CREATE TABLE topic(
id INT NOT NULL AUTO_INCREMENT,
PRIMARY KEY(id),
  category VARCHAR(30),
  name VARCHAR(30),
  creator VARCHAR(30),
  date VARCHAR(30),
  content VARCHAR(50000),
  status VARCHAR(30),
  lastreply VARCHAR(30))")
  or die(mysql_error());
echo "Table Created!";
?>
</body>
</html>
