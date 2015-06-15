/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - http://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

	
$(document).ready (function (){

    // add a class to all tbody
    $("table > tbody").addClass("tablestyles");

    // add even/odd clsses to table rows
   $(".tablestyles > tr:odd").addClass("even");
   $(".tablestyles > tr:not(.even)").addClass("odd");
			
			
  // Find all instances of the string "CTD2" and wrap a <sup> tag around the 2
  //$('body').html( $('body').html().replace(/CTD2/g, "CTD<sup>2</sup>") );
  
  $("#closeAnnouncement").click(function() {
    $(".view-id-announcement").hide();
  });
  $('.view-e-newsletters.views-accordion .view-grouping-header h3').addClass('collapsed');
  $('.view-e-newsletters.views-accordion .view-grouping-content').hide();
  $('.view-e-newsletters.views-accordion h3 .toggle').click(function(e){
    e.preventDefault();
    $(this).closest('.view-grouping').find('.view-grouping-content').slideToggle('slow');
    $(this).closest('h3').toggleClass('collapsed');
  });
  
  
  $('#superfish-2 a').focus(function(){
    $('#superfish-2 li').removeClass('focus-hover');
    $(this).parents('li').addClass('focus-hover');
  });
  $('#superfish-2 a').blur(function(){
    $('#superfish-2 li').removeClass('focus-hover');
  });

  // Make image captions same width as the image
  
 //  $('#content div.imgleft').each(function() {
 //    var width = $(this).find('.field-type-image img').width();
 //   $(this).css("width", width);
 //    } );

// Center Pages tabs
  var hash = window.location.hash;
  var url = window.location.hash.slice(1);
  if(url){ 
    $(document.getElementById(url)).removeClass('collapsed');
  }
  
  $('.fieldset-title').click(function () {
      var $this = $(this);
      $('fieldset').addClass('collapsed');
      $this.parent().parent().parent().removeClass('collapsed');
      history.replaceState(null, '', '#' + $this.parent().parent().parent().attr('id'));
  });
	
}); // end doc ready

// Detecting font
window.onload = function() {
  // Detect font and remove Modernizr's font face class if the font isn't being detected - controls for IE security settings
  var detective = new Detector();
  if (!detective.detect('FranklinGothicFSMedCdRegular')) {
    $('html').removeClass('fontface');
  }    
};
	
})(jQuery, Drupal, this, this.document);
