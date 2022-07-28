<?php

function view_migration_admin_settings_submit(&$form, $form_state) {
	
	$viewsFilePath = $form_state['values']['path'];
   	//To get all views;
	$viewData = views_get_all_views();
	$custom_views = [];
	
	foreach($viewData as $key=>$value){
		$default_views = array("archive","backlinks","comments_recent","frontpage","glossary","taxonomy_term","tracker");
		if(!in_array($value->name, $default_views)){
			$custom_views[$key] = $value->name;
		}
	}

	//Created array for views one by one;
	foreach($custom_views as $key=>$value) {
		$finalContent = array();
		$viewName=$value;
		
		//To get views data;
		$view = views_get_view($viewName);
		
		$viewContent = array();
		
		$fields = $view->display['default']->display_options['fields'];
		$viewContent['countFields'] = count($fields);
		
		$viewContent['id'] = $view->name;
		$viewContent['human_name'] = $view->human_name;
		$viewContent['description'] = $view->description;
		$viewContent['tag'] = $view->tag;
		$viewContent['base_table'] = $view->base_table;
		$viewContent['base_field'] = $view->base_field;
		$viewContent['core'] = $view->core;
		
		$viewContent['display_default_display_plugin'] = $view->display['default']->display_plugin;
		$viewContent['display_default_id'] = $view->display['default']->id;
		$viewContent['display_default_display_title'] = $view->display['default']->display_title;
		$viewContent['display_default_position'] = $view->display['default']->position;
		
		$viewContent['display_query_type'] = $view->display['default']->display_options['query']['type'];
		$viewContent['display_access_type'] = $view->display['default']->display_options['access']['type'];
		$viewContent['display_access_perm'] = $view->display['default']->display_options['access']['perm'];
		$viewContent['display_cache_type'] = $view->display['default']->display_options['cache']['type'];
		
		$viewContent['display_exposed_form_type'] = $view->display['default']->display_options['exposed_form']['type'];
		
		$viewContent['display_pager_type'] = $view->display['default']->display_options['pager']['type'];
		$viewContent['display_pager_items_per_page'] = $view->display['default']->display_options['pager']['options']['items_per_page'];
		
		$viewContent['display_style_type'] = $view->display['default']->display_options['style_plugin'];
		$viewContent['display_row_type'] = $view->display['default']->display_options['row_plugin'];
		
		$viewContent['display_filters_status_value'] = $view->display['default']->display_options['filters']['status']['value'];
		$viewContent['display_filters_status_table'] = $view->display['default']->display_options['filters']['status']['table'];
		$viewContent['display_filters_status_field'] = $view->display['default']->display_options['filters']['status']['field'];
		$viewContent['display_filters_status_id'] = $view->display['default']->display_options['filters']['status']['id'];
		$viewContent['display_filters_status_group'] = $view->display['default']->display_options['filters']['status']['group'];
		
		if (isset($view->display['default']->display_options['filters']['type']['id'])){
			$viewContent['display_filters_type_id'] = $view->display['default']->display_options['filters']['type']['id'];
		}else {
			$viewContent['display_filters_type_id'] = "";
		}
		
		if (isset($view->display['default']->display_options['filters']['type']['table'])){
			$viewContent['display_filters_type_table'] = $view->display['default']->display_options['filters']['type']['table'];
		}else {
			$viewContent['display_filters_type_table'] = "";
		}
		
		if (isset($view->display['default']->display_options['filters']['type']['field'])){
			$viewContent['display_filters_type_field'] = $view->display['default']->display_options['filters']['type']['field'];
		}else {
			$viewContent['display_filters_type_field'] = "";
		}
		
		
		if (isset($view->display['default']->display_options['filters']['type']['value'])) {
			$contentType = $view->display['default']->display_options['filters']['type']['value'];
			foreach($contentType as $key => $value){
				$viewContent['display_filters_type_value_contentType'] = $value;
			}
		}else {
			$viewContent['display_filters_type_value_contentType'] = "";
		}
		
		$viewContent['display_sorts_created_id'] = $view->display['default']->display_options['sorts']['created']['id'];
		$viewContent['display_sorts_created_table'] = $view->display['default']->display_options['sorts']['created']['table'];
		$viewContent['display_sorts_created_field'] = $view->display['default']->display_options['sorts']['created']['field'];
		$viewContent['display_sorts_created_order'] = $view->display['default']->display_options['sorts']['created']['order'];
		
		if (isset($view->display['default']->display_options['row_options']['build_mode'])) {
				$viewContent['display_row_options_build_mode'] = $view->display['default']->display_options['row_options']['build_mode'];
		} else {
			$viewContent['display_row_options_build_mode'] = "";
		}
		
		if (isset($view->display['page']->display_plugin)) {
			$viewContent['display_page_display_plugin'] = $view->display['page']->display_plugin;
		}else {
			$viewContent['display_page_display_plugin'] = "";
		}
		
		if (isset($view->display['page']->id)) {
			$viewContent['display_page_id'] = $view->display['page']->id;
		}else {
			$viewContent['display_page_id'] = "";
		}
		
		if (isset($view->display['page']->display_title)) {
			$viewContent['display_page_display_title'] = $view->display['page']->display_title;
		}else {
			$viewContent['display_page_display_title'] = "";
		}
		
		if (isset($view->display['page']->position)) {
			$viewContent['display_page_position'] = $view->display['page']->position;
		}else {
			$viewContent['display_page_position'] = "";
		}
		
		if (isset($view->display['page']->display_title)) {
			$viewContent['display_page_display_title'] = $view->display['page']->display_title;
		}else {
			$viewContent['display_page_display_title'] = "";
		}
		
		if (isset($view->display['page']->display_options['path'])) {
			$viewContent['display_page_display_options_path'] = $view->display['page']->display_options['path'];
		}else {
			$viewContent['display_page_display_options_path'] = "";
		}
		
		if (isset($view->display['page']->display_options['field'])) {
			$titleField = $view->display['page']->display_options['field'];
			foreach($titleField as $key => $value){
				$viewContent['display_page_display_options_field'] = $key;
			}
		}else {
			$viewContent['display_page_display_options_field'] = "";
		}
		
		$finalContent[] = $viewContent;
		
		//To get fields data in one array under fields;
		$fields = $view->display['default']->display_options['fields'];
		$finalfieldContent = array();
	
		foreach($fields as $field){
			$fieldContent=array();
			$fieldContent['display_fields_title_id'] = $field['id'];
			$fieldContent['display_fields_title_table'] = $field['table'];
			$fieldContent['display_fields_title_field'] = $field['field'];
			
			if (isset($field['label'])){
				$fieldContent['display_fields_title_label'] = $field['label'];
			}else {
				$fieldContent['display_fields_title_label'] = "";
			}
			
			if (isset($field['exclude'])){
				$fieldContent['display_fields_title_exclude'] = $field['exclude'];
			}else {
				$fieldContent['display_fields_title_exclude'] = "";
			}
			
			$fieldContent['display_fields_title_alter_word_boundary'] = $field['alter']['word_boundary'];
			$fieldContent['display_fields_title_alter_ellipsis'] = $field['alter']['ellipsis'];
			
			if (isset($field['element_label_colon'])){
				$fieldContent['display_fields_title_element_label_colon'] = $field['element_label_colon'];
			}else {
				$fieldContent['display_fields_title_element_label_colon'] = "";
			}
			
			if (isset($field['link_to_node'])){
				$fieldContent['display_fields_title_settings_link_to_entity'] = $field['link_to_node'];
			}else {
				$fieldContent['display_fields_title_settings_link_to_entity'] = "";
			}
			
			if (isset($field['type'])){
				$fieldContent['display_fields_title_type'] = $field['type'];
			}else {
				$fieldContent['display_fields_title_type'] = "";
			}
			
			$finalfieldContent[] = $fieldContent;
		}
		$finalContent['fields'] = $finalfieldContent;
		
		CreateViewParser($finalContent,$viewName,$viewsFilePath);
	}
}


/**
* Parse Drupal 7 view fields and generate a yml file
* containing configuration data.
*/
function CreateViewParser($viewData,$viewName,$viewsFilePath) {
	
	//Created New YML file in Folder;
	//$folder = 'public://views_exports/';
	//file_prepare_directory($folder, FILE_CREATE_DIRECTORY);
	//if ($wrapper = file_stream_wrapper_get_instance_by_uri($folder)) {
	//  $path = $wrapper->realpath();
	//}
	
	$file = $viewsFilePath .'/views.view.'.$viewName.'.yml';
	//$file = drupal_get_path('module', 'custom_view') . '/exports/views.view.'.$viewName.'.yml';
	
	$views = array();
	
	//Variables added for WhiteSpace;
	$fourSpace = "    ";
	$sixSpace = $fourSpace ."  ";
	$eightSpace = $fourSpace ."    ";
	$tenSpace = $eightSpace ."  ";
	$twelveSpace = $eightSpace .$fourSpace;
	
	$views[] = "uuid: " ."" ."\n";
	$views[] = "langcode: " ."en" ."\n";
	$views[] = "status: " ."true" ."\n";
	$views[] = "dependencies:" ."\n" ."  ";
	
	if ($viewData[0]['countFields'] != 1) {
		$views[] = "config:" ."\n" .$fourSpace;
	}
	
	if ($viewData[0]['display_row_options_build_mode'] == 'teaser' || $viewData[0]['display_row_options_build_mode'] == 'full') {
		$views[] = "config:" ."\n" .$fourSpace;
	}
	
	if ($viewData[0]['display_page_display_options_field'] == 'title' && $viewData[0]['display_filters_type_value_contentType'] != '') {
		$views[] = "config:" ."\n" .$fourSpace;
	}
	
	$configfields = $viewData['fields'];
	foreach($configfields as $configfield){
		if($configfield['display_fields_title_id'] != 'title')
			$views[] = "- " ."field.storage.node." .$configfield['display_fields_title_id'] ."\n" .$fourSpace;
	}
	
	if($viewData[0]['display_row_options_build_mode'] == 'teaser') {
		$views[] = "- " ."core.entity_view_mode.node.teaser" ."\n" .$fourSpace;
	}
	
	if($viewData[0]['display_row_options_build_mode'] == 'full') {
		$views[] = "- " ."core.entity_view_mode.node.full" ."\n" .$fourSpace;
	}
		
	if($viewData[0]['display_filters_type_value_contentType'] == null || $viewData[0]['display_filters_type_value_contentType'] == ''){
		$views[] = "\n" ."  ";
	}else{
		$views[] = "- " ."node.type." .$viewData[0]['display_filters_type_value_contentType'] ."\n" ."  ";
	}
	
	$views[] = "module:" ."\n" .$fourSpace;
	$views[] = "- " ."node" ."\n" .$fourSpace;
	if($viewData[0]['display_row_options_build_mode'] != 'teaser' || $viewData[0]['display_row_options_build_mode'] != 'full') {
	    $views[] = "- " ."text" ."\n" .$fourSpace;
	}
	$views[] = "- " ."user" ."\n";
	$views[] = "id: " .$viewData[0]['id'] ."\n";
	$views[] = "label: " ."'" .$viewData[0]['human_name'] ."'" ."\n";
	$views[] = "module: " ."views" ."\n";
	$views[] = "description: " ."'" .$viewData[0]['description'] ."'" ."\n";
	$views[] = "tag: " .$viewData[0]['tag'] ."\n";
	
	if($viewData[0]['base_table'] == 'node'){
		$views[] = "base_table: " .$viewData[0]['base_table'] ."_field_data" ."\n";
	}
	
	$views[] = "base_field: " .$viewData[0]['base_field'] ."\n";
	$views[] = "core: " ."8.x" ."\n";
	$views[] = "display:" ."\n" ."  ";
	$views[] = "default:" ."\n" .$fourSpace;
	$views[] = "display_plugin: " .$viewData[0]['display_default_display_plugin'] ."\n" .$fourSpace;
	$views[] = "id: " .$viewData[0]['display_default_id'] ."\n" .$fourSpace;
	$views[] = "display_title: " .$viewData[0]['display_default_display_title'] ."\n" .$fourSpace;
	$views[] = "position: " .$viewData[0]['display_default_position'] ."\n" .$fourSpace;
	$views[] = "display_options:" ."\n" .$sixSpace;
	$views[] = "access:" ."\n" .$eightSpace;
	$views[] = "type: " .$viewData[0]['display_access_type'] ."\n" .$eightSpace;
	$views[] = "options:" ."\n" .$tenSpace;
	$views[] = "perm: " ."'" .$viewData[0]['display_access_perm'] ."'" ."\n" .$sixSpace;
	$views[] = "cache:" ."\n" .$eightSpace;
	$views[] = "type: " .$viewData[0]['display_cache_type'] ."\n" .$eightSpace;
	$views[] = "options: " ."{  }" ."\n" .$sixSpace;
	$views[] = "query:" ."\n" .$eightSpace;
	$views[] = "type: " .$viewData[0]['display_query_type'] ."\n" .$eightSpace;
	$views[] = "options:" ."\n" .$tenSpace;
	$views[] = "disable_sql_rewrite: " ."false" ."\n" .$tenSpace;
	$views[] = "distinct: " ."false" ."\n" .$tenSpace;
	$views[] = "replica: " ."false" ."\n" .$tenSpace;
	$views[] = "query_comment: " ."''" ."\n" .$tenSpace;
	$views[] = "query_tags: " ."{  }" ."\n" .$sixSpace;
	$views[] = "exposed_form:" ."\n" .$eightSpace;
	$views[] = "type: " .$viewData[0]['display_exposed_form_type'] ."\n" .$eightSpace;
	$views[] = "options:" ."\n" .$tenSpace;
	$views[] = "submit_button: " ."Apply" ."\n" .$tenSpace;
	$views[] = "reset_button: " ."false" ."\n" .$tenSpace;
	$views[] = "reset_button_label: " ."Reset" ."\n" .$tenSpace;
	$views[] = "exposed_sorts_label: " ."'Sort by'" ."\n" .$tenSpace;
	$views[] = "expose_sort_order: " ."true" ."\n" .$tenSpace;
	$views[] = "sort_asc_label: " ."Asc" ."\n" .$tenSpace;
	$views[] = "sort_desc_label: " ."Desc" ."\n" .$sixSpace;
	$views[] = "pager:" ."\n" .$eightSpace;
	$views[] = "type: " .$viewData[0]['display_pager_type'] ."\n" .$eightSpace;
	$views[] = "options:" ."\n" .$tenSpace;
	$views[] = "items_per_page: " .$viewData[0]['display_pager_items_per_page'] ."\n" .$tenSpace;
	$views[] = "offset: " ."0" ."\n" .$tenSpace;
	$views[] = "id: " ."0" ."\n" .$tenSpace;
	$views[] = "total_pages: " ."null" ."\n" .$tenSpace;
	$views[] = "tags:" ."\n" .$twelveSpace;
	$views[] = "previous: " ."‹‹" ."\n" .$twelveSpace;
	$views[] = "next: " ."››" ."\n" .$twelveSpace;
	$views[] = "first: " ."'« First'" ."\n" .$twelveSpace;
	$views[] = "last: " ."'Last »'" ."\n" .$tenSpace;
	$views[] = "expose:" ."\n" .$twelveSpace;
	$views[] = "items_per_page: " ."false" ."\n" .$twelveSpace;
	$views[] = "items_per_page_label: " ."'Items per page'" ."\n" .$twelveSpace;
	$views[] = "items_per_page_options: " ."'5, 10, 25, 50'" ."\n" .$twelveSpace;
	$views[] = "items_per_page_options_all: " ."false" ."\n" .$twelveSpace;
	$views[] = "items_per_page_options_all_label: " ."'- All -'" ."\n" .$twelveSpace;
	$views[] = "offset: " ."false" ."\n" .$twelveSpace;
	$views[] = "offset_label: " ."Offset" ."\n" .$tenSpace;
	$views[] = "quantity: " ."9" ."\n" .$sixSpace;
	$views[] = "style:" ."\n" .$eightSpace;
	$views[] = "type: " .$viewData[0]['display_style_type'] ."\n" .$sixSpace;
	
	$views[] = "row:" ."\n" .$eightSpace;
	if($viewData[0]['display_row_options_build_mode'] == 'teaser' || $viewData[0]['display_row_options_build_mode'] == 'full') {
		$views[] = "type: " ."'entity:node'" ."\n" .$eightSpace;
		$views[] = "options:" ."\n" .$tenSpace;
		$views[] = "view_mode: " .$viewData[0]['display_row_options_build_mode'] ."\n" .$sixSpace;
	}else {
		$views[] = "type: " .$viewData[0]['display_row_type'] ."\n" .$sixSpace;
	}
	
	//Fetching Data for Fields;
	$views[] = "fields:" ."\n" .$eightSpace;
	
	$fieldsData = $viewData['fields'];
	$countFields = count($fieldsData);
		
	//Foreach Loop to fetch all fields Data;
	foreach($fieldsData as $fieldData){
		$views[] = $fieldData['display_fields_title_id'] .":" ."\n" .$tenSpace;
		$views[] = "id: " .$fieldData['display_fields_title_id'] ."\n" .$tenSpace;
			 
		if($fieldData['display_fields_title_table'] == 'node'){
			$views[] = "table: " .$fieldData['display_fields_title_table'] ."_field_data" ."\n" .$tenSpace;
		}else { 
			$views[] = "table: " ."node__" .$fieldData['display_fields_title_id'] ."\n" .$tenSpace;
		}
				
		$views[] = "field: " .$fieldData['display_fields_title_field'] ."\n" .$tenSpace;
		$views[] = "relationship: " ."none" ."\n" .$tenSpace;
		$views[] = "group_type: " ."group" ."\n" .$tenSpace;
		$views[] = "admin_label: " ."''" ."\n" .$tenSpace;
		$views[] = "label: " ."'" .$fieldData['display_fields_title_label'] ."'" ."\n" .$tenSpace;
			 
		if($fieldData['display_fields_title_exclude'] == 1){
			$views[] = "exclude: " ."true" ."\n" .$tenSpace;
		}else{
			$views[] = "exclude: " ."false" ."\n" .$tenSpace;
		}
			 
		$views[] = "alter:" ."\n" .$twelveSpace;
		$views[] = "alter_text: " ."false" ."\n" .$twelveSpace;
		$views[] = "text: " ."''" ."\n" .$twelveSpace;
		$views[] = "make_link: " ."false" ."\n" .$twelveSpace;
		$views[] = "path: " ."''" ."\n" .$twelveSpace;
		$views[] = "absolute: " ."false" ."\n" .$twelveSpace;
		$views[] = "external: " ."false" ."\n" .$twelveSpace;
		$views[] = "replace_spaces: " ."false" ."\n" .$twelveSpace;
		$views[] = "path_case: " ."none" ."\n" .$twelveSpace;
		$views[] = "trim_whitespace: " ."false" ."\n" .$twelveSpace;
		$views[] = "alt: " ."''" ."\n" .$twelveSpace;
		$views[] = "rel: " ."''" ."\n" .$twelveSpace;
		$views[] = "link_class: " ."''" ."\n" .$twelveSpace;
		$views[] = "prefix: " ."''" ."\n" .$twelveSpace;
		$views[] = "suffix: " ."''" ."\n" .$twelveSpace;
		$views[] = "target: " ."''" ."\n" .$twelveSpace;
		$views[] = "nl2br: " ."false" ."\n" .$twelveSpace;
		$views[] = "max_length: " ."0" ."\n" .$twelveSpace;
			 
		if($fieldData['display_fields_title_alter_word_boundary'] == 1)
		{
		    $views[] = "word_boundary: " ."true" ."\n" .$twelveSpace;
		}else{
			$views[] = "word_boundary: " ."false" ."\n" .$twelveSpace;
		}
			 
		if($fieldData['display_fields_title_alter_ellipsis'] == 1){
			$views[] = "ellipsis: " ."true" ."\n" .$twelveSpace;
		}else{
		    $views[] = "ellipsis: " ."false" ."\n" .$twelveSpace;
		}
			 
		$views[] = "more_link: " ."false" ."\n" .$twelveSpace;
		$views[] = "more_link_text: " ."''" ."\n" .$twelveSpace;
		$views[] = "more_link_path: " ."''" ."\n" .$twelveSpace;
		$views[] = "strip_tags: " ."false" ."\n" .$twelveSpace;
		$views[] = "trim: " ."false" ."\n" .$twelveSpace;
		$views[] = "preserve_tags: " ."''" ."\n" .$twelveSpace;
		$views[] = "html: " ."false" ."\n" .$tenSpace;
		$views[] = "element_type: " ."''" ."\n" .$tenSpace;
		$views[] = "element_class: " ."''" ."\n" .$tenSpace;
		$views[] = "element_label_type: " ."''" ."\n" .$tenSpace;
		$views[] = "element_label_class: " ."''" ."\n" .$tenSpace;
			 
		if($fieldData['display_fields_title_element_label_colon'] == 1){
			$views[] = "element_label_colon: " ."true" ."\n" .$tenSpace;
		}else{
			$views[] = "element_label_colon: " ."false" ."\n" .$tenSpace;
		}
			 
		$views[] = "element_wrapper_type: " ."''" ."\n" .$tenSpace;
		$views[] = "element_wrapper_class: " ."''" ."\n" .$tenSpace;
		$views[] = "element_default_classes: " ."true" ."\n" .$tenSpace;
		$views[] = "empty: " ."''" ."\n" .$tenSpace;
		$views[] = "hide_empty: " ."false" ."\n" .$tenSpace;
		$views[] = "empty_zero: " ."false" ."\n" .$tenSpace;
		$views[] = "hide_alter_empty: " ."true" ."\n" .$tenSpace;
		$views[] = "click_sort_column: " ."value" ."\n" .$tenSpace;
		 
		if($fieldData['display_fields_title_id'] == 'title'){
			$views[] = "type: " ."string" ."\n" .$tenSpace;
		}else{
			$views[] = "type: " .$fieldData['display_fields_title_type'] ."\n" .$tenSpace;
		}
			 
		if($fieldData['display_fields_title_id'] == 'title' && $fieldData['display_fields_title_settings_link_to_entity'] == 1){
			$views[] = "settings:" ."\n" .$twelveSpace;
			$views[] = "link_to_entity: " ."true" ."\n" .$tenSpace;
		}else if($fieldData['display_fields_title_id'] == 'title' && $fieldData['display_fields_title_settings_link_to_entity'] == 0){
			$views[] = "settings:" ."\n" .$twelveSpace;
			$views[] = "link_to_entity: " ."false" ."\n" .$tenSpace;
		}else{
			$views[] = "settings: " ."{  }" ."\n" .$tenSpace;
		}
			 
		$views[] = "group_column: " ."value" ."\n" .$tenSpace;
		$views[] = "group_columns: " ."{  }" ."\n" .$tenSpace;
		$views[] = "group_rows: " ."true" ."\n" .$tenSpace;
		$views[] = "delta_limit: " ."0" ."\n" .$tenSpace;
		$views[] = "delta_offset: " ."0" ."\n" .$tenSpace;
		$views[] = "delta_reversed: " ."false" ."\n" .$tenSpace;
		$views[] = "delta_first_last: " ."false" ."\n" .$tenSpace;
		$views[] = "multi_type: " ."separator" ."\n" .$tenSpace;
		$views[] = "separator: " ."', '" ."\n" .$tenSpace;
		$views[] = "field_api_classes: " ."false" ."\n" .$tenSpace;
			 
		if($fieldData['display_fields_title_id'] == 'title'){
			$views[] = "entity_type: " .$fieldData['display_fields_title_table'] ."\n" .$tenSpace;
			$views[] = "entity_field: " .$fieldData['display_fields_title_id'] ."\n" .$tenSpace;
		}
			 
		if($countFields == 1) {
			$views[] = "plugin_id: " ."field" ."\n" .$sixSpace;
		}else{
			$views[] = "plugin_id: " ."field" ."\n" .$eightSpace;
		}
		$countFields--;
 	}
	//Foreach loop Ends for fields;
	
	
	$views[] = "filters:" ."\n" .$eightSpace;
	$views[] = "status:" ."\n" .$tenSpace;
	$views[] = "value: " ."'" .$viewData[0]['display_filters_status_value'] ."'" ."\n" .$tenSpace;
	
	if($viewData[0]['display_filters_status_table'] == 'node'){
		$views[] = "table: " .$viewData[0]['display_filters_status_table'] ."_field_data" ."\n" .$tenSpace;
	}
		
	$views[] = "field: " .$viewData[0]['display_filters_status_field'] ."\n" .$tenSpace;
	$views[] = "plugin_id: " ."boolean" ."\n" .$tenSpace;
	$views[] = "entity_type: " ."node" ."\n" .$tenSpace;
	$views[] = "entity_field: " ."status" ."\n" .$tenSpace;
	$views[] = "id: " .$viewData[0]['display_filters_status_id'] ."\n" .$tenSpace;
	$views[] = "expose:" ."\n" .$twelveSpace;
	$views[] = "operator: " ."''" ."\n" .$tenSpace;
	
	if($viewData[0]['display_filters_type_value_contentType'] == null || $viewData[0]['display_filters_type_value_contentType'] == ''){
		$views[] = "group: " .$viewData[0]['display_filters_status_group'] ."\n" .$sixSpace;
	}else{
		$views[] = "group: " .$viewData[0]['display_filters_status_group'] ."\n" .$eightSpace;
		$views[] = "type:" ."\n" .$tenSpace;
		$views[] = "id: " .$viewData[0]['display_filters_type_id'] ."\n" .$tenSpace;
				
		if($viewData[0]['display_filters_type_table'] == 'node'){
			$views[] = "table: " .$viewData[0]['display_filters_type_table'] ."_field_data" ."\n" .$tenSpace;
		}
					
		$views[] = "field: " .$viewData[0]['display_filters_type_field'] ."\n" .$tenSpace;
		$views[] = "value:" ."\n" .$twelveSpace;
		$views[] = $viewData[0]['display_filters_type_value_contentType'] .": " .$viewData[0]['display_filters_type_value_contentType'] ."\n" .$tenSpace;
		$views[] = "entity_type: " ."node" ."\n" .$tenSpace;
		$views[] = "entity_field: " ."type" ."\n" .$tenSpace;
		$views[] = "plugin_id: " ."bundle" ."\n" .$sixSpace;
	}	
	
	$views[] = "sorts:" ."\n" .$eightSpace;
	$views[] = "created:" ."\n" .$tenSpace;
	$views[] = "id: " .$viewData[0]['display_sorts_created_id'] ."\n" .$tenSpace;
	
	if($viewData[0]['display_sorts_created_table'] == 'node'){
		$views[] = "table: " .$viewData[0]['display_sorts_created_table'] ."_field_data" ."\n" .$tenSpace;
	}
	
	$views[] = "field: " .$viewData[0]['display_sorts_created_field'] ."\n" .$tenSpace;
	$views[] = "order: " .$viewData[0]['display_sorts_created_order'] ."\n" .$tenSpace;
	$views[] = "entity_type: " ."node" ."\n" .$tenSpace;
	$views[] = "entity_field: " ."created" ."\n" .$tenSpace;
	$views[] = "plugin_id: " ."date" ."\n" .$tenSpace;
	$views[] = "relationship: " ."none" ."\n" .$tenSpace;
	$views[] = "group_type: " ."group" ."\n" .$tenSpace;
	$views[] = "admin_label: " ."''" ."\n" .$tenSpace;
	$views[] = "exposed: " ."false" ."\n" .$tenSpace;
	$views[] = "expose:" ."\n" .$twelveSpace;
	$views[] = "label: " ."''" ."\n" .$tenSpace;
	$views[] = "granularity: " ."second" ."\n" .$sixSpace;
	$views[] = "title: " ."'" .$viewData[0]['human_name'] ."'" ."\n" .$sixSpace;
	$views[] = "header: " ."{  }" ."\n" .$sixSpace;
	$views[] = "footer: " ."{  }" ."\n" .$sixSpace;
	$views[] = "empty: " ."{  }" ."\n" .$sixSpace;
	$views[] = "relationships: " ."{  }" ."\n" .$sixSpace;
	$views[] = "arguments: " ."{  }" ."\n" .$sixSpace;
	$views[] = "display_extenders: " ."{  }" ."\n" .$fourSpace;
	$views[] = "cache_metadata:" ."\n" .$sixSpace;
	$views[] = "max-age: " ."-1" ."\n" .$sixSpace;
	$views[] = "contexts:" ."\n" .$eightSpace;
	$views[] = "- " ."'languages:language_content'" ."\n" .$eightSpace;
	$views[] = "- " ."'languages:language_interface'" ."\n" .$eightSpace;
	$views[] = "- " ."url.query_args" ."\n" .$eightSpace;
	$views[] = "- " ."'user.node_grants:view'" ."\n" .$eightSpace;
	$views[] = "- " ."user.permissions" ."\n" .$sixSpace;
	
	if($viewData[0]['display_row_options_build_mode'] == 'teaser' || $viewData[0]['display_row_options_build_mode'] == 'full' || $viewData[0]['countFields'] == 1) {
	    $views[] = "tags: " ."{  }"."\n" ."  ";
	}else {
		$views[] = "tags:" ."\n" .$eightSpace;
	}
	
	$displayTagfields = $viewData['fields'];
	$countFields = count($displayTagfields);
	
	foreach($displayTagfields as $displayTagfield){
		if($displayTagfield['display_fields_title_id'] != 'title')
			if($countFields == 1){
				$views[] = "- " ."'config:field.storage.node." .$displayTagfield['display_fields_title_id'] ."'" ."\n" ."  ";
			}else{
				$views[] = "- " ."'config:field.storage.node." .$displayTagfield['display_fields_title_id'] ."'" ."\n" .$eightSpace;
			}
		$countFields--;
	}
		
	$views[] = $viewData[0]['display_page_id'] .":" ."\n" .$fourSpace;
	$views[] = "display_plugin: " .$viewData[0]['display_page_display_plugin'] ."\n" .$fourSpace;
	$views[] = "id: " .$viewData[0]['display_page_id'] ."\n" .$fourSpace;
	$views[] = "display_title: " .$viewData[0]['display_page_display_title'] ."\n" .$fourSpace;
	$views[] = "position: " .$viewData[0]['display_page_position'] ."\n" .$fourSpace;
	$views[] = "display_options:" ."\n" .$sixSpace;
	$views[] = "display_extenders: " ."{  }" ."\n" .$sixSpace;
	$views[] = "path: " .$viewData[0]['display_page_display_options_path'] ."\n" .$fourSpace;
	$views[] = "cache_metadata:" ."\n" .$sixSpace;
	$views[] = "max-age: " ."-1" ."\n" .$sixSpace;
	$views[] = "contexts:" ."\n" .$eightSpace;
	$views[] = "- " ."'languages:language_content'" ."\n" .$eightSpace;
	$views[] = "- " ."'languages:language_interface'" ."\n" .$eightSpace;
	$views[] = "- " ."url.query_args" ."\n" .$eightSpace;
	$views[] = "- " ."'user.node_grants:view'" ."\n" .$eightSpace;
	$views[] = "- " ."user.permissions" ."\n" .$sixSpace;
	
	if($viewData[0]['display_row_options_build_mode'] == 'teaser' || $viewData[0]['display_row_options_build_mode'] == 'full' || $viewData[0]['countFields'] == 1) {
	    $views[] = "tags: " ."{  }";
	}else {
		$views[] = "tags:" ."\n" .$eightSpace;
	}
	
	$tagfields = $viewData['fields'];
		foreach($tagfields as $tagfield){
			if($tagfield['display_fields_title_id'] != 'title')
				$views[] = "- " ."'config:field.storage.node." .$tagfield['display_fields_title_id'] ."'" ."\n" .$eightSpace;
		}
 	
	if(file_put_contents($file, $views)) {
		echo 'File Created Successfully' ."\n";
	} else {
		echo 'Failed to Create File';
	}
}