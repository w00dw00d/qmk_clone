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
  RAISE,
};

static bool is_auto_shift = true;

const uint16_t auto_shift_map_cnt = 4;
uint16_t auto_shift_map[4][2] = {
  {KC_0,JP_UNDS}
  ,{KC_SCLN,JP_COLN}
  ,{KC_BSLS,JP_PIPE}
  ,{KC_GRV,JP_ASTR}
};

const uint16_t conv_jis_map_cnt = 2;
uint16_t conv_jis_map[2][2] = {
  {KC_BSLS, JP_YEN}
  ,{KC_GRV, JP_PLUS}
};
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

#define MO_LO MO(_LOWER)
#define MO_RA MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /* Base */ 
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH,  \
    KC_LCTL, KC_LGUI, KC_LALT, MO_LO,   KC_MHEN, KC_SPC,  KC_HENK, MO_RA,            KC_LEFT, KC_DOWN, KC_RGHT  \
  ),

/*   [_QWERTY] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    JP_LBRC, JP_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    JP_AT,   KC_SLSH, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_COMM, KC_DOT,  KC_N,    KC_M,    KC_HOME, KC_UP,   KC_END,  KC_DEL,  \
             KC_LALT, KC_LGUI,MO(_LOWER),KC_SPC,          KC_MHEN, KC_HENK,          KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT  \
  ), */

  [_LOWER] = LAYOUT(
 _______,C(KC_PGUP),C(KC_PGDN),_______, _______, _______, _______, _______, JP_LBRC, JP_RBRC, JP_CIRC, KC_BSLS, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, JP_LBRC, JP_RBRC, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, JP_AT,   KC_GRV,  _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______, \
 _______,C(KC_PGUP),C(KC_PGDN),_______, _______, _______, _______, _______,          KC_HOME, KC_PGDN, KC_END   \
  ),

  [_RAISE] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, JP_LBRC, JP_RBRC, JP_CIRC, KC_BSLS, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, JP_LBRC, JP_RBRC, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, JP_AT,   KC_GRV,  _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______,          KC_HOME, KC_PGDN, KC_END   \
  ),
/*
  [_LOWER] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, JP_LBRC, JP_RBRC, _______, _______, _______, \
    _______, _______, _______, _______, _______, JP_CIRC, KC_BSLS, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, JP_PLUS, JP_ASTR, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, JP_AT,   KC_SLSH, _______, _______, _______, KC_PGUP, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______,          KC_HOME, KC_PGDN, KC_END   \
  ),

  [_RAISE] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, JP_LBRC, JP_RBRC, _______, _______, _______, \
    _______, _______, _______, _______, _______, JP_CIRC, KC_BSLS, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, JP_PLUS, JP_ASTR, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, JP_AT,   KC_SLSH, _______, _______, _______, KC_PGUP, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______,          KC_HOME, KC_PGDN, KC_END   \
  ),
*/
  [_ADJUST] = LAYOUT(
    RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_ASTG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______  \
  )

/*   [_RAISE] = LAYOUT(
    RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_ASTG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______  \
  ) */
};

const uint16_t PROGMEM combo_f01[] = {KC_ESC, KC_1, COMBO_END};
const uint16_t PROGMEM combo_f02[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM combo_f03[] = {KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM combo_f04[] = {KC_3, KC_4, COMBO_END};
const uint16_t PROGMEM combo_f05[] = {KC_4, KC_5, COMBO_END};
const uint16_t PROGMEM combo_f06[] = {KC_5, KC_6, COMBO_END};
const uint16_t PROGMEM combo_f07[] = {KC_6, KC_7, COMBO_END};
const uint16_t PROGMEM combo_f08[] = {KC_7, KC_8, COMBO_END};
const uint16_t PROGMEM combo_f09[] = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM combo_f10[] = {KC_9, KC_0, COMBO_END};
const uint16_t PROGMEM combo_f11[] = {KC_0, KC_MINS, COMBO_END};
const uint16_t PROGMEM combo_f12[] = {KC_MINS, KC_BSPC, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_UP, KC_SLSH, COMBO_END};
// const uint16_t PROGMEM combo_del[] = {KC_O, KC_P, COMBO_END};
// const uint16_t PROGMEM combo_slh[] = {KC_DOT, KC_UP, COMBO_END};
// const uint16_t PROGMEM combo_hat[] = {KC_COMM, KC_DOT, COMBO_END};

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
  // COMBO(combo_del, KC_DEL),
  // COMBO(combo_slh, KC_SLSH),
  // COMBO(combo_hat, JP_QUES)
};

void keyboard_post_init_user(void) {
  // Enable the LED layers
/*   rgblight_reload_from_eeprom();
  rgblight_disable_noeeprom(); */
  //key_override_on();
}

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

uint16_t get_shifted_key(uint16_t keycode) {
  for (int i = 0; i < auto_shift_map_cnt; i++) {
    if (auto_shift_map[i][0] == keycode) return auto_shift_map[i][1];
  }
  return XXXXXXX;
}

uint16_t get_conv_jis_key(uint16_t keycode) {
  for (int i = 0; i < conv_jis_map_cnt; i++) {
    if (conv_jis_map[i][0] == keycode) return conv_jis_map[i][1];
  }
  return XXXXXXX;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
    case KC_ASTG:
      if (record->event.pressed) {
        is_auto_shift = !is_auto_shift;
/*         if (is_auto_shift) {
          rgblight_disable_noeeprom();
        } else {
          rgblight_enable_noeeprom();
        } */
      }
      break;
    default:
      if (!is_auto_shift) {
        uint16_t conv_keycode = get_conv_jis_key(keycode);
        if (conv_keycode != XXXXXXX) {
          if (record->event.pressed) {
            if (!(keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT))) {
              register_code16(conv_keycode);
              return false;
            }
          } else {
            unregister_code16(conv_keycode);
            return true;
          }
        }
      }
      break;
  }
  return true;
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
  uint16_t shifted_keycode = get_shifted_key(keycode);
  if (shifted_keycode == XXXXXXX) {
    if (shifted) add_weak_mods(MOD_BIT(KC_LSFT));
    register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
  } else {
    /* =キーなどのjis変換対応 */
    uint16_t conv_keycode = get_conv_jis_key(keycode);
    conv_keycode = conv_keycode == XXXXXXX ? keycode : conv_keycode;
    register_code16((!shifted) ? conv_keycode : shifted_keycode);
  }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
  uint16_t shifted_keycode = get_shifted_key(keycode);
  if (shifted_keycode == XXXXXXX) {
    unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
  } else {
    /* =キーなどのjis変換対応 */
    uint16_t conv_keycode = get_conv_jis_key(keycode);
    conv_keycode = conv_keycode == XXXXXXX ? keycode : conv_keycode;
    unregister_code16((!shifted) ? conv_keycode : shifted_keycode);
  }
}

