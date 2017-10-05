<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($rows[0])) { ?>

<?php foreach ($rows as $id => $row): ?>
  <td width="13%" class="outer colNM" rowspan="<?php print ctd2_pi_row_count($view->result[0]->nid, $view->args[0]); ?>" style="vertical-align: middle; text-align: center;" headers="pi_ch <?php print $view->result[0]->nid . '_bn ' . ctd2_pi_row_classes($view->result[0]->nid) . $view->args[0] . '_rh';?>">
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
    <?php print $row; ?>
  </div>
  </td>
<?php endforeach; ?>
<?php } ?>
