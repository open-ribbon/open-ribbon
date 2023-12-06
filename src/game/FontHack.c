#include "common.h"

#include "globals.h"

#include <psyq/LIBGTE.H>
#include <psyq/STDIO.H>

// NOTE: -G0 override for this file

FAInstance FontHack_Instance = {0, 0};
char D_80047EDC[2] = "\n\n";

INCLUDE_ASM("asm/game/nonmatchings/FontHack", func_8001E658);

// FontHack::Dtor
void FontHack__Dtor()
{
    FontHack__UnkFunc00(&FontHack_Instance, 2);
    if (((s32) (vsync.unk8 - (s32)vsync.cb) >> 2) != 0)
        MemorySys__free(vsync.cb);
}

// *FontHack::Ctor
INCLUDE_ASM("asm/game/nonmatchings/FontHack", FontHack__Ctor);
