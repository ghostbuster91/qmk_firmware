#include QMK_KEYBOARD_H

const uint16_t PROGMEM combo_fp_tab[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM combo_lu_esc[] = {KC_L, KC_U, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_fp_tab, KC_TAB),
    COMBO(combo_lu_esc, KC_ESC), 
};


// This keymap uses home row mods. In addition to mods, I have home row
// layer-tap keys for the SYM layer. The key arrangement is a variation on
// "GASC-order" home row mods:
//
//             Left hand                          Right hand
// +-------+-------+-------+-------+   +-------+-------+-------+-------+
// |  Sym  |  LAlt | Shift | Ctrl  |   | Ctrl  | Shift |  LAlt |  Sym  |
// +-------+-------+-------+-------+   +-------+-------+-------+-------+
// |  Gui  |  RAlt |                                   |  RAlt |  Gui  |
// +-------+-------+                                   +-------+-------+
//

// Home row mods for Colemak-dh layer.
#define HOME_R  LALT_T(KC_R)
#define HOME_S  LSFT_T(KC_S)
#define HOME_T  LCTL_T(KC_T)
#define HOME_N  RCTL_T(KC_N)
#define HOME_E  RSFT_T(KC_E)
#define HOME_I  LALT_T(KC_I)
#define HOME_Z  LGUI_T(KC_Z)
#define HOME_X  RALT_T(KC_X)
#define HOME_DOT  RALT_T(KC_DOT)	
#define HOME_SLSH  RGUI_T(KC_SLSH)	

// Home row mods for QWERTY layer.
#define QHOME_S LALT_T(KC_S)
#define QHOME_D LSFT_T(KC_D)
#define QHOME_F LCTL_T(KC_F)
#define QHOME_J RCTL_T(KC_J)
#define QHOME_K RSFT_T(KC_K)
#define QHOME_L LALT_T(KC_L)
#define QHOME_Z  LGUI_T(KC_Z)
#define QHOME_X  RALT_T(KC_X)
#define QHOME_DOT  RALT_T(KC_DOT)
#define QHOME_SLSH  RGUI_T(KC_SLSH)

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _COLEMAK_DH,
    _QWERTY,
    _NAV,
    _SYM,
    _NUM,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAK,
    KC_NAV,
    KC_SYM,
    KC_NMBR,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |COLEMA|   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_COLEMAK,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  KC_TAB,   KC_A,   QHOME_S,    QHOME_D,    QHOME_F,    KC_G,                     KC_H,    QHOME_J,    QHOME_K,    QHOME_L, KC_SCLN,  KC_QUOT,
  KC_LSFT,  QHOME_Z,   QHOME_X,    KC_C,    KC_B,    KC_B, KC_MUTE,     XXXXXXX,KC_N,    KC_M, KC_COMM,  QHOME_DOT, QHOME_SLSH,  KC_RSFT,
                 KC_LGUI,KC_LALT,KC_LCTRL, XXXXXXX, KC_ENT,      KC_SPC,  XXXXXXX, KC_RCTRL, KC_RALT, KC_RGUI
),
/*
 * COLEMAK DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |QWERTY|   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |  R/◆ |  S/⇧ | T/⎈  |   G  |-------.    ,-------|   M  | N/⎈  | E/⇧  | I/◆  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      | Z/⎇  |  X/◆ |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  | ./◆  | //⎇  |  _   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |SWITCH|  SYM | / BSPC  /       \Space \  |  NAV | CAPS |      |      |
 *            |      |      |      |      |/       /         \      \ |  ENT |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */

[_COLEMAK_DH] = LAYOUT(
  KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,                         KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11,     KC_F12,
  KC_QWERTY, KC_Q,      KC_W,      KC_F,      KC_P,      KC_B,                          KC_J,     KC_L,     KC_U,     KC_Y,      KC_SCLN,    XXXXXXX,
  KC_ESC,    KC_A,      HOME_R,    HOME_S,    HOME_T,    KC_G,                          KC_M,     HOME_N,   HOME_E,   HOME_I,    KC_O,       KC_QUOT,
  XXXXXXX,   HOME_Z,    HOME_X,    KC_C,      KC_D,      KC_V,    KC_MUTE,     XXXXXXX, KC_K,     KC_H,     KC_COMM,  HOME_DOT,  HOME_SLSH,  KC_UNDS,
                 XXXXXXX, XXXXXXX, XXXXXXX, MO(_SYM), KC_BSPC,    KC_SPC,  LT(_NAV, KC_ENT), XXXXXXX, XXXXXXX, XXXXXXX
),
/*
 * _SYMBOL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   '  |   <  |   >  |   "  |   .  |                    |   &  |   _  |   [  |   ]  |   %  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   -  |   +  |   =  |   #  |-------.    ,-------|   |  |   :  |   (  |   )  |   ?  | LOCK |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |   ^  |   /  |   *  |   \  | ../  |-------|    |-------|   ~  |   $  |   {  |   }  |   @  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |  SYM | /Enter  /       \Space \  |  NAV |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_SYM] = LAYOUT(
  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                      XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
  KC_ESC,    KC_QUOT,   KC_LABK,   KC_RABK,   KC_DQUO,   KC_DOT,                       KC_AMPR,   KC_UNDERSCORE,KC_RBRC,KC_LBRC,   KC_PERC,   XXXXXXX,
  KC_TAB,    KC_EXLM,   KC_MINS,   KC_PLUS,   KC_EQL,    KC_HASH,                      KC_PIPE,   KC_COLON,  KC_LPRN,   KC_RPRN,   KC_QUES,   XXXXXXX,
  KC_LSFT,   KC_CIRC,   KC_SLSH,   KC_ASTR,   KC_BSLS,   XXXXXXX, KC_MUTE,    XXXXXXX, KC_TILD,   KC_DLR,    KC_LCBR,   KC_RCBR,   KC_AT,     XXXXXXX,
            		        XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_ENT,    KC_SPC,  _______, XXXXXXX, XXXXXXX, XXXXXXX 
),
/* NAVIGATION
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      | Home |  End |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | LAlt |LShift| LCTR |      |-------.    ,-------|      | LEFT | DOWN |  UP  | RIGHT|      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      | LGUI | RAlt |      |      |      |-------|    |-------|      |      | PgDn | PgUp |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |  SYM | / BSPC  /       \Space \  |  NAV |      |      |      |
 *            |      |      |      |      |/       /         \      \ |  ENT |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */
[_NAV] = LAYOUT(
  _______,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                       XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
  KC_GRV,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                          KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_F12,
  _______,   KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,                       KC_CIRC,   KC_AMPR,   KC_ASTR,   KC_LPRN,   KC_RPRN,   KC_PIPE,
  _______,   KC_EQL,    KC_MINS,   KC_PLUS,   KC_LCBR,   KC_RCBR, _______,     _______, KC_LBRC,   KC_RBRC,   KC_SCLN,   KC_COLN,   KC_BSLS,   _______,
                             XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,       _______, _______, _______, _______, _______
),
/* NUMBERS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |   *  |   7  |   8  |   9  |   -  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | LAlt |LShift| LCTR |      |-------.    ,-------|   /  |   3  |   4  |   5  |   +  |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      | LGUI | RAlt |  .   |  ,   |      |-------|    |-------|   =  |   1  |   2  |   3  |   0  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |  SYM | / BSPC  /       \Space \  |  NAV |      |      |      |
 *            |      |      |      |      |/       /         \      \ |  ENT |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */
[_NUM] = LAYOUT(    
  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                     XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                     KC_ASTR,   KC_7,      KC_8,      KC_9,      KC_MINS,   XXXXXXX,
  XXXXXXX,   XXXXXXX,   KC_LALT,   KC_RSFT,   KC_LCTRL,  XXXXXXX,                     KC_SLSH,   KC_4,      KC_5,      KC_6,      KC_PLUS,   XXXXXXX,
  XXXXXXX,   KC_LGUI,   KC_RALT,   KC_DOT,    KC_COMM,   XXXXXXX, XXXXXXX,   XXXXXXX, KC_EQL,    KC_1,      KC_2,      KC_3,      KC_ENT,    XXXXXXX,
                       XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,                 _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
),
};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _COLEMAK_DH:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK_DH:
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Number"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Symbol"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK_DH);
            }
            return false;
        case KC_NAV:
            if (record->event.pressed) {
                layer_on(_NAV);
                update_tri_layer(_NAV, _SYM, _NUM);
            } else {
                layer_off(_NAV);
                update_tri_layer(_NAV, _SYM, _NUM);
            }
            return false;
        case KC_SYM:
            if (record->event.pressed) {
                layer_on(_SYM);
                update_tri_layer(_NAV, _SYM, _NUM);
            } else {
                layer_off(_SYM);
                update_tri_layer(_NAV, _SYM, _NUM);
            }
            return false;
        case KC_NMBR:
            if (record->event.pressed) {
                layer_on(_NUM);
            } else {
                layer_off(_NUM);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDOWN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif
