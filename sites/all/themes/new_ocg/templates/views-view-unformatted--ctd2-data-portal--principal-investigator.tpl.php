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
  <td class="outer colNM" rowspan="<?php print ctd2_row_count($view->result[0]->nid); ?>" style="vertical-align: middle; text-align: center;" headers="pi_ch <?php print $view->result[0]->nid . '_bn ' . $view->args[0] . '_rh' . ctd2_pi_row_classes($view->args[0], $view->result[0]->nid, 'field_principal_investigator');?>">
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
    <?php print $row; ?>
  </div>
  </td>
<?php endforeach; ?>
<?php } ?>
