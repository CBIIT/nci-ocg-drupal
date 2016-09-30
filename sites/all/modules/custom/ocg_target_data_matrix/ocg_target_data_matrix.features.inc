<?php
/**
 * @file
 * ocg_target_data_matrix.features.inc
 */

/**
 * Implements hook_node_info().
 */
function ocg_target_data_matrix_node_info() {
  $items = array(
    'target_data_matrix' => array(
      'name' => t('TARGET Data Matrix'),
      'base' => 'node_content',
      'description' => t('Individual pieces of content to create data matrices for TARGET.'),
      'has_title' => '1',
      'title_label' => t('Primary Disease Categorization'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
