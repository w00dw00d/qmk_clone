/* Copyright 2021 daraku-neko
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
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    C(KC_Z),   KC_1,    KC_2,     KC_3,    KC_4,          KC_5,
    KC_F24,    KC_6,    KC_7,     KC_8,    KC_9,          KC_0,
    C(KC_Y),   KC_BSPC, KC_QUOT,  KC_SPC,  SFT_T(KC_ENT), MO(1),
    KC_MS_BTN1, KC_MS_BTN2
  ),

  [1] = LAYOUT(
    C(KC_Z),   KC_1,    KC_2,     KC_3,    KC_4,          KC_5,
    KC_F24,    KC_6,    KC_7,     KC_8,    KC_9,          KC_0,
    C(KC_Y),   KC_BSPC, KC_QUOT,  KC_SPC,  SFT_T(KC_ENT), MO(1),
    KC_MS_BTN1, KC_MS_BTN2
  ),

  [2] = LAYOUT(
    C(KC_Z),   KC_1,    KC_2,     KC_3,    KC_4,          KC_5,
    KC_F24,    KC_6,    KC_7,     KC_8,    KC_9,          KC_0,
    C(KC_Y),   KC_BSPC, KC_QUOT,  KC_SPC,  SFT_T(KC_ENT), MO(1),
    KC_MS_BTN1, KC_MS_BTN2
  ),

  [3] = LAYOUT(
    C(KC_Z),   KC_1,    KC_2,     KC_3,    KC_4,          KC_5,
    KC_F24,    KC_6,    KC_7,     KC_8,    KC_9,          KC_0,
    C(KC_Y),   KC_BSPC, KC_QUOT,  KC_SPC,  SFT_T(KC_ENT), MO(1),
    KC_MS_BTN1, KC_MS_BTN2
  )
};

keyevent_t encoder1_ccw = {
    .key = (keypos_t){.row = 4, .col = 2},
    .pressed = false
};

keyevent_t encoder1_cw = {
    .key = (keypos_t){.row = 4, .col = 3},
    .pressed = false
};

void matrix_scan_user(void) {
    if (IS_PRESSED(encoder1_ccw)) {
        encoder1_ccw.pressed = false;
        encoder1_ccw.time = (timer_read() | 1);
        action_exec(encoder1_ccw);
    }

    if (IS_PRESSED(encoder1_cw)) {
        encoder1_cw.pressed = false;
        encoder1_cw.time = (timer_read() | 1);
        action_exec(encoder1_cw);
    }
}

bool is_hold = false;

void encoder_layer_up(void) {
  if (get_highest_layer(layer_state|default_layer_state) == 3 ) {
    layer_clear();
  } else {
    layer_move(get_highest_layer(layer_state)+1);
  }
}

void encoder_layer_down(void) {
    if (get_highest_layer(layer_state|default_layer_state) == 0 ) {
      layer_move(3);
    } else {
      layer_move(get_highest_layer(layer_state)-1);
    }
}

void encoder_ccw(void) {
  encoder1_ccw.pressed = true;
  encoder1_ccw.time = (timer_read() | 1);
  is_hold ? encoder_layer_down() : action_exec(encoder1_ccw);
}

void encoder_cw(void) {
  encoder1_cw.pressed = true;
  encoder1_cw.time = (timer_read() | 1);
  is_hold ? encoder_layer_up() : action_exec(encoder1_cw);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { clockwise ? encoder_cw() : encoder_ccw(); }
    return true;
}

void matrix_init_kb(void) {
  debug_enable = true;
  debug_matrix = true;
  debug_mouse  = true;
}

void debug_string(char *str) {
    send_string(str);
    tap_code(KC_ENT);
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  static uint16_t pressed_time = 0;
  switch (keycode) {
      case KC_BTN1 ... KC_BTN5:
        if (record->event.pressed) {
          pointing_device_set_button(1 << (keycode - KC_BTN1));
        } else {
          pointing_device_clear_button(1 << (keycode - KC_BTN1));
        }
      return false;
      break;
    case KC_F24:
      if (record->event.pressed) {
        pressed_time = record->event.time;
        if(!is_hold){
            encoder_layer_up();
        }
        is_hold = false;
      } else {
          if((record->event.time - pressed_time) > TAPPING_TERM) {
            is_hold = true;
          }
      }
      return false;
    default:
      return true;
  }
};

void eeconfig_init_user(void) {

}

