<?php
/**
 * @file
 * Displays the items of the accordion.
 *
 * @ingroup views_templates
 *
 * Note that the accordion NEEDS <?php print $row ?> to be wrapped by an
 * element, or it will hide all fields on all rows under the first field.
 *
 * Also, if you use field grouping and use the headers of the groups as the
 * accordion headers, these NEED to be inside h3 tags exactly as below
 * (though you can add classes).
 *
 * The current div wraping each row gets two css classes, which should be
 * enough for most cases:
 *     "views-accordion-item"
 *      and a unique per row class like item-0
 */

?>

<table class="views-table sticky-enabled cols-1 tableheader-processed sticky-table" width="100%">
   <?php if (!empty($title) || !empty($caption)) : ?>
     <caption><?php print $caption . $title; ?></caption>
  <?php endif; ?>
    <thead>
      <tr>
        
        <th id="projtitle_ch" class="colheader" scope="col" width="46%">Project Title</th>
        <th id="expapp_ch" class="colheader" scope="col" width="14%">Experimental<br>Approaches</th>
        <th id="data_ch" class="colheader" scope="col" width="9%">Data</th>
        <th id="pi_ch" class="colheader" scope="col"width="13%">Principal<br>Investigator</th>
        <th id="contact_ch" class="colheader" scope="col" width="10%">Contact Name</th>
        <th id="contact_ch" class="colheader" scope="col" width="8%">Submission Date</th>
      </tr>
    </thead>
</table>
<?php if (!empty($title)): ?>
  <h3 class="<?php print $view_accordion_id; ?>">
    <?php print $title; ?>
  </h3>
<?php endif; ?>
<?php if ($use_group_header): ?><div><?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div class="<?php print $classes_array[$id]; ?>">
    <?php print $row; ?>
  </div>
<?php endforeach; ?>
<?php if ($use_group_header): ?></div><?php endif; ?>
