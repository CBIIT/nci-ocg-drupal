<?php
/**
 * @file
 * Default simple view template to display a group of summary lines.
 *
 * This wraps items in a span if set to inline, or a div if not.
 *
 * @ingroup views_templates
 */
if (!empty(drupal_get_query_parameters())) {
  $parameters = drupal_get_query_parameters();
  $tool_type_parameter = $parameters['tool_type'];
  $items_per_page_parameter = $parameters['items_per_page'];
} else {
  $tool_type_parameter = 'All';
  $items_per_page_parameter = 10;
}
$total = array();
?>
<?php if ($tool_type_parameter != 91): ?>
  <?php foreach ($rows as $id => $row): ?>
    <?php
    $tool_type = 'tool_type=' . $tool_type_parameter;
    if (!empty($items_per_page_parameter)) {
      $items_per_page = '&items_per_page=' . $items_per_page_parameter;
      if ($items_per_page_parameter == 'All') {
        $page_number = '';
      } else {
        $total[] = $row->count;
        if (((array_sum($total)-$row->count)+1) <= $items_per_page_parameter) {
          $page_number = '';
        } else {
          if (!is_float(((array_sum($total)-$row->count)+1)/$items_per_page_parameter)) {
            $page = floor(((array_sum($total)-$row->count)+1)/$items_per_page_parameter)-1;
          } else {
            $page = floor(((array_sum($total)-$row->count)+1)/$items_per_page_parameter);
          }
          $page_number = '&page=' . $page;
        }
      }
    } else {
      $items_per_page = '';
    }
    $row->url = '/programs/ctd2/analytical-tools/?' . $tool_type . $items_per_page . $page_number . '#' . $row->link;
    ?>

    <?php print (!empty($options['inline']) ? '<span' : '<div') . ' class="views-summary views-summary-unformatted">'; ?>
    <?php
    if (!empty($row->separator)) {
      print $row->separator;
    }
    ?>
    <a href="<?php print $row->url; ?>"<?php print !empty($row_classes[$id]) ? ' class="' . $row_classes[$id] . '"' : ''; ?>><?php print $row->link; ?></a>
    <?php if (!empty($options['count'])): ?>
      (<?php print $row->count; ?>)
    <?php endif; ?>
    <?php print !empty($options['inline']) ? '</span>' : '</div>'; ?>
  <?php endforeach; ?>
<?php endif; ?>