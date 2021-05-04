#include QMK_KEYBOARD_H

enum keymap_layers {
	_COLEJDR,
    _FNNUM,
    _PUNC,
	_RGBGUI,
	_QWERTY,
	_COLEMAK,
	_GAME,
	_FN,
	_ADJUST
};

enum keymap_keycodes {
    // Disables touch processing
    TCH_TOG = SAFE_RANGE
};

// Default Layers
#define COLEJDR  DF(_COLEJDR)
#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK)
#define GAME     DF(_GAME)

// Toggled layers
#define FNNUM   TG(_FNNUM)
#define PUNC    TG(_PUNC)
#define RGBGUI  TG(_RGBGUI)

// Momentary Layers
#define FN       MO(_FN)
#define ADJUST   MO(_ADJUST)

// Tap-hold keys
#define SFT_TAB  LSFT_T(KC_TAB)
#define CTL_SPC  LCTL_T(KC_SPC)
#define FN_CAPS  LT(_FN, KC_CAPS)
#define FN_ESC   LT(_FN, KC_ESC)

// Tap-dance keys
// Currently unused, but I'd like to have left and right alt on the same key (hold for left, tap for one-shot right),
// but I'll have to get more familiar with tap dance before I trust myself to execute this correctly.

// Mod-tap keys
#define ALT_F4 LALT(KC_F4)
#define KC_PND LSFT(KC_3)

// One-shot keys
#define OS_ALT 	OSM(MOD_RALT)

// Swap hands key (when held)
// https://docs.qmk.fm/#/feature_swap_hands
#define SWP_BCK SH_T(KC_BSPC)

// https://docs.qmk.fm/#/keycodes

const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
  // Left half
  {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}, {6, 5}},
  {{0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}, {6, 6}},
  {{0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7}, {6, 7}},
  {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}},
  {{0, 9}, {1, 9}, {2, 9}, {3, 9}, {4, 9}, {5, 9}, {6, 9}},
  // Right half
  {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}},
  {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}},
  {{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {6, 2}},
  {{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {6, 3}},
  {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {6, 4}},
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_COLEJDR] = LAYOUT(
		RESET,   KC_UP,    KC_DOWN, KC_2,    KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    RGBGUI,   KC_LEFT, KC_RIGHT, TCH_TOG,
		OS_ALT,  KC_NUHS,  KC_1,    KC_W,    KC_F,    KC_P,    KC_J,    KC_V,     KC_L,    KC_U,    KC_DOT,  KC_9,    KC_INS,   KC_MUTE,
		KC_ESC,  KC_QUOT,  KC_Q,    KC_R,    KC_S,    KC_T,    KC_M,    KC_COMM,  KC_N,    KC_E,    KC_I,    KC_K,    KC_0,     KC_NUBS,
		FNNUM,   SFT_TAB,  KC_A,    KC_X,    KC_C,    KC_D,    KC_SLSH, KC_SCLN,  KC_H,    KC_G,    KC_B,    KC_O,    KC_MINS,  PUNC,
		KC_LALT, KC_LBRC,  KC_Z,    KC_GRV,  KC_DEL,  SWP_BCK, CTL_SPC, KC_SFTENT,KC_LALT, KC_CAPS,   KC_LWIN, KC_Y, KC_RBRC,     ALT_F4
	),

    [_FNNUM] = LAYOUT(
        _______, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______,  _______, _______, _______, _______, _______,  KC_PSCR,
        _______, KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PAST,  KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,  KC_NLCK,
        KC_CAPS, KC_TAB,   KC_MUTE, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_PSLS,  KC_P4,   KC_P5,   KC_P6,   KC_MINS,  KC_BSPC,  KC_INS,
		_______, KC_LBRC,  KC_RBRC, KC_LALT, KC_LWIN, KC_MPRV, KC_MPLY, KC_MNXT,  KC_P1,   KC_P2,   KC_P3,   KC_EQL,  _______,  _______,
		_______, _______,  KC_LSFT, KC_VOLD, KC_VOLU, _______, _______, _______,  KC_P0,   _______, KC_PDOT, KC_LALT, KC_COMM,  KC_RALT
    ),

    [_PUNC] = LAYOUT(
		_______, _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,  _______,
		_______, _______,  _______, KC_LWIN, KC_DEL,  KC_BSPC, _______, KC_INS,   KC_Z,    KC_X,    KC_C,    _______, _______,  _______,
		_______, _______,  KC_ESC,  KC_PND,  KC_PERC, KC_CIRC, _______, _______,  KC_EXLM, KC_DQT,  KC_AMPR, KC_V,    _______,  _______,
		_______, KC_CAPS,  KC_DLR,  _______, _______, _______, _______, _______,  KC_S,    KC_U,    KC_B,    KC_NUHS, KC_RSFT,  _______,
		_______, _______,  KC_LSFT, _______, _______, _______, _______, _______,  _______, _______, _______, KC_I,    _______,  _______
    ),

    [_RGBGUI] = LAYOUT(
		_______, _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,  _______,
		_______, _______,  _______, KC_E,    KC_UP,   KC_D,    _______, _______,  _______, _______, _______, _______, _______,  _______,
		_______, _______,  RGB_TOG, KC_LEFT, KC_DOWN, KC_RIGHT,_______, _______,  KC_LWIN, KC_LSFT, _______, _______, _______,  _______,
		_______, _______,  _______, RGB_HUI, RGB_VAI, RGB_VAD, _______, _______,  RGB_MOD, RGB_RMOD,RGB_SAI, _______, _______,  _______,
		_______, _______,  RGB_HUD, _______, _______, _______, _______, _______,  _______, _______, _______, RGB_SAD, _______,  _______
    ),
    /* QWERTY - default keymap 2021-04-28
     * .--------------------------------------------------------------.  .--------------------------------------------------------------.
     * | `~/ESC | 1      | 2      | 3      | 4      | 5      |   -    |  |    =   | 6      | 7      | 8      | 9      | 0      | Bckspc |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * | Tab    | Q      | W      | E      | R      | T      |   [    |  |    ]   | Y      | U      | I      | O      | P      | \      |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * | FN/Caps| A      | S      | D      | F      | G      |   (    |  |    )   | H      | J      | K      | L      | :      | '      |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * | Shift( | Z      | X      | C      | V      | B      |   {    |  |    }   | N      | M      | ,      | .      | /      | )Shift |
     * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     * | Ctrl   | Win    | Alt    | RGBTOG | FN     | Space  | Bksp   |  | Enter  | Space  | Space  | FN     | Alt    | Win    | Ctrl   |
     * '--------+--------+--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------+--------+--------'
     */
    [_QWERTY] = LAYOUT(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,   KC_EQL,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,   KC_RBRC,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLASH,
        FN_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LPRN,   KC_RPRN,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LCBR,   KC_RCBR,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
        KC_LCTL, KC_LGUI, KC_LALT, RGB_TOG, ADJUST,  KC_SPC,  KC_DEL,    KC_ENT,    KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_RCTL
    ),

    [_COLEMAK] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    _______, _______, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,
        _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    _______, _______, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_GAME] = LAYOUT(
        _______, _______, _______, _______, _______, _______, KC_F1,   KC_F5,   _______, _______, _______, _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_F2,   KC_F6,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_F3,   KC_F7,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_F4,   KC_F8,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
        _______, KC_NO,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_FN] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,  KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, KC_HOME, KC_UP,   KC_END,  _______, _______, _______, _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PSCR, KC_PGUP,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  KC_PGDN,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, TCH_TOG, _______, _______, _______, _______, _______, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU
    ),

    [_ADJUST] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,  KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, RGB_SAD, RGB_VAI, RGB_SAI, RESET,   _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______,
        _______, RGB_HUD, RGB_VAD, RGB_HUI, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   _______, _______,
        _______, RGB_SPD, _______, RGB_SPI, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, GAME,
        _______, RGB_RMOD,_______, RGB_MOD, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT, KC_NLCK, QWERTY, COLEMAK
    ),
};


// Default configuration: 3 tap zones, slide up, slide down
const uint16_t PROGMEM touch_encoders[][NUMBER_OF_TOUCH_ENCODERS][TOUCH_ENCODER_OPTIONS] = {
	[_COLEJDR] = TOUCH_ENCODER_LAYOUT( \
		KC_5,   KC_6,  KC_7,  KC_END,  KC_HOME,
		KC_8,    KC_9, KC_0, KC_BSPC, KC_DEL
	),
	[_FNNUM] = TOUCH_ENCODER_LAYOUT( \
		_______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______
	),
	[_PUNC] = TOUCH_ENCODER_LAYOUT( \
		_______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______
	),
	[_RGBGUI] = TOUCH_ENCODER_LAYOUT( \
		_______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______
	),
    [_QWERTY] = TOUCH_ENCODER_LAYOUT( \
		KC_NO,   RGBGUI,  FNNUM,  KC_END,  KC_HOME,
		PUNC,    KC_NO,   COLEJDR,KC_BSPC, KC_DEL
//        KC_MNXT, KC_MPLY, KC_MPRV, KC_VOLU, KC_VOLD,
//        KC_NO, KC_NO, KC_NO, KC_PGDN, KC_PGUP
        //RGB_RMOD, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD,
        //RGB_RMOD, RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD
    ),
    [_COLEMAK] = TOUCH_ENCODER_LAYOUT( \
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______
    ),
    [_GAME] = TOUCH_ENCODER_LAYOUT( \
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______
    ),
    [_FN] = TOUCH_ENCODER_LAYOUT( \
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______
    ),
    [_ADJUST] = TOUCH_ENCODER_LAYOUT( \
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______
    )
};

const uint16_t PROGMEM encoders[][NUMBER_OF_ENCODERS][ENCODER_OPTIONS]  = {
	[_COLEJDR] = ENCODER_LAYOUT( \
		_______, _______,
		_______, _______,
		_______, _______,
		_______, _______
	),
	[_FNNUM] = ENCODER_LAYOUT( \
		_______, _______,
		_______, _______,
		_______, _______,
		_______, _______
	),
	[_PUNC] = ENCODER_LAYOUT( \
		_______, _______,
		_______, _______,
		_______, _______,
		_______, _______
	),
    [_RGBGUI] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______
    ),
    [_QWERTY] = ENCODER_LAYOUT( \
        KC_VOLU, KC_VOLD,
        KC_VOLU, KC_VOLD,
        KC_PGDN, KC_PGUP,
        KC_PGDN, KC_PGUP
    ),
    [_COLEMAK] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______
    ),
    [_GAME] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______
    ),
    [_FN] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______
    ),
    [_ADJUST] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TCH_TOG:
            touch_encoder_toggle();
            return false;  // Skip all further processing of this key
        default:
            return true;  // Process all other keycodes normally
    }
}

#if defined(OLED_DRIVER_ENABLE)
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("Colemak"), false);
            break;
        case _GAME:
            oled_write_ln_P(PSTR("GAME"), false);
            break;
        case _FN:
            oled_write_ln_P(PSTR("FN"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("ADJ"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_ln_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif
