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
          <th <?php
          if ($header_classes[$field]) {
            print 'class="' . $header_classes[$field] . '" ';
          }
          ?> scope="col">
              <?php print $label; ?>
          </th>
        <?php endforeach; ?>
        <th scope="col">Patient Data</th>
        <th scope="col">Gene Expression</th>
        <th scope="col">Copy Number</th>
        <th scope="col">miRNA</th>
        <th colspan="3" scope="col">Sequence</th>
        <th scope="col">Other</th>
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
          <th class="disease" colspan="9" scope="col">
            <?php print $content; ?>
          </th>
        <?php endforeach; ?>
      </tr>
      <?php foreach ($wrapper->field_disease as $disease): ?>
        <tr>
          <td class="disease" scope="row">
            <a href="<?php print $disease->field_link->url->value() ?>"><?php print $disease->field_link->title->value() ?></a>
          </td>
          <td class="colSN">
            <?php foreach ($disease->field_patient_data as $patient_data): ?>
              <?php $field_link = field_view_field('field_collection_item', entity_load_single('field_collection_item', $patient_data->item_id->value()), 'field_link'); ?>
              <?php
              if (!empty($field_link['#items'][0]['attributes']['title'])) {
                $link_title = 'title="' . $field_link['#items'][0]['attributes']['title'] . '"';
              } else {
                $link_title = '';
              }
              ?>
              <?php if ($patient_data->field_availability->value() == 'Unavailable'): ?>
                <span <?php print $link_title; ?>><?php print $patient_data->field_link->title->value(); ?></span>
                <br />
              <?php endif; ?>
              <?php if ($patient_data->field_availability->value() == 'Protected'): ?>
                <a class="protected" target="_blank" <?php print $link_title; ?> href='<?php print $patient_data->field_link->url->value(); ?>'><?php print $patient_data->field_link->title->value() . '†'; ?></a>
                <br />
              <?php endif; ?>
              <?php if ($patient_data->field_availability->value() == 'Public'): ?>
                <a class="public" target="_blank" <?php print $link_title; ?> href='<?php print $patient_data->field_link->url->value(); ?>'><?php print $patient_data->field_link->title->value() . '*'; ?></a>
                <br />
              <?php endif; ?>
            <?php endforeach; ?>
          </td>
          <?php if ($disease->field_gene_expression->value()) { ?>
            <td class='outer colN'>
              <?php foreach ($disease->field_gene_expression->field_column_header as $gene_expression): ?>
                <div class="cellheader"><?php print $gene_expression->field_link->title->value(); ?></div>
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
                    <?php if ($column_values->field_availability->value() == 'Unavailable'): ?>
                      <span <?php print $link_title; ?>><?php print $column_values->field_link->title->value(); ?></span>
                      <br />
                    <?php endif; ?>
                    <?php if ($column_values->field_availability->value() == 'Protected'): ?>
                      <a class="protected" target="_blank" <?php print $link_title; ?> href='<?php print $column_values->field_link->url->value(); ?>'><?php print $column_values->field_link->title->value() . '†'; ?></a>
                      <br />
                    <?php endif; ?>
                    <?php if ($column_values->field_availability->value() == 'Public'): ?>
                      <a class="public" target="_blank" <?php print $link_title; ?> href='<?php print $column_values->field_link->url->value(); ?>'><?php print $column_values->field_link->title->value() . '*'; ?></a>
                      <br />
                    <?php endif; ?>
                  <?php endforeach; ?>
                </div>
              <?php endforeach; ?>
            </td>
          <?php } else { ?>
            <td class='outer colN'></td>
          <?php } ?>
          <?php if ($disease->field_copy_number->value()) { ?>
            <td class='outer colW'>
              <?php foreach ($disease->field_copy_number->field_column_header as $copy_number): ?>
                <div class="cellheader"><?php print $copy_number->field_link->title->value(); ?></div>
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
                    <?php if ($column_values->field_availability->value() == 'Unavailable'): ?>
                      <span <?php print $link_title; ?>><?php print $column_values->field_link->title->value(); ?></span>
                      <br />
                    <?php endif; ?>
                    <?php if ($column_values->field_availability->value() == 'Protected'): ?>
                      <a class="protected" target="_blank" <?php print $link_title; ?> href='<?php print $column_values->field_link->url->value(); ?>'><?php print $column_values->field_link->title->value() . '†'; ?></a>
                      <br />
                    <?php endif; ?>
                    <?php if ($column_values->field_availability->value() == 'Public'): ?>
                      <a class="public" target="_blank" <?php print $link_title; ?> href='<?php print $column_values->field_link->url->value(); ?>'><?php print $column_values->field_link->title->value() . '*'; ?></a>
                      <br />
                    <?php endif; ?>
                  <?php endforeach; ?>
                </div>
              <?php endforeach; ?>
            </td>
          <?php } else { ?>
            <td class='outer colN'></td>
          <?php } ?>
          <?php if ($disease->field_mirna->value()) { ?>
            <td class='outer colN'>
              <?php if ($disease->field_mirna->value()): ?>
                <?php foreach ($disease->field_mirna->field_column_header as $mirna): ?>
                  <div class="cellheader"><?php print $mirna->field_link->title->value(); ?></div>
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
                      <?php if ($column_values->field_availability->value() == 'Unavailable'): ?>
                        <span <?php print $link_title; ?>><?php print $column_values->field_link->title->value(); ?></span>
                        <br />
                      <?php endif; ?>
                      <?php if ($column_values->field_availability->value() == 'Protected'): ?>
                        <a class="protected" target="_blank" <?php print $link_title; ?> href='<?php print $column_values->field_link->url->value(); ?>'><?php print $column_values->field_link->title->value() . '†'; ?></a>
                        <br />
                      <?php endif; ?>
                      <?php if ($column_values->field_availability->value() == 'Public'): ?>
                        <a class="public" target="_blank" <?php print $link_title; ?> href='<?php print $column_values->field_link->url->value(); ?>'><?php print $column_values->field_link->title->value() . '*'; ?></a>
                        <br />
                      <?php endif; ?>
                    <?php endforeach; ?>
                  </div>
                <?php endforeach; ?>
              <?php endif; ?>
            </td>
          <?php } else { ?>
            <td class='outer colN'><div class="cellheader"></div></td>
          <?php } ?>
          <?php if ($disease->field_sequence->value()) { ?>
            <?php foreach ($disease->field_sequence->field_column_header as $sequence): ?>
              <td class='outer colN'>
                <div class="cellheader"><?php print $sequence->field_link->title->value(); ?></div>
                <div class='cellbody'>
                  <?php foreach ($sequence->field_column_values as $i => $column_values): ?>
                    <?php $field_link = field_view_field('field_collection_item', entity_load_single('field_collection_item', $column_values->item_id->value()), 'field_link'); ?>
                    <?php
                    if (!empty($field_link['#items'][0]['attributes']['title'])) {
                      $link_title = 'title="' . $field_link['#items'][0]['attributes']['title'] . '"';
                    } else {
                      $link_title = '';
                    }
                    ?>
                    <?php if ($column_values->field_availability->value() == 'Unavailable'): ?>
                      <span <?php print $link_title; ?>><?php print $column_values->field_link->title->value(); ?></span>
                      <br />
                    <?php endif; ?>
                    <?php if ($column_values->field_availability->value() == 'Protected'): ?>
                      <a class="protected" target="_blank" <?php print $link_title; ?> href='<?php print $column_values->field_link->url->value(); ?>'><?php print $column_values->field_link->title->value() . '†'; ?></a>
                      <br />
                    <?php endif; ?>
                    <?php if ($column_values->field_availability->value() == 'Public'): ?>
                      <a class="public" target="_blank" <?php print $link_title; ?> href='<?php print $column_values->field_link->url->value(); ?>'><?php print $column_values->field_link->title->value() . '*'; ?></a>
                      <br />
                    <?php endif; ?>
                  <?php endforeach; ?>
                </div>
              </td>
            <?php endforeach; ?>
          <?php } ?>
          <?php if ($disease->field_other->value()) { ?>
            <td class='outer colN'>
              <?php if ($disease->field_other->value()): ?>
                <?php foreach ($disease->field_other->field_column_header as $other): ?>
                  <div class="cellheader"><?php print $other->field_link->title->value(); ?></div>
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
                      <?php if ($column_values->field_availability->value() == 'Unavailable'): ?>
                        <span <?php print $link_title; ?>><?php print $column_values->field_link->title->value(); ?></span>
                        <br />
                      <?php endif; ?>
                      <?php if ($column_values->field_availability->value() == 'Protected'): ?>
                        <a class="protected" target="_blank" <?php print $link_title; ?> href='<?php print $column_values->field_link->url->value(); ?>'><?php print $column_values->field_link->title->value() . '†'; ?></a>
                        <br />
                      <?php endif; ?>
                      <?php if ($column_values->field_availability->value() == 'Public'): ?>
                        <a class="public" target="_blank" <?php print $link_title; ?> href='<?php print $column_values->field_link->url->value(); ?>'><?php print $column_values->field_link->title->value() . '*'; ?></a>
                        <br />
                      <?php endif; ?>
                    <?php endforeach; ?>
                  </div>
                <?php endforeach; ?>
              <?php endif; ?>
            </td>
          <?php } else { ?>
            <td class='outer colN'><div class="cellheader"></div></td>
          <?php } ?>
        </tr>
      <?php endforeach; ?>
    <?php endforeach; ?>
  </tbody>
</table>
