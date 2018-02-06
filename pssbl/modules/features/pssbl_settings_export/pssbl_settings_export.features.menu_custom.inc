<?php
/**
 * @file
 * pssbl_settings_export.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function pssbl_settings_export_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
    'language' => 'en',
    'i18n_mode' => 2,
  );
  // Exported menu: menu-de-menu.
  $menus['menu-de-menu'] = array(
    'menu_name' => 'menu-de-menu',
    'title' => 'De menu',
    'description' => '',
    'language' => 'de',
    'i18n_mode' => 2,
  );
  // Exported menu: menu-hun-menu.
  $menus['menu-hun-menu'] = array(
    'menu_name' => 'menu-hun-menu',
    'title' => 'Hun menu',
    'description' => '',
    'language' => 'hu',
    'i18n_mode' => 2,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('De menu');
  t('Hun menu');
  t('Main menu');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');

  return $menus;
}
