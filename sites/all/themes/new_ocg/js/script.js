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
      window.location.hash = '#' + $this.parent().parent().parent().attr('id');
      $('.view-display-id-projects_description span').hide();
  });
  
  $(".expand-collapse").click(function(e) {
    if($('fieldset').hasClass('collapsed')) {
      $('fieldset').removeClass('collapsed');
      $(this).text('Collapse All');
      e.preventDefault();
    } else {
      $('fieldset').addClass('collapsed');
      $(this).text('Expand All');
      e.preventDefault();
    }
  });
  
  $(".open-close-all").click(function(e) {
    if($('.views-field-field-institute').hasClass('ui-corner-all')) {
      $('.ui-accordion-header').removeClass('ui-corner-all').addClass('ui-accordion-header-active ui-state-active ui-corner-top').attr({'aria-selected':'true','tabindex':'0'});
      $('.ui-accordion-header .ui-icon').removeClass('ui-icon-triangle-1-e').addClass('ui-icon-triangle-1-s');
      $('.ui-accordion-content').addClass('ui-accordion-content-active').attr({'aria-expanded':'true','aria-hidden':'false'}).show();
      $(this).text('Collapse All');
      e.preventDefault();
    } else {
      $('.ui-accordion-header').removeClass('ui-accordion-header-active ui-state-active ui-corner-top').addClass('ui-corner-all').attr({'aria-selected':'false','tabindex':'-1'});
      $('.ui-accordion-header .ui-icon').removeClass('ui-icon-triangle-1-s').addClass('ui-icon-triangle-1-e');
      $('.ui-accordion-content').removeClass('ui-accordion-content-active').attr({'aria-expanded':'false','aria-hidden':'true'}).hide();
      $(this).text('Expand All');
      e.preventDefault();
    }
    
  });
  
  $(".open-close-new").click(function(e) {
    if($('.New').hasClass('ui-corner-all')) {
      $('.New').removeClass('ui-corner-all').addClass('ui-accordion-header-active ui-state-active ui-corner-top').attr({'aria-selected':'true','tabindex':'0'});
      $('.New .ui-icon').removeClass('ui-icon-triangle-1-e').addClass('ui-icon-triangle-1-s');
      $('.New').siblings('.ui-accordion-content').addClass('ui-accordion-content-active').attr({'aria-expanded':'true','aria-hidden':'false'}).show();
      $(this).text('Collapse All New Projects');
      e.preventDefault();
    } else {
      $('.New').removeClass('ui-accordion-header-active ui-state-active ui-corner-top').addClass('ui-corner-all').attr({'aria-selected':'false','tabindex':'-1'});
      $('.New .ui-icon').removeClass('ui-icon-triangle-1-s').addClass('ui-icon-triangle-1-e');
      $('.New').siblings('.ui-accordion-content').removeClass('ui-accordion-content-active').attr({'aria-expanded':'false','aria-hidden':'true'}).hide();
      $(this).text('Expand All New Projects');
      e.preventDefault();
    }
    
  });
  
  $(".open-close-completed").click(function(e) {
    if($('.Completed').hasClass('ui-corner-all')) {
      $('.Completed').removeClass('ui-corner-all').addClass('ui-accordion-header-active ui-state-active ui-corner-top').attr({'aria-selected':'true','tabindex':'0'});
      $('.Completed .ui-icon').removeClass('ui-icon-triangle-1-e').addClass('ui-icon-triangle-1-s');
      $('.Completed').siblings('.ui-accordion-content').addClass('ui-accordion-content-active').attr({'aria-expanded':'true','aria-hidden':'false'}).show();
      $(this).text('Collapse All Completed Projects');
      e.preventDefault();
    } else {
      $('.Completed').removeClass('ui-accordion-header-active ui-state-active ui-corner-top').addClass('ui-corner-all').attr({'aria-selected':'false','tabindex':'-1'});
      $('.Completed .ui-icon').removeClass('ui-icon-triangle-1-s').addClass('ui-icon-triangle-1-e');
      $('.Completed').siblings('.ui-accordion-content').removeClass('ui-accordion-content-active').attr({'aria-expanded':'false','aria-hidden':'true'}).hide();
      $(this).text('Expand All Completed Projects');
      e.preventDefault();
    }
    
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
