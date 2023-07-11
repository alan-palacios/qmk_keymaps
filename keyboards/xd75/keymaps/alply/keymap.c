/* Copyright 2017 Wunder
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

//Use with Spanish Keyboard 
#include QMK_KEYBOARD_H
#include "sendstring_spanish.h"

// Layer shorthand
#define DEV  MO(_DEV)
#define NUM  MO(_NUM)
#define SYSTEM MO(_SYSTEM)

enum xd75_layers {
 _QWERTY,
 _DEV,
 _NUM,
 _SYSTEM
};
/*
enum unicode_names {
    TILD,
    LPRN,
    RPRN,
    LBRC,
    RBRC,
    LCBR,
    RCBR,
    LT,
    GT,
    SCLN,
    COLN,
    CIRC,
    SLSH,
    BSLS,
    PIPE,
    GRAVE,
};

const uint32_t PROGMEM unicode_map[] = {
    [TILD]  = 0x007E,  // ~
    [LPRN] = 0x0028,  // (
    [RPRN]  = 0x0029, // )
    [LBRC] = 0x005B,  // [
    [RBRC]  = 0x005D, // ]
    [LCBR] = 0x007B,  // {
    [RCBR]  = 0x007D, // }
    [LT] = 0x003C,  // <
    [GT]  = 0x003E, // >
    [SCLN] = 0x003B,  // ;
    [COLN]  = 0x003A, // :
    [CIRC]  = 0x005E, // :
    [SLSH]  = 0x002F, // :   
    [BSLS]  = 0x005C, // :   
    [PIPE]  = 0x007C, // :   
    [GRAVE] = 0x0060, // 	`  
};
*/

enum custom_keycodes {
    HEART = SAFE_RANGE,
    COMMIT,
    ADD,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case HEART:
          if (record->event.pressed) {
              SEND_STRING("<3 ");
          }
          break;
      case ADD:
          if (record->event.pressed) {
              SEND_STRING("git add .");
          }
          break;
      case COMMIT:
          if (record->event.pressed) {
              SEND_STRING("git commit -m \"");
          }
          break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * | ESC    | 1      | 2      | 3      | 4      | 5      | HOME   | SUPR   | END    | 6      | 7      | 8      | 9      | 0      | BACKSP |

 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | !      | "      | ·      | $      | %      | HOME   | SUPR   | END    | &      | /      | (      | )      | =      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | CUT    | SLEEP  | EMOJI  | Y      | U      | I      | O      | P      | ´      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | LCTRL  | A      | S      | D      | F      | G      | COPY   | PRINT  | APP    | H      | J      | K      | L      | Ñ      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | PASTE  | APP    | UNDO   | N      | M      | ,      | .      | -      | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | SUPER  | CAPS   | ALT    | NUM    | SPACE  |        |        |        | SPACE  | DEV    | ALGR   | ¡      | \      | SYS    |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_QWERTY] = LAYOUT_ortho_5x15( /* QWERTY */
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    ADD,     _______, COMMIT,    KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    C(KC_X), KC_SLEP, HEART,     KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    ES_ACUT,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    C(KC_C), KC_PSCR, A(KC_SPC), KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    C(KC_V), KC_APP,  C(KC_Z),   KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LGUI, KC_LALT, NUM,     KC_SPC,  _______, KC_F24,  _______,   KC_SPC,  DEV,    KC_ALGR, KC_MINS, KC_EQL,  SYSTEM
  ),

/* DEV
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |   F1   |   F2   |   F3   |   F4   |   F5   |        |        |        |   F6   |   F7   |   F8   |   F9   |   F10  | SLEEP  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |   ~    |   $    |    (   |    )   |    /   |        |        |        |   "    |   '    |   +    |    -   |   *    |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |   ;    |   :    |   {    |    }   |    |   |        |        |        |  LEFT  | DOWM   |   UP   | RIGHT  |   &    |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |    <   |    >   |   [    |    ]   |    `   |        |        |        |   ?    |   =    |   ¿    |   ¡    |   \    |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_DEV] = LAYOUT_ortho_5x15( /* Symbols */
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, _______, KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_DEL,
    _______, ES_TILD, ES_DLR,  ES_LPRN, ES_RPRN, ES_SLSH, _______, _______, _______, ES_DQUO, ES_QUOT, ES_PLUS,  ES_MINS, ES_ASTR, _______,
    _______, ES_SCLN, ES_COLN, ES_LCBR, ES_RCBR, ES_PIPE, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT, ES_AMPR, _______,
    _______, ES_LABK, ES_RABK, ES_LBRC, ES_RBRC, ES_GRV,  _______, _______, _______, ES_QUES, ES_EQL,  ES_IQUE,  ES_IEXL,  ES_BSLS, _______,
    _______, _______, _______, _______, KC_LSFT, KC_LCTL, _______, _______, _______, _______, _______, _______,  _______, _______, _______
  ),

/* NUM
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        |        |        |   1    |    2   |    3   |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        |        |        |        |        |   4    |    5   |    6   |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |   7    |    8   |    9   |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |    0   |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_NUM] = LAYOUT_ortho_5x15( /* Numbers and functions */
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_F11,  _______,
    KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,    KC_F12,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_0,    _______, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

/* SYSTEM
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | RESET  | DEBUG  |        |        |        |        |        |        |        |        |        |        |        |        | SLEEP  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        | PLAY   | MUTE   |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        | VOL UP | VOL DWN|        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_SYSTEM] = LAYOUT_ortho_5x15( /* System functions */
    RESET,   DEBUG,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLEP,
    _______, _______, _______, _______, KC_MPLY, KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )
};
