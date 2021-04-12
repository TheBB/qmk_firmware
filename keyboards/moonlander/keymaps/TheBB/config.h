/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR

#undef TAPPING_TERM
#define TAPPING_TERM 174
#define TAPPING_TERM_PER_KEY

#undef HOMEROWMODS

#ifdef HOMEROWMODS
#define IGNORE_MOD_TAP_INTERRUPT
#endif

#define FIRMWARE_VERSION u8"wEjzJ/qvGQ4"
#define RGB_MATRIX_STARTUP_SPD 60
