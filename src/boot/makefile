
CC16?=/usr/bin/watcom/binl64/wcc
LD16?=/usr/bin/watcom/binl64/wlink

default:
	nasm -f obj stage2.s -o stage2.o

	$(CC16) -4 -d3 -s -wx -ms -zl -zq -fo=/home/brenner/code/Hermes/src/boot/main.o main.c
	$(LD16) NAME stage2.bin FILE \{ stage2.o main.o \} OPTION MAP=stage2.map @linker.lnk

