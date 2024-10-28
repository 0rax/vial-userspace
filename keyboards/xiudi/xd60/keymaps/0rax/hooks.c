#include QMK_KEYBOARD_H

// Keyboard Initialization hook (https://docs.qmk.fm/#/custom_quantum_functions?id=keyboard-post-initialization-code)
void keyboard_post_init_user(void)
{
  rgblight_disable_noeeprom(); // Disable RGB Lighting by default
  // rgblight_mode(1);       // Set RGB Mode to PLAIN
  // rgblight_sethsv_blue(); // Set RGB Color to BLUE
}

// // Layer Change hook (https://docs.qmk.fm/#/custom_quantum_functions?id=layer-change-code)
// uint32_t layer_state_set_user(uint32_t state) {
//     // Change color of the underglow based on the current layer (test code)
//     switch (biton32(state)) {
//     case _BL:
//         rgblight_setrgb (0x00,  0x00, 0xFF);
//         break;
//     case _FL:
//         rgblight_setrgb (0xFF,  0x00, 0x00);
//         break;
//     default: // for any other layers
//         rgblight_setrgb (0x00,  0xFF, 0xFF);
//         break;
//     }
//   return state;
// }

// EXTRA: RGB Underglow based on layer (https://docs.qmk.fm/#/custom_quantum_functions?id=example-layer_state_set_-implementation)
// EXTRA: RGB Lighting setup (https://docs.qmk.fm/#/feature_rgblight)
