#pragma once

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
extern void (*pointing_device_set_button)(uint8_t btn);
extern void (*pointing_device_clear_button)(uint8_t btn);

extern bool is_lshift_press;
extern bool is_rshift_press;
extern bool is_lower_press;
extern bool is_raise_press;
extern uint16_t current_target;
extern uint16_t current_layout;

#define LAYOUT( \
    k001, k002, k003, k004, k005, k006, k007, k008, k009, k010, k011, k012, \
    k101, k102, k103, k104, k105, k106, k107, k108, k109, k110, k111, k112, \
    k201, k202, k203, k204, k205, k206, k207, k208, k209, k210, k211, k212, \
    k301,             k304, k305, k306, k307, k308, k309,             k312  \
) \
{ \
    { k001, k002, k003, k004, k005, k006, k007, k008, k009, k010, k011, k012 } , \
    { k101, k102, k103, k104, k105, k106, k107, k108, k109, k110, k111, k112 } ,  \
    { k201, k202, k203, k204, k205, k206, k207, k208, k209, k210, k211, k212 } , \
    { k301,KC_NO,KC_NO, k304, k305, k306, k307, k308, k309, KC_NO,KC_NO,k312 } , \
}

