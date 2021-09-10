<?php
ob_start();
session_start();

if(!$_POST['submit']){
    echo "<form method=\"post\" action=\"file1.php\">\n";
    echo "<table border=\"0\" cellspacing=\"3\" cellpadding=\"3\">\n";
    echo "<tr><td>Type The Letters You See Below Into the Box</td></tr>\n";
    echo "<tr><td align=\"center\"><img src=\"file1.php\"></td></tr>\n";
    echo "<tr><td align=\"right\"><input type=\"text\" name=\"image\"></td></tr>\n";
    echo "<tr><td align=\"right\"><input type=\"submit\" name=\"submit\" value=\"Check CAPTCHA\"></td></tr>\n";
    echo "</table></form>\n";
}else {
    $image = $_POST['image'];
    
    if($image == $_SESSION['string']){
        echo "<b>Great success!</b>\n";
    }else {
        echo "<em>Failure!</em>\n";
    }
}

ob_end_flush();
?> 
