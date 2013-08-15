<?php


$device = $_GET['device'];
$state = $_GET['state'];

exec( "./send " . $device . " " . $state );

?>