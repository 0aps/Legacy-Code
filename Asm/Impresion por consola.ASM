format PE console			;forma del programa
					;puede ser GUI o console
					;GUI no muestra la consola osea GUI :P
					;console console
					;DLL para dll

include 'C:\Documents and Settings\Owner\Desktop\Programming\Asm\Fasm\INCLUDE\win32ax.inc'

.data
 
    msgerror db 'No se a encontrado la consola',0
    tituloerror db 'Error',0
    tituloconsola db 'Drinky Console in Asm',0
    linea db 'Esta es mi consola!',0
    texto db 'Ya se creo.. :D',0
    hwnd dd ?
    escribe dd ?
    longitud dd ?
.code
start:
 
    invoke GetStdHandle, STD_OUTPUT_HANDLE
    cmp eax,0
    ja correcto
    jbe incorrecto

    incorrecto:
	invoke MessageBoxA,0,msgerror,tituloerror,MB_ICONERROR
	jmp fin
    correcto:
	mov [hwnd],eax
	invoke SetConsoleTitle,tituloconsola
	invoke lstrlen,linea
	mov [longitud],eax
	invoke WriteConsole, [hwnd], linea, [longitud], escribe, NULL	; Esta es la linea que creo que falla
	invoke MessageBoxA,0,texto,tituloconsola,MB_OK
 
	jmp fin


     fin:
	ret
 
.end start