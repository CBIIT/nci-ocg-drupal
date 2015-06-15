<?php
/**
 * @file
 * ocg_dashboard.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ocg_dashboard_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'program_header';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Program Header';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Link to Data Source */
  $handler->display->display_options['fields']['field_programs_link_data_source']['id'] = 'field_programs_link_data_source';
  $handler->display->display_options['fields']['field_programs_link_data_source']['table'] = 'field_data_field_programs_link_data_source';
  $handler->display->display_options['fields']['field_programs_link_data_source']['field'] = 'field_programs_link_data_source';
  $handler->display->display_options['fields']['field_programs_link_data_source']['label'] = '';
  $handler->display->display_options['fields']['field_programs_link_data_source']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_programs_link_data_source']['alter']['text'] = 'View Data Target Matrix';
  $handler->display->display_options['fields']['field_programs_link_data_source']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_programs_link_data_source']['alter']['path'] = '[field_programs_link_data_source]';
  $handler->display->display_options['fields']['field_programs_link_data_source']['element_class'] = 'data-matrix';
  $handler->display->display_options['fields']['field_programs_link_data_source']['element_label_colon'] = FALSE;
  /* Field: Content: 'Using Data' Content */
  $handler->display->display_options['fields']['field_programs_using_data']['id'] = 'field_programs_using_data';
  $handler->display->display_options['fields']['field_programs_using_data']['table'] = 'field_data_field_programs_using_data';
  $handler->display->display_options['fields']['field_programs_using_data']['field'] = 'field_programs_using_data';
  $handler->display->display_options['fields']['field_programs_using_data']['label'] = '';
  $handler->display->display_options['fields']['field_programs_using_data']['element_class'] = 'corner';
  $handler->display->display_options['fields']['field_programs_using_data']['element_label_colon'] = FALSE;
  /* Field: Content: Abbreviated Title */
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['id'] = 'field_programs_abbreviated_title';
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['table'] = 'field_data_field_programs_abbreviated_title';
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['field'] = 'field_programs_abbreviated_title';
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['label'] = '';
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_programs_abbreviated_title]: <span>[title]</span>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h1';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
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
    'programs' => 'programs',
  );

  /* Display: Program Header (Program Page) */
  $handler = $view->new_display('block', 'Program Header (Program Page)', 'block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Abbreviated Title */
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['id'] = 'field_programs_abbreviated_title';
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['table'] = 'field_data_field_programs_abbreviated_title';
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['field'] = 'field_programs_abbreviated_title';
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['label'] = '';
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_programs_abbreviated_title]: <span>[title]</span>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h1';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_class'] = 'intro';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'nid';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = '3';
  $handler->display->display_options['fields']['views_conditional']['then'] = 'Portal';
  $handler->display->display_options['fields']['views_conditional']['or'] = 'Matrix';
  /* Field: Content: Link to Data Source */
  $handler->display->display_options['fields']['field_programs_link_data_source']['id'] = 'field_programs_link_data_source';
  $handler->display->display_options['fields']['field_programs_link_data_source']['table'] = 'field_data_field_programs_link_data_source';
  $handler->display->display_options['fields']['field_programs_link_data_source']['field'] = 'field_programs_link_data_source';
  $handler->display->display_options['fields']['field_programs_link_data_source']['label'] = '';
  $handler->display->display_options['fields']['field_programs_link_data_source']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_programs_link_data_source']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_programs_link_data_source']['alter']['text'] = '<a href="[field_programs_link_data_source-value]" target="_blank">View [field_programs_abbreviated_title] Data [views_conditional]<span class="noicon">Opens in a New Tab</span></a>';
  $handler->display->display_options['fields']['field_programs_link_data_source']['alter']['path'] = '[field_programs_link_data_source]';
  $handler->display->display_options['fields']['field_programs_link_data_source']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_programs_link_data_source']['element_class'] = 'data-matrix';
  $handler->display->display_options['fields']['field_programs_link_data_source']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programs_link_data_source']['hide_empty'] = TRUE;
  /* Field: Content: 'Using Data' Content */
  $handler->display->display_options['fields']['field_programs_using_data']['id'] = 'field_programs_using_data';
  $handler->display->display_options['fields']['field_programs_using_data']['table'] = 'field_data_field_programs_using_data';
  $handler->display->display_options['fields']['field_programs_using_data']['field'] = 'field_programs_using_data';
  $handler->display->display_options['fields']['field_programs_using_data']['label'] = '';
  $handler->display->display_options['fields']['field_programs_using_data']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_programs_using_data']['alter']['text'] = '<div>
[field_programs_link_data_source]
[field_programs_using_data]
</div>';
  $handler->display->display_options['fields']['field_programs_using_data']['element_class'] = 'corner';
  $handler->display->display_options['fields']['field_programs_using_data']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programs_using_data']['hide_empty'] = TRUE;
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

  /* Display: View Matrix (Program Sub Page) */
  $handler = $view->new_display('block', 'View Matrix (Program Sub Page)', 'block_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Abbreviated Title */
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['id'] = 'field_programs_abbreviated_title';
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['table'] = 'field_data_field_programs_abbreviated_title';
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['field'] = 'field_programs_abbreviated_title';
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['label'] = '';
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['element_label_colon'] = FALSE;
  /* Field: Content: Abbreviated Title for URL */
  $handler->display->display_options['fields']['field_abbreviated_title_url']['id'] = 'field_abbreviated_title_url';
  $handler->display->display_options['fields']['field_abbreviated_title_url']['table'] = 'field_data_field_abbreviated_title_url';
  $handler->display->display_options['fields']['field_abbreviated_title_url']['field'] = 'field_abbreviated_title_url';
  $handler->display->display_options['fields']['field_abbreviated_title_url']['label'] = '';
  $handler->display->display_options['fields']['field_abbreviated_title_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_abbreviated_title_url']['element_label_colon'] = FALSE;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'field_abbreviated_title_url';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'ctd2';
  $handler->display->display_options['fields']['views_conditional']['then'] = 'Portal';
  $handler->display->display_options['fields']['views_conditional']['or'] = 'Matrix';
  /* Field: Content: Link to Data Source */
  $handler->display->display_options['fields']['field_programs_link_data_source']['id'] = 'field_programs_link_data_source';
  $handler->display->display_options['fields']['field_programs_link_data_source']['table'] = 'field_data_field_programs_link_data_source';
  $handler->display->display_options['fields']['field_programs_link_data_source']['field'] = 'field_programs_link_data_source';
  $handler->display->display_options['fields']['field_programs_link_data_source']['label'] = '';
  $handler->display->display_options['fields']['field_programs_link_data_source']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_programs_link_data_source']['alter']['text'] = '<a href="[field_programs_link_data_source-value]" target="_blank">View [field_programs_abbreviated_title] Data [views_conditional]<span class="noicon">Opens in a New Tab</span></a>';
  $handler->display->display_options['fields']['field_programs_link_data_source']['alter']['path'] = '[field_programs_link_data_source]';
  $handler->display->display_options['fields']['field_programs_link_data_source']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_programs_link_data_source']['element_class'] = 'data-matrix';
  $handler->display->display_options['fields']['field_programs_link_data_source']['element_label_colon'] = FALSE;
  /* Field: Content: Link to Dashboard */
  $handler->display->display_options['fields']['field_link_to_dashboard']['id'] = 'field_link_to_dashboard';
  $handler->display->display_options['fields']['field_link_to_dashboard']['table'] = 'field_data_field_link_to_dashboard';
  $handler->display->display_options['fields']['field_link_to_dashboard']['field'] = 'field_link_to_dashboard';
  $handler->display->display_options['fields']['field_link_to_dashboard']['label'] = '';
  $handler->display->display_options['fields']['field_link_to_dashboard']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link_to_dashboard']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_link_to_dashboard']['alter']['text'] = '<a href="[field_link_to_dashboard]" target="_blank">View [field_programs_abbreviated_title] Dashboard<span class="noicon">Opens in a New Tab</span></a>';
  $handler->display->display_options['fields']['field_link_to_dashboard']['element_label_colon'] = FALSE;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_1']['id'] = 'views_conditional_1';
  $handler->display->display_options['fields']['views_conditional_1']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_1']['if'] = 'field_abbreviated_title_url';
  $handler->display->display_options['fields']['views_conditional_1']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional_1']['equalto'] = 'ctd2';
  $handler->display->display_options['fields']['views_conditional_1']['then'] = '[field_link_to_dashboard]';
  /* Field: Content: 'Using Data' Content */
  $handler->display->display_options['fields']['field_programs_using_data']['id'] = 'field_programs_using_data';
  $handler->display->display_options['fields']['field_programs_using_data']['table'] = 'field_data_field_programs_using_data';
  $handler->display->display_options['fields']['field_programs_using_data']['field'] = 'field_programs_using_data';
  $handler->display->display_options['fields']['field_programs_using_data']['label'] = '';
  $handler->display->display_options['fields']['field_programs_using_data']['element_class'] = 'corner';
  $handler->display->display_options['fields']['field_programs_using_data']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Abbreviated Title for URL (field_abbreviated_title_url) */
  $handler->display->display_options['arguments']['field_abbreviated_title_url_value']['id'] = 'field_abbreviated_title_url_value';
  $handler->display->display_options['arguments']['field_abbreviated_title_url_value']['table'] = 'field_data_field_abbreviated_title_url';
  $handler->display->display_options['arguments']['field_abbreviated_title_url_value']['field'] = 'field_abbreviated_title_url_value';
  $handler->display->display_options['arguments']['field_abbreviated_title_url_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_abbreviated_title_url_value']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_abbreviated_title_url_value']['default_argument_options']['code'] = 'if (arg(0) == \'programs\') {
  return arg(1);
} elseif ((arg(0) == \'node\') && (is_numeric(arg(1)))) {
  $url = explode(\'/\',$_SERVER[\'REQUEST_URI\']);
  if (isset($url[2])) { 
    if ($url[2] == \'ctd%C2%B2\') {
       return \'ctd²\';
    }
    else {
    return $url[2]; 
  }
}
}';
  $handler->display->display_options['arguments']['field_abbreviated_title_url_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_abbreviated_title_url_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_abbreviated_title_url_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_abbreviated_title_url_value']['limit'] = '0';
  $export['program_header'] = $view;

  return $export;
}
