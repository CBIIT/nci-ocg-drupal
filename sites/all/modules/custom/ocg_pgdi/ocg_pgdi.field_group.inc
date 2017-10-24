<?php
/**
 * @file
 * ocg_pgdi.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ocg_pgdi_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cancer_type_descriptors|node|pgdi|form';
  $field_group->group_name = 'group_cancer_type_descriptors';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pgdi';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Project cancer type descriptors',
    'weight' => '7',
    'children' => array(
      0 => 'field_cancer_diagnosis',
      1 => 'field_icd_10_code',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Project cancer type descriptors',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-cancer-type-descriptors field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_cancer_type_descriptors|node|pgdi|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cancer_type|node|pgdi|form';
  $field_group->group_name = 'group_cancer_type';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pgdi';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Cancer Type',
    'weight' => '5',
    'children' => array(
      0 => 'field_cancer_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Cancer Type',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-cancer-type field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_cancer_type|node|pgdi|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_case_count_information|node|pgdi|form';
  $field_group->group_name = 'group_case_count_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pgdi';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Case Count Information',
    'weight' => '8',
    'children' => array(
      0 => 'field_organ_site_of_tumor',
      1 => 'field_number_of_cases_enrolled',
      2 => 'field_patient_age_range',
      3 => 'field_gender',
      4 => 'field_cohort_diversity',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Case Count Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-case-count-information field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_case_count_information|node|pgdi|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_information|node|pgdi|form';
  $field_group->group_name = 'group_contact_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pgdi';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '4',
    'children' => array(
      0 => 'field_project_pi',
      1 => 'field_technical_contact',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Contact Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-contact-information field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_contact_information|node|pgdi|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_information|node|pgdi|form';
  $field_group->group_name = 'group_project_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pgdi';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Project Information',
    'weight' => '3',
    'children' => array(
      0 => 'field_pgdi_project_status',
      1 => 'field_project_website',
      2 => 'field_is_the_project_data_availa',
      3 => 'field_are_collaborations_possibl',
      4 => 'field_data_website',
      5 => 'field_project_publication',
      6 => 'field_project_country',
      7 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Project Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-project-information field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_project_information|node|pgdi|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sample_count_information|node|pgdi|form';
  $field_group->group_name = 'group_sample_count_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'pgdi';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sample Count Information',
    'weight' => '9',
    'children' => array(
      0 => 'field_primary_tumor_sample',
      1 => 'field_normal_sample',
      2 => 'field_metastatic_sample',
      3 => 'field_wxs_data',
      4 => 'field_average_coverage',
      5 => 'field_paired_end_reads',
      6 => 'field_were_all_samples_sequenced',
      7 => 'field_number_of_cases_with_wxs',
      8 => 'field_what_was_the_achieved_aver',
      9 => 'field_capture_reagent_product_co',
      10 => 'field_number_of_cases_with_wgs_d',
      11 => 'field_average_coverage_for_each',
      12 => 'field_read_length',
      13 => 'field_identical_method_technolo',
      14 => 'field_number_of_cases_with_wgs',
      15 => 'field_achieved_average',
      16 => 'field_number_of_cases_with_targe',
      17 => 'field_location_of_the_bed_file',
      18 => 'field_was_clinical_outcome_data_',
      19 => 'field_is_the_outcome_data_availa',
      20 => 'field_was_tumor_rna_sequenced_',
      21 => 'field_how_many_cases_received_bo',
      22 => 'field_snp_based_copy_number_data',
      23 => 'field_other_molecular_data_avail',
      24 => 'field_date_these_data_submittted',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Sample Count Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-sample-count-information field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_sample_count_information|node|pgdi|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Cancer Type');
  t('Case Count Information');
  t('Contact Information');
  t('Project Information');
  t('Project cancer type descriptors');
  t('Sample Count Information');

  return $field_groups;
}
