/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up |      | Knob 2: Page Dn/Up |
        | Press: Mute       | Home | Press: Play/Pause  |
        | Left click        | Up   | Right click        |
        | Left              | Down | Right              |
     */
    [0] = LAYOUT(
        KC_MUTE      , MO(1)        , KC_MPLY,
        KC_BTN1      , LCTL(KC_UP)  , KC_BTN2,
        LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_RGHT)
    ),
    /*
        | RESET          | Held: Layer 2  | Media Stop |
        | Left click     | Home           | RGB Mode   |
        | Media Previous | End            | Media Next |
     */
    [1] = LAYOUT(
        RESET  , _______, KC_STOP,
        KC_BTN1, KC_HOME, KC_BTN2,
        KC_MPRV, KC_END , KC_MNXT
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
        }
    }
}
