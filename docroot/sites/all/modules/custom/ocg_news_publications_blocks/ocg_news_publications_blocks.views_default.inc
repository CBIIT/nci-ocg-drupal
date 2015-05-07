<?php
/**
 * @file
 * ocg_news_publications_blocks.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ocg_news_publications_blocks_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'news_and_publications';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'News';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'News';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'View In the News Page';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = 'first';
  $handler->display->display_options['pager']['options']['tags']['previous'] = 'previous';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'next';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'last';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_news_program_target_id']['id'] = 'field_news_program_target_id';
  $handler->display->display_options['relationships']['field_news_program_target_id']['table'] = 'field_data_field_news_program';
  $handler->display->display_options['relationships']['field_news_program_target_id']['field'] = 'field_news_program_target_id';
  /* Field: Content: Abbreviated Title */
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['id'] = 'field_programs_abbreviated_title';
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['table'] = 'field_data_field_programs_abbreviated_title';
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['field'] = 'field_programs_abbreviated_title';
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['relationship'] = 'field_news_program_target_id';
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['label'] = '';
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_news_date']['id'] = 'field_news_date';
  $handler->display->display_options['fields']['field_news_date']['table'] = 'field_data_field_news_date';
  $handler->display->display_options['fields']['field_news_date']['field'] = 'field_news_date';
  $handler->display->display_options['fields']['field_news_date']['label'] = '';
  $handler->display->display_options['fields']['field_news_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Date (field_news_date) */
  $handler->display->display_options['sorts']['field_news_date_value']['id'] = 'field_news_date_value';
  $handler->display->display_options['sorts']['field_news_date_value']['table'] = 'field_data_field_news_date';
  $handler->display->display_options['sorts']['field_news_date_value']['field'] = 'field_news_date_value';
  $handler->display->display_options['sorts']['field_news_date_value']['order'] = 'DESC';
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
    'news' => 'news',
  );

  /* Display: Featured News (Home) */
  $handler = $view->new_display('block', 'Featured News (Home)', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'In the News';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Program */
  $handler->display->display_options['fields']['field_news_program_1']['id'] = 'field_news_program_1';
  $handler->display->display_options['fields']['field_news_program_1']['table'] = 'field_data_field_news_program';
  $handler->display->display_options['fields']['field_news_program_1']['field'] = 'field_news_program';
  $handler->display->display_options['fields']['field_news_program_1']['label'] = '';
  $handler->display->display_options['fields']['field_news_program_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_news_program_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_program_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_news_program_1']['empty'] = 'all programs';
  $handler->display->display_options['fields']['field_news_program_1']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_news_program_1']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_news_program_1']['delta_offset'] = '0';
  /* Field: Content: Program */
  $handler->display->display_options['fields']['field_news_program']['id'] = 'field_news_program';
  $handler->display->display_options['fields']['field_news_program']['table'] = 'field_data_field_news_program';
  $handler->display->display_options['fields']['field_news_program']['field'] = 'field_news_program';
  $handler->display->display_options['fields']['field_news_program']['label'] = '';
  $handler->display->display_options['fields']['field_news_program']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_news_program']['element_class'] = 'program-[field_news_program_1]';
  $handler->display->display_options['fields']['field_news_program']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_program']['empty'] = 'All Programs';
  $handler->display->display_options['fields']['field_news_program']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_news_program']['settings'] = array(
    'view_mode' => 'abbreviation',
    'links' => 1,
  );
  $handler->display->display_options['fields']['field_news_program']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_news_program']['separator'] = ' ';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'span';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_news_date']['id'] = 'field_news_date';
  $handler->display->display_options['fields']['field_news_date']['table'] = 'field_data_field_news_date';
  $handler->display->display_options['fields']['field_news_date']['field'] = 'field_news_date';
  $handler->display->display_options['fields']['field_news_date']['label'] = '';
  $handler->display->display_options['fields']['field_news_date']['alter']['text'] = '<div class="right">
<div class="break">[field_news_date]</div>
<div class="views-field views-field-title"> <span class="field-content">[title]</span></div>
</div>';
  $handler->display->display_options['fields']['field_news_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date (field_news_date) */
  $handler->display->display_options['sorts']['field_news_date_value']['id'] = 'field_news_date_value';
  $handler->display->display_options['sorts']['field_news_date_value']['table'] = 'field_data_field_news_date';
  $handler->display->display_options['sorts']['field_news_date_value']['field'] = 'field_news_date_value';
  $handler->display->display_options['sorts']['field_news_date_value']['order'] = 'DESC';
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
    'news' => 'news',
  );

  /* Display: News (News Page) */
  $handler = $view->new_display('block', 'News (News Page)', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'In the News';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Program */
  $handler->display->display_options['fields']['field_news_program_1']['id'] = 'field_news_program_1';
  $handler->display->display_options['fields']['field_news_program_1']['table'] = 'field_data_field_news_program';
  $handler->display->display_options['fields']['field_news_program_1']['field'] = 'field_news_program';
  $handler->display->display_options['fields']['field_news_program_1']['label'] = '';
  $handler->display->display_options['fields']['field_news_program_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_news_program_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_program_1']['empty'] = 'all programs';
  $handler->display->display_options['fields']['field_news_program_1']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_news_program_1']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_news_program_1']['delta_offset'] = '0';
  /* Field: Content: Program */
  $handler->display->display_options['fields']['field_news_program']['id'] = 'field_news_program';
  $handler->display->display_options['fields']['field_news_program']['table'] = 'field_data_field_news_program';
  $handler->display->display_options['fields']['field_news_program']['field'] = 'field_news_program';
  $handler->display->display_options['fields']['field_news_program']['label'] = '';
  $handler->display->display_options['fields']['field_news_program']['element_class'] = 'program-[field_news_program_1]';
  $handler->display->display_options['fields']['field_news_program']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_program']['empty'] = 'All Programs';
  $handler->display->display_options['fields']['field_news_program']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_news_program']['settings'] = array(
    'view_mode' => 'abbreviation',
    'links' => 1,
  );
  $handler->display->display_options['fields']['field_news_program']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_news_program']['separator'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_news_date']['id'] = 'field_news_date';
  $handler->display->display_options['fields']['field_news_date']['table'] = 'field_data_field_news_date';
  $handler->display->display_options['fields']['field_news_date']['field'] = 'field_news_date';
  $handler->display->display_options['fields']['field_news_date']['label'] = '';
  $handler->display->display_options['fields']['field_news_date']['alter']['text'] = '<div class="right">
[field_news_date]
<h3>[title]</h3>
</div>';
  $handler->display->display_options['fields']['field_news_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
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
    'news' => 'news',
  );

  /* Display: News (Page) */
  $handler = $view->new_display('page', 'News (Page)', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'In the News';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'archive';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View News and Announcements Page';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = 'first';
  $handler->display->display_options['pager']['options']['tags']['previous'] = 'previous';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'next';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'last';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="intro"><p>Read the latest news on OCG to stay up-to-date on new research findings and important announcements.</p></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Program */
  $handler->display->display_options['fields']['field_news_program_1']['id'] = 'field_news_program_1';
  $handler->display->display_options['fields']['field_news_program_1']['table'] = 'field_data_field_news_program';
  $handler->display->display_options['fields']['field_news_program_1']['field'] = 'field_news_program';
  $handler->display->display_options['fields']['field_news_program_1']['label'] = '';
  $handler->display->display_options['fields']['field_news_program_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_news_program_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_program_1']['empty'] = 'all programs';
  $handler->display->display_options['fields']['field_news_program_1']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_news_program_1']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_news_program_1']['delta_offset'] = '0';
  /* Field: Content: Program */
  $handler->display->display_options['fields']['field_news_program']['id'] = 'field_news_program';
  $handler->display->display_options['fields']['field_news_program']['table'] = 'field_data_field_news_program';
  $handler->display->display_options['fields']['field_news_program']['field'] = 'field_news_program';
  $handler->display->display_options['fields']['field_news_program']['label'] = '';
  $handler->display->display_options['fields']['field_news_program']['element_class'] = 'program-[field_news_program_1]';
  $handler->display->display_options['fields']['field_news_program']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_program']['empty'] = 'All Programs';
  $handler->display->display_options['fields']['field_news_program']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_news_program']['settings'] = array(
    'view_mode' => 'abbreviation',
    'links' => 1,
  );
  $handler->display->display_options['fields']['field_news_program']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_news_program']['separator'] = ' ';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_news_date']['id'] = 'field_news_date';
  $handler->display->display_options['fields']['field_news_date']['table'] = 'field_data_field_news_date';
  $handler->display->display_options['fields']['field_news_date']['field'] = 'field_news_date';
  $handler->display->display_options['fields']['field_news_date']['label'] = '';
  $handler->display->display_options['fields']['field_news_date']['alter']['text'] = '<div class="right">
<div class="break">[field_news_date]</div>
<h2>[title]</h2>
[body]
</div>';
  $handler->display->display_options['fields']['field_news_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = '<p><span>';
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
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
    'news' => 'news',
  );
  $handler->display->display_options['path'] = 'news-publications/news';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'News';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Program News (Program Page) */
  $handler = $view->new_display('block', 'Program News (Program Page)', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'In the News';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View In the News Page';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_news_date']['id'] = 'field_news_date';
  $handler->display->display_options['fields']['field_news_date']['table'] = 'field_data_field_news_date';
  $handler->display->display_options['fields']['field_news_date']['field'] = 'field_news_date';
  $handler->display->display_options['fields']['field_news_date']['label'] = '';
  $handler->display->display_options['fields']['field_news_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Program (field_news_program) */
  $handler->display->display_options['arguments']['field_news_program_target_id']['id'] = 'field_news_program_target_id';
  $handler->display->display_options['arguments']['field_news_program_target_id']['table'] = 'field_data_field_news_program';
  $handler->display->display_options['arguments']['field_news_program_target_id']['field'] = 'field_news_program_target_id';
  $handler->display->display_options['arguments']['field_news_program_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_news_program_target_id']['exception']['value'] = 'programs';
  $handler->display->display_options['arguments']['field_news_program_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_news_program_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_news_program_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_news_program_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_news_program_target_id']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['field_news_program_target_id']['break_phrase'] = TRUE;
  $handler->display->display_options['arguments']['field_news_program_target_id']['not'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
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
    'news' => 'news',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date (field_news_date) */
  $handler->display->display_options['sorts']['field_news_date_value']['id'] = 'field_news_date_value';
  $handler->display->display_options['sorts']['field_news_date_value']['table'] = 'field_data_field_news_date';
  $handler->display->display_options['sorts']['field_news_date_value']['field'] = 'field_news_date_value';
  $handler->display->display_options['sorts']['field_news_date_value']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'rss/news.xml';

  /* Display: Featured News & Publications */
  $handler = $view->new_display('block', 'Featured News & Publications', 'featured_news_publications');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'News & Publications';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View In the News Page';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href="/news-publications/news">View In the News Page </a>';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: News Program */
  $handler->display->display_options['fields']['field_news_program']['id'] = 'field_news_program';
  $handler->display->display_options['fields']['field_news_program']['table'] = 'field_data_field_news_program';
  $handler->display->display_options['fields']['field_news_program']['field'] = 'field_news_program';
  $handler->display->display_options['fields']['field_news_program']['ui_name'] = 'News Program';
  $handler->display->display_options['fields']['field_news_program']['label'] = '';
  $handler->display->display_options['fields']['field_news_program']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_news_program']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_program']['empty'] = '<div class="all-programs">All Programs</div>';
  $handler->display->display_options['fields']['field_news_program']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_news_program']['settings'] = array(
    'view_mode' => 'abbreviation',
    'links' => 0,
  );
  $handler->display->display_options['fields']['field_news_program']['delta_offset'] = '0';
  /* Field: Publication Program */
  $handler->display->display_options['fields']['field_publication_program']['id'] = 'field_publication_program';
  $handler->display->display_options['fields']['field_publication_program']['table'] = 'field_data_field_publication_program';
  $handler->display->display_options['fields']['field_publication_program']['field'] = 'field_publication_program';
  $handler->display->display_options['fields']['field_publication_program']['ui_name'] = 'Publication Program';
  $handler->display->display_options['fields']['field_publication_program']['label'] = '';
  $handler->display->display_options['fields']['field_publication_program']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_publication_program']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_program']['empty'] = '<div class="all-programs">All Programs</div>';
  $handler->display->display_options['fields']['field_publication_program']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_publication_program']['settings'] = array(
    'view_mode' => 'abbreviation',
    'links' => 0,
  );
  $handler->display->display_options['fields']['field_publication_program']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'span';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: News Date */
  $handler->display->display_options['fields']['field_news_date']['id'] = 'field_news_date';
  $handler->display->display_options['fields']['field_news_date']['table'] = 'field_data_field_news_date';
  $handler->display->display_options['fields']['field_news_date']['field'] = 'field_news_date';
  $handler->display->display_options['fields']['field_news_date']['ui_name'] = 'News Date';
  $handler->display->display_options['fields']['field_news_date']['label'] = '';
  $handler->display->display_options['fields']['field_news_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_news_date']['alter']['text'] = '[field_news_program]<br />
[title]<br />
[field_news_date]';
  $handler->display->display_options['fields']['field_news_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_date']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_news_date']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_news_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Publication Date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['ui_name'] = 'Publication Date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = '';
  $handler->display->display_options['fields']['field_publication_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_publication_date']['alter']['text'] = '[field_publication_program]<br />
[title]<br />
[field_publication_date]';
  $handler->display->display_options['fields']['field_publication_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_publication_date']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date (field_publication_date) */
  $handler->display->display_options['sorts']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['order'] = 'DESC';
  /* Sort criterion: Content: Date (field_news_date) */
  $handler->display->display_options['sorts']['field_news_date_value']['id'] = 'field_news_date_value';
  $handler->display->display_options['sorts']['field_news_date_value']['table'] = 'field_data_field_news_date';
  $handler->display->display_options['sorts']['field_news_date_value']['field'] = 'field_news_date_value';
  $handler->display->display_options['sorts']['field_news_date_value']['order'] = 'DESC';
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
    'news' => 'news',
    'publication' => 'publication',
  );
  /* Filter criterion: Content: Feature on Home Page (field_home_page_feature) */
  $handler->display->display_options['filters']['field_home_page_feature_value']['id'] = 'field_home_page_feature_value';
  $handler->display->display_options['filters']['field_home_page_feature_value']['table'] = 'field_data_field_home_page_feature';
  $handler->display->display_options['filters']['field_home_page_feature_value']['field'] = 'field_home_page_feature_value';
  $handler->display->display_options['filters']['field_home_page_feature_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['block_description'] = 'New & Publications Block';
  $export['news_and_publications'] = $view;

  $view = new view();
  $view->name = 'publications';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Publications';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'View Publications Page';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = '';
  $handler->display->display_options['fields']['field_publication_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Date (field_publication_date) */
  $handler->display->display_options['sorts']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['order'] = 'DESC';
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
    'publication' => 'publication',
  );

  /* Display: Featured Content (Home) */
  $handler = $view->new_display('block', 'Featured Content (Home)', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Publications';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Program */
  $handler->display->display_options['fields']['field_publication_program_1']['id'] = 'field_publication_program_1';
  $handler->display->display_options['fields']['field_publication_program_1']['table'] = 'field_data_field_publication_program';
  $handler->display->display_options['fields']['field_publication_program_1']['field'] = 'field_publication_program';
  $handler->display->display_options['fields']['field_publication_program_1']['label'] = '';
  $handler->display->display_options['fields']['field_publication_program_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_publication_program_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_program_1']['empty'] = 'all programs';
  $handler->display->display_options['fields']['field_publication_program_1']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_publication_program_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_class'] = 'left';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'pubres_150x150',
    'image_link' => 'content',
  );
  /* Field: Content: Program */
  $handler->display->display_options['fields']['field_publication_program']['id'] = 'field_publication_program';
  $handler->display->display_options['fields']['field_publication_program']['table'] = 'field_data_field_publication_program';
  $handler->display->display_options['fields']['field_publication_program']['field'] = 'field_publication_program';
  $handler->display->display_options['fields']['field_publication_program']['label'] = '';
  $handler->display->display_options['fields']['field_publication_program']['element_class'] = 'program-[field_publication_program_1]';
  $handler->display->display_options['fields']['field_publication_program']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_program']['empty'] = 'All Programs';
  $handler->display->display_options['fields']['field_publication_program']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_publication_program']['settings'] = array(
    'view_mode' => 'abbreviation',
    'links' => 1,
  );
  $handler->display->display_options['fields']['field_publication_program']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_publication_program']['separator'] = ' ';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = '';
  $handler->display->display_options['fields']['field_publication_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Publication/Journal */
  $handler->display->display_options['fields']['field_publication_journal']['id'] = 'field_publication_journal';
  $handler->display->display_options['fields']['field_publication_journal']['table'] = 'field_data_field_publication_journal';
  $handler->display->display_options['fields']['field_publication_journal']['field'] = 'field_publication_journal';
  $handler->display->display_options['fields']['field_publication_journal']['label'] = '';
  $handler->display->display_options['fields']['field_publication_journal']['element_type'] = 'em';
  $handler->display->display_options['fields']['field_publication_journal']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_journal']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_publication_journal']['type'] = 'link_title_plain';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body_1']['id'] = 'body_1';
  $handler->display->display_options['fields']['body_1']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_1']['field'] = 'body';
  $handler->display->display_options['fields']['body_1']['label'] = '';
  $handler->display->display_options['fields']['body_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body_1']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body_1']['settings'] = array(
    'trim_length' => '300',
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
    'publication' => 'publication',
  );
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';

  /* Display: Publications (News Page) */
  $handler = $view->new_display('block', 'Publications (News Page)', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Publications';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'landing-page';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Program */
  $handler->display->display_options['fields']['field_publication_program_1']['id'] = 'field_publication_program_1';
  $handler->display->display_options['fields']['field_publication_program_1']['table'] = 'field_data_field_publication_program';
  $handler->display->display_options['fields']['field_publication_program_1']['field'] = 'field_publication_program';
  $handler->display->display_options['fields']['field_publication_program_1']['label'] = '';
  $handler->display->display_options['fields']['field_publication_program_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_publication_program_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_program_1']['empty'] = 'all programs';
  $handler->display->display_options['fields']['field_publication_program_1']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_publication_program_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_class'] = 'left';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'pubres_150x150',
    'image_link' => 'content',
  );
  /* Field: Content: Program */
  $handler->display->display_options['fields']['field_publication_program']['id'] = 'field_publication_program';
  $handler->display->display_options['fields']['field_publication_program']['table'] = 'field_data_field_publication_program';
  $handler->display->display_options['fields']['field_publication_program']['field'] = 'field_publication_program';
  $handler->display->display_options['fields']['field_publication_program']['label'] = '';
  $handler->display->display_options['fields']['field_publication_program']['element_class'] = 'program-[field_publication_program_1]';
  $handler->display->display_options['fields']['field_publication_program']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_program']['empty'] = 'All Programs';
  $handler->display->display_options['fields']['field_publication_program']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_publication_program']['settings'] = array(
    'view_mode' => 'abbreviation',
    'links' => 1,
  );
  $handler->display->display_options['fields']['field_publication_program']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_publication_program']['separator'] = ' ';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = '';
  $handler->display->display_options['fields']['field_publication_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_publication_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div class="right">
<div class="program-tag">[field_programs_abbreviated_title]</div>
<div class="break">[field_publication_date]</div>
<h3><a href="[path]">[title]</a></h3>
<i>[field_publication_journal]</i>
<div class="break">[body]</div>
</div>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Publication/Journal */
  $handler->display->display_options['fields']['field_publication_journal']['id'] = 'field_publication_journal';
  $handler->display->display_options['fields']['field_publication_journal']['table'] = 'field_data_field_publication_journal';
  $handler->display->display_options['fields']['field_publication_journal']['field'] = 'field_publication_journal';
  $handler->display->display_options['fields']['field_publication_journal']['label'] = '';
  $handler->display->display_options['fields']['field_publication_journal']['element_type'] = 'em';
  $handler->display->display_options['fields']['field_publication_journal']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_journal']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_publication_journal']['type'] = 'link_title_plain';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['text'] = '<div class="right">
<div class="program-tag">[field_programs_abbreviated_title]</div>
<div class="break">[field_publication_date]</div>
<h3>[title]</h3>
<a href="[field_publication_pubmed_link]">[field_publication_journal_name]</a>
<div class="break">[body]</div>
</div>';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );

  /* Display: Publications (Page) */
  $handler = $view->new_display('page', 'Publications (Page)', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Publications';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'archive';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View Publications Page';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = 'First';
  $handler->display->display_options['pager']['options']['tags']['previous'] = 'Previous';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'Next';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'Last';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="intro"><p>Included here is a list of publications from OCG programs.  All published data are available to the research community through the program-specific data matrices.</p></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Program */
  $handler->display->display_options['fields']['field_publication_program_1']['id'] = 'field_publication_program_1';
  $handler->display->display_options['fields']['field_publication_program_1']['table'] = 'field_data_field_publication_program';
  $handler->display->display_options['fields']['field_publication_program_1']['field'] = 'field_publication_program';
  $handler->display->display_options['fields']['field_publication_program_1']['label'] = '';
  $handler->display->display_options['fields']['field_publication_program_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_publication_program_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_program_1']['empty'] = 'all programs';
  $handler->display->display_options['fields']['field_publication_program_1']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_publication_program_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Program */
  $handler->display->display_options['fields']['field_publication_program']['id'] = 'field_publication_program';
  $handler->display->display_options['fields']['field_publication_program']['table'] = 'field_data_field_publication_program';
  $handler->display->display_options['fields']['field_publication_program']['field'] = 'field_publication_program';
  $handler->display->display_options['fields']['field_publication_program']['label'] = '';
  $handler->display->display_options['fields']['field_publication_program']['element_class'] = 'program-[field_publication_program_1]';
  $handler->display->display_options['fields']['field_publication_program']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_program']['empty'] = 'All Programs';
  $handler->display->display_options['fields']['field_publication_program']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_publication_program']['settings'] = array(
    'view_mode' => 'abbreviation',
    'links' => 1,
  );
  $handler->display->display_options['fields']['field_publication_program']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_publication_program']['separator'] = ' ';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = '';
  $handler->display->display_options['fields']['field_publication_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Publication/Journal */
  $handler->display->display_options['fields']['field_publication_journal']['id'] = 'field_publication_journal';
  $handler->display->display_options['fields']['field_publication_journal']['table'] = 'field_data_field_publication_journal';
  $handler->display->display_options['fields']['field_publication_journal']['field'] = 'field_publication_journal';
  $handler->display->display_options['fields']['field_publication_journal']['label'] = '';
  $handler->display->display_options['fields']['field_publication_journal']['element_type'] = 'em';
  $handler->display->display_options['fields']['field_publication_journal']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_journal']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_publication_journal']['type'] = 'link_title_plain';
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_publication_summary']['id'] = 'field_publication_summary';
  $handler->display->display_options['fields']['field_publication_summary']['table'] = 'field_data_field_publication_summary';
  $handler->display->display_options['fields']['field_publication_summary']['field'] = 'field_publication_summary';
  $handler->display->display_options['fields']['field_publication_summary']['label'] = '';
  $handler->display->display_options['fields']['field_publication_summary']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '<div class="right">
<h2>[title]</h2>
<div class="break">[field_publication_date]</div>
<div class="break"><em>[field_publication_journal]</em></div>
<div class="break">[body]</div>
<b><a href="[path]">[view_node]</a></b>
</div>';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more >';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date (field_publication_date) */
  $handler->display->display_options['sorts']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'news-publications/publications';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Publications';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Publications (Program Page) */
  $handler = $view->new_display('page', 'Publications (Program Page)', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Publications';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'archive';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View Publications Page';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_publication_program_target_id']['id'] = 'field_publication_program_target_id';
  $handler->display->display_options['relationships']['field_publication_program_target_id']['table'] = 'field_data_field_publication_program';
  $handler->display->display_options['relationships']['field_publication_program_target_id']['field'] = 'field_publication_program_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Abbreviated Title */
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['id'] = 'field_programs_abbreviated_title';
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['table'] = 'field_data_field_programs_abbreviated_title';
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['field'] = 'field_programs_abbreviated_title';
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['relationship'] = 'field_publication_program_target_id';
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['label'] = '';
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['alter']['text'] = '<div class="program-tag">[field_programs_abbreviated_title]</div>';
  $handler->display->display_options['fields']['field_programs_abbreviated_title']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = '';
  $handler->display->display_options['fields']['field_publication_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Publication/Journal */
  $handler->display->display_options['fields']['field_publication_journal']['id'] = 'field_publication_journal';
  $handler->display->display_options['fields']['field_publication_journal']['table'] = 'field_data_field_publication_journal';
  $handler->display->display_options['fields']['field_publication_journal']['field'] = 'field_publication_journal';
  $handler->display->display_options['fields']['field_publication_journal']['label'] = '';
  $handler->display->display_options['fields']['field_publication_journal']['element_type'] = 'em';
  $handler->display->display_options['fields']['field_publication_journal']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_journal']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_publication_journal']['type'] = 'link_title_plain';
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_publication_summary']['id'] = 'field_publication_summary';
  $handler->display->display_options['fields']['field_publication_summary']['table'] = 'field_data_field_publication_summary';
  $handler->display->display_options['fields']['field_publication_summary']['field'] = 'field_publication_summary';
  $handler->display->display_options['fields']['field_publication_summary']['label'] = '';
  $handler->display->display_options['fields']['field_publication_summary']['element_label_colon'] = FALSE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '<div class="right">
<h2>[title]</h2>
<div class="break">[field_publication_date]</div>
<div class="break"><i>[field_publication_journal]</i></div>
<div class="break">[body]</div>
<b><a href="[path]">[view_node]</a></b>
</div>';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read More >';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Abbreviated Title for URL (field_abbreviated_title_url) */
  $handler->display->display_options['arguments']['field_abbreviated_title_url_value']['id'] = 'field_abbreviated_title_url_value';
  $handler->display->display_options['arguments']['field_abbreviated_title_url_value']['table'] = 'field_data_field_abbreviated_title_url';
  $handler->display->display_options['arguments']['field_abbreviated_title_url_value']['field'] = 'field_abbreviated_title_url_value';
  $handler->display->display_options['arguments']['field_abbreviated_title_url_value']['relationship'] = 'field_publication_program_target_id';
  $handler->display->display_options['arguments']['field_abbreviated_title_url_value']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_abbreviated_title_url_value']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_abbreviated_title_url_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_abbreviated_title_url_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_abbreviated_title_url_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_abbreviated_title_url_value']['limit'] = '0';
  $handler->display->display_options['path'] = 'programs/%/publications';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Publications';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date (field_publication_date) */
  $handler->display->display_options['sorts']['field_publication_date_value']['id'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['sorts']['field_publication_date_value']['field'] = 'field_publication_date_value';
  $handler->display->display_options['sorts']['field_publication_date_value']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'rss/publications.xml';

  /* Display: Block 3 */
  $handler = $view->new_display('block', 'Block 3', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Program Publications';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_2';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Program (field_publication_program) */
  $handler->display->display_options['arguments']['field_publication_program_target_id']['id'] = 'field_publication_program_target_id';
  $handler->display->display_options['arguments']['field_publication_program_target_id']['table'] = 'field_data_field_publication_program';
  $handler->display->display_options['arguments']['field_publication_program_target_id']['field'] = 'field_publication_program_target_id';
  $handler->display->display_options['arguments']['field_publication_program_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_publication_program_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_publication_program_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_publication_program_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_publication_program_target_id']['summary_options']['items_per_page'] = '25';

  /* Display: Featured News & Publications - Publications */
  $handler = $view->new_display('block', 'Featured News & Publications - Publications', 'featured_news_publications');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'News & Publications';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View Publications Page';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href="/news-publications/publications">View Publications Page </a>
';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Program */
  $handler->display->display_options['fields']['field_publication_program_1']['id'] = 'field_publication_program_1';
  $handler->display->display_options['fields']['field_publication_program_1']['table'] = 'field_data_field_publication_program';
  $handler->display->display_options['fields']['field_publication_program_1']['field'] = 'field_publication_program';
  $handler->display->display_options['fields']['field_publication_program_1']['label'] = '';
  $handler->display->display_options['fields']['field_publication_program_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_publication_program_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_program_1']['empty'] = 'all programs';
  $handler->display->display_options['fields']['field_publication_program_1']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_publication_program_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_class'] = 'left';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'pubres_150x150',
    'image_link' => 'content',
  );
  /* Field: Content: Program */
  $handler->display->display_options['fields']['field_publication_program']['id'] = 'field_publication_program';
  $handler->display->display_options['fields']['field_publication_program']['table'] = 'field_data_field_publication_program';
  $handler->display->display_options['fields']['field_publication_program']['field'] = 'field_publication_program';
  $handler->display->display_options['fields']['field_publication_program']['label'] = '';
  $handler->display->display_options['fields']['field_publication_program']['element_class'] = 'program-[field_publication_program_1]';
  $handler->display->display_options['fields']['field_publication_program']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_program']['empty'] = 'All Programs';
  $handler->display->display_options['fields']['field_publication_program']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_publication_program']['settings'] = array(
    'view_mode' => 'abbreviation',
    'links' => 1,
  );
  $handler->display->display_options['fields']['field_publication_program']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_publication_program']['separator'] = ' ';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_publication_date']['id'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['table'] = 'field_data_field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['field'] = 'field_publication_date';
  $handler->display->display_options['fields']['field_publication_date']['label'] = '';
  $handler->display->display_options['fields']['field_publication_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_date']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_publication_date']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_publication_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Publication/Journal */
  $handler->display->display_options['fields']['field_publication_journal']['id'] = 'field_publication_journal';
  $handler->display->display_options['fields']['field_publication_journal']['table'] = 'field_data_field_publication_journal';
  $handler->display->display_options['fields']['field_publication_journal']['field'] = 'field_publication_journal';
  $handler->display->display_options['fields']['field_publication_journal']['label'] = '';
  $handler->display->display_options['fields']['field_publication_journal']['element_type'] = 'em';
  $handler->display->display_options['fields']['field_publication_journal']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_journal']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_publication_journal']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_publication_journal']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_publication_journal']['type'] = 'link_title_plain';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body_1']['id'] = 'body_1';
  $handler->display->display_options['fields']['body_1']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_1']['field'] = 'body';
  $handler->display->display_options['fields']['body_1']['label'] = '';
  $handler->display->display_options['fields']['body_1']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['body_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body_1']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body_1']['settings'] = array(
    'trim_length' => '300',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
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
    'news' => 'news',
    'publication' => 'publication',
  );
  /* Filter criterion: Content: Feature on Home Page (field_home_page_feature) */
  $handler->display->display_options['filters']['field_home_page_feature_value']['id'] = 'field_home_page_feature_value';
  $handler->display->display_options['filters']['field_home_page_feature_value']['table'] = 'field_data_field_home_page_feature';
  $handler->display->display_options['filters']['field_home_page_feature_value']['field'] = 'field_home_page_feature_value';
  $handler->display->display_options['filters']['field_home_page_feature_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'Featured News & Publications Block';

  /* Display: Featured News & Publications - News */
  $handler = $view->new_display('block', 'Featured News & Publications - News', 'featured_news_publications_news');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'News & Publications';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View Publications Page';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href="/news-publications/publications">View Publications Page </a>';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_class'] = 'left';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'pubres_150x150',
    'image_link' => 'content',
  );
  /* Field: Content: Program */
  $handler->display->display_options['fields']['field_news_program']['id'] = 'field_news_program';
  $handler->display->display_options['fields']['field_news_program']['table'] = 'field_data_field_news_program';
  $handler->display->display_options['fields']['field_news_program']['field'] = 'field_news_program';
  $handler->display->display_options['fields']['field_news_program']['label'] = '';
  $handler->display->display_options['fields']['field_news_program']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_news_program']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_program']['empty'] = 'All Programs';
  $handler->display->display_options['fields']['field_news_program']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_news_program']['settings'] = array(
    'view_mode' => 'abbreviation',
    'links' => 1,
  );
  $handler->display->display_options['fields']['field_news_program']['delta_offset'] = '0';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_news_date']['id'] = 'field_news_date';
  $handler->display->display_options['fields']['field_news_date']['table'] = 'field_data_field_news_date';
  $handler->display->display_options['fields']['field_news_date']['field'] = 'field_news_date';
  $handler->display->display_options['fields']['field_news_date']['label'] = '';
  $handler->display->display_options['fields']['field_news_date']['alter']['text'] = '<div class="views-field views-field-field-image"><div class="field-content left">[field_image]</div></div>
[field_news_program]
[field_news_date]<br />
<div class="views-field views-field-title"><span class="field-content">[title]</span></div>
<div class="views-field views-field-body-1"><div class="field-content">[body_1]</div></div>';
  $handler->display->display_options['fields']['field_news_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_date']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_news_date']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_news_date']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body_1']['id'] = 'body_1';
  $handler->display->display_options['fields']['body_1']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_1']['field'] = 'body';
  $handler->display->display_options['fields']['body_1']['label'] = '';
  $handler->display->display_options['fields']['body_1']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['body_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body_1']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body_1']['settings'] = array(
    'trim_length' => '300',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
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
    'news' => 'news',
    'publication' => 'publication',
  );
  /* Filter criterion: Content: Feature on Home Page (field_home_page_feature) */
  $handler->display->display_options['filters']['field_home_page_feature_value']['id'] = 'field_home_page_feature_value';
  $handler->display->display_options['filters']['field_home_page_feature_value']['table'] = 'field_data_field_home_page_feature';
  $handler->display->display_options['filters']['field_home_page_feature_value']['field'] = 'field_home_page_feature_value';
  $handler->display->display_options['filters']['field_home_page_feature_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'Featured News & Publications Block';
  $export['publications'] = $view;

  return $export;
}
