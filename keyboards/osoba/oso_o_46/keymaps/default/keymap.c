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

// const key_override_t at_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_2, JP_AT);
// const key_override_t circ_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_6, JP_CIRC);
// const key_override_t ampr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_7, JP_AMPR);
// const key_override_t astr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_8, JP_ASTR);
// const key_override_t lprn_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_9, JP_LPRN);
// const key_override_t rprn_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_0, JP_RPRN);
// const key_override_t unds_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, JP_UNDS);
// const key_override_t plus_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, JP_PLUS);
// const key_override_t lcbr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, JP_LCBR);
// const key_override_t rcbr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_RBRC, JP_RCBR);
// const key_override_t dquo_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, JP_QUOT);
// const key_override_t pipe_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSLS, JP_PIPE);
// const key_override_t coln_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SCLN, JP_COLN);
// const key_override_t tild_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_GRV, JP_TILD);

// const key_override_t eql_key_override = ko_make_with_layers_and_negmods(0, KC_EQL, JP_EQL, ~0, (uint8_t) MOD_MASK_SHIFT);
// const key_override_t lbrc_key_override = ko_make_with_layers_and_negmods(0, KC_LBRC, JP_LBRC, ~0, (uint8_t) MOD_MASK_SHIFT);
// const key_override_t rbrc_key_override = ko_make_with_layers_and_negmods(0, KC_RBRC, JP_RBRC, ~0, (uint8_t) MOD_MASK_SHIFT);
// const key_override_t quot_key_override = ko_make_with_layers_and_negmods(0, KC_QUOT, JP_DQUO, ~0, (uint8_t) MOD_MASK_SHIFT);
// const key_override_t bsls_key_override = ko_make_with_layers_and_negmods(0, KC_BSLS, JP_BSLS, ~0, (uint8_t) MOD_MASK_SHIFT);
// const key_override_t grv_key_override = ko_make_with_layers_and_negmods(0, KC_GRV, JP_GRV, ~0, (uint8_t) MOD_MASK_SHIFT);

// const key_override_t **key_overrides = (const key_override_t *[]){
//   &at_key_override,
//   &circ_key_override,
//   &ampr_key_override,
//   &astr_key_override,
//   &lprn_key_override,
//   &rprn_key_override,
//   &unds_key_override,
//   &plus_key_override,
//   &lcbr_key_override,
//   &rcbr_key_override,
//   &dquo_key_override,
//   &pipe_key_override,
//   &coln_key_override,
//   &tild_key_override,
//   &eql_key_override ,
//   &lbrc_key_override,
//   &rbrc_key_override,
//   &quot_key_override,
//   &bsls_key_override,
//   &grv_key_override,
//   NULL
// };

const uint16_t auto_shift_map_cnt = 6;
uint16_t auto_shift_map[6][2] = {
   {KC_0, JP_UNDS}
  ,{KC_SCLN, JP_COLN}
  ,{KC_QUOT, JP_ASTR}
  ,{KC_GRV, JP_CIRC}
  ,{KC_NUBS, JP_SLSH}
  ,{KC_BSLS, JP_PIPE}
};

const uint16_t conv_jis_map_cnt = 4;
uint16_t conv_jis_map[4][2] = {
   {KC_QUOT, JP_PLUS}
  ,{KC_GRV, JP_EQL}
  ,{KC_NUBS, JP_MINS}
  ,{KC_BSLS, JP_YEN}
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  QWERTY_M,
  LOWER,
  AT_TS,
  AT_PW,
  SP_SF,
  SP_HK,
  SP_MW,
};

static bool is_timer = false;
static bool is_not_pressed_key = false;
static bool is_sp_hk_pressed = false;
static bool is_sp_sf_pressed = false;
static uint16_t sp_hk_pressed_time = 0;
static uint16_t sp_sf_pressed_time = 0;
static uint16_t l_sh_pressed_time = 0;
//static uint16_t r_sh_pressed_time = 0;
static bool current_is_pc = true;

#define _QWERTY 0
#define _QWERTY_M 1
#define _LOWER 2
// #define _RAISE 3

// #define ZH_TG A(JP_ZKHK)
#define MO_LO MO(_LOWER)
// #define MO_RA MO(_RAISE)
#define SC_CAPS S(KC_CAPS)
#define DF_PC DF(_QWERTY)
#define DF_MC DF(_QWERTY_M)

// #define CL_PU C(KC_PGUP)
// #define CL_PD C(KC_PGDN)
// KC_MHEN KC_HENK KC_APP
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    JP_CIRC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    JP_MINS, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_APP,  KC_LGUI, KC_LALT,          SP_SF,   KC_SPC,  KC_BSPC, MO_LO,            KC_RALT, KC_RGUI, KC_DEL  \
  ),
  [_QWERTY_M] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    JP_CIRC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    JP_MINS, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_APP,  KC_LALT, KC_LGUI,          SP_SF,   KC_SPC,  KC_BSPC, MO_LO,            KC_RGUI, KC_RALT, KC_DEL  \
  ),
  [_LOWER] = LAYOUT(
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
    KC_INS,  _______, _______, _______, KC_QUOT, _______, JP_LBRC, JP_RBRC, KC_UP,   _______, KC_F12,  KC_BSLS, \
    _______, _______, _______, _______, KC_GRV, KC_BSLS,  JP_AT,   KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_BSPC, \
    _______, _______, _______, _______, KC_NUBS, SP_MW,   _______, _______, _______, _______, _______, _______, \
    SC_CAPS, _______, _______,          SP_HK,   _______, _______, _______,          AT_TS,   DF_PC,   DF_MC    \
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

void jamming(void) {
  tap_code(KC_LEFT);
  wait_ms(500);
}

void matrix_scan_user(void) {
  if (is_timer) {
    jamming();
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case DF_PC:
      if (record->event.pressed) {
        current_is_pc = true;
      }
      break;

    case DF_MC:
      if (record->event.pressed) {
        current_is_pc = false;
      }
      break;

    case KC_LSFT:
      if (record->event.pressed) {
        // if (TIMER_DIFF_16(record->event.time, l_sh_pressed_time) < TAPPING_TERM + 100) {
        //   unregister_code(KC_LSFT);
        //   tap_code(KC_MHEN);
        // }
        l_sh_pressed_time = record->event.time;
      }
      break;

    case KC_RSFT:
      if (record->event.pressed) {
        // if (TIMER_DIFF_16(record->event.time, r_sh_pressed_time) < TAPPING_TERM + 100) {
        //   unregister_code(KC_RSFT);
        //   tap_code(KC_HENK);
        // }
        // r_sh_pressed_time = record->event.time;
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
        is_sp_sf_pressed = true;
        // if (TIMER_DIFF_16(record->event.time, sp_sf_pressed_time) < TAPPING_TERM + 100) {
        //   tap_code(KC_HENK);
        // } else {
        if (current_is_pc) {
          tap_code(KC_MHEN);
        } else {
          tap_code(KC_LANG2);
        }
          
        //}
        // register_code(KC_RSFT);
        sp_sf_pressed_time = record->event.time;
      } else {
        // unregister_code(KC_RSFT);
        // if (is_not_pressed_key) {
        //   tap_code(KC_MHEN);
        // }
        is_sp_sf_pressed = false;
        is_not_pressed_key = false;
      }
      break;

    case SP_HK:
      if (record->event.pressed) {
        is_not_pressed_key = true;
        is_sp_hk_pressed = true;
        sp_hk_pressed_time = record->event.time;
      } else {
        if (current_is_pc) {
          tap_code(KC_HENK);
        } else {
          tap_code(KC_LANG1);
        }
        is_sp_hk_pressed = false;
        is_not_pressed_key = false;
      }
      break;

    case KC_SPC:
      if (! is_sp_sf_pressed) {
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

    case AT_PW:
      if (record->event.pressed) {
        SEND_STRING("empty");
        tap_code(JP_AT);
        SEND_STRING("empty");
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

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
  switch(keycode) {
      case KC_PPLS:
        SEND_STRING("empty");
  }
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

