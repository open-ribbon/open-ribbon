#include "common.h"

#include "globals.h"

#include <psyq/LIBGTE.H>
#include <psyq/STDIO.H>


INCLUDE_ASM("asm/game/nonmatchings/5FE8", func_8001E7E8);

void func_8001E9B0(u8 arg0, UnkStruct05 *arg1) {
    s32 tmp1;
    s32 tmp2;

    if (arg0 == 2) {
        tmp1 = arg1->unk2;
        tmp2 = tmp1 / 16;
        UnkVar01 = (tmp2 * 10) + (tmp1 - (tmp2 * 16));
    }
}

#if 0
void func_80032518(s32, s32*);
s32 D_8003F974;
s32 D_8004812C; // some kind of struct?
//
void func_8001E9FC(u8 arg0) {

    UnkVar00 = arg0 == 2;
    if (arg0 != 2) {
        func_80032518(D_8003F974, &D_8004812C);
        func_800314D8(3, &D_8004812C, 0, 0);
    }
}
#else
INCLUDE_ASM("asm/game/nonmatchings/5FE8", func_8001E9FC);
#endif

INCLUDE_ASM("asm/game/nonmatchings/5FE8", func_8001EA5C);

void UnkFunc03()
{
    UnkVar00 = -1;
    UnkVar01 = UnkVar00;
    UnkVar02 = 0;
}

INCLUDE_ASM("asm/game/nonmatchings/5FE8", func_8001EBD4);

INCLUDE_ASM("asm/game/nonmatchings/5FE8", func_8001EC08);

INCLUDE_RODATA("asm/game/nonmatchings/5FE8", D_8001907C);

INCLUDE_RODATA("asm/game/nonmatchings/5FE8", D_800190A4);

#if 0

typedef struct {
    s32 unk0;
    s32 unk4;
} UnkStruct03; // size unknown

typedef struct {
    s32 unk0;
    u8  pad4[0x24];
    s32 unk28;
    s32 unk2C;
} UnkStruct04; // size 0x30?

extern s32 D_80047F38;
extern s32 D_80047F3C;
extern s32 D_80047F40;
extern s32 D_80047F44;
extern s32 D_80047F50;
extern s32 D_80047F54;
extern s32 D_80047F5C;
extern s32 D_80047F60;
extern UnkStruct03 *D_80047F64;
extern s32 D_80047F68;
extern s32 D_80047F74;

void func_80031E48(void);
void func_80031374(void);
void func_80032158(UnkStruct04*);
u32 func_80031C40(void);

void func_8001EC74(UnkStruct03 *arg0) {
    UnkStruct04 sp10;  // struct of size 0x30?
    s32 temp_s0;

    D_80047F64 = arg0;

    UnkFunc03();
    D_80047F60 = 0;
    D_80047F40 = 0;
    D_80047F44 = 0;
    CdSys__Unk01MemAdd = 0;
    CdSys__Unk00MemAdd = 0;
    D_80047F50 = 0;
    D_80047F54 = 0;
    D_80047F74 = 0;
    D_80047F3C = -1;
    D_80047F38 = 0;
    D_80047F68 = 0;
    func_80031E48();
    func_80031374();

    sp10.unk0 = 0;
    func_80032158(&sp10);
    VSync(4);
    temp_s0 = (func_80031C40() >> 4) & 1;
    if ((D_80047F64->unk0 <= 0) && (temp_s0 != 0)) {

        sp10.unk28 = 1; //
        sp10.unk2C = 0;//

        D_80047F64->unk0 = 1;
        D_80047F64->unk4 = 0;

        printf("setting null home disk\n", D_80047F64, D_80047F64->unk0, D_80047F64->unk4);
    }
    D_80047F5C = temp_s0;
}

const char unused_string_in_5FE8[] = "CdSys::PlayTrack(): requested track out of range\n";
#else
INCLUDE_ASM("asm/game/nonmatchings/5FE8", func_8001EC74);
#endif

INCLUDE_ASM("asm/game/nonmatchings/5FE8", func_8001ED44);

INCLUDE_ASM("asm/game/nonmatchings/5FE8", func_8001ED6C);

#if 0
void func_8001EFEC(s32 arg0) {
    SwEnterCriticalSection();
    if (CdSys__Unk01MemAdd != 0) {
        printf("Assertion failed: file \"%s\", line %d\n", "C:/psj/dev/locale/game/CdSys.cpp", 0x1FF);
        exit(1);
    }
    CdSys__Unk01MemAdd = arg0;
    SwExitCriticalSection();
}
#else
INCLUDE_ASM("asm/game/nonmatchings/5FE8", func_8001EFEC);
#endif

#if 0
void func_8001F048(int *arg0)
{
    SwEnterCriticalSection();
    if (CdSys__Unk00MemAdd)
    {
        printf("Assertion failed: file \"%s\", line %d\n", "C:/psj/dev/locale/game/CdSys.cpp", 511);
        exit(1);
    }
    CdSys__Unk00MemAdd = arg0;
    SwExitCriticalSection();
}
#else
INCLUDE_ASM("asm/game/nonmatchings/5FE8", func_8001F048);
#endif

INCLUDE_ASM("asm/game/nonmatchings/5FE8", func_8001F0A4);
