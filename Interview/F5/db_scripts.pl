#!/usr/bin/perl
use DBI;
use strict;

my $driver = "oracle";
my $database = "mydb";
my $username = "Test";
my $password = "########";
my ($emp_id, $emp_name, $emp_age, $q_age) = @ARGV;

$dsn = "DBI:$driver:database=$database";

$dbh = DBI->connect($dsn,$username,$password) or die $DBI::errstr;

$sth = $dbh->prepare("INSERT INTO EMPLOYEE (EMP_ID, EMP_NAME, EMP_AGE)
						VALUES (?,?,?)");

$sth->execute($emp_id, $emp_name, $emp_age);
$sth->finish();

$dbh->commit or die $DBI::errstr;

$sth = $dbh->prepare("SELECT EMP_ID, EMP_NAME FROM EMPLOYEE
						WHERE EMP_AGE > ?");

$sth->execute($q_age);	

while(@row = $sth->fetchrow_array()){
	my($t_emp_id, $t_rmp_name) = @row;
}

$sth->finish();

$dbh->disconnect;
