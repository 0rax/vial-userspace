#include QMK_KEYBOARD_H
#include <0rax.h>

// Layer definitions (https://docs.qmk.fm/#/keymap)
enum id75_layers {
  _BL,
  _FL,
};

// Keymaps definition for each layer (https://docs.qmk.fm/#/keymap?id=layers-and-keymaps)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // _BL: Base Layer
  // .-----------------------------------------------------------------------------------------.
  // | ESC`|  1  |  2  |  3  |  4  |  5  |  -  |  ~  |  =  |  6  |  7  |  8  |  9  |  0  | BSPC|
  // |-----------------------------------------------------------------------------------------|
  // | TAB |  Q  |  W  |  E  |  R  |  T  |  [  |  \  |  ]  |  Y  |  U  |  I  |  O  |  P  |  '  |
  // |-----------------------------------------------------------------------------------------|
  // | BSPC|  A  |  S  |  D  |  F  |  G  | HOME| DEL | PG↑ |  H  |  J  |  K  |  L  |  ;  |ENTER|
  // |-----------------------------------------------------------------------------------------|
  // | LSFT|  Z  |  X  |  C  |  V  |  B  | END | UP↑ | PG↓ |  N  |  M  |  ,  |  .  |  /  | RSFT|
  // |-----------------------------------------------------------------------------------------|
  // | LCTL| FN  | LGUI| LALT|SPACE|SPACE| LF← | DW↓ | RG→ |SPACE|SPACE| RALT| RGUI| FN  | RCTL|
  // '-----------------------------------------------------------------------------------------'
 [_BL] = LAYOUT_ortho_5x15(
    K_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_NUHS,  KC_EQL, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_NUBS, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT, \
    KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_DEL,  KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_UP,   KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_LCTL, MO(_FL), KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC,  KC_SPC,  KC_RALT, KC_RGUI, MO(_FL), KC_RCTL  ),

  // _FL: Function Layer
  // .-----------------------------------------------------------------------------------------.
  // |RESET| F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 | F13 | DEL |
  // |-----------------------------------------------------------------------------------------|
  // |     |     |     |     |     |     |RGBUK|RGBFR|     |     |     |     |     |     |     |
  // |-----------------------------------------------------------------------------------------|
  // | DEL |     |     |VOLM↓|VMUTE|VOLM↑|RGBMD|RGBTG|     |MED◂◂|MED▮▮|MED▸▸|     |     |ENTER|
  // |-----------------------------------------------------------------------------------------|
  // | LSFT|     | CUT | COPY|PASTE|     |RGBH↑|RGBB↑|RGBS↑|     |     |     |     |     | RSFT|
  // |-----------------------------------------------------------------------------------------|
  // | LCTL| FN  | LGUI| LALT|SPACE|SPACE|RGBH↓|RGBB↓|RGBS↓|SPACE|SPACE| RALT| RGUI| FN  | RCTL|
  // '-----------------------------------------------------------------------------------------'
 [_FL] = LAYOUT_ortho_5x15(
    K_RESET, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,  KC_DEL,  \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RGB_UK,  RGB_FR,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   \
    KC_DEL,  KC_NO,   KC_NO,   KC_VOLD, KC_MUTE, KC_VOLU, RGB_MOD, RGB_TOG, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,   KC_NO,   KC_NO,   KC_ENT,  \
    KC_LSFT, KC_NO,   KC_CUT,  KC_COPY, KC_PASTE,KC_NO,   RGB_HUI, RGB_VAI, RGB_SAI, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RSFT, \
    KC_LCTL, KC_LGUI, KC_LALT, MO(_FL), KC_SPC,  KC_SPC,  RGB_HUD, RGB_VAD, RGB_SAD, KC_SPC,  KC_SPC,  MO(_FL), KC_RALT, KC_RGUI, KC_RCTL  ),
};
