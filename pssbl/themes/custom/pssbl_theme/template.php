<?php

/**
 * @file
 * template.php
 */

function pssbl_theme_preprocess_page(&$vars) {
    drupal_add_css(libraries_get_path('owl-carousel') . '/dist/assets/owl.carousel.css');
    drupal_add_js(libraries_get_path('owl-carousel') . '/dist/owl.carousel.js');
}
