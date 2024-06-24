bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_sequence_transform(keycode, record, US_MAG1)) 
    return false;
    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    post_process_sequence_transform();
}

void matrix_scan_user(void)
{
    sequence_transform_task();
}