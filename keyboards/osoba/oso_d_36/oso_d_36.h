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

#define LAYOUT( \
    k001, k002, k003, k004, k005, k006, k007, k008, k009, k010, \
    k101, k102, k103, k104, k105, k106, k107, k108, k109, k110, \
    k201, k202, k203, k204, k205, k206, k207, k208, k209, k210, \
                k303, k304, k305, k306, k307, k308              \
) \
{ \
    { k001, k002, k003, k004, k005, k006, k007, k008, k009, k010 } , \
    { k101, k102, k103, k104, k105, k106, k107, k108, k109, k110 } ,  \
    { k201, k202, k203, k204, k205, k206, k207, k208, k209, k210 } , \
    { KC_NO,KC_NO,k303, k304, k305, k306, k307, k308,KC_NO,KC_NO } , \
}

