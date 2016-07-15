<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
dpm($view->result);
dpm(field_collection_item_load($view->args));

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
  <td class="outer colSW" rowspan="<?php print $rowspan; ?>" headers="expapp_ch <?php print $view->args[0] . '_rh' ?> broad_bn broad1_rh broad2_rh broad3_rh broad4_rh">
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
    <?php print $row; ?>
  </div>
  </td>
<?php endforeach; ?>
<?php } ?>
