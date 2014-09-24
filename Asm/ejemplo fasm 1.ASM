include 'C:\Documents and Settings\Owner\Desktop\Programming\Asm\Fasm\INCLUDE\win32ax.inc'
 
.data
   cuerpo db 'Hola mundo', 0
   titulo db 'xD', 0
 
.code
start:
 
   mov eax, NULL    ; Esto equivale a eax = 0
   mov ebx, 0x1234  ; Esto equivale a ebx = 1234 (el 0x de delante indica que es hexadecimal)
 
   push 0	    ; Observamos la pila para ver que pasa
   push titulo
   push cuerpo
   push 0
   call [MessageBoxA]
 
   mov edi, NULL
   mov di, 2
 
   push 0
   call [ExitProcess]
 
 
.end start