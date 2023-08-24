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

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_8001F1D8);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_8001F42C);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_8001F57C);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_8001F5E4);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_8001F608);

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

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__Unk06);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_8001FE34);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_8001FE8C);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__CallBack);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_80020004);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_80020020);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", UnkCtor02);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_800200AC);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_800200E4);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", UnkFunc04); // Used by InputSys__Quit

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_800201C4);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_800202C0);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_8002038C);
