// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _MEDIA,
    _FKEYS,
    _NUMPAD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───────────┐
     * │ E │           │
     * ├───┼───────────┤
     * │F9 │F10│F11│F12│
     * ├───┼───┼───┼───┤
     * │F5 │F6 │F7 │F8 │
     * ├───┼───┼───┼───┤
     * │F1 │F2 │F3 │F4 │
     * └───┴───┴───┴───┘
     */
    [_MEDIA] = LAYOUT(
        TO(_FKEYS),
        KC_VOLD, KC_MUTE, KC_VOLU, KC_BRIU,
        KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID,
        KC_CUT,  KC_COPY, KC_PSTE, KC_PSCR
    ),
    [_FKEYS] = LAYOUT(
        TO(_NUMPAD),
        KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_F5,   KC_F6,   KC_F7,   KC_F8,
        KC_F1,   KC_F2,   KC_F3,   KC_F4
    ),
    [_NUMPAD] = LAYOUT(
        TG(_NUMPAD),
        KC_7,    KC_8,    KC_9,    KC_PENT,
        KC_4,    KC_5,    KC_6,    KC_BSPC,
        KC_1,    KC_2,    KC_3,    KC_0
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_MEDIA] =    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_FKEYS] =    { ENCODER_CCW_CW(KC_BRID, KC_BRIU)  },
    [_NUMPAD] =   { ENCODER_CCW_CW(KC_WH_U, KC_WH_D)  },
};
#endif

#ifdef OLED_ENABLE

bool oled_task_user(void) {
    oled_write_P(PSTR("LK12 MacroPad\n"), false);
    oled_write_P(PSTR("====================="), false);
    switch (get_highest_layer(layer_state)) {
    case _MEDIA:
        oled_write_P(PSTR("Layer: Media\n"), false);
        oled_write_P(PSTR("Encod: Volume\n"), false);
        break;
    case _FKEYS:
        oled_write_P(PSTR("Layer: F Keys\n"), false);
        oled_write_P(PSTR("Encod: Brightness\n"), false);
        break;
    case _NUMPAD:
        oled_write_P(PSTR("Layer: Numpad\n"), false);
        oled_write_P(PSTR("Encod: Scroll\n"), false);
        break;
    }
    return false;
}

#endif
