<?php

/**
 * @file
 * Default rules configuration for Deploy Add-on Push to Next module.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function deploy_addon_next_default_rules_configuration() {
  $items = [];

  $items['rules_to_push_to_next_plan'] = entity_import('rules_config', '{ "rules_to_push_to_next_plan" : {
      "LABEL" : "Move entity to Push to Next deployment plan",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "deploy" ],
      "REQUIRES" : [ "deploy_addon_next" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "entity" : { "label" : "Entity", "type" : "deploy_manager_entities" } },
      "ACTION SET" : [
        { "deploy_addon_next_action_move_to_push_to_next" : { "entity" : [ "entity" ] } }
      ]
    }
  }');

  return $items;
}
