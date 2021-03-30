<?php 
 include("insert1.php");
 ?>

<!DOCTYPE html>
<html>
    <body>
        
   <form action="" method="POST">

     Name : <input type="text" name="name">
     Mob  : <input type="text" name = "mob">
     <input type="submit"name ="submit">
   </form>
     <?php
      if(isset($_POST['submit']))
      {
          $name = $_POST['name'];
          $mob = $_POST['mob'];

          $res = mysqli_query($mysqli,"INSERT into student values('$name','$mob')");
          if($res){
            echo "success";
        }
        else
         echo "Failure";

         
      }
      
   ?>


      
    </body>
</html>