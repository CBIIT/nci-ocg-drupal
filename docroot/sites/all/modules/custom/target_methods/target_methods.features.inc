<?php
/**
 * @file
 * target_methods.features.inc
 */

/**
 * Implements hook_node_info().
 */
function target_methods_node_info() {
  $items = array(
    'target_methods' => array(
      'name' => t('TARGET Methods'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
