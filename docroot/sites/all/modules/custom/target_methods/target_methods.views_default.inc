<?php
/**
 * @file
 * target_methods.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function target_methods_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'target_methods';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Target Methods';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Target Methods';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['tags']['first'] = 'first';
  $handler->display->display_options['pager']['options']['tags']['previous'] = 'previous';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'next';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'last';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Content: Sample Processing (field_sample_processing) */
  $handler->display->display_options['relationships']['field_sample_processing_value']['id'] = 'field_sample_processing_value';
  $handler->display->display_options['relationships']['field_sample_processing_value']['table'] = 'field_data_field_sample_processing';
  $handler->display->display_options['relationships']['field_sample_processing_value']['field'] = 'field_sample_processing_value';
  $handler->display->display_options['relationships']['field_sample_processing_value']['delta'] = '-1';
  /* Field: Field collection item: General Methodology */
  $handler->display->display_options['fields']['field_general_methodology']['id'] = 'field_general_methodology';
  $handler->display->display_options['fields']['field_general_methodology']['table'] = 'field_data_field_general_methodology';
  $handler->display->display_options['fields']['field_general_methodology']['field'] = 'field_general_methodology';
  $handler->display->display_options['fields']['field_general_methodology']['relationship'] = 'field_sample_processing_value';
  /* Field: Field collection item: Sample Preparation Protocols */
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['id'] = 'field_sample_preparation_protoco';
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['table'] = 'field_data_field_sample_preparation_protoco';
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['field'] = 'field_sample_preparation_protoco';
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['relationship'] = 'field_sample_processing_value';
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['alter']['text'] = '[field_sample_preparation_protoco-value]';
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['alter']['path'] = '#[field_sample_preparation_protoco-value]';
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 0,
    'view_mode' => 'protocol',
  );
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'target_methods' => 'target_methods',
  );

  /* Display: Legend */
  $handler = $view->new_display('block', 'Legend', 'legend');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Sample Processing (field_sample_processing) */
  $handler->display->display_options['relationships']['field_sample_processing_value']['id'] = 'field_sample_processing_value';
  $handler->display->display_options['relationships']['field_sample_processing_value']['table'] = 'field_data_field_sample_processing';
  $handler->display->display_options['relationships']['field_sample_processing_value']['field'] = 'field_sample_processing_value';
  $handler->display->display_options['relationships']['field_sample_processing_value']['delta'] = '-1';
  /* Relationship: Field collection item: Sample Preparation Protocols (field_sample_preparation_protoco) */
  $handler->display->display_options['relationships']['field_sample_preparation_protoco_value']['id'] = 'field_sample_preparation_protoco_value';
  $handler->display->display_options['relationships']['field_sample_preparation_protoco_value']['table'] = 'field_data_field_sample_preparation_protoco';
  $handler->display->display_options['relationships']['field_sample_preparation_protoco_value']['field'] = 'field_sample_preparation_protoco_value';
  $handler->display->display_options['relationships']['field_sample_preparation_protoco_value']['relationship'] = 'field_sample_processing_value';
  $handler->display->display_options['relationships']['field_sample_preparation_protoco_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Symbol */
  $handler->display->display_options['fields']['field_symbol']['id'] = 'field_symbol';
  $handler->display->display_options['fields']['field_symbol']['table'] = 'field_data_field_symbol';
  $handler->display->display_options['fields']['field_symbol']['field'] = 'field_symbol';
  $handler->display->display_options['fields']['field_symbol']['relationship'] = 'field_sample_preparation_protoco_value';
  $handler->display->display_options['fields']['field_symbol']['label'] = '';
  $handler->display->display_options['fields']['field_symbol']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_symbol']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_symbol']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_symbol']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Field collection item: Legend */
  $handler->display->display_options['fields']['field_legend']['id'] = 'field_legend';
  $handler->display->display_options['fields']['field_legend']['table'] = 'field_data_field_legend';
  $handler->display->display_options['fields']['field_legend']['field'] = 'field_legend';
  $handler->display->display_options['fields']['field_legend']['relationship'] = 'field_sample_preparation_protoco_value';
  $handler->display->display_options['fields']['field_legend']['label'] = '';
  $handler->display->display_options['fields']['field_legend']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_legend']['alter']['text'] = '[field_symbol] [field_legend]';
  $handler->display->display_options['fields']['field_legend']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field collection item: Legend (field_legend) */
  $handler->display->display_options['sorts']['field_legend_value']['id'] = 'field_legend_value';
  $handler->display->display_options['sorts']['field_legend_value']['table'] = 'field_data_field_legend';
  $handler->display->display_options['sorts']['field_legend_value']['field'] = 'field_legend_value';
  $handler->display->display_options['sorts']['field_legend_value']['relationship'] = 'field_sample_processing_value';
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
    'target_methods' => 'target_methods',
  );

  /* Display: Body */
  $handler = $view->new_display('block', 'Body', 'body');
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
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;

  /* Display: Description */
  $handler = $view->new_display('block', 'Description', 'description');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Sample Preparation Protocols */
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['id'] = 'field_sample_preparation_protoco';
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['table'] = 'field_data_field_sample_preparation_protoco';
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['field'] = 'field_sample_preparation_protoco';
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['relationship'] = 'field_sample_processing_value';
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['label'] = '';
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['alter']['text'] = '<span id="[field_sample_preparation_protoco-value]">[field_sample_preparation_protoco]</span>';
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['alter']['path'] = '[field_sample_preparation_protoco-value]';
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 0,
    'view_mode' => 'description',
  );
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['delta_offset'] = '0';

  /* Display: Table */
  $handler = $view->new_display('block', 'Table', 'table');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: General Methodology */
  $handler->display->display_options['fields']['field_general_methodology']['id'] = 'field_general_methodology';
  $handler->display->display_options['fields']['field_general_methodology']['table'] = 'field_data_field_general_methodology';
  $handler->display->display_options['fields']['field_general_methodology']['field'] = 'field_general_methodology';
  $handler->display->display_options['fields']['field_general_methodology']['relationship'] = 'field_sample_processing_value';
  /* Field: Field collection item: Sample Preparation Protocols */
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['id'] = 'field_sample_preparation_protoco';
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['table'] = 'field_data_field_sample_preparation_protoco';
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['field'] = 'field_sample_preparation_protoco';
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['relationship'] = 'field_sample_processing_value';
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['alter']['text'] = '[field_sample_preparation_protoco-value]';
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['alter']['path'] = '#[field_sample_preparation_protoco-value]';
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['alter']['preserve_tags'] = '<img>';
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 0,
    'view_mode' => 'protocol',
  );
  $handler->display->display_options['fields']['field_sample_preparation_protoco']['delta_offset'] = '0';

  /* Display: Projects */
  $handler = $view->new_display('block', 'Projects', 'projects');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'views-accordion';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Title */
  $handler->display->display_options['fields']['field_target_methods_projects_1']['id'] = 'field_target_methods_projects_1';
  $handler->display->display_options['fields']['field_target_methods_projects_1']['table'] = 'field_data_field_target_methods_projects';
  $handler->display->display_options['fields']['field_target_methods_projects_1']['field'] = 'field_target_methods_projects';
  $handler->display->display_options['fields']['field_target_methods_projects_1']['ui_name'] = 'Title';
  $handler->display->display_options['fields']['field_target_methods_projects_1']['label'] = '';
  $handler->display->display_options['fields']['field_target_methods_projects_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_target_methods_projects_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_target_methods_projects_1']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_target_methods_projects_1']['delta_offset'] = '0';
  /* Field: Global: Fieldset */
  $handler->display->display_options['fields']['fieldset']['id'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['fieldset']['alter']['text'] = '[field_target_methods_projects_1]';
  $handler->display->display_options['fields']['fieldset']['children'] = array(
    0 => 'field_target_methods_projects',
  );
  $handler->display->display_options['fields']['fieldset']['fieldset']['id'] = '[field_target_methods_projects_1]';
  $handler->display->display_options['fields']['fieldset']['fieldset']['collapsible'] = 1;
  $handler->display->display_options['fields']['fieldset']['fieldset']['collapsed'] = 1;
  /* Field: Content: Projects */
  $handler->display->display_options['fields']['field_target_methods_projects']['id'] = 'field_target_methods_projects';
  $handler->display->display_options['fields']['field_target_methods_projects']['table'] = 'field_data_field_target_methods_projects';
  $handler->display->display_options['fields']['field_target_methods_projects']['field'] = 'field_target_methods_projects';
  $handler->display->display_options['fields']['field_target_methods_projects']['label'] = '';
  $handler->display->display_options['fields']['field_target_methods_projects']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_target_methods_projects']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_target_methods_projects']['settings'] = array(
    'view_mode' => 'default',
    'links' => 1,
  );
  $handler->display->display_options['fields']['field_target_methods_projects']['delta_offset'] = '0';

  /* Display: Projects Table */
  $handler = $view->new_display('block', 'Projects Table', 'projects_table');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Table Row (field_table_row) */
  $handler->display->display_options['relationships']['field_table_row_value']['id'] = 'field_table_row_value';
  $handler->display->display_options['relationships']['field_table_row_value']['table'] = 'field_data_field_table_row';
  $handler->display->display_options['relationships']['field_table_row_value']['field'] = 'field_table_row_value';
  $handler->display->display_options['relationships']['field_table_row_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: General Methodology */
  $handler->display->display_options['fields']['field_general_methodology']['id'] = 'field_general_methodology';
  $handler->display->display_options['fields']['field_general_methodology']['table'] = 'field_data_field_general_methodology';
  $handler->display->display_options['fields']['field_general_methodology']['field'] = 'field_general_methodology';
  $handler->display->display_options['fields']['field_general_methodology']['relationship'] = 'field_table_row_value';
  /* Field: Field collection item: Data Analysis Protocols */
  $handler->display->display_options['fields']['field_data_analysis_protocols']['id'] = 'field_data_analysis_protocols';
  $handler->display->display_options['fields']['field_data_analysis_protocols']['table'] = 'field_data_field_data_analysis_protocols';
  $handler->display->display_options['fields']['field_data_analysis_protocols']['field'] = 'field_data_analysis_protocols';
  $handler->display->display_options['fields']['field_data_analysis_protocols']['relationship'] = 'field_table_row_value';
  $handler->display->display_options['fields']['field_data_analysis_protocols']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_data_analysis_protocols']['alter']['path'] = '#[field_data_analysis_protocols-value]';
  $handler->display->display_options['fields']['field_data_analysis_protocols']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_data_analysis_protocols']['alter']['preserve_tags'] = '<img>';
  $handler->display->display_options['fields']['field_data_analysis_protocols']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 1,
    'view_mode' => 'protocol',
  );
  $handler->display->display_options['fields']['field_data_analysis_protocols']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'target_methods_projects' => 'target_methods_projects',
  );
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
    'target_methods_projects' => 'target_methods_projects',
  );

  /* Display: Projects Description */
  $handler = $view->new_display('block', 'Projects Description', 'projects_description');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Table Row (field_table_row) */
  $handler->display->display_options['relationships']['field_table_row_value']['id'] = 'field_table_row_value';
  $handler->display->display_options['relationships']['field_table_row_value']['table'] = 'field_data_field_table_row';
  $handler->display->display_options['relationships']['field_table_row_value']['field'] = 'field_table_row_value';
  $handler->display->display_options['relationships']['field_table_row_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Data Analysis Protocols */
  $handler->display->display_options['fields']['field_data_analysis_protocols']['id'] = 'field_data_analysis_protocols';
  $handler->display->display_options['fields']['field_data_analysis_protocols']['table'] = 'field_data_field_data_analysis_protocols';
  $handler->display->display_options['fields']['field_data_analysis_protocols']['field'] = 'field_data_analysis_protocols';
  $handler->display->display_options['fields']['field_data_analysis_protocols']['relationship'] = 'field_table_row_value';
  $handler->display->display_options['fields']['field_data_analysis_protocols']['label'] = '';
  $handler->display->display_options['fields']['field_data_analysis_protocols']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_data_analysis_protocols']['alter']['text'] = '<span id="[field_data_analysis_protocols-value]">[field_data_analysis_protocols]</span>';
  $handler->display->display_options['fields']['field_data_analysis_protocols']['alter']['path'] = '#[field_data_analysis_protocols-value]';
  $handler->display->display_options['fields']['field_data_analysis_protocols']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_data_analysis_protocols']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 1,
    'view_mode' => 'description',
  );
  $handler->display->display_options['fields']['field_data_analysis_protocols']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_data_analysis_protocols']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'target_methods_projects' => 'target_methods_projects',
  );
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
    'target_methods_projects' => 'target_methods_projects',
  );
  $export['target_methods'] = $view;

  return $export;
}
