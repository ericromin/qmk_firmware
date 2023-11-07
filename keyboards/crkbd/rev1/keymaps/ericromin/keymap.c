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

#include QMK_KEYBOARD_H

#define KC_C_NUM LT(_NUM, KC_C)
#define KC_X_NAV LT(_NAV, KC_X)

enum layers {
    _WIN,
    _MAC,
    _NAV,
    _NUM
};

enum combos {
    QW_ESC,
    AS_TAB,
    SD_GRV,
    ASDF_CAPS,
    UI_MINS,
    IO_EQL,
    OP_BSPC,
    JK_LPRN,
    KL_RPRN,
    JKL_LBRC,
    KLQUOT_RBRC,
    LQUOT_SCLN,
    JKLQUOT_BSLS
};

const uint16_t PROGMEM qw_combo[]       = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM as_combo[]       = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM sd_combo[]       = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM asdf_combo[]     = {KC_A, KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM ui_combo[]       = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM io_combo[]       = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM op_combo[]       = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM jk_combo[]       = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[]       = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM jkl_combo[]      = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM klquot_combo[]   = {KC_K, KC_L, KC_QUOT, COMBO_END};
const uint16_t PROGMEM lquot_combo[]    = {KC_L, KC_QUOT, COMBO_END};
const uint16_t PROGMEM jklquot_combo[]  = {KC_J, KC_K, KC_L, KC_QUOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [QW_ESC]          = COMBO(qw_combo, KC_ESCAPE),
  [AS_TAB]          = COMBO(as_combo, KC_TAB),
  [SD_GRV]          = COMBO(sd_combo, KC_GRAVE),
  [ASDF_CAPS]       = COMBO(asdf_combo, KC_CAPS_LOCK),
  [UI_MINS]         = COMBO(ui_combo, KC_MINS),
  [IO_EQL]          = COMBO(io_combo, KC_EQL),
  [OP_BSPC]         = COMBO(op_combo, KC_BACKSPACE),
  [JK_LPRN]         = COMBO(jk_combo, KC_LPRN),
  [KL_RPRN]         = COMBO(kl_combo, KC_RPRN),
  [JKL_LBRC]        = COMBO(jkl_combo, KC_LBRC),
  [KLQUOT_RBRC]     = COMBO(klquot_combo, KC_RBRC),
  [LQUOT_SCLN]      = COMBO(lquot_combo, KC_SEMICOLON),
  [JKLQUOT_BSLS]    = COMBO(jklquot_combo, KC_BACKSLASH)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WIN] = LAYOUT_36(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_Z,KC_X_NAV,KC_C_NUM,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                        KC_LCTL, KC_LSFT, KC_LALT,     KC_ENT,  KC_SPC, KC_RGUI
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
