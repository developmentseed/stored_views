<?php

class stored_views_views_handler_field_title extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['path'] = 'path';
    $this->additional_fields['arguments'] = 'arguments';
    $this->additional_fields['filters'] = 'filters';
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['link_to_view'] = array('default' => FALSE);
    return $options;
  }

  /**
   * Provide link to node option
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['link_to_view'] = array(
      '#title' => t('Link this field to its view'),
      '#description' => t('This will override any other link you have set.'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_view']),
    );
  }

  /**
   * Custom version of l() which only attaches the active class for pages with fully identical query strings.
   */
  function l($text, $path, $options = array()) {
    global $language;

    // Merge in defaults.
    $options += array(
        'attributes' => array(),
        'html' => FALSE,
      );

    // Append active class.
    $matches = TRUE;
    if (!empty($options['query'])) {
      foreach ($options['query'] as $k => $v) {
        if (!isset($_GET[$k]) || $_GET[$k] != $v) {
          $matches = FALSE;
        }
      }
    }
    if ((($path == $_GET['q'] && $matches) || ($path == '<front>' && drupal_is_front_page())) &&
        (empty($options['language']) || $options['language']->language == $language->language)) {
      if (isset($options['attributes']['class'])) {
        $options['attributes']['class'] .= ' active';
      }
      else {
        $options['attributes']['class'] = 'active';
      }
    }

    // Remove all HTML and PHP tags from a tooltip. For best performance, we act only
    // if a quick strpos() pre-check gave a suspicion (because strip_tags() is expensive).
    if (isset($options['attributes']['title']) && strpos($options['attributes']['title'], '<') !== FALSE) {
      $options['attributes']['title'] = strip_tags($options['attributes']['title']);
    }

    return '<a href="'. check_url(url($path, $options)) .'"'. drupal_attributes($options['attributes']) .'>'. ($options['html'] ? $text : check_plain($text)) .'</a>';
  }

  function render($values) {
    $path = $values->{$this->aliases['path']};
    $arguments = unserialize($values->{$this->aliases['arguments']});
    $filters = unserialize($values->{$this->aliases['filters']});

    if (is_array($arguments) && count($arguments)) {
      $path .= '/'. implode('/', $arguments);
    }

    return $this->l($values->{$this->field_alias}, $path, array('query' => $filters));
  }
}
