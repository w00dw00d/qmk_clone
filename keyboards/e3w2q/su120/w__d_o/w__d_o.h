/* Copyright 2019 e3w2q
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

#define RGBLIGHT_LAYERS
#undef RGBLED_NUM
#define RGBLED_NUM 57
#define RGBLIGHT_MAX_LAYERS 8
#define LAYOUT( \
    k012, k011, k010, k009, k008, k007, k006, k005, k004, k003, k002, k001, \
    k112, k111, k110, k109, k108, k107, k106, k105, k104, k103, k102, k101, \
    k212, k211, k210, k209, k208, k207, k206, k205, k204, k203, k202, k201, \
    k312, k311, k310, k309, k308, k307, k306, k305, k304, k303, k302, k301, \
    k412, k411, k410,       k408,       k406, k405,       k403, k402, k401  \
) \
{ \
    { k007, k107, k207, k307, KC_NO } , \
    { k008, k108, k208, k308, k408 } ,  \
    { k009, k109, k209, k309, KC_NO } , \
    { k010, k110, k210, k310, k410 } , \
    { k011, k111, k211, k311, k411 } , \
    { k012, k112, k212, k312, k412 } , \
    { k001, k101, k201, k301, k401 } , \
    { k002, k102, k202, k302, k402 } , \
    { k003, k103, k203, k303, k403 } , \
    { k004, k104, k204, k304, KC_NO } , \
    { k005, k105, k205, k305, k405 } , \
    { k006, k106, k206, k306, k406 } , \
}

#define RGBLIGHT_LED_MAP LED_LAYOUT( \
11, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1,  0, \
12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, \
35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, \
36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, \
56, 55, 54,     53,     52, 51,     50, 49, 48)
