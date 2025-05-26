#include "common.h"

#include <psyq/LIBGTE.H>

__attribute__((noreturn)) void exit(s32 arg0);
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

extern s32 HWD0;
extern s32 VWD0;

extern EVECTOR* evmx[];
extern EVECTOR evbfad;

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


typedef struct {
		s32  unk0;
		void *unk4;
} FAInstance; // size 0x8

extern FAInstance FontHack_Instance;


extern void AudioSys__InitSpu();
extern int AudioSys__CallBack();
extern void AudioSys__UnkFunc00();
extern int AudioSys__UnkFunc06(s16, s16, s16, s16, s32, s32, s32, s32, s32);
extern int AudioSys__UnkFunc08();


extern void VideoSys__AddVSyncCB(void *callback);
extern void VideoSys__RemoveVSyncCB(void *callback);

extern void MemorySys__free(void *addr);

extern void FontHack__UnkFunc00(FAInstance*, s32); // TO BE FIXED

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
    s16 unk2; // Lowers a bit without it, this variable exists
    s16 unk4;
} UnkStruct02;

typedef struct {
    s32 unk0;
    s32 unk4;
} UnkStruct03; // size unknown

typedef struct {
    void *unk0;
    u8  pad4[0x24];
    UnkStruct03 unk28;
} UnkStruct04; // size 0x30?

typedef struct {
  s16 unk0;
  u8  unk2;
} UnkStruct05;

typedef struct {
  u8 unk0;
  u8 pad1[0x4];
  u8 unk5;
  u8 unk6;
  u8 unk7;
} UnkStruct06;

typedef struct {
		s32 unk0;
		s32 unk4;
		s32 unk8;
} UnkStruct07;

typedef struct {
		s32 unk0;
		s32 unk4;
} UnkStruct08;

typedef struct {
    char pad1[0x48];
    s32 unk48;
} UnkStruct09;

typedef struct {
    s32 pad1[0x6];
    s32 unk6;
} UnkStruct10;

typedef struct {
    char pad1[0x2C];
    s32 unk2C;
} UnkStruct11;

typedef struct {
    s32 unk0;
    char pad1[0x10];
    s32 unk14;
} UnkStruct12;

typedef struct {
    char pad1[0x38];
    s32 unk38;
} UnkStruct13;

typedef struct {
    s32 unk0;
    char pad1[0xC - 0x4];
    s32 unkC;
} UnkStruct14;

typedef struct {
    char pad1[0x10];
    s32 unk10;
} UnkStruct15;

typedef struct {
    char pad1[0x18];
    s32 unk18;
    s32 unk1C;
} UnkStruct16;

// No origin established yet
extern UnkStruct01* UnkVar03;

extern s32 UnkVar05[24];

// ^ NO RELATIONS V
extern void UnkFunc00();
extern void UnkFunc01();
extern int  UnkFunc02();
extern void UnkFunc04();
extern void UnkFunc05();
