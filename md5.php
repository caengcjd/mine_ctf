<?php
srand((int)($argv[1]));
echo rand();
echo "\n";
$rand = array();
$i = 5;
$d = '';
$_d = '';
 $token = '';
while($i--){
    $r = (string)rand();
    $rand = $r;
    $d .= $r;
    //$_d .= 'check[]=';
    //$_d .= $r;
    //$_d .= "&";
}
$_d=sha1($d);
echo sha1($d);
echo "\n";
echo $_d;
echo "\n";
?>
