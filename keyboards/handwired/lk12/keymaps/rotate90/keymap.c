// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _MEDIA,
    _FKEYS,
    _NUMPAD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MEDIA] = LAYOUT(
        TO(_FKEYS),
        KC_LEFT, KC_PGDN, KC_MPRV, KC_BRID,
        KC_DOWN, KC_UP,   KC_MPLY, KC_MUTE,
        KC_RGHT, KC_PGUP, KC_MNXT, KC_BRIU
    ),
    [_FKEYS] = LAYOUT(
        TO(_NUMPAD),
        KC_F1,   KC_F4,   KC_F7,   KC_F10,
        KC_F2,   KC_F5,   KC_F8,   KC_F11,
        KC_F3,   KC_F6,   KC_F9,   KC_F12
    ),
    [_NUMPAD] = LAYOUT(
        TG(_NUMPAD),
        KC_NUM,  KC_P1,    KC_P4,    KC_P7,
        KC_P0,   KC_P2,    KC_P5,    KC_P8,
        KC_PENT, KC_P3,    KC_P6,    KC_P9
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

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

static char PROGMEM oledMap[3][60+1] = {
    [_MEDIA] = {
        ' ',  ' ',  ' ',  ' ',  ' ',
        'L',  'A',  'Y',  'E',  'R',
        ' ',  'M',  'E',  'D',  ' ',
        ' ',  ' ',  ' ',  ' ',  ' ',
        'E',  'N',  'C',  'O',  'D',
        ' ',  'V',  'O',  'L',  ' ',
        ' ',  ' ',  ' ',  ' ',  ' ',
        ' ',  ' ',  ' ',  ' ',  ' ',
        0x0F, ' ',  'M',  ' ',  0x2A,
        0x11, ' ',  0x0E, ' ',  0x10,
        0x1F, ' ',  0x18, ' ',  0x1E,
        0x1B, ' ',  0x19, ' ',  0x1A,
        0x00
    },
    [_FKEYS] = {
        ' ',  ' ',  ' ',  ' ',  ' ',
        'L',  'A',  'Y',  'E',  'R',
        ' ',  'F',  'N',  ' ',  ' ',
        ' ',  ' ',  ' ',  ' ',  ' ',
        'E',  'N',  'C',  'O',  'D',
        ' ',  'B',  'R',  'I',  ' ',
        ' ',  ' ',  ' ',  ' ',  ' ',
        ' ',  ' ',  ' ',  ' ',  ' ',
        'A',  ' ',  'B',  ' ',  'C',
        '7',  ' ',  '8',  ' ',  '9',
        '4',  ' ',  '5',  ' ',  '6',
        '1',  ' ',  '2',  ' ',  '3',
        0x00
    },
    [_NUMPAD] = {
        ' ',  ' ',  ' ',  ' ',  ' ',
        'L',  'A',  'Y',  'E',  'R',
        ' ',  'N',  'U',  'M',  ' ',
        ' ',  ' ',  ' ',  ' ',  ' ',
        'E',  'N',  'C',  'O',  'D',
        ' ',  'S',  'C',  'L',  ' ',
        ' ',  ' ',  ' ',  ' ',  ' ',
        ' ',  ' ',  ' ',  ' ',  ' ',
        '7',  ' ', '8',  ' ', '9',
        '4',  ' ', '5',  ' ', '6',
        '1',  ' ', '2',  ' ', '3',
        0x09, ' ', '0',  ' ', 0x14,
        0x00
    }
};

bool oled_task_user(void) {
    oled_write_P(PSTR("====="), false);
    oled_write_P(PSTR("LK12*"), false);
    oled_write_P(PSTR("====="), false);

    uint16_t layer = get_highest_layer(layer_state);
    char* PROGMEM map = oledMap[layer];
    led_t state = host_keyboard_led_state();

    switch (layer) {
    case _NUMPAD:
        if (state.num_lock) {
            map[55] = 0x08;
        } else {
            map[55] = 0x07;
        }
        break;
    }

    oled_write_P(map, false);
    return false;
}

#endif
