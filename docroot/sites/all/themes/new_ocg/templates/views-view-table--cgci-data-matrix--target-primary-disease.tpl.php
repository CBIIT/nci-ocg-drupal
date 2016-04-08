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
<table <?php
if ($classes) {
  print 'class="' . $classes . '" ';
}
?><?php print $attributes; ?> width="100%" style="min-width: 1020px;">
    <?php if (!empty($title) || !empty($caption)) : ?>
    <caption><?php print $caption . $title; ?></caption>
  <?php endif; ?>
  <?php if (!empty($header)) : ?>
    <thead>
      <tr>
        <?php foreach ($header as $field => $label): ?>
          <th id="disease_ch"<?php
          if ($header_classes[$field]) {
            print 'class="colheader ' . $header_classes[$field] . '" ';
          }
          ?> scope="col" style="width: 9%;">
                <?php print $label; ?>
          </th>
        <?php endforeach; ?>
        <th id="patient_ch" class="colheader" scope="col" style="width: 7%;">Patient Data</th>
        <th id="gep_ch" class="colheader" scope="col" style="width: 15%;">Gene Expression</th>
        <th id="cna_ch" class="colheader" scope="col" style="width: 9%;">Copy Number</th>
        <th id="meth_ch" class="colheader" scope="col"style="width: 9%;">Methylation</th>
        <th id="mirna_ch" class="colheader" scope="col" style="width: 9%;">miRNA</th>
        <th id="seq_ch" class="colheader" colspan="4" scope="col" style="width: 42%;">Sequence</th>
        <th id="other_ch" class="colheader" scope="col" style="width: 9%;">Other</th>
      </tr>
    </thead>
  <?php endif; ?>
  <tbody>
    <?php foreach ($rows as $row_count => $row): ?>
      <?php
      $node = $view->result[$row_count]->nid;
      $wrapper = entity_metadata_wrapper('node', $node);
      ?>
      <tr <?php
      if ($row_classes[$row_count]) {
        print 'class="' . implode(' ', $row_classes[$row_count]) . '"';
      }
      ?>>
          <?php foreach ($row as $field => $content): ?>
          <th id="<?php print $node; ?>-bn"class="disease diseasebanner" colspan="11" scope="col">
            <?php print $content; ?>
          </th>
        <?php endforeach; ?>
      </tr>
      <?php foreach ($wrapper->field_target_disease as $disease): ?>
        <tr>
          <th id="<?php print $disease->item_id->value(); ?>-rh"class="diseasebanner rowheader" scope="row">
            <?php if (!empty($disease->field_link->url->value()) && !empty($disease->field_link->title->value())): ?>
              <a target="_blank" href="<?php print $disease->field_link->url->value() ?>"><?php print $disease->field_link->title->value() ?></a>
            <?php endif; ?>
          </th>
          <td class="colSN" headers="<?php print $disease->item_id->value(); ?>-rh patient_ch <?php print $node; ?>-bn">
            <div class="patient-data">
            <?php foreach ($disease->field_patient_data as $patient_data): ?>
              <?php $field_link = field_view_field('field_collection_item', entity_load_single('field_collection_item', $patient_data->item_id->value()), 'field_link'); ?>
              <?php
              if (!empty($field_link['#items'][0]['attributes']['title'])) {
                $link_title = 'title="' . $field_link['#items'][0]['attributes']['title'] . '"';
              } else {
                $link_title = '';
              }
              ?>
              <?php if (!empty($patient_data->field_link->title->value())): ?>
                <?php if ($patient_data->field_availability->value() == 'Unavailable'): ?>
                  <span class='patientcellelem' <?php print $link_title; ?>><?php print $patient_data->field_link->title->value(); ?></span>
                  <br />
                <?php endif; ?>
              <?php endif; ?>
              <?php if (!empty($patient_data->field_link->title->value()) && !empty($patient_data->field_link->url->value())): ?>
                <?php if ($patient_data->field_availability->value() == 'Protected'): ?>
                  <a class="protected patientcellelem" target="_blank" <?php print $link_title; ?> href='<?php print $patient_data->field_link->url->value(); ?>'><?php print $patient_data->field_link->title->value() . '†'; ?></a>
                  <br />
                <?php endif; ?>
                <?php if ($patient_data->field_availability->value() == 'Public'): ?>
                  <a class="public patientcellelem" target="_blank" <?php print $link_title; ?> href='<?php print $patient_data->field_link->url->value(); ?>'><?php print $patient_data->field_link->title->value(); ?></a>
                  <br />
                <?php endif; ?>
              <?php endif; ?>
            <?php endforeach; ?>
            </div>
          </td>
          <?php print views_embed_view('cgci_data_matrix', 'target_gene_expression_column_header', $disease->item_id->value()); ?>
          <?php print views_embed_view('cgci_data_matrix', 'target_copy_number_column_header', $disease->item_id->value()); ?>
          <?php print views_embed_view('cgci_data_matrix', 'target_methylation_column_header', $disease->item_id->value()); ?>
          <?php print views_embed_view('cgci_data_matrix', 'target_mirna_column_header', $disease->item_id->value()); ?>
          <?php print views_embed_view('cgci_data_matrix', 'target_column_header', $disease->item_id->value()); ?>
          <?php print views_embed_view('cgci_data_matrix', 'target_other_column_header', $disease->item_id->value()); ?>
    </tr>
  <?php endforeach; ?>
<?php endforeach; ?>
</tbody>
</table>