#include QMK_KEYBOARD_H

// Layer definitions (https://docs.qmk.fm/#/keymap)
enum dz60_layers {
  _BL,
  _FL,
};

// Keymaps definition for each layer (https://docs.qmk.fm/#/keymap?id=layers-and-keymaps)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // _BL: Base Layer
  // .-----------------------------------------------------------------------------------------.
  // | ESC`|  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  +  | BACKSPACE |
  // |-----------------------------------------------------------------------------------------|
  // | TAB    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |  Enter |
  // |---------------------------------------------------------------------------------|       |
  // | CAPS    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |  ~  |       |
  // |-----------------------------------------------------------------------------------------|
  // | SFT |  \  |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  <  |  >  |  ?  | SFT | UP↑ | DEL |
  // |-----------------------------------------------------------------------------------------|
  // | LCTL | LGUI | LALT |                 SPACE                | ALT | FN  | LF← | DW↓ | RG→ |
  // '-----------------------------------------------------------------------------------------'
  [_BL] = LAYOUT_60_iso_4th_row_all_1u(
    QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,           KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,                   \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_NUHS,           KC_ENT, \
    KC_LSFT,   KC_NUBS,   KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, KC_UP,KC_DEL, \
    KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,                          KC_RALT, MO(_FL), KC_LEFT, KC_DOWN,  KC_RIGHT ),

  // _FL: Function Layer
  // .-----------------------------------------------------------------------------------------.
  // |  `  | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |    DELETE |
  // |-----------------------------------------------------------------------------------------|
  // |        |     |     |     |     |     |     |     |     |     |     |     |     |  Enter |
  // |---------------------------------------------------------------------------------|       |
  // | CAPS    |VMUTE|VOLM↓|VOLM↑|     |     |     |MED▮▮|MED◂◂|MED▸▸|     |     |     |       |
  // |-----------------------------------------------------------------------------------------|
  // | SFT |     |     | CUT |COPY |PASTE|     |     |     |     |     |     |HOME | PG↑ | END |
  // |-----------------------------------------------------------------------------------------|
  // | LCTL | LGUI | LALT |                 SPACE                | ALT | FN  |     | PG↓ |     |
  // '-----------------------------------------------------------------------------------------'
  [_FL] = LAYOUT_60_iso_4th_row_all_1u(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_F12,           KC_DEL, \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,    KC_NO,                    \
    KC_CAPS, KC_MUTE,KC_VOLD,  KC_VOLU,  KC_NO,  KC_NO, KC_NO,  KC_MPLY,KC_MPRV, KC_MNXT,KC_NO,   KC_NO,    KC_NO,            KC_ENT, \
    KC_LSFT, KC_NO,   KC_NO,     KC_CUT,  KC_COPY,KC_PASTE,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,KC_HOME, KC_PGUP, KC_END, \
    KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,                          KC_RALT, MO(_FL), KC_NO,    KC_PGDN,  KC_NO  ),
};
