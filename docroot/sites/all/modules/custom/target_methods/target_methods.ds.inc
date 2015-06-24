<?php
/**
 * @file
 * target_methods.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function target_methods_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'description';
  $ds_view_mode->label = 'Description';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['description'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'legend';
  $ds_view_mode->label = 'Legend';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['legend'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'projects';
  $ds_view_mode->label = 'Projects';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['projects'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'protocol';
  $ds_view_mode->label = 'Protocol';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['protocol'] = $ds_view_mode;

  return $export;
}
