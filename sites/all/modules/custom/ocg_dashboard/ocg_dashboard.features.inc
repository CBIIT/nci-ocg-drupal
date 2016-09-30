<?php
/**
 * @file
 * ocg_dashboard.features.inc
 */

/**
 * Implements hook_views_api().
 */
function ocg_dashboard_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ocg_dashboard_node_info() {
  $items = array(
    'programs' => array(
      'name' => t('Programs'),
      'base' => 'node_content',
      'description' => t('Content type for programs. Programs can then have sub-projects. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
