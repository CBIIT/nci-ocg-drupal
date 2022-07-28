<?php

/**
 * @file
 * Rules implementations for deploy addon next plans.
 */

/**
 * Implements hook_rules_action_info().
 */
function deploy_addon_next_rules_action_info() {
  return array(
    'deploy_addon_next_action_move_to_push_to_next' => array(
      'label' => t('Move an entity to Push to Next deployment plan'),
      'group' => t('Deploy'),
      'parameter' => array(
        'entity' => array(
          'type' => 'entity',
          'label' => t('Entity'),
          'description' => t('The Deploy Manager Entity that shall be moved to Push to Next deployment plan.'),
          'wrapped' => TRUE,
        ),
      ),
    ),
  );
}

/**
 * Action callback for "Move an entity to Push to Next deployment plan".
 *
 * @param object $dme
 *   The Deploy Manager Entity to be moved to push to next.
 */
function deploy_addon_next_action_move_to_push_to_next($dme) {
  // Remove from previous plan.
  $label = $dme->label();
  $dme->delete();
  drupal_set_message(t('Entity has been removed: @label', ['@label' => $label]));

  // Add to Push to next plan.
  $type = $dme->entity_type->value();
  $entity = entity_load_single($type, $dme->entity_id->value());
  deploy_manager_add_to_plan('push_to_next', $type, $entity);
  drupal_set_message(t('Entity @label has been moved to the Push to Next deployment plan.', array('@label' => $entity->title)));
}
