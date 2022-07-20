#pragma once

#include "config_common.h"

#define RGB_DI_PIN E2
#ifdef RGB_DI_PIN
#    define RGBLIGHT_ANIMATIONS
#    define RGBLED_NUM 16
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#    define RGBLIGHT_SLEEP
#endif

#define RGBLIGHT_LED_MAP { 0,  1,  2,  3,  4,  5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }
#define RGBLIGHT_LAYERS 8
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
