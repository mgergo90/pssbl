(function ($, Drupal) {
    Drupal.behaviors.pssble_theme = {
        attach: function (context) {
            $('.owl-carousel').owlCarousel({
                loop:true,
                items: 1,
                autoplay: true
            });
        }
    };

})(jQuery, Drupal);
