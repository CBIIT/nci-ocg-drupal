<?php
/**
 * @file
 * ocg_news_publications_blocks.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ocg_news_publications_blocks_default_rules_configuration() {
  $items = array();
  $items['rules_change_news_item_values'] = entity_import('rules_config', '{ "rules_change_news_item_values" : {
      "LABEL" : "Change News Item Values",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "news_item" : { "label" : "News Item", "type" : "node" } },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "news-item" ], "field" : "field_home_page_feature" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "news-item:field-home-page-feature" ], "value" : "0" } }
      ]
    }
  }');
  $items['rules_change_publications_item_values'] = entity_import('rules_config', '{ "rules_change_publications_item_values" : {
      "LABEL" : "Change Publications Item Values",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "publication_item" : { "label" : "Publication Item", "type" : "node" } },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "publication-item" ], "field" : "field_home_page_feature" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "publication-item:field-home-page-feature" ], "value" : "0" } }
      ]
    }
  }');
  $items['rules_changed_featured_news_or_publication'] = entity_import('rules_config', '{ "rules_changed_featured_news_or_publication" : {
      "LABEL" : "Changed Featured News or Publication",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert" : [], "node_update" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "news" : "news", "publication" : "publication" } }
          }
        },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_home_page_feature" } },
        { "data_is" : { "data" : [ "node:field-home-page-feature" ], "value" : "1" } }
      ],
      "DO" : [
        { "entity_query" : {
            "USING" : {
              "type" : "node",
              "property" : "type",
              "value" : "news",
              "limit" : "1000"
            },
            "PROVIDE" : { "entity_fetched" : { "news_items" : "News Items" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "news-items" ] },
            "ITEM" : { "news_item" : "News item" },
            "DO" : [
              { "component_rules_change_news_item_values" : { "news_item" : [ "news_item" ] } }
            ]
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "node",
              "property" : "type",
              "value" : "publication",
              "limit" : "1000"
            },
            "PROVIDE" : { "entity_fetched" : { "publications" : "Publications" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "publications" ] },
            "ITEM" : { "publication_item" : "Publication item" },
            "DO" : [
              { "component_rules_change_publications_item_values" : { "publication_item" : [ "publication_item" ] } }
            ]
          }
        },
        { "data_set" : { "data" : [ "node:field-home-page-feature" ], "value" : "1" } }
      ]
    }
  }');
  return $items;
}
