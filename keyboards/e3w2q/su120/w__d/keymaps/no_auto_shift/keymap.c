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
// const key_override_t tild_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_GRV,  JP_ASTR);
// const key_override_t plus_key_override = ko_make_with_layers_and_negmods(0, KC_GRV, JP_PLUS, ~0, (uint8_t) MOD_MASK_SHIFT);
const key_override_t bsls_key_override = ko_make_with_layers_and_negmods(0, KC_BSLS, JP_YEN, ~0, (uint8_t) MOD_MASK_SHIFT);

const key_override_t **key_overrides = (const key_override_t *[]){
  &unds_key_override,
  &pipe_key_override,
  &coln_key_override,
  // &tild_key_override,
  // &plus_key_override,
  &bsls_key_override,
  NULL
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE ,
  LOWER,
  AT_TB,
  AT_TS,
  AT_TE,
  AT_PW,
  AT_RA,
};

static bool is_windows = true;
static bool is_timer = false;
static bool is_raise = false;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

#define MO_LO MO(_LOWER)
//#define MO_RA MO(_RAISE)

#define CL_PU C(KC_PGUP)
#define CL_PD C(KC_PGDN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
    MO_LO,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH, \
    KC_LCTL, KC_LGUI, KC_LALT, _______, KC_MHEN, KC_SPC,  KC_HENK, _______,          KC_LEFT, KC_DOWN, KC_RGHT  \
  ),
  [_LOWER] = LAYOUT(
    RESET,   AT_TS,   AT_TE,   AT_PW,   _______, _______, _______, _______, JP_LPRN, JP_RPRN, JP_CIRC, KC_BSLS, KC_BSPC, \
    KC_INS,  _______, _______, _______, _______, _______, _______, JP_LCBR, JP_RCBR, JP_PLUS, JP_ASTR, \
    _______, _______, _______, CL_PU,   CL_PD,   _______, _______, JP_LBRC, JP_RBRC, JP_AT,   JP_COLN, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______, \
    _______, _______, _______, _______, _______,   AT_TB, _______, _______,          KC_HOME, KC_PGDN, KC_END   \
  ),
  [_RAISE] = LAYOUT(
    KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, \
    AT_RA,   _______, _______, CL_PU,   CL_PD,   _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______, \
    _______, _______, _______, _______, _______,   AT_TB, _______, _______,          KC_HOME, KC_PGDN, KC_END   \
  ),
};

const uint16_t PROGMEM combo_f01[] = {KC_ESC, KC_1, COMBO_END};
const uint16_t PROGMEM combo_f02[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM combo_f03[] = {KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM combo_f04[] = {KC_3, KC_4, COMBO_END};
const uint16_t PROGMEM combo_f05[] = {KC_4, KC_5, COMBO_END};
const uint16_t PROGMEM combo_f06[] = {KC_5, KC_6, COMBO_END};
const uint16_t PROGMEM combo_f07[] = {KC_6, KC_7, COMBO_END};
const uint16_t PROGMEM combo_f08[] = {KC_7, KC_8, COMBO_END};
const uint16_t PROGMEM combo_f09[] = {KC_7, KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM combo_f10[] = {KC_9, KC_0, COMBO_END};
const uint16_t PROGMEM combo_f11[] = {KC_0, KC_MINS, COMBO_END};
const uint16_t PROGMEM combo_f12[] = {KC_MINS, KC_BSPC, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_UP, KC_SLSH, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(combo_f01, KC_F1),
  COMBO(combo_f02, KC_F2),
  COMBO(combo_f03, KC_F3),
  COMBO(combo_f04, KC_F4),
  COMBO(combo_f05, KC_F5),
  COMBO(combo_f06, KC_F6),
  COMBO(combo_f07, KC_F7),
  COMBO(combo_f08, KC_F8),
  COMBO(combo_f09, KC_F9),
  COMBO(combo_f10, KC_F10),
  COMBO(combo_f11, KC_F11),
  COMBO(combo_f12, KC_F12),
  COMBO(combo_del, KC_DEL)
};

void keyboard_post_init_user(void) {
  // Enable the LED layers
/*   rgblight_reload_from_eeprom();
  rgblight_disable_noeeprom(); */
  //key_override_on();
}

void jamming(void) {
  tap_code(KC_LEFT);
  wait_ms((rand() % 6 + 1) * 100);
}

void matrix_scan_user(void) {
  if (is_timer) {
    jamming();
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_MHEN:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      break;

    case AT_RA:
      is_raise = record->event.pressed;
      break;

    case KC_LEFT:
      if (is_raise) {
        if (record->event.pressed) {
          tap_code(KC_HOME);
        }
        return false;
      }
      break;
      
    case KC_UP:
      if (is_raise) {
        if (record->event.pressed) {
          tap_code(KC_PGUP);
        }
        return false;
      }
      break;
      
    case KC_DOWN:
      if (is_raise) {
        if (record->event.pressed) {
          tap_code(KC_PGDN);
        }
        return false;
      }
      break;
      
    case KC_RGHT:
      if (is_raise) {
        if (record->event.pressed) {
          tap_code(KC_END);
        }
        return false;
      }
      break;

    case KC_HOME:
      if (record->event.pressed) {
        if (is_windows) {
          tap_code(KC_LEFT);
          return false;
        }
      }
      break;
      
    case KC_END:
      if (record->event.pressed) {
        if (is_windows) {
          tap_code(KC_RGHT);
          return false;
        }
      }
      break;

    case KC_PGUP:
      if (record->event.pressed) {
        if (is_windows) {
          tap_code(KC_UP);
          return false;
        }
      }
      break;

    case KC_PGDN:
      if (record->event.pressed) {
        if (is_windows) {
          tap_code(KC_DOWN);
          return false;
        }
      }
      break;

    case AT_TB:
      if (record->event.pressed) {
        if (!is_windows) {
          register_code16(KC_LALT);
          tap_code(KC_TAB);
          is_windows = true;
        }
      } else {

      }
      break;

    case AT_TS:
      if (record->event.pressed) {
        is_timer = true;
      }
      break;

    case AT_TE:
      if (record->event.pressed) {
        is_timer = false;
      }
      break;

    case AT_PW:
      if (record->event.pressed) {
        SEND_STRING("Ep");
        tap_code(JP_AT);
        SEND_STRING("rkUsers37");
      }
      break;

    case MO_LO:
      if (record->event.pressed) {
        
      } else {
        if (is_windows) {
          unregister_code16(KC_LALT);
          is_windows = false;
        }
      }
      break;

  }
  return true;
}