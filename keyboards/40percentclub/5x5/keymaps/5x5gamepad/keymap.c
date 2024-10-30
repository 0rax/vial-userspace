#include QMK_KEYBOARD_H

// Keymaps definition for each layer (https://docs.qmk.fm/#/keymap?id=layers-and-keymaps)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // ,-----------------------------.
  // | Esc |  1  |  2  |  3  |  4  |
  // |-----+-----+-----+-----+-----|
  // | Tab |  Q  |  W  |  E  |  R  |
  // |-----+-----+-----+-----+-----|
  // |CapsL|  A  |  S  |  D  |  F  |
  // |-----+-----+-----+-----+-----|
  // |Shift|  Z  |  X  |  C  |  V  |
  // |-----+-----+-----+-----+-----|
  // |Ctrl |Meta | Alt |Space|Space|
  // `-----------------------------'
  [0] = LAYOUT_ortho_5x5(
    KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,  \
    KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,  \
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC ),
};
