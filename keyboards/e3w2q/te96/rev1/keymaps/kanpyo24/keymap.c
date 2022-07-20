/* Copyright 2020 e3w2q
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  SEND_00 = SAFE_RANGE,
  SEND_000
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Default Layer
   *  Master Side (USB Cable Connected Side)
   *  ,-----------------------------------------
   *  |    =    (    )   BS XXXX XXXX XXXX XXXX 
   *  | NmLk  KP/  KP*  Tab XXXX XXXX XXXX XXXX 
   *  |  KP7  KP8  KP9  KP- XXXX XXXX XXXX XXXX 
   *  |  KP4  KP5  KP6  KP+ XXXX XXXX XXXX XXXX 
   *  |  KP1  KP2  KP3 Entr XXXX XXXX XXXX XXXX 
   *  |  KP0   00    .    , XXXX XXXX XXXX XXXX 
   *  `-----------------------------------------
   *  Slave Side (USB Cable Not Connected Side)
   *  ,-----------------------------------------
   *  | XXXX XXXX XXXX XXXX XXXX XXXX XXXX XXXX 
   *  | XXXX XXXX XXXX XXXX XXXX XXXX XXXX XXXX 
   *  | XXXX XXXX XXXX XXXX XXXX XXXX XXXX XXXX 
   *  | XXXX XXXX XXXX XXXX XXXX XXXX XXXX XXXX 
   *  | XXXX XXXX XXXX XXXX XXXX XXXX XXXX XXXX 
   *  | XXXX XXXX XXXX XXXX XXXX XXXX XXXX XXXX 
   *  `-----------------------------------------
   */

  [0] = LAYOUT( /* Base */ 
    KC_EQL,   KC_LPRN,  KC_RPRN,  KC_BSPC,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    KC_NLCK,  KC_PSLS,  KC_PAST,  KC_TAB,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    KC_P7,    KC_P8,    KC_P9,    KC_PMNS,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    KC_P4,    KC_P5,    KC_P6,    KC_PPLS,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    KC_P1,    KC_P2,    KC_P3,    KC_ENT,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    KC_P0,    SEND_00,  KC_PDOT,  KC_COMM,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  

    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX   
  ),

  [1] = LAYOUT(
    RGB_TOG,  RGB_MOD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    RGB_HUI,  RGB_SAI,  RGB_VAI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    RGB_HUD,  RGB_SAD,  RGB_VAD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    EEP_RST,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  

    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX   
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SEND_00:
      if (record->event.pressed) {
        // when keycode SEND_00 is pressed
        SEND_STRING("00");
      } else {
        // when keycode SEND_00 is released
      }
      break;
    case SEND_000:
      if (record->event.pressed) {
        // when keycode SEND_000 is pressed
        //SEND_STRING("000" SS_TAP(X_ENTER));
        SEND_STRING("000");
      } else {
        // when keycode SEND_000 is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
