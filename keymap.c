#include QMK_KEYBOARD_H
#include <stdio.h>
#include "russian.h"

enum {
  TD_DVORAK,
  TD_DIKTOR,
  TD_QWERTY 
};

enum {
  _DVORAK,
  _DIKTOR,
  _QWERTY,
  _MEDIA,
  _NAV,
  _MOUSE,
  _SYM,
  _NUM,
  _FUN
} ;

void dvorak_tap_dance(tap_dance_state_t *state, void *user_data)
{
    if(state->count == 2) 
    {   
        register_code(KC_LCTL);
        register_code(KC_LSFT);
        default_layer_set((layer_state_t)1 <<_DVORAK);
        unregister_code(KC_LCTL);
        unregister_code(KC_LSFT);
    }
}

void diktor_tap_dance(tap_dance_state_t *state, void *user_data)
{
    if(state->count == 2) 
    {   
        register_code(KC_LCTL);
        register_code(KC_LSFT);
        default_layer_set((layer_state_t)1 <<_DIKTOR);
        unregister_code(KC_LCTL);
        unregister_code(KC_LSFT);
    }
}

void qwerty_tap_dance(tap_dance_state_t *state, void *user_data)
{
    if(state->count == 2) 
    {   
        register_code(KC_LCTL);
        register_code(KC_LSFT);
        default_layer_set((layer_state_t)1 <<_QWERTY);
        unregister_code(KC_LCTL);
        unregister_code(KC_LSFT);
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_DVORAK] = ACTION_TAP_DANCE_FN(dvorak_tap_dance),
    [TD_DIKTOR] = ACTION_TAP_DANCE_FN(diktor_tap_dance),
    [TD_QWERTY] = ACTION_TAP_DANCE_FN(qwerty_tap_dance)
};


#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

#define U_RDO C(KC_Y)
#define U_PST C(KC_V)
#define U_CPY C(KC_C)
#define U_CUT C(KC_X)
#define U_UND C(KC_Z)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DVORAK] = LAYOUT_split_3x6_3(
            KC_EQL,   KC_QUOT,        KC_COMM,        KC_DOT,         KC_P,           KC_Y,   KC_F,   KC_G,         KC_C,          KC_R,            KC_L, KC_SLSH,
            KC_GRV,   LGUI_T(KC_A),   LALT_T(KC_O),   LCTL_T(KC_E),   LSFT_T(KC_U),   KC_I,   KC_D,   LSFT_T(KC_H), LCTL_T(KC_T),  LALT_T(KC_N),    LGUI_T(KC_S), KC_MINS,
            KC_BSLS,   KC_SCLN,        ALGR_T(KC_Q),   KC_J,           KC_K,           KC_X,   KC_B,   KC_M,         KC_W,          ALGR_T(KC_V),    KC_Z, KC_LBRC,
             LT(_MEDIA,KC_ESC),LT(_NAV,KC_SPC),LT(_MOUSE,KC_TAB),LT(_SYM,KC_ENT),LT(_NUM,KC_BSPC),LT(_FUN,KC_DEL)
    ),  
    [_DIKTOR] = LAYOUT_split_3x6_3(
          RU_SHCHA, RU_TSE, RU_SSIGN, RU_YA, RU_COMM, RU_DOT,           RU_ZE, RU_VE, RU_KA, RU_DE, RU_CHE, RU_SHA, 
          RU_IO,    LGUI_T(RU_U),   LALT_T(RU_I),     LCTL_T(RU_IE), LSFT_T(RU_O),    RU_A,             RU_EL, LSFT_T(RU_EN), LCTL_T(RU_TE), LALT(RU_ES), LGUI_T(RU_ER),  RU_SRT_I, 
          KC_BSLS,  RU_EF,  RU_E,     ALGR_T(RU_HA), RU_YERU, RU_YU,            RU_BE, RU_EM, RU_PE, ALGR_T(RU_GHE), RU_ZHE, RU_RUBL, 
          LT(_MEDIA,KC_ESC),LT(_NAV,KC_SPC),LT(_MOUSE,KC_TAB),LT(_SYM,KC_ENT),LT(_NUM,KC_BSPC),LT(_FUN,KC_DEL)

    ),
    [_QWERTY] = LAYOUT_split_3x6_3(
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    LGUI_T(KC_A),    LALT_T(KC_S),    LCTL_T(KC_D),    LSFT_T(KC_F),    KC_G,                         KC_H,    LSFT_T(KC_J),    LCTL_T(KC_K),    LALT_T(KC_L), LGUI_T(KC_SCLN), KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    ALGR_T(KC_X),    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  ALGR_T(KC_DOT), KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          LT(_MEDIA,KC_ESC),  LT(_NAV,KC_SPC),  LT(_MOUSE,KC_TAB),LT(_SYM,KC_ENT),LT(_NUM,KC_BSPC),LT(_FUN,KC_DEL) 
                                      //`--------------------------'  `--------------------------'        
    ),
    [_MEDIA] = LAYOUT_split_3x6_3(
        U_NA,   U_NA,   TD(TD_QWERTY),   TD(TD_DVORAK), TD(TD_DIKTOR), U_NA,     U_NA,   U_NA,   U_NA,  U_NA,    U_NA,   U_NA,
        U_NA,   KC_LGUI,    KC_LALT,  KC_LCTL,  KC_LSFT,      U_NA,     U_NU, KC_MPRV, KC_VOLD, KC_VOLU,KC_MNXT,U_NA,
        U_NA,   KC_ALGR,    U_NA,   U_NA,       U_NA,        U_NA,      U_NA,  U_NA,    U_NA,   U_NA,   U_NA,   U_NA,
        U_NA,U_NA,U_NA, KC_MSTP,KC_MPLY, KC_MUTE
    ),
    [_NAV] = LAYOUT_split_3x6_3(
        U_NA,   U_NA,   TD(TD_QWERTY),   TD(TD_DVORAK), TD(TD_DIKTOR), U_NA,     U_RDO,U_PST,U_CPY,U_CUT,U_UND,U_NA,
        U_NA, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,U_NA,                  CW_TOGG,KC_LEFT, KC_DOWN, KC_UP,KC_RIGHT,U_NA,
        U_NA,   KC_ALGR, U_NA, U_NA, U_NA, U_NA,                    KC_INS,  KC_HOME,KC_PGDN,KC_PGUP,KC_END,U_NA,
        U_NA,U_NA,U_NA,                              KC_ENT,KC_BSPC, KC_DEL       
    ),
    [_MOUSE] = LAYOUT_split_3x6_3(
        U_NA,   U_NA,   TD(TD_QWERTY),   TD(TD_DVORAK), TD(TD_DIKTOR), U_NA,     U_RDO,  U_PST,  U_CPY,  U_CUT,  U_UND,  U_NA,
        U_NA,   KC_LGUI, KC_LALT, KC_LCTL,      KC_LSFT,     U_NA,      U_NU,   KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R,    U_NU,
        U_NA,   KC_ALGR, U_NA,      U_NA,       U_NA,       U_NA,        U_NU,  KC_WH_L,  KC_WH_D,      KC_WH_U,    KC_WH_R,    KC_END, 
        U_NA,   U_NA,   U_NA, KC_BTN2, KC_BTN1, KC_BTN3 
    ),
    [_SYM] = LAYOUT_split_3x6_3(
    U_NU,  KC_LCBR,     KC_AMPR,    KC_ASTR,     KC_LPRN,     KC_RCBR,     U_NA,        TD(TD_DVORAK),   TD(TD_DIKTOR),  TD(TD_QWERTY),     U_NU,     U_NU,     
    U_NU,  KC_COLN,     KC_DLR,     KC_PERC,     KC_CIRC,     KC_PLUS,     U_NA,        KC_LSFT,         KC_LCTL,        KC_LALT,  KC_LGUI,  U_NU,         
    U_NU,  KC_TILD,     KC_EXLM,    KC_AT,       KC_HASH,     KC_PIPE,     U_NA,        U_NU,            U_NA,           KC_ALGR,  U_NA,     U_NU,         
    KC_LPRN,     KC_RPRN,     KC_UNDS,     U_NA,        U_NA,            U_NA               
    ),
    [_NUM] = LAYOUT_split_3x6_3(
        U_NU,   KC_LBRC,     KC_7,    KC_8,      KC_9,    KC_RBRC,          U_NA,      TD(TD_DVORAK),   TD(TD_DIKTOR),      TD(TD_QWERTY),     U_NU,      U_NU,     
        U_NU,   KC_SCLN,     KC_4,    KC_5,      KC_6,    KC_EQL,           U_NA,      KC_LSFT,           KC_LCTL,          KC_LALT,  KC_LGUI,   U_NU,
        U_NU,   KC_GRV,      KC_1,    KC_2,      KC_3,    KC_BSLS,          U_NA,      U_NU,              U_NU,             KC_ALGR,  U_NA,      U_NU,
        KC_DOT,    KC_0,    KC_MINS,          U_NA,      U_NA,              U_NA                   
    ),
    [_FUN] = LAYOUT_split_3x6_3(
        U_NP, KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,           U_NA,      TD(TD_DIKTOR),   TD(TD_DVORAK),  TD(TD_QWERTY),    U_NU, U_NU,    
        U_NP, KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SCRL,           U_NA,      KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,U_NU,           
        U_NP, KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,           U_NA,      U_NA,    U_NA,  KC_ALGR,           U_NA, U_NA,             
        KC_APP,            KC_SPC,            KC_TAB,            U_NA,      U_NA,              U_NA
    ),

};

const key_override_t comm_dikt_override = ko_make_with_layers(MOD_MASK_SHIFT, RU_COMM,  RU_QUES,  (layer_state_t)1 <<_DIKTOR);
const key_override_t dot_dikt_override  = ko_make_with_layers(MOD_MASK_SHIFT, RU_DOT,   RU_EXLM,  (layer_state_t)1 <<_DIKTOR);
const key_override_t sign_dikt_override = ko_make_with_layers(MOD_MASK_SHIFT, RU_SSIGN, RU_HSIGN, (layer_state_t)1 <<_DIKTOR);

const key_override_t** key_overrides = (const key_override_t*[])
{
    &comm_dikt_override, &dot_dikt_override, &sign_dikt_override, NULL
};
