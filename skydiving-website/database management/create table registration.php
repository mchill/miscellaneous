<html>
<body>
<?php
include '../pages/databaseconnect.php';
mysql_query("CREATE TABLE registration(
id INT NOT NULL AUTO_INCREMENT,
PRIMARY KEY(id),
  year INT,
  month VARCHAR(30),
  day INT,
  time VARCHAR(30),
  status VARCHAR(30),
  name VARCHAR(30),
  phone VARCHAR(30),
  email VARCHAR(30))")
  or die(mysql_error());
echo "Table Created!";
?>
</body>
</html>
