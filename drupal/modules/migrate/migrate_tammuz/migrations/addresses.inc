<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



class AddressesMigration extends TammuzMigration {  // learn from https://www.drupal.org/node/1900640 about field collections migration
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Addresses as field-collection for individuals.');
    $this->dependencies = array('egg_donor');

    $this->source = new MigrateSourceCSV(
      $this->csv_path,
      array(),
      array('header_rows' => 1)
    );

    $this->destination = new MigrateDestinationFieldCollection(
      'field_address',
      array('host_entity_type' => 'crm_core_contact')
    );
    
    $source_keys = $arguments['keys'];

    $this->map = new MigrateSQLMap($this->machineName, $source_keys, MigrateDestinationFieldCollection::getKeySchema() );

    $this->addFieldMapping('host_entity_id', 'id')->sourceMigration('egg_donor');

    
    $this->addFieldMapping('field_address_details', 'address_country');
    $this->addFieldMapping('field_address_details:thoroughfare', 'address_street');
    $this->addFieldMapping('field_address_details:locality', 'address_city');
    $this->addFieldMapping('field_address_details:administrative_area', 'address_state');
  }
  
    public function prepareRow($row) {
	if (empty($row->address_country) || strtolower(trim($row->address_country))== 'israel')
	{
	    $row->address_country = "IL";
	}
    }
  
    public function prepare($entity, stdClass $row) {  //	https://www.drupal.org/node/2487618
//    parent::prepare($entity, $row);
    // The field collection migration code will have loaded an old revision of
    // the host entity; when it saves the host entity, old field values will
    // overwrite the current ones. Set the most recent revision as the host
    // entity instead.
    if ($hosts = entity_load($entity->hostEntityType(), array($entity->hostEntityId()))) {
      $host = reset($hosts);
      $entity->updateHostEntity($host);
    }
  }

}