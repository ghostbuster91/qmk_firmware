#include QMK_KEYBOARD_H

void update_swapper(bool *active, uint16_t cmdish, uint16_t tabish,
                    uint16_t trigger, uint16_t prv, uint16_t sftish, uint16_t keycode, keyrecord_t *record);

// To be implemented by the consumer. Defines keys to ignore when swapper is active.
bool is_swapper_ignored_key(uint16_t keycode);

const uint16_t PROGMEM combo_fp_tab[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM combo_lu_esc[] = {KC_L, KC_U, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_fp_tab, KC_TAB),
    COMBO(combo_lu_esc, KC_ESC), 
};


bool alt_tab_active = true;
// This keymap uses home row mods. In addition to mods, I have home row
// layer-tap keys for the SYM layer. The key arrangement is a variation on
// "GASC-order" home row mods:
//
//             Left hand                          Right hand
// +-------+-------+-------+-------+------+    +------+-------+-------+-------+-------+
// | LGui  |  LAlt |LShift | LCtrl | RAlt |    | RAlt | RCtrl |RShift |  LAlt | RGui  |
// +-------+-------+-------+-------+------+    +------+-------+-------+-------+-------+

// Home row mods for Colemak-dh layer.
#define HOME_R  LALT_T(KC_R)
#define HOME_S  LSFT_T(KC_S)
#define HOME_T  LCTL_T(KC_T)
#define HOME_N  RCTL_T(KC_N)
#define HOME_E  RSFT_T(KC_E)
#define HOME_I  LALT_T(KC_I)
#define HOME_A  LGUI_T(KC_A)
#define HOME_G  RALT_T(KC_G)
#define HOME_M  RALT_T(KC_M)	
#define HOME_O  RGUI_T(KC_O)	

// Home row mods for number layer.
#define NUM_1 LGUI_T(KC_1)
#define NUM_2 LALT_T(KC_2)
#define NUM_3 LSFT_T(KC_3)
#define NUM_4 LCTL_T(KC_4)
#define NUM_5 RALT_T(KC_5)
#define NUM_6 RALT_T(KC_6)
#define NUM_7 RCTL_T(KC_7)
#define NUM_8 RSFT_T(KC_8)
#define NUM_9 LALT_T(KC_9)
#define NUM_0 RGUI_T(KC_0)

// Home row mods for QWERTY layer.
#define QHOME_S LALT_T(KC_S)
#define QHOME_D LSFT_T(KC_D)
#define QHOME_F LCTL_T(KC_F)
#define QHOME_J RCTL_T(KC_J)
#define QHOME_K RSFT_T(KC_K)
#define QHOME_L LALT_T(KC_L)
#define QHOME_A  LGUI_T(KC_A)
#define QHOME_G  RALT_T(KC_G)
#define QHOME_H  RALT_T(KC_H)
#define QHOME_SCLN  RGUI_T(KC_SCLN)

#define SPACE LT(_SYM, KC_SPC)
#define BSPC LT(_NAV, KC_BSPC)
#define DEL LSFT_T(KC_DEL)

#define      O_GUI    OSM(MOD_LGUI)
#define      O_SFT    OSM(MOD_LSFT)
#define      O_CTL    OSM(MOD_LCTL)
#define      O_LALT    OSM(MOD_LALT)
#define      O_RALT    OSM(MOD_RALT)

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _CLM,
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
    KC_DLINE,
    KC_TMUX,
    ALT_TAB,
    SFT_TAB
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * COLEMAK DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  | A/⎇  |  R/◆ |  S/⇧ | T/⎈  |  G/◆ |-------.    ,-------| M/◆  | N/⎈  | E/⇧  | I/◆  | O/⎇  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      | Z    |  X   |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |  _   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      | TAB  |  DEL | / BSPC  /       \Space \  |  ENT |      |      |      |
 *            |      |      |      |      |/  NAV  /         \ SYM  \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */

[_CLM] = LAYOUT(
  KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,                         KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11,     KC_F12,
  XXXXXXX,   KC_Q,      KC_W,      KC_F,      KC_P,      KC_B,                          KC_J,     KC_L,     KC_U,     KC_Y,      KC_SCLN,    XXXXXXX,
  KC_ESC,    HOME_A,    HOME_R,    HOME_S,    HOME_T,    HOME_G,                        HOME_M,   HOME_N,   HOME_E,   HOME_I,    HOME_O,     KC_QUOT,
  XXXXXXX,   KC_Z,      KC_X,      KC_C,      KC_D,      KC_V,    KC_MUTE,     XXXXXXX, KC_K,     KC_H,     KC_COMM,  KC_DOT,    KC_SLSH,    KC_UNDS,
                 XXXXXXX, XXXXXXX, KC_TAB,    DEL,       BSPC,    SPACE,  KC_ENT, XXXXXXX, XXXXXXX, XXXXXXX
),
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      | NAV  | / BSPC  /       \Space \  |  SYM |      |      |      |
 *            |      |      |      |      |/       /         \      \ |  ENT |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_QWERTY] = LAYOUT(
  XXXXXXX,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  KC_TAB,   QHOME_A,QHOME_S, QHOME_D, QHOME_F, QHOME_G,                  QHOME_H, QHOME_J, QHOME_K, QHOME_L, QHOME_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_B,    KC_B, KC_MUTE,     XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 XXXXXXX,XXXXXXX,XXXXXXX, MO(_NAV), KC_BSPC,      KC_SPC,  LT(_SYM,KC_ENT), XXXXXXX, XXXXXXX, XXXXXXX
),
/*
 * _SYMBOL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   '  |   <  |   >  |   "  |   `  |                    |   &  |   _  |   [  |   ]  |   %  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   -  |   +  |   =  |   #  |-------.    ,-------|   |  |   :  |   (  |   )  |   ;  | LOCK |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |   ^  |   /  |   *  |   \  |   @  |-------|    |-------|   ~  |   $  |   {  |   }  |   ?  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |  DEL | / BSCP  /       \Space \  |  SYM |      |      |      |
 *            |      |      |      |      |/       /         \      \ |  ENT |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */

[_SYM] = LAYOUT(
  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                      XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
  KC_ESC,    KC_QUOT,   KC_LABK,   KC_RABK,   KC_DQUO,   KC_GRV,                       KC_AMPR,   KC_UNDERSCORE,KC_LBRC,KC_RBRC,   KC_PERC,   XXXXXXX,
  KC_TAB,    KC_EXLM,   KC_MINS,   KC_PLUS,   KC_EQL,    KC_HASH,                      KC_PIPE,   KC_COLON,  KC_LPRN,   KC_RPRN,   KC_SCLN,   XXXXXXX,
  KC_LSFT,   KC_CIRC,   KC_SLSH,   KC_ASTR,   KC_BSLS,   KC_AT,   KC_MUTE,    XXXXXXX, KC_TILD,   KC_DLR,    KC_LCBR,   KC_RCBR,   KC_QUES,   XXXXXXX,
            		      XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,    _______, _______, XXXXXXX, XXXXXXX, XXXXXXX 
),
/* NAVIGATION
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | RST  |      |      |      |      |      |                    |      |      |      |      |COLEMA|QWERTY|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |KC_INS| PSCR |SELECT| TMUX | 	                  |CPSWRD| Tab  | Home | End  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |ALTTAB| LGUI | LAlt |LShift| LCTR | RAlt |-------.    ,-------| LEFT | DOWN |  UP  | RIGHT|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |SFTTAB| UNDO | CUT  | COPY | PASTE|      |-------|    |-------|      | PgDn | PgUp |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |  NAV | / BSPC  /       \Space \  |  SYM |      |      |      |
 *            |      |      |      |      |/       /         \      \ |  ENT |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */
[_NAV] = LAYOUT(
  QK_BOOT,   _______,   _______,   _______,   _______,   _______,                       _______,    _______,    _______,  KC_COLEMAK, KC_QWERTY, _______,   
  _______,   _______,   KC_INS,    KC_PSCR,   LCTL(KC_A),KC_TMUX,                       CAPSWRD,    KC_TAB, 	KC_HOME,  KC_END,    _______,   _______,   
  ALT_TAB,   O_GUI,     O_LALT,    O_SFT,     O_CTL,     O_RALT,                        KC_LEFT,    KC_DOWN,    KC_UP,    KC_RIGHT,  _______,   _______,   
  SFT_TAB,   KC_UNDO,   KC_CUT,    KC_COPY,   KC_PASTE,  _______, _______,     _______, _______,    KC_PGDOWN,  KC_PGUP,  _______,   _______,   _______,   
                             _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* NUMBERS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  .   | DOWN |  %   |  +   |                    |  -   |  =   |  UP  |  ,   |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   1  |  2   |  3   |  4   |  5   |-------.    ,-------|  6   |  7   |  8   |  9   |  0   |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |  "   |  0   |      |-------|    |-------|      |  /   |   (  |  )   |  _   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |  NAV | / BSPC  /       \Space \  |  SYM |      |      |      |
 *            |      |      |      |      |/       /         \      \ |  ENT |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */
[_NUM] = LAYOUT(    
  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                     XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
  XXXXXXX,   XXXXXXX,   KC_DOT,    KC_DOWN,   KC_PERC,   KC_PLUS,                     KC_MINS,   KC_EQL,    KC_UP,     KC_COLON,  XXXXXXX,   XXXXXXX,
  XXXXXXX,   NUM_1,     NUM_2,     NUM_3,     NUM_4,     NUM_5,                       NUM_6,     NUM_7,     NUM_8,     NUM_9,     NUM_0,      XXXXXXX,
  XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_DQT,    KC_ASTR,   XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,   KC_SLSH,   KC_LPRN,   KC_RPRN,   KC_UNDS,   XXXXXXX,
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

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _CLM:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _CLM:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _QWERTY:
            oled_write_P(PSTR("Qwrt\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("NMBR\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("SYM\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("NAV\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    bool caps_word_state = is_caps_word_on();
    oled_write_ln_P(PSTR("CPSLK"), caps_word_state);
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
    update_swapper(&alt_tab_active, KC_LALT, KC_TAB, ALT_TAB, SFT_TAB, KC_LSFT, keycode, record);
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_CLM);
            }
            return false;
        case KC_NAV:
            if (record->event.pressed) {
                layer_on(_NAV);
            } else {
                layer_off(_NAV);
            }
            return false;
        case KC_SYM:
            if (record->event.pressed) {
                layer_on(_SYM);
            } else {
                layer_off(_SYM);
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
	case KC_TMUX:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_B);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_B);
            }
            return false;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NAV, _SYM, _NUM);
}

bool is_swapper_ignored_key(uint16_t keycode) {
  switch (keycode) { 
    default:
      return false;
  }
}


void update_swapper(bool *active, uint16_t cmdish, uint16_t tabish,
                    uint16_t trigger, uint16_t prv, uint16_t sftish,
		    uint16_t keycode, keyrecord_t *record) {
  if (keycode == trigger) {
    if (record->event.pressed) {
      if (!*active) {
        *active = true;
        register_code(cmdish);
      }
      register_code(tabish);
    } else {
      unregister_code(tabish);
      // Don't unregister cmdish until some other key is hit or released.
    }
  } else if (keycode == prv && *active) {
    if (record->event.pressed) {
	register_code16(S(tabish));
    } else {
        unregister_code16(S(tabish));
    }
  } else if (!is_swapper_ignored_key(keycode) && *active) {
    // On non-ignored keyup, disable swapper
    unregister_code(cmdish);
    *active = false;
  }
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
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDOWN);
        }
    }
    return true;
}

#endif

