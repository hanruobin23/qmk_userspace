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

enum custom_keycodes {          // Make sure have the awesome keycode ready
  ALT_TAB = SAFE_RANGE,
};

//TAP DANCE CONSTRUCTION
enum {
    TD_SPC_TAB,
    TD_DEL_EECLR,
    TD_PRN,
    TD_BRC,
    TD_CBR,
    TD_MINS,
    TD_EQL,
    TD_GRV,
    TD_BSLS,
};

// Tap Dance definitions
// void spc_tab_each(tap_dance_state_t *state, void *user_data) {
//     tap_code16(KC_LPRN);
//     switch (state->count) {
//         // case 1:
//             // break;
//         case 2:
//             tap_code16(KC_BSPC);
//             tap_code16(KC_RPRN);
//             break;
//     }
// }

// void spc_tab_finished(tap_dance_state_t *state, void *user_data) {}
// void spc_tab_reset(tap_dance_state_t *state, void *user_data) {}

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_SPC_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_SPC,KC_TAB),
    [TD_DEL_EECLR] = ACTION_TAP_DANCE_DOUBLE(KC_DEL, EE_CLR),
    [TD_PRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_BRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    [TD_BRC] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [TD_MINS] = ACTION_TAP_DANCE_DOUBLE(KC_MINS,KC_UNDS),
    [TD_EQL] = ACTION_TAP_DANCE_DOUBLE(KC_EQL,KC_PLUS),
    [TD_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_GRV,KC_TILD),
    [TD_BSLS] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS,KC_PIPE)
};

bool is_alt_tab_active = false;

layer_state_t layer_state_set_user(layer_state_t state) {
    if (is_alt_tab_active) {
        unregister_code(KC_RGUI);
        is_alt_tab_active = false;
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode){
        case ALT_TAB: // super alt tab macro
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_RGUI);
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        return false;
     }
  return true;
}

// TAP HOLDS
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case LT(_BASE,KC_T):
//             if (!record->tap.count && record->event.pressed) {
//                 tap_code16(G(KC_T)); // Intercept hold function to send Ctrl-Z
//                 return false;
//             }
//         case LT(_BASE,KC_A):
//             if (!record->tap.count && record->event.pressed) {
//                 tap_code16(G(KC_A)); // Intercept hold function to send Ctrl-Z
//                 return false;
//             }
//             return true;             // Return true for normal processing of tap keycode
//         case LT(_BASE,KC_S):
//             if (!record->tap.count && record->event.pressed) {
//                 tap_code16(G(KC_S)); // Intercept hold function to send Ctrl-Z
//                 return false;
//             }
//             return true;             // Return true for normal processing of tap keycode
//         case LT(_BASE,KC_Z):
//             if (!record->tap.count && record->event.pressed) {
//                 tap_code16(G(KC_Z)); // Intercept hold function to send Ctrl-Z
//                 return false;
//             }
//             return true;             // Return true for normal processing of tap keycode
//         case LT(_BASE,KC_X):
//             if (!record->tap.count && record->event.pressed) {
//                 tap_code16(G(KC_X)); // Intercept hold function to send Ctrl-X
//                 return false;
//             }
//             return true;             // Return true for normal processing of tap keycode
//         case LT(_BASE,KC_C):
//             if (!record->tap.count && record->event.pressed) {
//                 tap_code16(G(KC_C)); // Intercept hold function to send Ctrl-C
//                 return false;
//             }
//             return true;             // Return true for normal processing of tap keycode
//         case LT(_BASE,KC_V):
//             if (!record->tap.count && record->event.pressed) {
//                 tap_code16(G(KC_V)); // Intercept hold function to send Ctrl-V
//                 return false;
//             }
//             return true;             // Return true for normal processing of tap keycode
//         case LT(_BASE,KC_Y):
//             if (!record->tap.count && record->event.pressed) {
//                 tap_code16(G(KC_Y)); // Intercept hold function to send Ctrl-V
//                 return false;
//             }
//             return true;             // Return true for normal processing of tap keycode
//         case LT(_BASE,KC_N):
//             if (!record->tap.count && record->event.pressed) {
//                 tap_code16(G(KC_N)); // Intercept hold function to send Ctrl-V
//                 return false;
//             }
//             return true;             // Return true for normal processing of tap keycode
//         case LT(_BASE,KC_BSPC):
//             if (!record->tap.count && record->event.pressed) {
//                 tap_code16(A(KC_BSPC)); // Intercept hold function to send Ctrl-BSPC
//                 return false;
//             }
//             return true;             // Return true for normal processing of tap keycode
//     }
//     return true;
// }

// FAILED RGB LIGHTING

// extern rgblight_config_t rgblight_config;
// void keyboard_post_init_user(void) {
//   rgblight_enable_noeeprom();
//   rgblight_sethsv_noeeprom(HSV_ORANGE); // or even sth. like rgblight_sethsv_noeeprom(HSV_TEAL);
// }

// typedef union {
//   uint32_t raw;
//   struct {
//     bool     rgb_layer_change :1;
//   };
// } user_config_t;

// user_config_t user_config;

// void eeconfig_init_user(void) {  // EEPROM is getting reset!
//   user_config.raw = 0;
//   user_config.rgb_layer_change = true; // We want this enabled by default
//   eeconfig_update_user(user_config.raw); // Write default value to EEPROM now

//   // use the non noeeprom versions, to write these values to EEPROM too
//   rgblight_enable(); // Enable RGB by default
//   rgblight_sethsv(HSV_ORANGE);  // Set it to CYAN by default
//   rgblight_mode(1); // set to solid by default
// }

// ============= DEFINE PERMISSIVE HOLD PER KEY
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_T(KC_DEL):
            // Immediately select the hold action when another key is pressed.
            return true;
        case SFT_T(KC_ENT):
            // Immediately select the hold action when another key is pressed.
            return true;
        case SFT_T(KC_CAPS):
            // Immediately select the hold action when another key is pressed.
            return true;
        case ALT_T(KC_ESC):
            // Immediately select the hold action when another key is pressed.
            return true;
        // case ALT_T(KC_SPC):
        //     // Immediately select the hold action when another key is pressed.
        //     return true;
        case LT(_NAV,KC_TAB):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

// bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case LT_T(KC_SPC):
//             // Immediately select the hold action when another key is tapped.
//             return true;
//         default:
//             // Do not select the hold action when another key is tapped.
//             return false;
//     }
// }


// ==================== COMBO KEYS
const uint16_t PROGMEM MINS_COMBO[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM EQL_COMBO[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM GRV_COMBO[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM BSLS_COMBO[] = {KC_L, KC_SCLN, COMBO_END};

combo_t key_combos[] = {
    COMBO(MINS_COMBO, KC_MINS),
    COMBO(EQL_COMBO, KC_EQL), // keycodes with modifiers are possible too!
    COMBO(GRV_COMBO,KC_GRV),
    COMBO(BSLS_COMBO,KC_BSLS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_split_3x6_3(
    KC_TAB         , KC_Q           , KC_W           , KC_E           , KC_R           , KC_T           ,            KC_Y           , KC_U          , KC_I     , KC_O     , KC_P     , KC_ESC  ,
    ALT_T(KC_ESC)  , KC_A           , KC_S           , KC_D           , KC_F           , KC_G           ,            KC_H           , KC_J          , KC_K     , KC_L     , KC_SCLN  , KC_QUOT ,
    SFT_T(KC_CAPS) , KC_Z           , KC_X           , KC_C           , KC_V           , KC_B           ,            KC_N           , KC_M          , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RGUI ,
                                                         CTL_T(KC_DEL), SFT_T(KC_ENT)  , MO(_SYM)       ,            LT(_NAV,KC_TAB), ALT_T(KC_SPC) , CTL_T(KC_BSPC)
    ),

[_SYM] = LAYOUT_split_3x6_3(
    KC_TRNS  , KC_TRNS  , KC_7     , KC_8     , KC_9     , TD(TD_PRN)    ,             KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , EE_CLR     ,
    KC_TRNS  , ALT_TAB  , KC_4     , KC_5     , KC_6     , TD(TD_BRC)    ,             TD(TD_MINS)  , TD(TD_EQL)   , TD(TD_GRV)   , TD(TD_BSLS)  , KC_TRNS  , KC_TRNS    ,
    KC_TRNS  , KC_0     , KC_1     , KC_2     , KC_3     , TD(TD_CBR)    ,             KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS    ,
                                     KC_TRNS  , KC_TRNS    , KC_TRNS     ,             KC_TRNS  , KC_TRNS  , KC_TRNS
    ),

[_NAV] = LAYOUT_split_3x6_3(
    KC_TRNS  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,             KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_PSCR    ,
    KC_TRNS  , KC_MPRV  , KC_MNXT  , KC_VOLD  , KC_VOLU  , KC_MUTE  ,             KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , KC_TRNS  , KC_TRNS    ,
    KC_TRNS  , KC_NO    , KC_NO    , KC_BRID  , KC_BRIU  , KC_MPLY  ,             KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , KC_INS   , KC_TRNS    ,
                                     KC_TRNS  , KC_TRNS  , KC_TRNS  ,             TG(_BASE)  , KC_TRNS  , KC_TRNS
    ),

[_THIRD] = LAYOUT_split_3x6_3(
    QK_BOOT  , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,             KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO      ,
    RGB_TOG  , RGB_HUI  , RGB_SAI  , RGB_VAI  , KC_NO    , KC_NO    ,             KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO      ,
    RGB_MOD  , RGB_HUD  , RGB_SAD  , RGB_VAD  , KC_NO    , KC_NO    ,             KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO      ,
                                     KC_LGUI  , KC_SPC   , KC_TRNS  ,             KC_TRNS  , KC_ENT   , KC_TRNS
    )

};
