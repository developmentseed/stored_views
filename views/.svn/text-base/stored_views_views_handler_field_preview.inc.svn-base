<?php

/**
 * Offers the view's displays as a choice for rendering a preview of the view.
 */
class stored_views_views_handler_field_preview extends views_handler_field {

  protected $view_name, $arguments, $filters;
  
  /**
   * Options definitions.
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['displays'] = array('default' => 'preview', 'translatable' => FALSE);

    return $options;
  }

  /**
   * Options form callback.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['displays'] = array(
      '#type' => 'textfield',
      '#title' => t('Displays'),
      '#default_value' => $this->options['displays'],
      '#description' => t('The name(s), separated by commas, of the displays to use for preview. For exposed filters to work, the display has to be an attachment and "Inherit exposed filters" has to be enabled.'),
    );
  }

  /**
   * Add view, arguments and filters field.
   */
  function query() {
    $this->ensure_my_table();

    $this->view_name = $this->query->add_field($this->table_alias, 'view');
    $this->arguments = $this->query->add_field($this->table_alias, 'arguments');
    $this->filters = $this->query->add_field($this->table_alias, 'filters');

    $this->add_additional_fields();
  }

  /**
   * Override render().
   */
  function render($values) {
    $view_name = $values->{$this->view_name};
    $arguments = unserialize($values->{$this->arguments});
    $filters = unserialize($values->{$this->filters});
    $displays = preg_split('/\s*,\s*/', $this->options['displays']);

    // Render selected displays.
    $output = '';
    if (is_array($displays) && count($displays)) {
      foreach ($displays as $i => $display_title) {
        $view = views_get_view($view_name);
        foreach ($view->display as $id => $display) {
          if ($display->display_title == $display_title) {
            $view->set_exposed_input($filters); 
            $output .= $view->preview($id, $arguments);
            unset($view);
            break;
          }
        }
      }

      if (!empty($output)) {
        return $output;
      }
    }
    return check_plain(t('<No preview available>'));
  }
}