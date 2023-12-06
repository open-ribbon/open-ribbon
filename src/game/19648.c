#include "common.h"

#if 0

typedef struct {
    s32 unk0;
    s32 unk4;
} UnkStruct03; // size unknown

typedef struct {
    s32 pad0;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s32 unk14;
    s32 unk18;
    s16 unk1C;
    s16 unk1E;
    s32 unk20;
    s32 unk24;
    UnkStruct03 unk28;
} UnkStruct04; // size 0x30?

typedef struct {
    u8  pad0[0x180];
    u16 unk180;
    u16 unk182;
    u8  pad184[0x26];
    s16 unk1AA;
    u8  pad1AC[0x4];
    s16 unk1B0;
    u16 unk1B2;
    s16 unk1B4;
    s16 unk1B6;
    u16 unk1B8;
    s16 unk1BA;
} UnkStruct06;

extern UnkStruct06 *D_80042B28;

void func_80031E48(UnkStruct04 *arg0) {
    s16 var_a1;
    s16 var_a2;

    s32 var_a3; // bitfield
    s32 var_t0; // bitfield

    u16 tmp1;

    UnkStruct06 *tmp;

    var_a1 = 0;
    // var_a2 = 0;

    var_a3 = D_80042B28->unk180;
    var_t0 = D_80042B28->unk182;

    // top bit not set at all
    if (!(var_a3 & 0x8000)) {
        // fuuu
        var_a2 = var_a1;
        var_a2 = 0;
    } else {
        switch (var_a3 & 0xF000) {
          case 0x8000: // 1000 0000 0000 0000
            var_a2 = 1;
            break;
          case 0x9000: // 1001 0000 0000 0000
            var_a2 = 2;
            break;
          case 0xA000: // 1010 0000 0000 0000
            var_a2 = 3;
            break;
          case 0xB000: // 1011 0000 0000 0000
            var_a2 = 4;
            break;
          case 0xC000: // 1100 0000 0000 0000
            var_a2 = 5;
            break;
          case 0xD000: // 1101 0000 0000 0000
            var_a2 = 6;
            break;
          case 0xE000: // 1110 0000 0000 0000
            var_a2 = 7;
            break;
          case 0xF000: // 1111 0000 0000 0000
            var_a2 = 7;
            break;
        }
        var_a3 &= 0xFFF;
    }


    if ((var_t0 & 0x8000) == 0) {
        var_a1 = 0;
    } else {
        switch (var_t0 & 0xF000) {
        case 0x8000: // 1000 0000 0000 0000
            var_a1 = 1;
            break;
        case 0x9000: // 1001 0000 0000 0000
            var_a1 = 2;
            break;
        case 0xA000: // 1010 0000 0000 0000
            var_a1 = 3;
            break;
        case 0xB000: // 1011 0000 0000 0000
            var_a1 = 4;
            break;
        case 0xC000: // 1100 0000 0000 0000
            var_a1 = 5;
            break;
        case 0xD000: // 1101 0000 0000 0000
            var_a1 = 6;
            break;
        case 0xE000: // 1110 0000 0000 0000
            var_a1 = 7;
            break;
        case 0xF000: // 1111 0000 0000 0000
            var_a1 = 7;
            break;
        }
        var_t0 &= 0xFFF;
    }

    tmp1 = var_a3;
    if (tmp1 >= 0x4000U) {
        arg0->unk4 = tmp1 - 0x8000;
    } else {
        arg0->unk4 = var_a3;
    }

    tmp1 = var_t0;
    if (tmp1 >= 0x4000U) {
        arg0->unk6 = tmp1 - 0x8000;
    } else {
        arg0->unk6 = var_t0;
    }

    tmp = D_80042B28;

    arg0->unk8 = var_a2;
    arg0->unkA = var_a1;

    arg0->unkC = tmp->unk1B8;
    arg0->unkE = tmp->unk1BA;

    arg0->unk10 = tmp->unk1B0;
    arg0->unk12 = tmp->unk1B2;

    tmp = D_80042B28;
    if (tmp->unk1AA & 4) {
        arg0->unk14 = 1;
    } else {
        arg0->unk14 = 0;
    }
    if (D_80042B28->unk1AA & 1) {
        arg0->unk18 = 1;
    } else {
        arg0->unk18 = 0;
    }

    tmp = D_80042B28;
    arg0->unk1C = tmp->unk1B4;
    arg0->unk1E = tmp->unk1B6;

    if (tmp->unk1AA & 8) {
        arg0->unk20 = 1;
    } else {
        arg0->unk20 = 0;
    }
    if (D_80042B28->unk1AA & 2) {
        arg0->unk24 = 1;
        return;
    } else {
        arg0->unk24 = 0;
    }
}
#else
INCLUDE_ASM("asm/game/nonmatchings/19648", func_80031E48);
#endif
