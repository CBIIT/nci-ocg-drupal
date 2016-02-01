<?php
/**
 * @file
 * ocg_data_matrix.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ocg_data_matrix_user_default_roles() {
  $roles = array();

  // Exported role: Data Matrix Editor.
  $roles['Data Matrix Editor'] = array(
    'name' => 'Data Matrix Editor',
    'weight' => 4,
  );

  return $roles;
}
