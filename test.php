<?php
srand((int)($argv[1]));
echo rand();
echo "\n";
$rand = array();
$i = 5;
$d = '';
$_d = '';
 $token = '';
  for ($i = 0; $i < 5; ++$i) {
    $token .= (string)rand();
  }
  $token = sha1($token);
  echo  "\n";
  echo $token;
?>
 
