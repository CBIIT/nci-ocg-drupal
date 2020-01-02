window.onload = (function($) {
  
  window.onscroll = function (e) {  
  // called when the window is scrolled.
    if($(window).scrollTop() > 20) {
      $('body:not(.toolbar)').css({'transform':'none'});
    } else {
      $('body:not(.toolbar)').css({'transform':'translateY(24px)'});
    }
  };

})(jQuery);