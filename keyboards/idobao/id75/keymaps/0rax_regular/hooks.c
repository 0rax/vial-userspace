#include QMK_KEYBOARD_H

// Keyboard Initialization hook (https://docs.qmk.fm/#/custom_quantum_functions?id=keyboard-post-initialization-code)
void keyboard_post_init_user(void)
{
  rgblight_enable_noeeprom();                              // Enable RGB Lighting by default
  rgblight_sethsv_noeeprom (255, 155, 128);                // Set brightness to half (128/255)
  rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 4); // Set RGB to Rainbow Swirl
}

// EXTRA: RGB Lighting setup (https://docs.qmk.fm/#/feature_rgblight)
