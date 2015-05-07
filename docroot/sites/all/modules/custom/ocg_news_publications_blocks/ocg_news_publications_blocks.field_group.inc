<?php
/**
 * @file
 * ocg_news_publications_blocks.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ocg_news_publications_blocks_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publication_image|node|publication|default';
  $field_group->group_name = 'group_publication_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publication';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '0',
    'children' => array(
      0 => 'field_image',
      1 => 'field_publication_image_caption',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'classes' => ' group-publication-image field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'id' => 'node_publication_full_group_publication_image',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_publication_image|node|publication|default'] = $field_group;

  return $export;
}
