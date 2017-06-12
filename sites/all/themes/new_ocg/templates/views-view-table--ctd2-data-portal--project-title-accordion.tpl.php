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
<table class="accordion-table">
    <?php foreach ($rows as $row_count => $row): ?>
      <tr <?php if ($row_classes[$row_count]) { print 'class="' . implode(' ', $row_classes[$row_count]) .'"';  } ?>>
        <?php foreach ($row as $field => $content): ?>
          <th width="46%" id="<?php print $result[$row_count]->field_collection_item_field_data_field_row_item_id . '_rh'; ?>" scope="row"<?php if ($field_classes[$field][$row_count]) { print 'class="rowheader '. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
            <div class="projcell">
            <?php print $content; ?>
            </div>
          </th>
        
          <?php print views_embed_view('ctd2_data_portal', 'experimental_approaches', $result[$row_count]->field_collection_item_field_data_field_row_item_id); ?>
          <td width="9%" class="outer colN" headers="data_ch <?php print $result[$row_count]->nid . '_bn ' . $result[$row_count]->field_collection_item_field_data_field_row_item_id . '_rh'; ?>"><?php print views_embed_view('ctd2_data_portal', 'data', $result[$row_count]->field_collection_item_field_data_field_row_item_id); ?></td>
          <?php 
          $view_result = views_get_view_result('ctd2_data_portal', 'principal_investigator', $result[$row_count]->field_collection_item_field_data_field_row_item_id);
          if(!empty($view_result[0]->field_field_pi_link)){ ?>
          <?php print views_embed_view('ctd2_data_portal', 'principal_investigator', $result[$row_count]->field_collection_item_field_data_field_row_item_id); ?>
          <?php } ?>
          <?php print views_embed_view('ctd2_data_portal', 'contact_name', $result[$row_count]->field_collection_item_field_data_field_row_item_id); ?>
          <?php print views_embed_view('ctd2_data_portal', 'submission_date', $result[$row_count]->field_collection_item_field_data_field_row_item_id); ?>
      <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
</table>