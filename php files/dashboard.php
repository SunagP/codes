<?php
//include auth_session.php file on all user panel pages
include("auth_session.php");
?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>Dashboard - Client area</title>
    <link rel="stylesheet" href="style.css" />
</head>
<body>
    <div class="form" style="background-color:rgb(190, 183, 170); border-radius:10px">
        <p>Hey, <?php echo $_SESSION['username']; ?>!</p>
        <p>You are now on user dashboard page.</p>
        <p><a href="https://sunagp.github.io/FashionEcommerce/"><button style="background-color : rgb(180, 153, 109);border-radius:6px;color:white;cursor:pointer" >click here for home page</button></a></p>
        <p><a href="logout.php">Logout</a></p>
    </div>
</body>
</html>