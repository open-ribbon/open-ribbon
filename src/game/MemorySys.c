#include "common.h"

#include "globals.h"

#include <psyq/LIBGTE.H>
#include <psyq/STDIO.H>


INCLUDE_ASM("asm/game/nonmatchings/MemorySys", MemorySys__Init);

void func_80021758(void) {} // MemorySys__Stub [Empty]

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", MemorySys__Info);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", MemorySys__DumpUsage);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", MemorySys__DumpHead);

void MemorySys__Init01(void) {
    MemorySys__Init();
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", MemorySys__malloc);

#ifndef NON_MATCHING
INCLUDE_ASM("asm/game/nonmatchings/MemorySys", MemorySys__free);
#else
void MemorySys__free(s32 address) {
    if (address != 0) {
        func_8003439C();
        freeAmount += 1;
    }
}
#endif

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", MemorySys__CountHeapFree);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80021AC0);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", cbready);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", cbsync);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80021CD0);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", FileSys__Read);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80021E6C);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80021EF4);

extern s32 D_800194A4[];

s32 PackedFiles__Unk00(s32 arg0, s32 *arg1, s32 arg2) {
    s32 c;
    s32 v;

    if (*arg1 >= 5) {
        if (arg2 == 0) {
            return 0;
        }
        *arg1 = 0;
    }
    c = *arg1;
    v = D_800194A4[c];
    *arg1 = c + 1;
    return arg0 | v;
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", PackedFiles__Init);

extern PakFile D_8003FE68;

void PackedFiles__Quit(void) {
    PakFile pf = D_8003FE68;
    FileSys__DeleteFile(pf);
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", PackedFiles__Load);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", FileSys__LoadFile);

void FileSys__DeleteFile(PakFile pf)
{
    if (pf.size != 0 && pf.next != NULL)
        delete(pf.next);
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", FileSys__Unknown);

typedef struct {
    char *start;
    char *end;
} FileSysStr0;

extern void *func_8003424C(void *, const void *, int); /* memcpy */
extern void *func_80030BF4(void *, const void *, int); /* memmove */

FileSysStr0* FileSys__Unk00(FileSysStr0* self, char* new_start, char* new_end) {
    char *curEnd;
    char *newEnd;

    if ((unsigned int)(self->end - self->start) >= (unsigned int)(new_end - new_start)) {
        func_8003424C(self->start, new_start, new_end - new_start);

        curEnd = self->end;
        newEnd = self->start + (new_end - new_start);

        if (newEnd != curEnd) {
            func_80030BF4(newEnd, curEnd, 1);
            self->end -= (curEnd - newEnd);
        }
    } else {
        func_8003424C(self->start, new_start, self->end - self->start);
        func_80022660(self, new_start + (self->end - self->start), new_end, 0);
    }

    return self;
}

void func_80022658(void) {}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80022660);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80022824);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80022968);

void func_80022A58(void) {}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80022A60);

extern int (*D_80048028)();
extern char D_80019494[]; // "out of memory\n"

void func_80022C80(s32 arg0) {
    int (*var_v0)();

    do {
        var_v0 = D_80048028;
        if (var_v0 == NULL) {
            printf(&D_80019494);
            exit(1);
        }
        var_v0();
    } while (MemorySys__malloc(arg0) == 0);
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80022CDC);

u8* func_80022D78(u8* dest, s32 count, u8* value) {
    // memset-like function
    u8* ptr = dest;

    while (count != 0) {
        *ptr++ = *value;
        count--;
    }

    return ptr;
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80022D9C);

void VideoSys__SetProjection(s32 h)
{
	s32 proj;

	s32 factor = 360;
	s32 scale = 2;

	s32 a = rcos((h / factor) / scale);
	s32 b = rsin((h / factor) / scale);

	proj = (((a * VWD0) / b) >> 1) * HWD0;
	proj = (proj * 3) / (VWD0 * 4);

	GsSetProjection(proj);
	InitClip(&evbfad, HWD0 + 8, VWD0 + 8, proj, proj / 2, 0xFFFF);
}

s32 func_80023060(SVECTOR* vec1, SVECTOR* vec2)
{
    if (Clip3F(vec1, vec2, vec2, evmx) >= 2)
    {
        *vec1 = evmx[0]->v;
        *vec2 = evmx[1]->v;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_8002310C);

void func_80023174(s32* arg0) {
    *arg0 = 0;
}

void func_8002317C(UnkStruct09* arg0, int arg1) {
    arg0->unk48 = func_800231F4(arg1);
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_800231A8);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_800231C4);

extern int D_8003FE8C;

s32 func_800231F4(s32 arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (arg0 != &D_8003FE8C) {
        var_v1 = arg0;
    }
    return var_v1;
}

s32 func_80023210(s32 value) {
    // rounds up a value to the nearest multiple of 4
    return (value + 3) & ~3;
}

#ifndef NON_MATCHING
INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80023220);
#else
s32 func_80023220(s8* first_string, s8* second_string) {
    // https://decomp.me/scratch/MVnJF
    s8 current_character = *first_string;
    s8 other_character = *second_string;

    // uppercase to lowercase (A-Z)
    if ((u32)(current_character - 65) < 26) {
        current_character += 0x20;
    }
    if ((u32)(other_character - 65) < 26) {
        other_character += 0x20;
    }

    // compare characters?
    if (current_character < other_character) {
        return -1;
    }
    if (other_character < current_character) {
        return 1;
    }
    
    if (current_character != 0) {
        return func_80023220(first_string + 1, second_string + 1);
    }
    
    return 0;
}
#endif

s32 func_800232A0(s32 arg0) {
    return arg0 + func_80023210(func_80035C6C() + 1);
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_800232D0);

s32 func_80023388(void) {
    s32 temp_return_value;

    temp_return_value = func_800232D0();

    if (temp_return_value != 0) {
        return func_800232A0(temp_return_value); 
    }

    return 0;
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", main);

s32 func_80023A7C(s32 arg0, s32 arg1, s32 arg2) {
    return arg0 + (arg2 - arg1);
}

s32 func_80023A88(s32 arg0, s32 arg1, s32 arg2) {
    return arg0 + (arg2 - arg1);
}

extern char D_800195F4[]; // "out of memory\n"

void func_80023A94(s32 arg0) {
    int (*var_v0)();

    do {
        var_v0 = D_80048028;
        if (var_v0 == NULL) {
            printf(&D_800195F4);
            exit(1);
        }
        var_v0();
    } while (MemorySys__malloc(arg0) == 0);
}

void func_80023AF0(void) {}

s32* func_80023AF8(s32* arg0) {
    arg0[30] = 0; /* 0x78 */
    arg0[38] = 0; /* 0x98 */
    return arg0;
}

s32* func_80023B08(s32* arg0) {
    *arg0 = 0;
    return arg0;
}

s32* func_80023B14(s32* arg0) {
    *arg0 = 0;
    return arg0;
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80023B20);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80023C2C);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80023D38);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_800245CC);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_800246EC);

extern int (*D_80048028)();
extern char D_80019704[]; // "out of memory\n"

void func_80024820(s32 arg0) {
    int (*var_v0)();

    do {
        var_v0 = D_80048028;
        if (var_v0 == NULL) {
            printf(&D_80019704); // "out of memory\n"
            exit(1);
        }
        var_v0();
    } while (MemorySys__malloc(arg0) == 0);
}

void func_8002487C(void) {}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80024884);

// part of TmdLineObj.cpp
INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80024A48);

typedef struct {
    s32 unk0;
    char pad4[8];
    void *unkC;
    char pad10[0x1C];
    void *unk2C;
} UnkStruct17;

void func_80024CC4(UnkStruct17* arg0, s32 arg1) {
    if (arg0->unkC != NULL) {
        delete(arg0->unkC);
    }
    if (arg0->unk0 != 0 && arg0->unk2C != NULL) {
        delete(arg0->unk2C);
    }
    if (arg1 & 1) {
        free(arg0);
    }
}

typedef struct {
    char pad0[0x20];
    s32 idx0;
    s32 idx1;
    s32 idx2;
    SVECTOR *vbuf;
} TriObj;

s32 func_80024D40(TriObj* arg0) {
    long sxy0, sxy1, sxy2;
    long flag;

    RotTransPers3(
        arg0->vbuf + arg0->idx0,
        arg0->vbuf + arg0->idx1,
        arg0->vbuf + arg0->idx2,
        &sxy0, &sxy1, &sxy2, &flag, &flag);

    return (u32)NormalClip(sxy0, sxy1, sxy2) >> 31;
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80024DBC);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80024F8C);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80025330);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80025584);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80025590);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80025604);

void UnkFunc05(UnkStruct00 *arg0, s32 arg1)
{
    arg0->unk18 = arg1;
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_800256CC);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_800258B0);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80025954);

extern int D_8003FE8C;

s32 func_80025B18(s32 arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (arg0 != &D_8003FE8C) {
        var_v1 = arg0;
    }
    return var_v1;
}

void TmdLineObj__Unk12(s32* arg0) { *arg0 = 0; }

void func_80025B3C(UnkStruct09* arg0, int arg1) {
    arg0->unk48 = func_80025B18(arg1);
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80025B68);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80025D1C);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80025DC0);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80025EBC);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80025F44);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_800262B4);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_8002663C);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80026834);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80026940);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_800269A4);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80026A10);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80026AA0);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80026CB8);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80026D78);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80026E08);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80026E64);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80026ED0);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80026F5C);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80027000);

typedef struct {
    char pad0[0xC];
    s32 unkC;
} F800270XXEntry;

typedef struct {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x4];
    F800270XXEntry *unkC;
} F800270XXStruct;

extern s32 AudioSys__UnkFunc09();

s32 func_80027090(F800270XXStruct *arg0) {
    if (arg0->unkC[arg0->unk4].unkC == -97) {
        return 0;
    }
    return AudioSys__UnkFunc09(0) ^ 1;
}

extern s32 func_8001F5E4(s16);

void func_800270DC(s32 *arg0) {
    arg0[1] = 0;
    arg0[0] = 0;
    func_8001F5E4(0);
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80027104);