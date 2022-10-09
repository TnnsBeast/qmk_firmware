#include QMK_KEYBOARD_H
#include "keymap_japanese.h"


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _QWERTY = 0,
  _MOUSE,
  _BROWSER,
  _FLOCK,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  RGB_RST = SAFE_RANGE,
  SEND_SUM,
  SEND_AVE,
  SEND_CIF,
  SEND_MAX,
  SEND_MIN
};

enum tapdances{
  TD_ESFL = 0,
  TD_ESQW,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_ESFL] = ACTION_TAP_DANCE_LAYER_MOVE(KC_ESC, _FLOCK),
  [TD_ESQW] = ACTION_TAP_DANCE_LAYER_MOVE(KC_ESC, _QWERTY),
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define LWR_ENT LT(_LOWER,KC_ENT)
#define RSE_SPC LT(_RAISE,KC_SPC)
#define LWR_P0 LT(_LOWER, KC_P0)
#define RSE_DOT LT(_RAISE, KC_PDOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_with_setta21(
    //,--------------------------------------------------------------|             |--------------------------------------------------------------.             ,-----------------------------------.
     TG(_MOUSE),TD(TD_ESFL), KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                  KC_6,    KC_7,    KC_8,    KC_9,    KC_0, JP_MINS, KC_BSPC,              KC_ESC,   KC_F2,   KC_EQL,  KC_DEL,
    //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------|
   TG(_BROWSER),  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, JP_LBRC, JP_RBRC,              KC_NLCK,  KC_PSLS, KC_PAST, KC_PMNS,
    //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------|
                KC_LCTRL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                  KC_H,    KC_J,    KC_K,    KC_L, JP_MINS, JP_BSLS,  KC_ENT,              KC_P7,    KC_P8,   KC_P9,
    //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------|        |
                 KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                  KC_N,    KC_M, JP_COMM,  JP_DOT, JP_SLSH,   KC_UP, KC_RSFT,              KC_P4,    KC_P5,   KC_P6,   KC_PPLS,
    //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------|
                 JP_ZKHK,  LGUI_T(JP_MHEN), LWR_ENT, KC_BSPC,                         KC_DEL ,RSE_SPC,   ALT_T(JP_HENK), KC_LEFT, KC_DOWN, KC_RGHT,              KC_P1,    KC_P2,   KC_P3,
              //`---------------------------------------------------------------------------------------------------------------------------------'             |-----------------+--------|        |
                                                                                                                                                                 LWR_P0,            RSE_DOT, KC_PENT
              //                                                                                                                                                `-----------------------------------'
    ),

    [_MOUSE] = LAYOUT_with_setta21(
    //,--------------------------------------------------------------|             |--------------------------------------------------------------.             ,-----------------------------------.
     TG(_MOUSE), _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------|
        XXXXXXX, _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------|
                 _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______,               _______, _______, _______,
    //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------|        |
                 _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2,               _______, _______, _______, _______,
    //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------|
                 _______,          _______,          _______, _______,               _______, _______,          _______, KC_MS_L, KC_MS_D, KC_MS_R,               _______, _______, _______,
            //`-----------------------------------------------------------------------------------------------------------------------------------'             |-----------------+--------|        |
                                                                                                                                                                  _______,          _______, _______
            //                                                                                                                                                  `-----------------------------------'
    ),

    [_BROWSER] = LAYOUT_with_setta21(
    //,--------------------------------------------------------------|             |---------------------------------------------------------------------.             ,-----------------------------------.
        XXXXXXX, _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______,      _______, _______,                 _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+-------------+----------|             |--------+--------+--------+--------|
   TG(_BROWSER), _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______,      _______, KC_PGUP,                 _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+-------------+----------|             |--------+--------+--------+--------|
                 _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______,      _______, KC_PGDN,                 _______, _______, _______,
    //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+-------------+--------+----------|             |--------+--------+--------|        |
                 _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, C(S(KC_T)),   KC_UP  , C(KC_W),                 _______, _______, _______, _______,
    //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+----------|                  |--------+--------+--------+--------|
                 _______,          _______,          _______, _______,               _______, _______,          _______, C(S(KC_TAB)), KC_DOWN, C(KC_TAB),               _______, _______, _______,
            //`-----------------------------------------------------------------------------------------------------------------------------------'                    |-----------------+--------|        |
                                                                                                                                                                         _______,          _______, _______
            //                                                                                                                                                         `-----------------------------------'
    ),

    [_FLOCK] = LAYOUT_with_setta21(
    //,--------------------------------------------------------------|             |--------------------------------------------------------------.             ,-----------------------------------.
        _______,TD(TD_ESQW),KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                 KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,               _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------|
                 _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______,               _______, _______, _______,
    //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------|        |
                 _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______,
    //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------|
                 _______,          _______,          _______, _______,               _______, _______,          _______, _______, _______, _______,               _______, _______, _______,
            //`-----------------------------------------------------------------------------------------------------------------------------------'             |-----------------+--------|        |
                                                                                                                                                                  _______,          _______, _______
            //                                                                                                                                                  `-----------------------------------'
    ),

    [_LOWER] = LAYOUT_with_setta21(
    //,--------------------------------------------------------------|             |--------------------------------------------------------------.             ,-----------------------------------.
        _______,  KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                 KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,               KC_ESC,  KC_F2,   KC_EQL,  KC_DEL,
    //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------|
        _______, JP_QUOT, JP_EXLM, JP_QUES, JP_LBRC, JP_RBRC, JP_TILD,                 KC_P6,   KC_P7,   KC_P8,   KC_P9, JP_ASTR, JP_SLSH, XXXXXXX,               XXXXXXX, KC_PSLS, KC_PAST, KC_PMNS,
    //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------|
                 JP_QUOT, JP_HASH, JP_DQUO, JP_LPRN, JP_RPRN,   JP_AT,               XXXXXXX,   KC_P4,   KC_P5,   KC_P6, JP_MINS,  JP_EQL,  KC_ENT,               XXXXXXX, KC_UP,   XXXXXXX,
    //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------|        |
                 JP_CIRC, JP_PERC, JP_AMPR, JP_SCLN, JP_COLN, JP_PIPE,                 KC_P0,   KC_P1,   KC_P2,   KC_P3, JP_PLUS,   KC_UP, KC_RSFT,               KC_LEFT, KC_DOWN, KC_RGHT, KC_PPLS,
    //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------|
                 JP_ZKHK,          _______,            LOWER, _______,               _______,   RAISE,           JP_DOT, KC_LEFT, KC_DOWN, KC_RGHT,               XXXXXXX, KC_DOWN, XXXXXXX,
            //`-----------------------------------------------------------------------------------------------------------------------------------'             |-----------------+--------|        |
                                                                                                                                                                    LOWER,            RAISE, KC_PENT
            //                                                                                                                                                  `-----------------------------------'
    ),

    [_RAISE] = LAYOUT_with_setta21(
    //,--------------------------------------------------------------|             |--------------------------------------------------------------.             ,---------------------------------------.
        _______,  KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                 KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,                 KC_ESC,    KC_F2,   KC_EQL,   KC_DEL,
    //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|             |---------+---------+---------+---------|
        _______,  KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,               XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, KC_PGUP, XXXXXXX, XXXXXXX,               SEND_MIN, SEND_MAX, SEND_CIF, SEND_AVE,
    //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|             |---------+---------+---------+---------|
          LCTL_T(KC_F11), XXXXXXX,   KC_F2,   KC_F3,   KC_F4,   KC_F5,               XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX, XXXXXXX, _______,                  KC_F7,    KC_F8,    KC_F9,
    //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|             |---------+---------+---------|         |
           SFT_T(KC_F12),   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, _______, _______,                  KC_F4,    KC_F5,    KC_F6, SEND_SUM,
    //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------+--------|             |---------+---------+---------+---------|
                 _______,          _______,          _______, _______,               _______,          _______, _______, _______, _______, _______,                 KC_F11,   KC_F12,    KC_F3,
            //`-----------------------------------------------------------------------------------------------------------------------------------'             |-------------------+---------|         |
                                                                                                                                                                   _______,            _______,  KC_RPRN
            //                                                                                                                                                  `---------------------------------------'
    ),


    [_ADJUST] = LAYOUT_with_setta21( /* Base */
    //,--------------------------------------------------------------|             |------------------------------------------------------------------------.             ,-----------------------------------.
        _______,   QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                 KC_F6,   KC_F7,   KC_F8,       KC_F9,        KC_F10,  KC_F11,  KC_F12,               _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+------------+--------------+--------+--------|             |--------+--------+--------+--------|
        _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               RGB_RST, XXXXXXX, XXXXXXX,     XXXXXXX,       XXXXXXX, XXXXXXX, _______,               XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------+--------|             |--------+--------+--------+------------+--------------+--------+--------|             |--------+--------+--------+--------|
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               RGB_TOG, RGB_MOD, XXXXXXX, LCA(KC_DEL), LALT(KC_PSCR), KC_PSCR, XXXXXXX,               RGB_SAD, RGB_SAI, XXXXXXX,
    //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+------------+--------------+--------+--------|             |--------+--------+--------+--------|
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               RGB_VAD, RGB_VAI, RGB_HUD,     RGB_HUI,       RGB_SAD, RGB_SAI, XXXXXXX,               RGB_HUD, RGB_HUI, XXXXXXX, RGB_TOG,
    //         |--------+--------+--------+--------+--------+--------|             |--------+--------+--------+------------+--------------+--------+--------|             |--------+--------+--------+--------|
                 _______,          _______,          _______, _______,               _______,          _______,     _______,       _______, _______, _______,               RGB_VAD, RGB_VAI, XXXXXXX,
            //`---------------------------------------------------------------------------------------------------------------------------------------------'             |-----------------+--------+--------|
                                                                                                                                                                            _______,          _______, RGB_MOD
            //                                                                                                                                                            `-----------------------------------'
    )
};

//A description for expressing the layer position in LED mode.
layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
#ifdef RGBLIGHT_ENABLE
    switch (get_highest_layer(state)) {
    case _MOUSE:
      rgblight_sethsv_at(HSV_RED, 0);
      break;
    case _BROWSER:
      rgblight_sethsv_at(HSV_RED, 1);
      break;
    case _FLOCK:
      rgblight_sethsv_range(HSV_YELLOW, 0, 2);
      break;
    case _LOWER:
      rgblight_sethsv_range(HSV_BLUE, 0, 2);
      break;
    case _RAISE:
      rgblight_sethsv_range(HSV_RED, 0, 2);
      break;
    case _ADJUST:
      rgblight_sethsv_range(HSV_PURPLE, 0, 2);
      break;
    default: //  for any other layers, or the default layer
      rgblight_sethsv_range( 0, 0, 0, 0, 2);
      break;
    }
    rgblight_set_effect_range( 2, 6);
#endif
return state;
}

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  bool result = false;
  switch (keycode) {
    case SEND_SUM:
      if (record->event.pressed) {
        SEND_STRING("=SUM(");
      }
      break;
    case SEND_AVE:
      if (record->event.pressed) {
        SEND_STRING("=AVERAGE(");
      }
      break;
    case SEND_CIF:
      if (record->event.pressed) {
        SEND_STRING("=COUNTIF(");
      }
      break;
    case SEND_MAX:
      if (record->event.pressed) {
        SEND_STRING("=MAX(");
      }
      break;
    case SEND_MIN:
      if (record->event.pressed) {
        SEND_STRING("=MIN(");
      }
      break;
    #ifdef RGBLIGHT_ENABLE
      case RGB_MOD:
          if (record->event.pressed) {
            rgblight_mode(RGB_current_mode);
            rgblight_step();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
      case RGB_RST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
    #endif
    default:
      result = true;
      break;
  }

  return result;
}

void matrix_init_user(void) {

}
