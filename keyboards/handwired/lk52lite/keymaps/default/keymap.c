// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _FUNC,
    _LOWER,
    _UPPER,
};

#define KC_FUNC MO(_FUNC)
#define KC_DROP MO(_LOWER)
#define KC_RAIS MO(_UPPER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    /* */ KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    /* */ KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    /* */ KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_FUNC, KC_DROP, KC_SPC,  /* */ KC_ENT,  KC_RAIS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
                          KC_MPLY, KC_CAPS, KC_ESC,           /* */          KC_BSPC, KC_DEL,  KC_PSCR
    ),
    [_FUNC] = LAYOUT(
        KC_F1,   KC_F2,   KC_3,    KC_F4,   KC_F5,   KC_F6,   /* */ KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_CAPS, _______, _______, _______, _______, _______, /* */ _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, /* */ _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, /* */ _______, _______, _______, _______, _______, _______,
                          _______,  _______, _______,          /* */          _______, _______, _______
    ),
    [_LOWER] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    /* */  KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
        _______, _______, _______, _______, _______, _______, /* */ _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, /* */ _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, /* */ _______, _______, _______, _______, _______, _______,
                          _______, _______, _______,          /* */          _______, _______, _______
    ),
    [_UPPER] = LAYOUT(
        S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), /* */ S(KC_7), S(KC_8), S(KC_9), S(KC_0), S(KC_MINS), S(KC_EQL),
        _______, _______, _______, _______, _______, _______, /* */ _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, /* */ _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, /* */ _______, _______, _______, _______, _______, _______,
                          _______, _______, _______,          /* */          _______, _______, _______
    )
};

void keyboard_post_init_user(void) {
    debug_enable=true;
    // debug_matrix=true;
    // debug_keyboard=true;
    // debug_mouse=true;
}
