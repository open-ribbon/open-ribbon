#include "common.h"

#include "globals.h"

#include <psyq/LIBGTE.H>
#include <psyq/STDIO.H>

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001E4E4);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001E658);


// FontHack::Dtor
INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001E744);
/*void func_8001E744() 
{
    FontHack__Unk00(FontHack_Instance, 2);
    if (&vsync_cb_end - &vsync_cb)
        MemorySys__Free(&vsync_cb); // MemorySys__Free
}*/

// *FontHack::Ctor
INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001E798);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001E7E8);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001E9B0);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001E9FC);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001EA5C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001EBB4);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001EBD4);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001EC08);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001EC74);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001ED44);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001ED6C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001EFEC);

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
INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001F048);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001F0A4);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001F0D4);

void AudioSys__QuitSpu() {
    VideoSys__RemoveVSyncCB(&AudioSys__CallBack);
    UnknownFunction00();
    SpuQuit();
}
// INCLUDE_ASM("asm/game/nonmatchings/5CE4", AudioSys__QuitSpu);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001F13C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001F1D8);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001F42C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001F57C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001F5E4);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001F608);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001F628);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001F6F0);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001F74C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001F7F4);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001F86C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001F8E8);

s32 AudioSys__IsTransferCompleted(s32 arg0)
{
    return SpuIsTransferCompleted(arg0 != 0) != 0;
}
// INCLUDE_ASM("asm/game/nonmatchings/5CE4", AudioSys__IsTransferCompleted);

/* FIXME:
void func_8001F92C(s32 int* arg0, char* arg1) {
    signed int sndBuf;

    sndBuf = arg0[5];
    arg0[6] = &unkVar;
    if ( sndBuf >= 0 )
        SpuFree(sndBuf);
    func_8001F6F0(arg0, arg1); // <- sub is only in ida, i renamed it to func
}
*/
INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001F92C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001F980);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", UnknownFunction00);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001FA7C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001FB48);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001FB8C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001FC18);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001FE34);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8001FE8C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", AudioSys__CallBack);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80020004);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80020020);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80020098);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800200AC);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800200E4);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80020168);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800201C4);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800202C0);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8002038C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800203B8);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80020558);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800205FC);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800206D4);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80020728);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800207C4);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800207D0);

void func_800208BC(void) {}

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800208C4);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80020920);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80020AE4);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80020BA8);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800211D4);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8002146C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800214E8);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8002157C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80021608);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800216FC);

void func_80021758(void) {}

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80021760);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8002184C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800218C4);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80021968);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80021988);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80021A50);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80021A84);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80021AC0);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80021BE8);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80021C84);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80021CD0);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80021D9C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80021E6C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80021EF4);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80022044);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80022094);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80022138);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80022184);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80022210);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80022514);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8002254C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80022594);

void func_80022658(void) {}

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80022660);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80022824);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80022968);

void func_80022A58(void) {}

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80022A60);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80022C80);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80022CDC);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80022D78);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80022D9C);

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

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8002310C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80023174);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8002317C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800231A8);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800231C4);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800231F4);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80023210);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80023220);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800232A0);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800232D0);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80023388);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", main);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80023A7C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80023A88);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80023A94);

void func_80023AF0(void) {}

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80023AF8);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80023B08);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80023B14);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80023B20);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80023C2C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80023D38);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800245CC);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800246EC);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80024820);

void func_8002487C(void) {}

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80024884);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80024A48);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80024CC4);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80024D40);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80024DBC);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80024F8C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80025330);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80025584);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80025590);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80025604);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800256C4);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800256CC);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800258B0);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80025954);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80025B18);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80025B34);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80025B3C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80025B68);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80025D1C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80025DC0);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80025EBC);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80025F44);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800262B4);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8002663C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80026834);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80026940);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800269A4);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80026A10);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80026AA0);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80026CB8);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80026D78);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80026E08);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80026E64);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80026ED0);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80026F5C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80027000);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80027090);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800270DC);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80027104);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800271A0);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80027340);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80027394);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800274EC);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80027570);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_80027578);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8002758C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800275BC);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_8002780C);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800278BC);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800278EC);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800278F8);

INCLUDE_ASM("asm/game/nonmatchings/5CE4", func_800279E4);
