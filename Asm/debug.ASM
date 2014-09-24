format PE GUI 4.0
entry start

include 'C:\Documents and Settings\Owner\Desktop\Programming\Asm\Fasm\INCLUDE\win32ax.inc'

    SiDbg db 'Hay Debugger',0
    NoDbg db 'No hay Debugger',0

start:
	mov eax,dword[fs:18h]
	mov eax,dword[eax+30h]
	mov bl,byte[eax+2]

	.if bl = 1
	    invoke MessageBoxA,0,SiDbg,0,0
	.else
	    invoke MessageBoxA,0,NoDbg,0,0
	.endif
	ret
data import
	library user32,'user32.dll'

	import user32,MessageBoxA,'MessageBoxA'

end data