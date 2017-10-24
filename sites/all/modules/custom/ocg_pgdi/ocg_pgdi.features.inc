<?php
/**
 * @file
 * ocg_pgdi.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ocg_pgdi_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ocg_pgdi_node_info() {
  $items = array(
    'pgdi' => array(
      'name' => t('PGDI'),
      'base' => 'node_content',
      'description' => t('Form for entering data for PGDI.'),
      'has_title' => '1',
      'title_label' => t('Project Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
