<?php

/**
 * Implementation of hook_views_data().
 */
function stored_views_views_data() {
  $data = array();
  $data['stored_views']['table']['group'] = t('Stored views');
  $data['stored_views']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Stored view'),
    'help' => t('Build a view of stored views.'),
  );
  $data['stored_views']['created'] = array(
    'title' => t('Created'),
    'help' => t('Time when this view was stored.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  $data['stored_views']['title'] = array(
    'title' => t('Title'),
    'help' => t('The title of the page view'),
    'field' => array(
      'handler' => 'stored_views_views_handler_field_title',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['stored_views']['view'] = array(
    'title' => t('View'),
    'help' => t('The view name of the page view'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['stored_views']['display'] = array(
    'title' => t('Display'),
    'help' => t('The active display of the page view'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['stored_views']['path'] = array(
    'title' => t('Path'),
    'help' => t('The path of the view'),
    'field' => array(
      'handler' => 'stored_views_views_handler_field_path',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['stored_views']['status'] = array(
    'title' => t('Status'),
    'help' => t('The status of the view'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  $data['stored_views']['preview'] = array(
    'field' => array(
      'title' => t('Preview'),
      'help' => t('Pick a display of the view for rendering a preview of it.'),
      'handler' => 'stored_views_views_handler_field_preview',
    ),
  );
  $data['stored_views']['link_delete'] = array(
    'field' => array(
      'title' => t('Delete link'),
      'help' => t('Provide a link to delete a stored view.'),
      'handler' => 'stored_views_views_handler_field_link_delete',
    ),
  );

  return $data;
}

/**
 * Implementation of hook_views_handlers().
 */
function stored_views_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'stored_views') .'/views',
    ),
    'handlers' => array(
      // field handlers
      'stored_views_views_handler_field_title' => array(
        'parent' => 'views_handler_field',
      ),
      'stored_views_views_handler_field_path' => array(
        'parent' => 'views_handler_field',
      ),
      'stored_views_views_handler_field_preview' => array(
        'parent' => 'views_handler_field',
      ),
      'stored_views_views_handler_field_link_delete' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}
