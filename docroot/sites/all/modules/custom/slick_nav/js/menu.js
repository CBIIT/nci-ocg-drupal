/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
(function($) {

  // Iterate through selectors, check window sizes, add some classes.
  Drupal.behaviors.responsive_menus = {
    attach: function(context, settings) {

      settings.responsive_menus = settings.responsive_menus || {};

      $.each(settings.responsive_menus, function(ind, iteration) {
        if (iteration.responsive_menus_style != 'slick_nav') {
          return true;
        }
        var prepend = iteration.prepend.toString();
        var children = iteration.children.toString();
        var toggler_text = iteration.toggler_text.toString();
        $.each(iteration.selectors, function(index, value) {
          if (children == 'true') {
            console.log(children);
            $(value).slicknav({
              label: toggler_text,
              prependTo: prepend,
              showChildren: true
            });
          } else {
            $(value).slicknav({
              label: toggler_text,
              prependTo: prepend,
              showChildren: false
            });
          }
          $(value).addClass('not_slicknav');
        });
      });
    }
  };
}(jQuery));

