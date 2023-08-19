#include "common.h"

#include <psyq/LIBGTE.H>

void exit(s32);
s32 printf(char* format, ...);

void SwEnterCriticalSection();
void SwExitCriticalSection();

void FntFlush();
void GsSetProjection(s32);
s32 SetDispMask(s32);
s32 VSync(s32);
s32 ResetGraph(s32);

void SpuQuit();
s32 SpuIsTransferCompleted(s32);

extern s32 buffer_i;
extern s32 fntStream;

extern s32 HWD0;
extern s32 VWD0;

extern EVECTOR* evmx[];
extern EVECTOR evbfad;

extern s32 CdSys__Unk00MemAdd;
extern s32 CdSys__Unk01MemAdd;

struct VSyncCb{};
extern struct VSyncCb vsync_cb;
extern struct VSyncCb vsync_cb_end;

typedef void (*VSyncCb)();
struct VSyncCbList
{
	VSyncCb *cb;
	VSyncCb tail;
};
extern struct VSyncCbList vsync;


typedef struct {} FAInstance;
extern struct FAInstance* FontHack_Instance;


extern int AudioSys__CallBack();
extern void VideoSys__RemoveVSyncCB(void *callback);


// No origin established yet
extern void UnkFunc00();