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
if (!empty($view->result[0]->field_field_span_rows)) {
  $rowspan = $view->result[0]->field_field_span_rows[0]['rendered']['#markup'];
} else {
  $rowspan = 1;
}
?>
<?php foreach ($rows as $id => $row): ?>
  <td width="10%" class="outer colNM" rowspan="<?php print $rowspan; ?>" style="vertical-align: middle;" headers="contact_ch <?php print $view->result[0]->nid . '_bn ' . $view->args[0] . '_rh' . ctd2_row_classes($view->args[0], $view->result[0]->nid, 'field_ctd2_contact_name');?>">
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
    <?php print $row; ?>
  </div>
  </td>
<?php endforeach; ?>
<?php } ?>
