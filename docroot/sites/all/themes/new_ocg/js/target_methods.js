(function($) {
  Drupal.behaviors.targetMethods = {
    attach: function(context, settings) {
      $('.view-display-id-description .views-row').show();
      $('.view-display-id-projects_description .field-item span').show();
      $('.view-display-id-description .views-row').hide();
      $('.view-display-id-projects_description .hide-description').hide();

      $(".views-field-field-sample-preparation-protoco a").click(function(e) {
        e.preventDefault();
        var $this = $(this);
        history.replaceState(null, '', $this.attr('href'));
        var url = window.location.hash;
        $('.view-display-id-description .views-row').hide();
        $(url).parent().parent().parent().show();
        $(url).show();
      });
      $(".views-field-field-data-analysis-protocols a").click(function(e) {
        e.preventDefault();
        var $this = $(this);
        history.replaceState(null, '', $this.attr('href'));
        var url = window.location.hash;
        $('.view-display-id-projects_description .hide-description').hide();
        $('.view-display-id-projects_description .field-item span').show();
        $(url).show();
      });
    }
  };

})(jQuery);