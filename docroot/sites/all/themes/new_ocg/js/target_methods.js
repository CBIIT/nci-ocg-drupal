(function($) {
  Drupal.behaviors.targetMethods = {
    attach: function(context, settings) {
      $('.view-display-id-description span').hide();
      $('.view-display-id-projects_description span').hide();
      
      $(".views-field-field-sample-preparation-protoco a").click(function(e) {
        e.preventDefault();
        var $this = $(this);
        history.replaceState(null, '', $this.attr('href'));
        var url = window.location.hash;
        $('.view-display-id-description span').hide();
        $(url).show();
      });
      $(".views-field-field-data-analysis-protocols a").click(function(e) {
        e.preventDefault();
        var $this = $(this);
        history.replaceState(null, '', $this.attr('href'));
        var url = window.location.hash;
        $('.view-display-id-projects_description span').hide();
        $(url).show();
      });
    }
  }

})(jQuery);