<?php
/**
 * @file
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $caption: The caption for this table. May be empty.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * @ingroup views_templates
 */
?>
<?php
$column1 = array_search(1, array_column($rows, 'field_column_number'));

if (!is_numeric($column1)) {
  ?>
  <td class='outer colN' headers="<?php print $rows[$column1]['item_id_1']; ?>-rh seq_ch <?php print $rows[$column1]['nid']; ?>-bn">
    <div class="cellheader"></div>
    <div class='cellbody'></div>
  </td>
<?php } else { ?>
  <?php if ($rows[$column1]['field_availability'] == 'Unavailable'): ?>
    <?php $header = '<span' . $rows[$column1]['field_link'] . '>' . $rows[$column1]['field_link'] . '</span><br />'; ?>
  <?php endif; ?>
  <?php if ($rows[$column1]['field_availability'] == 'Protected'): ?>
    <?php $header = '<a class="protected" target="_blank"' . $rows[$column1]['field_link'] . ' href="' . $rows[$column1]['field_link_1'] . '">' . $rows[$column1]['field_link'] . '†</a><br />'; ?>
  <?php endif; ?>
  <?php if ($rows[$column1]['field_availability'] == 'Public'): ?>
    <?php $header = '<a class="public" target="_blank"' . $rows[$column1]['field_link'] . ' href="' . $rows[$column1]['field_link_1'] . '">' . $rows[$column1]['field_link'] . '*</a><br />'; ?>
  <?php endif; ?>
  <td class='outer colN' headers="<?php print $rows[$column1]['item_id_1']; ?>-rh seq_ch <?php print $rows[$column1]['nid']; ?>-bn">
    <table class="cell">
      <tbody>
        <tr>
          <th id="<?php print $rows[$column1]['item_id_1']; ?>_1" scope="col" class="cellheader">
      <div class="cellheader"><?php print $header; ?></div>
    </th>
  </tr>
  <tr>
    <td class="cellbody" headers="<?php print $rows[$column1]['item_id_1']; ?>_rh seq_ch <?php print $rows[$column1]['nid']; ?>_bn <?php print $rows[$column1]['item_id_1']; ?>_1">
      <div class='cellbody'><?php print $rows[$column1]['view']; ?></div>
    </td>
  </tr>
  </tbody>
  </table>
  </td>
<?php } ?>

<?php
$column2 = array_search(2, array_column($rows, 'field_column_number'));

if (!is_numeric($column2)) {
  ?>
  <td class='outer colN' headers="<?php print $rows[$column2]['item_id_1']; ?>-rh seq_ch <?php print $rows[$column2]['nid']; ?>-bn">
    <div class="cellheader"></div>
    <div class='cellbody'></div>
  </td>
<?php } else { ?>
  <?php if ($rows[$column2]['field_availability'] == 'Unavailable'): ?>
    <?php $header = '<span' . $rows[$column2]['field_link'] . '>' . $rows[$column2]['field_link'] . '</span><br />'; ?>
  <?php endif; ?>
  <?php if ($rows[$column2]['field_availability'] == 'Protected'): ?>
    <?php $header = '<a class="protected" target="_blank"' . $rows[$column2]['field_link'] . ' href="' . $rows[$column2]['field_link_1'] . '">' . $rows[$column2]['field_link'] . '†</a><br />'; ?>
  <?php endif; ?>
  <?php if ($rows[$column2]['field_availability'] == 'Public'): ?>
    <?php $header = '<a class="public" target="_blank"' . $rows[$column2]['field_link'] . ' href="' . $rows[$column2]['field_link_1'] . '">' . $rows[$column2]['field_link'] . '*</a><br />'; ?>
  <?php endif; ?>
  <td class='outer colN' headers="<?php print $rows[$column2]['item_id_1']; ?>-rh seq_ch <?php print $rows[$column2]['nid']; ?>-bn">
    <table class="cell">
      <tbody>
        <tr>
          <th id="<?php print $rows[$column2]['item_id_1']; ?>_2" scope="col" class="cellheader">
    <div class="cellheader"><?php print $header; ?></div>
    </th>
  </tr>
  <tr>
    <td class="cellbody" headers="<?php print $rows[$column2]['item_id_1']; ?>_rh seq_ch <?php print $rows[$column2]['nid']; ?>_bn <?php print $rows[$column2]['item_id_1']; ?>_2">
    <div class='cellbody'><?php print $rows[$column2]['view']; ?></div>
    </td>
  </tr>
  </tbody>
  </table>
  </td>
<?php } ?>

<?php
$column3 = array_search(3, array_column($rows, 'field_column_number'));

if (!is_numeric($column3)) {
  ?>
  <td class='outer colN' headers="<?php print $rows[$column3]['item_id_1']; ?>-rh seq_ch <?php print $rows[$column3]['nid']; ?>-bn">
    <div class="cellheader"></div>
    <div class='cellbody'></div>
  </td>
<?php } else { ?>
  <?php if ($rows[$column3]['field_availability'] == 'Unavailable'): ?>
    <?php $header = '<span' . $rows[$column3]['field_link'] . '>' . $rows[$column3]['field_link'] . '</span><br />'; ?>
  <?php endif; ?>
  <?php if ($rows[$column3]['field_availability'] == 'Protected'): ?>
    <?php $header = '<a class="protected" target="_blank"' . $rows[$column3]['field_link'] . ' href="' . $rows[$column3]['field_link_1'] . '">' . $rows[$column3]['field_link'] . '†</a><br />'; ?>
  <?php endif; ?>
  <?php if ($rows[$column3]['field_availability'] == 'Public'): ?>
    <?php $header = '<a class="public" target="_blank"' . $rows[$column3]['field_link'] . ' href="' . $rows[$column3]['field_link_1'] . '">' . $rows[$column3]['field_link'] . '*</a><br />'; ?>
  <?php endif; ?>
  <td class='outer colN' headers="<?php print $rows[$column3]['item_id_1']; ?>-rh seq_ch <?php print $rows[$column3]['nid']; ?>-bn">
    <table class="cell">
      <tbody>
        <tr>
          <th id="<?php print $rows[$column3]['item_id_1']; ?>_3" scope="col" class="cellheader">
    <div class="cellheader"><?php print $header; ?></div>
    </th>
  </tr>
  <tr>
    <td class="cellbody" headers="<?php print $rows[$column3]['item_id_1']; ?>_rh seq_ch <?php print $rows[$column3]['nid']; ?>_bn <?php print $rows[$column3]['item_id_1']; ?>_3">
    <div class='cellbody'><?php print $rows[$column3]['view']; ?></div>
    </td>
  </tr>
  </tbody>
  </table>
  </td>
<?php } ?>

