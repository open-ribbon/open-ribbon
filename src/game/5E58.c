#include "common.h"

#include "globals.h"

#include <psyq/LIBGTE.H>
#include <psyq/STDIO.H>


INCLUDE_ASM("asm/game/nonmatchings/5E58", func_8001E658);

// FontHack::Dtor
INCLUDE_ASM("asm/game/nonmatchings/5E58", FontHack__Dtor); // ALL BROKEN
/*void FontHack__Dtor()
{
    FontHack__UnkFunc00(FontHack_Instance, 2);
    if (((s32) (vsync.unk8 - (s32)vsync.cb) >> 2) != 0)
        MemorySys__free(vsync.cb);
}*/

// *FontHack::Ctor
INCLUDE_ASM("asm/game/nonmatchings/5E58", FontHack__Ctor);

INCLUDE_ASM("asm/game/nonmatchings/5E58", func_8001E7E8);

INCLUDE_ASM("asm/game/nonmatchings/5E58", func_8001E9B0);

INCLUDE_ASM("asm/game/nonmatchings/5E58", func_8001E9FC);

INCLUDE_ASM("asm/game/nonmatchings/5E58", func_8001EA5C);

INCLUDE_ASM("asm/game/nonmatchings/5E58", UnkFunc03);
/*void UnkFunc03()
{
    UnkVar00 = -1;
    UnkVar01 = UnkVar00;
    UnkVar02 = 0;
}*/

INCLUDE_ASM("asm/game/nonmatchings/5E58", func_8001EBD4);

INCLUDE_ASM("asm/game/nonmatchings/5E58", func_8001EC08);

INCLUDE_ASM("asm/game/nonmatchings/5E58", func_8001EC74);

INCLUDE_ASM("asm/game/nonmatchings/5E58", func_8001ED44);

INCLUDE_ASM("asm/game/nonmatchings/5E58", func_8001ED6C);

INCLUDE_ASM("asm/game/nonmatchings/5E58", func_8001EFEC);

/* CdSys__Unk00 [Error when implementing]
void func_8001F048(int *arg0)
{
    SwEnterCriticalSection();

    if (CdSys__Unk00MemAdd)
    {
        printf("Assertion failed: file \"%s\", line %d\n", "C:/psj/dev/locale/game/CdSys.cpp", 511);
        exit(1);
    }
    CdSys__Unk00MemAdd = arg0;
    SwExitCriticalSection();
}
*/
INCLUDE_ASM("asm/game/nonmatchings/5E58", func_8001F048);

INCLUDE_ASM("asm/game/nonmatchings/5E58", func_8001F0A4);
