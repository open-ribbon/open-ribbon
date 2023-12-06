#include "common.h"

#include "globals.h"

// .sdata
s32 D_80047EC0 = 0;
s32 D_80047EC4 = 0;
s32 D_80047EC8 = 0;
s32 D_80047ECC = 0;
s32 buffer_i = 0; // 0x80047ED0

// what is this?!
// s32 D_80047EE0; // 0x2F6E0 -> 0x2573 => "%s"

// .sbss
s32 D_80047EE4;
s32 D_80047EE8;
s32 D_80047EEC;
s32 D_80047EF0;
s32 D_80047EF4;
s32 D_80047EF8;
s32 D_80047EFC;
s32 D_80047F00;
s32 D_80047F04;
s32 fntStream;  // 0x80047F08
s32 D_80047F0C;
s32 D_80047F10;
s32 D_80047F14;
s32 D_80047F18;

void VideoSys__FlipBuffer()
{
	buffer_i = (buffer_i + 1) % 2;
}

void VideoSys__OnDrawSync() {}

void VideoSys__OnVSync()
{
	VSyncCb* cb;

	for (cb = vsync.cb; cb < (VSyncCb*)vsync.tail; cb++)
	{
		(*cb)();
	}
}

INCLUDE_ASM("asm/game/nonmatchings/VideoSys", VideoSys__Init);

INCLUDE_RODATA("asm/game/nonmatchings/VideoSys", D_80019000);

INCLUDE_RODATA("asm/game/nonmatchings/VideoSys", D_80019028);

INCLUDE_ASM("asm/game/nonmatchings/VideoSys", VideoSys__Quit);

void VideoSys__Reset()
{
  ResetGraph(1);
  VSync(0);
  SetDispMask(0);
}

INCLUDE_ASM("asm/game/nonmatchings/VideoSys", VideoSys__Flip);

INCLUDE_ASM("asm/game/nonmatchings/VideoSys", VideoSys__WriteFnt);

void VideoSys__DisplayFnt()
{
	FntFlush(fntStream);
}

INCLUDE_ASM("asm/game/nonmatchings/VideoSys", VideoSys__GetOT);

INCLUDE_ASM("asm/game/nonmatchings/VideoSys", VideoSys__AddVSyncCB);

INCLUDE_ASM("asm/game/nonmatchings/VideoSys", VideoSys__RemoveVSyncCB);

INCLUDE_ASM("asm/game/nonmatchings/VideoSys", VideoSys__alloc);

INCLUDE_ASM("asm/game/nonmatchings/VideoSys", func_8001E4E4);
