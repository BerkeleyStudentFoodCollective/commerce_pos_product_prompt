(function ($) {

  Drupal.behaviors.commercePosProductPrompt = {
    attach: function (context, settings) {
      if (settings.commercePosProductPrompt && settings.commercePosProductPrompt.sku) {
        var sku = settings.commercePosProductPrompt.sku; 
        Drupal.settings.commercePosProductPrompt.sku = false;
        if (confirm(Drupal.t('Add ') + settings.commercePosProductPrompt.title + '?')) {
          setTimeout(function(){
            $('.commerce-pos-input').val(sku);
            $('.commerce-pos-ajax-trigger').click();
          }, 100);
        }
      }
    }
  };

})(jQuery);
