<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>

<div id="page">
    
  <div class="outer-header">
    <div class="disappear">

  <header class="header" id="header" role="banner">

    <?php if ($new_logo): ?>
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="header__logo" id="logo"><img src="<?php print base_path() . $new_logo; ?>" alt="<?php print t('Home'); ?>" class="header__logo-image" /></a>
    <?php endif; ?>

    <?php if ($site_name || $site_slogan): ?>
      <div class="header__name-and-slogan" id="name-and-slogan">
        <?php if ($site_name): ?>
          <h1 class="header__site-name" id="site-name">
            <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" class="header__site-link" rel="home"><span><?php print $site_name; ?></span></a>
          </h1>
        <?php endif; ?>

        <?php if ($site_slogan): ?>
          <div class="header__site-slogan" id="site-slogan"><?php print $site_slogan; ?></div>
        <?php endif; ?>
      </div>
    <?php endif; ?>

    <?php if ($secondary_menu): ?>
      <nav class="header__secondary-menu" id="secondary-menu" role="navigation">
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

  </header>
      <div class="dna-banner">
  </div><!-- /dna-banner -->
    <div id="navigation">

      <?php print render($page['navigation']); ?>

    </div>
    </div>
  </div>
<div id="page-inner">
  <div id="main">
    
    <div id="pre-content">
      <div id="block-block-7" class="block block-block addthis first odd">
        <?php 
        if ((arg(0) == 'node') && (is_numeric(arg(1)))) {
          $nid = arg(1);
        } else {
          $nid = '';
        }
        ?>
        <?php 
        if (!empty($nid)) { 
          $mailurl = 'printmail/' . $nid;
          $printurl = 'print/' . $nid;
        } else { 
          $mailurl = 'printmail';
          $printurl = 'print';
        }
        $url = 'http://' . $_SERVER['SERVER_NAME'] . $_SERVER['REQUEST_URI'];
        if (!strpos($url,'printmail')) {
          print '<a href="/' . $mailurl . '" style="border-left:none;border-right:1px dotted #d2d2d2;margin-right:0;padding-right:5px;">Email</a>';
        }
        print '<a href="/' . $printurl . '" style="border-left:none;padding-left:0;">Print</a>';
        ?>
      </div>
      <?php print render($page['highlighted']); ?>
      <?php print $breadcrumb; ?>
      <?php print render($page['pre_content']); ?>
    </div>
    <div id="content" class="column" role="main">
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <h1 class="page__title title" id="page-title"><?php print $title; ?></h1>
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
    </div>

    <?php
      // Render the sidebars to see if there's anything in them.
      $sidebar_first  = render($page['sidebar_first']);
      $sidebar_second = render($page['sidebar_second']);
    ?>

    <?php if ($sidebar_first || $sidebar_second): ?>
      <aside class="sidebars">
        <?php print $sidebar_first; ?>
        <?php print $sidebar_second; ?>
      </aside>
    <?php endif; ?>

  </div>

</div>
  <div class="footer-wrap">
    <div class="footer-wrap-inner">
      <?php print render($page['footer']); ?>
    </div><!-- /footer-wrap-inner -->
  </div><!-- /footer-wrap -->
</div>

<?php print render($page['bottom']); ?>
