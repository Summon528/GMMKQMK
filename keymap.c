/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

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

enum custom_keycodes {
    M_EMAIL = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_EMAIL:
            if (record->event.pressed) {
                SEND_STRING("@xywami.com");
            } else {
            }
            break;
    }
    return true;
};

enum userspace_layers {
    QWERTY,
    FNLAYER,
    CLLAYER,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [QWERTY] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_DEL,          KC_MEDIA_PLAY_PAUSE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        TT(2),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL,    KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [CLLAYER] = LAYOUT(
        _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,                    _______,     
        _______,      _______,      M_EMAIL,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,                    _______,     
   LCTL(KC_TAB),   LCTL(KC_Q),   LCTL(KC_W),   LCTL(KC_E),   LCTL(KC_R),   LCTL(KC_T),   LCTL(KC_Y),      KC_HOME,   LCTL(KC_I),       KC_END,   LCTL(KC_P),      _______,      _______,      _______,      _______,     
        _______,   LCTL(KC_A),   LCTL(KC_S),   LCTL(KC_D),   LCTL(KC_F),   LCTL(KC_G),      KC_LEFT,      KC_DOWN,        KC_UP,      KC_RGHT,      _______,      _______,                    _______,                    _______,     
        _______,                 LCTL(KC_Z),   LCTL(KC_X),   LCTL(KC_C),   LCTL(KC_V),   LCTL(KC_B),   LCTL(KC_N),   LCTL(KC_M),      _______,      _______,      _______,                    _______,      _______,      _______,     
        KC_CAPS,      _______,   _______,                                     _______,                                  _______,      _______,      _______,      _______,      _______,      _______
    ),


    [FNLAYER] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,          KC_MUTE,
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, RGB_VAI, _______, _______, LSFT(LCTL(KC_ESC)), _______, _______, _______, _______, _______, _______, _______, RESET  ,          KC_MEDIA_PREV_TRACK,
        _______, _______, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          KC_MEDIA_NEXT_TRACK,
        _______,          _______, RGB_HUI, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),


};

// clang-format on

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return false;
}
#endif  // ENCODER_ENABLE

#ifdef RGB_MATRIX_ENABLE
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch (get_highest_layer(layer_state)) {
        case CLLAYER:
            RGB_MATRIX_INDICATOR_SET_COLOR(13, 0, 0, 255)  // 2
            RGB_MATRIX_INDICATOR_SET_COLOR(37, 0, 0, 255)  // h
            RGB_MATRIX_INDICATOR_SET_COLOR(41, 0, 0, 255)  // u
            RGB_MATRIX_INDICATOR_SET_COLOR(42, 0, 0, 255)  // j
            RGB_MATRIX_INDICATOR_SET_COLOR(47, 0, 0, 255)  // k
            RGB_MATRIX_INDICATOR_SET_COLOR(52, 0, 0, 255)  // l
            RGB_MATRIX_INDICATOR_SET_COLOR(53, 0, 0, 255)  // l
            break;
        default:
            break;
    }
    if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) RGB_MATRIX_INDICATOR_SET_COLOR(0, 255, 255, 255);
}
#endif