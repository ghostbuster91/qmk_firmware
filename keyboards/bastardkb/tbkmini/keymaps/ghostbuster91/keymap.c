#include QMK_KEYBOARD_H
#include "features/achordion.h"
#include "print.h"

#define HOME_R LALT_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)
#define HOME_N RCTL_T(KC_N)
#define HOME_E RSFT_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_A LGUI_T(KC_A)
#define HOME_G RALT_T(KC_G)
#define HOME_M RALT_T(KC_M)
#define HOME_O RGUI_T(KC_O)

#define NRST_N LGUI_T(KC_R)
#define NRST_R LALT_T(KC_S)
#define NRST_S LSFT_T(KC_T)
#define NRST_T LCTL_T(KC_H)
#define NRST_D RALT_T(KC_D)

#define NRST_L RALT_T(KC_M)
#define NRST_H RCTL_T(KC_N)
#define NRST_A RSFT_T(KC_A)
#define NRST_E LALT_T(KC_I)
#define NRST_I RGUI_T(KC_O)

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

#define O_GUI OSM(MOD_LGUI)
#define O_SFT OSM(MOD_LSFT)
#define O_CTL OSM(MOD_LCTL)
#define O_LALT OSM(MOD_LALT)
#define O_RALT OSM(MOD_RALT)

#define CT_TAB LCTL(KC_TAB)
#define CT_SFT_TAB LCTL(LSFT(KC_TAB))

#define SFT_TAB LSFT(KC_TAB)

enum tbkmini_layers {
  /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
  _CLM,
  _NRST,
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
  KC_NRST,
  KC_NAV,
  KC_SYM,
  KC_NMBR,
  KC_TMUX,
  KC_FUN,
  ALT_TAB,
  ALT_SFT_TAB,
  KC_SFT_TAB,
  VIM_W,
  LLOCK,
  KC_GAME,
  KC_GAME2
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_CLM] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB     ,KC_Q     ,KC_W     ,KC_F    ,KC_P    ,KC_B				,KC_J   ,KC_L   ,KC_U    ,KC_Y    ,KC_SCLN ,XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_ESC     ,HOME_A   ,HOME_R   ,HOME_S  ,HOME_T  ,HOME_G                        ,HOME_M ,HOME_N ,HOME_E  ,HOME_I  ,HOME_O  ,KC_QUOT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	XXXXXXX    ,KC_Z     ,KC_X     ,KC_C    ,KC_D    ,KC_V     			,KC_K   ,KC_H   ,KC_COMM ,KC_DOT  ,KC_SLSH ,XXXXXXX  , 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
						                        KC_NMBR, BSPC     ,DEL       ,ENTER    ,SPACE    ,KC_TMUX
        //`--------------------------'  `--------------------------'

        ),
   [_NRST] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB     ,KC_Q     ,KC_W     ,KC_Y    ,KC_P    ,KC_B			            	,KC_J   ,KC_K   ,KC_O    ,KC_U    ,XXXXXXX ,XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_ESC     ,NRST_N   ,NRST_R   ,NRST_S  ,NRST_T  ,NRST_D                        ,NRST_L ,NRST_H ,NRST_A  ,NRST_E  ,NRST_I  ,KC_QUOT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	    XXXXXXX    ,KC_Z     ,KC_X     ,KC_C    ,KC_F    ,KC_G     			            ,KC_V   ,KC_M   ,KC_COMM ,KC_DOT  ,KC_SLSH ,XXXXXXX  , 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
						                        KC_NMBR,  BSPC   ,DEL       ,ENTER    ,SPACE    ,KC_TMUX
        //                                    `--------------------------'  `--------------------------'

        ),
    [_GAME] = LAYOUT_split_3x6_3(

        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
	XXXXXXX     ,KC_ESC  ,KC_Q    ,KC_W    ,KC_E     ,KC_R         	     	     ,XXXXXXX ,XXXXXXX  ,XXXXXXX ,XXXXXXX, XXXXXXX, KC_COLEMAK  ,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	XXXXXXX     ,KC_TAB  ,KC_A    ,KC_S    ,KC_D     ,KC_F                       ,XXXXXXX   ,XXXXXXX    ,XXXXXXX  ,XXXXXXX   ,XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	XXXXXXX     ,XXXXXXX ,KC_Z    ,KC_X    ,KC_C     ,KC_V               ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX, XXXXXXX, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        					KC_SPC, KC_GAME2, KC_ENT           ,XXXXXXX  ,XXXXXXX, XXXXXXX
	//`--------------------------'  `--------------------------'
        ),

    [_GAME2] = LAYOUT_split_3x6_3(

        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
	XXXXXXX     ,KC_0  ,KC_1    ,KC_2    ,KC_3   ,KC_4           	     ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX, XXXXXXX  ,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	XXXXXXX     ,XXXXXXX ,O_LALT  ,O_SFT   ,O_CTL   ,XXXXXXX                     ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	XXXXXXX     ,XXXXXXX ,KC_J ,KC_M ,KC_N ,XXXXXXX                	             ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX, XXXXXXX, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
					  _______, _______, _______           ,XXXXXXX  ,XXXXXXX, XXXXXXX
	//`--------------------------'  `--------------------------'
        ),


    [_NAV] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
	_______ ,_______ ,_______ ,_______ ,_______ ,_______  		     	     ,_______   ,_______  ,KC_HOME  ,KC_END   ,_______  ,_______  ,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	ALT_TAB    ,O_GUI    ,O_LALT   ,O_SFT    ,O_CTL    ,O_RALT   		     ,KC_LEFT   ,KC_DOWN  ,KC_UP    ,KC_RIGHT ,_______  ,VIM_W   ,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	ALT_SFT_TAB,KC_UNDO  ,KC_CUT   ,KC_COPY  ,KC_PASTE ,_______  		     ,KC_PSCR   ,KC_PGDN,KC_PGUP  ,_______  ,_______  ,_______  ,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
						_______,_______,_______, 	_______,_______,_______
        //`--------------------------'  `--------------------------'
        ),

    [_SYM] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
	_______     , KC_QUOT,   KC_LABK,   KC_RABK,   KC_DQUO,   KC_GRV, KC_AMPR,   KC_UNDERSCORE,KC_LBRC,KC_RBRC,   KC_PERC   ,_______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	KC_TAB      , KC_EXLM,   KC_MINS,   KC_PLUS,   KC_EQL,    KC_HASH,KC_PIPE,   KC_COLON,  KC_LPRN,   KC_RPRN,   KC_SCLN,  KC_DQUO,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	SFT_TAB  , KC_CIRC,   KC_SLSH,   KC_ASTR,   KC_BSLS,   KC_AT,                KC_TILD,  KC_DLR   ,KC_LCBR ,KC_RCBR ,KC_QUES ,_______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        					_______,_______,_______, 	_______,_______,_______
        //`--------------------------'  `--------------------------'
        ),

    [_NUM] = LAYOUT_split_3x6_3(

        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
	_______     ,_______  ,_______   ,_______   ,_______   , _______             ,_______  ,KC_7   ,KC_8   ,KC_9   , _______, _______  ,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	CT_TAB      ,O_GUI    ,O_LALT   ,O_SFT    ,O_CTL    ,O_RALT        	     ,_______ ,KC_4   ,KC_5   ,KC_6   , KC_0, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	CT_SFT_TAB  ,_______  ,_______   ,_______   ,_______   ,_______              ,_______ ,KC_1   ,KC_2   ,KC_3   , _______, _______, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
					_______,_______,_______, 	KC_BSPC,_______,_______
	//`--------------------------'  `--------------------------'
        ),
   [_FUN] = LAYOUT_split_3x6_3(

        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
	QK_BOOT     ,KC_COLEMAK  ,KC_NRST   ,_______   ,_______   ,_______                ,_______ ,KC_F7  ,KC_F8   ,KC_F9   ,KC_F12, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	_______      ,O_GUI    ,O_LALT   ,O_SFT    ,O_CTL    ,O_RALT	       	       ,_______ ,KC_F4  ,KC_F5   ,KC_F6   ,KC_F11, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	_______  ,_______  ,_______   ,_______   ,_______   ,_______                   ,_______ ,KC_F1  ,KC_F2   ,KC_F3   ,KC_F10, _______, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        					_______,_______,_______, 	_______,_______,_______
	//`--------------------------'  `--------------------------'
        ),
    [_ADJ] = LAYOUT_split_3x6_3(

        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
	_______    ,LCTL(KC_1),LCTL(KC_2), LCTL(KC_3),LCTL(KC_4),LCTL(KC_5),     LCTL(KC_6),LCTL(KC_7),LCTL(KC_8),LCTL(KC_9),LCTL(KC_0), _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	_______    ,LALT(KC_1),LALT(KC_2),LALT(KC_3),LALT(KC_4),LALT(KC_5),      LALT(KC_6),LALT(KC_7),LALT(KC_8),LALT(KC_9),LALT(KC_0), _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	_______ ,_______   ,_______   ,_______   ,_______   ,_______               ,_______ ,_______ ,_______ ,_______ ,_______, _______, 
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        					_______,_______,_______, 	_______,_______,_______
	//`--------------------------'  `--------------------------'
        )
};
// clang-format on

void update_swapper(bool *active, uint16_t cmdish, uint16_t tabish,
                    uint16_t trigger, uint16_t prv, bool *other_active,
                    uint16_t keycode, keyrecord_t *record) {
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
  // If console is enabled, it will print the matrix position and status of each
  // key pressed
#ifdef CONSOLE_ENABLE
  uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: "
          "%u, count: %u\n",
          keycode, record->event.key.col, record->event.key.row,
          record->event.pressed, record->event.time, record->tap.interrupted,
          record->tap.count);
#endif
  if (!process_achordion(keycode, record)) {
    return false;
  }
  update_swapper(&alt_tab_active, KC_LALT, KC_TAB, ALT_TAB, ALT_SFT_TAB,
                 &sft_grv_active, keycode, record);
  update_swapper(&sft_grv_active, KC_LALT, KC_GRV, ALT_SFT_TAB, ALT_TAB,
                 &alt_tab_active, keycode, record);
  switch (keycode) {
  case KC_COLEMAK:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_CLM);
    }
    return false;
  case KC_NRST:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_NRST);
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
  case VIM_W:
    if (record->event.pressed) {
      register_mods(mod_config(MOD_LSFT));
      register_code(KC_SCLN);
      unregister_mods(mod_config(MOD_LSFT));
      register_code(KC_W);
      register_code(KC_ENT);
      unregister_code(KC_SCLN);
      unregister_code(KC_W);
      unregister_code(KC_ENT);
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
  state = update_tri_layer_state(state, _NAV, _SYM, _ADJ);
#ifdef CONSOLE_ENABLE
  uprintf("%d layer\n", state);
#endif
  return state;
}

void matrix_scan_user(void) { achordion_task(); }

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record,
                     uint16_t other_keycode, keyrecord_t *other_record) {
  // Exceptionally consider the following chords as holds, even though they are
  // on the same hand
  switch (tap_hold_keycode) {
  case HOME_T: // T + A.
    if (other_keycode == HOME_A) {
      return true;
    }
    break;
  }

  // Also allow same-hand holds when the tap_hold_key belongs to thumb cluster
  if (tap_hold_record->event.key.row == 7 ||
      tap_hold_record->event.key.row == 3) {
    return true;
  }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}
