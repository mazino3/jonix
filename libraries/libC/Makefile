INCLUDEDIR := include
OBJDIR := ../build/libC
SYSROOT := ../../sysroot
INCLUDEDEST := $(SYSROOT)/usr/include
LIBDEST := $(SYSROOT)/usr/lib

CC = ../../toolchain/local/x86_64/bin/x86_64-jonix-elf-gcc
AR = ../../toolchain/local/x86_64/bin/x86_64-jonix-elf-ar
LOGGING = -Wall -Wextra -Wpedantic -Werror
CFLAGS = --sysroot=$(SYSROOT) -O2 -g -shared -fPIC -ffreestanding -fshort-wchar -mno-red-zone -fno-exceptions -I$(INCLUDEDEST) $(LOGGING)

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

SRC = $(call rwildcard,.,./*.c)
OBJS = $(patsubst ./%.c, $(OBJDIR)/%.o, $(SRC))

libC: dirs headers libC.a sysroot-install

libC.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)
	@ mv libC.a $(OBJDIR)/libC.a

$(OBJDIR)/%.o: ./%.c
	@ echo !==== COMPILING $^
	@ mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@

dirs:
	mkdir -p $(INCLUDEDEST)
	mkdir -p ../../sysroot/usr/include
	mkdir -p ../../sysroot/usr/lib

headers:
	cp -R --preserve=timestamps $(INCLUDEDIR)/. $(INCLUDEDEST)

sysroot-install:
	cp -R --preserve=timestamps $(OBJDIR)/libC.a $(LIBDEST)

setup:
	@ mkdir -p $(OBJDIR)
