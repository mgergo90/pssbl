<?php
/**
 * @file
 * pssbl_settings_export.default_breakpoint_group.inc
 */

/**
 * Implements hook_default_breakpoint_group().
 */
function pssbl_settings_export_default_breakpoint_group() {
  $export = array();

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'pssbl_theme';
  $breakpoint_group->name = 'Pssbl theme';
  $breakpoint_group->breakpoints = array(
    0 => 'breakpoints.theme.pssbl_theme.desktop',
    1 => 'breakpoints.theme.pssbl_theme.tablet',
    2 => 'breakpoints.theme.pssbl_theme.mobile',
  );
  $breakpoint_group->type = 'theme';
  $breakpoint_group->overridden = 0;
  $export['pssbl_theme'] = $breakpoint_group;

  return $export;
}
