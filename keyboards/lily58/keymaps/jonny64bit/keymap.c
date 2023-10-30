#include QMK_KEYBOARD_H
#include "keymap_uk.h"

enum layer_number {
  _QWERTY = 0,
  _SYMBOLS,
  _MOVEMENT,
  _RAISE,
  _LOWER
};

// Tap Dance declarations
enum {
    TD_J_ESC,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for J, twice for Escape
    [TD_J_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_J, KC_ESC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────────────────────┬───┬───┬─────────────┬─────────────┬───────────────┐                              ┌──────┬──────────────┬─────────┬───┬───┬───────────────┐
//    │        pscr         │ 1 │ 2 │      3      │      4      │       5       │                              │  6   │      7       │    8    │ 9 │ 0 │       `       │
//    ├─────────────────────┼───┼───┼─────────────┼─────────────┼───────────────┤                              ├──────┼──────────────┼─────────┼───┼───┼───────────────┤
//    │ QK_CAPS_WORD_TOGGLE │ q │ w │      e      │      r      │       t       │                              │  y   │      u       │    i    │ o │ p │       -       │
//    ├─────────────────────┼───┼───┼─────────────┼─────────────┼───────────────┤                              ├──────┼──────────────┼─────────┼───┼───┼───────────────┤
//    │        lsft         │ a │ s │      d      │      f      │       g       │                              │  h   │ TD(TD_J_ESC) │    k    │ l │ ; │       '       │
//    ├─────────────────────┼───┼───┼─────────────┼─────────────┼───────────────┼────────────────────┐   ┌─────┼──────┼──────────────┼─────────┼───┼───┼───────────────┤
//    │        lctl         │ z │ x │      c      │      v      │       b       │         [          │   │  ]  │  n   │      m       │    ,    │ . │ / │ QK_REPEAT_KEY │
//    └─────────────────────┴───┴───┼─────────────┼─────────────┼───────────────┼────────────────────┤   ├─────┼──────┼──────────────┼─────────┼───┴───┴───────────────┘
//                                  │ OSL(_LOWER) │ OSL(_RAISE) │ OSL(_SYMBOLS) │ LT(_MOVEMENT, spc) │   │ ent │ bspc │     del      │ LGUI(.) │
//                                  └─────────────┴─────────────┴───────────────┴────────────────────┘   └─────┴──────┴──────────────┴─────────┘
[_QWERTY] = LAYOUT(
  KC_PSCR             , KC_1 , KC_2 , KC_3        , KC_4        , KC_5          ,                                         KC_6    , KC_7         , KC_8         , KC_9   , KC_0    , KC_GRV       ,
  QK_CAPS_WORD_TOGGLE , KC_Q , KC_W , KC_E        , KC_R        , KC_T          ,                                         KC_Y    , KC_U         , KC_I         , KC_O   , KC_P    , KC_MINS      ,
  KC_LSFT             , KC_A , KC_S , KC_D        , KC_F        , KC_G          ,                                         KC_H    , TD(TD_J_ESC) , KC_K         , KC_L   , KC_SCLN , KC_QUOT      ,
  KC_LCTL             , KC_Z , KC_X , KC_C        , KC_V        , KC_B          , KC_LBRC                 ,     KC_RBRC , KC_N    , KC_M         , KC_COMM      , KC_DOT , KC_SLSH , QK_REPEAT_KEY,
                                      OSL(_LOWER) , OSL(_RAISE) , OSL(_SYMBOLS) , LT(_MOVEMENT, KC_SPACE) ,     KC_ENT  , KC_BSPC , KC_DELETE    , LGUI(KC_DOT)
),

//    ┌────────┬─────────┬─────────┬───────┬─────┬─────────┐               ┌──────────┬───────────────┬───────────────┬───────────────┬───────────────┬─────┐
//    │        │         │         │       │     │         │               │          │               │               │               │               │     │
//    ├────────┼─────────┼─────────┼───────┼─────┼─────────┤               ├──────────┼───────────────┼───────────────┼───────────────┼───────────────┼─────┤
//    │ UK_PND │ UK_LABK │    [    │   {   │  (  │ UK_TILD │               │    ^     │       )       │       }       │       ]       │    UK_RABK    │  `  │
//    ├────────┼─────────┼─────────┼───────┼─────┼─────────┤               ├──────────┼───────────────┼───────────────┼───────────────┼───────────────┼─────┤
//    │        │    -    │    *    │   =   │  _  │    $    │               │ UK_HASH  │ OSM(MOD_LSFT) │ OSM(MOD_LCTL) │ OSM(MOD_LALT) │ OSM(MOD_LGUI) │     │
//    ├────────┼─────────┼─────────┼───────┼─────┼─────────┼─────┐   ┌─────┼──────────┼───────────────┼───────────────┼───────────────┼───────────────┼─────┤
//    │        │ UK_PLUS │ UK_PIPE │ UK_AT │  /  │    %    │     │   │     │ left_GUI │    UK_BSLS    │       &       │       ?       │       !       │     │
//    └────────┴─────────┴─────────┼───────┼─────┼─────────┼─────┤   ├─────┼──────────┼───────────────┼───────────────┼───────────────┴───────────────┴─────┘
//                                 │       │     │         │     │   │     │          │               │               │
//                                 └───────┴─────┴─────────┴─────┘   └─────┴──────────┴───────────────┴───────────────┘
[_SYMBOLS] = LAYOUT(
  _______ , _______ , _______ , _______ , _______ , _______ ,                         _______     , _______       , _______       , _______       , _______       , _______,
  UK_PND  , UK_LABK , KC_LBRC , KC_LCBR , KC_LPRN , UK_TILD ,                         KC_CIRC     , KC_RPRN       , KC_RCBR       , KC_RBRC       , UK_RABK       , KC_GRV ,
  _______ , KC_MINS , KC_ASTR , KC_EQL  , KC_UNDS , KC_DLR  ,                         UK_HASH     , OSM(MOD_LSFT) , OSM(MOD_LCTL) , OSM(MOD_LALT) , OSM(MOD_LGUI) , _______,
  _______ , UK_PLUS , UK_PIPE , UK_AT   , KC_SLSH , KC_PERC , _______ ,     _______ , KC_LEFT_GUI , UK_BSLS       , KC_AMPR       , KC_QUES       , KC_EXLM       , _______,
                                _______ , _______ , _______ , _______ ,     _______ , _______     , _______       , _______
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
        case _SYMBOLS:
            oled_write_ln_P(PSTR("SYMBO"), false);
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
