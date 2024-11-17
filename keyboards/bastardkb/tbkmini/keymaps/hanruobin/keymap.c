/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation     , either version 2 of the License     , or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not     , see <http://www.gnu.org/licenses/>.
 */

// #include <queue>
#include QMK_KEYBOARD_H


// #define _LAYER0 0
// #define _LAYER1 1
// #define _LAYER2 2
// #define _LAYER3 3
// #define QMK_FAST_BSPC

enum layers {
    _BASE,
    _SYM,
    _NAV,
    _THIRD
};

enum {
    TD_SPC_TAB,
};

// enum custom_keycodes {
//     TD_ESC_CAPS = SAFE_RANGE,
// };

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_SPC_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_TAB),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(0,KC_Z):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_Z)); // Intercept hold function to send Ctrl-X
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(0,KC_X):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_X)); // Intercept hold function to send Ctrl-X
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(0,KC_C):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_C)); // Intercept hold function to send Ctrl-C
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(0,KC_V):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_V)); // Intercept hold function to send Ctrl-C
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(0,KC_BSPC):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(C(KC_BSPC)); // Intercept hold function to send Ctrl-BSPC
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_split_3x6_3(
KC_TAB         , KC_Q     , KC_W     , KC_E     , KC_R          , KC_T              ,             KC_Y  , KC_U          , KC_I     , KC_O     , KC_P     , KC_ESC  ,
ALT_T(KC_ESC)  , KC_A     , KC_S     , KC_D     , KC_F          , KC_G              ,             KC_H  , KC_J          , KC_K     , KC_L     , KC_SCLN  , KC_QUOT ,
KC_LSFT        , KC_Z     , KC_X     , KC_C     , KC_V          , KC_B              ,             KC_N  , KC_M          , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RGUI ,
                                   CTL_T(KC_DEL), SFT_T(KC_ENT) , LT(_SYM,KC_SPC)   ,           MO(_NAV), TD(TD_SPC_TAB), KC_BSPC
),

[_SYM] = LAYOUT_split_3x6_3(
    KC_TRNS  , KC_EXLM  , KC_AT    , KC_HASH  , KC_DLR   , KC_PERC  ,             KC_CIRC  , KC_AMPR  , KC_ASTR  , KC_LPRN  , KC_RPRN  , KC_ESC     ,
    KC_TRNS  , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,             KC_UNDS  , KC_PLUS  , KC_TILD  , KC_LBRC  , KC_RBRC  , KC_PIPE    ,
    KC_TRNS  , KC_6     , KC_7     , KC_8     , KC_9     , KC_0     ,             KC_MINS  , KC_EQL   , KC_GRV   , KC_LCBR  , KC_RCBR  , KC_BSLS    ,
                                     KC_TRNS  , KC_TRNS  , KC_TRNS  ,             KC_TRNS  , KC_TRNS  , MO(_THIRD)
    ),

[_NAV] = LAYOUT_split_3x6_3(
    KC_TRNS  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,             KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_PSCR    ,
    KC_TRNS  , KC_MPRV  , KC_MNXT  , KC_VOLD  , KC_VOLU  , KC_MUTE  ,             KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , KC_TRNS  , KC_TRNS    ,
    KC_TRNS  , KC_NO    , KC_NO    , KC_BRID  , KC_BRIU  , KC_MPLY  ,             KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , KC_INS   , KC_TRNS    ,
                                     KC_TRNS  , KC_TRNS  , KC_TRNS  ,             KC_TRNS  , KC_TRNS  , KC_TRNS
    ),

[_THIRD] = LAYOUT_split_3x6_3(
    QK_BOOT  , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,             KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO      ,
    RGB_TOG  , RGB_HUI  , RGB_SAI  , RGB_VAI  , KC_NO    , KC_NO    ,             KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO      ,
    RGB_MOD  , RGB_HUD  , RGB_SAD  , RGB_VAD  , KC_NO    , KC_NO    ,             KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO      ,
                                     KC_LGUI  , KC_SPC   , KC_TRNS  ,             KC_TRNS  , KC_ENT   , KC_TRNS
    )

};
