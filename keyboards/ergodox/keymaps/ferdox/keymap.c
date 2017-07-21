#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"


#include "keymap_spanish.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Basic layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |  Esc   |   1  |   2  |   3  |   4  |   5  | Ins  |           | Supr |   6  |   7  |   8  |   9  |   0  |   '    |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |   =    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   Ç    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |CapsLock|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |Ñ / L2|´ / Cmd |
   * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
   * | LShift |  Z   |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |  Up  |   ,  |   .  | RShift |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   | ~L1  | Ctrl |AltShf|CtrlSh| AltGr|                                       | Left | Down | Right|   -  | ~L1  |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        | Alt  | LGui |       |Win+L |Ctrl/Esc|
   *                                 ,------|------|------|       |------+--------+------.
   *                                 |      |      | Home |       | PgUp |        |      |
   *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
   *                                 |      |ace   | End  |       | PgDn |        |      |
   *                                 `--------------------'       `----------------------'
   */
  [BASE] = KEYMAP(
    KC_ESCAPE,  KC_1,   KC_2,     KC_3,           KC_4,             KC_5,          KC_TRNS,
    KC_EQUAL,   KC_Q,   KC_W,     KC_E,           KC_R,             KC_T,          TG(1),
    KC_CAPSLOCK,   KC_A,   KC_S,     KC_D,           KC_F,             KC_G,
    KC_LSHIFT,  KC_Z,   KC_X,     KC_C,           KC_V,             KC_B,          ALL_T(KC_NO),
                MO(1),  KC_LCTL,  LALT(KC_LSHIFT),  LSFT(KC_LCTL),  ALGR_T(KC_NO),

                                                                        ALT_T(KC_NO), KC_LGUI,
                                                                                      KC_HOME,
                                                                KC_SPACE,  KC_BSPACE,  KC_END,


  KC_DELETE,        KC_6,    KC_7,     KC_8,     KC_9,     KC_0,             ES_APOS,
  TG(1),          KC_Y,    KC_U,     KC_I,     KC_O,     KC_P,             ES_CCED,
                  KC_H,    KC_J,     KC_K,     KC_L,     LT(2, KC_SCOLON), GUI_T(KC_QUOTE),
  MEH_T(KC_NO),   KC_N,    KC_M,     KC_UP,    KC_COMMA, KC_DOT,           KC_RSHIFT,
                           KC_LEFT,  KC_DOWN,  KC_RIGHT, CTL_T(ES_MINS),   MO(1),

  GUI_T(KC_L),  CTL_T(KC_ESCAPE),
  KC_PGUP,
  KC_PGDOWN,  KC_TAB, KC_ENTER
),

/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   /  |   @  |   {  |   }  |   "  |      |           |      |   7  |   8  |   9  |   \  |      |   F12  |
 * |---------+------+------+------+------+------|  !   |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   '  |------|           |------|   4  |   5  |   6  |   *  |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   `  |  =   |           |      |   1  |   2  |   3  |   +  |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |   &  |   |  |  <   |   >  |                                       |   0  |   =  |   -  |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,   KC_F1,   KC_F2,  KC_F3,     KC_F4,   KC_F5,  KC_TRNS,
       KC_TRNS, ES_SLSH,   ES_AT,  ES_LCBR, ES_RCBR, ES_QUOT,  KC_EXLM,
       KC_TRNS, ES_HASH,  KC_DLR,  ES_LPRN, ES_RPRN, ES_APOS,
       KC_TRNS, KC_PERC, ES_CIRC,  ES_LBRC, ES_RBRC,  ES_GRV,  ES_EQL,
          EPRM, ES_AMPR, ES_PIPE,  ES_LESS, ES_GRTR,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,  KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_7,    KC_8,    KC_9,    ES_ASTR, KC_TRNS, KC_F12,
                KC_4,    KC_5,    KC_6,    ES_BSLS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_1,    KC_2,    KC_3,    ES_PLUS, KC_TRNS, KC_TRNS,
                         KC_0,    ES_EQL,  ES_MINS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  EPRM  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
          EPRM, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_MUTE,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_VOLU,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV,
                 KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS, KC_MPLY,
       KC_VOLD,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
 ),
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;

  }
  return true;
}

void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

};
