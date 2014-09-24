    format PE Console

include 'C:\Documents and Settings\Owner\Desktop\Programming\Asm\Fasm\INCLUDE\win32ax.inc'

    .data
	    inConsola		    dd ? ; Entrada a la consola
	    outConsola		    dd ? ; Salida de la consola
     
	    buffer		    dd ?
	    PintarEspacios	    dd ?
     
	    Salto		    db 13,10 ; '\n'
     
    .code
    start:
	    invoke SetConsoleTitle,"Dibuja una Piramide en FASM ;D"
     
	    invoke GetStdHandle,STD_OUTPUT_HANDLE
	    mov [outConsola],eax
     
	    invoke GetStdHandle,STD_INPUT_HANDLE
	    mov [inConsola],eax
     
     
	    invoke WriteConsole,[outConsola], "Introduce el alto de la piramide: ", 34, ebx, NULL
	    invoke ReadConsole,[inConsola],buffer,1,ebx,NULL
     
	    sub [buffer],0x30
     
	    mov ebx,[buffer]
	    mov [PintarEspacios],ebx
     
	    mov edi,1
     
	    .while [buffer] > 0
		   .while [PintarEspacios] > 1
			  ; Bucle que pinta los huecos en blanco.
			  dec [PintarEspacios]
			  invoke WriteConsole,[outConsola], " ", 1, ebx, NULL
		   .endw
     
		   dec ebx
     
		   mov [PintarEspacios],ebx
     
		   push edi
     
		   mov eax,2
		   mul edi
		   mov edi,eax
     
		   .while edi > 0
			    ; Pintamos la piramide
			    invoke WriteConsole,[outConsola], "*", 1, ebx, NULL
			    dec edi
		   .endw
     
		   pop edi
		   inc edi
     
		   ; Salto a otra linea
		   invoke WriteConsole,[outConsola], Salto, 2, ebx, NULL
     
		   dec [buffer]
	    .endw
     
	    ret
    .end start