<?php
/**
 * @file
 * ormil_activities.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ormil_activities_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_activity_date'
  $field_bases['field_activity_date'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'crm_core_activity',
    ),
    'field_name' => 'field_activity_date',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'granularity' => array(
        'day' => 'day',
        'hour' => 'hour',
        'minute' => 'minute',
        'month' => 'month',
        'second' => 0,
        'year' => 'year',
      ),
      'repeat' => 0,
      'timezone_db' => 'UTC',
      'todate' => '',
      'tz_handling' => 'site',
    ),
    'translatable' => 0,
    'type' => 'datetime',
  );

  // Exported field_base: 'field_activity_notes'
  $field_bases['field_activity_notes'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'crm_core_activity',
    ),
    'field_name' => 'field_activity_notes',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 1,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_activity_participants'
  $field_bases['field_activity_participants'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'crm_core_activity',
    ),
    'field_name' => 'field_activity_participants',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 1,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'target_bundles' => array(),
      ),
      'handler_submit' => 'Change handler',
      'target_type' => 'crm_core_contact',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}