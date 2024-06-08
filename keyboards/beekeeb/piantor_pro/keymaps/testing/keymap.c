// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later 

#include QMK_KEYBOARD_H
#include "sequence_transform/sequence_transform.h"

#define OS_LSFT OSM(MOD_LSFT)
#define OS_SYM  OSL(2)
#define MT_CTLI CTL_T(KC_I)
#define MT_SFTN SFT_T(KC_N)
#define MT_SFTD SFT_T(KC_D)
#define MT_CTLS CTL_T(KC_SCLN)
#define SF_EXCL LSFT(KC_1)
#define SF_AT   LSFT(KC_2)
#define SF_LBRC LSFT(KC_9)
#define SF_RBRC LSFT(KC_0)
#define SF_QUES LSFT(KC_SLSH)
#define SF_UNDR LSFT(KC_MINS)
#define TH_SPC  LT(2, KC_SPC)
#define TH_REP  LT(NAV, KC_NO)


enum custom_keycodes {
    US_MAG1 = SAFE_RANGE,
    US_MAG2,
    US_MAG3,
    US_MAG4,
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_sequence_transform(keycode, record, US_MAG1)) return false;
    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    post_process_sequence_transform();
}

void matrix_scan_user(void)
{
    sequence_transform_task();
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
//     ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐      ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
         _______,   KC_V,     KC_M,     KC_L,     KC_C,     KC_P,            KC_X,    US_MAG1,   KC_O,     KC_U,     KC_J,     _______,
//     ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤      ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
         _______,   KC_S,     KC_T,     KC_R,    MT_SFTD,   KC_Y,            KC_F,    MT_SFTN,   KC_A,     KC_E,    MT_CTLI,  _______,
//     ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤      ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
         _______,   KC_Z,     KC_K,     KC_Q,     KC_G,     KC_W,            KC_B,     KC_H,    KC_QUOT,  KC_SCLN,  KC_DOT,   _______,
//     └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘      └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
//                                   ┌─────────┬─────────┬─────────┐      ┌─────────┬─────────┬─────────┐
                                       _______,  US_MAG2,  KC_BSPC,         KC_ENT,   LT_SPC,   _______
//                                   └─────────┴─────────┴─────────┘      └─────────┴─────────┴─────────┘
 ),

    [1] = LAYOUT_split_3x6_3( 
//     ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐      ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
         _______,   KC_Q,     KC_W,    KC_E,     KC_R,     KC_T,            KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     _______,
//     ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤      ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
         _______,   KC_A,     KC_S,    KC_D,     KC_F,     KC_G,            KC_H,     KC_J,     KC_K,     KC_L,     MT_CTLS,  _______,
//     ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤      ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
         _______,   KC_Z,     KC_X,    KC_C,     KC_V,     KC_B,            KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  _______,
//     └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘      └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
//                                   ┌─────────┬─────────┬─────────┐      ┌─────────┬─────────┬─────────┐
                                       KC_BSPC,  _______,  OS_LSFT,         KC_ENT,   KC_SPC,   TO(0)
//                                   └─────────┴─────────┴─────────┘      └─────────┴─────────┴─────────┘
 ),

    [2] = LAYOUT_split_3x6_3(
 //    ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐      ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
         _______,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,            KC_6,     KC_7,     KC_8,     KC_9,     KC_0,    _______,
//     ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤      ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
         _______,  SF_EXCL,  SF_AT,    SF_LBRC,  SF_RBRC,  KC_PSCR,         KC_GRV,   SF_QUES,  KC_MINS,  KC_EQL,   KC_COMM,    _______,
//     ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤      ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
         _______,  QK_BOOT,  KC_LGUI,  KC_LBRC,  KC_RBRC,  KC_ESC,          KC_DEL,   KC_SLSH,  SF_UNDR,  KC_BSLS,  KC_F11,   _______,
//     └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘      └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
//                                   ┌─────────┬─────────┬─────────┐      ┌─────────┬─────────┬─────────┐
                                       KC_BSPC,  KC_TAB,   OS_LSFT,         KC_ENT,   KC_SPC,    TO(0)
//                                   └─────────┴─────────┴─────────┘      └─────────┴─────────┴─────────┘
  ),

    [3] = LAYOUT_split_3x6_3(
//     ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐      ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
         _______,  _______,  _______,  KC_BRID,  KC_BRIU,  _______,         _______,  _______,   KC_UP,   _______,  _______,  _______,
//     ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤      ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
         _______,  KC_LCTL,  _______,  KC_VOLD,  KC_VOLU,  _______,         _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  _______,
//     ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤      ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
         _______,  _______,  _______,  _______,  _______,  _______,         _______,  _______,  _______,  _______,  _______,  _______,
//     └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘      └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
//                                   ┌─────────┬─────────┬─────────┐      ┌─────────┬─────────┬─────────┐
                                       KC_BSPC,  KC_TAB,   OS_LSFT,         KC_ENT,   KC_SPC,    TO(0)
//                                   └─────────┴─────────┴─────────┘      └─────────┴─────────┴─────────┘
  )
};


//Combos

const uint16_t PROGMEM test_combo1[] = {KC_N, KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_BSPC, KC_ENT, COMBO_END};
combo_t key_combos[] = {
    COMBO(test_combo1, TG(3)),
    COMBO(test_combo2, TG(1))
};



//Tap Dances


//Custom Keycodes

//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//    switch (keycode) {
//        case SS_DTSP:
//            if (record->event.pressed) {
//                SEND_STRING(". ");
//            }
//            return false;
//    }
//
//    return true;
//}

//enum custom_keys {
//    SS_DTSP = SAFE_RANGE
//};

//bool remember_last_key_user(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods) {
//    switch (keycode) {
//        case LT(2, KC_NO):
//            return false;
//    }
//    return true;
//}

