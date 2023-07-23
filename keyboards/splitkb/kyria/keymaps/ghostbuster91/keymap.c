#include QMK_KEYBOARD_H
#include "features/achordion.h"

enum layers {
  _CLM = 0,
  _RSTHD,
  _NAV,
  _SYM,
  _FUN,
  _ADJ,
  _NUM,
};

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
#define R_E LT(_NAV, KC_E)
#define TAB LT(_NUM, KC_TAB)

#define RSTH_R LGUI_T(KC_R)
#define RSTH_S LALT_T(KC_S)
#define RSTH_T LSFT_T(KC_T)
#define RSTH_H LCTL_T(KC_H)
#define RSTH_D RALT_T(KC_D)

#define RSTH_M RALT_T(KC_M)
#define RSTH_N RCTL_T(KC_N)
#define RSTH_A RSFT_T(KC_A)
#define RSTH_I LALT_T(KC_I)
#define RSTH_O RGUI_T(KC_O)

#define R_BSPC LT(_NUM, KC_BSPC)

#define O_GUI OSM(MOD_LGUI)
#define O_SFT OSM(MOD_LSFT)
#define O_CTL OSM(MOD_LCTL)
#define O_LALT OSM(MOD_LALT)
#define O_RALT OSM(MOD_RALT)

#define CT_TAB LCTL(KC_TAB)
#define CT_SFT_TAB LCTL(LSFT(KC_TAB))

#define SFT_TAB LSFT(KC_TAB)

enum custom_keycodes {
  KC_QWERTY = QK_USER,
  KC_NAV,
  KC_SYM,
  KC_NMBR,
  KC_FUN,
  ALT_TAB,
  ALT_SFT_TAB,
  KC_SFT_TAB,
  KC_COLEMAK,
  KC_RSTHD,
  KC_TMUX
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_CLM] = LAYOUT(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,                                        KC_J , KC_L   ,  KC_U  ,   KC_Y ,KC_SCLN, XXXXXXX,
     KC_ESC  ,HOME_A,  HOME_R , HOME_S ,  HOME_T,  HOME_G,                                       HOME_M, HOME_N ,HOME_E  ,HOME_I  ,HOME_O , KC_QUOT,
     XXXXXXX , KC_Z ,  KC_X   ,  KC_C  ,   KC_D ,   KC_V , XXXXXXX,XXXXXXX,   XXXXXXX, XXXXXXX,   KC_K ,   KC_H ,KC_COMM , KC_DOT ,KC_SLSH, XXXXXXX,
                                XXXXXXX, XXXXXXX,     TAB, BSPC   ,DEL    ,     ENTER,  SPACE , KC_TMUX, XXXXXXX,XXXXXXX
    ),


    [_RSTHD] = LAYOUT(
     KC_TAB  ,XXXXXXX,KC_C    ,KC_Y    ,KC_F    ,KC_K	 ,                                       KC_Z  , KC_L   ,KC_Q    ,KC_U    ,XXXXXXX, XXXXXXX,
     KC_ESC  ,RSTH_R ,RSTH_S  ,RSTH_T  ,RSTH_H  ,RSTH_D  ,                                       RSTH_M,RSTH_N  ,RSTH_A  ,RSTH_I  ,RSTH_O , KC_QUOT,
     XXXXXXX ,KC_J   ,KC_V    ,KC_G    ,KC_P    ,KC_B    ,XXXXXXX,XXXXXXX,    XXXXXXX, XXXXXXX,  KC_X  ,KC_W    ,KC_COMM ,KC_DOT  ,KC_SLSH, XXXXXXX,
                               XXXXXXX ,XXXXXXX ,R_BSPC  ,R_E    ,DEL    ,      ENTER, SPACE  ,XXXXXXX ,XXXXXXX ,XXXXXXX
    ),


    [_NAV] = LAYOUT(
     _______ , _______, _______, _______, _______, _______,                                     _______, _______, KC_HOME, KC_END , _______, KC_F12,
     ALT_TAB ,  O_GUI , O_LALT ,  O_SFT ,  O_CTL ,  O_RALT,                                     KC_LEFT, KC_DOWN, KC_UP  ,KC_RIGHT, _______, KC_F11,
  ALT_SFT_TAB,KC_UNDO , KC_CUT , KC_COPY,KC_PASTE, KC_PSCR, _______, _______, _______, _______, _______, KC_PGDN,KC_PGUP ,_______ , _______, KC_F10,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),


    [_SYM] = LAYOUT(
     _______ , KC_QUOT, KC_LABK, KC_RABK, KC_DQUO, KC_GRV ,                                     KC_AMPR, KC_UNDS, KC_LBRC, KC_RBRC, KC_PERC, _______,
     KC_TAB  , KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_HASH,                                     KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_SCLN, KC_DQUO,
     SFT_TAB , KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, KC_AT,   _______, _______, _______, _______, KC_TILD, KC_DLR , KC_LCBR, KC_RCBR, KC_QUES, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),


    [_NUM] = LAYOUT(
	 _______ , _______, _______, _______, _______, _______,                                     _______, KC_7   , KC_8    , KC_9   , _______, _______,
	 CT_TAB  , O_GUI  , O_LALT ,  O_SFT ,  O_CTL ,  O_RALT,                                     _______, KC_4   , KC_5    , KC_6   , KC_0   , _______,
   CT_SFT_TAB, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_1   , KC_2    , KC_3   , _______, _______,
					             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),


    [_FUN] = LAYOUT(
	 QK_BOOT,KC_COLEMAK,KC_RSTHD, _______, _______, _______,                                     _______, KC_F7  , KC_F8   , KC_F9  , KC_F12 , _______,
	 _______  ,KC_LGUI , O_LALT , O_SFT  ,  O_CTL , O_RALT ,                                     _______, KC_F4  , KC_F5   , KC_F6  , KC_F11 , _______,
	 _______  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F1  , KC_F2   , KC_F3  , KC_F10 , _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),


    [_ADJ] = LAYOUT(
	 _______  ,LCTL(KC_1),LCTL(KC_2), LCTL(KC_3),LCTL(KC_4),LCTL(KC_5),                         LCTL(KC_6),LCTL(KC_7),LCTL(KC_8),LCTL(KC_9),LCTL(KC_0), _______,
	 _______  ,LALT(KC_1),LALT(KC_2),LALT(KC_3),LALT(KC_4),LALT(KC_5),                          LALT(KC_6),LALT(KC_7),LALT(KC_8),LALT(KC_9),LALT(KC_0), _______,
	 _______  ,_______   ,_______   ,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______ ,_______ ,_______, _______,
        					         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
  case KC_RSTHD:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_RSTHD);
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
  case KC_TMUX:
    if (record->event.pressed) {
      register_mods(mod_config(MOD_LCTL));
      register_code(KC_B);
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

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;
        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;
        default:
            return false;  // Deactivate Caps Word.
    }
}

#ifdef OLED_ENABLE

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // QMK Logo and version information
    // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
    // clang-format on

    oled_write_P(qmk_logo, false);
    oled_write_P(PSTR("Kyria "), false);
    oled_write_P(PSTR("rev3\n\n"), false);
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state | default_layer_state)) {
    case 0:
      oled_write_P(PSTR("Colemak-DH\n"), false);
      break;
    case 1:
      oled_write_P(PSTR("RSTHD\n"), false);
      break;
    case 2:
      oled_write_P(PSTR("Nav\n"), false);
      break;
    case 3:
      oled_write_P(PSTR("Sym\n"), false);
      break;
    case 4:
      oled_write_P(PSTR("Fun\n"), false);
      break;
    case 5:
      oled_write_P(PSTR("Adj\n"), false);
      break;
    case 6:
      oled_write_P(PSTR("Num\n"), false);
      break;
    default:
      oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(led_usb_state.num_lock ? PSTR("NUMLCK ") : PSTR("       "),
                 false);
    oled_write_P(led_usb_state.caps_lock ? PSTR("CAPLCK ") : PSTR("       "),
                 false);
    oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "),
                 false);
  } else {
    // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
    // clang-format on
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
  }
  return false;
}
#endif
