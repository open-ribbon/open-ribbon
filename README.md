# open-ribbon
This repository is dedicated to the decompilation of the PS1 game Vib-Ribbon (ビブリボン)  [PAL]

## How to build

 1. Run `make extract` to generate the assembly files in the `asm/` directory
 1. Run `make all` to compile the binaries in the `build/` directory

In case there are any changes in the `config/` folder, you might need to run `make clean` to reset the extraction.

Some non-matching functions are present in the source preprocessed by the macro `NON_MATCHING`. You can still compile the game binaries by running `CPP_FLAGS=-DNON_MATCHING make`. In theory they might be logically equivalent in-game, but I cannot promise that. Few of them could match by tuning or changing the compiler.

#
## How to decompile

1. Run `make clean extract all expected` at least once
1. Look for one of those function which hasn't successfully decompiled yet (eg. `INCLUDE_ASM("asm/game/nonmatchings/4D58", VideoSys__FlipBuffer);`)
1. Run `FUNC=VideoSys__FlipBuffer make decompile` to dump the decompiled code on the console
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
| ![](https://avatars.githubusercontent.com/u/52961795?s=64) | [xPythh](https://github.com/xPythh)

You can join our [Discord server](https://discord.gg/n5TPTBvGjE) to discuss the project.
