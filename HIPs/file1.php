<html>
<head>
<title>Opening and reading a file line by line</title>
</head>
<body>
<?php
//session_start();
$filename = "data.txt";
$fp = fopen( $filename, "r" ) or die("Couldn't open $filename");

/*imagecreate($data)
{
$img = imagecreatetruecolor(80,30);

$white = imagecolorallocate($img, 255, 255, 255);
$black = imagecolorallocate($img, 0, 0, 0);
$grey = imagecolorallocate($img,150,150,150);
$red = imagecolorallocate($img, 255, 0, 0);
$pink = imagecolorallocate($img, 200, 0, 150);

for($i=1;$i<=rand(1,5);$i++){
    $color = (rand(1,2) == 1) ? $pink : $red;
    imageline($img,rand(5,70),rand(5,20), rand(5,70)+5,rand(5,20)+5, $color);
}

imagefill($img, 0, 0, $white);

$string = $data;
$_SESSION['string'] = $string;

imagettftext($img, 11, 0, 10, 20, $black, "calibri.ttf", $string);

header("Content-type: image/png");
imagepng($img);
imagedestroy($img);
}*/



$i = 0;


while ( ! feof( $fp ) ) {

if($i == 0)
$word1 = fgets( $fp, 1024 );


if($i == 1)
$word2 = fgets( $fp, 1024 );


if($i == 2)
$j= fgets( $fp, 1024 );


if($i == 3)
$k= fgets( $fp, 1024 );

   
if($i == 4)
break;

$i++;

}


fclose($fp);


if($j > $k)
{
$l = $j;
$j = $k;
$k = $l;
}

$j=$j+4;
$k=$k+4;

$i = 0;

$fp = fopen( $filename, "r" ) or die("Couldn't open $filename");

while ( ! feof( $fp ) ) {

$line = fgets( $fp, 1024 );

if($i>=4 && $i!=$j && $i!=$k)
{
echo "$line";
$i=rand(97,122);
echo chr($i);
}

if($i == $j)
{
echo "$word2";
$i=rand(97,122);
echo chr($i);
}

if($i == $k)
{
echo "$word1";
$i=rand(97,122);
echo chr($i);
}

$i++;

}

fclose($fp);

?>
</body>
</html>
