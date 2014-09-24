    ; mDrinky
include 'C:\Documents and Settings\Owner\Desktop\Programming\Asm\Fasm\INCLUDE\win32ax.inc'

    .data
	    cadena	    db 'La magia del ASM',0
    .code
    start:
	    push 0
	    push 0
	    push cadena
	    push 0
     
	    push salir
     
	    push [MessageBoxA]
     
	    ret
     
	    salir:
	    leave
	    ret
     
    .end start
