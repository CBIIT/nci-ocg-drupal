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