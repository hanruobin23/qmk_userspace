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
    // TD_SPC_TAB,
    // TD_DEL_EECLR,
    TD_PRN,
    TD_BRC,
    TD_CBR,
    TD_MINS,
    TD_EQL,
    TD_GRV,
    TD_BSLS,
    TD_SCLN,
    TD_QUOT,
    TD_COMM,
    TD_DOT,
    TD_SLSH,
    // TD_BSPC
};

// Tap Dance definitions
void prn_each(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code16(KC_LPRN);
            break;
        case 2:
            tap_code16(KC_BSPC);
            tap_code16(KC_RPRN);
            break;
    }
}

void brc_each(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code16(KC_LBRC);
            break;
        case 2:
            tap_code16(KC_BSPC);
            tap_code16(KC_RBRC);
            break;
    }
}

void cbr_each(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code16(KC_LCBR);
            break;
        case 2:
            tap_code16(KC_BSPC);
            tap_code16(KC_RCBR);
            break;
    }
}

void mins_each(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code16(KC_MINS);
            break;
        case 2:
            tap_code16(KC_BSPC);
            tap_code16(KC_UNDS);
            break;
    }
}

void eql_each(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code16(KC_EQL);
            break;
        case 2:
            tap_code16(KC_BSPC);
            tap_code16(KC_PLUS);
            break;
    }
}

void grv_each(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code16(KC_GRV);
            break;
        case 2:
            tap_code16(KC_BSPC);
            tap_code16(KC_TILD);
            break;
    }
}

void bsls_each(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code16(KC_BSLS);
            break;
        case 2:
            tap_code16(KC_BSPC);
            tap_code16(KC_PIPE);
            break;
    }
}

void scln_each(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code16(KC_SCLN);
            break;
        case 2:
            tap_code16(KC_BSPC);
            tap_code16(KC_COLN);
            break;
    }
}

void quot_each(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code16(KC_QUOT);
            break;
        case 2:
            tap_code16(KC_BSPC);
            tap_code16(KC_DQT);
            break;
    }
}

void comm_each(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code16(KC_COMM);
            break;
        case 2:
            tap_code16(KC_BSPC);
            tap_code16(KC_LT);
            break;
    }
}

void dot_each(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code16(KC_DOT);
            break;
        case 2:
            tap_code16(KC_BSPC);
            tap_code16(KC_GT);
            break;
    }
}

void slsh_each(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code16(KC_SLSH);
            break;
        case 2:
            tap_code16(KC_BSPC);
            tap_code16(KC_QUES);
            break;
    }
}

void null_finished(tap_dance_state_t *state, void *user_data) {}
void null_reset(tap_dance_state_t *state, void *user_data) {}

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    // [TD_SPC_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_SPC,KC_TAB),
    // [TD_DEL_EECLR] = ACTION_TAP_DANCE_DOUBLE(KC_DEL, EE_CLR),
    // [TD_PRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_PRN] = ACTION_TAP_DANCE_FN_ADVANCED(prn_each, null_finished, null_reset),
    // [TD_BRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    [TD_BRC] = ACTION_TAP_DANCE_FN_ADVANCED(brc_each, null_finished, null_reset),
    // [TD_CBR] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [TD_CBR] = ACTION_TAP_DANCE_FN_ADVANCED(cbr_each, null_finished, null_reset),
    // [TD_MINS] = ACTION_TAP_DANCE_DOUBLE(KC_MINS,KC_UNDS),
    [TD_MINS] = ACTION_TAP_DANCE_FN_ADVANCED(mins_each,null_finished, null_reset),
    // [TD_EQL] = ACTION_TAP_DANCE_DOUBLE(KC_EQL,KC_PLUS),
    [TD_EQL] = ACTION_TAP_DANCE_FN_ADVANCED(eql_each, null_finished, null_reset),
    // [TD_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_GRV,KC_TILD),
    [TD_GRV] = ACTION_TAP_DANCE_FN_ADVANCED(grv_each, null_finished, null_reset),
    // [TD_BSLS] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS,KC_PIPE),
    [TD_BSLS] = ACTION_TAP_DANCE_FN_ADVANCED(bsls_each, null_finished, null_reset),
    // [TD_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN,KC_COLN),
    [TD_SCLN] = ACTION_TAP_DANCE_FN_ADVANCED(scln_each, null_finished, null_reset),
    // [TD_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT,KC_DQT),
    [TD_QUOT] = ACTION_TAP_DANCE_FN_ADVANCED(quot_each, null_finished, null_reset),
    // [TD_COMM] = ACTION_TAP_DANCE_DOUBLE(KC_COMM,KC_LT),
    [TD_COMM] = ACTION_TAP_DANCE_FN_ADVANCED(comm_each, null_finished, null_reset),
    // [TD_DOT] = ACTION_TAP_DANCE_DOUBLE(KC_DOT,KC_GT),
    [TD_DOT] = ACTION_TAP_DANCE_FN_ADVANCED(dot_each, null_finished, null_reset),
    // [TD_SLSH] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH,KC_QUES),
    [TD_SLSH] = ACTION_TAP_DANCE_FN_ADVANCED(slsh_each, null_finished, null_reset),
    // [TD_BSPC] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC,C(KC_BSPC)),

};

bool is_alt_tab_active = false;

layer_state_t layer_state_set_user(layer_state_t state) {
    if (is_alt_tab_active) {
        unregister_code(KC_RALT);
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
                    register_code(KC_RALT);
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
// bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case CTL_T(KC_DEL):
//             // Immediately select the hold action when another key is pressed.
//             return true;
//         case SFT_T(KC_ENT):
//             // Immediately select the hold action when another key is pressed.
//             return true;
//         case SFT_T(KC_CAPS):
//             // Immediately select the hold action when another key is pressed.
//             return true;
//         case ALT_T(KC_ESC):
//             // Immediately select the hold action when another key is pressed.
//             return true;
//         // case ALT_T(KC_SPC):
//         //     // Immediately select the hold action when another key is pressed.
//         //     return true;
//         case LT(_NAV,KC_TAB):
//             // Immediately select the hold action when another key is pressed.
//             return true;
//         default:
//             // Do not select the hold action when another key is pressed.
//             return false;
//     }
// }

// ======================== DEFINE TAPPING TERM PER KEY ============================
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_T(KC_ENT):
            // return TAPPING_TERM + 1250;
            return TAPPING_TERM - 50;
        default:
            return TAPPING_TERM;
    }
}

// ==================== COMBO KEYS
const uint16_t PROGMEM MINS_COMBO[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM EQL_COMBO[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM GRV_COMBO[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM BSLS_COMBO[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM LE_COMBO[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM NE_COMBO[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM GE_COMBO[] = {KC_DOT, KC_SLSH, COMBO_END};
// const uint16_t PROGMEM ZERO_COMBO[] = {KC_RSFT, KC_Z, COMBO_END};
// const uint16_t PROGMEM ONE_COMBO[] = {KC_Z, KC_X, COMBO_END};
// const uint16_t PROGMEM TWO_COMBO[] = {KC_X, KC_C, COMBO_END};
// const uint16_t PROGMEM THREE_COMBO[] = {KC_C, KC_V, COMBO_END};
// const uint16_t PROGMEM FOUR_COMBO[] = {KC_A, KC_S, COMBO_END};
// const uint16_t PROGMEM FIVE_COMBO[] = {KC_S, KC_D, COMBO_END};
// const uint16_t PROGMEM SIX_COMBO[] = {KC_D, KC_F, COMBO_END};
// const uint16_t PROGMEM SEVEN_COMBO[] = {KC_Q, KC_W, COMBO_END};
// const uint16_t PROGMEM EIGHT_COMBO[] = {KC_W, KC_E, COMBO_END};
// const uint16_t PROGMEM NINE_COMBO[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM LPRN_COMBO[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM LBRC_COMBO[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM LCBR_COMBO[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM CSENT_COMBO[] = {KC_F, KC_G, COMBO_END};

combo_t key_combos[] = {
    COMBO(MINS_COMBO, KC_MINS),
    COMBO(EQL_COMBO, KC_EQL), // keycodes with modifiers are possible too!
    COMBO(GRV_COMBO,KC_GRV),
    COMBO(BSLS_COMBO,KC_BSLS),
    // COMBO(ZERO_COMBO,KC_0),
    // COMBO(ONE_COMBO,KC_1),
    // COMBO(TWO_COMBO,KC_2),
    // COMBO(THREE_COMBO,KC_3),
    // COMBO(FOUR_COMBO,KC_4),
    // COMBO(FIVE_COMBO,KC_5),
    // COMBO(SIX_COMBO,KC_6),
    // COMBO(SEVEN_COMBO,KC_7),
    // COMBO(EIGHT_COMBO,KC_8),
    // COMBO(NINE_COMBO,KC_9),
    COMBO(LPRN_COMBO,KC_LPRN),
    COMBO(LBRC_COMBO,KC_LBRC),
    COMBO(LCBR_COMBO,KC_LCBR),
    COMBO(CSENT_COMBO,LCTL(LSFT(KC_ENT)))
};

// RGB for caps lock
// extern rgblight_config_t rgblight_config;

uint32_t mode;
uint16_t hue;
uint8_t sat;
uint8_t val;

// void matrix_init_user(void)
// {
//     mode = rgblight_get_mode();
//     hue = rgblight_get_hue();
//     sat = rgblight_get_sat();
//     val = rgblight_get_val();
// }

bool led_update_user(led_t led_state) {
    static uint8_t caps_state = 0;
    if (caps_state != led_state.caps_lock) {
        if (led_state.caps_lock==1) {
        mode = rgblight_get_mode();
        hue = rgblight_get_hue();
        sat = rgblight_get_sat();
        val = rgblight_get_val();

        rgblight_mode_noeeprom(1);
        rgblight_sethsv(HSV_RED);
        } else {
        rgblight_mode(mode);
        rgblight_sethsv(hue, sat, val);
        }
        caps_state = led_state.caps_lock;
    }
    return true;
}

// void led_set_user(uint8_t usb_led) {
//   if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
//     mode = rgblight_get_mode();
//     hue = rgblight_get_hue();
//     sat = rgblight_get_sat();
//     val = rgblight_get_val();

//     rgblight_mode_noeeprom(1);
//     // rgblight_setrgb(0xD3, 0x7F, 0xED);
//     rgblight_sethsv(HSV_RED);
//   } else {
//     rgblight_mode(mode);
//     rgblight_sethsv(hue, sat, val);
//   }
// }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_split_3x6_3(
    CTL_T(KC_ESC)  , KC_Q           , KC_W           , KC_E           , KC_R           , KC_T           ,            KC_Y           , KC_U          , KC_I     , KC_O     , KC_P         , CTL_T(KC_PSCR)     ,
    ALT_T(KC_TAB)  , KC_A           , KC_S           , KC_D           , KC_F           , KC_G           ,            KC_H           , KC_J          , KC_K     , KC_L     , TD(TD_SCLN)  , TD(TD_QUOT) ,
    SFT_T(KC_CAPS) , KC_Z           , KC_X           , KC_C           , KC_V           , KC_B           ,            KC_N           , KC_M          , TD(TD_COMM)  , TD(TD_DOT)   , TD(TD_SLSH)  , KC_RGUI ,
                                                       CTL_T(KC_DEL)  , SFT_T(KC_ENT)  , MO(_SYM)       ,            LT(_NAV,KC_TAB), ALT_T(KC_SPC) , KC_BSPC
    ),

[_SYM] = LAYOUT_split_3x6_3(
    _______                   , _______  , KC_7     , KC_8     , KC_9     , TD(TD_PRN)    ,             KC_RPRN  , _______     , _______   , _______  , _______  , EE_CLR     ,
    OSM(MOD_LCTL | MOD_LALT)  , ALT_TAB  , KC_4     , KC_5     , KC_6     , TD(TD_BRC)    ,             KC_RBRC  ,TD(TD_MINS)  , TD(TD_EQL), TD(TD_GRV)   , TD(TD_BSLS)  , _______    ,
    _______                   , KC_0     , KC_1     , KC_2     , KC_3     , TD(TD_CBR)    ,             KC_RCBR  , _______  , _______  , _______  , _______  , _______    ,
                                                      _______  , _______  , KC_0          ,             _______  , _______  , _______
    ),

[_NAV] = LAYOUT_split_3x6_3(
    KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    , KC_F6    ,             KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   , KC_F12     ,
    _______  , KC_BRIU  , KC_MPLY  , KC_VOLD  , KC_VOLU  , KC_MUTE  ,             KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , _______  , _______    ,
    _______  , KC_BRID  , UG_VALU  , UG_SATU  , UG_HUEU  , UG_NEXT  ,             KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , KC_INS   , UG_TOGG    ,
                                     _______  , _______  , _______  ,             _______  , _______  , _______
    ),

[_THIRD] = LAYOUT_split_3x6_3(
    _______  , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,             KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO      ,
    _______  , _______  , _______  , _______  , KC_NO    , KC_NO    ,             KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO      ,
    _______  , _______  , _______  , _______  , KC_NO    , KC_NO    ,             KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO      ,
                                     _______  , _______  , _______  ,             _______  , _______  , _______
    )

};
