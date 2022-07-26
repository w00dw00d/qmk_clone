// Copyright 2021 Werther (@thewerther)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_GRV,
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,      KC_DEL,
        KC_RALT,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,              KC_PGUP,
        KC_LSFT,            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,          KC_PGDN,
        KC_LCTL,   KC_LGUI,   KC_LALT,                       LT(1, KC_SPC),                       MO(2),     KC_RCTL,   KC_LEFT,   KC_DOWN,    KC_RGHT
    ),
    [1] = LAYOUT_65_ansi_blocker(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,          _______,
        _______,     _______, _______,  _______, _______, _______, _______, KC_PGUP, _______, _______, _______, _______, _______, _______,     _______,
        _______,        _______, _______, KC_PGDN, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,  _______, _______, _______,            _______,
        _______,           _______,  _______,  _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,    _______,
        _______,   _______,   _______,                      _______,                              _______,   _______,   _______,   _______,    _______
    ),
    [2] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______,     _______,
        _______,     RGB_TOG, _______,  RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_MPLY, KC_MPRV, KC_MNXT, _______,     _______,
        _______,        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            KC_HOME,
        _______,         QK_BOOT,  RGB_SPI,  RGB_SPD, _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______,  _______,  _______,  _______,      KC_END,
        _______,   _______,   _______,                      _______,                              _______,   _______,   _______,   _______,    _______
    )

};

void matrix_scan_user(void) {
    #if defined(RGB_MATRIX_ENABLE)
    int current_effect = rgb_matrix_get_mode();
    if (current_effect >= RGB_MATRIX_SOLID_REACTIVE_SIMPLE && current_effect <= RGB_MATRIX_SOLID_MULTISPLASH) {
        // set all underglow leds to current color
        RGB current_color = hsv_to_rgb(rgb_matrix_get_hsv());
        for (int i = DRIVER_LED_TOTAL - DRIVER_LED_UNDERGLOW; i < DRIVER_LED_TOTAL; i++) {
            rgb_matrix_set_color(i, current_color.r, current_color.g, current_color.b);
        }
    }
    #endif
}
