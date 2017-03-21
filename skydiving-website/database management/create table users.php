<html>
<body>
<?php
include '../pages/databaseconnect.php';
mysql_query("CREATE TABLE users(
id INT NOT NULL AUTO_INCREMENT,
PRIMARY KEY(id),
  name VARCHAR(30),
  password VARCHAR(30),
  email VARCHAR(30),
  date VARCHAR(30),
  level INT)")
  or die(mysql_error());
echo "Table Created!";
?>
</body>
</html>
