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
  <td rowspan="<?php print $rowspan; ?>">
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
    <?php print $row; ?>
  </div>
  </td>
<?php endforeach; ?>
<?php } ?>
