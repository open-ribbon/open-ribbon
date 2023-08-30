#include "common.h"

#include "globals.h"

#include <psyq/LIBGTE.H>
#include <psyq/STDIO.H>

void AudioSys__Init() {
    SsUtReverbOff();
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
// INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__UnkFunc01);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_8001F5E4);

int AudioSys__UnkFunc09()
{
    return AudioSys__UnkFunc08();
}
// INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__UnkFunc07);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__ParseVH);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__UnkFunc00); // Since its "circled" by AudioSys, its probably part of AudioSys

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_8001F74C);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__new);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__Unk01);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__Unk02);

s32 AudioSys__IsTransferCompleted(s32 arg0)
{
    return SpuIsTransferCompleted(arg0 != 0) != 0;
}

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__Dtor); // Uses AudioSys__UnkFunc00

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__InitSpu);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", UnkFunc00);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__Unk00);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__Unk05);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__Unk04);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__UnkFunc06);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_8001FE34);

// INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__UnkFunc07);
void AudioSys__UnkFunc07() // Clears the UnkVar05 values
{
    s32 i;

    voice_bit = 0xFFFFFF; // 16777215 in decimal
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

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", UnkCtor02);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_800200AC);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_800200E4);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", UnkFunc04); // Used by InputSys__Quit

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_800201C4);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_800202C0);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_8002038C);

INCLUDE_RODATA("asm/game/nonmatchings/AudioSys", AudioSys__UnknownVar);

INCLUDE_RODATA("asm/game/nonmatchings/AudioSys", D_8001918C);
