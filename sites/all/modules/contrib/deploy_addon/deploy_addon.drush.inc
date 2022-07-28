<?php

/**
 * @file
 * Drush integration for the Deploy Addon module.
 */

/**
 * Implements hook_drush_sql_sync_sanitize().
 */
function deploy_addon_drush_sql_sync_sanitize($source) {
  // Delete variables that contains sensitive data.
  $variables = array(
    'deploy_addon_next_url',
    'deploy_addon_next_user',
    'deploy_addon_next_pass',
  );

  $variables = implode("','", $variables);
  $delete_variables_query = "DELETE FROM variable WHERE name IN ('$variables');";
  drush_sql_register_post_sync_op('deploy_addon_variables',
    dt("Delete Deploy Addon variables that contains sensitive data."),
    $delete_variables_query);
}
