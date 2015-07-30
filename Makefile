ASM=nasm
ASMFLAGS= -f elf64
CC=g++
CFLAGS= -std=c++11 -Wall -m64 -march=native
LIBS= -lopencv_core -lopencv_highgui

.PHONY: all clean debug

all: CFLAGS+=-D NDEBUG -O3
all: greyscale	

greyscale: main.cpp greyscale.cpp
	$(CC) $(CFLAGS) $(LIBS) $^ -o greyscale

clean:
	rm greyscale
	rm -rf out

debug: CFLAGS+=-g
debug: ASMFLAGS+=-g -F dwarf

debug: greyscale
