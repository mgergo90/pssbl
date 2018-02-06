<?php
/**
 * @file
 * pssbl_settings_export.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pssbl_settings_export_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "breakpoints" && $api == "default_breakpoint_group") {
    return array("version" => "1");
  }
  if ($module == "breakpoints" && $api == "default_breakpoints") {
    return array("version" => "1");
  }
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function pssbl_settings_export_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function pssbl_settings_export_image_default_styles() {
  $styles = array();

  // Exported image style: above_mobilbreakpoints_theme_pssbl_theme_desktop_1x.
  $styles['above_mobilbreakpoints_theme_pssbl_theme_desktop_1x'] = array(
    'label' => 'above_mobilbreakpoints_theme_pssbl_theme_desktop_1x',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1300,
          'height' => 400,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: above_mobilbreakpoints_theme_pssbl_theme_tablet_1x.
  $styles['above_mobilbreakpoints_theme_pssbl_theme_tablet_1x'] = array(
    'label' => 'above_mobilbreakpoints_theme_pssbl_theme_tablet_1x',
    'effects' => array(
      5 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1300,
          'height' => 400,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: above_mobilmodule_picture_empty_srcset_1x.
  $styles['above_mobilmodule_picture_empty_srcset_1x'] = array(
    'label' => 'above_mobilmodule_picture_empty_srcset_1x',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1300,
          'height' => 400,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: only_mobilbreakpoints_theme_pssbl_theme_mobile_1x.
  $styles['only_mobilbreakpoints_theme_pssbl_theme_mobile_1x'] = array(
    'label' => 'only_mobilbreakpoints_theme_pssbl_theme_mobile_1x',
    'effects' => array(
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 600,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: slider_desktop.
  $styles['slider_desktop'] = array(
    'label' => 'slider_desktop',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1300,
          'height' => 400,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: slider_mobile.
  $styles['slider_mobile'] = array(
    'label' => 'slider_mobile',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 600,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function pssbl_settings_export_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'slider' => array(
      'name' => t('Slider'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
