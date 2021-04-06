<?php

 session_start()

 ?>

 <!DOCTYPE html>
 <html>
   <body>

   <?php
    
    
    echo" varaible naem :". $_SESSION["name"]."<br>";
    echo "Favorite color is " . $_SESSION["favcolor"] . ".<br>";
    echo "Favorite animal is " . $_SESSION["favanimal"] . ".";

    // print_r($_SESSION);

    session_unset();

// destroy the session
  session_destroy();
    ?>

</body>
</html>