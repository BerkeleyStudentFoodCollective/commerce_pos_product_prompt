<?php

/**
 * @file
 * Rules integration for the product prompt module.
 *
 * @addtogroup rules
 * @{
 */

/**
 * Implements hook_rules_action_info().
 */
function commerce_pos_product_prompt_rules_action_info() {
  $actions = array();

  $actions['commerce_pos_product_prompt_add_product'] = array(
    'label' => t('Product Add Prompt'),
    'group' => t('Commerce POS'),
    'parameter' => array(
      'commerce_product' => array('type' => 'commerce_product', 'label' => t('Product', array(), array('context' => 'a drupal commerce product'))),
    ),
    'callbacks' => array( 'execute' => 'commerce_pos_product_prompt_rules_product_prompt'),
  );

  return $actions;
}

/**
 * Execute callback for product prompt action.
 */
function commerce_pos_product_prompt_rules_product_prompt($product, $action_settings, $rule_state, $action, $callback_type) {
  drupal_add_js(array(
  	'commercePosProductPrompt' => array(
  		'sku' => $product->sku,
  		'title' => $product->title)
  ), 'setting');
  drupal_add_js(drupal_get_path('module', 'commerce_pos_product_prompt') . '/commerce_pos_product_prompt.js', array('weight' => -100));
}