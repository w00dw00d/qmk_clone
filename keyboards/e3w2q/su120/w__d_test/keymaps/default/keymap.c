/* Copyright 2019 e3w2q
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

/*
参考URL
# 概要
https://qiita.com/rai_suta/items/0376ed4ce6498bb85770

# キーオーバーライド
https://qiita.com/shela/items/9e5bd102a95a15d1b00c

# ファーム容量削り
https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/

# 公式
https://github.com/qmk/qmk_firmware/blob/master/docs/feature_key_overrides.md
https://github.com/qmk/qmk_firmware/blob/master/docs/feature_auto_shift.md
*/

//const key_override_t zero_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_0, JP_UNDS);
//const key_override_t smcn_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SCLN, JP_COLN);
//const key_override_t jyen_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSLS, JP_PIPE);

/* const key_override_t **key_overrides = (const key_override_t *[]){
  //&zero_key_override,
  &smcn_key_override,
  //&jyen_key_override,
  NULL
}; */

enum custom_keycodes {
  QWERTY = SAFE_RANGE ,
  LOWER,
};

#define _QWERTY 0
#define _LOWER 1

#define MO_LO MO(_LOWER)
#define MO_RA MO(_RAISE)

#define CL_PU C(KC_PGUP)
#define CL_PD C(KC_PGDN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_ESC,  KC_1, \
    KC_TAB,  KC_Q  \
  ),
  [_LOWER] = LAYOUT(
    KC_INS, KC_INS, \
    KC_INS, KC_INS \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  return true;
}

void ps2_mouse_moved_user(report_mouse_t *mouse_report) {
    pointing_device_set_report(mouse_report);
}
