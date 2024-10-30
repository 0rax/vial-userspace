#include QMK_KEYBOARD_H

// Keymaps definition for each layer (https://docs.qmk.fm/#/keymap?id=layers-and-keymaps)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // ,-----------------------------.
  // |NumLk|  =  |  /  |  *  | Bspc|
  // |-----+-----+-----+-----+-----|
  // |  7  |  8  |  9  |  -  | Del |
  // |-----+-----+-----+-----+-----|
  // |  4  |  5  |  6  |  +  | Tab |
  // |-----+-----+-----+-----+-----|
  // |  1  |  2  |  3  | Up  |Enter|
  // |-----+-----+-----+-----+-----|
  // |  0  |  .  |Left |Down |Right|
  // `-----------------------------'
  [0] = LAYOUT_ortho_5x5(
    KC_LNUM, KC_PEQL, KC_PSLS, KC_PAST, KC_BSPC, \
    KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_TAB,  \
    KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_RSFT, \
    KC_P1,   KC_P2,   KC_P3,   KC_UP,   KC_PENT, \
    KC_P0,   KC_PDOT, KC_LEFT, KC_DOWN, KC_RGHT  ),
};
