#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
#define COMBO_COUNT 2
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#ifdef TAPPING_TERM
#  undef TAPPING_TERM
#endif // !TAPPING_TERM	

#define TAPPING_TERM 200 

#define IGNORE_MOD_TAP_INTERRUPT

