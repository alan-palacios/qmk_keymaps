/* Copyright 2020 ipetepete
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
  * qmk compile -kb bm60poker -km alply
  * keyboard layout:
  * http://www.keyboard-layout-editor.com/#/gists/4ff28e170718596d56ca3e4c168067c4  
  */ 
#include QMK_KEYBOARD_H

enum layers {
_QWERTY,
_SPCFN,
_DEV,
_RGB,
_GAMER
};


enum keycodes {
    ST_QWERTY,
    ST_GAMER = SAFE_RANGE,
    ST_DEV,
    SLEEP
};
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
#define KC_SPCFN LT(_SPCFN, KC_SPC) // press for space, hold for function layer (aka spacefn)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* 0: qwerty */
  /*┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
    │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Bcksp │
    ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
    │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │ \   │
    ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬────│
    │ Ctrl │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
    ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
    │  Shift │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │  Shift   │
    ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
    │Ctrl│GUI │Alt │         Space          │Cmd │Hypr│ Fn │Ctrl│
    └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘*/
  [_QWERTY] = LAYOUT_60_ansi( /* Layer 0: Qwerty */
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_RSFT,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,      KC_ENT     ,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,         KC_RSFT          ,
    KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPCFN,                                    RGB_TOG, KC_RCTL, MO(_DEV), MO(_RGB)
  ),
  /* 1: SPCFN most used keys */
  /*┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
    │ § │Br-│Br+│   │   │BL-│BL+│Pre│Pau│Nxt│Mut│Vo-│Vo+│  Del  │
    ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
    │     │   │   │   │   │   │Hom│pDw│pUp│End│   │   │   │ Ins │
    ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐----│
    │      │   │   │   │   │   │ ◄ │ ▼ │ ▲ │ ►  │  │   │        │
    ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
    │        │   │   │   │   │BL~│   │   │   │   │   │          │
    ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
    │    │    │    │                        │    │    │    │    │
    └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘*/
  [_SPCFN] = LAYOUT_60_ansi( /* Layer 1: Functions */
    _______,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, _______, _______,
    KC_CAPS, _______, _______, KC_LSFT, KC_LCTL, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,      _______    ,
    _______, _______, _______, _______, _______, _______, KC_PSCR, KC_APP, _______, _______, _______,          _______        ,
    _______, _______, _______,                   _______,                                     _______, _______, _______, _______
  ),
  /* 3: DEV symbols */
  /*┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
    │Pwr│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│ Eject │
    ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
    │     │   │   │   │   │   │   │   │   │   │   │   │   │     │
    ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐----│
    │ Caps │   │   │   │   │   │Hom│PgD│PgU│End│   │   │        │
    ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
    │        │   │   │   │   │Rst│   │   │   │   │   │          │
    ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
    │    │    │    │                        │    │    │    │    │
    └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘*/
  [_DEV] = LAYOUT_60_ansi( /* Layer 2: Functions */
    RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
    _______, X(TILD), X(CIRC), X(LPRN), X(RPRN), X(SLSH), X(BSLS), _______, _______, _______, _______, _______, _______, _______,
    _______, X(SCLN), X(COLN), X(LCBR), X(RCBR), X(PIPE), _______, _______, _______, _______,  _______, _______,      _______    ,
    _______, X(LT),   X(GT),   X(LBRC), X(RBRC), X(GRAVE), _______, _______, _______, _______, _______,           _______        ,
    _______, _______, _______,                   _______,                                     _______, _______, _______, _______
  ),
   
  /* 4: RGB, media and reset keys */
  /*┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
    │Pwr│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│ Eject │
    ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
    │     │   │   │   │   │   │   │   │   │   │   │   │   │     │
    ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐----│
    │ Caps │   │   │   │   │   │Hom│PgD│PgU│End│   │   │        │
    ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
    │        │   │   │   │   │Rst│   │   │   │   │   │          │
    ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
    │    │    │    │                        │    │    │    │    │
    └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘*/
  [_RGB] = LAYOUT_60_ansi( /* Layer 2: Functions */
    RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, SLEEP, 
    _______, RGB_HUD, RGB_HUI, RGB_TOG, KC_MPLY, KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, RGB_SAD, RGB_SAI, RGB_MOD, KC_VOLD, KC_VOLU, _______, _______, _______, _______,  _______, _______,      _______    ,
    _______, RGB_VAD, RGB_VAI, RGB_RMOD, RGB_M_P, _______, _______, _______, ST_QWERTY, ST_GAMER, ST_DEV,           _______        ,
    _______, _______, _______,                   _______,                                     _______, _______, _______, _______
  ),

  [_GAMER] = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                            KC_SPACE,                            _______, _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case ST_QWERTY:
        if (record->event.pressed) {
            layer_clear();
            layer_on(_QWERTY);
            set_single_persistent_default_layer(_QWERTY);
        }
        return false;
        break;
      case ST_GAMER:
        if (record->event.pressed) {
            layer_clear();
            layer_on(_GAMER);
        }
        return false;
        break;
      case ST_DEV:
        if (record->event.pressed) {
            layer_clear();
            layer_on(_DEV);
        }
        return false;
        break;
      case SLEEP:
        if (record->event.pressed) {
            if (rgb_matrix_is_enabled()){
              rgb_matrix_toggle();
            }
            register_code(KC_SLEP);
            unregister_code(KC_SLEP);
            //register_code(KC_LGUI);
            //register_code(RGB_TOG);
        }
        return false;
        break;
  }
  return true;
}

void rgb_matrix_layer_helper (uint8_t hue, uint8_t sat) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
        uint8_t val = rgb_matrix_get_val();
        HSV hsv = {.h = hue, .s = sat, .v = val+10};
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.b, rgb.g);  
        //rgb_matrix_set_color( i, red, green, blue);
    }
  }
}


void rgb_matrix_indicators_kb(void)
{
	if (!g_suspend_state && rgb_matrix_config.enable) {
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                rgb_matrix_layer_helper( 100 , 210);
                break;
            case _DEV:
                rgb_matrix_layer_helper( 170, 255);
                break;
            case _SPCFN:
                rgb_matrix_layer_helper( 0, 255);
                break;
            case _RGB:
                rgb_matrix_layer_helper( 75, 255);
                break;
        }
    }
}
