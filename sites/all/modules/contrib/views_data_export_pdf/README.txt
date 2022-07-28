Views Data Export PDF
==========================

Description
-----------
This module extends Views Data Export module to allow PDF files export.
Possibly it will support more formats in the future.

Requirements
------------
1. Views Data Export
2. WkHtmlToPdf
3. phpwkhtmltopdf module (https://www.drupal.org/project/phpwkhtmltopdf)
4. Libraries

Installation
------------
1. Place WkHtmlToPdf library under sites/all/libraries folder, so the resulting
structure should look like:
- sites/all/libraries/phpwkhtmltopdf
- sites/all/libraries/phpwkhtmltopdf/scr
- sites/all/libraries/phpwkhtmltopdf/scr/Pdf.php
[...]
2. Enable the module.

Usage
-----
Follow the instructions from README.txt of the Views Data Export module.

Credits
-------
Sergey Grigorenko <https://www.drupal.org/u/svipsa>
