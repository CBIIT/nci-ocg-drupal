<?php

/**
 * @file
 * Views_data_export_pdf admin form.
 */

/**
 * Implements form callback.
 */
function views_data_export_pdf_settings_form() {
  $form = array();
  $form['views_data_export_pdf_wkhtmltopdf'] = array(
    '#type' => 'textfield',
    '#title' => t('WkhtmlToPdf Location'),
    '#description' => t('Set this to the system path where WkhtmlToPdf is located.'),
    '#default_value' => variable_get('views_data_export_pdf_wkhtmltopdf', '/usr/local/bin/wkhtmltopdf'),
  );
  return system_settings_form($form);
}
