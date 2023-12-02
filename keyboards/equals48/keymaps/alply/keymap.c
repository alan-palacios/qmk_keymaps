//Use with Spanish Keyboard 
#include QMK_KEYBOARD_H
#include "sendstring_spanish.h"

// Layer shorthand
#define DEV  MO(_DEV)
#define NUM  MO(_NUM)
#define SYSTEM MO(_SYSTEM)

enum layers {
 _QWERTY,
 _DEV,
 _NUM,
 _SYSTEM
};

enum custom_keycodes {
    HEART = SAFE_RANGE,
    COMMIT,
    ADD,
    CLEAR_EEPROM,
    RICK,
    RUDOLPH
};
float the_song[][2] = SONG(THE_SONG);
float rudolph_song[][2] = SONG(RUDOLPH_MELODY);

float git_add_sound[][2] = {
    {NOTE_G5, 4}, // G5 note, 1/4th duration
};

float git_commit_sound[][2] = {
    {NOTE_C5, 4}, // G5 note, 1/4th duration
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
              PLAY_SONG(git_add_sound);
          }
          break;
      case COMMIT:
          if (record->event.pressed) {
              SEND_STRING("git commit -m \"");
              PLAY_SONG(git_commit_sound);
          }
          break;
      case CLEAR_EEPROM:
          if (record->event.pressed) {
              eeconfig_init();
          }
          break;
      case RICK:
          if (record->event.pressed) {
              PLAY_SONG(the_song);
          }
          break;
      case RUDOLPH:
          if (record->event.pressed) {
              PLAY_SONG(rudolph_song);
          }
          break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------. 
   | TAB    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | Backsp | 
   |--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------| 
   | LCTRL  | A      | S      | D      | F      | G      | H      | J      | K      | L      | Ñ      | ENTER  | 
   |--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------| 
   | LSHIFT | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | -      | ´      | 
   |--------+--------+--------+--------+--------+-----------------+--------+-----------------+--------+--------| 
   | RCTRL  | SUPER  | CAPS   | ALT    | NUM    | SPACE  | SPACE  | DEV    | ALGR   | ¡      | \      | SYS    | 
   '-----------------------------------------------------------------------------------------------------------' */

  [_QWERTY] = LAYOUT_ortho_4x12( /* QWERTY */
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    ES_ACUT, KC_LGUI, KC_LGUI, KC_LALT, NUM,     KC_ESC,  KC_SPC,  DEV,    KC_ALGR, KC_MINS, KC_EQL,  SYSTEM
  ),

/* DEV
 * .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------.
 * |        |   ~    |   $    |    (   |    )   |    /   |   "    |   '    |   +    |    -   |   *    | DELETE |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |   ;    |   :    |   {    |    }   |    |   |  LEFT  | DOWM   |   UP   | RIGHT  |   &    |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |    <   |    >   |   [    |    ]   |    `   |   ?    |   =    |   ¿    |   ¡    |   \    |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------'
 */

  [_DEV] = LAYOUT_ortho_4x12( /* Symbols */
    _______, ES_TILD, ES_DLR,  ES_LPRN, ES_RPRN, ES_SLSH, ES_DQUO, ES_QUOT, ES_PLUS,  ES_MINS, ES_ASTR, KC_DEL,
    _______, ES_SCLN, ES_COLN, ES_LCBR, ES_RCBR, ES_PIPE, KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT, ES_AMPR, _______,
    _______, ES_LABK, ES_RABK, ES_LBRC, ES_RBRC, ES_GRV,  ES_QUES, ES_EQL,  ES_IQUE,  ES_IEXL, ES_BSLS, _______,
    _______, _______, _______, _______, KC_LSFT, KC_LCTL, _______, _______, _______,  _______, _______, _______
  ),

/* NUM
 * .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------'
 */

  [_NUM] = LAYOUT_ortho_4x12( /* Numbers and functions */
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F11,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

/* SYSTEM
 * .-----------------------------------------------------------------------------------------------------------.
 * | RESET  | WIN+1  | WIN+2  | WIN+3  | PLAY   | MUTE   |        |        |        |        |        | SLEEP  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |Listary | PrntSc | Discord| VOL UP | VOL DWN|        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
 */

  [_SYSTEM] = LAYOUT_ortho_4x12( /* System functions */
    QK_BOOT,      LGUI(KC_1),   LGUI(KC_2), LGUI(KC_3),		   KC_MPLY, ADD,     COMMIT,  _______, _______, _______, _______, KC_SLEP,
    CLEAR_EEPROM, LALT(KC_SPC), KC_PSCR,	   LCTL(LSFT(KC_M)), KC_VOLD, KC_VOLU, HEART,   _______, _______, _______, _______, _______,
    RICK,         _______,	     _______,	   _______,			     _______, _______, _______, _______, _______, _______, _______, _______,
    RUDOLPH,      _______,	     _______,    _______, 		     _______, _______, _______, _______, _______, _______, _______, _______
  )
};
