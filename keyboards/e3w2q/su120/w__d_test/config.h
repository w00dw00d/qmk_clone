/*
Copyright 2019 e3w2q

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x1209
#define PRODUCT_ID      0x4649
#define DEVICE_VER      0x0001
#define MANUFACTURER    e3w2q
#define PRODUCT         SU120
#define DESCRIPTION     Expandable keyboard with up to 80 keys

/* key matrix size */
#define MATRIX_ROWS 2
#define MATRIX_COLS 2
#define DIODE_DIRECTION ROW2COL
#define MATRIX_ROW_PINS { D1, D0 }
#define MATRIX_COL_PINS { B1, F7 }
#define UNUSED_PINS
#define DEBOUNCE 5
#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

#define PS2_DRIVER_INTERRUPT

#ifdef PS2_DRIVER_INTERRUPT
#define PS2_CLOCK_PIN   D2
#define PS2_DATA_PIN    D5

#define PS2_INT_INIT()  do {    \
    EICRA |= ((1<<ISC21) |      \
              (0<<ISC20));      \
} while (0)
#define PS2_INT_ON()  do {      \
    EIMSK |= (1<<INT2);         \
} while (0)
#define PS2_INT_OFF() do {      \
    EIMSK &= ~(1<<INT2);        \
} while (0)
#define PS2_INT_VECT   INT2_vect
#endif
