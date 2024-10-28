#ifndef USERSPACE_0RAX_H
#define USERSPACE_0RAX_H

// Defines when to send ESC and when to send GRAVE on GESC trigger
#define GRAVE_MODS (MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI)|MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))

// Macro keycode deinitions (https://docs.qmk.fm/#/feature_macros)
enum macro_keycodes {
  RGB_UK = SAFE_RANGE, // RGB Underglow UK Flag
  RGB_FR,              // RGB Underglow French Flag
  K_GESC,              // KC_ESC with KC_GRAVE on modifiers
  K_RESET,             // Reset keyboard when pressed
};

// One shot modifiers keycode aliases (https://docs.qmk.fm/#/feature_advanced_keycodes?id=one-shot-keys)
#define OSM_SFT OSM(MOD_LSFT) // Make KC_LSFT acts as KC_CAPS when pressed twice

#endif
