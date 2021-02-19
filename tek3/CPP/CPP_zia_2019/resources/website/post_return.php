<?php
    function Sanitize($str) {
        return filter_var($str, FILTER_SANITIZE_STRING);
    }

    function validEmail() {
        if (isset($_POST['email'])) {
            if (filter_var($_POST['email'], FILTER_VALIDATE_EMAIL)) {
                return Sanitize($_POST['email']);
            }
            return "Invalid Email";
        } else {
            return "No email specified";
        }
    }

    function validPassword() {
        if (isset($_POST['password'])) {
            return password_hash(Sanitize($_POST['password']), PASSWORD_ARGON2ID, ['memory_cost' => 1<<17, 'time_cost' => 4, 'threads' => 3]);
        } else {
            return "No password specified";
        }
    }

    function validAddress() {
        if (isset($_POST['address'])) {
            return Sanitize($_POST['address']);
        } else {
            return "No address specified";
        }
    }

    function validCity() {
        if (isset($_POST['city'])) {
            return Sanitize($_POST['city']);
        } else {
            return "No city specified";
        }
    }

    function validState() {
        if (isset($_POST['state'])) {
            return Sanitize($_POST['state']);
        } else {
            return "No state specified";
        }
    }

    function validZip() {
        if (isset($_POST['zip'])) {
            return Sanitize($_POST['zip']);
        } else {
            return "No zip specified";
        }
    }
?>
<!doctype html>
<html lang="en">
<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
    <link rel="stylesheet" href="./assets/style.css">
    <link rel="shortcut icon" href="./assets/cagette.png" />
    <title>ZIA - Les 6 Cagettes</title>
</head>
<body>
<div class="menu">
    <!-- Image and text -->
    <nav class="navbar navbar-light navbar-colored">
        <a class="navbar-brand" href="/">
            <img src="./assets/cagette.png" width="30" height="30" class="d-inline-block align-top" alt="">
            Les 6 Cagettes
        </a>
    </nav>
</div>

<div class="container">
    <div class="card mb-3 card-head">
        <div class="row no-gutters">
            <div class="col-md-4">
                <img src="./assets/marsala.jpg" class="card-img" alt="Sale Arabe">
            </div>
            <div class="col-md-8">
                <div class="card-body">
                    <h5 class="card-title">Form result</h5>
                    <p class="card-text">
                        <b>Email:</b> <?php echo validEmail(); ?>
                    </p>
                    <p class="card-text">
                        <b>Password (Argon2i with Memory Cost, Time Cost and Thread):</b> <?php echo validPassword(); ?>
                    </p>
                    <p class="card-text">
                        <b>Address:</b> <?php echo validAddress(); ?>
                    </p>
                    <p class="card-text">
                        <b>City:</b> <?php echo validCity(); ?>
                    </p>
                    <p class="card-text">
                        <b>State:</b> <?php echo validState(); ?>
                    </p>
                    <p class="card-text">
                        <b>Zip:</b> <?php echo validZip(); ?>
                    </p>
                </div>
            </div>
        </div>
    </div>
</div>
<!-- Optional JavaScript -->
<!-- jQuery first, then Popper.js, then Bootstrap JS -->
<script src="https://code.jquery.com/jquery-3.4.1.slim.min.js" integrity="sha384-J6qa4849blE2+poT4WnyKhv5vZF5SrPo0iEjwBvKU7imGFAV0wwj1yYfoRSJoZ+n" crossorigin="anonymous"></script>
<script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.0/dist/umd/popper.min.js" integrity="sha384-Q6E9RHvbIyZFJoft+2mJbHaEWldlvI9IOYy5n3zV9zzTtmI3UksdQRVvoxMfooAo" crossorigin="anonymous"></script>
<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/js/bootstrap.min.js" integrity="sha384-wfSDF2E50Y2D1uUdj0O3uMBJnjuUD4Ih7YwaYd1iqfktj0Uod8GCExl3Og8ifwB6" crossorigin="anonymous"></script>
</body>
</html>