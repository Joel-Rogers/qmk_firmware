#pragma once

#include "quantum.h"
#include "sol3.h"

// clang-format off
/* Blank ascii map to reuse
┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐  ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┐
│      │      │      │      │      │      │      │  │      │      │      │      │      │      │      │
├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
│      │      │      │      │      │      │      │  │      │      │      │      │      │      │      │
├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
│      │      │      │      │      │      │      │  │      │      │      │      │      │      │      │
├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
│      │      │      │      │      │      │      │  │      │      │      │      │      │      │      │
├──────┼──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┼──────┤
│      │      │      │      │      │      │      │  │      │      │      │      │      │      │      │
└──────┴──────┴──────┴──────┴──────┤      ├──────┤  ├──────┤      ├──────┴──────┴──────┴──────┴──────┘
                                   │      │      │  │      │      │
                                   └──────┴──────┘  └──────┴──────┘
┌──────┬──────┬──────┬──────┬──────┬──────┐                ┌──────┬──────┬──────┬──────┬──────┬──────┐
│      │      │      │      │      │      │                │      │      │      │      │      │      │
├──────┼──────┼──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┼──────┼──────┤
│      │      │      │      │      │      │                │      │      │      │      │      │      │
├──────┼──────┼──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┼──────┼──────┤
│      │      │      │      │      │      │                │      │      │      │      │      │      │
├──────┼──────┼──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┼──────┼──────┤
│      │      │      │      │      │      │                │      │      │      │      │      │      │
└──────┴──────┴──────┴──────┴──────┴──────┘                └──────┴──────┴──────┴──────┴──────┴──────┘
┌──────┬──────┬──────┬──────┬──────┬──────┐                ┌──────┬──────┬──────┬──────┬──────┬──────┐
│      │      │      │      │      │      │                │      │      │      │      │      │      │
└──────┴──────┴──────┴──────┴──────┴──────┘                └──────┴──────┴──────┴──────┴──────┴──────┘

*/
#define LAYOUT( \
    L00, L01, L02, L03, L04, L05, L06,           R00, R01, R02, R03, R04, R05, R06, \
    L10, L11, L12, L13, L14, L15, L16,           R10, R11, R12, R13, R14, R15, R16, \
    L20, L21, L22, L23, L24, L25, L26,           R20, R21, R22, R23, R24, R25, R26, \
    L30, L31, L32, L33, L34, L35, L36,           R30, R31, R32, R33, R34, R35, R36, \
    L40, L41, L42, L43, L44, L45, L46, L47, R40, R41, R42, R43, R44, R45, R46, R47, \
    \
    E0L, E0R, E1L, E1R, E2L, E2R,                     E6L, E6R, E7L, E7R, E8L, E8R, \
    E3L, E3R, E4L, E4R, E5L, E5R,                     E9L, E9R, EAL, EAR, EBL, EBR, \
    LT0, LT1, LT2, LSL, LSR,                               RT0, RT1, RT2, RSL, RSR \
) \
{ \
    /* Left Half */ \
    { L00, L01, L02, L03, L04, L05, L06, LT0   }, \
    { L10, L11, L12, L13, L14, L15, L16, LT1   }, \
    { L20, L21, L22, L23, L24, L25, L26, LT2   }, \
    { L30, L31, L32, L33, L34, L35, L36, KC_NO }, \
    { L40, L41, L42, L43, L44, L45, L46, L47   }, \
    { E0L, E0R, E1L, E1R, E2L, E2R, LSL, KC_NO }, \
    { E3L, E3R, E4L, E4R, E5L, E5R, LSR, KC_NO }, \
    /* Right Half */ \
    { R06, R05, R04, R03, R02, R01, R00, RT0   }, \
    { R16, R15, R14, R13, R12, R11, R10, RT1   }, \
    { R26, R25, R24, R23, R22, R21, R20, RT2   }, \
    { R36, R35, R34, R33, R32, R31, R30, KC_NO }, \
    { R47, R46, R45, R44, R43, R42, R41, R40   }, \
    { E6L, E6R, E7L, E7R, E8L, E8R, RSL, KC_NO }, \
    { E9L, E9R, EAL, EAR, EBL, EBR, RSR, KC_NO } \
}

#define NUMBER_OF_TOUCH_ENCODERS 2
#define TOUCH_ENCODER_OPTIONS TOUCH_SEGMENTS + 2
#define TOUCH_ENCODER_MATRIX_MAP { \
    { { 0, 7 }, { 1, 7 }, { 2, 7 }, { 5, 6 }, { 6, 6 }, }, \
    { { 7, 7 }, { 8, 7 }, { 9, 7 }, {12, 6 }, {13, 6 }, }  \
}

#define NUMBER_OF_ENCODERS 12
#define ENCODER_OPTIONS 2
#define ENCODER_MATRIX_MAP { \
    { { 5, 0 }, { 5, 1 } }, \
    { { 5, 3 }, { 5, 2 } }, \
    { { 5, 5 }, { 5, 4 } }, \
    { { 6, 1 }, { 6, 0 } }, \
    { { 6, 3 }, { 6, 2 } }, \
    { { 6, 5 }, { 6, 4 } }, \
    { {12, 0 }, {12, 1 } }, \
    { {12, 3 }, {12, 2 } }, \
    { {12, 5 }, {12, 4 } }, \
    { {13, 1 }, {13, 0 } }, \
    { {13, 3 }, {13, 2 } }, \
    { {13, 5 }, {13, 4 } }  \
}

typedef struct PACKED {
    uint8_t row;
    uint8_t col;
} encodermap_t;

// clang-format on
