#include "common.h"

#include "globals.h"

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
