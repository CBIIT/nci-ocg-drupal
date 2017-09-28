<?php

// Add some cool text to the search block form
function new_ocg_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'search_block_form') {
    // HTML5 placeholder attribute
    $form['search_block_form']['#attributes']['placeholder'] = t('');
  }
}

/* - Decided not to use for now 
  function new_ocg_preprocess_node(&$variables) {
  $node = $variables['node'];

  // Only add the revision information if the node is configured to display
  if ($variables['display_submitted'] && ($node->revision_uid != $node->uid || $node->revision_timestamp != $node->created)) {
  // Append the revision information to the submitted by text.
  $revision_account = user_load($node->revision_uid);
  $variables['revision_name'] = theme('username', array('account' => $revision_account));
  $variables['revision_date'] = format_date($node->changed);
  $variables['submitted'] = t(' Last Updated: !revision-date', array(
  '!revision-date' => $variables['revision_date']));
  // use !revision-name if name is needed
  }
  }
 */

/**
 * Return a themed breadcrumb trail.
 *
 * @param $variables
 *   - title: An optional string to be used as a navigational heading to give
 *     context for breadcrumb links to screen-reader users.
 *   - title_attributes_array: Array of HTML attributes for the title. It is
 *     flattened into a string within the theme function.
 *   - breadcrumb: An array containing the breadcrumb links.
 * @return
 *   A string containing the breadcrumb output.
 */
function new_ocg_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];
  $output = '';

  // Determine if we are to display the breadcrumb.
  $show_breadcrumb = theme_get_setting('zen_breadcrumb');
  if ($show_breadcrumb == 'yes' || $show_breadcrumb == 'admin' && arg(0) == 'admin') {

    // Optionally get rid of the homepage link.
    $show_breadcrumb_home = theme_get_setting('zen_breadcrumb_home');
    if (!$show_breadcrumb_home) {
      array_shift($breadcrumb);
    }

    // Return the breadcrumb with separators.
    if (!empty($breadcrumb)) {
      $breadcrumb_separator = theme_get_setting('zen_breadcrumb_separator');
      $trailing_separator = $title = '';
      if (theme_get_setting('zen_breadcrumb_title')) {
        $item = menu_get_item();
        if (!empty($item['tab_parent'])) {
          // If we are on a non-default tab, use the tab's title.
          if (($item['tab_parent'] != 'search/node') && ($item['tab_parent'] != 'search')) {
            $breadcrumb[] = check_plain($item['title']);
          }
        } else {
          //Check if node type is Program
          if (arg(0) == 'node' && is_numeric(arg(1))) {
            $node = node_load(arg(1));

            if ($node->type == 'programs') {
              $modtitle = $node->field_programs_abbreviated_title['und'][0]['safe_value'];
            } else {
              $title = drupal_get_title();
              if (strlen($title) > 50) {
                $title = drupal_substr($title, 0, 50) . "...";
              }

              $modtitle = $title;
            }
          } else {
            $modtitle = drupal_get_title();
          }
          $breadcrumb[] = $modtitle;
        }
      } elseif (theme_get_setting('zen_breadcrumb_trailing')) {
        $trailing_separator = $breadcrumb_separator;
      }

      // Provide a navigational heading to give context for breadcrumb links to
      // screen-reader users.
      if (empty($variables['title'])) {
        $variables['title'] = t('You are here');
      }
      // Unless overridden by a preprocess function, make the heading invisible.
      if (!isset($variables['title_attributes_array']['class'])) {
        $variables['title_attributes_array']['class'][] = 'element-invisible';
      }

      // Build the breadcrumb trail.
      $output = '<nav class="breadcrumb" role="navigation">';
      $output .= '<h2' . drupal_attributes($variables['title_attributes_array']) . '>' . $variables['title'] . '</h2>';
      $output .= '<ol><li>' . implode($breadcrumb_separator . '</li><li>', $breadcrumb) . $trailing_separator . '</li></ol>';
      $output .= '</nav>';
    }
  }

  return $output;
}

/**
 * Override or insert variables into the page template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
function new_ocg_preprocess_page(&$variables, $hook) {

  global $base_url;
  drupal_theme_initialize();
  $variables['new_logo'] = theme_get_setting('logo_path');
  
  if (($views_page = views_get_page_view()) && $views_page->name === "cgci_data_matrix" && $views_page->current_display === "primary_disease") {
    $variables['theme_hook_suggestions'][] = 'page__views__cgci';
  }
  if (($views_page = views_get_page_view()) && $views_page->name === "cgci_data_matrix" && $views_page->current_display === "target_primary_disease") {
    $variables['theme_hook_suggestions'][] = 'page__views__target';
  }
  if (($views_page = views_get_page_view()) && $views_page->name === "ctd2_data_portal" && $views_page->current_display === "portal") {
    $variables['theme_hook_suggestions'][] = 'page__views__ctd2';
  }
  if (($views_page = views_get_page_view()) && $views_page->name === "ctd2_data_portal" && $views_page->current_display === "accordion") {
    $variables['theme_hook_suggestions'][] = 'page__views__ctd2';
  }
  if (($views_page = views_get_page_view()) && $views_page->name === "ctd2_data_portal" && $views_page->current_display === "accordion1") {
    $variables['theme_hook_suggestions'][] = 'page__views__ctd2';
  }
  if (($views_page = views_get_page_view()) && $views_page->name === "ctd2_data_portal" && $views_page->current_display === "internal_portal") {
    $variables['theme_hook_suggestions'][] = 'page__views__ctd2_network';
  }
  if (($views_page = views_get_page_view()) && $views_page->name === "homepage" && $views_page->current_display === "homepage_mission") {
    $variables['theme_hook_suggestions'][] = 'page__homepage';
  }
}

function new_ocg_preprocess_node(&$variables) {
  if ($variables['type'] == 'publication') {
    $auth_journal = '';
    if (!empty($variables['field_publication_authors'])) {
      $auth_journal .= $variables['field_publication_authors'][0]['value'] . '<br />';
    }

    if (!empty($variables['field_publication_journal'])) {
      $auth_journal .= '<p><em>' . $variables['field_publication_journal'][0]['title'] . '</em></p>';
    }

    $variables['author_journal'] = $auth_journal;
  } elseif ($variables['type'] == 'target_methods') {
    drupal_add_js(drupal_get_path('theme', 'new_ocg') . '/js/target_methods.js');
  }
}

/**
 * VSCC icons
 */
function new_ocg_vscc_element_black_icons($vars) {
  $image_vars = array(
      'path' => drupal_get_path('theme', 'new_ocg') . '/images/vscc/' . $vars['element'] . '.png',
      'alt' => t($vars['element']),
      'title' => t($vars['element']),
  );
  return theme('image', $image_vars);
}

function new_ocg_preprocess_views_view(&$variables) {
  if ($variables['view']->name == 'analytical_tools') {
    if ($variables['view']->current_display == 'page' && $variables['view']->filter['field_type_of_analytic_tool_target_id']->value[0] == 86) {
      $variables['footer'] = '';
    }
  }
}

/**
 * Function for adding rowspan classes for CTD2 Data Portal
 */

function ctd2_row_classes($item_id, $nid, $field) {
  try {
    $class = '';
    $field_collection = entity_metadata_wrapper('field_collection_item', $item_id);
    if (!empty($field_collection->$field->value()) && !empty($field_collection->$field[0]->field_span_rows->value())) {
      $node = node_load($nid);
      $row_ids = field_get_items('node', $node, 'field_row');
      $row_classes = array_slice($row_ids, $field_collection->field_row_number->value(), $field_collection->$field[0]->field_span_rows->value());
      foreach($row_classes as $row_class) {
        $class = $class . ' ' . $row_class['value'] . '_rh';
      }
    
      return $class;
    }
  
  }
  catch (EntityMetadataWrapperException $exc) {
    watchdog(
      'CTD2 Data Portal',
      'EntityMetadataWrapper exception in %function() @trace',
      array('%function' => __FUNCTION__, '@trace' => $exc->getTraceAsString()),
      WATCHDOG_ERROR
    );
  }
}

function ctd2_pi_row_classes($item_id, $nid, $field) {
  try {
    $class = '';
    $field_collection = entity_metadata_wrapper('field_collection_item', $item_id);
    if (!empty($field_collection->$field->value())) {
      $node = node_load($nid);
      $row_ids = field_get_items('node', $node, 'field_row');
      $row_classes = array_slice($row_ids, $field_collection->field_row_number->value(), count($row_ids));
      foreach($row_classes as $row_class) {
        $class = $class . ' ' . $row_class['value'] . '_rh';
      }
    
      return $class;
    }
  
  }
  catch (EntityMetadataWrapperException $exc) {
    watchdog(
      'CTD2 Data Portal',
      'EntityMetadataWrapper exception in %function() @trace',
      array('%function' => __FUNCTION__, '@trace' => $exc->getTraceAsString()),
      WATCHDOG_ERROR
    );
  }
}

function ctd2_row_count($nid) {
    $node = node_load($nid);
    $rows = field_get_items('node', $node, 'field_row');
    $count = 0;
    foreach($rows as $row) {
      $fc_item = field_collection_item_load($row['value']);
      $internal = $fc_item->field_internal[LANGUAGE_NONE][0]['value'];
      if($internal == 0){
        $count++;
      }
    }
    
    return $count;
}

function ctd2_ea_row_count($nid) {
    $node = node_load($nid);
    $rows = field_get_items('node', $node, 'field_row');
    $count = 0;
    foreach($rows as $row) {
      $fc_item = field_collection_item_load($row['value']);
      $internal = $fc_item->field_internal[LANGUAGE_NONE][0]['value'];
      if($internal == 0) {
        if(!empty($fc_item->field_experimental_approaches)){
          $count++;
        }
      }
    }
    
    return $count;
}

function ctd2_row_count_internal($nid) {
    $node = node_load($nid);
    $rows = field_get_items('node', $node, 'field_row');
    $count = 0;
    foreach($rows as $row) {
      $fc_item = field_collection_item_load($row['value']);
      $internal = $fc_item->field_internal[LANGUAGE_NONE][0]['value'];
      if($internal == 1){
        $count++;
      }
    }
    
    return $count;
}

function ctd2_ea_row_count_internal($nid) {
    $node = node_load($nid);
    $rows = field_get_items('node', $node, 'field_row');
    $count = 0;
    foreach($rows as $row) {
      $fc_item = field_collection_item_load($row['value']);
      $internal = $fc_item->field_internal[LANGUAGE_NONE][0]['value'];
      if($internal == 1) {
        if(!empty($fc_item->field_experimental_approaches)){
          $count++;
        }
      }
    }
    
    return $count;
}

function ctd2_pi_row_count_internal($nid, $fc_id) {
    $rows = views_get_view_result('ctd2_data_portal', 'internal_project_title', $nid);
    $row_ids = array();
    foreach($rows as $row) {
      $fc_item = field_collection_item_load($row->field_collection_item_field_data_field_row_item_id);
      $internal = $fc_item->field_internal[LANGUAGE_NONE][0]['value'];
      if($internal == 1) {
        $row_ids[] = $fc_item->item_id;
        }
      }
    $position = array_search($fc_id, $row_ids) + 1;
    $new_array = array_slice($row_ids, $position);
    $row_span = 1;
    foreach ($new_array as $array_element) {
      $pi_item = field_collection_item_load($array_element);
      if (!empty($pi_item->field_principal_investigator)) {
        break;
      }
      $row_span++;
      
    }
    return $row_span;
}

function embed_cgci_view($viewname, $display, $filter, $view_label) {

  $embed = views_embed_view($viewname, $display, $filter);
  
  $output = '<div class="views-field views-field-view">
              <span class="views-label views-label-view">' . $view_label. ': </span>
              <span class="field-content">' . 
                $embed . 
              '</span>
            </div>';  
      
  return $output;      
}

function embed_target_view($viewname, $display, $filter) {

  $embed = views_embed_view($viewname, $display, $filter);
  
  return $embed;      
}