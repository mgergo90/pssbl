<?php
/**
 * @file
 * pssbl_settings_export.domains.inc
 */

/**
 * Implements hook_domain_default_domains().
 */
function pssbl_settings_export_domain_default_domains() {
  $domains = array();
  $domains['wipe-domain-tables'] = 'wipe-domain-tables';
  $domains['blue_pssbl_dev'] = array(
    'subdomain' => 'blue.pssbl.dev:8000',
    'sitename' => 'Blue site',
    'scheme' => 'http',
    'valid' => 1,
    'weight' => 1,
    'is_default' => 0,
    'machine_name' => 'blue_pssbl_dev',
  );
  $domains['red_pssbl_dev'] = array(
    'subdomain' => 'red.pssbl.dev:8000',
    'sitename' => 'Red site ',
    'scheme' => 'http',
    'valid' => 1,
    'weight' => -1,
    'is_default' => 1,
    'machine_name' => 'red_pssbl_dev',
  );

  return $domains;
}

/**
 * Implements hook_domain_conf_default_variables().
 */
function pssbl_settings_export_domain_conf_default_variables() {
  $domain_variables = array();
  $domain_variables['wipe-domain-tables'] = 'wipe-domain-tables';
  $domain_variables['blue_pssbl_dev'] = array(
    'language_default' => 'en',
  );
  $domain_variables['red_pssbl_dev'] = array(
    'language_default' => 'en',
  );

  return $domain_variables;
}
