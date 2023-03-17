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

// const key_override_t at_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_2,
// JP_AT); const key_override_t circ_key_override =
// ko_make_basic(MOD_MASK_SHIFT, KC_6, JP_CIRC); const key_override_t
// ampr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_7, JP_AMPR); const
// key_override_t astr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_8,
// JP_ASTR); const key_override_t lprn_key_override =
// ko_make_basic(MOD_MASK_SHIFT, KC_9, JP_LPRN); const key_override_t
// rprn_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_0, JP_RPRN); const
// key_override_t unds_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_MINS,
// JP_UNDS); const key_override_t plus_key_override =
// ko_make_basic(MOD_MASK_SHIFT, KC_EQL, JP_PLUS); const key_override_t
// lcbr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, JP_LCBR); const
// key_override_t rcbr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_RBRC,
// JP_RCBR); const key_override_t dquo_key_override =
// ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, JP_QUOT); const key_override_t
// pipe_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSLS, JP_PIPE); const
// key_override_t coln_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SCLN,
// JP_COLN); const key_override_t tild_key_override =
// ko_make_basic(MOD_MASK_SHIFT, KC_GRV, JP_TILD);

// const key_override_t eql_key_override = ko_make_with_layers_and_negmods(0,
// KC_EQL, JP_EQL, ~0, (uint8_t) MOD_MASK_SHIFT); const key_override_t
// lbrc_key_override = ko_make_with_layers_and_negmods(0, KC_LBRC, JP_LBRC, ~0,
// (uint8_t) MOD_MASK_SHIFT); const key_override_t rbrc_key_override =
// ko_make_with_layers_and_negmods(0, KC_RBRC, JP_RBRC, ~0, (uint8_t)
// MOD_MASK_SHIFT); const key_override_t quot_key_override =
// ko_make_with_layers_and_negmods(0, KC_QUOT, JP_DQUO, ~0, (uint8_t)
// MOD_MASK_SHIFT); const key_override_t bsls_key_override =
// ko_make_with_layers_and_negmods(0, KC_BSLS, JP_BSLS, ~0, (uint8_t)
// MOD_MASK_SHIFT); const key_override_t grv_key_override =
// ko_make_with_layers_and_negmods(0, KC_GRV, JP_GRV, ~0, (uint8_t)
// MOD_MASK_SHIFT);

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

// 変換テーブル（シフト後の値） key : jp_pc : us_pc
const uint16_t auto_shift_map_cnt = 16;
uint16_t auto_shift_map[16][3] = {
    {KC_UR01, JP_DQUO, S(KC_QUOT)}  // 2 "
    ,
    {KC_UR02, JP_AMPR, S(KC_7)}  // 6 &
    ,
    {KC_UR03, JP_QUOT, KC_QUOT}  // 7 '
    ,
    {KC_UR04, JP_LPRN, S(KC_9)}  // 8 (
    ,
    {KC_UR05, JP_RPRN, S(KC_0)}  // 9 )
    ,
    {KC_UR06, JP_UNDS, S(KC_MINS)}  // 0 _
    ,
    {KC_UR07, JP_EQL, KC_EQL}  // - =
    ,
    {KC_UR08, JP_TILD, S(KC_GRV)}  // ^ ~
    ,
    {KC_UR09, JP_PIPE, S(KC_BSLS)}  // ¥ |
    ,
    {KC_UR10, JP_GRV, KC_GRV}  // @ `
    ,
    {KC_UR11, JP_LCBR, S(KC_LBRC)}  // [ {
    ,
    {KC_UR12, JP_ASTR, S(KC_8)}  // + *
    ,
    {KC_UR13, JP_SLSH, KC_SLSH}  // - /
    ,
    {KC_UR14, JP_RCBR, S(KC_RBRC)}  // ] }
    ,
    {KC_UR15, JP_EQL, KC_EQL}  // =
    ,
    {KC_UR16, JP_COLN, S(KC_SCLN)}  // ; :
};

// 変換テーブル（シフト前の値） key : jp_pc : us_pc
const uint16_t conv_jis_map_cnt = 16;
uint16_t conv_jis_map[16][3] = {
    {KC_UR01, KC_2, KC_2}  // 2
    ,
    {KC_UR02, KC_6, KC_6}  // 6
    ,
    {KC_UR03, KC_7, KC_7}  // 7
    ,
    {KC_UR04, KC_8, KC_8}  // 8
    ,
    {KC_UR05, KC_9, KC_9}  // 9
    ,
    {KC_UR06, KC_0, KC_0}  // 0
    ,
    {KC_UR07, JP_MINS, KC_MINS}  // -
    ,
    {KC_UR08, JP_CIRC, S(KC_6)}  // ^
    ,
    {KC_UR09, JP_YEN, KC_BSLS}  // ¥
    ,
    {KC_UR10, JP_AT, S(KC_2)}  // @
    ,
    {KC_UR11, JP_LBRC, KC_LBRC}  // [
    ,
    {KC_UR12, JP_PLUS, S(KC_EQL)}  // +
    ,
    {KC_UR13, JP_MINS, KC_MINS}  // -
    ,
    {KC_UR14, JP_RBRC, KC_RBRC}  // ]
    ,
    {KC_UR15, JP_EQL, KC_EQL}  // =
    ,
    {KC_UR16, JP_SCLN, KC_SCLN}  // ; :
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  SP_SF,
  SP_HK,
  SP_CP,
  SP_LANG,
  SP_LNTY,
};

static bool is_not_keypress = false;
static bool current_is_pc = false;
static uint16_t pressed_time = 0;
static uint16_t last_keycode = 0;
static uint16_t lang_type = 1;  // 1:jp 2:us

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

// #define MO_LO MO(_LOWER)
// #define MO_RA MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] =
        LAYOUT(KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
               KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,  \
               KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RCTL, \
                                 KC_LGUI, KC_LSFT, KC_SPC, KC_BSPC,  LOWER,   KC_RALT                    \
        ),

    [_LOWER] =
        LAYOUT(KC_1,    KC_UR01, KC_3,    KC_4,    KC_5,    KC_UR09, KC_TAB,  KC_UP,   _______, KC_UR07, \
               KC_UR02, KC_UR03, KC_UR04, KC_UR05, KC_UR06, KC_UR10, KC_LEFT, KC_DOWN, KC_RGHT, KC_UR16, \
               KC_ESC,  KC_UR13, KC_UR12, KC_UR15, KC_DOT,  KC_UR08, KC_UR11, KC_UR14, _______, KC_SLSH, \
                                 _______, _______, SP_LANG, _______, _______, _______                    \
        ),

    [_RAISE] =
        LAYOUT(KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   SP_CP,   _______, _______, _______, SP_LNTY, \
               KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, _______, _______, _______, \
               _______, _______, _______, KC_F11,  KC_F12,  _______, _______, _______, _______, _______, \
                                 _______, _______, _______, _______, _______, _______ \
        ),
};

void set_input_source(bool is_eisu) {
  if (is_eisu) {
    if (current_is_pc) {
      tap_code(KC_MHEN);
    } else {
      tap_code(KC_LANG2);
    }
  } else {
    if (current_is_pc) {
      tap_code(KC_HENK);
    } else {
      tap_code(KC_LANG1);
    }
  }
}

void set_layer(bool is_set, uint16_t keycode) {
  uint16_t layer = _QWERTY;
  switch (keycode) {
    case LOWER:
      layer = _LOWER;
      break;
    case RAISE:
      layer = _RAISE;
      break;
  }
  if (is_set) {
    layer_on(layer);
  } else {
    layer_off(_LOWER);
    layer_off(_RAISE);
  }
}

uint16_t get_shifted_key(uint16_t keycode) {
  for (int i = 0; i < auto_shift_map_cnt; i++) {
    if (auto_shift_map[i][0] == keycode) return auto_shift_map[i][lang_type];
  }
  return XXXXXXX;
}

uint16_t get_conv_jis_key(uint16_t keycode) {
  for (int i = 0; i < conv_jis_map_cnt; i++) {
    if (conv_jis_map[i][0] == keycode) return conv_jis_map[i][lang_type];
  }
  return XXXXXXX;
}

void get_captcha(void) {
  register_code(KC_LSFT);
  register_code(KC_LGUI);
  register_code(KC_4);
  unregister_code(KC_4);
  unregister_code(KC_LGUI);
  unregister_code(KC_LSFT);
}

void keyboard_post_init_user(void) {}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool is_double_tap = record -> event.pressed && last_keycode == keycode && TIMER_DIFF_16(record -> event.time, pressed_time) < TAPPING_TERM + 50;
  last_keycode = keycode;
  if (record -> event.pressed) pressed_time = record -> event.time;
  switch (keycode) {
    case SP_CP:
      if (record->event.pressed) {
        get_captcha();
      }
      break;

    case SP_LNTY:
      if (record->event.pressed) {
        lang_type = (lang_type == 1 ? 2 : 1);
      }
      break;

    case LOWER:
        set_layer(record -> event.pressed, is_double_tap ? RAISE : LOWER);
        break;

    case SP_LANG:
        if (record -> event.pressed) {
            if (is_double_tap) {
                set_input_source(false);
            } else {
                set_input_source(true);
            }
        }
        break;

    // case SP_SF:
    //   if (record->event.pressed) {
    //     is_not_keypress = true;
    //     is_sp_sf_pressed = true;
    //     // if (TIMER_DIFF_16(record->event.time, sp_sf_pressed_time) <
    //     // TAPPING_TERM + 100) {
    //     //   tap_code(KC_HENK);
    //     // } else {
    //     if (current_is_pc) {
    //       tap_code(KC_MHEN);
    //     } else {
    //       tap_code(KC_LANG2);
    //     }

    //     //}
    //     // register_code(KC_RSFT);
    //     sp_sf_pressed_time = record->event.time;
    //   } else {
    //     // unregister_code(KC_RSFT);
    //     // if (is_not_keypress) {
    //     //   tap_code(KC_MHEN);
    //     // }
    //     is_sp_sf_pressed = false;
    //     is_not_keypress = false;
    //   }
    //   break;

    // case SP_HK:
    //   if (record->event.pressed) {
    //     is_not_keypress = true;
    //     is_sp_hk_pressed = true;
    //     sp_hk_pressed_time = record->event.time;
    //     if (current_is_pc) {
    //       tap_code(KC_HENK);
    //     } else {
    //       tap_code(KC_LANG1);
    //     }
    //   } else {
    //     is_sp_hk_pressed = false;
    //     is_not_keypress = false;
    //   }
    //   break;

    default:
      if (record->event.pressed) {
        is_not_keypress = false;
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

void autoshift_release_user(uint16_t keycode, bool shifted,
                            keyrecord_t *record) {
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
