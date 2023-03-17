#include "youkan44.h"

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.


#include "i2c_master.h"
#include "pointing_device.h"
#include "debug.h"

#include "iqs5xx.h"
#include "host.h"

#include "keymap_jp.h"

#define TP_TYPE_MTCH6102 0
#define TP_TYPE_IQS5XX 1
#define TP_TYPE_IQS5XX_BOOTLOADER 2


#define TP_TYPE TP_TYPE_IQS5XX

static int16_t send_flg_max = 3;
static int16_t send_flg_counter = 0;

static void dummy_func(uint8_t btn){};
void (*pointing_device_set_button)(uint8_t btn) = dummy_func;
void (*pointing_device_clear_button)(uint8_t btn) = dummy_func;

bool mouse_send_flg = false;
void pointing_device_task(void) {
    if (mouse_send_flg) {
        pointing_device_send();
        mouse_send_flg = false;
    }
}

void keyboard_pre_init_kb() {
    i2c_init();

    keyboard_pre_init_user();
}

void keyboard_post_init_kb() {
    debug_enable = true;
    debug_mouse  = true;
    debug_matrix = true;

    // setPinOutput(F4);
    // writePinHigh(F4);

    wait_ms(200);

#if TP_TYPE == TP_TYPE_MTCH6102
    init_mtch6102();
    pointing_device_set_button = pointing_device_set_button_mtch6102;
    pointing_device_clear_button = pointing_device_clear_button_mtch6102;
#elif TP_TYPE == TP_TYPE_IQS5XX
    check_iqs5xx();
    init_iqs5xx();
    pointing_device_set_button = pointing_device_set_button_iqs5xx;
    pointing_device_clear_button = pointing_device_clear_button_iqs5xx;
#endif

    ges_time = timer_read32();
    keyboard_post_init_user();
}

#if TP_TYPE == TP_TYPE_MTCH6102

void matrix_scan_kb() {
    static int      cnt = 0;
    static uint16_t last_read_time;
    mtch6102_data_t mtch6102_data;
    report_mouse_t  mouse_rep = {0};
    bool            is_valid  = false;

    // read mtch6102 data every 15ms
    if (timer_elapsed(last_read_time) > 15) {
        last_read_time = timer_read();
        is_valid       = read_mtch6102(&mtch6102_data);
    }

    if (is_valid) {
        bool send_flg = process_mtch6102(&mtch6102_data, &mouse_rep);

        if (send_flg) {
            mouse_send_flg = true;
            pointing_device_set_report(mouse_rep);
        }

        if (++cnt % 10 == 0) {
            if (debug_mouse) {
                dprintf("0x%02X 0x%02X %d %d\n", mtch6102_data.status, mtch6102_data.gesture, mtch6102_data.x, mtch6102_data.y);
            }
        }
    }

    matrix_scan_user();
}

#elif TP_TYPE == TP_TYPE_IQS5XX

bool update_send_flg_counter(void) {
    if (send_flg_counter >= send_flg_max) {
        send_flg_counter = 0;
        return true;
    }
    send_flg_counter++;
    return false;
}

void matrix_scan_kb() {
    static int cnt = 0;
    iqs5xx_data_t iqs5xx_data;
    report_mouse_t mouse_rep = {0};
    bool is_valid = false;

    is_valid = read_iqs5xx(&iqs5xx_data);

    if (is_valid) {
        static iqs5xx_processed_data_t iqs5xx_processed_data;
        static iqs5xx_gesture_data_t iqs5xx_gesture_data;
        bool send_flg = process_iqs5xx(&iqs5xx_data, &iqs5xx_processed_data, &mouse_rep, &iqs5xx_gesture_data);

        switch (iqs5xx_gesture_data.two.gesture_state) {
            case GESTURE_SWIPE_RU ... GESTURE_SWIPE_UL:
                if (is_lower_press) {
                    if(timer_elapsed32(ges_time) > GES_TIME_MS) {
                        if (current_target == 1) {
                            tap_code16(LGUI(KC_W));
                        } else {
                            tap_code16(LCTL(KC_W));
                        }
                        ges_time = timer_read32();
                    }
                } else {
                    mouse_rep.v = -1;
                    send_flg = update_send_flg_counter();
                }
                break;
            case GESTURE_SWIPE_LD ... GESTURE_SWIPE_DR:
                if (is_lower_press) {
                    if(timer_elapsed32(ges_time) > GES_TIME_MS) {
                        if (current_target == 1) {
                            tap_code16(LCTL(KC_UP));
                        } else {
                            tap_code16(LGUI(KC_TAB));
                        }
                        ges_time = timer_read32();
                    }
                } else {
                    mouse_rep.v = 1;
                    send_flg = update_send_flg_counter();
                }
                break;
            case GESTURE_SWIPE_R:
                if (!is_lower_press) {
                    if(timer_elapsed32(ges_time) > GES_TIME_MS) {
                        if (current_target == 1) {
                            if (current_layout == 1) {
                                tap_code16(LGUI(JP_RBRC));
                            } else {
                                tap_code16(LGUI(KC_RBRC));
                            }
                        } else {
                            tap_code16(KC_WFWD);
                        }
                        ges_time = timer_read32();
                    }
                } else {
                    mouse_rep.h = 1;
                    send_flg = update_send_flg_counter();
                }
                break;
            case GESTURE_SWIPE_L:
                if (!is_lower_press) {
                    if(timer_elapsed32(ges_time) > GES_TIME_MS) {
                        if (current_target == 1) {
                            if (current_layout == 1) {
                                tap_code16(LGUI(JP_LBRC));
                            } else {
                                tap_code16(LGUI(KC_LBRC));
                            }
                        } else {
                            tap_code16(KC_WBAK);
                        }
                        ges_time = timer_read32();
                    }
                } else {
                    mouse_rep.h = -1;
                    send_flg = update_send_flg_counter();
                }
                break;
            case GESTURE_PINCH_IN:
                tap_code16(LCTL(KC_EQL));
                break;
            case GESTURE_PINCH_OUT:
                tap_code16(LCTL(KC_MINS));
                break;
            default:
                break;
        }

        if (is_lshift_press) {
            mouse_rep.buttons |= 1;
        } else {
            mouse_rep.buttons &= ~0;
        }

        if (send_flg) {
            mouse_send_flg = true;
            pointing_device_set_report(mouse_rep);
        }

        if (++cnt % 10 == 0) {
            if (debug_mouse) {
                dprintf("%2d %2d %3d %3d %3d %3d %6u %4d %4d\n",
                iqs5xx_gesture_data.two.gesture_state,
                iqs5xx_data.finger_cnt,
                iqs5xx_data.fingers[0].current.x, iqs5xx_data.fingers[0].current.y,
                iqs5xx_data.fingers[1].current.x, iqs5xx_data.fingers[1].current.y,
                iqs5xx_gesture_data.two.dist_sq, iqs5xx_gesture_data.two.dot, iqs5xx_gesture_data.two.dot_rel);
            }
        }
    }

    matrix_scan_user();
}
#endif
