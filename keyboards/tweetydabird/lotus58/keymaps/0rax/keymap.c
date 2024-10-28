// Copyright 2022 Markus Knutsson (@TweetyDaBird)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#define ____ KC_TRNS

#ifdef AUTO_SHIFT_ENABLE

void keyboard_post_init_user(void) {
    autoshift_disable();
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MPLY, KC_MPLY, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,
        KC_NUHS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,	KC_QUOT,
        LCTL_T(KC_LEFT), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_DOWN, KC_UP,  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RCTL_T(KC_RIGHT),
        KC_DEL, TG(1), LALT_T(KC_LGUI),	LSFT_T(KC_SPACE), RSFT_T(KC_ENTER), RALT_T(KC_APP), TG(2), KC_BSPC
    ),

    [1] = LAYOUT(
        ____, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, ____, ____, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____, KC_PGDN, KC_PGUP, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____, ____, ____
    ),

    [2] = LAYOUT(
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____, ____, ____
    ),

    [3] = LAYOUT(
        QK_BOOT, ____, ____, ____, NK_TOGG, AC_TOGG, ____, ____, ____, ____, ____, RGB_VAI, RGB_VAD, RGB_TOG,
        QK_RBT, ____, ____, ____, ____, ____, ____, ____, ____, RGB_HUI, RGB_HUD, RGB_M_P,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, RGB_SAI, RGB_SAD, RGB_M_B,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, RGB_SPI, RGB_SPD, RGB_M_R,
        ____, ____, ____, ____, ____, ____, ____, ____
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;
}

static void render_logo(void) {
    static const char PROGMEM logo[] = {
        0x8A, 0x8B, 0x8B, 0x8B, 0x8B, 0x8B, 0x8B, 0x8B, 0x8B, 0x8C,
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9,
        0x9F, 0x8B, 0x8B, 0x8B, 0x8B, 0x8B, 0x8B, 0x8B, 0x8B, 0xBF,
        0xAA, ' ',  'L',  'o',  't',  'u',  's',  0xAB, ' ',  0xAC,
        // 0xAA, 'L',  'o',  't',  'u',  's',  ' ',  '5',  '8',  0xAC,
        // 0xCA, 0xCB, 0xCB, 0xCB, 0xCB, 0xCB, 0xCB, 0xCB, 0xCB, 0xCC, 0x00
        0x9F, 0x8B, 0x8B, 0x8B, 0x8B, 0x8B, 0x8B, 0x8B, 0x8B, 0xBF, 0x00
    };

    oled_write_P(logo, false);
}

static void render_layer(void) {
    static const char PROGMEM title[] = {
        ' ', ' ', 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, ' ', ' ', 0x00
    };
    static const char PROGMEM layer_text[4][21] = {
        [0] = {
            0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96,
            0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0x00
        },
        [1] = {
            0x97, 0x98, 0xD0, 0xD1, 0xCD, ' ',  0x91, 0x92, 0xD4, 0xD5,
            0xB7, 0xB8, 0xD2, 0xD3, 0xCE, 0xCF, 0xB1, 0xB2, 0xD6, 0xD7, 0x00
        },
        [2] = {
            0xCD, ' ',  0xD0, 0xD1, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
            0xCE, 0xCF, 0xD2, 0xD3, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0x00
        },
        [3] = {
            0x93, 0x94, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x91, 0x92,
            0xB3, 0xB4, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xB1, 0xB2, 0x00
        },
    };
    uint16_t layer = get_highest_layer(layer_state);
    oled_advance_page(true);
    oled_write_P(title, false);
    oled_advance_page(true);
    oled_write_P(layer_text[layer], false);
    oled_advance_page(true);
}

static void render_footer(void) {
    static const char PROGMEM footer[] = {
        // 0xDE, 0xDE, 0xDE, 0xDE, 0xDE, 0xDE, 0xDE, 0xDE, 0xDE, 0xDE, 0x00
        0xCA, 0xCB, ' ', '0', 'r', 'a', 'x', ' ', 0xCB, 0xCC, 0x00
    };
    oled_write_P(footer, false);
}

bool oled_task_user(void) {
    render_logo();
    oled_advance_page(true);
    render_layer();
    oled_advance_page(true);
    render_footer();
    return false;
}

#endif
