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

void free(void *ptr);

void PadStartCom();

void SsUtReverbOff();

extern s32 buffer_i;
extern s32 fntStream;

extern s32 HWD0;
extern s32 VWD0;

extern EVECTOR* evmx[];
extern EVECTOR evbfad;

extern s32 CdSys__Unk00MemAdd;
extern s32 CdSys__Unk01MemAdd;

extern s32 voice_bit;


struct VSyncCb {};
extern struct VSyncCb vsync_cb;
extern struct VSyncCb vsync_cb_end;

typedef void (*VSyncCb)();
struct VSyncCbList
{
	VSyncCb *cb;
	VSyncCb tail;
	s32 unk8;
};
extern struct VSyncCbList vsync;


typedef struct {} FAInstance;
extern struct FAInstance FontHack_Instance;


extern void AudioSys__InitSpu();
extern int AudioSys__CallBack();
extern void AudioSys__UnkFunc00();
extern int AudioSys__UnkFunc06(s16, s16, s16, s16, s32, s32, s32, s32, s32);
extern int AudioSys__UnkFunc08();


extern void VideoSys__AddVSyncCB(void *callback);
extern void VideoSys__RemoveVSyncCB(void *callback);

extern void MemorySys__free(void *addr);

extern void FontHack__UnkFunc00(struct FAInstance*, s32); // TO BE FIXED

typedef struct PakFile PakFile;
struct PakFile {
    PakFile *next;
    s32 unk4;
    s32 size;
};
s32 delete(PakFile);


typedef struct {
    char Dummy_Data[0x18]; // To force Unk18 to be at byte N°18
    s32 unk18;
} UnkStruct00;

typedef struct {
    void *unk0;
} UnkStruct01;

typedef struct
{
    s16 unk0;
    s16 unk1; // Lowers a bit without it, this variable exists
    s16 unk4;
} UnkStruct02;

typedef struct {
  s16 unk0;
  u8  unk2;
} UnkStruct05;

// No origin established yet
volatile s32 UnkVar00;
volatile s32 UnkVar01;
volatile s32 UnkVar02;
extern UnkStruct01* UnkVar03;
extern s16 UnkVar04;
extern s32 UnkVar05[24];
extern s32 UnkVar06;
extern s32 UnkVar07;
// ^ NO RELATIONS V
extern void UnkFunc00();
extern void UnkFunc01();
extern int  UnkFunc02();
extern void UnkFunc04();
extern void UnkFunc05();
