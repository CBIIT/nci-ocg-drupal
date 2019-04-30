<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
global $base_root;
$alias = $base_root . '/' . drupal_get_path_alias('node/'.$row->nid);
?>
<a name="<?php print $row->nid; ?>"></a>
<span><?php print $row->field_field_enews_category[0]['rendered']['#label']; ?></span>
<span class="share-buttons">
  <div class="addthis_toolbox addthis_default_style addthis_32x32_style">
    <a class="addthis_button_facebook" addthis:url="<?php print $alias ?>?cid=fb_ocg-updates_sharedposts" addthis:title="<?php print $row->node_title; ?>"></a>
    <a class="addthis_button_twitter" addthis:url="<?php print $alias ?>?cid=tw_ocg-updates_sharedposts"></a>
    <a class="addthis_button_linkedin" addthis:url="<?php print $alias ?>?cid=li_ocg-updates_sharedposts"></a>
    <a class="addthis_button_email" addthis:url="<?php print $alias ?>?cid=em_ocg-updates_sharedposts"></a>
</div>
</span><br /> <?php print $output; ?>
