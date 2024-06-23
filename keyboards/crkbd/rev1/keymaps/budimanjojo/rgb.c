/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
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

#include "color.h"
#include "rgb_matrix.h"
#include <stdint.h>
#include <action_layer.h>

#ifdef RGB_MATRIX_ENABLE

HSV hsv_by_layer_index(uint8_t layer_index) {
    switch (layer_index) {
        // NUMBER layer
        case 1:
            return (HSV){HSV_RED};
            break;
        // FUNC layer
        case 2:
            return (HSV){HSV_MAGENTA};
            break;
        // ADJUST layer
        case 3:
            return (HSV){HSV_GREEN};
            break;
        // MOUSE layer
        case 4:
            return (HSV){HSV_ORANGE};
            break;
        // SYMBOL layer
        case 5:
            return (HSV){HSV_PURPLE};
            break;
        default:
            return rgb_matrix_get_hsv();
            break;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // always go back to original color
    rgb_matrix_reload_from_eeprom();
    uint8_t mode = rgb_matrix_get_mode();

    uint8_t layer = get_highest_layer(state);

    if (layer > 0) {
        rgb_matrix_step_noeeprom();
        HSV hsv = hsv_by_layer_index(layer);
        rgb_matrix_sethsv_noeeprom(hsv.h, hsv.s, hsv.v);
    } else {
        rgb_matrix_mode_noeeprom(mode);
    }

    // TODO: find a better way to not place this here
    return update_tri_layer_state(state, 1, 2, 3);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t i = 0; i < led_max; ++i) {
            // set underglow color depending on active layer
            if HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW) {
                RGB rgb = hsv_to_rgb(hsv_by_layer_index(layer));
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            }
        }
    }
    return false;
}

#endif
