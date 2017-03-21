<html>
<body>
<?php
include '../pages/databaseconnect.php';

$counter=1;

while ($counter<32) {
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','January','$counter','8:00 am')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','January','$counter','10:00 am')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','January','$counter','1:00 pm')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','January','$counter','3:00 pm')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','January','$counter','5:00 pm')") or die(mysql_error());
$counter=$counter+1;
}
echo "January finished!";
$counter=1;
while ($counter<29) {
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','February','$counter','8:00 am')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','February','$counter','10:00 am')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','February','$counter','1:00 pm')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','February','$counter','3:00 pm')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','February','$counter','5:00 pm')") or die(mysql_error());
$counter=$counter+1;
}
echo "February finished!";
$counter=1;
while ($counter<32) {
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','March','$counter','8:00 am')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','March','$counter','10:00 am')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','March','$counter','1:00 pm')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','March','$counter','3:00 pm')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','March','$counter','5:00 pm')") or die(mysql_error());
$counter=$counter+1;
}
echo "March finished!";
$counter=1;
while ($counter<31) {
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','April','$counter','8:00 am')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','April','$counter','10:00 am')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','April','$counter','1:00 pm')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','April','$counter','3:00 pm')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','April','$counter','5:00 pm')") or die(mysql_error());
$counter=$counter+1;
}
echo "April finished!";
$counter=1;
while ($counter<32) {
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','May','$counter','8:00 am')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','May','$counter','10:00 am')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','May','$counter','1:00 pm')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','May','$counter','3:00 pm')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','May','$counter','5:00 pm')") or die(mysql_error());
$counter=$counter+1;
}
echo "May finished!";
$counter=1;
while ($counter<31) {
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','June','$counter','8:00 am')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','June','$counter','10:00 am')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','June','$counter','1:00 pm')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','June','$counter','3:00 pm')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','June','$counter','5:00 pm')") or die(mysql_error());
$counter=$counter+1;
}
echo "June finished!";
$counter=1;
while ($counter<32) {
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','July','$counter','8:00 am')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','July','$counter','10:00 am')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','July','$counter','1:00 pm')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','July','$counter','3:00 pm')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','July','$counter','5:00 pm')") or die(mysql_error());
$counter=$counter+1;
}
echo "July finished!";
$counter=1;
while ($counter<31) {
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','August','$counter','8:00 am')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','August','$counter','10:00 am')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','August','$counter','1:00 pm')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','August','$counter','3:00 pm')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','August','$counter','5:00 pm')") or die(mysql_error());
$counter=$counter+1;
}
echo "August finished!";
$counter=1;
while ($counter<32) {
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','September','$counter','8:00 am')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','September','$counter','10:00 am')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','September','$counter','1:00 pm')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','September','$counter','3:00 pm')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','September','$counter','5:00 pm')") or die(mysql_error());
$counter=$counter+1;
}
echo "September finished!";
$counter=1;
while ($counter<32) {
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','October','$counter','8:00 am')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','October','$counter','10:00 am')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','October','$counter','1:00 pm')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','October','$counter','3:00 pm')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','October','$counter','5:00 pm')") or die(mysql_error());
$counter=$counter+1;
}
echo "October finished!";
$counter=1;
while ($counter<31) {
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','November','$counter','8:00 am')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','November','$counter','10:00 am')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','November','$counter','1:00 pm')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','November','$counter','3:00 pm')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','November','$counter','5:00 pm')") or die(mysql_error());
$counter=$counter+1;
}
echo "November finished!";
$counter=1;
while ($counter<32) {
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','December','$counter','8:00 am')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','December','$counter','10:00 am')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','December','$counter','1:00 pm')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','December','$counter','3:00 pm')") or die(mysql_error());
mysql_query("INSERT INTO registration(year,month,day,time) VALUES('2011','December','$counter','5:00 pm')") or die(mysql_error());
$counter=$counter+1;
}
echo "December finished!";

echo "Wow. This actually worked.";

?>
</body>
</html>
