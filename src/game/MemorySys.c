#include "common.h"

#include "globals.h"

#include <psyq/LIBGTE.H>
#include <psyq/STDIO.H>


INCLUDE_ASM("asm/game/nonmatchings/MemorySys", MemorySys__Init);

void func_80021758(void) {} // MemorySys__Stub [Empty]

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", MemorySys__Info);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", MemorySys__DumpUsage);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", MemorySys__DumpHead);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", MemorySys__Init01);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", MemorySys__malloc);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", MemorySys__free);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", MemorySys__CountHeapFree);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80021AC0);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", cbready);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", cbsync);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80021CD0);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", FileSys__Read);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80021E6C);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80021EF4);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", PackedFiles__Unk00);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", PackedFiles__Init);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", PackedFiles__Quit);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", PackedFiles__Load);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", FileSys__LoadFile);

void FileSys__DeleteFile(PakFile pf)
{
    if (pf.size != 0 && pf.next != NULL)
        delete(pf);
}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", FileSys__Unknown);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", FileSys__Unk00);

void func_80022658(void) {}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80022660);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80022824);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80022968);

void func_80022A58(void) {}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80022A60);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80022C80);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80022CDC);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80022D78);

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

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80023174);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_8002317C);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_800231A8);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_800231C4);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_800231F4);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80023210);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80023220);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_800232A0);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_800232D0);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80023388);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", main);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80023A7C);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80023A88);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80023A94);

void func_80023AF0(void) {}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80023AF8);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80023B08);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80023B14);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80023B20);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80023C2C);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80023D38);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_800245CC);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_800246EC);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80024820);

void func_8002487C(void) {}

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80024884);

// part of TmdLineObj.cpp
INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80024A48);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80024CC4);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80024D40);

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

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80025B18);

void TmdLineObj__Unk12(s32* arg0) { *arg0 = 0; }

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80025B3C);

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

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80027090);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_800270DC);

INCLUDE_ASM("asm/game/nonmatchings/MemorySys", func_80027104);
