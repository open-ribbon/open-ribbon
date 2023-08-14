# binaries
BUILD 			:= sces028
GAME 			:= vib-ribbon
MAINT 			:= MAIN_T

# compilers
CROSS           := mipsel-linux-gnu-
AS              := $(CROSS)as
CC              := ./bin/cc1-psx
LD              := $(CROSS)ld
CPP				:= $(CROSS)cpp
OBJCOPY         := $(CROSS)objcopy
AS_FLAGS        += -Iinclude -march=r3000 -mtune=r3000 -no-pad-sections -O1
CC_FLAGS        += -mips1 -mcpu=3000 -quiet -G4 -Wall -fno-builtin -mno-abicalls -funsigned-char -O2
CPP_FLAGS       += -Iinclude -undef -Wall -lang-c -fno-builtin -gstabs
CPP_FLAGS       += -Dmips -D__GNUC__=2 -D__OPTIMIZE__ -D__mips__ -D__mips -Dpsx -D__psx__ -D__psx -D_PSYQ -D__EXTENSIONS__ -D_MIPSEL -D_LANGUAGE_C -DLANGUAGE_C

ifdef PERMUTER
CPP_FLAGS       += -DPERMUTER
endif

# directories
ASM_DIR 		:= asm
SRC_DIR 		:= src
INCLUDE_DIR 	:= include
BUILD_DIR 		:= build
CONFIG_DIR 		:= config
TOOLS_DIR 		:= tools

# files
VIBRI_ASM_DIRS   := $(ASM_DIR)/game $(ASM_DIR)/game/data
VIBRI_SRC_DIRS   := $(SRC_DIR)/game
VIBRI_S_FILES    := $(foreach dir,	$(VIBRI_ASM_DIRS), 	$(wildcard $(dir)/*.s)) \
					$(foreach dir,	$(VIBRI_ASM_DIRS), 	$(wildcard $(dir)/**/*.s))
VIBRI_C_FILES    := $(foreach dir,	$(VIBRI_SRC_DIRS), 	$(wildcard $(dir)/*.c)) \
					$(foreach dir,	$(VIBRI_SRC_DIRS), 	$(wildcard $(dir)/**/*.c))
VIBRI_O_FILES    := $(foreach file,	$(VIBRI_S_FILES), 	$(BUILD_DIR)/$(file).o) \
					$(foreach file,	$(VIBRI_C_FILES), 	$(BUILD_DIR)/$(file).o)
VIBRI_TARGET     := $(BUILD_DIR)/$(GAME)

# tools
PYTHON          := python3
SPLAT_DIR       := $(TOOLS_DIR)/splat
SPLAT_APP       := $(SPLAT_DIR)/split.py
SPLAT           := $(PYTHON) $(SPLAT_APP)
ASMDIFFER_DIR   := $(TOOLS_DIR)/asm-differ
ASMDIFFER_APP   := $(ASMDIFFER_DIR)/diff.py
M2CTX_APP       := $(TOOLS_DIR)/m2ctx.py
M2CTX           := $(PYTHON) $(M2CTX_APP)
M2C_DIR         := $(TOOLS_DIR)/m2c
M2C_APP         := $(M2C_DIR)/m2c.py
M2C             := $(PYTHON) $(M2C_APP)
M2C_ARGS		:= -P 4
MASPSX_DIR		:= $(TOOLS_DIR)/maspsx
MASPSX_APP		:= $(MASPSX_DIR)/maspsx.py
MASPSX			:= $(PYTHON) $(MASPSX_APP)
MASPSX_ARGS		:= --no-macro-inc --expand-div

define list_src_files
		$(foreach dir, $(ASM_DIR)/game,			$(wildcard $(dir)/**.s))
		$(foreach dir, $(ASM_DIR)/game/data,	$(wildcard $(dir)/**.s))
		$(foreach dir, $(SRC_DIR)/game,			$(wildcard $(dir)/**.c))
endef

define list_o_files
		$(foreach file, $(call list_src_files), $(BUILD_DIR)/$(file).o)
endef

define link
		$(LD) -o $(2) \
			-Map $(BUILD_DIR)/$(1).map \
			-T $(1).ld \
			-T $(CONFIG_DIR)/undefined_syms_auto.$(BUILD).$(1).txt \
			-T $(CONFIG_DIR)/undefined_funcs_auto.$(BUILD).$(1).txt \
			--no-check-sections \
			-nostdlib \
			-s
endef

all: build check
build: vib-ribbon
clean:
		git clean -fdx asm/
		git clean -fdx $(BUILD_DIR)
		git clean -fdx config/
		git clean -fx
format:
		clang-format -i $$(find $(SRC_DIR)/ -type f -name "*.c")
		clang-format -i $$(find $(INCLUDE_DIR)/ -type f -name "*.h")
check:
		sha1sum --check sces028.sha
expected: check
		rm -rf expected/build
		cp -r build expected/
		
MAIN_T.elf: $(VIBRI_O_FILES)
		$(LD) -o $@ \
		-Map $(VIBRI_TARGET).map \
		-T $(GAME).ld \
		-T $(CONFIG_DIR)/undefined_syms_auto.$(BUILD).$(GAME).txt \
		--no-check-sections \
		-nostdlib \
		-s
		
vib-ribbon: $(BUILD_DIR)/MAIN_T.EXE
$(BUILD_DIR)/MAIN_T.EXE: $(BUILD_DIR)/$(MAINT).elf
		$(OBJCOPY) -O binary $(BUILD_DIR)/$(MAINT).elf $@
$(BUILD_DIR)/$(MAINT).elf: $(call list_o_files)
		$(call link,vib-ribbon,$@)
		
extract: require-tools
		$(SPLAT) $(CONFIG_DIR)/splat.sces028.yml
$(CONFIG_DIR)/symbols.%.txt:

decompile: $(M2C_APP)
		$(M2CTX) src/game/4D58.c
		$(M2C) $(M2C_ARGS) --target mipsel-gcc-c --context ctx.c asm/game/nonmatchings/4D58/$(FUNC).s
	
require-tools: $(SPLAT_APP) $(ASMDIFFER_APP)
update-dependencies: require-tools $(M2CTX_APP) $(M2C_APP)
		pip3 install -r $(TOOLS_DIR)/requirements.txt

$(SPLAT_APP):
		git submodule init $(SPLAT_DIR)
		git submodule update $(SPLAT_DIR)
		pip3 install -r $(SPLAT_DIR)/requirements.txt
$(ASMDIFFER_APP):
		git submodule init $(ASMDIFFER_DIR)
		git submodule update $(ASMDIFFER_DIR)
$(M2CTX_APP):
		curl -o $@ https://raw.githubusercontent.com/ethteck/m2ctx/main/m2ctx.py
$(M2C_APP):
		git submodule init $(M2C_DIR)
		git submodule update $(M2C_DIR)
		python3 -m pip install --upgrade pycparser
$(MASPSX_APP):
		git submodule init $(MASPSX_DIR)
		git submodule update $(MASPSX_DIR)
		
$(BUILD_DIR)/%.s.o: %.s
	$(AS) $(AS_FLAGS) -o $@ $<
$(BUILD_DIR)/%.bin.o: %.bin
	$(LD) -r -b binary -o -Map %.map $@ $<
$(BUILD_DIR)/%.c.o: %.c $(MASPSX_APP)
	$(CPP) $(CPP_FLAGS) $< | $(CC) $(CC_FLAGS) | $(MASPSX) $(MASPSX_ARGS) | $(AS) $(AS_FLAGS) -o $@

SHELL = /bin/bash -e -o pipefail

.PHONY: all, clean, format, check, expected
.PHONY: vib-ribbon
.PHONY: extract
.PHONY: require-tools, update-dependencies