<?php
/**
 * @file
 * pssbl_settings_export.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function pssbl_settings_export_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_home:<front>.
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'en',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-de-menu_hauptseite:<front>.
  $menu_links['menu-de-menu_hauptseite:<front>'] = array(
    'menu_name' => 'menu-de-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Hauptseite',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-de-menu_hauptseite:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'de',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-hun-menu_foldal:<front>.
  $menu_links['menu-hun-menu_foldal:<front>'] = array(
    'menu_name' => 'menu-hun-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Főoldal',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-hun-menu_foldal:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'hu',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Főoldal');
  t('Hauptseite');
  t('Home');

  return $menu_links;
}
