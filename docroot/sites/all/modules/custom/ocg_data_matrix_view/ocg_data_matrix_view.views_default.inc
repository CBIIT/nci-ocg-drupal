<?php
/**
 * @file
 * ocg_data_matrix_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ocg_data_matrix_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'cgci_data_matrix';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'CGCI Data Matrix';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CGCI Data Matrix';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_link' => 'field_link',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_link' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Disease';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Patient Data Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['relationship'] = 'field_patient_data_value';
  $handler->display->display_options['fields']['field_link']['ui_name'] = 'Patient Data Link';
  $handler->display->display_options['fields']['field_link']['label'] = 'Patient Data';
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'disease' => 'disease',
  );

  /* Display: Disease */
  $handler = $view->new_display('page', 'Disease', 'primary_disease');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'edit_node' => 'title',
    'field_project_status' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' - ',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_project_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Disease';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Project Status */
  $handler->display->display_options['fields']['field_project_status']['id'] = 'field_project_status';
  $handler->display->display_options['fields']['field_project_status']['table'] = 'field_data_field_project_status';
  $handler->display->display_options['fields']['field_project_status']['field'] = 'field_project_status';
  $handler->display->display_options['fields']['field_project_status']['label'] = '';
  $handler->display->display_options['fields']['field_project_status']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Project Status (field_project_status) */
  $handler->display->display_options['sorts']['field_project_status_value']['id'] = 'field_project_status_value';
  $handler->display->display_options['sorts']['field_project_status_value']['table'] = 'field_data_field_project_status';
  $handler->display->display_options['sorts']['field_project_status_value']['field'] = 'field_project_status_value';
  $handler->display->display_options['sorts']['field_project_status_value']['order'] = 'DESC';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'programs/cgci/data-matrix';

  /* Display: Column Header */
  $handler = $view->new_display('block', 'Column Header', 'column_header');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Disease (field_disease) */
  $handler->display->display_options['relationships']['field_disease_value']['id'] = 'field_disease_value';
  $handler->display->display_options['relationships']['field_disease_value']['table'] = 'field_data_field_disease';
  $handler->display->display_options['relationships']['field_disease_value']['field'] = 'field_disease_value';
  $handler->display->display_options['relationships']['field_disease_value']['delta'] = '-1';
  /* Relationship: Field collection item: Sequence (field_sequence) */
  $handler->display->display_options['relationships']['field_sequence_value']['id'] = 'field_sequence_value';
  $handler->display->display_options['relationships']['field_sequence_value']['table'] = 'field_data_field_sequence';
  $handler->display->display_options['relationships']['field_sequence_value']['field'] = 'field_sequence_value';
  $handler->display->display_options['relationships']['field_sequence_value']['relationship'] = 'field_disease_value';
  $handler->display->display_options['relationships']['field_sequence_value']['delta'] = '-1';
  /* Relationship: Field collection item: Column Header (field_column_header) */
  $handler->display->display_options['relationships']['field_column_header_value']['id'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['table'] = 'field_data_field_column_header';
  $handler->display->display_options['relationships']['field_column_header_value']['field'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['relationship'] = 'field_sequence_value';
  $handler->display->display_options['relationships']['field_column_header_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Field collection item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['item_id']['label'] = '';
  $handler->display->display_options['fields']['item_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['item_id']['separator'] = '';
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_title_plain';
  /* Field: Field collection item: Availability */
  $handler->display->display_options['fields']['field_availability']['id'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['table'] = 'field_data_field_availability';
  $handler->display->display_options['fields']['field_availability']['field'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_availability']['label'] = '';
  $handler->display->display_options['fields']['field_availability']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Column Number */
  $handler->display->display_options['fields']['field_column_number']['id'] = 'field_column_number';
  $handler->display->display_options['fields']['field_column_number']['table'] = 'field_data_field_column_number';
  $handler->display->display_options['fields']['field_column_number']['field'] = 'field_column_number';
  $handler->display->display_options['fields']['field_column_number']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_column_number']['label'] = '';
  $handler->display->display_options['fields']['field_column_number']['element_label_colon'] = FALSE;
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['view'] = 'cgci_data_matrix';
  $handler->display->display_options['fields']['view']['display'] = 'column_values';
  $handler->display->display_options['fields']['view']['arguments'] = '[!item_id]';
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link_1']['id'] = 'field_link_1';
  $handler->display->display_options['fields']['field_link_1']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link_1']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link_1']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link_1']['type'] = 'link_plain';
  /* Field: disease_id */
  $handler->display->display_options['fields']['item_id_1']['id'] = 'item_id_1';
  $handler->display->display_options['fields']['item_id_1']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id_1']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id_1']['relationship'] = 'field_disease_value';
  $handler->display->display_options['fields']['item_id_1']['ui_name'] = 'disease_id';
  $handler->display->display_options['fields']['item_id_1']['label'] = '';
  $handler->display->display_options['fields']['item_id_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['item_id_1']['separator'] = '';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field collection item: Column Number (field_column_number) */
  $handler->display->display_options['sorts']['field_column_number_value']['id'] = 'field_column_number_value';
  $handler->display->display_options['sorts']['field_column_number_value']['table'] = 'field_data_field_column_number';
  $handler->display->display_options['sorts']['field_column_number_value']['field'] = 'field_column_number_value';
  $handler->display->display_options['sorts']['field_column_number_value']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field collection item: Field collection item ID */
  $handler->display->display_options['arguments']['item_id']['id'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['item_id']['field'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['relationship'] = 'field_disease_value';
  $handler->display->display_options['arguments']['item_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['item_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['item_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['item_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'disease' => 'disease',
  );

  /* Display: Column Values */
  $handler = $view->new_display('block', 'Column Values', 'column_values');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Disease (field_disease) */
  $handler->display->display_options['relationships']['field_disease_value']['id'] = 'field_disease_value';
  $handler->display->display_options['relationships']['field_disease_value']['table'] = 'field_data_field_disease';
  $handler->display->display_options['relationships']['field_disease_value']['field'] = 'field_disease_value';
  $handler->display->display_options['relationships']['field_disease_value']['delta'] = '-1';
  /* Relationship: Field collection item: Sequence (field_sequence) */
  $handler->display->display_options['relationships']['field_sequence_value']['id'] = 'field_sequence_value';
  $handler->display->display_options['relationships']['field_sequence_value']['table'] = 'field_data_field_sequence';
  $handler->display->display_options['relationships']['field_sequence_value']['field'] = 'field_sequence_value';
  $handler->display->display_options['relationships']['field_sequence_value']['relationship'] = 'field_disease_value';
  $handler->display->display_options['relationships']['field_sequence_value']['delta'] = '-1';
  /* Relationship: Field collection item: Column Header (field_column_header) */
  $handler->display->display_options['relationships']['field_column_header_value']['id'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['table'] = 'field_data_field_column_header';
  $handler->display->display_options['relationships']['field_column_header_value']['field'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['relationship'] = 'field_sequence_value';
  $handler->display->display_options['relationships']['field_column_header_value']['delta'] = '-1';
  /* Relationship: Field collection item: Column Values (field_column_values) */
  $handler->display->display_options['relationships']['field_column_values_value']['id'] = 'field_column_values_value';
  $handler->display->display_options['relationships']['field_column_values_value']['table'] = 'field_data_field_column_values';
  $handler->display->display_options['relationships']['field_column_values_value']['field'] = 'field_column_values_value';
  $handler->display->display_options['relationships']['field_column_values_value']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_values_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['relationship'] = 'field_column_values_value';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_title_plain';
  /* Field: Field collection item: Availability */
  $handler->display->display_options['fields']['field_availability']['id'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['table'] = 'field_data_field_availability';
  $handler->display->display_options['fields']['field_availability']['field'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['relationship'] = 'field_column_values_value';
  $handler->display->display_options['fields']['field_availability']['label'] = '';
  $handler->display->display_options['fields']['field_availability']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link_1']['id'] = 'field_link_1';
  $handler->display->display_options['fields']['field_link_1']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link_1']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link_1']['relationship'] = 'field_column_values_value';
  $handler->display->display_options['fields']['field_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link_1']['type'] = 'link_plain';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field collection item: Column Number (field_column_number) */
  $handler->display->display_options['sorts']['field_column_number_value']['id'] = 'field_column_number_value';
  $handler->display->display_options['sorts']['field_column_number_value']['table'] = 'field_data_field_column_number';
  $handler->display->display_options['sorts']['field_column_number_value']['field'] = 'field_column_number_value';
  $handler->display->display_options['sorts']['field_column_number_value']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field collection item: Field collection item ID */
  $handler->display->display_options['arguments']['item_id']['id'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['item_id']['field'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['arguments']['item_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['item_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['item_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['item_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['item_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'disease' => 'disease',
  );

  /* Display: Last Updated Block */
  $handler = $view->new_display('block', 'Last Updated Block', 'last_updated');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'medium';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';

  /* Display: TARGET */
  $handler = $view->new_display('page', 'TARGET', 'target_primary_disease');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'TARGET DATA MATRIX';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'edit_node' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' - ',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Disease';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'target_data_matrix' => 'target_data_matrix',
  );
  $handler->display->display_options['path'] = 'programs/target/data-matrix';

  /* Display: TARGET Sequence Column Header */
  $handler = $view->new_display('block', 'TARGET Sequence Column Header', 'target_column_header');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Disease (field_target_disease) */
  $handler->display->display_options['relationships']['field_target_disease_value']['id'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_target_disease_value']['table'] = 'field_data_field_target_disease';
  $handler->display->display_options['relationships']['field_target_disease_value']['field'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_target_disease_value']['delta'] = '-1';
  /* Relationship: Field collection item: Sequence (field_sequence) */
  $handler->display->display_options['relationships']['field_sequence_value']['id'] = 'field_sequence_value';
  $handler->display->display_options['relationships']['field_sequence_value']['table'] = 'field_data_field_sequence';
  $handler->display->display_options['relationships']['field_sequence_value']['field'] = 'field_sequence_value';
  $handler->display->display_options['relationships']['field_sequence_value']['relationship'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_sequence_value']['delta'] = '-1';
  /* Relationship: Field collection item: Column Header (field_column_header) */
  $handler->display->display_options['relationships']['field_column_header_value']['id'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['table'] = 'field_data_field_column_header';
  $handler->display->display_options['relationships']['field_column_header_value']['field'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['relationship'] = 'field_sequence_value';
  $handler->display->display_options['relationships']['field_column_header_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Field collection item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['item_id']['label'] = '';
  $handler->display->display_options['fields']['item_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['item_id']['separator'] = '';
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_title_plain';
  /* Field: Field collection item: Availability */
  $handler->display->display_options['fields']['field_availability']['id'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['table'] = 'field_data_field_availability';
  $handler->display->display_options['fields']['field_availability']['field'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_availability']['label'] = '';
  $handler->display->display_options['fields']['field_availability']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Column Number */
  $handler->display->display_options['fields']['field_column_number']['id'] = 'field_column_number';
  $handler->display->display_options['fields']['field_column_number']['table'] = 'field_data_field_column_number';
  $handler->display->display_options['fields']['field_column_number']['field'] = 'field_column_number';
  $handler->display->display_options['fields']['field_column_number']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_column_number']['label'] = '';
  $handler->display->display_options['fields']['field_column_number']['element_label_colon'] = FALSE;
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['view'] = 'cgci_data_matrix';
  $handler->display->display_options['fields']['view']['display'] = 'target_column_values';
  $handler->display->display_options['fields']['view']['arguments'] = '[!item_id]';
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link_1']['id'] = 'field_link_1';
  $handler->display->display_options['fields']['field_link_1']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link_1']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link_1']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link_1']['type'] = 'link_plain';
  /* Field: disease_id */
  $handler->display->display_options['fields']['item_id_1']['id'] = 'item_id_1';
  $handler->display->display_options['fields']['item_id_1']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id_1']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id_1']['relationship'] = 'field_target_disease_value';
  $handler->display->display_options['fields']['item_id_1']['ui_name'] = 'disease_id';
  $handler->display->display_options['fields']['item_id_1']['label'] = '';
  $handler->display->display_options['fields']['item_id_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['item_id_1']['separator'] = '';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field collection item: Column Number (field_column_number) */
  $handler->display->display_options['sorts']['field_column_number_value']['id'] = 'field_column_number_value';
  $handler->display->display_options['sorts']['field_column_number_value']['table'] = 'field_data_field_column_number';
  $handler->display->display_options['sorts']['field_column_number_value']['field'] = 'field_column_number_value';
  $handler->display->display_options['sorts']['field_column_number_value']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field collection item: Field collection item ID */
  $handler->display->display_options['arguments']['item_id']['id'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['item_id']['field'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['relationship'] = 'field_target_disease_value';
  $handler->display->display_options['arguments']['item_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['item_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['item_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['item_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'target_data_matrix' => 'target_data_matrix',
  );

  /* Display: TARGET Sequence Column Values */
  $handler = $view->new_display('block', 'TARGET Sequence Column Values', 'target_column_values');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Disease (field_target_disease) */
  $handler->display->display_options['relationships']['field_target_disease_value']['id'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_target_disease_value']['table'] = 'field_data_field_target_disease';
  $handler->display->display_options['relationships']['field_target_disease_value']['field'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_target_disease_value']['delta'] = '-1';
  /* Relationship: Field collection item: Sequence (field_sequence) */
  $handler->display->display_options['relationships']['field_sequence_value']['id'] = 'field_sequence_value';
  $handler->display->display_options['relationships']['field_sequence_value']['table'] = 'field_data_field_sequence';
  $handler->display->display_options['relationships']['field_sequence_value']['field'] = 'field_sequence_value';
  $handler->display->display_options['relationships']['field_sequence_value']['relationship'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_sequence_value']['delta'] = '-1';
  /* Relationship: Field collection item: Column Header (field_column_header) */
  $handler->display->display_options['relationships']['field_column_header_value']['id'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['table'] = 'field_data_field_column_header';
  $handler->display->display_options['relationships']['field_column_header_value']['field'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['relationship'] = 'field_sequence_value';
  $handler->display->display_options['relationships']['field_column_header_value']['delta'] = '-1';
  /* Relationship: Field collection item: Column Values (field_column_values) */
  $handler->display->display_options['relationships']['field_column_values_value']['id'] = 'field_column_values_value';
  $handler->display->display_options['relationships']['field_column_values_value']['table'] = 'field_data_field_column_values';
  $handler->display->display_options['relationships']['field_column_values_value']['field'] = 'field_column_values_value';
  $handler->display->display_options['relationships']['field_column_values_value']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_values_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['relationship'] = 'field_column_values_value';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_title_plain';
  /* Field: Field collection item: Availability */
  $handler->display->display_options['fields']['field_availability']['id'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['table'] = 'field_data_field_availability';
  $handler->display->display_options['fields']['field_availability']['field'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['relationship'] = 'field_column_values_value';
  $handler->display->display_options['fields']['field_availability']['label'] = '';
  $handler->display->display_options['fields']['field_availability']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link_1']['id'] = 'field_link_1';
  $handler->display->display_options['fields']['field_link_1']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link_1']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link_1']['relationship'] = 'field_column_values_value';
  $handler->display->display_options['fields']['field_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link_1']['type'] = 'link_plain';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field collection item: Column Number (field_column_number) */
  $handler->display->display_options['sorts']['field_column_number_value']['id'] = 'field_column_number_value';
  $handler->display->display_options['sorts']['field_column_number_value']['table'] = 'field_data_field_column_number';
  $handler->display->display_options['sorts']['field_column_number_value']['field'] = 'field_column_number_value';
  $handler->display->display_options['sorts']['field_column_number_value']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field collection item: Field collection item ID */
  $handler->display->display_options['arguments']['item_id']['id'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['item_id']['field'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['arguments']['item_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['item_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['item_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['item_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['item_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'target_data_matrix' => 'target_data_matrix',
  );

  /* Display: TARGET Last Updated Block */
  $handler = $view->new_display('block', 'TARGET Last Updated Block', 'target_last_updated');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'medium';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'target_data_matrix' => 'target_data_matrix',
  );

  /* Display: TARGET Gene Expression Column Header */
  $handler = $view->new_display('block', 'TARGET Gene Expression Column Header', 'target_gene_expression_column_header');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Disease (field_target_disease) */
  $handler->display->display_options['relationships']['field_target_disease_value']['id'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_target_disease_value']['table'] = 'field_data_field_target_disease';
  $handler->display->display_options['relationships']['field_target_disease_value']['field'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_target_disease_value']['delta'] = '-1';
  /* Relationship: Field collection item: Gene Expression (field_gene_expression) */
  $handler->display->display_options['relationships']['field_gene_expression_value']['id'] = 'field_gene_expression_value';
  $handler->display->display_options['relationships']['field_gene_expression_value']['table'] = 'field_data_field_gene_expression';
  $handler->display->display_options['relationships']['field_gene_expression_value']['field'] = 'field_gene_expression_value';
  $handler->display->display_options['relationships']['field_gene_expression_value']['relationship'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_gene_expression_value']['delta'] = '-1';
  /* Relationship: Field collection item: Column Header (field_column_header) */
  $handler->display->display_options['relationships']['field_column_header_value']['id'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['table'] = 'field_data_field_column_header';
  $handler->display->display_options['relationships']['field_column_header_value']['field'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['relationship'] = 'field_gene_expression_value';
  $handler->display->display_options['relationships']['field_column_header_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Field collection item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['item_id']['label'] = '';
  $handler->display->display_options['fields']['item_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['item_id']['separator'] = '';
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_title_plain';
  /* Field: Field collection item: Availability */
  $handler->display->display_options['fields']['field_availability']['id'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['table'] = 'field_data_field_availability';
  $handler->display->display_options['fields']['field_availability']['field'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_availability']['label'] = '';
  $handler->display->display_options['fields']['field_availability']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Column Number */
  $handler->display->display_options['fields']['field_column_number']['id'] = 'field_column_number';
  $handler->display->display_options['fields']['field_column_number']['table'] = 'field_data_field_column_number';
  $handler->display->display_options['fields']['field_column_number']['field'] = 'field_column_number';
  $handler->display->display_options['fields']['field_column_number']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_column_number']['label'] = '';
  $handler->display->display_options['fields']['field_column_number']['element_label_colon'] = FALSE;
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['view'] = 'cgci_data_matrix';
  $handler->display->display_options['fields']['view']['display'] = 'target_gene_expression_column_values';
  $handler->display->display_options['fields']['view']['arguments'] = '[!item_id]';
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link_1']['id'] = 'field_link_1';
  $handler->display->display_options['fields']['field_link_1']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link_1']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link_1']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link_1']['type'] = 'link_plain';
  /* Field: disease_id */
  $handler->display->display_options['fields']['item_id_1']['id'] = 'item_id_1';
  $handler->display->display_options['fields']['item_id_1']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id_1']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id_1']['relationship'] = 'field_target_disease_value';
  $handler->display->display_options['fields']['item_id_1']['ui_name'] = 'disease_id';
  $handler->display->display_options['fields']['item_id_1']['label'] = '';
  $handler->display->display_options['fields']['item_id_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['item_id_1']['separator'] = '';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field collection item: Column Number (field_column_number) */
  $handler->display->display_options['sorts']['field_column_number_value']['id'] = 'field_column_number_value';
  $handler->display->display_options['sorts']['field_column_number_value']['table'] = 'field_data_field_column_number';
  $handler->display->display_options['sorts']['field_column_number_value']['field'] = 'field_column_number_value';
  $handler->display->display_options['sorts']['field_column_number_value']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field collection item: Field collection item ID */
  $handler->display->display_options['arguments']['item_id']['id'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['item_id']['field'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['relationship'] = 'field_target_disease_value';
  $handler->display->display_options['arguments']['item_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['item_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['item_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['item_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'target_data_matrix' => 'target_data_matrix',
  );

  /* Display: TARGET Gene Expression Column Values */
  $handler = $view->new_display('block', 'TARGET Gene Expression Column Values', 'target_gene_expression_column_values');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Disease (field_target_disease) */
  $handler->display->display_options['relationships']['field_target_disease_value']['id'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_target_disease_value']['table'] = 'field_data_field_target_disease';
  $handler->display->display_options['relationships']['field_target_disease_value']['field'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_target_disease_value']['delta'] = '-1';
  /* Relationship: Field collection item: Gene Expression (field_gene_expression) */
  $handler->display->display_options['relationships']['field_gene_expression_value']['id'] = 'field_gene_expression_value';
  $handler->display->display_options['relationships']['field_gene_expression_value']['table'] = 'field_data_field_gene_expression';
  $handler->display->display_options['relationships']['field_gene_expression_value']['field'] = 'field_gene_expression_value';
  $handler->display->display_options['relationships']['field_gene_expression_value']['relationship'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_gene_expression_value']['delta'] = '-1';
  /* Relationship: Field collection item: Column Header (field_column_header) */
  $handler->display->display_options['relationships']['field_column_header_value']['id'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['table'] = 'field_data_field_column_header';
  $handler->display->display_options['relationships']['field_column_header_value']['field'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['relationship'] = 'field_gene_expression_value';
  $handler->display->display_options['relationships']['field_column_header_value']['delta'] = '-1';
  /* Relationship: Field collection item: Column Values (field_column_values) */
  $handler->display->display_options['relationships']['field_column_values_value']['id'] = 'field_column_values_value';
  $handler->display->display_options['relationships']['field_column_values_value']['table'] = 'field_data_field_column_values';
  $handler->display->display_options['relationships']['field_column_values_value']['field'] = 'field_column_values_value';
  $handler->display->display_options['relationships']['field_column_values_value']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_values_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['relationship'] = 'field_column_values_value';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_title_plain';
  /* Field: Field collection item: Availability */
  $handler->display->display_options['fields']['field_availability']['id'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['table'] = 'field_data_field_availability';
  $handler->display->display_options['fields']['field_availability']['field'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['relationship'] = 'field_column_values_value';
  $handler->display->display_options['fields']['field_availability']['label'] = '';
  $handler->display->display_options['fields']['field_availability']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link_1']['id'] = 'field_link_1';
  $handler->display->display_options['fields']['field_link_1']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link_1']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link_1']['relationship'] = 'field_column_values_value';
  $handler->display->display_options['fields']['field_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link_1']['type'] = 'link_plain';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field collection item: Column Number (field_column_number) */
  $handler->display->display_options['sorts']['field_column_number_value']['id'] = 'field_column_number_value';
  $handler->display->display_options['sorts']['field_column_number_value']['table'] = 'field_data_field_column_number';
  $handler->display->display_options['sorts']['field_column_number_value']['field'] = 'field_column_number_value';
  $handler->display->display_options['sorts']['field_column_number_value']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field collection item: Field collection item ID */
  $handler->display->display_options['arguments']['item_id']['id'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['item_id']['field'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['arguments']['item_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['item_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['item_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['item_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['item_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'target_data_matrix' => 'target_data_matrix',
  );

  /* Display: TARGET Copy Number Column Header */
  $handler = $view->new_display('block', 'TARGET Copy Number Column Header', 'target_copy_number_column_header');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Disease (field_target_disease) */
  $handler->display->display_options['relationships']['field_target_disease_value']['id'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_target_disease_value']['table'] = 'field_data_field_target_disease';
  $handler->display->display_options['relationships']['field_target_disease_value']['field'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_target_disease_value']['delta'] = '-1';
  /* Relationship: Field collection item: Copy Number (field_copy_number) */
  $handler->display->display_options['relationships']['field_copy_number_value']['id'] = 'field_copy_number_value';
  $handler->display->display_options['relationships']['field_copy_number_value']['table'] = 'field_data_field_copy_number';
  $handler->display->display_options['relationships']['field_copy_number_value']['field'] = 'field_copy_number_value';
  $handler->display->display_options['relationships']['field_copy_number_value']['relationship'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_copy_number_value']['delta'] = '-1';
  /* Relationship: Field collection item: Column Header (field_column_header) */
  $handler->display->display_options['relationships']['field_column_header_value']['id'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['table'] = 'field_data_field_column_header';
  $handler->display->display_options['relationships']['field_column_header_value']['field'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['relationship'] = 'field_copy_number_value';
  $handler->display->display_options['relationships']['field_column_header_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Field collection item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['item_id']['label'] = '';
  $handler->display->display_options['fields']['item_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['item_id']['separator'] = '';
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_title_plain';
  /* Field: Field collection item: Availability */
  $handler->display->display_options['fields']['field_availability']['id'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['table'] = 'field_data_field_availability';
  $handler->display->display_options['fields']['field_availability']['field'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_availability']['label'] = '';
  $handler->display->display_options['fields']['field_availability']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Column Number */
  $handler->display->display_options['fields']['field_column_number']['id'] = 'field_column_number';
  $handler->display->display_options['fields']['field_column_number']['table'] = 'field_data_field_column_number';
  $handler->display->display_options['fields']['field_column_number']['field'] = 'field_column_number';
  $handler->display->display_options['fields']['field_column_number']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_column_number']['label'] = '';
  $handler->display->display_options['fields']['field_column_number']['element_label_colon'] = FALSE;
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['view'] = 'cgci_data_matrix';
  $handler->display->display_options['fields']['view']['display'] = 'target_copy_number_column_values';
  $handler->display->display_options['fields']['view']['arguments'] = '[!item_id]';
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link_1']['id'] = 'field_link_1';
  $handler->display->display_options['fields']['field_link_1']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link_1']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link_1']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link_1']['type'] = 'link_plain';
  /* Field: disease_id */
  $handler->display->display_options['fields']['item_id_1']['id'] = 'item_id_1';
  $handler->display->display_options['fields']['item_id_1']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id_1']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id_1']['relationship'] = 'field_target_disease_value';
  $handler->display->display_options['fields']['item_id_1']['ui_name'] = 'disease_id';
  $handler->display->display_options['fields']['item_id_1']['label'] = '';
  $handler->display->display_options['fields']['item_id_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['item_id_1']['separator'] = '';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field collection item: Field collection item ID */
  $handler->display->display_options['arguments']['item_id']['id'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['item_id']['field'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['relationship'] = 'field_target_disease_value';
  $handler->display->display_options['arguments']['item_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['item_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['item_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['item_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'target_data_matrix' => 'target_data_matrix',
  );

  /* Display: TARGET Copy Number Column Values */
  $handler = $view->new_display('block', 'TARGET Copy Number Column Values', 'target_copy_number_column_values');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Disease (field_target_disease) */
  $handler->display->display_options['relationships']['field_target_disease_value']['id'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_target_disease_value']['table'] = 'field_data_field_target_disease';
  $handler->display->display_options['relationships']['field_target_disease_value']['field'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_target_disease_value']['delta'] = '-1';
  /* Relationship: Field collection item: Copy Number (field_copy_number) */
  $handler->display->display_options['relationships']['field_copy_number_value']['id'] = 'field_copy_number_value';
  $handler->display->display_options['relationships']['field_copy_number_value']['table'] = 'field_data_field_copy_number';
  $handler->display->display_options['relationships']['field_copy_number_value']['field'] = 'field_copy_number_value';
  $handler->display->display_options['relationships']['field_copy_number_value']['relationship'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_copy_number_value']['delta'] = '-1';
  /* Relationship: Field collection item: Column Header (field_column_header) */
  $handler->display->display_options['relationships']['field_column_header_value']['id'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['table'] = 'field_data_field_column_header';
  $handler->display->display_options['relationships']['field_column_header_value']['field'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['relationship'] = 'field_copy_number_value';
  $handler->display->display_options['relationships']['field_column_header_value']['delta'] = '-1';
  /* Relationship: Field collection item: Column Values (field_column_values) */
  $handler->display->display_options['relationships']['field_column_values_value']['id'] = 'field_column_values_value';
  $handler->display->display_options['relationships']['field_column_values_value']['table'] = 'field_data_field_column_values';
  $handler->display->display_options['relationships']['field_column_values_value']['field'] = 'field_column_values_value';
  $handler->display->display_options['relationships']['field_column_values_value']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_values_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['relationship'] = 'field_column_values_value';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_title_plain';
  /* Field: Field collection item: Availability */
  $handler->display->display_options['fields']['field_availability']['id'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['table'] = 'field_data_field_availability';
  $handler->display->display_options['fields']['field_availability']['field'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['relationship'] = 'field_column_values_value';
  $handler->display->display_options['fields']['field_availability']['label'] = '';
  $handler->display->display_options['fields']['field_availability']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link_1']['id'] = 'field_link_1';
  $handler->display->display_options['fields']['field_link_1']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link_1']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link_1']['relationship'] = 'field_column_values_value';
  $handler->display->display_options['fields']['field_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link_1']['type'] = 'link_plain';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field collection item: Field collection item ID */
  $handler->display->display_options['arguments']['item_id']['id'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['item_id']['field'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['arguments']['item_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['item_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['item_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['item_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['item_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'target_data_matrix' => 'target_data_matrix',
  );

  /* Display: TARGET Methylation Column Header */
  $handler = $view->new_display('block', 'TARGET Methylation Column Header', 'target_methylation_column_header');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Disease (field_target_disease) */
  $handler->display->display_options['relationships']['field_target_disease_value']['id'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_target_disease_value']['table'] = 'field_data_field_target_disease';
  $handler->display->display_options['relationships']['field_target_disease_value']['field'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_target_disease_value']['delta'] = '-1';
  /* Relationship: Field collection item: Methylation (field_methylation) */
  $handler->display->display_options['relationships']['field_methylation_value']['id'] = 'field_methylation_value';
  $handler->display->display_options['relationships']['field_methylation_value']['table'] = 'field_data_field_methylation';
  $handler->display->display_options['relationships']['field_methylation_value']['field'] = 'field_methylation_value';
  $handler->display->display_options['relationships']['field_methylation_value']['relationship'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_methylation_value']['delta'] = '-1';
  /* Relationship: Field collection item: Column Header (field_column_header) */
  $handler->display->display_options['relationships']['field_column_header_value']['id'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['table'] = 'field_data_field_column_header';
  $handler->display->display_options['relationships']['field_column_header_value']['field'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['relationship'] = 'field_methylation_value';
  $handler->display->display_options['relationships']['field_column_header_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Field collection item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['item_id']['label'] = '';
  $handler->display->display_options['fields']['item_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['item_id']['separator'] = '';
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_title_plain';
  /* Field: Field collection item: Availability */
  $handler->display->display_options['fields']['field_availability']['id'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['table'] = 'field_data_field_availability';
  $handler->display->display_options['fields']['field_availability']['field'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_availability']['label'] = '';
  $handler->display->display_options['fields']['field_availability']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Column Number */
  $handler->display->display_options['fields']['field_column_number']['id'] = 'field_column_number';
  $handler->display->display_options['fields']['field_column_number']['table'] = 'field_data_field_column_number';
  $handler->display->display_options['fields']['field_column_number']['field'] = 'field_column_number';
  $handler->display->display_options['fields']['field_column_number']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_column_number']['label'] = '';
  $handler->display->display_options['fields']['field_column_number']['element_label_colon'] = FALSE;
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['view'] = 'cgci_data_matrix';
  $handler->display->display_options['fields']['view']['display'] = 'target_methylation_column_values';
  $handler->display->display_options['fields']['view']['arguments'] = '[!item_id]';
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link_1']['id'] = 'field_link_1';
  $handler->display->display_options['fields']['field_link_1']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link_1']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link_1']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link_1']['type'] = 'link_plain';
  /* Field: disease_id */
  $handler->display->display_options['fields']['item_id_1']['id'] = 'item_id_1';
  $handler->display->display_options['fields']['item_id_1']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id_1']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id_1']['relationship'] = 'field_target_disease_value';
  $handler->display->display_options['fields']['item_id_1']['ui_name'] = 'disease_id';
  $handler->display->display_options['fields']['item_id_1']['label'] = '';
  $handler->display->display_options['fields']['item_id_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['item_id_1']['separator'] = '';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field collection item: Field collection item ID */
  $handler->display->display_options['arguments']['item_id']['id'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['item_id']['field'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['relationship'] = 'field_target_disease_value';
  $handler->display->display_options['arguments']['item_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['item_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['item_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['item_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'target_data_matrix' => 'target_data_matrix',
  );

  /* Display: TARGET Methylation Column Values */
  $handler = $view->new_display('block', 'TARGET Methylation Column Values', 'target_methylation_column_values');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Disease (field_target_disease) */
  $handler->display->display_options['relationships']['field_target_disease_value']['id'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_target_disease_value']['table'] = 'field_data_field_target_disease';
  $handler->display->display_options['relationships']['field_target_disease_value']['field'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_target_disease_value']['delta'] = '-1';
  /* Relationship: Field collection item: Methylation (field_methylation) */
  $handler->display->display_options['relationships']['field_methylation_value']['id'] = 'field_methylation_value';
  $handler->display->display_options['relationships']['field_methylation_value']['table'] = 'field_data_field_methylation';
  $handler->display->display_options['relationships']['field_methylation_value']['field'] = 'field_methylation_value';
  $handler->display->display_options['relationships']['field_methylation_value']['relationship'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_methylation_value']['delta'] = '-1';
  /* Relationship: Field collection item: Column Header (field_column_header) */
  $handler->display->display_options['relationships']['field_column_header_value']['id'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['table'] = 'field_data_field_column_header';
  $handler->display->display_options['relationships']['field_column_header_value']['field'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['relationship'] = 'field_methylation_value';
  $handler->display->display_options['relationships']['field_column_header_value']['delta'] = '-1';
  /* Relationship: Field collection item: Column Values (field_column_values) */
  $handler->display->display_options['relationships']['field_column_values_value']['id'] = 'field_column_values_value';
  $handler->display->display_options['relationships']['field_column_values_value']['table'] = 'field_data_field_column_values';
  $handler->display->display_options['relationships']['field_column_values_value']['field'] = 'field_column_values_value';
  $handler->display->display_options['relationships']['field_column_values_value']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_values_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['relationship'] = 'field_column_values_value';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_title_plain';
  /* Field: Field collection item: Availability */
  $handler->display->display_options['fields']['field_availability']['id'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['table'] = 'field_data_field_availability';
  $handler->display->display_options['fields']['field_availability']['field'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['relationship'] = 'field_column_values_value';
  $handler->display->display_options['fields']['field_availability']['label'] = '';
  $handler->display->display_options['fields']['field_availability']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link_1']['id'] = 'field_link_1';
  $handler->display->display_options['fields']['field_link_1']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link_1']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link_1']['relationship'] = 'field_column_values_value';
  $handler->display->display_options['fields']['field_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link_1']['type'] = 'link_plain';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field collection item: Field collection item ID */
  $handler->display->display_options['arguments']['item_id']['id'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['item_id']['field'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['arguments']['item_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['item_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['item_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['item_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['item_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'target_data_matrix' => 'target_data_matrix',
  );

  /* Display: TARGET miRNA Column Header */
  $handler = $view->new_display('block', 'TARGET miRNA Column Header', 'target_mirna_column_header');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Disease (field_target_disease) */
  $handler->display->display_options['relationships']['field_target_disease_value']['id'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_target_disease_value']['table'] = 'field_data_field_target_disease';
  $handler->display->display_options['relationships']['field_target_disease_value']['field'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_target_disease_value']['delta'] = '-1';
  /* Relationship: Field collection item: miRNA (field_mirna) */
  $handler->display->display_options['relationships']['field_mirna_value']['id'] = 'field_mirna_value';
  $handler->display->display_options['relationships']['field_mirna_value']['table'] = 'field_data_field_mirna';
  $handler->display->display_options['relationships']['field_mirna_value']['field'] = 'field_mirna_value';
  $handler->display->display_options['relationships']['field_mirna_value']['relationship'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_mirna_value']['delta'] = '-1';
  /* Relationship: Field collection item: Column Header (field_column_header) */
  $handler->display->display_options['relationships']['field_column_header_value']['id'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['table'] = 'field_data_field_column_header';
  $handler->display->display_options['relationships']['field_column_header_value']['field'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['relationship'] = 'field_mirna_value';
  $handler->display->display_options['relationships']['field_column_header_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Field collection item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['item_id']['label'] = '';
  $handler->display->display_options['fields']['item_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['item_id']['separator'] = '';
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_title_plain';
  /* Field: Field collection item: Availability */
  $handler->display->display_options['fields']['field_availability']['id'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['table'] = 'field_data_field_availability';
  $handler->display->display_options['fields']['field_availability']['field'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_availability']['label'] = '';
  $handler->display->display_options['fields']['field_availability']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Column Number */
  $handler->display->display_options['fields']['field_column_number']['id'] = 'field_column_number';
  $handler->display->display_options['fields']['field_column_number']['table'] = 'field_data_field_column_number';
  $handler->display->display_options['fields']['field_column_number']['field'] = 'field_column_number';
  $handler->display->display_options['fields']['field_column_number']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_column_number']['label'] = '';
  $handler->display->display_options['fields']['field_column_number']['element_label_colon'] = FALSE;
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['view'] = 'cgci_data_matrix';
  $handler->display->display_options['fields']['view']['display'] = 'target_mirna_column_values';
  $handler->display->display_options['fields']['view']['arguments'] = '[!item_id]';
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link_1']['id'] = 'field_link_1';
  $handler->display->display_options['fields']['field_link_1']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link_1']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link_1']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link_1']['type'] = 'link_plain';
  /* Field: disease_id */
  $handler->display->display_options['fields']['item_id_1']['id'] = 'item_id_1';
  $handler->display->display_options['fields']['item_id_1']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id_1']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id_1']['relationship'] = 'field_target_disease_value';
  $handler->display->display_options['fields']['item_id_1']['ui_name'] = 'disease_id';
  $handler->display->display_options['fields']['item_id_1']['label'] = '';
  $handler->display->display_options['fields']['item_id_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['item_id_1']['separator'] = '';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field collection item: Field collection item ID */
  $handler->display->display_options['arguments']['item_id']['id'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['item_id']['field'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['relationship'] = 'field_target_disease_value';
  $handler->display->display_options['arguments']['item_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['item_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['item_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['item_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'target_data_matrix' => 'target_data_matrix',
  );

  /* Display: TARGET miRNA Column Values */
  $handler = $view->new_display('block', 'TARGET miRNA Column Values', 'target_mirna_column_values');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Disease (field_target_disease) */
  $handler->display->display_options['relationships']['field_target_disease_value']['id'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_target_disease_value']['table'] = 'field_data_field_target_disease';
  $handler->display->display_options['relationships']['field_target_disease_value']['field'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_target_disease_value']['delta'] = '-1';
  /* Relationship: Field collection item: miRNA (field_mirna) */
  $handler->display->display_options['relationships']['field_mirna_value']['id'] = 'field_mirna_value';
  $handler->display->display_options['relationships']['field_mirna_value']['table'] = 'field_data_field_mirna';
  $handler->display->display_options['relationships']['field_mirna_value']['field'] = 'field_mirna_value';
  $handler->display->display_options['relationships']['field_mirna_value']['relationship'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_mirna_value']['delta'] = '-1';
  /* Relationship: Field collection item: Column Header (field_column_header) */
  $handler->display->display_options['relationships']['field_column_header_value']['id'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['table'] = 'field_data_field_column_header';
  $handler->display->display_options['relationships']['field_column_header_value']['field'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['relationship'] = 'field_mirna_value';
  $handler->display->display_options['relationships']['field_column_header_value']['delta'] = '-1';
  /* Relationship: Field collection item: Column Values (field_column_values) */
  $handler->display->display_options['relationships']['field_column_values_value']['id'] = 'field_column_values_value';
  $handler->display->display_options['relationships']['field_column_values_value']['table'] = 'field_data_field_column_values';
  $handler->display->display_options['relationships']['field_column_values_value']['field'] = 'field_column_values_value';
  $handler->display->display_options['relationships']['field_column_values_value']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_values_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['relationship'] = 'field_column_values_value';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_title_plain';
  /* Field: Field collection item: Availability */
  $handler->display->display_options['fields']['field_availability']['id'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['table'] = 'field_data_field_availability';
  $handler->display->display_options['fields']['field_availability']['field'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['relationship'] = 'field_column_values_value';
  $handler->display->display_options['fields']['field_availability']['label'] = '';
  $handler->display->display_options['fields']['field_availability']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link_1']['id'] = 'field_link_1';
  $handler->display->display_options['fields']['field_link_1']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link_1']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link_1']['relationship'] = 'field_column_values_value';
  $handler->display->display_options['fields']['field_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link_1']['type'] = 'link_plain';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field collection item: Field collection item ID */
  $handler->display->display_options['arguments']['item_id']['id'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['item_id']['field'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['arguments']['item_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['item_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['item_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['item_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['item_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'target_data_matrix' => 'target_data_matrix',
  );

  /* Display: TARGET Other Column Header */
  $handler = $view->new_display('block', 'TARGET Other Column Header', 'target_other_column_header');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Disease (field_target_disease) */
  $handler->display->display_options['relationships']['field_target_disease_value']['id'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_target_disease_value']['table'] = 'field_data_field_target_disease';
  $handler->display->display_options['relationships']['field_target_disease_value']['field'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_target_disease_value']['delta'] = '-1';
  /* Relationship: Field collection item: Other (field_other) */
  $handler->display->display_options['relationships']['field_other_value']['id'] = 'field_other_value';
  $handler->display->display_options['relationships']['field_other_value']['table'] = 'field_data_field_other';
  $handler->display->display_options['relationships']['field_other_value']['field'] = 'field_other_value';
  $handler->display->display_options['relationships']['field_other_value']['relationship'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_other_value']['delta'] = '-1';
  /* Relationship: Field collection item: Column Header (field_column_header) */
  $handler->display->display_options['relationships']['field_column_header_value']['id'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['table'] = 'field_data_field_column_header';
  $handler->display->display_options['relationships']['field_column_header_value']['field'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['relationship'] = 'field_other_value';
  $handler->display->display_options['relationships']['field_column_header_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Field collection item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['item_id']['label'] = '';
  $handler->display->display_options['fields']['item_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['item_id']['separator'] = '';
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_title_plain';
  /* Field: Field collection item: Availability */
  $handler->display->display_options['fields']['field_availability']['id'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['table'] = 'field_data_field_availability';
  $handler->display->display_options['fields']['field_availability']['field'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_availability']['label'] = '';
  $handler->display->display_options['fields']['field_availability']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Column Number */
  $handler->display->display_options['fields']['field_column_number']['id'] = 'field_column_number';
  $handler->display->display_options['fields']['field_column_number']['table'] = 'field_data_field_column_number';
  $handler->display->display_options['fields']['field_column_number']['field'] = 'field_column_number';
  $handler->display->display_options['fields']['field_column_number']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_column_number']['label'] = '';
  $handler->display->display_options['fields']['field_column_number']['element_label_colon'] = FALSE;
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['view'] = 'cgci_data_matrix';
  $handler->display->display_options['fields']['view']['display'] = 'target_other_column_values';
  $handler->display->display_options['fields']['view']['arguments'] = '[!item_id]';
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link_1']['id'] = 'field_link_1';
  $handler->display->display_options['fields']['field_link_1']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link_1']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link_1']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['fields']['field_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link_1']['type'] = 'link_plain';
  /* Field: disease_id */
  $handler->display->display_options['fields']['item_id_1']['id'] = 'item_id_1';
  $handler->display->display_options['fields']['item_id_1']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id_1']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id_1']['relationship'] = 'field_target_disease_value';
  $handler->display->display_options['fields']['item_id_1']['ui_name'] = 'disease_id';
  $handler->display->display_options['fields']['item_id_1']['label'] = '';
  $handler->display->display_options['fields']['item_id_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['item_id_1']['separator'] = '';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field collection item: Field collection item ID */
  $handler->display->display_options['arguments']['item_id']['id'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['item_id']['field'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['relationship'] = 'field_target_disease_value';
  $handler->display->display_options['arguments']['item_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['item_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['item_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['item_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'target_data_matrix' => 'target_data_matrix',
  );

  /* Display: TARGET Other Column Values */
  $handler = $view->new_display('block', 'TARGET Other Column Values', 'target_other_column_values');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Disease (field_target_disease) */
  $handler->display->display_options['relationships']['field_target_disease_value']['id'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_target_disease_value']['table'] = 'field_data_field_target_disease';
  $handler->display->display_options['relationships']['field_target_disease_value']['field'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_target_disease_value']['delta'] = '-1';
  /* Relationship: Field collection item: Other (field_other) */
  $handler->display->display_options['relationships']['field_other_value']['id'] = 'field_other_value';
  $handler->display->display_options['relationships']['field_other_value']['table'] = 'field_data_field_other';
  $handler->display->display_options['relationships']['field_other_value']['field'] = 'field_other_value';
  $handler->display->display_options['relationships']['field_other_value']['relationship'] = 'field_target_disease_value';
  $handler->display->display_options['relationships']['field_other_value']['delta'] = '-1';
  /* Relationship: Field collection item: Column Header (field_column_header) */
  $handler->display->display_options['relationships']['field_column_header_value']['id'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['table'] = 'field_data_field_column_header';
  $handler->display->display_options['relationships']['field_column_header_value']['field'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_header_value']['relationship'] = 'field_other_value';
  $handler->display->display_options['relationships']['field_column_header_value']['delta'] = '-1';
  /* Relationship: Field collection item: Column Values (field_column_values) */
  $handler->display->display_options['relationships']['field_column_values_value']['id'] = 'field_column_values_value';
  $handler->display->display_options['relationships']['field_column_values_value']['table'] = 'field_data_field_column_values';
  $handler->display->display_options['relationships']['field_column_values_value']['field'] = 'field_column_values_value';
  $handler->display->display_options['relationships']['field_column_values_value']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['relationships']['field_column_values_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['relationship'] = 'field_column_values_value';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_title_plain';
  /* Field: Field collection item: Availability */
  $handler->display->display_options['fields']['field_availability']['id'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['table'] = 'field_data_field_availability';
  $handler->display->display_options['fields']['field_availability']['field'] = 'field_availability';
  $handler->display->display_options['fields']['field_availability']['relationship'] = 'field_column_values_value';
  $handler->display->display_options['fields']['field_availability']['label'] = '';
  $handler->display->display_options['fields']['field_availability']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_link_1']['id'] = 'field_link_1';
  $handler->display->display_options['fields']['field_link_1']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link_1']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link_1']['relationship'] = 'field_column_values_value';
  $handler->display->display_options['fields']['field_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link_1']['type'] = 'link_plain';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field collection item: Field collection item ID */
  $handler->display->display_options['arguments']['item_id']['id'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['item_id']['field'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['relationship'] = 'field_column_header_value';
  $handler->display->display_options['arguments']['item_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['item_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['item_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['item_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['item_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'target_data_matrix' => 'target_data_matrix',
  );
  $export['cgci_data_matrix'] = $view;

  return $export;
}
