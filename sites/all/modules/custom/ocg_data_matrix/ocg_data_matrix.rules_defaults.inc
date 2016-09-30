<?php
/**
 * @file
 * ocg_data_matrix.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ocg_data_matrix_default_rules_configuration() {
  $items = array();
  $items['rules_redirect_after_saving_disease_content'] = entity_import('rules_config', '{ "rules_redirect_after_saving_disease_content" : {
      "LABEL" : "Redirect after saving Disease content",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : {
        "node_insert--disease" : { "bundle" : "disease" },
        "node_update--disease" : { "bundle" : "disease" }
      },
      "DO" : [ { "redirect" : { "url" : "programs\\/cgci\\/data-matrix" } } ]
    }
  }');
  $items['rules_redirect_data_matrix_editor_after_login'] = entity_import('rules_config', '{ "rules_redirect_data_matrix_editor_after_login" : {
      "LABEL" : "Redirect Data Matrix Editor After Login",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_login" : [] },
      "IF" : [
        { "NOT text_matches" : {
            "text" : [ "site:current-page:path" ],
            "match" : "^user\\/reset\\/",
            "operation" : "regex"
          }
        },
        { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "6" : "6" } } } }
      ],
      "DO" : [ { "redirect" : { "url" : "programs\\/cgci\\/data-matrix" } } ]
    }
  }');
  return $items;
}
