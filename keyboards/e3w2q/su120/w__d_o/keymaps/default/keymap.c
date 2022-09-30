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

#ifdef RGBLIGHT_ENABLE
#include "rgblight.h"
extern rgblight_config_t rgblight_config;
#endif
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

const rgblight_segment_t PROGMEM rgb_default_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 57, HSV_WHITE}
/*
    {0, 57, HSV_BLUE}, 
    {11, 1, HSV_PURPLE},
    {48, 9, HSV_PURPLE}
*/
);

const rgblight_segment_t PROGMEM rgb_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 57, HSV_OFF}, 
    {0, 11, HSV_PURPLE},
    {22, 1, HSV_PURPLE},
    {31, 1, HSV_PURPLE},
    {20, 1, HSV_PURPLE},
    {26, 3, HSV_PURPLE},
    {51, 3, HSV_PURPLE},
    {54, 1, HSV_PURPLE},
    {56, 1, HSV_PURPLE},
    {49, 2, HSV_BLUE},
    {11, 1, HSV_RED}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_default_layer,
    rgb_lower_layer
);

const key_override_t coln_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SCLN, JP_COLN);

const key_override_t **key_overrides = (const key_override_t *[]){
  &coln_key_override,
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
};

static bool is_timer = false;
static bool is_not_pressed_key = false;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

// #define ZH_TG A(JP_ZKHK)
#define MO_LO MO(_LOWER)
#define MO_RA MO(_RAISE)

// #define CL_PU C(KC_PGUP)
// #define CL_PD C(KC_PGDN)
// KC_MHEN KC_HENK KC_APP S(KC_CAPS)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_ESC,  KC_LGUI, KC_LALT,          LOWER,   KC_SPC,           RAISE,            KC_RALT, KC_RGUI, KC_DEL   \
  ),
  [_LOWER] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    KC_INS,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
    _______, XXXXXXX, JP_PERC, JP_SLSH, JP_MINS, JP_ASTR, JP_PLUS, JP_EQL,  JP_CIRC, JP_DOT,  XXXXXXX, KC_BSPC, \
    _______, KC_0,    KC_1,    KC_2,    KC_3,    JP_LPRN, JP_RPRN, JP_LCBR, JP_RCBR, JP_LBRC, JP_RBRC, _______, \
    RGB_TOG, _______, S(KC_CAPS),       _______, _______,          _______,          AT_TS,   AT_PW,   XXXXXXX  \
  ),
  [_RAISE] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    KC_INS,  JP_GRV,  JP_EXLM, JP_PIPE, JP_AMPR, JP_DLR,  JP_HASH, JP_AT,   KC_UP,   XXXXXXX, XXXXXXX, KC_BSLS, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, SP_MW,   JP_QUOT, JP_DQUO, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_BSPC, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, JP_TILD, JP_BSLS, JP_UNDS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    RGB_TOG, _______, S(KC_CAPS),       _______, _______,          _______,          AT_TS,   AT_PW,   XXXXXXX  \
  ),
  [_ADJUST] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, KC_PGUP, _______, _______, _______, \
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, KC_HOME, KC_PGDN, KC_END,  _______, _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, \
    RESET,   _______, S(KC_CAPS),       _______, _______,          _______,          AT_TS,   AT_PW,   XXXXXXX  \
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));

    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void keyboard_post_init_user(void) {
  // Enable the LED layers
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);

  rgblight_layers = rgb_layers;
    
  // sethsv(HSV_WHITE, (LED_TYPE *)&led[0]); // led 0
  rgblight_set();

  rgblight_disable();
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
  // lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
  // rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        is_not_pressed_key = true;
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);

        if (is_not_pressed_key && keyboard_report->mods & MOD_BIT(KC_LCTL)) {
          unregister_code(KC_LCTL);
          tap_code(KC_MHEN);
          register_code(KC_LCTL);
        }
      }
      return false;
      break;

    case RAISE:
      if (record->event.pressed) {
        is_not_pressed_key = true;
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);

        if (is_not_pressed_key && keyboard_report->mods & MOD_BIT(KC_LCTL)) {
          unregister_code(KC_LCTL);
          tap_code(KC_HENK);
          register_code(KC_LCTL);
        }
      }
      return false;
      break;

    // case KC_LSFT:
    //   if (record->event.pressed) {
    //     if (TIMER_DIFF_16(record->event.time, l_sh_pressed_time) < TAPPING_TERM + 100) {
    //       unregister_code(KC_LSFT);
    //       tap_code(KC_MHEN);
    //     }
    //     l_sh_pressed_time = record->event.time;
    //   }
    //   break;

    // case KC_RSFT:
    //   if (record->event.pressed) {
    //     if (TIMER_DIFF_16(record->event.time, r_sh_pressed_time) < TAPPING_TERM + 100) {
    //       unregister_code(KC_RSFT);
    //       tap_code(KC_HENK);
    //     }
    //     r_sh_pressed_time = record->event.time;
    //   }
    //   break;

    case SP_MW:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_TAB);
      } else {
        unregister_code(KC_LALT);
      }
      is_not_pressed_key = false;
      break;

    // case SP_SF:
    //   if (record->event.pressed) {
    //     is_not_pressed_key = true;
    //     is_sp_sf_pressed = true;
    //     // if (TIMER_DIFF_16(record->event.time, sp_sf_pressed_time) < TAPPING_TERM + 100) {
    //     //   tap_code(KC_HENK);
    //     // } else {
    //       tap_code(KC_MHEN);
    //     //}
    //     register_code(KC_RSFT);
    //     sp_sf_pressed_time = record->event.time;
    //   } else {
    //     unregister_code(KC_RSFT);
    //     // if (is_not_pressed_key) {
    //     //   tap_code(KC_MHEN);
    //     // }
    //     is_sp_sf_pressed = false;
    //     is_not_pressed_key = false;
    //   }
    //   break;

    // case SP_HK:
    //   if (record->event.pressed) {
    //     is_not_pressed_key = true;
    //     is_sp_hk_pressed = true;
    //     sp_hk_pressed_time = record->event.time;
    //   } else {
    //     if (is_not_pressed_key) {
    //       tap_code(KC_HENK);
    //     }
    //     is_sp_hk_pressed = false;
    //     is_not_pressed_key = false;
    //   }
    //   break;

    // case KC_LEFT:
    //   if (! is_sp_hk_pressed) {
    //     break;
    //   }
    //   if (record->event.pressed) {
    //     tap_code(KC_HOME);
    //     is_not_pressed_key = false;
    //     return false;
    //   }

    // case KC_RGHT:
    //   if (! is_sp_hk_pressed) {
    //     break;
    //   }
    //   if (record->event.pressed) {
    //     tap_code(KC_END);
    //     is_not_pressed_key = false;
    //     return false;
    //   }

    // case KC_UP:
    //   if (! is_sp_hk_pressed) {
    //     break;
    //   }
    //   if (record->event.pressed) {
    //     tap_code(KC_PGUP);
    //     is_not_pressed_key = false;
    //     return false;
    //   }

    // case KC_DOWN:
    //   if (! is_sp_hk_pressed) {
    //     break;
    //   }
    //   if (record->event.pressed) {
    //     tap_code(KC_PGDN);
    //     is_not_pressed_key = false;
    //     return false;
    //   }

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