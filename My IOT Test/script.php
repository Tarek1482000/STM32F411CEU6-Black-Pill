<?php
if (isset($_GET['status'])) {
    $myfile = fopen("status.txt", "w") or die("Unable to open file!");
    if ($_GET['status'] == 'on') {
        fwrite($myfile, '1') or die("Unable to write to file!");
        fclose($myfile);
        header("Location: ON.html");
        exit;
    } elseif ($_GET['status'] == 'off') {
        fwrite($myfile, '0') or die("Unable to write to file!");
        fclose($myfile);
        header("Location: OFF.html");
        exit;
    } elseif ($_GET['status'] == 'tog') {
        fwrite($myfile, '2') or die("Unable to write to file!");
        fclose($myfile);
        header("Location: TOG.html");
        exit;
    }
}
?>
