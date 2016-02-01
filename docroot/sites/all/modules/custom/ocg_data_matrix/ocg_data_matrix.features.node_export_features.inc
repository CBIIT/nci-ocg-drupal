<?php
/**
 * @file
 * ocg_data_matrix.features.node_export_features.inc
 */

/**
 * Implements hook_node_export_features_default().
 */
function ocg_data_matrix_node_export_features_default() {
  $node_export = array(
  'code_string' => 'array(
  (object) array(
      \'vid\' => \'1166\',
      \'uid\' => \'1176\',
      \'title\' => \'HIV+ Tumor Molecular Characterization Project (HTMCP)\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'0\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'a7b710db-be7a-46bc-9ecb-464e3575b986\',
      \'ds_switch\' => \'\',
      \'nid\' => \'1166\',
      \'type\' => \'disease\',
      \'language\' => \'und\',
      \'created\' => \'1453488218\',
      \'changed\' => \'1454013513\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'222dfa65-1493-40f7-b5e5-6c51998030d1\',
      \'revision_timestamp\' => \'1454013513\',
      \'revision_uid\' => \'1181\',
      \'field_program\' => array(
        \'und\' => array(
          array(
            \'value\' => \'CGCI\',
          ),
        ),
      ),
      \'field_disease\' => array(
        \'und\' => array(
          array(
            \'value\' => \'666\',
            \'revision_id\' => \'666\',
          ),
          array(
            \'value\' => \'696\',
            \'revision_id\' => \'696\',
          ),
          array(
            \'value\' => \'821\',
            \'revision_id\' => \'821\',
          ),
        ),
      ),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'print_display\' => 1,
      \'print_display_comment\' => 0,
      \'print_display_urllist\' => 1,
      \'name\' => \'ian-moran\',
      \'picture\' => \'0\',
      \'data\' => \'a:5:{s:16:"ckeditor_default";s:1:"t";s:20:"ckeditor_show_toggle";s:1:"t";s:14:"ckeditor_width";s:4:"100%";s:13:"ckeditor_lang";s:2:"en";s:18:"ckeditor_auto_lang";s:1:"t";}\',
      \'print_mail_display\' => 1,
      \'print_mail_display_comment\' => 0,
      \'print_mail_display_urllist\' => 1,
      \'path\' => FALSE,
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
      \'node_export_dependency\' => array(
        array(
          \'type\' => \'field_collection_item\',
          \'id\' => \'666\',
          \'delta\' => 0,
          \'property\' => \'value\',
          \'module\' => \'field_collection\',
          \'field_name\' => \'field_disease\',
          \'langcode\' => \'und\',
          \'uuid\' => \'3815735f-ed5a-439f-be9e-b997f9517d44\',
        ),
        array(
          \'type\' => \'field_collection_item\',
          \'id\' => \'696\',
          \'delta\' => 1,
          \'property\' => \'value\',
          \'module\' => \'field_collection\',
          \'field_name\' => \'field_disease\',
          \'langcode\' => \'und\',
          \'uuid\' => \'a530f9b6-8766-4130-b3af-973527830735\',
        ),
        array(
          \'type\' => \'field_collection_item\',
          \'id\' => \'821\',
          \'delta\' => 2,
          \'property\' => \'value\',
          \'module\' => \'field_collection\',
          \'field_name\' => \'field_disease\',
          \'langcode\' => \'und\',
          \'uuid\' => \'2ba2878a-e7cb-45ff-8f04-434d5e900104\',
        ),
        array(
          \'type\' => \'user\',
          \'id\' => \'1176\',
          \'delta\' => 0,
          \'property\' => \'uid\',
          \'module\' => \'node\',
          \'uuid\' => \'3f6d8ba4-8b44-412d-99d4-7c772095b40a\',
        ),
        array(
          \'type\' => \'user\',
          \'id\' => \'1181\',
          \'delta\' => 0,
          \'property\' => \'revision_uid\',
          \'module\' => \'node\',
          \'uuid\' => \'ff685c9d-54da-44b0-bd95-09e5cb377c20\',
        ),
      ),
    ),
  (object) array(
      \'vid\' => \'1116\',
      \'uid\' => \'426\',
      \'title\' => "Burkitt\'s Lymphoma (BLGSP)",
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'0\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'290298a6-820c-41f4-a57f-046f784f9b35\',
      \'ds_switch\' => \'\',
      \'nid\' => \'1116\',
      \'type\' => \'disease\',
      \'language\' => \'und\',
      \'created\' => \'1448377164\',
      \'changed\' => \'1454009527\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'5e3dd5a9-48aa-4a6e-9573-fe66ed3a2eff\',
      \'revision_timestamp\' => \'1454009527\',
      \'revision_uid\' => \'426\',
      \'field_program\' => array(
        \'und\' => array(
          array(
            \'value\' => \'CGCI\',
          ),
        ),
      ),
      \'field_disease\' => array(
        \'und\' => array(
          array(
            \'value\' => \'311\',
            \'revision_id\' => \'311\',
          ),
        ),
      ),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'print_display\' => 1,
      \'print_display_comment\' => 0,
      \'print_display_urllist\' => 1,
      \'name\' => \'imoran\',
      \'picture\' => \'0\',
      \'data\' => \'a:6:{s:16:"ckeditor_default";s:1:"t";s:20:"ckeditor_show_toggle";s:1:"t";s:14:"ckeditor_width";s:4:"100%";s:13:"ckeditor_lang";s:2:"en";s:18:"ckeditor_auto_lang";s:1:"t";s:7:"overlay";i:1;}\',
      \'print_mail_display\' => 1,
      \'print_mail_display_comment\' => 0,
      \'print_mail_display_urllist\' => 1,
      \'path\' => FALSE,
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
      \'node_export_dependency\' => array(
        array(
          \'type\' => \'field_collection_item\',
          \'id\' => \'311\',
          \'delta\' => 0,
          \'property\' => \'value\',
          \'module\' => \'field_collection\',
          \'field_name\' => \'field_disease\',
          \'langcode\' => \'und\',
          \'uuid\' => \'ab8e2ce1-d63b-4f39-9776-94f3277647a2\',
        ),
        array(
          \'type\' => \'user\',
          \'id\' => \'426\',
          \'delta\' => 0,
          \'property\' => \'uid\',
          \'module\' => \'node\',
          \'uuid\' => \'10782d1b-75df-4cd6-9b4b-ec3499b45090\',
        ),
        array(
          \'type\' => \'user\',
          \'id\' => \'426\',
          \'delta\' => 0,
          \'property\' => \'revision_uid\',
          \'module\' => \'node\',
          \'uuid\' => \'10782d1b-75df-4cd6-9b4b-ec3499b45090\',
        ),
      ),
    ),
  (object) array(
      \'vid\' => \'1126\',
      \'uid\' => \'426\',
      \'title\' => "Non-Hodgkin\'s Lymphoma (NHL)",
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'0\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'b9c9beef-e9a9-47db-b4a3-c8533088d468\',
      \'ds_switch\' => \'\',
      \'nid\' => \'1126\',
      \'type\' => \'disease\',
      \'language\' => \'und\',
      \'created\' => \'1448379401\',
      \'changed\' => \'1454101091\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'7efb60e4-8d3b-441b-bcd9-e44db0245fe1\',
      \'revision_timestamp\' => \'1454101091\',
      \'revision_uid\' => \'1181\',
      \'field_program\' => array(
        \'und\' => array(
          array(
            \'value\' => \'CGCI\',
          ),
        ),
      ),
      \'field_disease\' => array(
        \'und\' => array(
          array(
            \'value\' => \'466\',
            \'revision_id\' => \'466\',
          ),
          array(
            \'value\' => \'561\',
            \'revision_id\' => \'561\',
          ),
        ),
      ),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'print_display\' => 1,
      \'print_display_comment\' => 0,
      \'print_display_urllist\' => 1,
      \'name\' => \'imoran\',
      \'picture\' => \'0\',
      \'data\' => \'a:6:{s:16:"ckeditor_default";s:1:"t";s:20:"ckeditor_show_toggle";s:1:"t";s:14:"ckeditor_width";s:4:"100%";s:13:"ckeditor_lang";s:2:"en";s:18:"ckeditor_auto_lang";s:1:"t";s:7:"overlay";i:1;}\',
      \'print_mail_display\' => 1,
      \'print_mail_display_comment\' => 0,
      \'print_mail_display_urllist\' => 1,
      \'path\' => FALSE,
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
      \'node_export_dependency\' => array(
        array(
          \'type\' => \'field_collection_item\',
          \'id\' => \'466\',
          \'delta\' => 0,
          \'property\' => \'value\',
          \'module\' => \'field_collection\',
          \'field_name\' => \'field_disease\',
          \'langcode\' => \'und\',
          \'uuid\' => \'3dc19f11-0f9e-4842-acd7-69add1ccd093\',
        ),
        array(
          \'type\' => \'field_collection_item\',
          \'id\' => \'561\',
          \'delta\' => 1,
          \'property\' => \'value\',
          \'module\' => \'field_collection\',
          \'field_name\' => \'field_disease\',
          \'langcode\' => \'und\',
          \'uuid\' => \'68d3e48f-afbc-4376-bd51-f2f31198a660\',
        ),
        array(
          \'type\' => \'user\',
          \'id\' => \'426\',
          \'delta\' => 0,
          \'property\' => \'uid\',
          \'module\' => \'node\',
          \'uuid\' => \'10782d1b-75df-4cd6-9b4b-ec3499b45090\',
        ),
        array(
          \'type\' => \'user\',
          \'id\' => \'1181\',
          \'delta\' => 0,
          \'property\' => \'revision_uid\',
          \'module\' => \'node\',
          \'uuid\' => \'ff685c9d-54da-44b0-bd95-09e5cb377c20\',
        ),
      ),
    ),
  (object) array(
      \'vid\' => \'1121\',
      \'uid\' => \'426\',
      \'title\' => \'Medulloblastoma (MB)\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'0\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'2a0594cc-f211-4606-bc79-c1bccfee08ac\',
      \'ds_switch\' => \'\',
      \'nid\' => \'1121\',
      \'type\' => \'disease\',
      \'language\' => \'und\',
      \'created\' => \'1448378283\',
      \'changed\' => \'1454009468\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'c22bd48d-8fed-44ce-b527-7c7cf0aa7693\',
      \'revision_timestamp\' => \'1454009468\',
      \'revision_uid\' => \'426\',
      \'field_program\' => array(
        \'und\' => array(
          array(
            \'value\' => \'CGCI\',
          ),
        ),
      ),
      \'field_disease\' => array(
        \'und\' => array(
          array(
            \'value\' => \'361\',
            \'revision_id\' => \'361\',
          ),
        ),
      ),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'print_display\' => 1,
      \'print_display_comment\' => 0,
      \'print_display_urllist\' => 1,
      \'name\' => \'imoran\',
      \'picture\' => \'0\',
      \'data\' => \'a:6:{s:16:"ckeditor_default";s:1:"t";s:20:"ckeditor_show_toggle";s:1:"t";s:14:"ckeditor_width";s:4:"100%";s:13:"ckeditor_lang";s:2:"en";s:18:"ckeditor_auto_lang";s:1:"t";s:7:"overlay";i:1;}\',
      \'print_mail_display\' => 1,
      \'print_mail_display_comment\' => 0,
      \'print_mail_display_urllist\' => 1,
      \'path\' => FALSE,
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
      \'node_export_dependency\' => array(
        array(
          \'type\' => \'field_collection_item\',
          \'id\' => \'361\',
          \'delta\' => 0,
          \'property\' => \'value\',
          \'module\' => \'field_collection\',
          \'field_name\' => \'field_disease\',
          \'langcode\' => \'und\',
          \'uuid\' => \'efab70d0-08ed-4d53-8952-8220fca37d7f\',
        ),
        array(
          \'type\' => \'user\',
          \'id\' => \'426\',
          \'delta\' => 0,
          \'property\' => \'uid\',
          \'module\' => \'node\',
          \'uuid\' => \'10782d1b-75df-4cd6-9b4b-ec3499b45090\',
        ),
        array(
          \'type\' => \'user\',
          \'id\' => \'426\',
          \'delta\' => 0,
          \'property\' => \'revision_uid\',
          \'module\' => \'node\',
          \'uuid\' => \'10782d1b-75df-4cd6-9b4b-ec3499b45090\',
        ),
      ),
    ),
)',
);
  return $node_export;
}
