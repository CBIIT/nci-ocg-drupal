<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */

?>
<?php if (!empty($view->result[0]->field_collection_item_field_data_field_experimental_approach)) { ?>
  <?php if (!empty($rows[0])) { ?>
    <?php
    if (!empty($view->result[0]->field_field_span_rows)) {
      $rowspan = $view->result[0]->field_field_span_rows[0]['rendered']['#markup'];
    } else {
      $rowspan = 1;
    }
    ?>
    <?php foreach ($rows as $id => $row): ?>
      <td width="14%" class="outer colSW" rowspan="<?php print $rowspan; ?>" style="vertical-align: middle;" headers="expapp_ch <?php print $view->result[0]->nid . '_bn ' . $view->args[0] . '_rh' . ctd2_row_classes($view->args[0], $view->result[0]->nid, 'field_experimental_approaches'); ?>">
        <div<?php if ($classes_array[$id]) {
        print ' class="' . $classes_array[$id] . '"';
      } ?>>
      <?php print $row; ?>
        </div>
      </td>
    <?php endforeach; ?>
  <?php } ?>
<?php } elseif (empty($view->result[0]->field_collection_item_field_data_field_experimental_approach) && $view->result[0]->field_field_internal[0]['rendered']['#markup'] == 'No') { ?>
  <?php
  $node = node_load($view->result[0]->nid);
  $countrows = field_get_items('node', $node, 'field_row');
  $current_row = current(array_column($countrows, 'value'));

  if ($view->result[0]->field_collection_item_field_data_field_row_item_id == $current_row) {
    ?>
    <td width="14%" class="outer colSW" rowspan="1" style="vertical-align: middle;" headers="expapp_ch <?php print $view->result[0]->nid . '_bn ' . $view->args[0] . '_rh' . ctd2_row_classes($view->args[0], $view->result[0]->nid, 'field_experimental_approaches'); ?>"></td>
  <?php
  } else {
    $span_included = FALSE;
    $old_rows = $countrows;
    $row_number = array_search($view->result[0]->field_collection_item_field_data_field_row_item_id, array_column($countrows, 'value'));
    array_splice($countrows, $row_number);

    foreach ($countrows as $countrow) {
      $fc_item = field_collection_item_load($countrow['value']);
      if (!empty($fc_item->field_experimental_approaches)) {
        $ea = $fc_item->field_experimental_approaches[LANGUAGE_NONE][0]['value'];
        $ea_item = field_collection_item_load($ea);
        $span_number = $ea_item->field_span_rows[LANGUAGE_NONE][0]['value'];

        if (($span_number - 1) >= $row_number) {
          $span_included = TRUE;
        }
      }
    }
    if ($span_included == FALSE) {
      ?>
      <td width="14%" class="outer colSW" rowspan="1" style="vertical-align: middle;" headers="expapp_ch <?php print $view->result[0]->nid . '_bn ' . $view->args[0] . '_rh' . ctd2_row_classes($view->args[0], $view->result[0]->nid, 'field_experimental_approaches'); ?>"></td>    
    <?php
    }
  }
  ?>

<?php } ?>