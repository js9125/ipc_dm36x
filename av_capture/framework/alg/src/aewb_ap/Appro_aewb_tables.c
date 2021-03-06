
#include "alg_aewb_priv.h"

#define APPRO_AEW_WIN_HZ_CNT	        12
#define APPRO_AEW_WIN_VT_CNT	        16

unsigned char APPRO_WEIGHTING_SPOT[APPRO_AEW_WIN_HZ_CNT * APPRO_AEW_WIN_VT_CNT]=
{
    0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,
    0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,
    0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,
    0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,
    0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,
    0x04,0x04,0x04,0x04,0x16,0x16,0x16,0x16,0x04,0x04,0x04,0x04,
    0x04,0x04,0x04,0x04,0x16,0xFF,0xFF,0x16,0x04,0x04,0x04,0x04,
    0x04,0x04,0x04,0x04,0x16,0xFF,0xFF,0x16,0x04,0x04,0x04,0x04,
    0x04,0x04,0x04,0x04,0x16,0xFF,0xFF,0x16,0x04,0x04,0x04,0x04,
    0x04,0x04,0x04,0x04,0x16,0xFF,0xFF,0x16,0x04,0x04,0x04,0x04,
    0x04,0x04,0x04,0x04,0x16,0x16,0x16,0x16,0x04,0x04,0x04,0x04,
    0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,
    0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,
    0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,
    0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,
    0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04
};

unsigned char APPRO_WEIGHTING_CENTER[APPRO_AEW_WIN_HZ_CNT * APPRO_AEW_WIN_VT_CNT]=
{
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,
    0x0A,0x0A,0x0A,0x12,0x12,0x12,0x12,0x12,0x12,0x0A,0x0A,0x0A,
    0x0A,0x0A,0x0A,0x12,0x12,0x12,0x12,0x12,0x12,0x0A,0x0A,0x0A,
    0x0A,0x0A,0x12,0x12,0x1C,0x1C,0x1C,0x1C,0x12,0x12,0x0A,0x0A,
    0x0A,0x0A,0x12,0x12,0x1C,0x1C,0x1C,0x1C,0x12,0x12,0x0A,0x0A,
    0x0A,0x12,0x12,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x12,0x12,0x0A,
    0x0A,0x12,0x12,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x12,0x12,0x0A,
    0x0A,0x12,0x12,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x12,0x12,0x0A,
    0x0A,0x12,0x12,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x12,0x12,0x0A,
    0x0A,0x0A,0x12,0x12,0x1C,0x1C,0x1C,0x1C,0x12,0x12,0x0A,0x0A,
    0x0A,0x0A,0x12,0x12,0x1C,0x1C,0x1C,0x1C,0x12,0x12,0x0A,0x0A,
    0x0A,0x0A,0x0A,0x12,0x12,0x12,0x12,0x12,0x12,0x0A,0x0A,0x0A,
    0x0A,0x0A,0x0A,0x12,0x12,0x12,0x12,0x12,0x12,0x0A,0x0A,0x0A,
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,
    0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A};

unsigned char APPRO_WEIGHTING_MATRIX[APPRO_AEW_WIN_HZ_CNT * APPRO_AEW_WIN_VT_CNT]={
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10};


IAWB_DynamicParams IAWB_DynamicParam=
{
    0,
    0,
    0,
    IAWB_MODE_AUTO,
    {
        0,
        0,
        0,
        0
    }
};

IAE_DynamicParams IAE_DynamicParam=
{
    0,
    125,
    {
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {496,496},
        {248,248},
        {248,248},
        {248,248},
        {248,248},
        {248,248},
        {248,248},
        {248,248},
        {248,248},
        {124,124},
        {124,124},
        {124,124},
        {124,124},
        {124,124},
        {124,124},
        {124,124},
        {124,124},
        {62 ,62},
        {62 ,62},
        {62 ,62},
        {62 ,62},
        {62 ,62},
        {62 ,62},
        {62 ,62},
        {62 ,62},
        {62 ,62},
        {57 ,57},
        {52 ,52},
        {48 ,48},
        {45 ,45},
        {42 ,42},
        {39 ,39},
        {37 ,37},
        {34 ,34},
        {32 ,32},
        {30 ,30},
        {28 ,28},
        {26 ,26},
        {24 ,24},
        {23 ,23},
        {21 ,21},
        {20 ,20},
        {18 ,18},
        {17 ,17},
        {16 ,16},
        {15 ,15},
        {14 ,14},
        {13 ,13},
        {12 ,12},
        {11 ,11},
        {11 ,11},
        {10 ,10},
        {9  ,9},
        {9  ,9},
        {8  ,8},
        {8  ,8},
        {7  ,7},
        {7  ,7},
        {6  ,6},
        {6  ,6},
        {6  ,6},
        {6  ,6},
        {6  ,6},
        {6  ,6},
        {6  ,6},
        {6  ,6},
        {6  ,6},
        {6  ,6},
        {6  ,6},
        {6  ,6},
        {6  ,6},
        {6  ,6},
        {6  ,6},
        {6  ,6},
        {6  ,6},
        {6  ,6},
        {6  ,6},
        {6  ,6},
        {6  ,6},
        {6  ,6},
        {6  ,6}
    },

    5,

    {
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0}
    },
    {
        {96,96},
        {96,96},
        {95,95},
        {93,93},
        {91,91},
        {89,89},
        {87,87},
        {85,85},
        {83,83},
        {81,81},
        {32,32},
        {32,32},
        {32,32},
        {32,32},
        {32,32},
        {32,32},
        {32,32},
        {32,32},
        {32,32},
        {32,32},
        {32,32},
        {32,32},
        {32,32},
        {32,32},
        {32,32},
        {32,32},
        {32,32},
        {32,32},
        {32,32},
        {32,32},
        {30,30},
        {28,28},
        {26,26},
        {24,24},
        {22,22},
        {20,20},
        {18,18},
        {16,16},
        {15,15},
        {14,14},
        {13,13},
        {12,12},
        {11,11},
        {10,10},
        {9 ,9},
        {16,16},
        {15,15},
        {14,14},
        {13,13},
        {12,12},
        {11,11},
        {10,10},
        {9 ,9},
        {16,16},
        {15,15},
        {14,14},
        {13,13},
        {12,12},
        {11,11},
        {10,10},
        {9 ,9},
        {16,16},
        {15,15},
        {14,14},
        {13,13},
        {12,12},
        {11,11},
        {10,10},
        {9 ,9},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8},
        {8 ,8}
    },
    {
        {374,374},
        {374,374},
        {374,374},
        {374,374},
        {374,374},
        {374,374},
        {374,374},
        {374,374},
        {374,374},
        {374,374},
        {374,374},
        {348,348},
        {326,326},
        {304,304},
        {284,284},
        {264,264},
        {246,246},
        {230,230},
        {214,214},
        {200,200},
        {187,187},
        {174,174},
        {163,163},
        {152,152},
        {142,142},
        {132,132},
        {123,123},
        {115,115},
        {107,107},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100},
        {100,100}
    },
    {
        80,100
    },
    140,
    255
};



IAE_Range APPRO_shutter_List_720P[IAE_MAX_RANGES]=
{
    {744,4464},
    {744,4464},
    {744,4464},
    {744,4464},
    {744,4464},
    {744,1488},
    {744,1488},
    {744,1488},
    {744,1488},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {372,372},
    {372,372},
    {372,372},
    {372,372},
    {372,372},
    {372,372},
    {372,372},
    {372,372},
    {186,186},
    {186,186},
    {186,186},
    {186,186},
    {186,186},
    {186,186},
    {186,186},
    {186,186},
    {186,186},
    {93 ,93},
    {93 ,93},
    {93 ,93},
    {93 ,93},
    {93 ,93},
    {93 ,93},
    {93 ,93},
    {93 ,93},
    {87 ,87},
    {81 ,81},
    {75 ,75},
    {70 ,70},
    {66 ,66},
    {61 ,61},
    {57 ,57},
    {53 ,53},
    {50 ,50},
    {46 ,46},
    {43 ,43},
    {40 ,40},
    {38 ,38},
    {35 ,35},
    {33 ,33},
    {31 ,31},
    {29 ,29},
    {27 ,27},
    {25 ,25},
    {23 ,23},
    {22 ,22},
    {20 ,20},
    {19 ,19},
    {18 ,18},
    {16 ,16},
    {15 ,15},
    {14 ,14},
    {13 ,13},
    {12 ,12},
    {12 ,12},
    {11 ,11},
    {10 ,10},
    {9  ,9},
    {9  ,9},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8}
};


IAE_Range APPRO_agc_List_720P[IAE_MAX_RANGES]=
{
    {87,20},
    {87,17},
    {87,14},
    {87,12},
    {87,10},
    {87,30},
    {87,26},
    {87,22},
    {87,18},
    {87,32},
    {87,32},
    {87,32},
    {87,32},
    {86,32},
    {85,32},
    {84,32},
    {83,32},
    {82,32},
    {81,32},
    {32,32},
    {32,32},
    {32,32},
    {32,32},
    {32,32},
    {32,32},
    {32,32},
    {32,32},
    {32,32},
    {32,32},
    {32,32},
    {30,30},
    {28,28},
    {26,26},
    {24,24},
    {22,22},
    {20,20},
    {18,18},
    {16,16},
    {15,15},
    {14,14},
    {13,13},
    {12,12},
    {11,11},
    {10,10},
    { 9, 9},
    {16,16},
    {15,15},
    {14,14},
    {13,13},
    {12,12},
    {11,11},
    {10,10},
    { 9, 9},
    {16,16},
    {15,15},
    {14,14},
    {13,13},
    {12,12},
    {11,11},
    {10,10},
    {9 ,9},
    {8 ,8},
    {15,15},
    {14,14},
    {13,13},
    {12,12},
    {11,11},
    {10,10},
    {9 ,9},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8}
};

IAE_Range APPRO_dgain_List_720P[IAE_MAX_RANGES]=
{
    {320,400},
    {303,400},
    {293,400},
    {283,400},
    {264,400},
    {254,400},
    {246,400},
    {238,400},
    {230,400},
    {222,400},
    {214,373},
    {207,348},
    {200,325},
    {200,303},
    {200,283},
    {200,264},
    {200,244},
    {200,230},
    {200,214},
    {200,200},
    {187,187},
    {174,174},
    {163,163},
    {152,152},
    {142,142},
    {132,132},
    {123,123},
    {115,115},
    {107,107},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100}
};



IAE_Range APPRO_shutter_List_480P[IAE_MAX_RANGES]=
{
    {976,5856},
    {976,5856},
    {976,5856},
    {976,5856},
    {976,5856},
    {976,1952},
    {976,1952},
    {976,1952},
    {976,1952},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {976,976},
    {488,488},
    {488,488},
    {488,488},
    {488,488} ,
    {488,488},
    {488,488},
    {488,488},
    {488,488},
    {244,244} ,
    {244,244} ,
    {244,244} ,
    {244,244} ,
    {244,244} ,
    {244,244} ,
    {244,244} ,
    {244,244} ,
    {244,244} ,
    {122,122} ,
    {122,122} ,
    {122,122} ,
    {122,122} ,
    {122,122} ,
    {122,122} ,
    {122,122} ,
    {122,122} ,
    {114,114},
    {106,106} ,
    {99 ,99} ,
    {92 ,92} ,
    {86 ,86} ,
    {80 ,80} ,
    {75 ,75} ,
    {70 ,70} ,
    {65 ,65} ,
    {61 ,61} ,
    {57 ,57} ,
    {53 ,53} ,
    {49 ,49} ,
    {46 ,46} ,
    {43 ,43} ,
    {40 ,40} ,
    {37 ,37} ,
    {35 ,35} ,
    {33 ,33} ,
    {30 ,30} ,
    {28 ,28} ,
    {26 ,26} ,
    {25 ,25} ,
    {23 ,23} ,
    {21 ,21} ,
    {20 ,20} ,
    {19 ,19} ,
    {17 ,17} ,
    {16 ,16} ,
    {15 ,15} ,
    {14 ,14} ,
    {13 ,13} ,
    {12 ,12} ,
    {11 ,11} ,
    {11 ,11} ,
    {10 ,10} ,
    {9  ,9} ,
    {9  ,9} ,
    {8  ,8} ,
    {8  ,8} ,
    {8  ,8} ,
    {8  ,8} ,
    {8  ,8} ,
    {8  ,8} ,
    {8  ,8} ,
    {8  ,8} ,
    {8  ,8} ,
    {8  ,8} ,
    {8  ,8} ,
    {8  ,8} ,
    {8  ,8} ,
    {8  ,8} ,
    {8  ,8} ,
    {8  ,8} ,
    {8  ,8}
};

IAE_Range APPRO_shutter_List_480P_Bin[IAE_MAX_RANGES]=
{
    {496, 2976},
    {496, 2976},
    {496, 2976},
    {496, 2976},
    {496, 2976},
    {496,   992},
    {496,   992},
    {496,   992},
    {496,   992},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {496,  496},
    {248,  248},
    {248,  248},
    {248,  248},
    {248,  248} ,
    {248,  248},
    {248,  248},
    {248,  248},
    {248,  248},
    {124,  124} ,
    {124,  124} ,
    {124,  124} ,
    {124,  124} ,
    {124,  124} ,
    {124,  124} ,
    {124,  124} ,
    {124,  124} ,
    {124,  124} ,
    {62,   62} ,
    {62,   62} ,
    {62,   62} ,
    {62,   62} ,
    {62,   62} ,
    {62,   62} ,
    {62,   62} ,
    {62,   62} ,
    {57,   57},
    {53,   53} ,
    {49,   49} ,
    {46,   46} ,
    {43,   43} ,
    {40,   40} ,
    {37,   37} ,
    {35,   35} ,
    {33,   33} ,
    {30,   30} ,
    {28,   28} ,
    {26,   26} ,
    {25,   25} ,
    {23,   23} ,
    {21,   21} ,
    {20,   20} ,
    {19,   19} ,
    {17,   17} ,
    {16,   16} ,
    {15,   15} ,
    {14,   14} ,
    {13,   13} ,
    {12,   12} ,
    {11,   11} ,
    {11,   11} ,
    {10,   10} ,
    {9 ,   9} ,
    {9 ,   9} ,
    {8 ,   8} ,
    {8 ,   8} ,
    {8 ,   8} ,
    {8 ,   8} ,
    {8 ,   8} ,
    {8 ,   8} ,
    {8 ,   8} ,
    {8 ,   8} ,
    {8 ,   8} ,
    {8 ,   8} ,
    {8 ,   8} ,
    {8 ,   8} ,
    {8 ,   8} ,
    {8 ,   8} ,
    {8 ,   8} ,
    {8 ,   8} ,
    {8 ,   8} ,
    {8 ,   8} ,
    {8 ,   8} ,
    {8 ,   8} ,
    {8 ,   8} ,
    {8 ,   8} ,
    {8 ,   8} ,
    {8 ,   8} ,
    {8 ,   8} ,
    {8 ,   8} ,
    {8 ,   8}
};

IAE_Range APPRO_agc_List_480P[IAE_MAX_RANGES]=
{
    {87,20},
    {87,17},
    {87,14},
    {87,12},
    {87,10},
    {87,30},
    {87,26},
    {87,22},
    {87,18},
    {87,32},
    {87,32},
    {87,32},
    {87,32},
    {86,32},
    {85,32},
    {84,32},
    {83,32},
    {82,32},
    {81,32},
    {32,32},
    {32,32},
    {32,32},
    {32,32},
    {32,32},
    {32,32},
    {32,32},
    {32,32},
    {32,32},
    {32,32},
    {32,32},
    {30,30},
    {28,28},
    {26,26},
    {24,24},
    {22,22},
    {20,20},
    {18,18},
    {16,16},
    {15,15},
    {14,14},
    {13,13},
    {12,12},
    {11,11},
    {10,10},
    { 9, 9},
    {16,16},
    {15,15},
    {14,14},
    {13,13},
    {12,12},
    {11,11},
    {10,10},
    { 9, 9},
    {16,16},
    {15,15},
    {14,14},
    {13,13},
    {12,12},
    {11,11},
    {10,10},
    {9 ,9},
    {8 ,8},
    {15,15},
    {14,14},
    {13,13},
    {12,12},
    {11,11},
    {10,10},
    {9 ,9},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8}
};

IAE_Range APPRO_dgain_List_480P[IAE_MAX_RANGES]=
{
    {320,400},
    {303,400},
    {293,400},
    {283,400},
    {264,400},
    {254,400},
    {246,400},
    {238,400},
    {230,400},
    {222,400},
    {214,373},
    {207,348},
    {200,325},
    {200,303},
    {200,283},
    {200,264},
    {200,244},
    {200,230},
    {200,214},
    {200,200},
    {187,187},
    {174,174},
    {163,163},
    {152,152},
    {142,142},
    {132,132},
    {123,123},
    {115,115},
    {107,107},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100}
};

IAE_Range APPRO_shutter_List_NF[IAE_MAX_RANGES]=
{
    {744,4464},
    {744,4464},
    {744,4464},
    {744,4464},
    {744,4464},
    {744,1488},
    {744,1488},
    {744,1488},
    {744,1488},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {744,744},
    {372,372},
    {372,372},
    {372,372},
    {372,372},
    {372,372},
    {372,372},
    {372,372},
    {372,372},
    {186,186},
    {186,186},
    {186,186},
    {186,186},
    {186,186},
    {186,186},
    {186,186},
    {186,186},
    {186,186},
    {93 ,93},
    {93 ,93},
    {93 ,93},
    {93 ,93},
    {93 ,93},
    {93 ,93},
    {93 ,93},
    {93 ,93},
    {87 ,87},
    {81 ,81},
    {75 ,75},
    {70 ,70},
    {66 ,66},
    {61 ,61},
    {57 ,57},
    {53 ,53},
    {50 ,50},
    {46 ,46},
    {43 ,43},
    {40 ,40},
    {38 ,38},
    {35 ,35},
    {33 ,33},
    {31 ,31},
    {29 ,29},
    {27 ,27},
    {25 ,25},
    {23 ,23},
    {22 ,22},
    {20 ,20},
    {19 ,19},
    {18 ,18},
    {16 ,16},
    {15 ,15},
    {14 ,14},
    {13 ,13},
    {12 ,12},
    {12 ,12},
    {11 ,11},
    {10 ,10},
    {9  ,9},
    {9  ,9},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8},
    {8  ,8}
};


IAE_Range APPRO_agc_List_NF[IAE_MAX_RANGES]=
{
    {87,20},
    {87,17},
    {87,14},
    {87,12},
    {87,10},
    {87,30},
    {87,26},
    {87,22},
    {87,18},
    {87,32},
    {87,32},
    {87,32},
    {87,32},
    {87,32},
    {87,32},
    {87,32},
    {87,32},
    {87,32},
    {87,32},
    {87,32},
    {87,32},
    {87,32},
    {87,32},
    {86,32},
    {85,32},
    {84,32},
    {83,32},
    {82,32},
    {81,32},
    {32,32},
    {30,30},
    {28,28},
    {26,26},
    {24,24},
    {22,22},
    {20,20},
    {18,18},
    {16,16},
    {15,15},
    {14,14},
    {13,13},
    {12,12},
    {11,11},
    {10,10},
    {9 , 9},
    {16,16},
    {15,15},
    {14,14},
    {13,13},
    {12,12},
    {11,11},
    {10,10},
    {9 , 9},
    {16,16},
    {15,15},
    {14,14},
    {13,13},
    {12,12},
    {11,11},
    {10,10},
    {9 ,9},
    {8 ,8},
    {15,15},
    {14,14},
    {13,13},
    {12,12},
    {11,11},
    {10,10},
    {9 ,9},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8},
    {8 ,8}
};

IAE_Range APPRO_dgain_List_NF[IAE_MAX_RANGES]=
{
    {100,400},
    {100,400},
    {100,400},
    {100,400},
    {100,400},
    {100,400},
    {100,400},
    {100,400},
    {100,400},
    {100,400},
    {100,373},
    {100,348},
    {100,325},
    {100,303},
    {100,283},
    {100,264},
    {100,244},
    {100,230},
    {100,214},
    {100,200},
    {100,187},
    {100,174},
    {100,163},
    {100,152},
    {100,142},
    {100,132},
    {100,123},
    {100,115},
    {100,107},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100},
    {100,100}
};

