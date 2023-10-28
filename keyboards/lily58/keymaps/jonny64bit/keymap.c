#include QMK_KEYBOARD_H
#include "keymap_uk.h"

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _MOVEMENT,
  _EXTRA
};

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

// Tap Dance declarations
enum {
    TD_ENT_ESC,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Enter, twice for Escape
    [TD_ENT_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_ENT, KC_ESC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬────────┬────────┬────────┬─────────────┬─────────────┐                                         ┌──────┬────────┬─────────────┬────────┬───────────┬─────┐
//    │ esc  │   1    │   2    │   3    │      4      │      5      │                                         │  6   │   7    │      8      │   9    │     0     │  `  │
//    ├──────┼────────┼────────┼────────┼─────────────┼─────────────┤                                         ├──────┼────────┼─────────────┼────────┼───────────┼─────┤
//    │ tab  │   q    │   w    │   e    │      r      │      t      │                                         │  y   │   u    │      i      │   o    │     p     │  -  │
//    ├──────┼────────┼────────┼────────┼─────────────┼─────────────┤                                         ├──────┼────────┼─────────────┼────────┼───────────┼─────┤
//    │ lctl │ HOME_A │ HOME_S │ HOME_D │   HOME_F    │      g      │                                         │  h   │ HOME_J │   HOME_K    │ HOME_L │ HOME_SCLN │  '  │
//    ├──────┼────────┼────────┼────────┼─────────────┼─────────────┼────────────────────┐   ┌────────────────┼──────┼────────┼─────────────┼────────┼───────────┼─────┤
//    │ lalt │   z    │   x    │   c    │      v      │      b      │         [          │   │       ]        │  n   │   m    │      ,      │   .    │     /     │ del │
//    └──────┴────────┴────────┼────────┼─────────────┼─────────────┼────────────────────┤   ├────────────────┼──────┼────────┼─────────────┼────────┴───────────┴─────┘
//                             │        │ OSL(_LOWER) │ OSL(_RAISE) │ LT(_MOVEMENT, spc) │   │ TD(TD_ENT_ESC) │ bspc │        │ OSL(_EXTRA) │
//                             └────────┴─────────────┴─────────────┴────────────────────┘   └────────────────┴──────┴────────┴─────────────┘
[_QWERTY] = LAYOUT(
  KC_ESC  , KC_1   , KC_2   , KC_3    , KC_4        , KC_5        ,                                                KC_6    , KC_7    , KC_8        , KC_9   , KC_0      , KC_GRV   ,
  KC_TAB  , KC_Q   , KC_W   , KC_E    , KC_R        , KC_T        ,                                                KC_Y    , KC_U    , KC_I        , KC_O   , KC_P      , KC_MINS  ,
  KC_LCTL , HOME_A , HOME_S , HOME_D  , HOME_F      , KC_G        ,                                                KC_H    , HOME_J  , HOME_K      , HOME_L , HOME_SCLN , KC_QUOT  ,
  KC_LALT , KC_Z   , KC_X   , KC_C    , KC_V        , KC_B        , KC_LBRC                 ,     KC_RBRC        , KC_N    , KC_M    , KC_COMM     , KC_DOT , KC_SLSH   , KC_DELETE,
                              _______ , OSL(_LOWER) , OSL(_RAISE) , LT(_MOVEMENT, KC_SPACE) ,     TD(TD_ENT_ESC) , KC_BSPC , _______ , OSL(_EXTRA)
),

//    ┌─────┬─────┬─────────┬────────┬─────┬─────┐               ┌─────────┬────────┬─────┬─────┬─────┬─────┐
//    │     │     │         │        │     │     │               │         │        │     │     │     │     │
//    ├─────┼─────┼─────────┼────────┼─────┼─────┤               ├─────────┼────────┼─────┼─────┼─────┼─────┤
//    │ f1  │ f2  │   f3    │   f4   │ f5  │ f6  │               │   f7    │   f8   │ f9  │ f10 │ f11 │ f12 │
//    ├─────┼─────┼─────────┼────────┼─────┼─────┤               ├─────────┼────────┼─────┼─────┼─────┼─────┤
//    │  `  │  !  │ UK_DQUO │ UK_PND │  $  │  %  │               │    ^    │   &    │  *  │  (  │  )  │  ~  │
//    ├─────┼─────┼─────────┼────────┼─────┼─────┼─────┐   ┌─────┼─────────┼────────┼─────┼─────┼─────┼─────┤
//    │     │     │         │        │     │  \  │     │   │     │ UK_PIPE │ UK_EQL │  +  │  {  │  }  │  _  │
//    └─────┴─────┴─────────┼────────┼─────┼─────┼─────┤   ├─────┼─────────┼────────┼─────┼─────┴─────┴─────┘
//                          │        │     │     │     │   │     │         │        │     │
//                          └────────┴─────┴─────┴─────┘   └─────┴─────────┴────────┴─────┘
[_RAISE] = LAYOUT(
  _______ , _______ , _______ , _______ , _______ , _______ ,                         _______ , _______ , _______ , _______ , _______ , _______,
  KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   ,                         KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12 ,
  KC_GRV  , KC_EXLM , UK_DQUO , UK_PND  , KC_DLR  , KC_PERC ,                         KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_TILD,
  _______ , _______ , _______ , _______ , _______ , KC_BSLS , _______ ,     _______ , UK_PIPE , UK_EQL  , KC_PLUS , KC_LCBR , KC_RCBR , KC_UNDS,
                                _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┐               ┌─────┬──────┬──────┬─────┬──────┬─────┐
//    │     │     │     │     │     │     │               │     │      │      │     │      │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼──────┼──────┼─────┼──────┼─────┤
//    │  `  │  1  │  2  │  3  │  4  │  5  │               │  6  │  7   │  8   │  9  │  0   │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼──────┼──────┼─────┼──────┼─────┤
//    │ f1  │ f2  │ f3  │ f4  │ f5  │ f6  │               │ no  │ left │ down │ up  │ rght │ no  │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┐   ┌─────┼─────┼──────┼──────┼─────┼──────┼─────┤
//    │ f7  │ f8  │ f9  │ f10 │ f11 │ f12 │     │   │     │  +  │  -   │  =   │  [  │  ]   │  \  │
//    └─────┴─────┴─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼──────┼──────┼─────┴──────┴─────┘
//                      │     │     │     │     │   │     │     │      │      │
//                      └─────┴─────┴─────┴─────┘   └─────┴─────┴──────┴──────┘
[_LOWER] = LAYOUT(
  _______ , _______ , _______ , _______ , _______ , _______ ,                         _______ , _______ , _______ , _______ , _______ , _______,
  KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,                         KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , _______,
  KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   ,                         XXXXXXX , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , XXXXXXX,
  KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , _______ ,     _______ , KC_PLUS , KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , KC_BSLS,
                                _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______
),

//    ┌────┬────┬────┬─────┬─────┬─────┐               ┌──────┬──────┬──────┬──────┬─────┬─────┐
//    │ no │ no │ no │ no  │ no  │ no  │               │  f1  │  f2  │  f3  │  f4  │ f5  │ f6  │
//    ├────┼────┼────┼─────┼─────┼─────┤               ├──────┼──────┼──────┼──────┼─────┼─────┤
//    │ no │ no │ no │ no  │ no  │ no  │               │  f7  │  f8  │  f9  │ f10  │ f11 │ f12 │
//    ├────┼────┼────┼─────┼─────┼─────┤               ├──────┼──────┼──────┼──────┼─────┼─────┤
//    │ no │ no │ no │ no  │ no  │ no  │               │ left │ down │  up  │ rght │ no  │ no  │
//    ├────┼────┼────┼─────┼─────┼─────┼─────┐   ┌─────┼──────┼──────┼──────┼──────┼─────┼─────┤
//    │ no │ no │ no │ no  │ no  │ no  │ no  │   │ no  │ home │ pgdn │ pgup │ end  │ no  │ no  │
//    └────┴────┴────┼─────┼─────┼─────┼─────┤   ├─────┼──────┼──────┼──────┼──────┴─────┴─────┘
//                   │     │     │     │     │   │     │      │      │      │
//                   └─────┴─────┴─────┴─────┘   └─────┴──────┴──────┴──────┘
[_MOVEMENT] = LAYOUT(
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                         KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6  ,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                         KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12 ,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                         KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , KC_HOME , KC_PGDN , KC_PGUP , KC_END  , XXXXXXX , XXXXXXX,
                                _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______
),

//    ┌────┬────┬────┬─────┬─────┬─────┐               ┌─────┬─────┬─────┬────┬────┬────┐
//    │ no │ no │ no │ no  │ no  │ no  │               │ no  │ no  │ no  │ no │ no │ no │
//    ├────┼────┼────┼─────┼─────┼─────┤               ├─────┼─────┼─────┼────┼────┼────┤
//    │ no │ no │ no │ no  │ no  │ no  │               │ no  │ no  │ no  │ no │ no │ no │
//    ├────┼────┼────┼─────┼─────┼─────┤               ├─────┼─────┼─────┼────┼────┼────┤
//    │ no │ no │ no │ no  │ no  │ no  │               │ no  │ no  │ no  │ no │ no │ no │
//    ├────┼────┼────┼─────┼─────┼─────┼─────┐   ┌─────┼─────┼─────┼─────┼────┼────┼────┤
//    │ no │ no │ no │ no  │ no  │ no  │ no  │   │ no  │ no  │ no  │ no  │ no │ no │ no │
//    └────┴────┴────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼────┴────┴────┘
//                   │     │     │     │     │   │     │     │     │     │
//                   └─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┘
[_EXTRA] = LAYOUT(
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
                                _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______
)
};

//layer_state_t layer_state_set_user(layer_state_t state) {
//  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
//}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_0;
    }
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void render_default_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("QRTY"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("LOW"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("HIGH"), false);
            break;
        case _MOVEMENT:
            oled_write_ln_P(PSTR("MOVE"), false);
            break;
        case _EXTRA:
            oled_write_ln_P(PSTR("EXTRA"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    //oled_write_ln(read_layer_state(), false);
    render_default_layer_state();
    //oled_write_ln(read_keylog(), false);
    //oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}


#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
