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
<br />
<p class="expand-flex"><a class="open-close-all" href="#">Expand All</a> <a class="open-close-current" href="#">Expand All Current Projects</a> <a class="open-close-completed" href="#">Expand All Completed Projects</a></p>

<table <?php if ($classes) { print 'class="'. $classes . '" '; } ?><?php print $attributes; ?> width="100%">
   <?php if (!empty($title) || !empty($caption)) : ?>
     <caption><?php print $caption . $title; ?></caption>
  <?php endif; ?>
  <?php //if (!empty($header)) : ?>
    <thead>
      <tr>
        <th id="projtitle_ch" class="colheader" scope="col" width="46%">Project Title</th>
        <th id="expapp_ch" class="colheader" scope="col" width="14%">Experimental<br>Approaches</th>
        <th id="data_ch" class="colheader" scope="col" width="9%">Data</th>
        <th id="pi_ch" class="colheader" scope="col"width="13%">Principal<br>Investigator</th>
        <th id="contact_ch" class="colheader" scope="col" width="10%">Contact Name</th>
        <th id="submission_ch" class="colheader" scope="col" width="8%">Submission<br>Date</th>
      </tr>
    </thead>
  <?php //endif; ?>
  <tbody>
    <?php foreach ($rows as $row_count => $row): ?>
      <tr <?php if ($row_classes[$row_count]) { print 'class="' . implode(' ', $row_classes[$row_count]) .'"';  } ?>>
        <?php foreach ($row as $field => $content): ?>
          <th id="<?php print $result[$row_count]->nid; ?>_bn" scope="col" colspan="6" class="projbanner <?php print $result[$row_count]->field_field_status[0]['rendered']['#markup']; ?>">
            <?php print $content; ?>
          </th>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>
