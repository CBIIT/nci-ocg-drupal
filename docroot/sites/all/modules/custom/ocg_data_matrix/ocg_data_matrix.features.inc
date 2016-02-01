<?php
/**
 * @file
 * ocg_data_matrix.features.inc
 */

/**
 * Implements hook_views_api().
 */
function ocg_data_matrix_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ocg_data_matrix_node_info() {
  $items = array(
    'disease' => array(
      'name' => t('Disease'),
      'base' => 'node_content',
      'description' => t('Individual pieces of content to create data matrices for CGCI & TARGET.'),
      'has_title' => '1',
      'title_label' => t('Primary Disease Categorization'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
