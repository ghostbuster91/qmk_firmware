#include QMK_KEYBOARD_H
#include "print.h"

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
#define DEL LT(_FUN, KC_DEL) 
#define ENTER RSFT_T(KC_ENT) 

#define      O_GUI    OSM(MOD_LGUI)
#define      O_SFT    OSM(MOD_LSFT)
#define      O_CTL    OSM(MOD_LCTL)
#define      O_LALT    OSM(MOD_LALT)
#define      O_RALT    OSM(MOD_RALT)

#define CT_TAB LCTL(KC_TAB)
#define CT_SFT_TAB LCTL(LSFT(KC_TAB))

#define SFT_TAB LSFT(KC_TAB)

enum tbkmini_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _CLM,
    _NAV,
    _SYM,
    _NUM,
    _ADJ,
    _FUN,
    _GAME,
    _GAME2
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAK,
    KC_NAV,
    KC_SYM,
    KC_NMBR,
    KC_TMUX,
    KC_FUN,
    ALT_TAB,
    ALT_SFT_TAB,
    KC_SFT_TAB,
    VIM_WQ,
    LLOCK,
    KC_GAME,
    KC_GAME2
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_CLM] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB     ,KC_Q     ,KC_W     ,KC_F    ,KC_P    ,KC_B				,KC_J   ,KC_L   ,KC_U    ,KC_Y    ,KC_SCLN ,XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_ESC     ,HOME_A   ,HOME_R   ,HOME_S  ,HOME_T  ,HOME_G                        ,HOME_M ,HOME_N ,HOME_E  ,HOME_I  ,HOME_O  ,KC_QUOT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	XXXXXXX    ,KC_Z     ,KC_X     ,KC_C    ,KC_D    ,KC_V     			,KC_K   ,KC_H   ,KC_COMM ,KC_DOT  ,KC_SLSH ,XXXXXXX  , 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
						 KC_NMBR, BSPC     ,DEL       ,ENTER    ,SPACE    ,XXXXXXX
        //`--------------------------'  `--------------------------'

        ),
    [_GAME] = LAYOUT_split_3x6_3(

        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
	XXXXXXX     ,KC_ESC  ,KC_Q    ,KC_W    ,KC_E     ,KC_R         	     	     ,XXXXXXX ,XXXXXXX  ,XXXXXXX ,XXXXXXX, XXXXXXX, KC_COLEMAK  ,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	XXXXXXX     ,KC_TAB  ,KC_A    ,KC_S    ,KC_D     ,KC_F                       ,XXXXXXX   ,XXXXXXX    ,XXXXXXX  ,XXXXXXX   ,XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	XXXXXXX     ,XXXXXXX ,KC_Z    ,KC_X    ,KC_C     ,KC_V               ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX, XXXXXXX, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        					LT(_NUM,KC_SPC), KC_GAME2, KC_ENT           ,XXXXXXX  ,XXXXXXX, XXXXXXX
	//`--------------------------'  `--------------------------'
        ),

    [_GAME2] = LAYOUT_split_3x6_3(

        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
	XXXXXXX     ,XXXXXXX  ,KC_J    ,KC_M    ,KC_N   ,XXXXXXX         	     ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX, XXXXXXX  ,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	XXXXXXX     ,XXXXXXX ,O_LALT  ,O_SFT   ,O_CTL   ,XXXXXXX                     ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	XXXXXXX     ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX               ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX, XXXXXXX, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        					_______, KC_SPC, KC_ENT           ,XXXXXXX  ,XXXXXXX, XXXXXXX
	//`--------------------------'  `--------------------------'
        ),


    [_NAV] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
	_______ ,_______ ,_______ ,_______ ,_______ ,_______  		     	     ,_______   ,_______  ,KC_HOME  ,KC_END   ,_______  ,_______  ,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	ALT_TAB    ,O_GUI    ,O_LALT   ,O_SFT    ,O_CTL    ,O_RALT   		     ,KC_LEFT   ,KC_DOWN  ,KC_UP    ,KC_RIGHT ,_______  ,VIM_WQ   ,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	ALT_SFT_TAB,KC_UNDO  ,KC_CUT   ,KC_COPY  ,KC_PASTE ,_______  		     ,_______   ,KC_PGDOWN,KC_PGUP  ,_______  ,_______  ,_______  ,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
						_______,_______,_______, 	_______,_______,_______
        //`--------------------------'  `--------------------------'
        ),

    [_SYM] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
	_______     , KC_QUOT,   KC_LABK,   KC_RABK,   KC_DQUO,   KC_GRV, KC_AMPR,   KC_UNDERSCORE,KC_LBRC,KC_RBRC,   KC_PERC,_______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	KC_TAB      , KC_EXLM,   KC_MINS,   KC_PLUS,   KC_EQL,    KC_HASH,KC_PIPE,   KC_COLON,  KC_LPRN,   KC_RPRN,   KC_SCLN,_______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	SFT_TAB  , KC_CIRC,   KC_SLSH,   KC_ASTR,   KC_BSLS,   KC_AT,                KC_TILD,  KC_DLR   ,KC_LCBR ,KC_RCBR ,KC_QUES ,_______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        					_______,_______,_______, 	_______,_______,_______
        //`--------------------------'  `--------------------------'
        ),

    [_NUM] = LAYOUT_split_3x6_3(

        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
	_______     ,_______  ,KC_7   ,KC_8   ,KC_9   ,	_______    , 	       _______  ,_______   ,_______   ,_______   , _______, _______  ,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	CT_TAB      ,KC_0     ,KC_1   ,KC_2   ,KC_3,   _______,        	               O_RALT   ,O_CTL    ,O_SFT  ,O_LALT   ,O_GUI, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	CT_SFT_TAB  ,_______  ,KC_4   ,KC_5   ,KC_6   ,_______               ,_______ ,_______ ,_______ ,_______ ,_______, _______, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        					_______,_______,_______, 	_______,_______,_______
	//`--------------------------'  `--------------------------'
        ),
   [_FUN] = LAYOUT_split_3x6_3(

        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
	_______     ,_______  ,_______   ,_______   ,_______   ,_______                ,_______ ,KC_F7  ,KC_F8   ,KC_F9   ,KC_F12, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	_______      ,O_GUI    ,O_LALT   ,O_SFT    ,O_CTL    ,O_RALT	       	       ,_______ ,KC_F4  ,KC_F5   ,KC_F6   ,KC_F11, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	_______  ,_______  ,_______   ,_______   ,_______   ,_______               	       ,_______ ,KC_F1  ,KC_F2   ,KC_F3   ,KC_F10, _______, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        					_______,_______,_______, 	_______,_______,_______
	//`--------------------------'  `--------------------------'
        ),
    [_ADJ] = LAYOUT_split_3x6_3(

        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
	_______    , _______,   _______, _______   ,_______   ,	_______    ,           KC_COLEMAK ,KC_GAME  ,_______ ,_______, _______, QK_BOOT  ,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	_______    , _______,     _______,  _______,   _______,   _______,             _______   ,_______    ,_______  ,_______   ,_______, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	_______ ,_______   ,_______   ,_______   ,_______   ,_______               ,_______ ,_______ ,_______ ,_______ ,_______, _______, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        					_______,_______,_______, 	_______,_______,_______
	//`--------------------------'  `--------------------------'
        )
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
  // If console is enabled, it will print the matrix position and status of each key pressed
    update_swapper(&alt_tab_active, KC_LALT, KC_TAB, ALT_TAB, ALT_SFT_TAB, &sft_grv_active, keycode, record);
    update_swapper(&sft_grv_active, KC_LALT, KC_GRV, ALT_SFT_TAB, ALT_TAB, &alt_tab_active, keycode, record);
    switch (keycode) {
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_CLM);
            }
            return false;
        case KC_GAME:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAME);
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
	case KC_GAME2:
            if (record->event.pressed) {
                layer_on(_GAME2);
            } else {
                layer_off(_GAME2);
            }
            return false;
	case KC_FUN:
            if (record->event.pressed) {
                layer_on(_FUN);
            } else {
                layer_off(_FUN);
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
  state = update_tri_layer_state(state, _NAV, _SYM, _ADJ);
  uprintf("%d layer\n", state);
  return state;
}
