/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2024 Budiman Jojo

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

#define TAPPING_TERM 200
#define PERMISSIVE_HOLD_PER_KEY
#define QUICK_TAP_TERM_PER_KEY
#define SPLIT_LAYER_STATE_ENABLE
#define MASTER_LEFT
#define OLED_TIMEOUT 60000

#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#   define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#   define RGB_MATRIX_KEYPRESSES
#   define RGB_MATRIX_SLEEP
#   define RGB_MATRIX_TIMEOUT OLED_TIMEOUT
#   define RGB_MATRIX_HUE_STEP 8
#   define RGB_MATRIX_SAT_STEP 8
#   define RGB_MATRIX_VAL_STEP 8
#   define RGB_MATRIX_SPD_STEP 10
#endif
