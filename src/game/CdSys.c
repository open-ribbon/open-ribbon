#include "common.h"

#include "globals.h"

#include <psyq/LIBGTE.H>
#include <psyq/STDIO.H>

s32 D_80047F1C;
s32 D_80047F20;
s32 D_80047F24;
s32 D_80047F28;

volatile s32 UnkVar01; // 0x80047F2C
volatile s32 UnkVar00; // 0x80047F30
volatile s32 UnkVar02; // 0x80047F34

s32 D_80047F38;
s32 D_80047F3C;
UnkStruct07 *D_80047F40;
s32 *D_80047F44;
s32 CdSys__Unk01MemAdd; // 0x80047F48
s32 CdSys__Unk00MemAdd; // 0x80047F4C
s32 D_80047F50;
s32 D_80047F54;
s32 D_80047F58; // ??
s32 D_80047F5C;
s32 D_80047F60;
UnkStruct03 *D_80047F64;
s32 D_80047F68;
s32 D_80047F6C;
s32 D_80047F70;
s32 D_80047F74;

void func_80031E48(UnkStruct03*);
void func_80031374(void);
void func_80032158(UnkStruct04*);
u32  func_80031C40(void);
void func_80032518(s32, void*);

extern UnkStruct08 D_8003F974[];
extern UnkStruct08 D_8003F96C[];
extern s32 D_8004812C; // some kind of struct?

void func_8001E7E8(u8 arg0, UnkStruct06 *arg1) {
    u8 sp10[3];
    s32 *temp_v1;
    s32 temp_a0;
    s32 temp_v0;
    s32 var_v1;
    UnkStruct08 *temp_v0_2;

    if (arg0 == 2) {
        temp_v0 = arg1->unk0;
        D_80047F60 = ((temp_v0 / 16) * 10) + (temp_v0 - ((temp_v0 / 16) * 16));

        sp10[0] = arg1->unk5;
        sp10[1] = arg1->unk6;
        sp10[2] = arg1->unk7;

        temp_a0 = func_8003261C(&sp10);

        switch (D_80047F68) {
        case 0:
            break;
        case 1:
            if (temp_a0 >= D_8003F96C[D_80047F6C].unk0) {
                D_80047F68 = arg0;
                func_800314D8(12, 0, 0, 0);
                if (D_80047F40 != NULL) {
                    D_80047F40->unk4 = D_80047F6C - (UnkVar00 != 0);
                    temp_v0_2 = &D_8003F96C[D_80047F6C];
                    temp_v1 = temp_v0_2->unk4;
                    if (temp_v1 != NULL) {
                        var_v1 = *temp_v1 - temp_v0_2->unk0;
                    } else {
                        var_v1 = 0;
                    }
                    D_80047F40->unk8 = (var_v1 / 75);
                    D_80047F40->unk0 = 1;
                }
            }
            break;
        case 2:
            if (D_80047F68 == arg0) {
                if (temp_a0 >= (D_8003F974[D_80047F6C].unk0 - 5)) {
                    D_80047F68 = 0;
                    func_800314D8(11, 0, 0, 0);
                    if (D_80047F44 != NULL) {
                        *D_80047F44 = 1;
                    }
                }
            }
            break;
        }
    }
}

void func_8001E9B0(u8 arg0, UnkStruct05 *arg1) {
    s32 tmp1;
    s32 tmp2;

    if (arg0 == 2) {
        tmp1 = arg1->unk2;
        tmp2 = tmp1 / 16;
        UnkVar01 = (tmp2 * 10) + (tmp1 - (tmp2 * 16));
    }
}

void func_8001E9FC(u8 arg0) {
    UnkVar00 = arg0 == 2;
    if (arg0 != 2) {
        func_80032518(D_8003F974[0].unk0, &D_8004812C);
        func_800314D8(3, &D_8004812C, 0, 0);
    }
}

INCLUDE_ASM("asm/game/nonmatchings/CdSys", func_8001EA5C);

void UnkFunc03()
{
    UnkVar00 = -1;
    UnkVar01 = UnkVar00;
    UnkVar02 = 0;
}

INCLUDE_ASM("asm/game/nonmatchings/CdSys", func_8001EBD4);

INCLUDE_ASM("asm/game/nonmatchings/CdSys", func_8001EC08);

INCLUDE_RODATA("asm/game/nonmatchings/CdSys", D_8001907C);

INCLUDE_RODATA("asm/game/nonmatchings/CdSys", D_800190A4);

#if 0
// addiu in wrong place
void func_8001EC74(UnkStruct03 *arg0) {
    UnkStruct04 sp10;  // struct of size 0x30?
    s32 temp_s0;
    s32 *tmp;

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

    func_80031E48(&sp10); // help
    func_80031374();

    sp10.unk0 = 0;
    func_80032158(&sp10);
    VSync(4);
    temp_s0 = (func_80031C40() >> 4) & 1;
    if ((D_80047F64->unk0 <= 0) && (temp_s0 != 0)) {

        sp10.unk28.unk0 = 1;
        sp10.unk28.unk4 = 0;

        *D_80047F64 = sp10.unk28;

        printf("setting null home disk\n");

        (void)"CdSys::PlayTrack(): requested track out of range\n";
    }
    D_80047F5C = temp_s0;
}

#else
INCLUDE_ASM("asm/game/nonmatchings/CdSys", func_8001EC74);
#endif

INCLUDE_ASM("asm/game/nonmatchings/CdSys", func_8001ED44);

INCLUDE_ASM("asm/game/nonmatchings/CdSys", func_8001ED6C);

#if 0
// need to migrate .rodata
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
INCLUDE_ASM("asm/game/nonmatchings/CdSys", func_8001EFEC);
#endif

#if 0
// need to migrate .rodata
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
INCLUDE_ASM("asm/game/nonmatchings/CdSys", func_8001F048);
#endif

// reset something
void func_8001F0A4(void) {
    s32 *var_v1;
    s32 i;

    var_v1 = &D_8003F974;

    for (i = 100; i != -1; i--) {
        var_v1[0] = 0;
        var_v1[1] = 0;
        var_v1 += 2;
    };

    D_80047F1C = 0;
}
