<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($rows[0])) { ?>
<?php 

$rowspan = 1;

?>
<?php foreach ($rows as $id => $row): ?>
  <td width="8%" class="outer colNM" rowspan="<?php print $rowspan; ?>" style="vertical-align: middle;" headers="contact_ch <?php print $view->result[0]->nid . '_bn ' . $view->args[0] . '_rh';?>">
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
    <?php print $row; ?>
  </div>
  </td>
<?php endforeach; ?>
<?php } ?>
