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
  // | ESC`|  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  `  | BSPC|
  // |-----------------------------------------------------------------------------------------|
  // | TAB |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |ENTER| PG↑ |
  // |-----------------------------------------------------------------------------------------|
  // | BSPC|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  "  |  #  |ENTER| PG↓ |
  // |-----------------------------------------------------------------------------------------|
  // | LSFT|  \  |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | RSFT| UP↑ | DEL |
  // |-----------------------------------------------------------------------------------------|
  // | LCTL| FN  | LGUI| LALT|SPACE|SPACE|SPACE|SPACE|SPACE| RALT| RGUI| FN  | LF← | DW↓ | RG→ |
  // '-----------------------------------------------------------------------------------------'
 [_BL] = LAYOUT_ortho_5x15(
    K_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_GRAVE,KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_ENT,  KC_PGUP, \
    KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,  KC_PGDN, \
    OSM_SFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_DEL,  \
    KC_LCTL, MO(_FL), KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_RALT, KC_RGUI, MO(_FL), KC_LEFT, KC_DOWN, KC_RGHT  ),

  // _FL: Function Layer
  // .-----------------------------------------------------------------------------------------.
  // | ESC`| F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |RESET| DEL |
  // |-----------------------------------------------------------------------------------------|
  // |     |     |     |     |     |     |     |     |     |     |     |     |     |ENTER| HOME|
  // |-----------------------------------------------------------------------------------------|
  // | DEL |RGBUK|RGBFR|VOLM↓|VMUTE|VOLM↑|MED◂◂|MED▮▮|MED▸▸|     |     |     |     |ENTER| END |
  // |-----------------------------------------------------------------------------------------|
  // | LSFT|RGBTG|RGBMD| CUT | COPY|PASTE|RGBH↑|RGBH↓|RGBS↑|RGBS↑|RGBB↑|RGBB↓| RSFT| UP↑ | BSPC|
  // |-----------------------------------------------------------------------------------------|
  // | LCTL| FN  | LGUI| LALT|SPACE|SPACE|SPACE|SPACE|SPACE| RALT| RGUI| FN  | LF← | DW↓ | RG→ |
  // '-----------------------------------------------------------------------------------------'
 [_FL] = LAYOUT_ortho_5x15(
    K_GESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  K_RESET, KC_DEL,  \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_ENT,  KC_HOME, \
    KC_BSPC, RGB_UK,  RGB_FR,  KC_VOLD, KC_MUTE, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_ENT,  KC_END,  \
    OSM_SFT, RGB_TOG, RGB_MOD, KC_CUT,  KC_COPY, KC_PASTE,RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_RSFT, KC_UP,   KC_BSPC, \
    KC_LCTL, MO(_FL), KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_RALT, KC_RGUI, MO(_FL), KC_LEFT, KC_DOWN, KC_RGHT  ),
};
