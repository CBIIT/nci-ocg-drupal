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
            <?php
            print theme('links__system_secondary_menu', array(
                'links' => $secondary_menu,
                'attributes' => array(
                    'class' => array('links', 'inline', 'clearfix'),
                ),
                'heading' => array(
                    'text' => $secondary_menu_heading,
                    'level' => 'h2',
                    'class' => array('element-invisible'),
                ),
            ));
            ?>
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
          if (!strpos($url, 'printmail')) {
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
      <?php print $messages; ?>
        <a id="main-content"></a>
        <div class="display-header">
          <div class="cgci-title">
            <?php print render($title_prefix); ?>
            <?php if ($title): ?>
              <h1 class="page__title title dataMatrixHeader" id="page-title"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print views_embed_view('cgci_data_matrix', 'target_last_updated'); ?>
          </div>
          <div class="target-home">
            <a href="/programs/target"><img typeof="foaf:Image" src="/sites/default/files/TARGET_Banner_Cropped.jpg" width="52" height="80" alt="Links to TARGET Homepage" title="Link to TARGET Homepage"></a>
            <a href="/programs/target">TARGET Program</a>
          </div>
          <div class="target-data">
            <a href="/programs/target/using-target-data"><img typeof="foaf:Image" src="/sites/default/files/styles/80x80/public/USING%20DATA.png" width="75" height="80" alt="Link to instructions on how to use the data" title="Link to instructions on how to use the data"></a>
            <a href="/programs/target/using-target-data">Using TARGET Data</a>
          </div>
          <div class="target-methods">
            <a href="/programs/target/target-methods"><img typeof="foaf:Image" src="/sites/default/files/styles/80x80/public/PROCEDURES%20METHODS%20ICON.png" width="76" height="80" alt="Link to Procedures and Methods" title="Link to Procedures and Methods"></a>
            <a href="/programs/target/target-methods">TARGET Methods</a>
          </div>
          <div class="target-awg">
            <a href="/programs/target/projects/target-analysis-working-group"><img typeof="foaf:Image" src="/sites/default/files/styles/80x80/public/TARGET%20ICON.png?itok=wh03aPv8" width="52" height="80" alt="DNA Helix with bullseye target. Links to TARGET Analysis Working Group" title="Link to TARGET Analysis Working Group"></a>
            <a href="/programs/target/projects/target-analysis-working-group">TARGET Analysis Working Group</a>
          </div>
          <div class="pgdi-overview">
            <a href="https://datascience.cancer.gov/resources/nci-data-catalog/pediatric-genomic-data-inventory"><img typeof="foaf:Image" src="/sites/default/files/styles/80x80/public/PGDI_Icon-for-Home-Page.png?itok=YLIiSqV5" width="80" height="80" alt="Pediatric Resource" title="Pediatric Resource"></a>
            <a href="https://datascience.cancer.gov/resources/nci-data-catalog/pediatric-genomic-data-inventory">Pediatric Resource</a>
          </div>
        </div>
        <?php print render($title_suffix); ?>
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
      $sidebar_first = render($page['sidebar_first']);
      $sidebar_second = render($page['sidebar_second']);
      ?>

        <?php if ($sidebar_first || $sidebar_second): ?>
        <aside class="sidebars">
        <?php print $sidebar_first; ?>
        <?php print $sidebar_second; ?>
        </aside>
        <?php endif; ?>

      <div id="postscript-first">
      <?php print render($page['postscript_first']); ?>
      </div><!-- /#postscript-first -->

    </div>

  </div>
  <div class="footer-wrap">
    <div class="footer-wrap-inner">
    <?php print render($page['footer']); ?>
    </div><!-- /footer-wrap-inner -->
  </div><!-- /footer-wrap -->
</div>

<?php print render($page['bottom']); ?>
