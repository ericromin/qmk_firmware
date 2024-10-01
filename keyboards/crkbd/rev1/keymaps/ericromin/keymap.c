/*
Copyright 2019 @foostan

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

#ifdef RGBLIGHT_ENABLE
    #include "rgblight.h"
#endif

#ifdef RGB_MATRIX_ENABLE
    #include "quantum/rgb_matrix/rgb_matrix.h"
#endif


#define FWORD   LCTL(KC_RIGHT)      // Skip one word forward
#define BWORD   LCTL(KC_LEFT)       // Skip one word back
#define FTAB    LCTL(KC_TAB)        // Browser tab forward
#define BTAB    LSFT(LCTL(KC_TAB))  // Browser tab back
#define CTALDT  LCTL(LALT(KC_DEL))  // Ctrl-Alt-Delete
#define COPY    LCTL(KC_C)
#define CUT     LCTL(KC_X)
#define PASTE   LCTL(KC_V)
#define UNDO    LCTL(KC_Z)
#define REDO    LCTL(KC_Y)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WIN] = LAYOUT_36(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         KC_LCTL, KC_LSFT, KC_LALT,     KC_ENT,  KC_SPC, KC_RGUI
  //                   ╰───────────────────────────╯ ╰──────────────────────────╯
  ),

//     [_MAC] = LAYOUT_36(
//   // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
//        _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
//   // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
//        _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
//   // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
//        _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
//   // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
//                          _______, _______, KC_LGUI,    _______, _______, KC_LALT
//   //                   ╰───────────────────────────╯ ╰──────────────────────────╯
//     ),

    [_NAV] = LAYOUT_36(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       _______, _______, _______, _______, _______,       REDO, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _______, _______, _______, _______, _______,    _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          UNDO,     CUT,    COPY,   PASTE, _______,    _______,   BWORD,    BTAB,    FTAB,   FWORD,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, _______,    _______, _______, _______
  //                   ╰───────────────────────────╯ ╰───────────────────────────╯
  ),

    [_NUM] = LAYOUT_36(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       _______, _______, _______, _______, _______,    _______,    KC_7,    KC_8,    KC_9,  CTALDT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _______, _______, _______, _______, _______,    _______,    KC_4,    KC_5,    KC_6,  KC_DOT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _______, _______, _______, _______, _______,    _______,    KC_1,    KC_2,    KC_3, _______,
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

layer_state_t layer_state_set_user(layer_state_t state) {
    switch(get_highest_layer(state)) {
        case _NAV:
            setrgb(255, 0, 0); // Red
            break;
        case _NUM:
            setrgb(0, 0, 255); // Blue
            break;
        case _MAC:
            setrgb(255, 255, 0); // Yellow
            break;
        default:
            setrgb(255, 255, 255); // White
            break;
    }
    return state;
}

// void rgb_matrix_indicators_user(void) {
//     switch (get_highest_layer(layer_state)) {
//         case _NAV:
//             rgb_matrix_set_color_all(255,0,0);
//             break;
//         case _NUM:
//             rgb_matrix_set_color_all(0,0,255);
//             break;
//         case _MAC:
//             rgb_matrix_set_color_all(255,255,0);
//             break;
//         default:
//             rgb_matrix_set_color_all(255,255,255);
//             break;
//     }
// }
