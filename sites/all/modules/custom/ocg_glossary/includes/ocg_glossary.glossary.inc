<?php
/**
 * Implementation of hook_ckeditor_link_TYPE_autocomplete().
 */
function ocg_glossary_ckeditor_link_glossary_autocomplete($string, $limit) {
  $matches = array();
  
  $vocabularies = array_keys(array_filter(variable_get('ckeditor_link_autocomplete_glossary', array())));
  
  if (count($vocabularies)) {
    $query = db_select('taxonomy_term_data', 't')
      ->fields('t', array('tid', 'name'))
      ->condition('t.name', '%'. db_like($string) .'%', 'LIKE')
      ->orderBy('t.name')
      ->range(0, $limit)
      ->addTag('term_access');
    if (!in_array('- any -', $vocabularies)) {
      $query->condition('t.vid', $vocabularies, 'IN');
    }
    $result = $query->execute();
    module_load_include('inc','pathauto','pathauto');
    foreach ($result as $term) {
      $term_string = pathauto_cleanstring($term->name);
      $matches['about-ocg/glossary/#'. $term_string] = $term->name;
    }
  }
  return $matches;
}

/**
 * Implementation of hook_ckeditor_link_TYPE_revert().
 */
function ocg_glossary_ckeditor_link_glossary_revert($path, &$langcode) {
  if (function_exists('ckeditor_link_ckeditor_link_i18n_taxonomy_revert')
   || !preg_match('`^about-ocg/glossary/(\d+)(/[\w/_+,-]+)?(\?[\w &=+_,;-]+)?(#[\w_-]+)?$`', $path, $matches)) {
    return;
  }
  $tid = $matches[1];
  $name = db_select('taxonomy_term_data', 't')
    ->fields('t', array('name'))
    ->condition('t.tid', $tid)
    ->addTag('term_access')
    ->execute()
    ->fetchField();
  return ($name) ? $name : FALSE;
}

/**
 * Implementation of hook_ckeditor_link_TYPE_url().
 */
function ocg_glossary_ckeditor_link_glossary_url($path, $langcode) {
  if (!preg_match('`^about-ocg/glossary/(\d+)(/[\w/_+,-]+)?(\?[\w &=+_,;-]+)?(#[\w_-]+)?$`', $path, $matches)) {
    return;
  }
  module_load_include('inc','pathauto','pathauto');
  //$new_topic = pathauto_cleanstring($term->name_field[$language][0]['safe_value']);
  $tid = $matches[1];

  $languages = ckeditor_link_get_languages();
  
  if ($languages) {
    $term = taxonomy_term_load($tid);
    if ($term && ($language = @$term->language) && ($language != LANGUAGE_NONE) && isset($languages[$language])) {
      $langcode = $language;
    }
  }
  dpm(get_defined_vars());
  return ckeditor_link_url("about-ocg/glossary", $langcode);
}

/**
 * Implementation of hook_ckeditor_link_TYPE_settings().
 */
function ocg_glossary_ckeditor_link_glossary_settings() {
  $form['glossary'] = array(
    '#type' => 'fieldset',
    '#title' => t('Glossary'),
  );

  $vocabularies = taxonomy_get_vocabularies();
  $options = array('- any -' => t('<em>Any vocabulary</em>'));
  foreach ($vocabularies as $vid => $vocabulary) {
    $options[$vid] = check_plain($vocabulary->name);
  }
  $form['glossary']['ckeditor_link_autocomplete_glossary'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Vocabularies'),
    '#options' => $options,
    '#default_value' => variable_get('ckeditor_link_autocomplete_glossary', array()),
    '#description' => t('Select the vocabularies to be available as autocomplete suggestions.'),
  );

  return $form;
}
