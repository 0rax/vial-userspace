#include QMK_KEYBOARD_H

// Layer definitions (https://docs.qmk.fm/#/keymap)
enum fourxfour_layers {
  _BL,
  _FL,
  _AL,
  _ML,
};

// TapDance keys name and definition (https://docs.qmk.fm/#/feature_tap_dance)
enum {
  EQENT,
  BL_PSLS,
  FL_PAST,
  AL_PMNS,
  ML_PPLS,
};

tap_dance_action_t tap_dance_actions[] = {
  [EQENT]   = ACTION_TAP_DANCE_DOUBLE(KC_PEQL, KC_PENT),
  [BL_PSLS] = ACTION_TAP_DANCE_LAYER_MOVE(KC_PSLS, _BL),
  [FL_PAST] = ACTION_TAP_DANCE_LAYER_MOVE(KC_PAST, _FL),
  [AL_PMNS] = ACTION_TAP_DANCE_LAYER_MOVE(KC_PMNS, _AL),
  [ML_PPLS] = ACTION_TAP_DANCE_LAYER_MOVE(KC_PPLS, _ML),
};

// Keymaps definition for each layer (https://docs.qmk.fm/#/keymap?id=layers-and-keymaps)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // _BL: Base Layer
  // ,-----------------------.
  // |  7  |  8  |  9  |/(BL)|
  // |-----+-----+-----+-----|
  // |  4  |  5  |  6  |*(FL)|
  // |-----+-----+-----+-----|
  // |  1  |  3  |  3  |-(AL)|
  // |-----+-----+-----+-----|
  // |  0  |  .  | =(⏎)|+(ML)|
  // `-----------------------'
  [_BL] = LAYOUT_ortho_4x4(
    KC_P7,    KC_P8,    KC_P9,     TD(BL_PSLS), \
    KC_P4,    KC_P5,    KC_P6,     TD(FL_PAST), \
    KC_P1,    KC_P2,    KC_P3,     TD(AL_PMNS), \
    KC_P0,    KC_PDOT,  TD(EQENT), TD(ML_PPLS)  ),
  // _FL: Function Layer
  // ,-----------------------.
  // | F1  | F2  | F3  | _BL |
  // |-----+-----+-----+-----|
  // | F4  | F5  | F6  | _FL |
  // |-----+-----+-----+-----|
  // | F7  | F8  | F9  | _AL |
  // |-----+-----+-----+-----|
  // | F10 | F11 | F12 | _ML |
  // `-----------------------'
  [_FL] = LAYOUT_ortho_4x4(
    KC_F1,    KC_F2,    KC_F3,  TO(_BL), \
    KC_F4,    KC_F5,    KC_F6,  TO(_FL), \
    KC_F7,    KC_F8,    KC_F9,  TO(_AL), \
    KC_F10,   KC_F11,   KC_F12, TO(_ML)  ),
  // _AL: Arrow Layer
  // ,-----------------------.
  // |     |     |     | _BL |
  // |-----+-----+-----+-----|
  // | PG↑ | UP↑ | PG↓ | _FL |
  // |-----+-----+-----+-----|
  // | LF← | DW↓ | RG→ | _AL |
  // |-----+-----+-----+-----|
  // |     |     |     | _ML |
  // `-----------------------'
  [_AL] = LAYOUT_ortho_4x4(
    KC_NO,    KC_NO,    KC_NO,   TO(_BL), \
    KC_PGUP,  KC_UP,    KC_PGDN, TO(_FL), \
    KC_LEFT,  KC_DOWN,  KC_RGHT, TO(_AL), \
    KC_NO,    KC_NO,    KC_NO,   TO(_ML)  ),
  // _ML: Mouse Layer
  // ,-----------------------.
  // |MWHL↑|MBTN3|MWHL↓| _BL |
  // |-----+-----------+-----|
  // |MBTN1| MO↑ |MBTN2| _FL |
  // |-----+-----+-----+-----|
  // | MO← | MO↓ | MO→ | _AL |
  // |-----+-----+-----+-----|
  // |MACL1|MACL2|MACL3| _ML |
  // `-----------------------'
  [_ML] = LAYOUT_ortho_4x4(
    KC_WH_U,  KC_BTN3,  KC_WH_D, TO(_BL), \
    KC_BTN1,  KC_MS_U,  KC_BTN2, TO(_FL), \
    KC_MS_L,  KC_MS_D,  KC_MS_R, TO(_AL), \
    KC_ACL0,  KC_ACL1,  KC_ACL2, TO(_ML)  ),
};
