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

enum layers {
    _BASE,
    _SYM,
    _NAV,
    _THIRD
};

enum {
    TD_SPC_TAB,
    TD_DEL_EECLR,
};

// enum custom_keycodes {
//     TD_ESC_CAPS = SAFE_RANGE,
// };

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_SPC_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_TAB),
    [TD_DEL_EECLR] = ACTION_TAP_DANCE_DOUBLE(KC_DEL, EE_CLR),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_BASE,KC_T):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(G(KC_T)); // Intercept hold function to send Ctrl-Z
                return false;
            }
        case LT(_BASE,KC_A):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(G(KC_A)); // Intercept hold function to send Ctrl-Z
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(_BASE,KC_S):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(G(KC_S)); // Intercept hold function to send Ctrl-Z
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(_BASE,KC_Z):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(G(KC_Z)); // Intercept hold function to send Ctrl-Z
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(_BASE,KC_X):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(G(KC_X)); // Intercept hold function to send Ctrl-X
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(_BASE,KC_C):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(G(KC_C)); // Intercept hold function to send Ctrl-C
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(_BASE,KC_V):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(G(KC_V)); // Intercept hold function to send Ctrl-V
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(_BASE,KC_Y):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(G(KC_Y)); // Intercept hold function to send Ctrl-V
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(_BASE,KC_N):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(G(KC_N)); // Intercept hold function to send Ctrl-V
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(_BASE,KC_BSPC):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(A(KC_BSPC)); // Intercept hold function to send Ctrl-BSPC
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
    }
    return true;
}

// extern rgblight_config_t rgblight_config;
// void keyboard_post_init_user(void) {
//   rgblight_enable_noeeprom();
//   rgblight_sethsv_noeeprom(HSV_ORANGE); // or even sth. like rgblight_sethsv_noeeprom(HSV_TEAL);
// }

typedef union {
  uint32_t raw;
  struct {
    bool     rgb_layer_change :1;
  };
} user_config_t;

user_config_t user_config;

void eeconfig_init_user(void) {  // EEPROM is getting reset!
  user_config.raw = 0;
  user_config.rgb_layer_change = true; // We want this enabled by default
  eeconfig_update_user(user_config.raw); // Write default value to EEPROM now

  // use the non noeeprom versions, to write these values to EEPROM too
  rgblight_enable(); // Enable RGB by default
  rgblight_sethsv(HSV_ORANGE);  // Set it to CYAN by default
  rgblight_mode(1); // set to solid by default
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_split_3x6_3(
    KC_TAB         , KC_Q           , KC_W           , KC_E           , KC_R           , KC_T           ,            KC_Y           , KC_U          , KC_I     , KC_O     , KC_P     , TD(TD_DEL_EECLR)  ,
    ALT_T(KC_ESC)  , KC_A           , KC_S           , KC_D           , KC_F           , KC_G           ,            KC_H           , KC_J          , KC_K     , KC_L     , KC_SCLN  , KC_QUOT ,
    SFT_T(KC_CAPS) , KC_Z           , KC_X           , KC_C           , KC_V           , KC_B           ,            KC_N           , KC_M          , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RGUI ,
                                                         CTL_T(KC_DEL), SFT_T(KC_ENT)  , LT(_SYM,KC_SPC),            MO(_NAV)       , TD(TD_SPC_TAB), LT(_BASE,KC_BSPC)
    ),

[_SYM] = LAYOUT_split_3x6_3(
    KC_TRNS  , KC_EXLM  , KC_AT    , KC_HASH  , KC_DLR   , KC_PERC  ,             KC_CIRC  , KC_AMPR  , KC_ASTR  , KC_LPRN  , KC_RPRN  , MO(_THIRD) ,
    KC_TRNS  , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,             KC_UNDS  , KC_PLUS  , KC_TILD  , KC_LBRC  , KC_RBRC  , KC_PIPE    ,
    KC_TRNS  , KC_6     , KC_7     , KC_8     , KC_9     , KC_0     ,             KC_MINS  , KC_EQL   , KC_GRV   , KC_LCBR  , KC_RCBR  , KC_BSLS    ,
                                     KC_TRNS  , KC_TRNS  , KC_TRNS  ,             KC_TRNS  , KC_TRNS  , KC_TRNS
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
