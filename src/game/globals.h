#include "common.h"

#include <psyq/LIBGTE.H>

//
// extern void exit(s32);
// extern int printf(const char* format, ...);

// extern void SwEnterCriticalSection();
// extern void SwExitCriticalSection();

// extern void FntFlush();
// extern void GsSetProjection(s32);

extern s32 buffer_i;
extern s32 fntStream;

extern s32 HWD0;
extern s32 VWD0;

extern EVECTOR* evmx[];
extern EVECTOR evbfad;

extern s32 CdSys__Unk00MemAdd;
extern s32 CdSys__Unk01MemAdd;


typedef void (*VSyncCb)();
struct VSyncCbList
{
	VSyncCb *cb;
	VSyncCb tail;
};
extern struct VSyncCbList vsync;