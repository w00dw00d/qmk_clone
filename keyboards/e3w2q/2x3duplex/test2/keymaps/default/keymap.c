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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
<<<<<<< HEAD:keyboards/e3w2q/2x3duplex/test2/keymaps/default/keymap.c
    /* Base */
    [_BASE] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
        KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,
        KC_G,    KC_H,    KC_I,    KC_J,    KC_K,    KC_L,
        KC_M,    KC_N,    KC_O,    KC_P,    KC_Q,    KC_R
    ),
    [_FN] = LAYOUT(
        QMKBEST, QMKURL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        QMKBEST, QMKURL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        QMKBEST, QMKURL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        RESET,   XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX
    )
=======

  [_BASE] = LAYOUT_ortho_4x4(
    KC_PGUP,  KC_HOME,  KC_UP,    KC_END ,
    KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,
    MO(_FN2), KC_VOLU,  KC_MPLY,  KC_MPRV,
    MO(_FN1), KC_VOLD,  KC_MUTE,  KC_MNXT
  ),
  [_FN1] = LAYOUT_ortho_4x4(
    KC_ESC,   KC_P7,    KC_P8,    KC_P9,
    KC_TAB,   KC_P4,    KC_P5,    KC_P6,
    KC_ENT,   KC_P1,    KC_P2,    KC_P3,
    _______,  KC_P0,    KC_P0,    KC_DOT
  ),
  [_FN2] = LAYOUT_ortho_4x4(
    RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI,
    RGB_RMOD, RGB_HUD,  RGB_SAD,  RGB_VAD,
    _______,  _______,  _______,  QK_BOOT,
    RGB_TOG,  _______,  QMKBEST,  QMKURL
  )

>>>>>>> upstream/master:keyboards/gkeyboard/gkb_m16/keymaps/default/keymap.c
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
