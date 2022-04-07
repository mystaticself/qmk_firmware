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
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MPLY,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, KC_RALT, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______,          _______,
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,            _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    // [1] = LAYOUT(
    //     _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______,          _______,
    //     _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    //     _______, _______, RGB_VAI, RGB_SAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,            _______,
    //     _______, _______, RGB_VAD, RGB_SAD, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
    //     _______,          _______, RGB_HUI, RGB_HUD, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, _______,
    //     _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    // ),


};

// taken from
// https://www.reddit.com/r/glorious/comments/rw5767/side_leds_with_qmk_on_gmmk_pro_iso/
// https://www.reddit.com/r/glorious/comments/rtr567/qmmk_pro_enable_encoder_wheel_to_change_the_rgb/?utm_source=amp&utm_medium=
// https://github.com/jwhurley1/qmk_firmware/blob/master/keyboards/gmmk/pro/ansi/keymaps/jwhurley1/keymap.c

uint8_t thisHue = 0;
uint8_t thisSat = 0;
uint8_t thisVal = 255;

const int SIZE = 8;
int leftSideLEDs[] = { 67, 70, 73, 76, 80, 83, 87, 91 };
int rightSideLEDs[] = { 68, 71, 74, 77, 81, 84, 88, 92 };

// 1, F7, F8, F9, F10, F11, F12, N
const int LAYER_1_SIZE = 8;
int layer1LEDs[] = {7, 39, 44, 50, 56, 61, 66, 38};

// 1, W, E, S, D, C, V, F7, F8, F9, F10, F11, F12, N, \, Up, Left, Down, Right
// const int LAYER_1_SIZE = 19;
// int layer1LEDs[] = {7, 14, 20, 15, 21, 22, 27, 39, 44, 50, 56, 61, 66, 38, 93, 94, 95, 97, 79};

bool sideLEDsActive = true;

#if defined(ENCODER_ENABLE) && !defined(ENCODER_DEFAULTACTIONS_ENABLE)

void encoder_action_hsv_change(bool clockwise, uint8_t hueChange, uint8_t satChange, uint8_t valChange) {
    if (clockwise) {
        thisHue += hueChange;
        thisSat += satChange;
        thisVal += valChange;
    } else {
        thisHue -= hueChange;
        thisSat -= satChange;
        thisVal -= valChange;
    }
}

void invert_sideLEDsActive(bool sideLEDsBoolean){
    if(sideLEDsBoolean) {
        sideLEDsActive = false;
    } else {
        sideLEDsActive = true;
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t mods_state = get_mods();

    if (mods_state & MOD_BIT(KC_LCTL)) {
        encoder_action_hsv_change(clockwise, 2, 0, 0); // Hue change
    } else if (mods_state & MOD_BIT(KC_LSFT)) {
        encoder_action_hsv_change(clockwise, 0, 2, 0); // Saturation change
    } else if (mods_state & MOD_BIT(KC_LALT)) {
        encoder_action_hsv_change(clockwise, 0, 0, 2); // Value/Brightness change
    } else {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}

#endif // endif ENCODER

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
        // rgb_matrix_set_color_all(RGB_WHITE);

        rgb_matrix_set_color(3, RGB_PINK);

        for (int i = 0; i < SIZE; i++) {
            rgb_matrix_set_color(leftSideLEDs[i], RGB_PINK);
            rgb_matrix_set_color(rightSideLEDs[i], RGB_PINK);
        }
    } else {
        HSV hsv = {thisHue, thisSat, thisVal};
        RGB rgb = hsv_to_rgb(hsv);

        HSV currentMatrix_hsv = rgb_matrix_get_hsv();
        RGB currentMatrix_rgb = hsv_to_rgb(currentMatrix_hsv);

        if(sideLEDsActive) {
            for (int i = 0; i < SIZE; i++) {
                rgb_matrix_set_color(leftSideLEDs[i], rgb.r, rgb.g, rgb.b);
                rgb_matrix_set_color(rightSideLEDs[i], rgb.r, rgb.g, rgb.b);
            }
        }

        if (get_highest_layer(layer_state) > 0) {
            uint8_t layer = get_highest_layer(layer_state);

            for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
                for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                    uint8_t index = g_led_config.matrix_co[row][col];

                    if (index >= led_min && index <= led_max && index != NO_LED &&
                    keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                        rgb_matrix_set_color(index, currentMatrix_rgb.r, currentMatrix_rgb.g, currentMatrix_rgb.b);
                    }
                }
            }

            // set layer 1 led colors when active
            for (int i = 0; i < LAYER_1_SIZE; i++) {
                rgb_matrix_set_color(layer1LEDs[i], RGB_PINK);
            }
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_MUTE:
        if (record->event.pressed) {
            if (get_mods() & MOD_MASK_CTRL){
                invert_sideLEDsActive(sideLEDsActive);
                return false;
            }
            return true;
        }
    default:
      return true; // Process all other keycodes normally
  }
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   return true;
// }
