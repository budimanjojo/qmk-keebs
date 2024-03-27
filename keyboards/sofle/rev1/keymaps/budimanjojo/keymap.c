 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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

#include QMK_KEYBOARD_H
#include "oled.c"

//Default keymap. This can be changed in Via.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  Caps |    | Pscr  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LGUI | LAlt |Space | /  DEL  /       \ Bspc \  |Enter |   [  |  ]   |  \   |
 *            |      |      |      |LOWER |/       /         \      \ |RAISE |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[0] = LAYOUT(
    KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
    KC_ESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_CAPS, KC_PSCR, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
              KC_LCTL, KC_LGUI, KC_LALT, LT(1, KC_SPC),  KC_DEL,  KC_BSPC, LT(2, KC_ENT),    KC_LBRC, KC_RBRC, KC_BSLS
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      |                    |      |   7  |   8  |   9  |   *  |   =  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |      |      |      |      |      |-------.    ,-------|   ^  |   4  |   5  |   6  |   +  |  Num |
 * |------+------+------+------+------+------|  Caps |    | Pscr  |------+------+------+------+------+------|
 * |Shift |      |      |      |      |      |-------|    |-------|   $  |   1  |   2  |   3  |   -  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LGUI | LAlt |Space | /  DEL  /       \ Bspc \  |Enter |  0   |  .   |   /  |
 *            |      |      |      |LOWER |/       /         \      \ |RAISE |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[1] = LAYOUT(
    KC_NO,    KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    _______,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_EQL,
    _______,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_CIRC, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_NUM,
    _______,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______, _______, KC_DLR,  KC_1,    KC_2,    KC_3,    KC_MINS, _______,
                      _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_DOT,  KC_SLSH
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  F1  |  F2  |  F3  |  F4  |      |                    | Home | PgUp |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |  F5  |  F6  |  F7  |  F8  |      |-------.    ,-------| Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------|  Caps  |   | Pscr  |------+------+------+------+------+------|
 * |Shift |  F9  |  F10 |  F11 |  F12 |      |--------|   |-------|  End | PgDn |      |      |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LGUI | LAlt |Space | /  DEL  /       \ Bspc \  |Enter |      |      |      |
 *            |      |      |      |LOWER |/       /         \      \ |RAISE |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[2] = LAYOUT(
    KC_NO,    KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    _______,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_NO,                     KC_HOME, KC_PGUP, KC_NO,   KC_NO,   KC_NO,   KC_NO,
    _______,  KC_F5,  KC_F6,   KC_F7,   KC_F8,   KC_NO,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_NO,
    _______,  KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_NO,   _______, _______, KC_END,  KC_PGDN, KC_NO,   KC_NO,   KC_NO,   _______,
                      _______, _______, _______, _______, _______, _______, _______, KC_NO,   KC_NO,   KC_NO
),
/* ADJUST
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |CS+F1 |CS+F2 |CS+F3 |CS+F4 |      |                    |      |GUI+7 |GUI+8 |GUI+9 |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Caps |CS+F5 |CS+F6 |CS+F7 |CS+F8 |      |-------.    ,-------|      |GUI+4 |GUI+5 |GUI+6 |      |      |
 * |------+------+------+------+------+------|  Caps  |   | Pscr  |------+------+------+------+------+------|
 * |Shift |CS+F9 |CS+F10|CS+F11|CS+F12|      |--------|   |-------|      |GUI+1 |GUI+2 |GUI+3 |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LGUI | LAlt |Space | /  DEL  /       \ Bspc \  |Enter |      |      |      |
 *            |      |      |      |LOWER |/       /         \      \ |RAISE |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[3] = LAYOUT(
    KC_NO,    KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,                     KC_NO,   KC_NO,      KC_NO,      KC_NO,      KC_NO, KC_NO,
    _______,  RCS(KC_F1),  RCS(KC_F2),  RCS(KC_F3),  RCS(KC_F4),  KC_NO,                     KC_NO,   LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), KC_NO, KC_NO,
    KC_CAPS,  RCS(KC_F5),  RCS(KC_F6),  RCS(KC_F7),  RCS(KC_F8),  KC_NO,                     KC_NO,   LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), KC_NO, KC_NO,
    _______,  RCS(KC_F9),  RCS(KC_F10), RCS(KC_F11), RCS(KC_F12), KC_NO,   _______, _______, KC_NO,   LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), KC_NO, _______,
                           _______,     _______,     _______,     _______, _______, _______, _______, KC_NO,      KC_NO,      KC_NO
)
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(C(S(KC_TAB)), C(KC_TAB)), ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [1] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [2] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [3] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, 1, 2, 3);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* KEYBOARD PET STATUS START */
        case KC_LCTL:
        case KC_RCTL:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case LT(1, KC_SPC):
            if (record->tap.count && record->event.pressed) {
                isJumping  = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;

            /* KEYBOARD PET STATUS END */
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1, KC_SPC):
        case LT(2, KC_ENT):
            return 200;
        default:
            return TAPPING_TERM;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1, KC_SPC):
        case LT(2, KC_ENT):
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1, KC_SPC):
        case LT(2, KC_ENT):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}
