#include QMK_KEYBOARD_H
#include "jtu_custom_keycodes.h"
#include "keymap_jp.h"
/*
https://github.com/koktoh/jtu_custom_keycodes/tree/master/default
キー	説明
JU_2	2 / Shift で @
JU_6	6 / Shift で ^
JU_7	7 / Shift で &
JU_8	8 / Shift で *
JU_9	9 / Shift で (
JU_0	0 / Shift で )
JU_2K	@
JU_6K	^
JU_7K	&
JU_8K	*
JU_9K	(
JU_0K	)
JU_MINS	- / Shift で _
JU_EQL	= / Shift で +
JU_LBRC	[ / Shift で {
JU_RBRC	] / Shift で }
JU_BSLS	\ / Shift で |
JU_SCLN	; / Shift で :
JU_QUOT	' / Shift で "
JU_GRV	` / Shift で ~
JU_CAPS	英数の大文字/小文字切り替え
*/
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
// #define _THIRD 3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = JTU_SAFE_RANGE ,
  LOWER,
  RAISE,
  //THIRD,
  ADJUST,
};

#define OR_EISU LALT(KC_GRV) // Henkan
#define OR_PRINT LALT(KC_PSCR) // Alt+PrintScreen
#define OR_TOP RCTL(KC_HOME) // TOP
#define OR_BOTOM RCTL(KC_END) // Bottom
#define OR_CTSPC RCTL(KC_SPC) // Ctl+Space
#define OR_OBJCT SEND_STRING("->") // Ctl+Space
#define OR_UNDER RSFT(JU_MINS) // _
#define OR_PLUS  RSFT(JU_EQL) // +
#define OR_DAI  RSFT(KC_COMM) // <
#define OR_SHO  RSFT(KC_DOT) // >
// static bool lower_pressed = false;
// static bool raise_pressed = false;

static uint16_t current_layer = _QWERTY;
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |  F13 |                    |  F14 |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |JU_GRV|                    |  F15 |   N  |   M  |   ,  |   .  |   /  | RGUI |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Esc  | Alt  |      |  F16 |||||||| Lower| Lower| Lower|||||||| Space| Enter| Raise|||||||| yen  |Print |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    JU_MINS,                        JU_EQL , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_F13,                         KC_F14,  KC_H,    KC_J,    KC_K,    KC_L,    JU_SCLN, JU_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    JU_GRV,                         KC_F15,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RGUI, \
    KC_ESC,  KC_LALT, _______, KC_F16,           LOWER,   LOWER,    LOWER,        KC_SPC, KC_ENT,  RAISE,            JP_YEN , OR_PRINT, _______, _______ \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Tab  |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  Del |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   1  |   2  |   3  |   4  |   5  |  F13 |                    |  F14 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  |JU_GRV|                    |  F15 |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Esc  | Alt  |      |  F16 |||||||| Lower| Lower| Lower|||||||| Space| Enter| Raise|||||||| yen  |Print |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_TAB,  KC_EXLM, JU_2K,   KC_HASH, KC_DLR,  KC_PERC, OR_UNDER,                       OR_PLUS, JU_6K,   JU_7K,   JU_8K,   JU_9K,   KC_RPRN, KC_DEL, \
    KC_LCTL, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_F13,                         KC_F14,  KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , \
    KC_LSFT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    JU_GRV,                         KC_F15,  KC_F7  , KC_F8  , KC_F9  , KC_F10,  KC_F11 , KC_F12 , \
    KC_ESC,  KC_LALT, _______, KC_F16,           LOWER,   LOWER,    LOWER,        KC_SPC, KC_ENT,  RAISE,            JP_YEN , OR_PRINT, _______, _______ \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F1  |  F2  |  F3  |  F5  |  F10 |  F12 |   /  |                    |   *  |      | Homw |  Up  |  End |  TOP |  Del |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   !  |   @  |   #  |   $  |   %  |  F13 |                    |  F14 |  H   | Left | Down | Right|Bottom|      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   ^  |   &  |   *  |   <  |   >  |JU_GRV|                    |  F15 |  M   |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Esc  | Alt  |      |  F16 |||||||| Lower| Lower| Lower|||||||| Space| Enter| Raise|||||||| yen  |Print |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F5,   KC_F10,  KC_F12,  KC_SLSH,                        JU_8K,   _______, KC_HOME, KC_UP,   KC_END,   OR_TOP,  KC_DEL, \
    KC_LCTL, KC_EXLM, JU_2K,   KC_HASH, KC_DLR,  KC_PERC, KC_F13,                         KC_F14,  KC_MHEN, KC_LEFT, KC_DOWN, KC_RGHT,  OR_BOTOM,_______, \
    KC_LSFT, JU_6K,   JU_7K,   JU_8K,   OR_DAI,  OR_SHO,  JU_GRV,                         KC_F15,  KC_HENK, _______, _______, _______,  _______, _______, \
    KC_ESC,  KC_LALT, _______, KC_F16,           LOWER,   LOWER,    LOWER,        KC_SPC, KC_ENT,  RAISE,            JP_YEN , OR_PRINT, _______, _______ \
    ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

void send_key_shift(uint16_t keycode) {
  register_code(KC_LSFT);
  register_code(keycode);
  unregister_code(keycode);
  unregister_code(KC_LSFT);
}

void send_key(uint16_t keycode) {
  register_code(keycode);
  unregister_code(keycode);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static bool lshift = false;
  static bool rshift = false;
  // static bool lctrl = false;
  // static bool rctrl = false;
  bool continue_process = process_record_user_jtu(keycode, record);
  if (continue_process == false) {
    return false;
  }
  switch (keycode) {
/*       case KC_SLSH:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          switch (current_layer) {
            case _QWERTY:
              SEND_STRING("?");
              break;
            case _LOWER:
              SEND_STRING("??");
              break;
            case _RAISE:
              SEND_STRING("???");
              break;
          }
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          return true;
        }
      }
      return false;
      break; */
    case KC_F13:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        // lctrl = keyboard_report->mods & MOD_BIT(KC_LCTL);
        // rctrl = keyboard_report->mods & MOD_BIT(KC_RCTL);
        unregister_code(KC_F13);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          switch (current_layer) {
            case _QWERTY:
              send_key_shift(KC_RBRC);
              break;
            case _LOWER:
              send_key(KC_RBRC);
              break;
            case _RAISE:
              send_key(KC_RBRC);
              break;
          }
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        // } else if (lctrl || rctrl) {
        //   if (lctrl) unregister_code(KC_LCTL);
        //   if (rctrl) unregister_code(KC_RCTL);
        //   send_key(KC_MHEN);
        //   if (lctrl) register_code(KC_LCTL);
        //   if (rctrl) register_code(KC_RCTL);
        } else {
          send_key_shift(KC_8);
        }
      }
      return false;
      break;
    case KC_F14:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        // lctrl = keyboard_report->mods & MOD_BIT(KC_LCTL);
        // rctrl = keyboard_report->mods & MOD_BIT(KC_RCTL);
        unregister_code(KC_F14);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          switch (current_layer) {
            case _QWERTY:
              send_key_shift(KC_NUHS);
              break;
            case _LOWER:
              send_key(KC_NUHS);
              break;
            case _RAISE:
              send_key(KC_NUHS);
              break;
          }
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        // } else if (lctrl || rctrl) {
        //   if (lctrl) unregister_code(KC_LCTL);
        //   if (rctrl) unregister_code(KC_RCTL);
        //   send_key(KC_HENK);
        //   if (lctrl) register_code(KC_LCTL);
        //   if (rctrl) register_code(KC_RCTL);
        } else {
          send_key_shift(KC_9);
        }
      }
      return false;
      break;
    case KC_F15:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        // lctrl = keyboard_report->mods & MOD_BIT(KC_LCTL);
        // rctrl = keyboard_report->mods & MOD_BIT(KC_RCTL);
        unregister_code(KC_F15);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          send_key_shift(KC_INT3);
          // switch (current_layer) {
          //   case _QWERTY:
          //     send_key_shift(KC_INT3);
          //     break;
          //   case _LOWER:
          //     send_key(KC_RBRC);
          //     break;
          //   case _RAISE:
          //     send_key(KC_RBRC);
          //     break;
          // }
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        // } else if (lctrl || rctrl) {
        //   if (lctrl) unregister_code(KC_LCTL);
        //   if (rctrl) unregister_code(KC_RCTL);
        //   send_key(KC_MHEN);
        //   if (lctrl) register_code(KC_LCTL);
        //   if (rctrl) register_code(KC_RCTL);
        } else {
          send_key_shift(KC_6);
        }
      }
      return false;
      break;
    case KC_F16:
      if (record->event.pressed) {
        SEND_STRING("->");
      //   lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
      //   rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
      //   // lctrl = keyboard_report->mods & MOD_BIT(KC_LCTL);
      //   // rctrl = keyboard_report->mods & MOD_BIT(KC_RCTL);
      //   unregister_code(KC_F15);
      //   if (lshift || rshift) {
      //     if (lshift) unregister_code(KC_LSFT);
      //     if (rshift) unregister_code(KC_RSFT);
      //     send_key_shift(KC_INT3);
      //     // switch (current_layer) {
      //     //   case _QWERTY:
      //     //     send_key_shift(KC_INT3);
      //     //     break;
      //     //   case _LOWER:
      //     //     send_key(KC_RBRC);
      //     //     break;
      //     //   case _RAISE:
      //     //     send_key(KC_RBRC);
      //     //     break;
      //     // }
      //     if (lshift) register_code(KC_LSFT);
      //     if (rshift) register_code(KC_RSFT);
      //   // } else if (lctrl || rctrl) {
      //   //   if (lctrl) unregister_code(KC_LCTL);
      //   //   if (rctrl) unregister_code(KC_RCTL);
      //   //   send_key(KC_MHEN);
      //   //   if (lctrl) register_code(KC_LCTL);
      //   //   if (rctrl) register_code(KC_RCTL);
      //   } else {
      //     send_key_shift(KC_6);
      //   }
      }
      return false;
      break;
    case JP_YEN:
      if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        // lctrl = keyboard_report->mods & MOD_BIT(KC_LCTL);
        // rctrl = keyboard_report->mods & MOD_BIT(KC_RCTL);
        unregister_code(KC_F15);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          send_key(KC_INT1);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          send_key(KC_INT3);
        }
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        // lower_pressed = true;
        layer_on(_LOWER);
        current_layer = _LOWER;
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        current_layer = _QWERTY;
        update_tri_layer(_LOWER, _RAISE, _ADJUST);

        // if (lower_pressed) {
        //   register_code(KC_MHEN);
        //   unregister_code(KC_MHEN);
        // }
        // lower_pressed = false;
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        // raise_pressed = true;
        layer_on(_RAISE);
        current_layer = _RAISE;
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        current_layer = _QWERTY;
        update_tri_layer(_LOWER, _RAISE, _ADJUST);

        // if (raise_pressed) {
        //   register_code(KC_HENK);
        //   unregister_code(KC_HENK);
        // }
        // raise_pressed = false;
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
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