#include QMK_KEYBOARD_H
#include "keymap_jp.h"
//#include "quantum.h"



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
  &eql_key_override ,
  &lbrc_key_override,
  &rbrc_key_override,
  &quot_key_override,
  &bsls_key_override,
  &grv_key_override ,
  NULL
};

static bool is_lock_layer = false;

#define OR_EISU LALT(KC_GRV) // Henkan
#define OR_PRINT LALT(KC_PSCR) // Alt+PrintScreen
// #define OR_TOP RCTL(KC_HOME) // TOP
// #define OR_BOTOM RCTL(KC_END) // Bottom

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE ,
  LOWER,
  RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base layer
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ \ │ ` │
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
   * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │Bspc │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │FnCaps│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ Enter  │
   * ├──────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬───┬───┤
   * │LShift │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │RSC│ ↑ │Del│
   * ├────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴───┼───┼───┼───┼───┼───┤
   * │LCtl│LGui│LAlt│         Space          │RAl│FnL│ ← │ ↓ │ → │
   * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┘
  */
  [_QWERTY] = LAYOUT_directional( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          \
    LOWER,            KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           \
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_DEL,  \
    KC_LCTL, KC_LGUI,          KC_LALT, XXXXXXX,          KC_SPC,           XXXXXXX,          KC_APP,  LOWER, KC_LEFT, KC_DOWN, KC_RGHT    \
  ),
  /* Function layer
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│   │PSc│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
   * │ M4  │M2 │M↑ │M1 │M3 │M5 │   │PgU│ ↑ │PgD│Ply│Prv│Nxt│Clear│
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
   * │      │M← │M↓ │M→ │MW↑│   │Hom│ ← │ ↓ │ → │End│   │        │
   * ├──────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬───┬───┤
   * │       │MA0│MA2│MW←│MW→│   │   │   │Vo-│Vo+│Mut│App│PgU│Ins│
   * ├────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴───┼───┼───┼───┼───┼───┤
   * │    │    │    │          MW↓           │   │   │Hom│PgD│End│
   * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┘
  [_LOWER] = LAYOUT_directional( \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_BSPC, \
    KC_TAB,KC_PSCR,G(S(KC_S)), _______, C(KC_F5),_______, _______, _______, _______, _______, _______, _______, _______, KC_GRV,           \
    LOWER,            C(KC_A), C(KC_S), _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT,           \
    KC_LSFT,          C(KC_Z), C(KC_X), C(KC_C), C(KC_V), _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_DEL,  \
    KC_LCTL, ,MO(_RAISE),       KC_LALT, XXXXXXX,          OR_EISU,          XXXXXXX,          KC_APP, LOWER,   KC_HOME, KC_PGDN, KC_END   \
  ),

  [_RAISE] = LAYOUT_directional( \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_BSPC, \
    _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,          \
    LOWER,            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,            \
    KC_LSFT,          _______, _______, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, _______, _______, _______, _______, _______, KC_PGUP, KC_DEL,  \
    KC_LCTL, _______,          KC_LALT, XXXXXXX,          OR_EISU,          XXXXXXX,          _______, LOWER,   KC_HOME, KC_PGDN, KC_END   \
  ),
  */

};

/* void keyboard_post_init_user(void) {
  // Enable the LED layers
  rgblight_reload_from_eeprom();
  rgblight_disable_noeeprom();
  key_override_on();
} */

void toggle_layer(keyrecord_t *record) {
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
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      toggle_layer(record);
      // if (record->event.pressed) {
      //   lower_pressed = true;
      // } else {
      //   if (lower_pressed) {
      //     register_code(KC_MHEN);
      //     unregister_code(KC_MHEN);
      //   }
      //   lower_pressed = false;
      // }
      return false;
      break;
    // default:
    //   if (record->event.pressed) {
    //     // reset the flags
    //     lower_pressed = false;
    //   }
    //   return true;
    //   break;
  }
  return true;
}