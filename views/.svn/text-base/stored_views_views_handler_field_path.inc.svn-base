<?php

/**
 * Special handler for serialized paths.
 */
class stored_views_views_handler_field_path extends views_handler_field {

  // Keep track of aliases.
  protected $arguments, $filters;

  /**
   * Add additional fields.
   */
  function query() {
    $this->ensure_my_table();

    $this->field_alias = $this->query->add_field($this->table_alias, $this->real_field);
    $this->arguments = $this->query->add_field($this->table_alias, 'arguments');
    $this->filters = $this->query->add_field($this->table_alias, 'filters');

    $this->add_additional_fields();
  }

  /**
   * Render path.
   */
  function render($values) {
    $path = $values->{$this->field_alias};
    $arguments = unserialize($values->{$this->arguments});
    $filters = unserialize($values->{$this->filters});

    if (is_array($arguments) && count($arguments)) {
      $path .= '/'. implode('/', $arguments);
    }

    $query = array();
    if (is_array($filters) && count($filters)) {
      foreach ($filters as $k => $v) {
        $query[] = "$k=$v";
      }
    }
   
    return $path .'?'. implode('&', $query);
  }
}