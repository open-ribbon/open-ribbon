#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H

#ifndef PERMUTER

#ifndef INCLUDE_ASM

#define INCLUDE_ASM(FOLDER, NAME)                                              \
  __asm__(".section .text\n"                                                   \
          "\t.align\t2\n"                                                      \
          "\t.globl\t" #NAME "\n"                                              \
          "\t.ent\t" #NAME "\n" #NAME ":\n"                                    \
          ".include \"" FOLDER "/" #NAME ".s\"\n"                              \
          "\t.set reorder\n"                                                   \
          "\t.set at\n"                                                        \
          "\t.end\t" #NAME);

#define INCLUDE_RODATA(FOLDER, NAME) \
__asm__( \
    ".section .rodata\n" \
    "\t.include \""FOLDER"/"#NAME".s\"\n" \
    ".section .text" \
)

#endif

#else
#define INCLUDE_ASM(FOLDER, NAME)
#define INCLUDE_RODATA(FOLDER, NAME)
#endif

#endif
