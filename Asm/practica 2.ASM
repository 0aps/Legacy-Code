
;- Hacer un programa que meta en la pila los valores 1, 2, 3, 4, 5 y 6 y los asigne a los registros eax, ebx, ecx, edx, edi y esi respectivamente con un pop

include 'C:\Documents and Settings\Owner\Desktop\Programming\Asm\Fasm\INCLUDE\win32ax.inc'

.code
codigo:

push 1
push 2
push 3
push 4
push 5
push 6
pop esi
pop edi
pop edx
pop ecx
pop ebx
pop eax

push 0;
call [ExitProcess]

.end codigo