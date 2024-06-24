const uint16_t PROGMEM test_combo1[] = {KC_N, KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_BSPC, KC_ENT, COMBO_END};
combo_t key_combos[] = {
    COMBO(test_combo1, TG(3)),
    COMBO(test_combo2, TG(1))
};