<?php
/**
 * @file
 * pssbl_settings_export.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function pssbl_settings_export_user_default_roles() {
  $roles = array();

  // Exported role: Editor.
  $roles['Editor'] = array(
    'name' => 'Editor',
    'weight' => 2,
  );

  return $roles;
}
