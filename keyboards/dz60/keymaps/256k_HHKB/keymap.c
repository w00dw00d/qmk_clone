#include QMK_KEYBOARD_H

#define ______ KC_TRNS

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    SP_F01,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  LAYOUT_directional(
      KC_ESC,  KC_1,   KC_2,   KC_3,   KC_4,  KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS, KC_EQL,  KC_GRV, SP_F01,
      KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,  KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_LBRC, KC_RBRC, KC_BSLS,
      KC_LCTL, KC_A,   KC_S,   KC_D,   KC_F,  KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,KC_QUOT, KC_ENT,
      KC_LSFT,         KC_Z,   KC_X,   KC_C,  KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, ______, KC_RSFT, KC_DEL,
      ______, KC_LALT, KC_LGUI,KC_SPC, MO(1), KC_BSPC, KC_RGUI, KC_RALT, ______,  ______,  ______
      ),

  LAYOUT_directional(
      KC_ESC,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12, ______,  ______,
      ______,  ______, ______, ______, ______, ______, ______,  ______,  KC_UP,   ______,  ______,  ______, ______, ______,
      ______,  ______, ______, ______, ______, KC_LANG2, KC_LANG1,  KC_LEFT, KC_DOWN, KC_RIGHT,______,  ______, RGB_TOG,
      ______,          ______, ______, ______, ______, ______,  ______,  ______,  ______,  ______,  ______, ______, ______,  ______,
      ______,  ______, ______, ______, ______, ______, ______,  ______,  ______,  ______,  ______
      ),
};

bool process_record_user(uint16_t keycode, keyrecord_t * record) {
    switch (keycode) {
        case SP_F01:
            if (record -> event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_D);
                unregister_code(KC_D);
                unregister_code(KC_LGUI);
            }
            break;

        default:
            break;
    }
    return true;
}
