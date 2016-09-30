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
			}					
	};
})(jQuery);
