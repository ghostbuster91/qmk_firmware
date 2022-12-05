#include QMK_KEYBOARD_H

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

#define SPACE LT(_SYM, KC_SPC)
#define BSPC LT(_NAV, KC_BSPC)
#define DEL LSFT_T(KC_DEL) 
#define ENTER RSFT_T(KC_ENT) 

#define      O_GUI    OSM(MOD_LGUI)
#define      O_SFT    OSM(MOD_LSFT)
#define      O_CTL    OSM(MOD_LCTL)
#define      O_LALT    OSM(MOD_LALT)
#define      O_RALT    OSM(MOD_RALT)

#define CT_TAB LCTL(KC_TAB)
#define CT_SFT_TAB LCTL(LSFT(KC_TAB))

#define SFT_TAB LSFT(KC_TAB)

enum kinesis_layers {
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
    KC_TMUX,
    ALT_TAB,
    ALT_SFT_TAB,
    KC_SFT_TAB,
    VIM_WQ,
    LLOCK,
};
/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Caps   |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   | INS  | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Ctrl | Alt  |         | Gui  | Ctrl |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Del  |------|         |------|Return| Space|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
           KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_EQL, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_TAB, KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,
           KC_CAPS,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,
           KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,
                   KC_GRV ,KC_INS ,KC_LEFT,KC_RGHT,

			   KC_LCTL, KC_LALT,
                                    KC_HOME,
                           KC_BSPC, KC_DEL ,KC_END ,

           KC_F9 ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  ,KC_PAUS, KC_NO, QK_BOOT,
	   KC_6  ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
	   KC_Y  ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
	   KC_H  ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,
	   KC_N  ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
		KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,

           KC_RGUI, KC_RCTL,
           KC_PGUP,
           KC_PGDN, KC_ENTER ,KC_SPC
    ),
[_CLM] = LAYOUT(
	XXXXXXX    ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX,
	XXXXXXX    ,KC_1     ,KC_2     ,KC_3     ,KC_4     ,KC_5     ,
	KC_TAB     ,KC_Q     ,KC_W     ,KC_F     ,KC_P     ,KC_B     ,
	KC_ESC     ,HOME_A   ,HOME_R   ,HOME_S   ,HOME_T   ,HOME_G   ,
	XXXXXXX    ,KC_Z     ,KC_X     ,KC_C     ,KC_D     ,KC_V     ,
		    XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,

			KC_NMBR, XXXXXXX,
				 XXXXXXX,
			BSPC,    DEL    ,XXXXXXX,

	XXXXXXX   ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX,  XXXXXXX,  QK_BOOT,	
	KC_6      ,KC_7     ,KC_8     ,KC_9     ,KC_0     ,XXXXXXX  ,
	KC_J      ,KC_L     ,KC_U     ,KC_Y     ,KC_SCLN  ,XXXXXXX  ,
	HOME_M    ,HOME_N   ,HOME_E   ,HOME_I   ,HOME_O   ,KC_QUOT  ,
	KC_K      ,KC_H     ,KC_COMM  ,KC_DOT   ,KC_SLSH  ,XXXXXXX  ,
		   XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,

			XXXXXXX, KC_NMBR,
				 XXXXXXX,
			XXXXXXX, ENTER  ,SPACE
	),
[_NAV] = LAYOUT(
	_______    ,_______  ,_______  ,_______  ,_______  ,_______  ,_______, _______ , _______,
	_______    ,_______  ,_______  ,_______  ,_______  ,_______  ,
	_______    ,_______  ,_______  ,_______  ,_______  ,_______  ,
	ALT_TAB    ,O_GUI    ,O_LALT   ,O_SFT    ,O_CTL    ,O_RALT   ,
	ALT_SFT_TAB,KC_UNDO  ,KC_CUT   ,KC_COPY  ,KC_PASTE ,_______  ,
		    _______  ,_______  ,_______  ,_______  ,

			_______, _______,
				 _______,
			_______, _______ ,_______,

	_______   ,_______  ,_______  ,_______  ,_______  ,_______  ,_______,  _______, _______,	
	_______   ,_______  ,_______  ,_______  ,_______  ,_______  ,
	_______   ,_______  ,KC_HOME  ,KC_END   ,_______  ,_______  ,
	KC_LEFT   ,KC_DOWN  ,KC_UP    ,KC_RIGHT ,_______  ,VIM_WQ   ,
	_______   ,KC_PGDOWN,KC_PGUP  ,_______  ,_______  ,_______  ,
		   _______  ,_______  ,_______  ,_______  ,

			_______, _______,
				 _______,
			_______, _______, _______
	),

[_SYM] = LAYOUT(
	_______     , _______ ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______,
	_______     , _______  ,_______   ,_______   ,_______   ,_______   ,
	_______     , KC_QUOT,   KC_LABK,   KC_RABK,   KC_DQUO,   KC_GRV,
	KC_TAB      , KC_EXLM,   KC_MINS,   KC_PLUS,   KC_EQL,    KC_HASH,
	SFT_TAB  , KC_CIRC,   KC_SLSH,   KC_ASTR,   KC_BSLS,   KC_AT,
		    _______ ,_______,_______,_______,

			_______, _______,
				_______,
			_______,_______ ,_______,

	_______     , _______ ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______,
	_______     , _______ ,_______  ,_______  ,_______  ,_______,
	KC_AMPR,   KC_UNDERSCORE,KC_LBRC,KC_RBRC,   KC_PERC,_______,
	KC_PIPE,   KC_COLON,  KC_LPRN,   KC_RPRN,   KC_SCLN,_______,
	KC_TILD,   KC_DLR,    KC_LCBR,   KC_RCBR,   KC_QUES,_______,
		_______,_______  ,_______,_______,

			_______,_______,
				_______,
			_______,_______ ,_______
	),
[_NUM] = LAYOUT(
	_______    , _______ ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______,
	_______    , _______  ,_______   ,_______   ,_______   ,_______   ,
	_______    , _______  ,_______   ,_______   ,_______   ,_______   ,
	CT_TAB    , NUM_1,     NUM_2,     NUM_3,     NUM_4,     NUM_5,
	CT_SFT_TAB ,_______   ,_______   ,_______   ,_______   ,_______   ,
		    _______ ,_______,_______,_______,

			_______, _______,
				_______,
			_______,_______ ,_______,

	_______  ,_______ ,_______ ,_______ ,_______ ,_______  ,_______, _______, _______,	
	_______   ,_______   ,_______   ,_______   ,_______   ,_______,
	_______   ,_______   ,_______   ,_______   ,_______,_______,
	NUM_6,     NUM_7,     NUM_8,     NUM_9,     NUM_0, _______,
	_______   ,_______   ,_______,_______ ,_______,_______,
		_______,_______  ,_______,_______,

			_______,_______,
				_______,
			_______,_______ ,_______
	),
};

void update_swapper(bool *active, uint16_t cmdish, uint16_t tabish,
                    uint16_t trigger, uint16_t prv, bool *other_active, uint16_t keycode, keyrecord_t *record) {
  if (keycode == trigger && !*other_active) {
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
  } else if (*active) {
    // On non-ignored keyup, disable swapper
    unregister_code(cmdish);
    *active = false;
  }
}

bool alt_tab_active = false;
bool sft_grv_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
    update_swapper(&alt_tab_active, KC_LALT, KC_TAB, ALT_TAB, ALT_SFT_TAB, &sft_grv_active, keycode, record);
    update_swapper(&sft_grv_active, KC_LALT, KC_GRV, ALT_SFT_TAB, ALT_TAB, &alt_tab_active, keycode, record);
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
	case VIM_WQ:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LSFT));
                register_code(KC_SCLN);
                unregister_mods(mod_config(MOD_LSFT));
                register_code(KC_W);
                register_code(KC_Q);
                register_code(KC_ENT);
            } else {
                unregister_code(KC_SCLN);
                unregister_code(KC_W);
                unregister_code(KC_Q);
                unregister_code(KC_ENT);
            }
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    writePinHigh(LED_NUM_LOCK_PIN);
    writePinHigh(LED_SCROLL_LOCK_PIN);
    writePinHigh(LED_COMPOSE_PIN);
    writePinHigh(LED_CAPS_LOCK_PIN);
    switch (get_highest_layer(state)) {
        case _CLM:
            // Num Lock Lit
            writePinLow(LED_CAPS_LOCK_PIN);
            break;
        case _NUM:
            // Scroll Lock Lit
            writePinLow(LED_NUM_LOCK_PIN);
            break;
        case _SYM:
            // Compose Lit
            writePinLow(LED_COMPOSE_PIN);
            break;
        case _NAV:
            // All LEDs Lit
            writePinLow(LED_SCROLL_LOCK_PIN);
            break;
    }
  return state;
}

bool led_update_user(led_t led_state) {
    // disable led_update_kb() so that we do not override layer indicators
    return false;
}
