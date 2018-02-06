<?php
/**
 * @file
 * pssbl_settings_export.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function pssbl_settings_export_default_picture_mapping() {
  $export = array();

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Slider break points';
  $picture_mapping->machine_name = 'slider_break_points';
  $picture_mapping->breakpoint_group = 'pssbl_theme';
  $picture_mapping->mapping = array(
    'breakpoints.theme.pssbl_theme.desktop' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'above_mobilbreakpoints_theme_pssbl_theme_desktop_1x',
      ),
    ),
    'breakpoints.theme.pssbl_theme.tablet' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'above_mobilbreakpoints_theme_pssbl_theme_tablet_1x',
      ),
    ),
    'breakpoints.theme.pssbl_theme.mobile' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'only_mobilbreakpoints_theme_pssbl_theme_mobile_1x',
      ),
    ),
  );
  $export['slider_break_points'] = $picture_mapping;

  return $export;
}
