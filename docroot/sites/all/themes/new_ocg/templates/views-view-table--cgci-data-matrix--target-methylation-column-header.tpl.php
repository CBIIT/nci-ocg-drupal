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
foreach ($rows as $row) {
  
  switch ($row['field_availability']) {
    case 'Unavailable':
      $header = '<span' . $rows[$column1]['field_link'] . '>' . $row['field_link'] . '</span><br />';
      break;
    case 'Protected':
      $header = '<a class="protected" target="_blank"' . $row['field_link'] . ' href="' . $row['field_link_1'] . '">' . $row['field_link'] . '</a><br />';
      break;
    case 'Public':
      $header = '<a class="public" target="_blank"' . $row['field_link'] . ' href="' . $row['field_link_1'] . '">' . $row['field_link'] . '</a><br />';
      break;
    default:
      $header = '';
  }
  ?>
  <td class='outer colN' headers="<?php print $row['item_id_1']; ?>-rh meth_ch <?php print $row['nid']; ?>-bn">
    <table class="cell">
      <tbody>
        <tr>
          <th id="<?php print $row['item_id_1']; ?>_meth" scope="col" class="cellheader">
      <div class="cellheader"><?php print $header; ?></div>
    </th>
  </tr>
  <tr>
    <td class="cellbody" headers="<?php print $row['item_id_1']; ?>_rh meth_ch <?php print $row['nid']; ?>_bn">
      <div class='cellbody'><?php print $row['view']; ?></div>
    </td>
  </tr>
  </tbody>
  </table>
  </td>
<?php } ?>