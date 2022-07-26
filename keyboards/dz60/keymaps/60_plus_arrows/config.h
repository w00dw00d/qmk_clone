#pragma once

#include "config_common.h"

<<<<<<< HEAD:keyboards/dz60/keymaps/60_plus_arrows/config.h
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

/* USB Device descriptor parameter */
#define VENDOR_ID       0x445A  // "DZ"
#define PRODUCT_ID      0x2260
#define DEVICE_VER      0x0001
#define MANUFACTURER    KBDFans
#define PRODUCT         DZ60

=======
>>>>>>> upstream/master:keyboards/dztech/bocc/config.h
/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
<<<<<<< HEAD:keyboards/dz60/keymaps/60_plus_arrows/config.h
#define MATRIX_ROW_PINS { D0, D1, D2, D3, D5 }
#define MATRIX_COL_PINS { F0, F1, E6, C7, C6, B7, D4, B1, B0, B5, B4, D7, D6, B3, F4 }
#define UNUSED_PINS
=======
#define MATRIX_ROW_PINS { B0, B1, B2, B3, F0 }
#define MATRIX_COL_PINS { B5, B6, C6, C7, F7, F6, F5, F4, F1, D1, D2, D3, D5, D4, D6, D7, B4 }
>>>>>>> upstream/master:keyboards/dztech/bocc/config.h

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* VIA related config */
#define VIA_EEPROM_LAYOUT_OPTIONS_SIZE 2

#define PREVENT_STUCK_MODIFIERS

#define LED_CAPS_LOCK_PIN B2
#define LED_PIN_ON_STATE 0

#define BACKLIGHT_PIN B6
#define BACKLIGHT_LEVELS 5

#define RGB_DI_PIN E2
#ifdef RGB_DI_PIN
#    define RGBLIGHT_ANIMATIONS
#    define RGBLED_NUM 16
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#    define RGBLIGHT_SLEEP
#endif
#define RGBLIGHT_LED_MAP { 0, 1,  2,  3,  4,  5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }
#define RGBLIGHT_LAYERS 8
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF

#define COMBO_COUNT 12

#define NO_ACTION_TAPPING
// #define NO_ACTION_ONESHOT
// #define NO_ACTION_MACRO