<?php

/**
 * @file
 * template.php
 */

/**
 * Implements theme_preprocess_page().
 */
function pssbl_theme_preprocess_page(&$vars) {
    drupal_add_css(libraries_get_path('owl-carousel') . '/dist/assets/owl.carousel.css');
    drupal_add_js(libraries_get_path('owl-carousel') . '/dist/owl.carousel.js');
}

/**
 * Implements theme_menu_tree().
 */
function pssbl_theme_menu_tree(array &$variables) {
    return '<ul class="menu nav navbar-nav">' . $variables['tree'] . '</ul>';
}
