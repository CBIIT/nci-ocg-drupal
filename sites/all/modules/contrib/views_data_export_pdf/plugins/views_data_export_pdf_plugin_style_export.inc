<?php

/**
 * @file
 * PDF style plugin.
 */
class views_data_export_pdf_plugin_style_export extends views_data_export_plugin_style_export {

  /**
   * Set options fields and default values.
   *
   * @return
   * An array of options information.
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['landscape'] = array(
      'default' => FALSE,
      'translatable' => FALSE,
    );

    $options['user_style_sheet'] = array(
      'default' => "",
      'translatable' => FALSE,
    );
    return $options;
  }

  /**
   * Options form mini callback.
   *
   * @param $form
   * Form array to add additional fields to.
   * @param $form_state
   * State of the form.
   * @return
   * None.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['landscape'] = array(
      '#type' => 'checkbox',
      '#title' => t('Landscape'),
      '#default_value' => $this->options['landscape'],
      '#description' => t('PDF Landscape format.'),
    );
    $form['user_style_sheet'] = array(
      '#type' => 'textfield',
      '#title' => t('User style sheet path'),
      '#default_value' => $this->options['user_style_sheet'],
      '#description' => t('Add user style sheet from path. Example sites/default/files/pdf_style.css'),
    );

  }

  function render_header() {
    $rows = array();
    $title = '';
    $output = '';
    $head = '';

    $is_style_sheet = (isset($this->options['user_style_sheet'])) ? $this->options['user_style_sheet'] : "";
    if (!empty($is_style_sheet)) {
      $path = ltrim($is_style_sheet, "/");
      if (!empty($path) && file_exists($path)) {
        $styles = array(
          '#type' => 'styles',
          '#items' => array(
            $path => array(
              'type' => 'file',
              'group' => CSS_DEFAULT,
              'weight' => 0,
              'every_page' => FALSE,
              'media' => 'all',
              'preprocess' => FALSE,
              'data' => $path,
              'browsers' => array(
                'IE' => TRUE,
                '!IE' => TRUE,
              ),
            )
          ),
        );
        $head = drupal_render($styles);
      }
      else {
        watchdog("views_data_export_pdf", "File not found :path", array(":path" => $is_style_sheet));
      }
    }

    $output .= theme($this->theme_functions($this->definition['additional themes base'] . '_header'), array(
      'view' => $this->view,
      'options' => $this->options,
      'rows' => $rows,
      'title' => $title,
      'head' => $head
    ));
    return $output;
  }

  function render_body(&$batch_sandbox = NULL) {
    if ($this->uses_row_plugin() && empty($this->row_plugin)) {
      vpr('views_plugin_style_default: Missing row plugin');
      return;
    }

    // Group the rows according to the grouping field, if specified.
    $sets = $this->render_grouping($this->view->result, $this->options['grouping']);

    // Render each group separately and concatenate.  Plugins may override this
    // method if they wish some other way of handling grouping.
    $output = '';

    if (!isset($batch_sandbox['group_titles'])) {
      $batch_sandbox['group_titles'] = array();
    }

    $group_titles = (isset($batch_sandbox['group_titles'])) ? $batch_sandbox['group_titles'] : array();

    foreach ($sets as $title => $records) {
      if ($this->uses_row_plugin()) {
        $rows = array();
        foreach ($records as $row_index => $row) {
          $this->view->row_index = $row_index;
          $rows[] = $this->row_plugin->render($row);
        }
      }
      else {
        $rows = $records;
      }

      $output .= theme($this->theme_functions($this->definition['additional themes base'] . '_body'), array(
        'view' => $this->view,
        'options' => $this->options,
        'rows' => $rows,
        'title' => $title,
        'group_titles' => $group_titles
      ));

      if (!in_array($title, $batch_sandbox['group_titles'])) {
        $batch_sandbox['group_titles'][] = $title;
      }

    }
    unset($this->view->row_index);
    return $output;

  }
}
