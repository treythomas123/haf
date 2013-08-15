<?php


$device = $_GET['device'];
$state = $_GET['state'];

exec( "sudo ./send " . $device . " " . $state );

?>
