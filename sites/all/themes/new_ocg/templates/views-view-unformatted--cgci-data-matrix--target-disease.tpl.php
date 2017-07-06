<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */

?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
    <?php print $row; ?>
    <?php $filter = $view->result[$id]->field_collection_item_field_data_field_target_disease_item_i; ?>
    
    <?php print embed_cgci_view('cgci_data_matrix', 'target_patient_data', $filter, 'Patient Data'); ?>
    <?php print embed_cgci_view('cgci_data_matrix', 'target_gene_expression', $filter, 'Gene Expression'); ?>
    <?php print embed_cgci_view('cgci_data_matrix', 'target_copy_number', $filter, 'Copy Number'); ?>
    <?php print embed_cgci_view('cgci_data_matrix', 'target_methylation', $filter, 'Methylation'); ?>
    <?php print embed_cgci_view('cgci_data_matrix', 'target_mirna', $filter, 'MiRNA'); ?>
    <?php print embed_cgci_view('cgci_data_matrix', 'target_sequence', $filter, 'Sequence'); ?>
    <?php print embed_cgci_view('cgci_data_matrix', 'target_other', $filter, 'Other'); ?>
  </div>
<?php endforeach; ?>
