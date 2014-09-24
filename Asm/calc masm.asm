.386
.model flat, stdcall  ;32 bit memory model
option casemap :none  ;case sensitive

include windows.inc
include kernel32.inc
include msvcrt.inc

includelib kernel32.lib
includelib msvcrt.lib

.data
   lib db "msvcrt.dll"

.code
start:
   invoke LoadLibrary, offset lib

   push ebp
   mov ebp, esp
   xor dl, dl
	
   sub esp, 10h ; dejamos espacio en la pila para meter nuestra cadena

   mov byte ptr [ebp-0fh], 63h	; 'c'
   mov byte ptr [ebp-0eh], 61h	; 'a'
   mov byte ptr [ebp-0dh], 6Ch	; 'l'
   mov byte ptr [ebp-0ch], 63h	; 'c'
   mov byte ptr [ebp-0bh], 2Eh	; '.'
   mov byte ptr [ebp-0ah], 65h	; 'e'
   mov byte ptr [ebp-09h], 78h	; 'x'
   mov byte ptr [ebp-08h], 65h	; 'e'
   mov byte ptr [ebp-07h], dl	; 0x00

   lea eax, [ebp-0fh]	; cargamos la direccion que apunta a nuestra cadena
   push eax		; metemos la dirección de 'calc.exe' en la pila

   mov ebx, 77bf93c7h	; metemos en ebx el valor del offset de system 
			; (en mi maquina)
   call ebx		; llamamos a system y ejecuta nuestra shellcode
	
   invoke ExitProcess, 0
end start