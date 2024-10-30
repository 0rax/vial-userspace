#include QMK_KEYBOARD_H

// TapDance keys name and definition (https://docs.qmk.fm/#/feature_tap_dance)
enum {
  SLSBSPC,
  ASTDEL,
  MNSTAB,
  PLUSENT,
};

tap_dance_action_t tap_dance_actions[] = {
  [SLSBSPC] = ACTION_TAP_DANCE_DOUBLE(KC_PSLS, KC_BSPC),
  [ASTDEL]  = ACTION_TAP_DANCE_DOUBLE(KC_PAST, KC_DEL),
  [MNSTAB]  = ACTION_TAP_DANCE_DOUBLE(KC_PMNS, KC_TAB),
  [PLUSENT] = ACTION_TAP_DANCE_DOUBLE(KC_PPLS, KC_PENT),
};

// Keymaps definition for each layer (https://docs.qmk.fm/#/keymap?id=layers-and-keymaps)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // ,------------------------.
  // |  7  |  8  |  9  |/(Bpc)|
  // |-----+-----+-----+------|
  // |  4  |  5  |  6  |*(Del)|
  // |-----+-----+-----+------|
  // |  1  |  2  |  3  |-(Tab)|
  // |-----+-----+-----+------|
  // |  0  |  .  |  =  | +(⏎) |
  // `------------------------'
  [0] = LAYOUT_ortho_4x4(
    KC_P7,   KC_P8,   KC_P9,   TD(SLSBSPC),\
    KC_P4,   KC_P5,   KC_P6,   TD(ASTDEL), \
    KC_P1,   KC_P2,   KC_P3,   TD(MNSTAB), \
    KC_P0,   KC_PDOT, KC_PEQL, TD(PLUSENT) ),
};
