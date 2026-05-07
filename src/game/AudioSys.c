#include "common.h"

#include "globals.h"

#include <psyq/LIBGTE.H>
#include <psyq/STDIO.H>

// is this bss or data???
s16 UnkVar04 = 0;  // 0x80047F78
s32 UnkVar06 = 0;  // 0x80047F7C
s32 voice_bit = 0; // 0x80047F80
s32 D_80047F84 = 0;
s32 UnkVar07 = 0;  // 0x80047F88

char D_80047F8C[2] = "%d";
char D_80047F90[2] = "%u";
char D_80047F94[2] = "";

s32 D_80047F98 = 0xFFFF0100;
s32 D_80047F9C = 0x0000FFFF;

void AudioSys__Init() {
    SpuInit();
    AudioSys__InitSpu();
    VideoSys__AddVSyncCB(&AudioSys__CallBack);
}

void AudioSys__QuitSpu() {
    VideoSys__RemoveVSyncCB(&AudioSys__CallBack);
    UnkFunc00();
    SpuQuit();
}

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__SetVolume);

INCLUDE_RODATA("asm/game/nonmatchings/AudioSys", D_80019114);

INCLUDE_RODATA("asm/game/nonmatchings/AudioSys", D_8001913C);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_8001F1D8);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_8001F42C);

// This function seems to be configuring the audio settings (By the AudioSys__Unk06)
void AudioSys__UnkFunc01(UnkStruct02* arg0, s16 arg1, s16 arg2, s16 arg3)
{
    AudioSys__UnkFunc06(arg1, UnkVar04, arg0->unk0, arg0->unk4, (s16) (arg0->unk4 + 1), 0, arg2, arg2, arg3);
}

extern s32 func_8001FE34(s32);

s32 func_8001F5E4(s16 arg0) {
    return func_8001FE34(arg0);
}

int AudioSys__UnkFunc09()
{
    return AudioSys__UnkFunc08();
}

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__ParseVH);

typedef struct {
    char pad0[0x10];
    void *unk10;
    s32 unk14;
    void *unk18;
} AudioSysUnkStruct02;

extern u32 D_8001918C;
extern u32 AudioSys__UnknownVar;
extern void SpuFree(s32);

void AudioSys__UnkFunc00(AudioSysUnkStruct02 *arg0, s32 arg1) {
    arg0->unk18 = &D_8001918C;
    if (arg0->unk10 != NULL) {
        delete(arg0->unk10);
    }
    if (arg1 & 1) {
        free(arg0);
    }
}

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_8001F74C);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__new);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__Unk01);

typedef struct {
    char unk0[0x1c];
    s32 unk1C;
} AudioSysUnkStruct01;

void AudioSys__Unk02(AudioSysUnkStruct01* arg0, s32 arg1, s32 arg2) {
    arg0->unk1C = arg1;
    AudioSys__Unk01(arg0, arg2);
}

s32 AudioSys__IsTransferCompleted(s32 flag)
{
    return SpuIsTransferCompleted(flag != 0) != 0;
}

void AudioSys__Dtor(AudioSysUnkStruct02 *arg0, s32 arg1) {
    arg0->unk18 = &AudioSys__UnknownVar;
    if (arg0->unk14 >= 0) {
        SpuFree(arg0->unk14);
    }
    AudioSys__UnkFunc00(arg0, arg1);
}

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__InitSpu);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", UnkFunc00);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__Unk00);

extern s32 D_8003FD8C[];

void AudioSys__Unk05(s16 arg0, void* data, s16 flag)
{
	AudioSys__Unk02(D_8003FD8C[arg0], data, flag == 1);
}

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__Unk04);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__UnkFunc06);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_8001FE34);

void AudioSys__UnkFunc07() // Clears the UnkVar05 values
{
    s32 i;

    voice_bit = 0xFFFFFF;
    i = 0;
    UnkVar06 = 0;
    UnkVar07 = 0;

    while (i < 24)
    {
        UnkVar05[i] = -1;
        i++;
    }
}

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__CallBack);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__UnkFunc08);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_80020020);

extern s32 D_8003FC9C[2];

void UnkCtor02(void) {
    D_8003FC9C[0] = 0;
    D_8003FC9C[1] = 0;
}

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_800200AC);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_800200E4);

void UnkFunc04(UnkStruct10* arg0, s32 arg1) {
    s32 temp_a0;

    temp_a0 = arg0->unk6;
    if (!(temp_a0 & 3)) {
        func_800341A8(temp_a0, 0, 0);
    }
    if (arg1 & 1) {
        free(arg0);
    }
}

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_800201C4);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_800202C0);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_8002038C);

INCLUDE_RODATA("asm/game/nonmatchings/AudioSys", AudioSys__UnknownVar);

INCLUDE_RODATA("asm/game/nonmatchings/AudioSys", D_8001918C);
