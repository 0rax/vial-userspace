#include QMK_KEYBOARD_H

// RGB Underflow Flag FR
void rgblight_flag_fr(void)
{
  rgblight_mode_noeeprom(1);
  rgblight_sethsv_at(240, 255, 255, 0);
  rgblight_sethsv_at(240, 255, 255, 1);
  rgblight_sethsv_at(0, 0, 255, 2);
  rgblight_sethsv_at(0, 0, 255, 3);
  rgblight_sethsv_at(0, 255, 255, 4);
  rgblight_sethsv_at(0, 255, 255, 5);
}

// RGB Underflow Flag UK
void rgblight_flag_uk(void)
{
  rgblight_mode_noeeprom(1);
  rgblight_sethsv_at(240, 255, 255, 0);
  rgblight_sethsv_at(0, 0, 255, 1);
  rgblight_sethsv_at(0, 255, 255, 2);
  rgblight_sethsv_at(0, 255, 255, 3);
  rgblight_sethsv_at(0, 0, 255, 4);
  rgblight_sethsv_at(240, 255, 255, 5);
}
