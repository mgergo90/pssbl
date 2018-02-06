<?php

/**
 * @file
 *   Pssbl profile.
 */

 /**
  * Implements hook_install_tasks().
  */
 function pssbl_install_tasks() {
  return array(
    'pssbl_set_permissions' => array(
      'display_name' => st('Set user permissions'),
    ),
    'pssbl_set_domain_locale' => array(
      'display_name' => st('Set domain locale'),
    ),
    'pssbl_create_editor_users' => array(
      'display_name' => st('Create editor users'),
    ),
    'pssbl_block_settings' => array(
      'display_name' => st('Block settings'),
    ),
  );
 }

 /**
  * Set user permissions.
  */
function pssbl_set_permissions() {
  // provide permissioms for anonymus users
  $anonymus_roles = array('access content');
  user_role_grant_permissions(DRUPAL_ANONYMOUS_RID, $anonymus_roles);
}

/**
 *  Get domain id.
 */
function pssbl_get_domain_id($machine_name) {
    return db_select('domain', 'd')
        ->fields('d', array('domain_id'))
        ->condition('machine_name', $machine_name)
        ->execute()
        ->fetchField();
}

/**
 * Set domain locale
 */
function pssbl_set_domain_locale() {
 $blueId = pssbl_get_domain_id('blue_pssbl_dev');
 $redId = pssbl_get_domain_id('red_pssbl_dev');

 $blueLang = db_select('domain_locale', 'dl')
    ->fields('dl', array('language'))
    ->condition('language', 'de')
    ->condition('domain_id', $blueId)
    ->execute()
    ->fetchField();
 if (!$blueLang) {
    $record = array(
        'language' => 'de',
        'domain_id' => $blueId,
        'weight' => 1,
    );
     drupal_write_record('domain_locale', $record);
  }

 $redLang = db_select('domain_locale', 'dl')
      ->fields('dl', array('language'))
      ->condition('language', 'hu')
      ->condition('domain_id', $redId)
      ->execute()
      ->fetchField();
    if (!$redLang) {
      $record = array(
          'language' => 'hu',
          'domain_id' => $redId,
          'weight' => 1,
      );
      drupal_write_record('domain_locale', $record);
    }
    variable_set("i18n_string_source_language", "en");
    features_revert();
    features_rebuild();
}

/**
 * Create editor users.
 */
function pssbl_create_editor_users() {
    $blueId = pssbl_get_domain_id('blue_pssbl_dev');
    $redId = pssbl_get_domain_id('red_pssbl_dev');
    $editorRoleId = db_select('role', 'r')
        ->fields('r', array('rid'))
        ->condition('name', 'Editor')
        ->execute()
        ->fetchField();

    $users = array(
        array(
            'lang' => 'en',
            'domain' => $blueId,
            'name' => 'blueengeditor',
        ),
        array(
            'lang' => 'en',
            'domain' => $redId,
            'name' => 'redengeditor',
        ),
        array(
            'lang' => 'de',
            'domain' => $blueId,
            'name' => 'bluedeeditor',
        ),
        array(
            'lang' => 'hu',
            'domain' => $redId,
            'name' => 'redhueditor',
        ),
    );
    foreach($users as $user) {
        $new_user = array(
          'name' => $user['name'],
          'pass' => $user['name'],
          'mail' => $user['name'] . '@example.com',
          'status' => 1,
          'init' => $user['name'] . '@example.com',
          'roles' => array(
            DRUPAL_AUTHENTICATED_RID => 'authenticated user',
            $editorRoleId => 'Editor',
          ),
          'language' => $user['lang'],
          'domain_user' => array(
             $user['domain'] => $user['domain'],
          ),
        );

        user_save('', $new_user);
    }

    $admin = user_load(1);
    $admin->domain_user = array($redId => $redId, $blueId => $blueId);
    user_save($admin);
}

/**
 * Block settings.
 */
function pssbl_block_settings() {
    $blocks = array(
        array(
            'status' => 1,
            'weight' => 0,
            'region' => 'navigation',
            'visibility' => 0,
            'pages' => '',
            'module' => 'locale',
            'delta' => 'language',
            'theme' => 'pssbl_theme',
            'cache' => -1,
            'title' => '<none>',
        ),
        array(
            'status' => 1,
            'weight' => 0,
            'region' => 'navigation',
            'visibility' => 0,
            'pages' => '',
            'module' => 'menu',
            'delta' => 'menu-de-menu',
            'theme' => 'pssbl_theme',
            'cache' => -1,
            'title' => '<none>',
        ),
        array(
            'status' => 1,
            'weight' => 0,
            'region' => 'navigation',
            'visibility' => 0,
            'pages' => '',
            'module' => 'menu',
            'delta' => 'menu-hun-menu',
            'theme' => 'pssbl_theme',
            'cache' => -1,
            'title' => '<none>',
        )
    );

    foreach($blocks as $block) {
        db_merge('block')
            ->key(array(
                'module'=> $block['module'],
                'delta'=>  $block['delta'],
                'theme'=>  $block['theme'],
            ))
            ->fields($block)
            ->execute();
    }
}
