(function ($) {
Drupal.behaviors.wardead = {
    attach: function(context) {

				// Close the announcement block with the click of an X.
      	$('#closeAnnouncement', context).click(function(event) {
      		$('#block-views-announcement-block').hide("slow");
      	});
      	
				$('.ui-accordion-header').attr('tabindex','0');
				
				// Hide/show the accordion content on events
				$('#accordion').live('mouseenter mouseleave', function(e) {
					var target = $(e.currentTarget).next('div.ui-accordion-content');
					if ( e.type === 'mouseenter' && !$(e.currentTarget).hasClass('open') ) {
						$('.ui-accordion-content').show();
						$(e.currentTarget).addClass('open');
					} else if ( e.type === 'mouseleave' ) {
						$('.ui-accordion-content').hide();
						$(e.currentTarget).removeClass('open');
					}
				});
				
				// Show the accordion content on focus
				$('#accordion').live('focus', function(e) {
					var prev = $(e.currentTarget);
					var target = $(e.currentTarget).find('div.ui-accordion-content');
					if ( e.type === 'focusin' ) {
						prev.addClass('open');
						target.show();						
					}
				});
				
				// Hide the accordion content on blur
				$('#accordion').find('div.ui-accordion-content').find('p:last-child a').live('blur', function(e) {
					var prev = $('#accordion');
					var target = $(e.currentTarget).parents('div.ui-accordion-content');
					if ( e.type === 'focusout' ) {
						prev.removeClass('open');
						target.hide();
					}
				});
        
        $('.pgdi-column input[type=checkbox]:checked').siblings('label').css({"background-color":"#900"});
        $('.pgdi-column input[type=checkbox]:checked').siblings('label').css({"color":"#faec7a"});
        $('.pgdi-column input[type=checkbox]:checked').siblings('label').css({"font-weight":"bold"});
        
        $('.pgdi-column input[type=checkbox]').on('change', function (e) {
          if ($('input[type=checkbox]:checked').length > 10) {
            $(this).prop('checked', false);
          }
          if ($(this).is(':checked')) {
            $(this).attr('checked', 'checked');
            $(this).siblings('label').css({"background-color":"#900"});
            $(this).siblings('label').css({"color":"#faec7a"});
            $(this).siblings('label').css({"font-weight":"bold"});
          } else {
            $(this).siblings('label').css({"background-color":"#e5e3e3"});
            $(this).siblings('label').css({"color":"#323232"});
          }
        });
        
			}					
	};
})(jQuery);
