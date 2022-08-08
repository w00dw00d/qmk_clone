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


const key_override_t at_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_2, JP_AT);
const key_override_t circ_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_6, JP_CIRC);
const key_override_t ampr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_7, JP_AMPR);
const key_override_t astr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_8, JP_ASTR);
const key_override_t lprn_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_9, JP_LPRN);
const key_override_t rprn_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_0, JP_RPRN);
const key_override_t unds_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, JP_UNDS);
const key_override_t plus_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, JP_PLUS);
const key_override_t lcbr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, JP_LCBR);
const key_override_t rcbr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_RBRC, JP_RCBR);
const key_override_t dquo_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, JP_QUOT);
const key_override_t pipe_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSLS, JP_PIPE);
const key_override_t coln_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SCLN, JP_COLN);
const key_override_t tild_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_GRV, JP_TILD);

const key_override_t eql_key_override = ko_make_with_layers_and_negmods(0, KC_EQL, JP_EQL, ~0, (uint8_t) MOD_MASK_SHIFT);
const key_override_t lbrc_key_override = ko_make_with_layers_and_negmods(0, KC_LBRC, JP_LBRC, ~0, (uint8_t) MOD_MASK_SHIFT);
const key_override_t rbrc_key_override = ko_make_with_layers_and_negmods(0, KC_RBRC, JP_RBRC, ~0, (uint8_t) MOD_MASK_SHIFT);
const key_override_t quot_key_override = ko_make_with_layers_and_negmods(0, KC_QUOT, JP_DQUO, ~0, (uint8_t) MOD_MASK_SHIFT);
const key_override_t bsls_key_override = ko_make_with_layers_and_negmods(0, KC_BSLS, JP_BSLS, ~0, (uint8_t) MOD_MASK_SHIFT);
const key_override_t grv_key_override = ko_make_with_layers_and_negmods(0, KC_GRV, JP_GRV, ~0, (uint8_t) MOD_MASK_SHIFT);

const key_override_t at2_key_override = ko_make_with_layers_and_negmods(0, KC_AT,   JP_AT, ~0, (uint8_t) MOD_MASK_SHIFT);
const key_override_t cc2_key_override = ko_make_with_layers_and_negmods(0, KC_CIRC, JP_CIRC, ~0, (uint8_t) MOD_MASK_SHIFT);

const key_override_t ap2_key_override = ko_make_with_layers_and_negmods(0, KC_AMPR, JP_AMPR, ~0, (uint8_t) MOD_MASK_SHIFT);
const key_override_t as2_key_override = ko_make_with_layers_and_negmods(0, KC_ASTR, JP_ASTR, ~0, (uint8_t) MOD_MASK_SHIFT);
const key_override_t lp2_key_override = ko_make_with_layers_and_negmods(0, KC_LPRN, JP_LPRN, ~0, (uint8_t) MOD_MASK_SHIFT);
const key_override_t rp2_key_override = ko_make_with_layers_and_negmods(0, KC_RPRN, JP_RPRN, ~0, (uint8_t) MOD_MASK_SHIFT);
const key_override_t ud2_key_override = ko_make_with_layers_and_negmods(0, KC_UNDS, JP_UNDS, ~0, (uint8_t) MOD_MASK_SHIFT);

const key_override_t **key_overrides = (const key_override_t *[]){
  &at_key_override,
  &circ_key_override,
  &ampr_key_override,
  &astr_key_override,
  &lprn_key_override,
  &rprn_key_override,
  &unds_key_override,
  &plus_key_override,
  &lcbr_key_override,
  &rcbr_key_override,
  &dquo_key_override,
  &pipe_key_override,
  &coln_key_override,
  &tild_key_override,
  &eql_key_override ,
  &lbrc_key_override,
  &rbrc_key_override,
  &quot_key_override,
  &bsls_key_override,
  &grv_key_override,
  &at2_key_override,
  &cc2_key_override,
  &ap2_key_override,
  &as2_key_override,
  &lp2_key_override,
  &rp2_key_override,
  &ud2_key_override,
  NULL
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  AT_TS,
  AT_PW,
  SP_SF,
  SP_HK,
  SP_MW,
  SP_AT,
};

static bool is_timer = false;
static bool is_not_pressed_key = false;
static bool is_lower_pressed = false;
static bool is_raise_pressed = false;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _CENTER 3

// #define ZH_TG A(JP_ZKHK)
#define MO_LO MO(_LOWER)
#define MO_RA MO(_RAISE)

// #define CL_PU C(KC_PGUP)
// #define CL_PD C(KC_PGDN)
// KC_MHEN KC_HENK
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,  KC_BSLS, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT, \
    KC_LGUI, KC_LALT, SP_AT,            MO_RA,   KC_SPC,  MO_LO,                     KC_LBRC, KC_RBRC, KC_APP   \
  ),
  [_LOWER] = LAYOUT(
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
    KC_INS,  _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______, KC_GRV, \
    _______, _______, _______, _______, SP_MW,   _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_BSPC, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______,          _______, KC_DEL,  _______,                   AT_TS,   AT_PW,   S(KC_CAPS)  \
  ),
  [_RAISE] = LAYOUT(
    _______, JP_EXLM, KC_AT,   JP_HASH, JP_DLR,  JP_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_BSPC, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______,          _______, _______, _______,                   _______, _______, _______  \
  ),
  [_CENTER] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END,  _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______,          _______, _______, _______,                   _______, _______, _______  \
  ),
};

// const uint16_t PROGMEM combo_f01[] = {KC_ESC, KC_1, COMBO_END};
// const uint16_t PROGMEM combo_f02[] = {KC_1, KC_2, COMBO_END};
// const uint16_t PROGMEM combo_f03[] = {KC_2, KC_3, COMBO_END};
// const uint16_t PROGMEM combo_f04[] = {KC_3, KC_4, COMBO_END};
// const uint16_t PROGMEM combo_f05[] = {KC_4, KC_5, COMBO_END};
// const uint16_t PROGMEM combo_f06[] = {KC_5, KC_6, COMBO_END};
// const uint16_t PROGMEM combo_f07[] = {KC_6, KC_7, COMBO_END};
// const uint16_t PROGMEM combo_f08[] = {KC_7, KC_8, COMBO_END};
// const uint16_t PROGMEM combo_f09[] = {KC_7, KC_8, KC_9, COMBO_END};
// const uint16_t PROGMEM combo_f10[] = {KC_9, KC_0, COMBO_END};
// const uint16_t PROGMEM combo_f11[] = {KC_0, KC_MINS, COMBO_END};
// const uint16_t PROGMEM combo_f12[] = {KC_MINS, KC_BSPC, COMBO_END};
// const uint16_t PROGMEM combo_del[] = {KC_UP, KC_SLSH, COMBO_END};

// combo_t key_combos[COMBO_COUNT] = {
//   COMBO(combo_f01, KC_F1),
//   COMBO(combo_f02, KC_F2),
//   COMBO(combo_f03, KC_F3),
//   COMBO(combo_f04, KC_F4),
//   COMBO(combo_f05, KC_F5),
//   COMBO(combo_f06, KC_F6),
//   COMBO(combo_f07, KC_F7),
//   COMBO(combo_f08, KC_F8),
//   COMBO(combo_f09, KC_F9),
//   COMBO(combo_f10, KC_F10),
//   COMBO(combo_f11, KC_F11),
//   COMBO(combo_f12, KC_F12),
//   COMBO(combo_del, KC_DEL)
// };

void keyboard_post_init_user(void) {
  // Enable the LED layers
  // rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  // rgblight_sethsv_noeeprom(HSV_ORANGE);
  // rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
  //key_override_on();


  // sethsv(HSV_WHITE, (LED_TYPE *)&led[0]); // led 0
  // sethsv(HSV_RED,   (LED_TYPE *)&led[1]); // led 1
  // sethsv(HSV_GREEN, (LED_TYPE *)&led[2]); // led 2
  // rgblight_set();
}

void jamming(void) {
  tap_code(KC_LEFT);
  wait_ms(500);
}

void matrix_scan_user(void) {
  if (is_timer) {
    jamming();
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _RAISE, _LOWER, _CENTER);
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {


    case SP_MW:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_TAB);
      } else {
        unregister_code(KC_LALT);
      }
      is_not_pressed_key = false;
      break;

    case MO_RA:
      if (record->event.pressed) {
        is_not_pressed_key = true;
        is_raise_pressed = true;
        tap_code(KC_MHEN);
      } else {
        if (is_not_pressed_key && is_lower_pressed) {
          tap_code(KC_HENK);
        }
        is_raise_pressed = false;
        is_not_pressed_key = false;
      }
      break;

    case MO_LO:
      if (record->event.pressed) {
        is_not_pressed_key = true;
        is_lower_pressed = true;
      } else {
        is_lower_pressed = false;
        is_not_pressed_key = false;
      }
      break;

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

    case AT_PW:
      if (record->event.pressed) {
        SEND_STRING("Ep");
        tap_code(JP_AT);
        SEND_STRING("rkUsers37");
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