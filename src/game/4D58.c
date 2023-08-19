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
//INCLUDE_ASM("asm/game/nonmatchings/4D58", VideoSys__OnVSync);

INCLUDE_ASM("asm/game/nonmatchings/4D58", VideoSys__Init);

INCLUDE_ASM("asm/game/nonmatchings/4D58", VideoSys__Quit);

INCLUDE_ASM("asm/game/nonmatchings/4D58", VideoSys__Reset);

INCLUDE_ASM("asm/game/nonmatchings/4D58", VideoSys__Flip);

INCLUDE_ASM("asm/game/nonmatchings/4D58", VideoSys__WriteFnt);

void VideoSys__DisplayFnt() 
{
	FntFlush(fntStream);
}
// INCLUDE_ASM("asm/game/nonmatchings/4D58", VideoSys__DisplayFnt);

INCLUDE_ASM("asm/game/nonmatchings/4D58", VideoSys__GetOT);

INCLUDE_ASM("asm/game/nonmatchings/4D58", VideoSys__AddVSyncCB);

INCLUDE_ASM("asm/game/nonmatchings/4D58", VideoSys__RemoveVSyncCB);

INCLUDE_ASM("asm/game/nonmatchings/4D58", VideoSys__alloc);