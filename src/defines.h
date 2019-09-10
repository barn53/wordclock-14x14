#define WIDTH 14
#define HEIGHT 14
#define PIXELS (WIDTH * HEIGHT)

#define ROW_NULL_1 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define ROW_NULL_2 ROW_NULL_1, ROW_NULL_1
#define ROW_NULL_3 ROW_NULL_2, ROW_NULL_1
#define ROW_NULL_4 ROW_NULL_3, ROW_NULL_1
#define ROW_NULL_5 ROW_NULL_4, ROW_NULL_1
#define ROW_NULL_6 ROW_NULL_5, ROW_NULL_1
#define ROW_NULL_7 ROW_NULL_6, ROW_NULL_1
#define ROW_NULL_8 ROW_NULL_7, ROW_NULL_1
#define ROW_NULL_9 ROW_NULL_8, ROW_NULL_1
#define ROW_NULL_10 ROW_NULL_9, ROW_NULL_1
#define ROW_NULL_11 ROW_NULL_10, ROW_NULL_1
#define ROW_NULL_12 ROW_NULL_11, ROW_NULL_1
#define ROW_NULL_13 ROW_NULL_12, ROW_NULL_1

#define ES_IST                                   \
    {                                            \
        0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 \
    }
#define S_Z_1                                        \
    {                                                \
        ROW_NULL_13,                                 \
            0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 \
    }
#define S_Z_2                                        \
    {                                                \
        ROW_NULL_13,                                 \
            0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 \
    }
#define S_Z_3                                        \
    {                                                \
        ROW_NULL_13,                                 \
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 \
    }
#define S_Z_4                                        \
    {                                                \
        ROW_NULL_13,                                 \
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 \
    }
#define S_Z_5                                        \
    {                                                \
        ROW_NULL_13,                                 \
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 \
    }
#define S_E_0                                        \
    {                                                \
        ROW_NULL_13,                                 \
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 \
    }
#define S_E_5                                        \
    {                                                \
        ROW_NULL_13,                                 \
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 \
    }
#define M_EINE                                   \
    {                                            \
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1 \
    }
#define M_ZWEI                                   \
    {                                            \
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0 \
    }
#define M_DREI_1                                     \
    {                                                \
        ROW_NULL_1,                                  \
            0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 \
    }
#define M_VIER                                       \
    {                                                \
        ROW_NULL_1,                                  \
            0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 \
    }
#define M_FUENF                                      \
    {                                                \
        ROW_NULL_3,                                  \
            0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 \
    }
#define M_SECHS                                      \
    {                                                \
        ROW_NULL_2,                                  \
            0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 \
    }
#define M_SIEBEN                                     \
    {                                                \
        ROW_NULL_2,                                  \
            0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 \
    }
#define M_ACHT                                        \
    {                                                 \
        ROW_NULL_1,                                   \
            1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
            1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
            1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
            1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  \
    }
#define M_NEUN                                       \
    {                                                \
        ROW_NULL_2,                                  \
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1 \
    }
#define M_ZEHN                                       \
    {                                                \
        ROW_NULL_3,                                  \
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1 \
    }
#define M_DASH_ZEHN                                  \
    {                                                \
        ROW_NULL_3,                                  \
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 \
    }
#define M_ELF                                        \
    {                                                \
        ROW_NULL_1,                                  \
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0 \
    }
#define M_ZWOELF                                     \
    {                                                \
        ROW_NULL_3,                                  \
            0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 \
    }
#define M_VIERTEL_1                                  \
    {                                                \
        ROW_NULL_1,                                  \
            0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 \
    }
#define M_MINUTE                                     \
    {                                                \
        ROW_NULL_4,                                  \
            0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 \
    }
#define M_MINUTEN                                    \
    {                                                \
        ROW_NULL_4,                                  \
            0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 \
    }
#define M_NACH                                       \
    {                                                \
        ROW_NULL_4,                                  \
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1 \
    }
#define M_VOR                                        \
    {                                                \
        ROW_NULL_5,                                  \
            0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 \
    }
#define M_HALB                                       \
    {                                                \
        ROW_NULL_5,                                  \
            0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 \
    }
#define M_DREI_2                                     \
    {                                                \
        ROW_NULL_5,                                  \
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1 \
    }
#define M_DASH_VIERTEL_2                             \
    {                                                \
        ROW_NULL_6,                                  \
            1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 \
    }
#define M_VIERTEL_2                                  \
    {                                                \
        ROW_NULL_6,                                  \
            0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 \
    }

#define H_NULL                                       \
    {                                                \
        ROW_NULL_7,                                  \
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0 \
    }
#define H_UHR                                        \
    {                                                \
        ROW_NULL_11,                                 \
            1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 \
    }
