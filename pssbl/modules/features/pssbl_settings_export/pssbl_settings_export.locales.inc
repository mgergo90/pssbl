<?php
/**
 * @file
 * pssbl_settings_export.locales.inc
 */

/**
 * Implements hook_domain_locale_default_locales().
 */
function pssbl_settings_export_domain_locale_default_locales() {
  $locales = array();
  $locales['wipe-domain-locale-tables'] = 'wipe-domain-locale-tables';
  $locales['blue_pssbl_dev'] = array(
    'en' => 0,
  );
  $locales['red_pssbl_dev'] = array(
    'en' => 0,
  );

  return $locales;
}
