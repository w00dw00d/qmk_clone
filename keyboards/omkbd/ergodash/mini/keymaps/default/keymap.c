#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define MO_LO MO(_LOWER)
#define MO_RA MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_RBRC,                        KC_EQL , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,                        KC_QUOT, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV ,                        XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_ESC,  KC_DEL,  KC_LALT, KC_LGUI,          KC_LNG2, KC_SPC , KC_DEL,        KC_ENT, KC_BSPC ,MO_LO,            MO_RA,   XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_LOWER] = LAYOUT(
    KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,                        KC_EQL , XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, KC_MINS,
    KC_LCTL, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   _______,                        KC_QUOT, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_ENT,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______ ,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,
    KC_ESC,  KC_DEL,  KC_LALT, KC_LGUI,          KC_LNG1, _______ , _______,     _______, _______ ,_______,          _______, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_RAISE] = LAYOUT(
    KC_TAB,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_PSCR,                        KC_EQL , XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, KC_MINS,
    KC_LCTL, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_INS,                         KC_QUOT, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_ENT,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______ ,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,
    KC_ESC,  KC_DEL,  KC_LALT, KC_LGUI,          KC_LNG1, _______ , _______,     _______, _______ ,_______,          _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),

  [_ADJUST] = LAYOUT(
    _______, QK_BOOT, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                         _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______,
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                         _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,_______,                         _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,          _______,_______,_______,         _______,_______, _______,          _______, _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    default:
      // if (record->event.pressed) {
      //   // reset the flags
      //   lower_pressed = false;
      //   raise_pressed = false;
      // }
      return true;
      break;
  }

  return true;
}
