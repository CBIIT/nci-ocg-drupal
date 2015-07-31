<?php
/**
 * @file
 * target_methods.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function target_methods_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'target_methods';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'target_methods' => 'target_methods',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-target_methods-legend' => array(
          'module' => 'views',
          'delta' => 'target_methods-legend',
          'region' => 'sidebar_first',
          'weight' => '50',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['target_methods'] = $context;

  return $export;
}
