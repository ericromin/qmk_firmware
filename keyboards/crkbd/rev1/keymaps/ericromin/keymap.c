/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

enum layers {
    _WIN,
    _MAC,
    _NAV,
    _NUM
};

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WIN] = LAYOUT_36(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         KC_LCTL, KC_LALT, KC_LSFT,     KC_SPC,  KC_ENT, KC_RGUI
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
  ),

    [_MAC] = LAYOUT_36(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, KC_LGUI,    _______, _______, KC_RALT
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
    ),

    [_NAV] = LAYOUT_36(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
      TO(_WIN),TO(_MAC), XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX,TG(_NUM),TG(_NAV), XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, _______,    _______, _______, _______
  //                   ╰───────────────────────────╯ ╰───────────────────────────╯
  ),

    [_NUM] = LAYOUT_36(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
      TO(_WIN),TO(_MAC), XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    KC_7,    KC_8,    KC_9, KC_MINS,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    KC_4,    KC_5,    KC_6,  KC_EQL,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX,TG(_NUM),TG(_NAV), XXXXXXX, XXXXXXX,    XXXXXXX,    KC_1,    KC_2,    KC_3, _______,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, _______,    _______, _______,    KC_0
  //                   ╰───────────────────────────╯ ╰───────────────────────────╯
  ),

//     [4] = LAYOUT_36(
//   // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
//        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
//        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
//        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
//                          _______, _______, _______,    _______, _______, _______
//   //                   ╰───────────────────────────╯ ╰───────────────────────────╯
//   )
};
