#include "common.h"
#include "globals.h"

INCLUDE_ASM("asm/game/nonmatchings/E9A0", func_800271A0);

void func_80027340(UnkStruct16* arg0, s32 arg1) {
    if (arg1 != 0) {
        arg0->unk18 += arg0->unk1C;
        return;
    }
    if (arg0->unk18 != 0) {
        arg0->unk18 += arg0->unk1C;
        if (arg0->unk18 == 0) {
            arg0->unk1C = 1;
        }
    }
}

INCLUDE_ASM("asm/game/nonmatchings/E9A0", func_80027394);

typedef struct {
    s32 unk0;
    char pad4[0x8];
    UnkStruct16 *unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} AnimStruct;

extern void func_80025954(UnkStruct16*);

void func_800274EC(AnimStruct* arg0, s32 arg1) {
    if (arg0->unk0 == 0) {
        arg0->unk18 = 0;
        arg0->unk1C = 1;
    }
    arg0->unk0++;
    if (arg0->unk0 > arg0->unk14) {
        func_80027340((UnkStruct16*)arg0, arg1);
        arg0->unkC->unk18 = 0;
        if (arg0->unk18 == 0) {
            func_80025954(arg0->unkC);
        }
    }
}

s32 func_80027570(void) {
    return 1;
}

void func_80027578(UnkStruct12* arg0) {
    arg0->unk0 = arg0->unk14 - 1;
}

void func_8002758C(UnkStruct14* arg0) {
    UnkStruct15* temp_v0;

    temp_v0 = arg0->unkC;
    arg0->unk0 = 0;
    temp_v0->unk10 = 0;
    UnkFunc01(temp_v0, 0x8000);
}

INCLUDE_ASM("asm/game/nonmatchings/E9A0", func_800275BC);

INCLUDE_ASM("asm/game/nonmatchings/E9A0", func_8002780C);

s32 func_800278BC(UnkStruct13* arg0) {
    return func_80025EBC(0x335) < arg0->unk38;
}

void func_800278EC(UnkStruct11* arg0) {
    arg0->unk2C = 1;
}

INCLUDE_ASM("asm/game/nonmatchings/E9A0", func_800278F8);

INCLUDE_ASM("asm/game/nonmatchings/E9A0", func_800279E4);
