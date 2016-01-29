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
?><?php print $attributes; ?> width="100%">
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
          ?> scope="col">
                <?php print $label; ?>
          </th>
        <?php endforeach; ?>
        <th id="patient_ch" class="colheader" scope="col">Patient Data</th>
        <th id="gep_ch" class="colheader" scope="col">Gene Expression</th>
        <th id="cna_ch" class="colheader" scope="col">Copy Number</th>
        <th id="mirna_ch" class="colheader" scope="col">miRNA</th>
        <th id="seq_ch" class="colheader" colspan="3" scope="col">Sequence</th>
        <th id="other_ch" class="colheader" scope="col">Other</th>
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
          <th id="<?php print $node; ?>-bn"class="disease diseasebanner" colspan="9" scope="col">
            <?php print $content; ?>
          </th>
        <?php endforeach; ?>
      </tr>
      <?php foreach ($wrapper->field_disease as $disease): ?>
        <tr>
          <th id="<?php print $disease->item_id->value(); ?>-rh"class="diseasebanner rowheader" scope="row">
            <?php if (!empty($disease->field_link->url->value()) && !empty($disease->field_link->title->value())): ?>
              <a href="<?php print $disease->field_link->url->value() ?>"><?php print $disease->field_link->title->value() ?></a>
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
          <?php if ($disease->field_gene_expression->value()) { ?>
            <td class='outer colN' headers="<?php print $disease->item_id->value(); ?>-rh gep_ch <?php print $node; ?>-bn">
              <table class="cell">
                <tbody>
                  <?php foreach ($disease->field_gene_expression->field_column_header as $gene_expression): ?>
                    <tr>
                      <th id="<?php print $disease->item_id->value(); ?>_gep" scope="col" class="cellheader">
                        <?php if (!empty($gene_expression->field_link->title->value())): ?>
                          <?php if ($gene_expression->field_availability->value() == 'Unavailable'): ?>
                            <div class="cellheader"><?php print $gene_expression->field_link->title->value(); ?></div>
                          <?php endif; ?>
                        <?php endif; ?>
                        <?php if (!empty($gene_expression->field_link->title->value()) && !empty($gene_expression->field_link->url->value())): ?>
                          <?php if ($gene_expression->field_availability->value() == 'Protected'): ?>
                            <div class="cellheader"><a class="protected" target="_blank" <?php print $link_title; ?> href='<?php print $gene_expression->field_link->url->value(); ?>'><?php print $gene_expression->field_link->title->value() . '†'; ?></a></div>
                          <?php endif; ?>
                          <?php if ($gene_expression->field_availability->value() == 'Public'): ?>
                            <div class="cellheader"><a class="public" target="_blank" <?php print $link_title; ?> href='<?php print $gene_expression->field_link->url->value(); ?>'><?php print $gene_expression->field_link->title->value(); ?></a></div>
                          <?php endif; ?>
                        <?php endif; ?>
                  </th>
            </tr>
            <tr>
              <td class="cellbody" headers="<?php print $disease->item_id->value(); ?>_rh gep_ch <?php print $node; ?>_bn <?php print $disease->item_id->value(); ?>_gep">
                <div class='cellbody'>
                  <?php foreach ($gene_expression->field_column_values as $i => $column_values): ?>
                    <?php $field_link = field_view_field('field_collection_item', entity_load_single('field_collection_item', $column_values->item_id->value()), 'field_link'); ?>
                    <?php
                    if (!empty($field_link['#items'][0]['attributes']['title'])) {
                      $link_title = 'title="' . $field_link['#items'][0]['attributes']['title'] . '"';
                    } else {
                      $link_title = '';
                    }
                    ?>
                    <?php if (!empty($column_values->field_link->title->value())): ?>
                      <?php if ($column_values->field_availability->value() == 'Unavailable'): ?>
                        <span <?php print $link_title; ?>><?php print $column_values->field_link->title->value(); ?></span>
                        <br />
                      <?php endif; ?>
                    <?php endif; ?>
                    <?php if (!empty($column_values->field_link->title->value()) && !empty($column_values->field_link->url->value())): ?>
                      <?php if ($column_values->field_availability->value() == 'Protected'): ?>
                        <a class="protected" target="_blank" <?php print $link_title; ?> href='<?php print $column_values->field_link->url->value(); ?>'><?php print $column_values->field_link->title->value() . '†'; ?></a>
                        <br />
                      <?php endif; ?>
                      <?php if ($column_values->field_availability->value() == 'Public'): ?>
                        <a class="public" target="_blank" <?php print $link_title; ?> href='<?php print $column_values->field_link->url->value(); ?>'><?php print $column_values->field_link->title->value() . '*'; ?></a>
                        <br />
                      <?php endif; ?>
                    <?php endif; ?>
                  <?php endforeach; ?>
                </div>
              </td>
            </tr>
          <?php endforeach; ?>
        </tbody>
      </table>
      </td>
    <?php } else { ?>
      <td class='outer colN' headers="<?php print $disease->item_id->value(); ?>-rh gep_ch <?php print $node; ?>-bn"><div class="cellheader"></div></td>
    <?php } ?>
    <?php if ($disease->field_copy_number->value()) { ?>
      <td class='outer colW' headers="<?php print $disease->item_id->value(); ?>-rh cna_ch <?php print $node; ?>-bn">
        <table class="cell">
          <tbody>
            <?php foreach ($disease->field_copy_number->field_column_header as $copy_number): ?>
              <tr>
                <th id="<?php print $disease->item_id->value(); ?>_cna" scope="col" class="cellheader">
                  <?php if (!empty($copy_number->field_link->title->value())): ?>
                          <?php if ($copy_number->field_availability->value() == 'Unavailable'): ?>
                            <div class="cellheader"><?php print $copy_number->field_link->title->value(); ?></div>
                          <?php endif; ?>
                        <?php endif; ?>
                        <?php if (!empty($copy_number->field_link->title->value()) && !empty($copy_number->field_link->url->value())): ?>
                          <?php if ($copy_number->field_availability->value() == 'Protected'): ?>
                            <div class="cellheader"><a class="protected" target="_blank" <?php print $link_title; ?> href='<?php print $copy_number->field_link->url->value(); ?>'><?php print $copy_number->field_link->title->value() . '†'; ?></a></div>
                          <?php endif; ?>
                          <?php if ($copy_number->field_availability->value() == 'Public'): ?>
                            <div class="cellheader"><a class="public" target="_blank" <?php print $link_title; ?> href='<?php print $copy_number->field_link->url->value(); ?>'><?php print $copy_number->field_link->title->value(); ?></a></div>
                          <?php endif; ?>
                        <?php endif; ?>
          </th>
        </tr>
        <tr>
          <td class="cellbody" headers="<?php print $disease->item_id->value(); ?>_rh cna_ch <?php print $node; ?>_bn <?php print $disease->item_id->value(); ?>_cna">
            <div class='cellbody'>
              <?php foreach ($copy_number->field_column_values as $i => $column_values): ?>
                <?php $field_link = field_view_field('field_collection_item', entity_load_single('field_collection_item', $column_values->item_id->value()), 'field_link'); ?>
                <?php
                if (!empty($field_link['#items'][0]['attributes']['title'])) {
                  $link_title = 'title="' . $field_link['#items'][0]['attributes']['title'] . '"';
                } else {
                  $link_title = '';
                }
                ?>
                <?php if (!empty($column_values->field_link->title->value())): ?>
                  <?php if ($column_values->field_availability->value() == 'Unavailable'): ?>
                    <span <?php print $link_title; ?>><?php print $column_values->field_link->title->value(); ?></span>
                    <br />
                  <?php endif; ?>
                <?php endif; ?>
                <?php if (!empty($column_values->field_link->title->value()) && !empty($column_values->field_link->url->value())): ?>
                  <?php if ($column_values->field_availability->value() == 'Protected'): ?>
                    <a class="protected" target="_blank" <?php print $link_title; ?> href='<?php print $column_values->field_link->url->value(); ?>'><?php print $column_values->field_link->title->value() . '†'; ?></a>
                    <br />
                  <?php endif; ?>
                  <?php if ($column_values->field_availability->value() == 'Public'): ?>
                    <a class="public" target="_blank" <?php print $link_title; ?> href='<?php print $column_values->field_link->url->value(); ?>'><?php print $column_values->field_link->title->value() . '*'; ?></a>
                    <br />
                  <?php endif; ?>
                <?php endif; ?>
              <?php endforeach; ?>
            </div>
          </td>
        </tr>
      <?php endforeach; ?>
      </tbody>
      </table>
      </td>
    <?php } else { ?>
      <td class='outer colN' headers="<?php print $disease->item_id->value(); ?>-rh cna_ch <?php print $node; ?>-bn"><div class="cellheader"></div></td>
    <?php } ?>
    <?php if ($disease->field_mirna->value()) { ?>
      <td class='outer colN' headers="<?php print $disease->item_id->value(); ?>-rh mirna_ch <?php print $node; ?>-bn">
        <table class="cell">
          <tbody>
            <?php if ($disease->field_mirna->value()): ?>
              <?php foreach ($disease->field_mirna->field_column_header as $mirna): ?>
                <tr>
                  <th id="<?php print $disease->item_id->value(); ?>_mirna" scope="col" class="cellheader">
              <?php if (!empty($mirna->field_link->title->value())): ?>
                          <?php if ($mirna->field_availability->value() == 'Unavailable'): ?>
                            <div class="cellheader"><?php print $mirna->field_link->title->value(); ?></div>
                          <?php endif; ?>
                        <?php endif; ?>
                        <?php if (!empty($mirna->field_link->title->value()) && !empty($mirna->field_link->url->value())): ?>
                          <?php if ($mirna->field_availability->value() == 'Protected'): ?>
                            <div class="cellheader"><a class="protected" target="_blank" <?php print $link_title; ?> href='<?php print $mirna->field_link->url->value(); ?>'><?php print $mirna->field_link->title->value() . '†'; ?></a></div>
                          <?php endif; ?>
                          <?php if ($mirna->field_availability->value() == 'Public'): ?>
                            <div class="cellheader"><a class="public" target="_blank" <?php print $link_title; ?> href='<?php print $mirna->field_link->url->value(); ?>'><?php print $mirna->field_link->title->value(); ?></a></div>
                          <?php endif; ?>
                        <?php endif; ?>
            </th>
          </tr>
          <tr>
            <td class="cellbody" headers="<?php print $disease->item_id->value(); ?>_rh mirna_ch <?php print $node; ?>_bn <?php print $disease->item_id->value(); ?>_mirna">
              <div class='cellbody'>
                <?php foreach ($mirna->field_column_values as $i => $column_values): ?>
                  <?php $field_link = field_view_field('field_collection_item', entity_load_single('field_collection_item', $column_values->item_id->value()), 'field_link'); ?>
                  <?php
                  if (!empty($field_link['#items'][0]['attributes']['title'])) {
                    $link_title = 'title="' . $field_link['#items'][0]['attributes']['title'] . '"';
                  } else {
                    $link_title = '';
                  }
                  ?>
                  <?php if (!empty($column_values->field_link->title->value())): ?>
                    <?php if ($column_values->field_availability->value() == 'Unavailable'): ?>
                      <span <?php print $link_title; ?>><?php print $column_values->field_link->title->value(); ?></span>
                      <br />
                    <?php endif; ?>
                  <?php endif; ?>
                  <?php if (!empty($column_values->field_link->title->value()) && !empty($column_values->field_link->url->value())): ?>
                    <?php if ($column_values->field_availability->value() == 'Protected'): ?>
                      <a class="protected" target="_blank" <?php print $link_title; ?> href='<?php print $column_values->field_link->url->value(); ?>'><?php print $column_values->field_link->title->value() . '†'; ?></a>
                      <br />
                    <?php endif; ?>
                    <?php if ($column_values->field_availability->value() == 'Public'): ?>
                      <a class="public" target="_blank" <?php print $link_title; ?> href='<?php print $column_values->field_link->url->value(); ?>'><?php print $column_values->field_link->title->value() . '*'; ?></a>
                      <br />
                    <?php endif; ?>
                  <?php endif; ?>
                <?php endforeach; ?>
              </div>
            </td>
          </tr>
        <?php endforeach; ?>
      <?php endif; ?>
      </tbody>
      </table>
      </td>
    <?php } else { ?>
      <td class='outer colN' headers="<?php print $disease->item_id->value(); ?>-rh mirna_ch <?php print $node; ?>-bn"><div class="cellheader"></div></td>
    <?php } ?>
    <?php print views_embed_view('cgci_data_matrix', 'column_header', $disease->item_id->value()); ?>
    <?php if ($disease->field_other->value()) { ?>
      <td class='outer colN' headers="<?php print $disease->item_id->value(); ?>-rh other_ch <?php print $node; ?>-bn">
        <table class="cell">
          <tbody>
            <?php if ($disease->field_other->value()): ?>
              <?php foreach ($disease->field_other->field_column_header as $other): ?>
                <tr>
                  <th id="<?php print $disease->item_id->value(); ?>_other" scope="col" class="cellheader">
              <?php if (!empty($other->field_link->title->value())): ?>
                          <?php if ($other->field_availability->value() == 'Unavailable'): ?>
                            <div class="cellheader"><?php print $other->field_link->title->value(); ?></div>
                          <?php endif; ?>
                        <?php endif; ?>
                        <?php if (!empty($other->field_link->title->value()) && !empty($other->field_link->url->value())): ?>
                          <?php if ($other->field_availability->value() == 'Protected'): ?>
                            <div class="cellheader"><a class="protected" target="_blank" <?php print $link_title; ?> href='<?php print $other->field_link->url->value(); ?>'><?php print $other->field_link->title->value() . '†'; ?></a></div>
                          <?php endif; ?>
                          <?php if ($other->field_availability->value() == 'Public'): ?>
                            <div class="cellheader"><a class="public" target="_blank" <?php print $link_title; ?> href='<?php print $other->field_link->url->value(); ?>'><?php print $other->field_link->title->value(); ?></a></div>
                          <?php endif; ?>
                        <?php endif; ?>
            </th>
          </tr>
          <tr>
            <td class="cellbody" headers="<?php print $disease->item_id->value(); ?>_rh other_ch <?php print $node; ?>_bn <?php print $disease->item_id->value(); ?>_other">
              <div class='cellbody'>
                <?php foreach ($other->field_column_values as $i => $column_values): ?>
                  <?php $field_link = field_view_field('field_collection_item', entity_load_single('field_collection_item', $column_values->item_id->value()), 'field_link'); ?>
                  <?php
                  if (!empty($field_link['#items'][0]['attributes']['title'])) {
                    $link_title = 'title="' . $field_link['#items'][0]['attributes']['title'] . '"';
                  } else {
                    $link_title = '';
                  }
                  ?>
                  <?php if (!empty($column_values->field_link->title->value())): ?>
                    <?php if ($column_values->field_availability->value() == 'Unavailable'): ?>
                      <span <?php print $link_title; ?>><?php print $column_values->field_link->title->value(); ?></span>
                      <br />
                    <?php endif; ?>
                  <?php endif; ?>
                  <?php if (!empty($column_values->field_link->title->value()) && !empty($column_values->field_link->url->value())): ?>
                    <?php if ($column_values->field_availability->value() == 'Protected'): ?>
                      <a class="protected" target="_blank" <?php print $link_title; ?> href='<?php print $column_values->field_link->url->value(); ?>'><?php print $column_values->field_link->title->value() . '†'; ?></a>
                      <br />
                    <?php endif; ?>
                    <?php if ($column_values->field_availability->value() == 'Public'): ?>
                      <a class="public" target="_blank" <?php print $link_title; ?> href='<?php print $column_values->field_link->url->value(); ?>'><?php print $column_values->field_link->title->value() . '*'; ?></a>
                      <br />
                    <?php endif; ?>
                  <?php endif; ?>
                <?php endforeach; ?>
              </div>
            </td>
          </tr>
        <?php endforeach; ?>
      <?php endif; ?>
      </tbody>
      </table>
      </td>
    <?php } else { ?>
      <td class='outer colN' headers="<?php print $disease->item_id->value(); ?>-rh other_ch <?php print $node; ?>-bn"><div class="cellheader"></div></td>
      <?php } ?>
    </tr>
  <?php endforeach; ?>
<?php endforeach; ?>
</tbody>
</table>
