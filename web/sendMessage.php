<?php

$device = escapeshellarg($_GET['device']);
$state = escapeshellarg($_GET['state']);

exec( "sudo ./send $device $state");

?>
