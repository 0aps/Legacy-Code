include 'C:\Documents and Settings\Owner\Desktop\Programming\Asm\Fasm\INCLUDE\win32ax.inc'

;global start

 .data
	hola	db	"Hola , mundo!", 11
	length	equ	$-hola

 .code

start:
	mov eax, 4		; escribe en el archivo
	mov ebx, 1		; manejador de STDOUT 
	mov ecx, hola	    ; el mensaje
	mov edx, length ; tamanio del mensaje
	int 80h 		; ejecuta la llamada al sistema

	xor ebx, ebx		; envia 0 como codigo de salida
	mov eax, 1		; termina proceso
	int 80h 		; ejecuta la llamada al sistema


.end start