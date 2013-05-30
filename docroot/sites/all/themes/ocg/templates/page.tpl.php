    <?php
/**
 * @file
 * Zen theme's implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $secondary_menu_heading: The title of the menu used by the secondary links.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['header']: Items for the header region.
 * - $page['navigation']: Items for the navigation region, below the main menu (if any).
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['footer']: Items for the footer region.
 * - $page['bottom']: Items to appear at the bottom of the page below the footer.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see zen_preprocess_page()
 * @see template_process()
 */
?>

<div id="page">

  <div class="NCI-banner">
    <div class="NCI-inner">
      <a href="http://www.cancer.gov"><img src="/sites/all/themes/ocg/images/NCI-banner.jpg" alt="<?php print t('National Cancer Institute at the National Institutes of Health (www.cancer.gov)'); ?>" /></a>
      <!--<img src="/sites/all/themes/ocg/images/NCI-banner.jpg" border=0 usemap="#bannermap">
      <map name="bannermap">
      <area shape=rect coords="13,1,257,33" href="http://www.cancer.gov" alt="National Cancer Institute">
      <area shape=rect coords="698,10,847,24" href="http://www.nih.gov" alt="at the National Institutes of Health">
      <area shape=rect coords="853,12,948,25" href="http://www.cancer.gov" alt="www.cancer.gov">
      </map>-->
    </div><!-- /NCI-inner -->
  </div><!-- /NCI-banner -->
  
  <div class="dna-banner">
  </div><!-- /dna-banner -->

  <div class="outer-header">
    <div class="disappear">
      <header id="header" role="banner">
  
        <?php if ($logo): ?>
          <a href="<?php print $front_page; ?>" title="<?php print t('OCG Home'); ?>" rel="home" id="logo"><img src="<?php print $logo; ?>" alt="<?php print t('OCG Home'); ?>" /></a>
          <?php endif; ?>
  
          <?php if ($site_name || $site_slogan): ?>
          <hgroup id="name-and-slogan">
            <?php if ($site_name): ?>
              <div id="site-name">
              <?php 
                $words = explode(' ', $site_name);
                $words[1] = '<span class="of">' . $words[1] . '</span>';
                $site_name = implode(' ',$words);
               ?>
                <a href="<?php print $front_page; ?>" title="<?php print t('OCG Home'); ?>"  alt="<?php print t('OCG Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
              </div>
                <?php endif; ?>
  
            <?php if ($site_slogan): ?>
              <h2 id="site-slogan"><?php print $site_slogan; ?></h2>
            <?php endif; ?>
          </hgroup><!-- /#name-and-slogan -->
        <?php endif; ?>
    
        <?php if ($secondary_menu): ?>
          <nav id="secondary-menu" role="navigation">
            <?php print theme('links__system_secondary_menu', array(
              'links' => $secondary_menu,
              'attributes' => array(
                'class' => array('links', 'inline', 'clearfix'),
              ),
              'heading' => array(
                'text' => $secondary_menu_heading,
                'level' => 'h2',
                'class' => array('element-invisible'),
              ),
            )); ?>
          </nav>
        <?php endif; ?>
    
        <?php print render($page['header']); ?>
        
            <div id="navigation">
              <?php print render($page['navigation']); ?>
            </div><!-- /#navigation -->
    
      </header>
    </div><!-- /disappear -->
  </div> <!-- /outer-hearder -->

  <div class="main-wrap">
    <div id="main">
      <div id="pre-content">
        <?php print render($page['highlighted']); ?>
        <?php print $breadcrumb; ?>
        <?php print render($page['pre_content']); ?>
      </div><!-- /#pre-content -->
  
      <div id="content" class="column" role="main">
        <a id="main-content"></a>
        <?php print render($title_prefix); ?>
        <?php if ($title): ?>
          <h1 class="title" id="page-title"><?php print $title; ?></h1>
        <?php endif; ?>
        <?php print render($title_suffix); ?>
        <?php print $messages; ?>
        <?php print render($tabs); ?>
        <?php print render($page['help']); ?>
        <?php if ($action_links): ?>
          <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>
        <?php print render($page['content']); ?>
        <?php print $feed_icons; ?>
      </div><!-- /#content -->
  
      <?php
        // Render the sidebars to see if there's anything in them.
        $sidebar_first  = render($page['sidebar_first']);
        $sidebar_second = render($page['sidebar_second']);
      ?>
  
      <?php if ($sidebar_first || $sidebar_second): ?>
        <aside class="sidebars">
          <?php print $sidebar_first; ?>
          <?php print $sidebar_second; ?>
        </aside><!-- /.sidebars -->
      <?php endif; ?>
      
      <div id="postscript-first">
        <?php print render($page['postscript_first']); ?>
      </div><!-- /#postscript-first -->
      
      <div id="postscript-second">
        <?php print render($page['postscript_second']); ?>
      </div><!-- /#postscript-second -->
  
    </div><!-- /#main -->
  </div><!-- /main-wrap -->

  <div class="footer-wrap">
    <div class="footer-wrap-inner">
      <?php print render($page['footer']); ?>
    </div><!-- /footer-wrap-inner -->
  </div><!-- /footer-wrap -->

</div><!-- /#page -->

<?php print render($page['bottom']); ?>