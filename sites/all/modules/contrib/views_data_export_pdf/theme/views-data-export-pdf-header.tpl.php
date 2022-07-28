<?php

/**
 * @file
 * Theme export DPF header.
 */
?>

<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <style>
        table td, table th {
            border: 1px solid #ccc;
        }
    </style>
  <?php print (isset($head) && !empty($head)) ? $head : ""; ?>
</head>
<body>
<table border="0" cellpadding="5" cellspacing="0">
  <?php print $header_row; ?>
    <tbody>
