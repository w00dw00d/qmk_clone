/* Copyright 2022 hanachi-ap
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

#ifdef CONSOLE_ENABLE
#include <print.h>
#endif

enum target {
    TARGET_MAC = 1,
    TARGET_PC,
};

enum layout {
    LAYOUT_JIS = 1,
    LAYOUT_ANSI,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    SP_CUR,
    SP_FUNC,
    SP_KANA,
    SP_EISU,
    SP_TO_MAC,
    SP_TO_PC,
    SP_TO_JIS,
    SP_TO_ANS,
    SP_TS,
    SP_LANG,
    SP_LNG1,
    SP_LNG2,
    SP_LLCK,
    SP_SPRC,
    SP_SPRW,
};

// 変換テーブル（シフト後の値） key : jp_pc : us_pc
const uint16_t auto_shift_map_cnt = 16;
uint16_t auto_shift_map[16][3] = {
     {KC_UR01, JP_DQUO, S(KC_QUOT)} // 2 "
    ,{KC_UR02, JP_AMPR, S(KC_7)} // 6 &
    ,{KC_UR03, JP_QUOT, KC_QUOT} // 7 '
    ,{KC_UR04, JP_LPRN, S(KC_9)} // 8 (
    ,{KC_UR05, JP_RPRN, S(KC_0)} // 9 )
    ,{KC_UR06, JP_UNDS, S(KC_MINS)} // 0 _
    ,{KC_UR07, JP_EQL , KC_EQL} // - =
    ,{KC_UR08, JP_TILD, S(KC_GRV)} // ^ ~
    ,{KC_UR09, JP_PIPE, S(KC_BSLS)} // ¥ |
    ,{KC_UR10, JP_GRV , KC_GRV} // @ `
    ,{KC_UR11, JP_LCBR, S(KC_LBRC)} // [ {
    ,{KC_UR12, JP_ASTR, S(KC_8)} // + *
    ,{KC_UR13, JP_SLSH, KC_SLSH} // - /
    ,{KC_UR14, JP_RCBR, S(KC_RBRC)} // ] }
    ,{KC_UR15, JP_EQL, KC_EQL} // =
    ,{KC_UR16, JP_COLN, S(KC_SCLN)} // ; :
};

// 変換テーブル（シフト前の値） key : jp_pc : us_pc
const uint16_t conv_jis_map_cnt = 16;
uint16_t conv_jis_map[16][3] = {
     {KC_UR01, KC_2, KC_2} // 2
    ,{KC_UR02, KC_6, KC_6} // 6
    ,{KC_UR03, KC_7, KC_7} // 7
    ,{KC_UR04, KC_8, KC_8} // 8
    ,{KC_UR05, KC_9, KC_9} // 9
    ,{KC_UR06, KC_0, KC_0} // 0
    ,{KC_UR07, JP_MINS ,KC_MINS} // -
    ,{KC_UR08, JP_CIRC, S(KC_6)} // ^
    ,{KC_UR09, JP_YEN, KC_BSLS} // ¥
    ,{KC_UR10, JP_AT , S(KC_2)} // @
    ,{KC_UR11, JP_LBRC, KC_LBRC} // [
    ,{KC_UR12, JP_PLUS, S(KC_EQL)} // +
    ,{KC_UR13, JP_MINS, KC_MINS} // -
    ,{KC_UR14, JP_RBRC, KC_RBRC} // ]
    ,{KC_UR15, JP_EQL, KC_EQL} // =
    ,{KC_UR16, JP_SCLN, KC_SCLN} // ; :
};

// MAC or PC
const uint16_t conv_mod_map_cnt = 3;
uint16_t conv_mod_map[3][3] = {
     {KC_UR17, KC_LGUI,  KC_LCTL} // cmd
    ,{KC_UR18, KC_LALT, KC_LGUI}  // option
    ,{KC_UR19, KC_LCTL, KC_LALT} // control
};

static bool is_not_keypress = false;
static uint16_t current_target = TARGET_MAC;
static uint16_t current_layout = LAYOUT_JIS;
static bool is_timer = false;
static bool is_layer_lock = false;
static bool is_rshift_pressed = false;
static uint16_t pressed_time = 0;
static uint16_t last_keycode = 0;

// Defines names for use in layer keycodes and the keymap

#define _QWERTY 0
#define _CURSOR 1
#define _FUNC 2
#define _TENKEY 3
// SP_CUR SP_LLCK KC_ESC KC_DEL KC_UR13, KC_UR12, KC_UR15, KC_DOT
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,     XXXXXXX,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,   KC_ENT,   XXXXXXX,
    XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_UR08, KC_UR09, KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,  XXXXXXX,
    KC_ESC,                    KC_UR18, KC_UR17, KC_LSFT, KC_SPC,  KC_BSPC, SP_CUR,  SP_FUNC, KC_UR19,                   KC_DEL,
    XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX
    )    ,

    [_CURSOR] = LAYOUT(
    _______, KC_1,    KC_UR01, KC_3,    KC_4,    KC_5,                      JP_PLUS, KC_TAB,  KC_UP,   KC_UR10, KC_UR07, _______,
    _______, KC_UR02, KC_UR03, KC_UR04, KC_UR05, KC_UR06,                   SP_LANG, KC_LEFT, KC_DOWN, KC_RGHT, KC_UR16, _______,
    _______, _______, _______, _______, _______, KC_DOT,  SP_SPRC, SP_SPRW, JP_ASTR, KC_UR11, KC_UR14, _______, _______, _______,
    _______,                   _______, _______, _______, _______, _______, _______, SP_LLCK, _______,                   _______,
    XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX
    )    ,

    [_FUNC] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                   SP_TO_MAC,SP_TO_PC, _______, _______, _______, _______,
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                  SP_TO_JIS,SP_TO_ANS,_______, _______, _______, _______,
    _______, _______, _______, _______, KC_F11,  KC_F12,  SP_SPRC, SP_SPRW, _______, _______, _______, _______, _______, _______,
    _______,                   _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
    XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX
    )    ,

    [_TENKEY] = LAYOUT(
    _______, KC_1,    KC_UR01, KC_3,    KC_4,    KC_5,                      _______, _______, KC_UP,   _______, _______, _______,
    _______, KC_UR02, KC_UR03, KC_UR04, KC_UR05, KC_UR06,                   _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, KC_DOT,  SP_SPRC, SP_SPRW, _______, _______, _______, _______, _______, _______,
    _______,                   _______, _______, KC_LSFT, KC_BSPC, _______, _______, SP_LLCK, _______,                   _______,
    XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX
    )    ,
};

void set_main_color(void) {
    rgblight_sethsv_noeeprom(HSV_CYAN);
}

void set_sub_color(void) {
    rgblight_sethsv_noeeprom(HSV_ORANGE);
}

void set_sub1_color(void) {
    rgblight_sethsv_noeeprom(HSV_PINK);
}

void set_sub2_color(void) {
    rgblight_sethsv_noeeprom(HSV_SPRINGGREEN);
}

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    set_main_color();
#ifdef CONSOLE_ENABLE
    debug_enable = true;
    debug_matrix = true;
#endif
}

#ifdef ENCODER_ENABLE
const uint8_t rt_matrix[][4][2] = {
    {{3,1},{3,2}},
    {{0,6},{1,6}},
    {{7,4},{7,5}},
    {{4,0},{5,0}},
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    keypos_t key;

    int cw = 0;
    if (clockwise) cw = 1;
    key.row = rt_matrix[index][cw][0];
    key.col = rt_matrix[index][cw][1];

    action_exec((keyevent_t) {
        .key = key, .pressed = true, .time = (timer_read() | 1)
    });
    action_exec((keyevent_t) {
        .key = key, .pressed = false, .time = (timer_read() | 1)
    });

    return false;
}
#endif

uint16_t get_shifted_key(uint16_t keycode) {
    for (int i = 0; i < auto_shift_map_cnt; i++) {
        if (auto_shift_map[i][0] == keycode) return auto_shift_map[i][current_layout];
    }
    return XXXXXXX;
}

uint16_t get_conv_jis_key(uint16_t keycode) {
    for (int i = 0; i < conv_jis_map_cnt; i++) {
        if (conv_jis_map[i][0] == keycode) return conv_jis_map[i][current_layout];
    }
    return XXXXXXX;
}

uint16_t get_conv_mod_key(uint16_t keycode) {
    for (int i = 0; i < conv_mod_map_cnt; i++) {
        if (conv_mod_map[i][0] == keycode) return conv_mod_map[i][current_target];
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

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }

void set_input_source(bool is_eisu) {
    // if (current_layout && current_target) {
    //     register_code(KC_LALT);
    //     tap_code(KC_GRV);
    //     unregister_code(KC_LALT);
    //     return;
    // }

    set_sub1_color();
    if (is_eisu) {
        tap_code(KC_LANG2);
    } else {
        tap_code(KC_LANG1);
    }
    // if (is_eisu) {
    //     if (current_target) {
    //         tap_code(KC_MHEN);
    //     } else {
    //         tap_code(KC_LANG2);
    //     }
    // } else {
    //     if (current_target) {
    //         tap_code(KC_HENK);
    //     } else {
    //         tap_code(KC_LANG1);
    //     }
    // }
    set_main_color();
}

void set_layer(bool is_set, uint16_t keycode) {
    uint16_t layer = _QWERTY;
    switch (keycode) {
        case SP_CUR:
            layer = _CURSOR;
            break;
        case SP_FUNC:
            layer = _FUNC;
            break;
        case SP_LLCK:
            layer = _TENKEY;
            break;
    }
    if (is_set) {
        layer_on(layer);
        set_sub_color();
    } else {
        layer_off(layer);
        if (!is_layer_lock) set_main_color();
    }
}

void get_captcha(uint16_t keycode) {
    register_code(KC_LSFT);
    register_code(KC_LGUI);
    register_code(KC_4);
    unregister_code(KC_4);
    unregister_code(KC_LGUI);
    unregister_code(KC_LSFT);
    if (keycode == SP_SPRW) {
        register_code(KC_SPC);
        unregister_code(KC_SPC);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t * record) {
    bool is_double_tap = record -> event.pressed && last_keycode == keycode && TIMER_DIFF_16(record -> event.time, pressed_time) < TAPPING_TERM + 100;
    last_keycode = keycode;
    if (record -> event.pressed) pressed_time = record -> event.time;
    switch (keycode) {
        case SP_SPRC:
        case SP_SPRW:
            if (record -> event.pressed) {
                get_captcha(keycode);
            }
            break;

        case SP_LLCK:
            if (record -> event.pressed) {
                is_layer_lock = ! is_layer_lock;
                set_layer(is_layer_lock, keycode);
            }
            break;

        case SP_CUR:
        case SP_FUNC:
            set_layer(record -> event.pressed, keycode);
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

        case KC_UR17:
        case KC_UR18:
        case KC_UR19:
            if (record -> event.pressed) {
                register_code(get_conv_mod_key(keycode));
            } else {
                unregister_code(get_conv_mod_key(keycode));
            }
            return false;
            break;

        case SP_TO_MAC:
            if (record -> event.pressed) {
                current_target = TARGET_MAC;
            }
            break;

        case SP_TO_PC:
            if (record -> event.pressed) {
                current_target = TARGET_PC;
            }
            break;

        case SP_TO_JIS:
            if (record -> event.pressed) {
                current_layout = LAYOUT_JIS;
            }
            break;

        case SP_TO_ANS:
            if (record -> event.pressed) {
                current_layout = LAYOUT_ANSI;
            }
            break;

        case SP_EISU:
            if (record -> event.pressed) {
                set_input_source(true);
            }
            break;

        case SP_KANA:
            if (record -> event.pressed) {
                set_input_source(false);
            }
            break;

        case KC_LCTL:
            if (record -> event.pressed) {
                is_timer = false;
            }
            break;

        case KC_RSFT:
            is_rshift_pressed = record -> event.pressed;
            break;

        case SP_TS:
            if (record -> event.pressed) {
                is_timer = true;
            }
            break;

        default:
            is_not_keypress = false;
            break;
    }
    return true;
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t * record) {
    uint16_t shifted_keycode = get_shifted_key(keycode);
    if (shifted_keycode == XXXXXXX) {
        if (shifted) add_weak_mods(MOD_BIT(KC_LSFT));
        register_code16((IS_RETRO(keycode)) ? keycode & 0xFFFF : keycode);
    } else {
        /* =キーなどのjis変換対応 */
        uint16_t conv_keycode = get_conv_jis_key(keycode);
        conv_keycode = conv_keycode == XXXXXXX ? keycode : conv_keycode;
        register_code16((!shifted) ? conv_keycode : shifted_keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t * record) {
    uint16_t shifted_keycode = get_shifted_key(keycode);
    if (shifted_keycode == XXXXXXX) {
        unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFFFF : keycode);
    } else {
        /* =キーなどのjis変換対応 */
        uint16_t conv_keycode = get_conv_jis_key(keycode);
        conv_keycode = conv_keycode == XXXXXXX ? keycode : conv_keycode;
        unregister_code16((!shifted) ? conv_keycode : shifted_keycode);
    }
}
