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
<table <?php if ($classes) { print 'class="'. $classes . '" '; } ?><?php print $attributes; ?> width="100%">
   <?php if (!empty($title) || !empty($caption)) : ?>
     <caption><?php print $caption . $title; ?></caption>
  <?php endif; ?>
  <?php if (!empty($header)) : ?>
    <thead>
      <tr>
        <?php foreach ($header as $field => $label): ?>
          <th id="projtitle_ch" class="colheader" scope="col">
            <?php print $label; ?>
          </th>
        <?php endforeach; ?>
        <th id="expapp_ch" class="colheader" scope="col">Experimental<br>Approaches</th>
        <th id="data_ch" class="colheader" scope="col">Data</th>
        <th id="pi_ch" class="colheader" scope="col">Principal<br>Investigator</th>
        <th id="contact_ch" class="colheader" scope="col">Contact Name</th>
      </tr>
    </thead>
  <?php endif; ?>
  <tbody>
    <?php foreach ($rows as $row_count => $row): ?>
      <tr <?php if ($row_classes[$row_count]) { print 'class="' . implode(' ', $row_classes[$row_count]) .'"';  } ?>>
        <?php foreach ($row as $field => $content): ?>
          <th id="broad_bn" scope="col" colspan="5" class="projbanner">
            <?php print $content; ?>
          </th>
        <?php endforeach; ?>
        <?php print views_embed_view('ctd2_data_portal', 'project_title', $result[$row_count]->nid); ?>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>
