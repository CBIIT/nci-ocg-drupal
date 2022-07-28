<?php

/**
 * @file
 * Views include file with views hooks.
 */

/**
 * Implements hook_views_plugins().
 */
function views_data_export_pdf_views_plugins() {
  $path = drupal_get_path('module', 'views_data_export_pdf');

  return array(
    'display' => array(
      'views_data_export_pdf' => array(
        'title' => t('Data export PDF'),
        'help' => t('Export the view results to a file. Can handle very large result sets.'),
        'path' => $path . '/plugins',
        'handler' => 'views_data_export_pdf_plugin_display_export',
        'parent' => 'feed',
        'uses hook menu' => TRUE,
        'use ajax' => FALSE,
        'use pager' => FALSE,
        'accept attachments' => FALSE,
        'admin' => t('Data export pdf'),
        'help topic' => 'display-data-export',
      ),
    ),
    'style' => array(
      'views_data_export_pdf' => array(
        'title' => t('PDF file'),
        'help' => t('Display the view as an pdf file.'),
        'handler' => 'views_data_export_pdf_plugin_style_export',
        'export headers' => array('Content-Type' => 'application/pdf'),
        'export feed type' => 'pdf',
        'export feed text' => 'PDF',
        'export feed file' => '%view.pdf',
        'export feed icon' => drupal_get_path('module', 'views_data_export_pdf') . '/images/pdf.png',
        'additional themes' => array(
          'views_data_export_pdf_header' => 'style',
          'views_data_export_pdf_body' => 'style',
          'views_data_export_pdf_footer' => 'style',
        ),
        'additional themes base' => 'views_data_export_pdf',
        'path' => $path . '/plugins',
        'theme' => 'views_data_export_pdf',
        'parent' => 'views_data_export',
        'theme path' => $path . '/theme',
        'theme file' => 'views_data_export_pdf.theme.inc',
        'uses row plugin' => FALSE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'data_export_pdf',
      )
    ),
  );
}
