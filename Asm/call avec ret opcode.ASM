
include 'C:\Documents and Settings\Owner\Desktop\Programming\Asm\Fasm\INCLUDE\win32ax.inc'
     
    .data
	    cadena	    db 'La magia del ASM',0
    .code
    start:
	    db 0x68,0x00,0x00,0x00,0x00
	    db 0x68,0x00,0x00,0x00,0x00
	    push cadena
	    db 0x68,0x00,0x00,0x00,0x00
	    push salir
	    push [MessageBoxA]
	    db 0xC3
	    salir:
	    db 0xC9,0xC3
     
    .end start
