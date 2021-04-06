<?php 
$cookie_name = "name";
$cookie_val = "value";
setcookie($cookie_name,$cookie_val,time()+3600,"/");


?>

<!DOCTYPE html>
<html>
    <body>
        <?php 
         if(!isset($_COOKIE[$cookie_name]))
          echo"cookie named".$cookie_name."is not set";
        else
          echo"cookie set ".$cookie_name." value is ".$cookie_val."" ;

        ?>
        <?php
if(count($_COOKIE) > 0) {
  echo "Cookies are enabled.";
} else {
  echo "Cookies are disabled.";
}
?>
    </body>

    </html>
