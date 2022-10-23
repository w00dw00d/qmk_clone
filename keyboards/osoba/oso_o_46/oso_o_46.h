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
    k001, k002, k003, k004, k005, k006, k007, k008, k009, k010, k011, k012, \
    k101, k102, k103, k104, k105, k106, k107, k108, k109, k110, k111, k112, \
    k201, k202, k203, k204, k205, k206, k207, k208, k209, k210, k211, k212, \
    k301, k302, k303, k304, k305, k306, k307, k308, k309, k310, k311, k312, \
    k401, k402, k403,       k405, k406, k407, k408,      k410, k411, k412  \
) \
{ \
    { k001, k002, k003, k004, k005, k006, k007, k008, k009, k010, k011, k012 } , \
    { k101, k102, k103, k104, k105, k106, k107, k108, k109, k110, k111, k112 } ,  \
    { k201, k202, k203, k204, k205, k206, k207, k208, k209, k210, k211, k212 } , \
    { k301, k302, k303, k304, k305, k306, k307, k308, k309, k310, k311, k312 } , \
    { k401, k402, k403, KC_NO, k405, k406, k407, k408, KC_NO, k410, k411, k412 } , \
}

