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
#include "keymap_jp.h"
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

const key_override_t unds_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_0,    JP_UNDS);
const key_override_t pipe_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSLS, JP_PIPE);
const key_override_t coln_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SCLN, JP_COLN);
const key_override_t tild_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_GRV,  JP_ASTR);
const key_override_t plus_key_override = ko_make_with_layers_and_negmods(0, KC_GRV, JP_PLUS, ~0, (uint8_t) MOD_MASK_SHIFT);
const key_override_t bsls_key_override = ko_make_with_layers_and_negmods(0, KC_BSLS, JP_YEN, ~0, (uint8_t) MOD_MASK_SHIFT);

const key_override_t **key_overrides = (const key_override_t *[]){
  &unds_key_override,
  &pipe_key_override,
  &coln_key_override,
  &tild_key_override,
  &plus_key_override,
  &bsls_key_override,
  NULL
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE ,
  LOWER,
  AT_TS,
  SP_SF,
  SP_HK,
  SP_MW,
  SP_PM,
};

static bool is_pc = false;
static bool is_timer = false;
static bool is_not_pressed_key = false;
static bool is_sp_hk_pressed = false;
static bool is_sp_hf_pressed = false;

#define _QWERTY 0
#define _LOWER 1

#define MO_LO MO(_LOWER)

// KC_MHEN KC_HENK
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_DEL,  \
    KC_APP,  KC_LGUI, KC_LALT, XXXXXXX, SP_SF,   KC_SPC,  MO_LO,   XXXXXXX,          JP_LBRC, JP_RBRC, XXXXXXX  \
  ),
  [_LOWER] = LAYOUT(
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
    KC_INS,  _______, JP_AT,   JP_CIRC, KC_BSLS, _______, XXXXXXX, XXXXXXX, XXXXXXX, JP_ASTR, JP_PLUS, \
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    S(KC_CAPS),_______,_______,XXXXXXX, SP_HK,   KC_BSPC, _______, XXXXXXX,          AT_TS,   SP_PM,   XXXXXXX  \
  ),
};

void keyboard_post_init_user(void) {
  // Enable the LED layers
/*   rgblight_reload_from_eeprom();
  rgblight_disable_noeeprom(); */
  //key_override_on();
}

void jamming(void) {
  tap_code(KC_LEFT);
  wait_ms(250);
}

void matrix_scan_user(void) {
  if (is_timer) {
    jamming();
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SP_PM:
      if (record->event.pressed) {
        is_pc = !is_pc;
      }
      break;

    case SP_MW:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_TAB);
      } else {
        unregister_code(KC_LALT);
      }
      is_not_pressed_key = false;
      break;

    case SP_SF:
      if (record->event.pressed) {
        is_not_pressed_key = true;
        is_sp_hf_pressed = true;
        if (is_pc) {
          tap_code(KC_MHEN);
        } else {
          tap_code(KC_LANG2);
        }
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
        // if (is_not_pressed_key) {
        //   tap_code(KC_MHEN);
        // }
        is_sp_hf_pressed = false;
        is_not_pressed_key = false;
      }
      break;

    case SP_HK:
      if (record->event.pressed) {
        is_not_pressed_key = true;
        is_sp_hk_pressed = true;
      } else {
        if (is_not_pressed_key) {
          if (is_pc) {
            tap_code(KC_HENK);
          } else {
            tap_code(KC_LANG1);
          }
        }
        is_sp_hk_pressed = false;
        is_not_pressed_key = false;
      }
      break;

    case KC_SPC:
      if (! is_sp_hf_pressed) {
        break;
      }
      if (record->event.pressed) {
        tap_code(KC_BSPC);
        is_not_pressed_key = false;
        return false;
      }

    case KC_LEFT:
      if (! is_sp_hk_pressed) {
        break;
      }
      if (record->event.pressed) {
        tap_code(KC_HOME);
        is_not_pressed_key = false;
        return false;
      }

    case KC_RGHT:
      if (! is_sp_hk_pressed) {
        break;
      }
      if (record->event.pressed) {
        tap_code(KC_END);
        is_not_pressed_key = false;
        return false;
      }

    case KC_UP:
      if (! is_sp_hk_pressed) {
        break;
      }
      if (record->event.pressed) {
        tap_code(KC_PGUP);
        is_not_pressed_key = false;
        return false;
      }

    case KC_DOWN:
      if (! is_sp_hk_pressed) {
        break;
      }
      if (record->event.pressed) {
        tap_code(KC_PGDN);
        is_not_pressed_key = false;
        return false;
      }

    case KC_LCTL:
      if (record->event.pressed) {
        is_timer = false;
      }
      break;

    case AT_TS:
      if (record->event.pressed) {
        is_timer = true;
      }
      break;

    default:
      if (record->event.pressed) {
        is_not_pressed_key = false;
      }
      break;
  }
  return true;
}
