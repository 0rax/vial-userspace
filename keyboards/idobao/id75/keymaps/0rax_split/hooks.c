#include QMK_KEYBOARD_H

// Keyboard Initialization hook (https://docs.qmk.fm/#/custom_quantum_functions?id=keyboard-post-initialization-code)
void keyboard_post_init_user(void)
{
  rgblight_disable_noeeprom(); // Disable RGB Lighting by default
}

// EXTRA: RGB Lighting setup (https://docs.qmk.fm/#/feature_rgblight)
