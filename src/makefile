



default:
	nasm -f bin boot/stage1/stage1.s -o bootloader.bin
	nasm -f bin kernel/kernel.s -o kernel.bin
	touch floppy.img
	
	truncate -s 1440k floppy.img
	dd if=/dev/zero of=floppy.img bs=512 count=2880
	mkfs.fat -F 12 -n "Balls" floppy.img
	dd if=bootloader.bin of=floppy.img conv=notrunc
	mcopy -i floppy.img kernel.bin "::kernel.bin"
	mcopy -i floppy.img boot/stage2/build/stage2.bin "::stage2.bin"


clean:
	rm bootloader.bin
	rm kernel.bin
	rm floppy.img
