<?php

class stored_views_views_handler_field_link_delete extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['id'] = 'id';
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['text'] = array('default' => '', 'translatable' => TRUE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    if (user_access('manage stored views')) {
      $id = $values->{$this->aliases['id']};
      $text = $this->options['text'];
      return l($text, "stored-views/$id/delete", array('query' => drupal_get_destination()));
    }
  }
}
