<?php

/**
 * @file
 * Theme and preprocess functions.
 */

/**
 * Implements template_preprocess_views_data_export_pdf_body().
 */
function template_preprocess_views_data_export_pdf_body(&$vars) {
  module_load_include("inc", "views_data_export", "theme/views_data_export.theme");
  _views_data_export_header_shared_preprocess($vars);
  _views_data_export_body_shared_preprocess($vars);
}

/**
 * Implements hook_process_views_data_export_pdf_body().
 */
function template_process_views_data_export_pdf_body(&$vars) {
  $output = '';

  $already_added_group_titles = (isset($vars['group_titles'])) ? $vars['group_titles'] : array();

  // Construct the tbody of a table, see theme_table().
  $ts = tablesort_init($vars['header']);

  $flip = array(
    'even' => 'odd',
    'odd' => 'even',
  );
  $class = 'even';

  // Add grouping.
  if (!empty($vars['title']) && !in_array($vars['title'], $already_added_group_titles)) {
    $_already_added_groups[] = $vars['title'];
    $cell = array(
      'data' => '<strong> ' . $vars['title'] . '</strong>',
      'colspan' => count($vars['header']),
    );
    $output .= ' <tr>';
    $output .= _theme_table_cell($cell);
    $output .= " </tr>\n";
  }

  foreach ($vars['themed_rows'] as $number => $row) {
    $attributes = array();

    // Check if we're dealing with a simple or complex row.
    if (isset($row['data'])) {
      foreach ($row as $key => $value) {
        if ($key == 'data') {
          $cells = $value;
        }
        else {
          $attributes[$key] = $value;
        }
      }
    }
    else {
      $cells = $row;
    }
    if (count($cells)) {
      // Add odd/even class.
      $class = $flip[$class];
      if (isset($attributes['class'])) {
        $attributes['class'] .= ' ' . $class;
      }
      else {
        $attributes['class'] = $class;
      }

      // Build row.
      $output .= ' <tr' . drupal_attributes($attributes) . '>';
      $i = 0;
      foreach ($cells as $cell) {
        $cell = tablesort_cell($cell, $vars['header'], $ts, $i++);
        $output .= _theme_table_cell($cell);
      }
      $output .= " </tr>\n";
    }
  }

  $vars['tbody'] = preg_replace('/<\/?(a|span) ?.*?>/', '', $output);
}

/**
 * Preprocess views_data_export_pdf_header.
 */
function template_preprocess_views_data_export_pdf_header(&$vars) {
  module_load_include("inc", "views_data_export", "theme/views_data_export.theme");
  _views_data_export_header_shared_preprocess($vars);

  // Need to do a little work to construct the table header, see theme_table().
  $vars['header_row'] = '';
  $vars['header_row'] .= '<thead><tr>';

  $ts = tablesort_init($vars['header']);

  foreach ($vars['header'] as $cell) {
    $cell = tablesort_header($cell, $vars['header'], $ts);
    $vars['header_row'] .= _theme_table_cell($cell, TRUE);
  }

  $vars['header_row'] .= '</tr></thead>';

  $vars['header_row'] = preg_replace('/<\/?(a|span) ?.*?>/', '', $vars['header_row']);
}

/**
 * Preprocess views_data_export_pdf.
 */
function template_preprocess_views_data_export_pdf(&$vars) {
  $vars['header'] = $vars['rows']['header'];
  $vars['body'] = $vars['rows']['body'];
  $vars['footer'] = $vars['rows']['footer'];
}
