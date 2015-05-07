<?php
/**
 * @file
 * ocg_news_publications_blocks.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ocg_news_publications_blocks_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ocg_news_publications_blocks_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ocg_news_publications_blocks_node_info() {
  $items = array(
    'news' => array(
      'name' => t('News Item'),
      'base' => 'node_content',
      'description' => t('A content type for News items.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'publication' => array(
      'name' => t('Publication'),
      'base' => 'node_content',
      'description' => t('A publication type used to house publications on the OCG site'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
