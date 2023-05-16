org 0x7c00
bits 16

jmp main


main:
	mov ax, 0 ;waits for keyboard input
	int 16h

	mov ah, 0x0e ;print character
	int 10h
	jmp main




times 510-($-$$) db 0
dw 0xaa55
