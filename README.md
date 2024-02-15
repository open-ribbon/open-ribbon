[![image](https://github.com/open-ribbon/open-ribbon/assets/52961795/e189d94c-9d19-4ace-ae25-9f2c17e5b30b)](https://github.com/open-ribbon)


A WIP decompilation of **PAL** build of the PS1 game Vib-Ribbon (ビブリボン). <br>
The objective is to produce a free and open-source reverse-engineered version of the game. <br>

**Documentation** about this game and project can be **[found here.](https://github.com/open-ribbon/documentation)** <br>
Join our **[Discord](https://discord.gg/n5TPTBvGjE)** server to discuss the project.


## Decompilation Progress

| File name  | Progress | Description
|------------|----------|------------
| `MAIN_T.EXE` | ![progress](https://img.shields.io/endpoint?url=https://raw.githubusercontent.com/polybiusproxy/open-ribbon/gh-report/assets/progress-sces028.json) | Title screen
| `MAIN_K.EXE` | N/A | Kiosk—Tutorial level
| `MAIN_G.EXE` | N/A | Main menu and gameplay
| `SCES_028.73` | N/A | Module (.EXE) loader

## General info

Vib-Ribbon was written in C++, which was uncommon for games in the 90s, especially on the PSX.<br>
However, due to current limitations, this decompilation is written in C.

## How to build

Place all the necessary PSX executable files in the `iso` directory (e.g. `MAIN_G.EXE`) first.
If you don't currently have the executables needed to decompile the game, please follow [this guide](https://open-ribbon.github.io/documentation/#decompilation/file-ext/#extracting-from-biniso-file) on how to extract the files from your copy of Vib-Ribbon.

 1. Run `make extract` to generate the assembly files in the `asm/` directory
 1. Run `make` to compile the binaries in the `build/` directory

In case there are any changes in the `config/` folder, you might need to run `make clean` to reset the extraction.

Some non-matching functions are present in the source preprocessed by the macro `NON_MATCHING`. You can still compile the game binaries by running `CPP_FLAGS=-DNON_MATCHING make`. In theory, they might be logically equivalent in-game, but I cannot promise that. Few of them could match by tuning or changing the compiler.

#
## How to decompile

1. Run `make clean extract all expected` at least once
1. Look for a function which hasn't been successfully decompiled yet (eg. `INCLUDE_ASM("asm/game/nonmatchings/4D58", VideoSys__FlipBuffer);`)
1. Run `FUNC=VideoSys__FlipBuffer FILE=VideoSys make decompile` to dump the decompiled code on the console
1. Replace the `INCLUDE_ASM(...);` you targeted with the console output content
1. and invoke `python3 ./tools/asm-differ/diff.py -mwo VideoSys__FlipBuffer`

You will probably have some differences from your compiled code to the original; keep refactoring the code and move variables around until you have a 100% match.

There are a few tricks to make the process more streamlined:

1. Use [decomp.me](https://decomp.me/) with the vib-ribbon preset.
1. The “context” section of decomp.me, is provided by the previous command `make decompile` as mentioned in the how to decompile.
1. Use [decomp-permuter](https://github.com/simonlindholm/decomp-permuter) to solve some mismatches.
1. Use [this](https://github.com/mkst/sssv/wiki/Jump-Tables) and [this](https://github.com/pmret/papermario/wiki/GCC-2.8.1-Tips-and-Tricks) guide to understand how some compiler patterns work.
1. Use the `#ifndef NON_MATCHING` if your code is logically equivalent but you cannot yet fully match it.

#
## Troubleshooting

### Not getting an "OK" on Ubuntu 22.04

Debian>=12 and Ubuntu>=22.04 uses `binutils-mipsel-linux-gnu`>=2.38 which, for some unknown reasons, it generates broken binaries. You need to downgrade to 2.34 or 2.35 with the following:

```shell
curl -L -o binutils-mipsel-linux-gnu_2.35.2-2cross2_amd64.deb http://ftp.de.debian.org/debian/pool/main/b/binutils-mipsen/binutils-mipsel-linux-gnu_2.35.2-2cross2_amd64.deb
dpkg -i binutils-mipsel-linux-gnu_2.35.2-2cross2_amd64.deb
rm binutils-mipsel-linux-gnu_2.35.2-2cross2_amd64.deb
```

#
## Contributors

| Avatar | Username |
| ------ | -------- | 
| ![](https://avatars.githubusercontent.com/u/47796739?s=64) | [polybiusproxy](https://github.com/polybiusproxy)
| ![](https://avatars.githubusercontent.com/u/22226349?s=64) | [mkst](https://github.com/mkst)
| ![](https://i.imgur.com/vtsmp8m.png) 						 | [unclamped](https://github.com/unclamped) 
| ![](https://avatars.githubusercontent.com/u/70072571?s=64) | [sys128](https://github.com/sys128)
| ![](https://avatars.githubusercontent.com/u/119765865?s=64) | [AnOpenSauceDev](https://github.com/AnOpenSauceDev)
