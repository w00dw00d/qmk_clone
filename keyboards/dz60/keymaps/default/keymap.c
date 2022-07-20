#include QMK_KEYBOARD_H
#include "keymap_jp.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define OR_EISU LALT(KC_GRV)

static bool is_timer = false;
static bool is_key_down = false;

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

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  AT_TS,
  AT_TE,
  AT_PW,
};

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

const key_override_t eql_key_override = ko_make_with_layers_and_negmods(0, KC_EQL, JP_EQL, ~0, (uint8_t) MOD_MASK_SHIFT);
const key_override_t lbrc_key_override = ko_make_with_layers_and_negmods(0, KC_LBRC, JP_LBRC, ~0, (uint8_t) MOD_MASK_SHIFT);
const key_override_t rbrc_key_override = ko_make_with_layers_and_negmods(0, KC_RBRC, JP_RBRC, ~0, (uint8_t) MOD_MASK_SHIFT);
const key_override_t quot_key_override = ko_make_with_layers_and_negmods(0, KC_QUOT, JP_QUOT, ~0, (uint8_t) MOD_MASK_SHIFT);
const key_override_t bsls_key_override = ko_make_with_layers_and_negmods(0, KC_BSLS, JP_BSLS, ~0, (uint8_t) MOD_MASK_SHIFT);
const key_override_t grv_key_override = ko_make_with_layers_and_negmods(0, KC_GRV, JP_GRV, ~0, (uint8_t) MOD_MASK_SHIFT);

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
  NULL
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
// const uint16_t PROGMEM combo_mhn[] = {KC_D, KC_F, COMBO_END};
// const uint16_t PROGMEM combo_hen[] = {KC_J, KC_K, COMBO_END};

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
  // COMBO(combo_mhn, KC_MHEN),
  // COMBO(combo_hen, KC_HENK)
};

// JU_CAPS KC_MHEN KC_HENK KC_CAPS MO(_RAISE)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
      KC_ESC,           KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, KC_BSPC,
      KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
      KC_LCTL,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
      KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_DEL,
      XXXXXXX, KC_LGUI, KC_LALT,                   KC_MHEN, KC_SPC,  LOWER,            KC_RALT, XXXXXXX, KC_APP,  XXXXXXX, XXXXXXX
  ),

  [_LOWER] = LAYOUT(
      RESET,            KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, _______,
      _______,          AT_TS,   AT_TE,   AT_PW,   _______, _______, _______, _______, KC_UP,   KC_PGUP, KC_PGDN, _______, _______, KC_GRV, 
      _______,          _______, _______, _______, _______, KC_HOME, KC_END,  KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,          _______,
      _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______,                   _______, _______, _______,          _______, XXXXXXX, _______, _______, _______
  ),

  [_RAISE] = LAYOUT(
      RESET,            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______,
      _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
      _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______,                   _______, _______, _______,          _______, XXXXXXX, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT(
      RESET,            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______,
      _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______, _______,
      _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_END,           _______,
      _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN, _______, _______,
      _______, _______, _______,                   _______, _______, _______,          _______, XXXXXXX, _______, _______, _______
  ),
};

/* void toggle_layer(keyrecord_t *record) {
  if (record->event.pressed) {
    // Down
    if (is_lock_layer) {
      // ボタンが押された、レイヤーロック中
      layer_off(_LOWER);
      rgblight_disable_noeeprom();
      is_lock_layer = false;
    } else {
      // ボタンが押された、レイヤーロック中じゃない
      is_lock_layer = keyboard_report->mods & MOD_BIT(KC_LALT) || keyboard_report->mods & MOD_BIT(KC_RALT);
      layer_on(_LOWER);
      if (is_lock_layer) rgblight_enable_noeeprom();
    }
  } else if(! is_lock_layer) {
    // ボタンが離された、レイヤーロック中じゃない
    layer_off(_LOWER);
    rgblight_disable_noeeprom();
  }
} */

void jamming(void) {
  tap_code(KC_LEFT);
  wait_ms((rand() % 6 + 1) * 100);
}

void matrix_scan_user(void) {
  if (is_timer) {
    jamming();
  }
}

void keyboard_post_init_user(void) {
  // Enable the LED layers
  rgblight_reload_from_eeprom();
  rgblight_disable_noeeprom();
  key_override_on();
}

uint32_t layer_state_set_user(uint32_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        is_key_down = false;
      } else {
        layer_off(_LOWER);
        if (! is_key_down) {
          tap_code(KC_HENK);
        }
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

    default:
      if (record->event.pressed) {
        is_key_down = true;
      }
      break;
      
    // case KC_SPC:
    //   if (record->event.pressed) {
    //     tap_code(JP_ZKHK);
    //   //} else {
    //   }
    //   break;

  }
  return true;
}
