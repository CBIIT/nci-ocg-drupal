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
<table class='views-table cols-0'>
   <?php if (!empty($title) || !empty($caption)) : ?>
     <caption><?php print $caption . $title; ?></caption>
  <?php endif; ?>
  
  <tbody>
    <?php foreach ($rows as $row_count => $row): ?>
      <tr <?php if ($row_classes[$row_count]) { print 'class="' . implode(' ', $row_classes[$row_count]) .'"';  } ?>>
        
          <td>
            <?php if ($row['field_availability'] == 'Unavailable'): ?>
                  <span class='patientcellelem'><?php print $row['field_link']; ?></span>
                  <br />
                <?php endif; ?>
                <?php if ($row['field_availability'] == 'Protected'): ?>
                  <a class="protected patientcellelem" target="_blank" href='<?php print $row['field_link_1']; ?>'><?php print $row['field_link']; ?></a>
                  <br />
                <?php endif; ?>
                <?php if ($row['field_availability'] == 'Public'): ?>
                  <a class="public patientcellelem" target="_blank" href='<?php print $row['field_link_1']; ?>'><?php print $row['field_link']; ?></a>
                  <br />
                <?php endif; ?>
                <?php print $row['view']; ?>
          </td>
        
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>
