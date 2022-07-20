#include QMK_KEYBOARD_H
#include "keymap_jp.h"/*
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
const key_override_t dquo_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, JP_DQUO);
const key_override_t pipe_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSLS, JP_PIPE);
const key_override_t coln_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SCLN, JP_COLN);
const key_override_t tild_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_GRV, JP_TILD);

/* auto_shiftと両立できない（非モディファイヤのキーオーバーライド）
const key_override_t eql_key_override = ko_make_with_layers_and_negmods(0, KC_EQL, JP_EQL, ~0, (uint8_t) MOD_MASK_SHIFT);
const key_override_t lbrc_key_override = ko_make_with_layers_and_negmods(0, KC_LBRC, JP_LBRC, ~0, (uint8_t) MOD_MASK_SHIFT);
const key_override_t rbrc_key_override = ko_make_with_layers_and_negmods(0, KC_RBRC, JP_RBRC, ~0, (uint8_t) MOD_MASK_SHIFT);
const key_override_t quot_key_override = ko_make_with_layers_and_negmods(0, KC_QUOT, JP_QUOT, ~0, (uint8_t) MOD_MASK_SHIFT);
const key_override_t bsls_key_override = ko_make_with_layers_and_negmods(0, KC_BSLS, JP_BSLS, ~0, (uint8_t) MOD_MASK_SHIFT);
const key_override_t grv_key_override = ko_make_with_layers_and_negmods(0, KC_GRV, JP_GRV, ~0, (uint8_t) MOD_MASK_SHIFT); */

const key_override_t **key_overrides = (const key_override_t *[]){
  &at_key_override  ,
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
/*   &eql_key_override ,
  &lbrc_key_override,
  &rbrc_key_override,
  &quot_key_override,
  &bsls_key_override,
  &grv_key_override , */
  NULL
};

// static bool lower_pressed = false;

// static bool is_lock_layer = false;
// static bool is_auto_shift = true;

const uint16_t auto_shift_map_cnt = 14;
uint16_t auto_shift_map[14][2] = {
  {KC_2,JP_AT},
  {KC_6,JP_CIRC},
  {KC_7,JP_AMPR},
  {KC_8,JP_ASTR},
  {KC_9,JP_LPRN},
  {KC_0,JP_RPRN},
  {KC_MINS,JP_UNDS},
  {KC_EQL,JP_PLUS},
  {KC_BSLS,JP_PIPE},
  {KC_QUOT,JP_DQUO},
  {KC_LBRC,JP_LCBR},
  {KC_RBRC,JP_RCBR},
  {KC_SCLN,JP_COLN},
  {KC_GRV,JP_TILD}
};

const uint16_t conv_jis_map_cnt = 6;
uint16_t conv_jis_map[6][2] = {
  {KC_EQL, JP_EQL},
  {KC_LBRC, JP_LBRC},
  {KC_RBRC, JP_RBRC},
  {KC_QUOT, JP_QUOT},
  {KC_BSLS, JP_BSLS},
  {KC_GRV, JP_GRV}
};

// #define OR_PRINT LALT(KC_PSCR) // Alt+PrintScreen
// #define OR_TOP RCTL(KC_HOME) // TOP
// #define OR_BOTOM RCTL(KC_END) // Bottom
// #define OR_KIRI G(S(KC_S)) 

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
//#define OR_EISU LALT(KC_GRV) // Henkan
#define OR_TGL TG(_LOWER) // 
/* NO_ACTION_ONESHOT NO_ACTION_MACRO でMOが使えなくなった
#define OR_MOL MO(_LOWER) // 
#define OR_MOR MO(_RAISE) // 
 */
enum custom_keycodes {
  QWERTY = SAFE_RANGE ,
  LOWER,
  // RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

#define MO_LO MO(_LOWER)

/* Qwerty
 * ,-----------------------------------------------------------------------------------------.
 * | ` ~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
 * |-----------------------------------------------------------------------------------------+
 * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
 * |-----------------------------------------------------------------------------------------+
 * | Caps    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
 * |-----------------------------------------------------------------------------------------+
 * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | RSh |  U  | FN  |
 * |-----------------------------------------------------------------------------------------+
 * | Ctrl |  Alt  |  Cmd  |              Space                | Cmd | RAlt |  L  |  D  |  R  |
 * `-----------------------------------------------------------------------------------------'
 */
  [_QWERTY] = LAYOUT_directional( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          \
    LOWER,            KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           \
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_DEL,  \
    KC_LCTL, KC_LGUI,          KC_LALT, XXXXXXX,          KC_SPC,           XXXXXXX,          LOWER,   LOWER,   KC_LEFT, KC_DOWN, KC_RGHT  \
  ),

  [_LOWER] = LAYOUT_directional( \
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, KC_BSPC, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_GRV,           \
    _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,           \
    _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_PGUP, KC_DEL,  \
    _______, _______,          _______, XXXXXXX,          KC_GRV,           XXXXXXX,          _______, _______, KC_HOME, KC_PGDN, KC_END   \
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
const uint16_t PROGMEM combo_f09[] = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM combo_f10[] = {KC_9, KC_0, COMBO_END};
const uint16_t PROGMEM combo_f11[] = {KC_0, KC_MINS, COMBO_END};
const uint16_t PROGMEM combo_f12[] = {KC_MINS, KC_EQL, COMBO_END};
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
  COMBO(combo_f12, KC_F12)
};

// const uint16_t PROGMEM combo_mhen[] = {KC_D, KC_F, COMBO_END};
// const uint16_t PROGMEM combo_henk[] = {KC_J, KC_K, COMBO_END};
// combo_t key_combos[COMBO_COUNT] = {
//     COMBO(combo_mhen, KC_MHEN),
//     COMBO(combo_henk, KC_HENK), 
// };

void keyboard_post_init_user(void) {
  // Enable the LED layers
  rgblight_reload_from_eeprom();
  rgblight_disable_noeeprom();
  key_override_on();
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
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
  //   // case RAISE:
  //   //   if (!is_lock_layer) {
  //   //     if (record->event.pressed) {
  //   //       layer_on(keycode == LOWER ? _LOWER : _RAISE);
  //   //     } else {
  //   //       layer_off(keycode == LOWER ? _LOWER : _RAISE);
  //   //     }
  //   //   }
  //   //   return false;
  //   //   break;
  //   // case KC_ASTG:
  //   //   if (record->event.pressed) {
  //   //     is_auto_shift = !is_auto_shift;
  //   //     if (is_auto_shift) {
  //   //       rgblight_disable_noeeprom();
  //   //     } else {
  //   //       rgblight_enable_noeeprom();
  //   //     }
  //   //   }
  //   //   break;
  //   // case OR_TGL:
  //   //   if (record->event.pressed) {
  //   //     is_lock_layer = !is_lock_layer;
  //   //     if (is_lock_layer) {
  //   //       rgblight_enable_noeeprom();
  //   //     } else {
  //   //       rgblight_disable_noeeprom();
  //   //     }
  //   //   }
  //   //   break;
  //   // default:
  //   //   if (!is_auto_shift) {
  //   //     uint16_t conv_keycode = get_conv_jis_key(keycode);
  //   //     if (conv_keycode != XXXXXXX) {
  //   //       if (record->event.pressed) {
  //   //         if (!(keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT))) {
  //   //           register_code16(conv_keycode);
  //   //           return false;
  //   //         }
  //   //       } else {
  //   //         unregister_code16(conv_keycode);
  //   //         return true;
  //   //       }
  //   //     }
  //   //   }
  //   //   break;
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