
GCC = gcc

SRC = $(wildcard src/*.c src/emulator/*.c src/pipeline/*.c)
OUT = build/CEMU.exe

INCLUDE = -ISDK1/include -Iinclude  
LIB = -LSDK1/lib 
LINK = -lSDL3 -lSDL3_image -lSDL3_mixer -lSDL3_ttf


W_FLAGS = -Wall -Werror -Wpedantic
OPT_FLAG = -O2 -s -DDEBUG -DSTDLIB_ALLOCATIONS
DEBUG_FLAG = -g -DDEBUG -DTRACK_ALLOCATIONS


default: debug_build run

all: json default


opt: opt_build run



json:
	@compiledb -n -- make debug_build



debug_build:
	@${GCC} -o ${OUT} ${SRC} -lSDK1_debug ${LINK} ${LIB} ${INCLUDE} ${W_FLAGS} ${DEBUG_FLAG}


opt_build:
	@${GCC} -o ${OUT} ${SRC} -lSDK1 ${LINK} ${LIB} ${INCLUDE} ${W_FLAGS} ${OPT_FLAG}


run:
	@${OUT}





