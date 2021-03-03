// Slight hack to get intellisense to play ball
#include "moonlander.h" // QMK_KEYBOARD_H

#include "version.h"
#include "keymap_us_international.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
    ST_MACRO_0,
    ST_MACRO_1,
    ST_MACRO_2,
    ST_MACRO_3,
    ST_MACRO_4,
    ST_MACRO_5,
};

enum layers {
    L_BASE,
    L_SYMS,
    L_NAV,
    L_NUM,
    L_SNUM,
    L_OS,
    L_GAME,
    L_EMPT,
};

#define NAV_SPC LT(L_NAV, KC_SPACE)

#define CTL_ENTER LCTL(KC_ENTER)
#define CTL_PGDOWN LCTL(KC_PGDOWN)
#define CTL_PGUP LCTL(KC_PGUP)

#define VSC_CMD LCTL(LSFT(KC_P))

// OS commands (Default Regolith Linux bindings)
#define OS_SLEEP LGUI(LSFT(KC_S))
#define OS_TOSCRATCH LCTL(LGUI(KC_M))
#define OS_FMSCRATCH LCTL(LGUI(KC_A))
#define OS_FULLSCRN LGUI(KC_F)
#define OS_FLOAT LGUI(LSFT(KC_F))
#define OS_NOTIFCTNS LGUI(KC_N)
#define OS_LOCK LGUI(KC_ESCAPE)
#define OS_GOTO LCTL(LGUI(KC_SPACE))
#define OS_UNUSED LGUI(KC_GRAVE)
#define OS_RESTART LGUI(LSFT(KC_B))
#define OS_RESIZE LGUI(KC_R)
#define OS_LAYOUT LGUI(KC_T)
#define OS_BAR LGUI(KC_I)
#define OS_TERMINAL LGUI(KC_ENTER)
#define OS_LEFT LGUI(KC_LEFT)
#define OS_DOWN LGUI(KC_DOWN)
#define OS_UP LGUI(KC_UP)
#define OS_RIGHT LGUI(KC_RIGHT)
#define OS_SHUTDOWN LGUI(LSFT(KC_P))
#define OS_SETTINGS LGUI(KC_C)
#define OS_CLOSE LGUI(LSFT(KC_Q))
#define OS_FILES LGUI(LSFT(KC_N))
#define OS_MOVELEFT LCTL(LGUI(LSFT(KC_LEFT)))
#define OS_NEXTWS LCTL(LGUI(KC_TAB))
#define OS_PREVWS LCTL(LGUI(LSFT(KC_TAB)))
#define OS_MOVERIGHT LCTL(LGUI(LSFT(KC_RIGHT)))
#define OS_HELP LGUI(LSFT(KC_SLASH))
#define OS_CMD LGUI(LSFT(KC_SPACE))
#define OS_LAUNCH LGUI(KC_SPACE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = LAYOUT_moonlander(
        TG(L_GAME)    , KC_1          , KC_2          , KC_3          , KC_4          , KC_5          , _______           , _______       , KC_6          , KC_7          , KC_8          , KC_9          , KC_0          , _______       ,
        _______       , KC_Q          , KC_W          , KC_F          , KC_P          , KC_G          , _______           , _______       , KC_J          , KC_L          , KC_U          , KC_Y          , KC_MINUS      , _______       ,
        MO(L_OS)      , KC_A          , KC_R          , KC_S          , KC_T          , KC_D          , KC_BSPACE         , KC_ENTER      , KC_H          , KC_N          , KC_E          , KC_I          , KC_O          , KC_QUOTE      ,
        KC_LSHIFT     , KC_Z          , KC_X          , KC_C          , KC_V          , KC_B                              ,                 KC_K          , KC_M          , KC_COMMA      , KC_DOT        , KC_SLASH      , KC_RSHIFT     ,
        _______       , _______       , _______       , KC_LALT       , KC_LCTRL      ,                 _______           , _______                       , KC_RCTRL      , KC_RALT       , _______       , _______       , _______       ,
                                                                        MO(L_SYMS)    , _______       , MO(L_NUM)         , KC_LGUI       , KC_TAB        , NAV_SPC
    ),
    [L_SYMS] = LAYOUT_moonlander(
        _______       , KC_F1         , KC_F2         , KC_F3         , KC_F4         , KC_F5         , _______           , _______       , KC_F6         , KC_F7         , KC_F8         , KC_F9         , KC_F10        , KC_F11        ,
        _______       , _______       , KC_AT         , KC_HASH       , KC_DLR        , KC_PERC       , _______           , _______       , KC_ASTR       , KC_LBRACKET   , KC_RBRACKET   , KC_UNDS       , _______       , KC_F12        ,
        _______       , KC_EXLM       , KC_CIRC       , KC_LABK       , KC_RABK       , KC_BSLASH     , KC_DELETE         , CTL_ENTER     , KC_EQUAL      , KC_LPRN       , KC_RPRN       , KC_ESCAPE     , KC_COLN       , KC_DQUO       ,
        _______       , _______       , KC_GRAVE      , KC_TILD       , KC_AMPR       , KC_PIPE                           ,                 KC_PLUS       , KC_LCBR       , KC_RCBR       , KC_QUES       , KC_SCOLON     , _______       ,
        _______       , _______       , _______       , _______       , _______       ,                 RGB_MOD           , RGB_TOG                       , _______       , _______       , _______       , _______       , _______       ,
                                                                        _______       , _______       , _______           , RGB_SLD       , _______       , _______
    ),
    [L_NAV] = LAYOUT_moonlander(
        _______       , _______       , _______       , _______       , _______       , _______       , _______           , _______       , _______       , _______       , _______       , _______       , _______       , _______       ,
        _______       , _______       , _______       , _______       , _______       , _______       , _______           , _______       , KC_HOME       , KC_PGDOWN     , KC_PGUP       , KC_END        , _______       , _______       ,
        _______       , _______       , KC_ESCAPE     , KC_ENTER      , KC_TAB        , _______       , _______           , _______       , KC_LEFT       , KC_DOWN       , KC_UP         , KC_RIGHT      , _______       , _______       ,
        _______       , _______       , _______       , _______       , VSC_CMD       , _______                           ,                 _______       , CTL_PGDOWN    , CTL_PGUP      , _______       , _______       , _______       ,
        _______       , _______       , _______       , _______       , _______       ,                 _______           , _______                       , _______       , _______       , _______       , _______       , _______       ,
                                                                        _______       , _______       , _______           , _______       , _______       , _______
    ),
    [L_NUM] = LAYOUT_moonlander(
        _______       , _______       , _______       , _______       , _______       , _______       , _______           , _______       , _______       , _______       , _______       , _______       , _______       , _______       ,
        _______       , _______       , _______       , _______       , _______       , _______       , _______           , _______       , ST_MACRO_0    , KC_7          , KC_8          , KC_9          , _______       , _______       ,
        _______       , _______       , _______       , _______       , _______       , _______       , _______           , _______       , ST_MACRO_1    , KC_4          , KC_5          , KC_6          , _______       , _______       ,
        MO(L_SNUM)    , _______       , _______       , _______       , _______       , _______                           ,                 ST_MACRO_2    , KC_1          , KC_2          , KC_3          , _______       , MO(L_SNUM)    ,
        _______       , _______       , _______       , _______       , _______       ,                 _______           , _______                       , KC_0          , _______       , KC_DOT        , _______       , _______       ,
                                                                        _______       , _______       , _______           , _______       , _______       , _______
    ),
    [L_SNUM] = LAYOUT_moonlander(
        _______       , _______       , _______       , _______       , _______       , _______       , _______           , _______       , _______       , _______       , _______       , _______       , _______       , _______       ,
        _______       , _______       , _______       , _______       , _______       , _______       , _______           , _______       , ST_MACRO_3    , _______       , _______       , _______       , _______       , _______       ,
        _______       , _______       , _______       , _______       , _______       , _______       , _______           , _______       , ST_MACRO_4    , _______       , _______       , _______       , _______       , _______       ,
        _______       , _______       , _______       , _______       , _______       , _______                           ,                 ST_MACRO_5    , _______       , _______       , _______       , _______       , _______       ,
        _______       , _______       , _______       , _______       , _______       ,                 _______           , _______                       , _______       , _______       , _______       , _______       , _______       ,
                                                                        _______       , _______       , _______           , _______       , _______       , _______
    ),
    [L_OS] = LAYOUT_moonlander(
        _______       , _______       , _______       , _______       , _______       , _______       , _______           , _______       , _______       , _______       , _______       , _______       , _______       , OS_SLEEP      ,
        _______       , OS_TOSCRATCH  , OS_FMSCRATCH  , OS_FULLSCRN   , OS_FLOAT      , OS_NOTIFCTNS  , _______           , _______       , _______       , OS_LOCK       , OS_GOTO       , OS_UNUSED     , _______       , OS_RESTART    ,
        _______       , _______       , OS_RESIZE     , _______       , OS_LAYOUT     , OS_BAR        , _______           , OS_TERMINAL   , OS_LEFT       , OS_DOWN       , OS_UP         , OS_RIGHT      , _______       , OS_SHUTDOWN   ,
        _______       , _______       , OS_SETTINGS   , OS_CLOSE      , OS_FILES      , _______                           ,                 OS_MOVELEFT   , OS_NEXTWS     , OS_PREVWS     , OS_MOVERIGHT  , OS_HELP       , _______       ,
        _______       , _______       , _______       , _______       , _______       ,                 _______           , _______                       , _______       , _______       , _______       , _______       , _______       ,
                                                                        OS_CMD        , _______       , _______           , _______       , _______       , OS_LAUNCH
    ),
    [L_GAME] = LAYOUT_moonlander(
        _______       , _______       , _______       , _______       , _______       , _______       , _______           , _______       , _______       , _______       , _______       , _______       , _______       , _______       ,
        _______       , KC_Q          , KC_W          , KC_E          , KC_R          , KC_T          , _______           , _______       , KC_Y          , KC_U          , KC_I          , KC_O          , KC_P          , _______       ,
        _______       , KC_A          , KC_S          , KC_D          , KC_F          , KC_G          , _______           , _______       , KC_H          , KC_J          , KC_K          , KC_L          , _______       , _______       ,
        _______       , KC_Z          , KC_X          , KC_C          , KC_V          , KC_B                              ,                 KC_N          , KC_M          , _______       , _______       , _______       , _______       ,
        _______       , _______       , _______       , _______       , _______       ,                 _______           , _______                       , _______       , _______       , _______       , _______       , _______       ,
                                                                        _______       , _______       , _______           , _______       , _______       , _______
    ),
    [L_EMPT] = LAYOUT_moonlander(
        _______       , _______       , _______       , _______       , _______       , _______       , _______           , _______       , _______       , _______       , _______       , _______       , _______       , _______       ,
        _______       , _______       , _______       , _______       , _______       , _______       , _______           , _______       , _______       , _______       , _______       , _______       , _______       , _______       ,
        _______       , _______       , _______       , _______       , _______       , _______       , _______           , _______       , _______       , _______       , _______       , _______       , _______       , _______       ,
        _______       , _______       , _______       , _______       , _______       , _______                           ,                 _______       , _______       , _______       , _______       , _______       , _______       ,
        _______       , _______       , _______       , _______       , _______       ,                 _______           , _______                       , _______       , _______       , _______       , _______       , _______       ,
                                                                        _______       , _______       , _______           , _______       , _______       , _______
    ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    debug_enable = false;
    debug_matrix = false;
    rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [L_NAV] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {43,255,255}, {43,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {43,255,255}, {43,255,255}, {43,255,255}, {0,0,0}, {0,0,0}, {43,255,255}, {43,255,255}, {43,255,255}, {0,0,0}, {0,0,0}, {43,255,255}, {43,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
};

void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color( i, 0, 0, 0 );
        } else {
            RGB rgb = hsv_to_rgb( hsv );
            float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
        }
    }
}

void rgb_matrix_indicators_user(void) {
    if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
    switch (biton32(layer_state)) {
      case L_NAV:
        set_layer_color(L_NAV);
        break;
      default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE)
          rgb_matrix_set_color_all(0, 0, 0);
        break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ST_MACRO_0:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_DELAY(100) SS_TAP(X_A) SS_DELAY(100) SS_TAP(X_E));
            }
            break;
        case ST_MACRO_1:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_DELAY(100) SS_TAP(X_SLASH) SS_DELAY(100) SS_TAP(X_O));
            }
            break;
        case ST_MACRO_2:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_DELAY(100) SS_TAP(X_O) SS_DELAY(100) SS_TAP(X_A));
            }
            break;
        case ST_MACRO_3:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_DELAY(100) SS_LSFT(SS_TAP(X_A)) SS_DELAY(100) SS_LSFT(SS_TAP(X_E)));
            }
            break;
        case ST_MACRO_4:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_DELAY(100) SS_TAP(X_SLASH) SS_DELAY(100) SS_LSFT(SS_TAP(X_O)));
            }
            break;
        case ST_MACRO_5:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_SCROLLLOCK) SS_DELAY(100) SS_TAP(X_O) SS_DELAY(100) SS_LSFT(SS_TAP(X_A)));
            }
            break;
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
    }
    return true;
}
