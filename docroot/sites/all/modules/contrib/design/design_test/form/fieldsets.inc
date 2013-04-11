<?php

/**
 * @file
 * Fieldset design test.
 */

/**
 * Fieldsets.
 */
function design_test_form_fieldsets($form, &$form_state) {
  $form['collapsible'] = array(
    '#type' => 'fieldset',
    '#title' => t('Collapsible fieldset'),
    '#description' => t('Fieldset description'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['collapsed'] = array(
    '#type' => 'fieldset',
    '#title' => t('Collapsed fieldset'),
    '#description' => t('Fieldset description'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['collapsed']['textfield'] = array(
    '#type' => 'textfield',
    '#title' => t('Textfield'),
    '#default_value' => '',
    '#description' => t('Textfield description'),
    '#required' => TRUE,
  );
  $form['collapsed']['textarea'] = array(
    '#type' => 'textarea',
    '#title' => t('Textarea'),
    '#default_value' => '',
    '#description' => t('Textarea description'),
    '#required' => TRUE,
  );

  $form['collapsed2'] = array(
    '#type' => 'fieldset',
    '#title' => t('Fieldset'),
    '#description' => t('Fieldset description'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['collapsed2']['collapsible'] = array(
    '#type' => 'fieldset',
    '#title' => t('Collapsible fieldset'),
    '#description' => t('Fieldset description'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['collapsed2']['collapsed'] = array(
    '#type' => 'fieldset',
    '#title' => t('Collapsed fieldset'),
    '#description' => t('Fieldset description'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['collapsed2']['regular'] = array(
    '#type' => 'fieldset',
    '#title' => t('Fieldset'),
    '#description' => t('Fieldset description'),
    '#collapsible' => FALSE,
  );

  $form['regular'] = array(
    '#type' => 'fieldset',
    '#title' => t('Fieldset'),
    '#description' => t('Fieldset description'),
    '#collapsible' => FALSE,
  );

  #$form['#attributes'] = array('class' => array('search-form'));
  $form['basic'] = array(
    '#type' => 'fieldset',
    '#title' => t('Filter aliases'),
    '#attributes' => array('class' => array('container-inline')),
  );
  $form['basic']['filter'] = array(
    '#type' => 'textfield',
    '#title' => '',
    '#default_value' => '',
    '#maxlength' => 128,
    '#size' => 25,
  );
  $form['basic']['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
  );
  $form['basic']['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Filter'),
    '#submit' => array('path_admin_filter_form_submit_filter'),
  );
  $form['basic']['actions']['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset'),
    '#submit' => array('path_admin_filter_form_submit_reset'),
  );

  // Vertical tabs.
  // Replicate the entire form; some more black magic.
  $subform = array_diff_key($form, array('group' => 0, 'tabs' => 0));

  $form['group'] = array(
    '#type' => 'vertical_tabs',
  );
  $form['tabs'][0] = array(
    '#type' => 'fieldset',
    '#title' => 'Vertical tab 1',
    '#description' => 'Description',
    '#group' => 'group',
  );
  $form['tabs'][0] += $subform;

  $form['tabs'][1] = array(
    '#type' => 'fieldset',
    '#title' => 'Vertical tab 2',
    '#description' => '<p>Description</p><p>Description</p>',
    '#group' => 'group',
  );
  $form['tabs'][1] += $subform;

  // In case you didn't know, vertical tabs are supported recursively.
  $form['tabs'][0]['subgroup'] = array(
    '#type' => 'vertical_tabs',
  );

  $form['subtabs'][0] = array(
    '#type' => 'fieldset',
    '#title' => 'Vertical tab 1',
    '#description' => 'Description',
    '#group' => 'subgroup',
  );
  $form['subtabs'][0] += $subform;

  $form['subtabs'][1] = array(
    '#type' => 'fieldset',
    '#title' => 'Vertical tab 2',
    '#description' => '<p>Description</p><p>Description</p>',
    '#group' => 'subgroup',
  );
  $form['subtabs'][1] += $subform;

  return $form;
}

