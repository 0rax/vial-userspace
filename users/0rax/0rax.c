#include QMK_KEYBOARD_H
#include "0rax.h"
#include "rgbflags.h"

// Placeholder to allow per keyboard processing of event without overwriting the global `process_record_user` set here (https://docs.qmk.fm/features/feature_userspace#customized-functions)
__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

// Macro handling & definitions (https://docs.qmk.fm/#/feature_macros)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  static bool grave_esc_was_shifted = false;

  switch (keycode) {
    case RGB_UK:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_flag_uk();
        #endif
      }
      return false;
    case RGB_FR:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_flag_fr();
        #endif
      }
      return false;
    case K_GESC: {
      uint8_t shifted = get_mods() & GRAVE_MODS;
      if (record->event.pressed) {
        grave_esc_was_shifted = shifted;
        add_key(shifted ? KC_GRAVE : KC_ESCAPE);
      } else {
        del_key(grave_esc_was_shifted ? KC_GRAVE : KC_ESCAPE);
      }
      send_keyboard_report();
      break;
    }
    case K_RESET: {
      // Set RGB underglow to red and put keyboard in RESET mode
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable_noeeprom();
          rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
          rgblight_sethsv_noeeprom(0, 255, 255);
        #endif
        reset_keyboard();
      }
      return false;
    }
  }
  // Return in process_record_user tels QMK how to process the event, if set to
  // true, the process will handle the press/release events normally after any
  // action taken here. Setting it to false will prevent any further processing
  // of the keypress event.
  return process_record_keymap(keycode, record);
};
