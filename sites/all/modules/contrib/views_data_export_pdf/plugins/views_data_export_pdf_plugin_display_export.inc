<?php

/**
 * @file
 * Contains the bulk export display plugin.
 *
 * This allows views to be rendered in parts by batch API.
 */

/**
 * The plugin that batches its rendering.
 *
 * We are based on a feed display for compatibility.
 *
 * @ingroup views_display_plugins
 */
class views_data_export_pdf_plugin_display_export extends views_data_export_plugin_display_export {

  /**
   * Generate pdf file.
   */
  public function generate_pdf($html, $filename = NULL) {
    if (($library = libraries_load('phpwkhtmltopdf')) && !empty($library['loaded'])) {
      try {
        $options = array('binary' => variable_get('views_data_export_pdf_wkhtmltopdf', '/usr/local/bin/wkhtmltopdf'));

        $is_landscape = (isset($this->options['style_options']['landscape']) && $this->options['style_options']['landscape']) ? TRUE : FALSE;
        if ($is_landscape) {
          $options['orientation'] = 'landscape';
        }

        $pdf = new WkHtmlToPdf($options);

        $pdf->addPage($html);
        if (!empty($filename)) {
          if ($pdf->saveAs($filename)) {
            return TRUE;
          }
          else {
            watchdog("views_data_export_pdf", $pdf->getError());
            return FALSE;
          }
        }
        else {
          ob_start();
          if ($pdf->send('php://output')) {
            $this->add_http_headers();
            return ob_get_clean();
          }
          else {
            watchdog("views_data_export_pdf", $pdf->getError());
            return $pdf->getError();
          }
        }

      }
      catch (Exception $exception) {
        watchdog("views_data_export_pdf", $exception->getMessage());
        return $exception->getMessage();
      }
    }
    else {
      watchdog("views_data_export_pdf", $library['error message']);
      return $library['error message'];
    }

    return $html;
  }

  /**
   * Render the display.
   *
   * We basically just work out if we should be rendering the header, body or
   * footer and call the appropriate functions on the style plugins.
   */
  function render() {
    if (!$this->is_batched()) {
      $result = $this->view->style_plugin->render($this->view->result);

      if (empty($this->view->live_preview) && isset($this->options['style_options']['provide_file']) && $this->options['style_options']['provide_file']) {
        $result = $this->generate_pdf($result);
      }

      return $result;
    }

    $this->view->build();

    switch ($this->batched_execution_state->batch_state) {
      case VIEWS_DATA_EXPORT_BODY:
        $output = $this->view->style_plugin->render_body($this->batched_execution_state->sandbox);
        break;
      case VIEWS_DATA_EXPORT_HEADER:
        $output = $this->view->style_plugin->render_header();
        break;
      case VIEWS_DATA_EXPORT_FOOTER:
        $output = $this->view->style_plugin->render_footer();
        break;
    }

    return $output;
  }

  /**
   * Transfer the output file to the client.
   */
  function transfer_file() {
    // Generate PDF instead of html file.
    if (empty($this->view->live_preview) && isset($this->options['style_options']['provide_file']) && $this->options['style_options']['provide_file']) {
      $output_file = $this->outputfile_path();
      $html = file_get_contents($output_file);
      if (!empty($html)) {
        $pdf_result = $this->generate_pdf($html, $output_file);
        if ($pdf_result && $file = $this->outputfile_entity()) {
          $file->filesize = filesize($file->uri);
          $file->filemime = file_get_mimetype($file->uri);
          file_save($file);
          $this->_output_file = $file;
        }
      }
    }

    // Build the view so we can set the headers.
    $this->view->build();
    // Arguments can cause the style to not get built.
    if (!$this->view->init_style()) {
      $this->view->build_info['fail'] = TRUE;
    }
    // Set the headers.
    if (empty($this->view->live_preview) && isset($this->options['style_options']['provide_file']) && $this->options['style_options']['provide_file']) {
      $this->add_http_headers();
    }
    $headers = array(
      'Content-Length' => $this->outputfile_entity()->filesize,
    );

    file_transfer($this->outputfile_path(), $headers);
  }


  /**
   * Define the option for this view.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['use_batch'] = array('default' => 'no_batch');
    $options['items_per_page'] = array('default' => '0');
    $options['return_path'] = array('default' => '');
    $options['style_plugin']['default'] = 'views_data_export_pdf';

    // This is the default size of a segment when doing a batched export.
    $options['segment_size']['default'] = 100;

    if (isset($options['defaults']['default']['items_per_page'])) {
      $options['defaults']['default']['items_per_page'] = FALSE;
    }

    return $options;
  }

  function get_style_type() {
    return 'data_export_pdf';
  }

}
