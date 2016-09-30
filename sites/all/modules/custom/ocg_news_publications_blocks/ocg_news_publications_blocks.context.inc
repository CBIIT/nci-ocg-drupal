<?php
/**
 * @file
 * ocg_news_publications_blocks.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ocg_news_publications_blocks_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ocg_page_front';
  $context->description = 'Context for front page blocks';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-announcement-block' => array(
          'module' => 'views',
          'delta' => 'announcement-block',
          'region' => 'pre_content',
          'weight' => '-10',
        ),
        'views-programs-block_1' => array(
          'module' => 'views',
          'delta' => 'programs-block_1',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-programs-block_3' => array(
          'module' => 'views',
          'delta' => 'programs-block_3',
          'region' => 'content',
          'weight' => '-6',
        ),
        'views-programs-block_2' => array(
          'module' => 'views',
          'delta' => 'programs-block_2',
          'region' => 'content',
          'weight' => '-5',
        ),
        'views-fe78d79853e84f0f15f21f1ffeee8437' => array(
          'module' => 'views',
          'delta' => 'fe78d79853e84f0f15f21f1ffeee8437',
          'region' => 'postscript_first',
          'weight' => '-10',
        ),
        'views-e_newsletter-block_2' => array(
          'module' => 'views',
          'delta' => 'e_newsletter-block_2',
          'region' => 'postscript_first',
          'weight' => '-8',
        ),
        'block-3' => array(
          'module' => 'block',
          'delta' => '3',
          'region' => 'postscript_first',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for front page blocks');
  $export['ocg_page_front'] = $context;

  return $export;
}
