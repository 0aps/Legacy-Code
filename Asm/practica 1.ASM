;- Hacer un programa que inicialice a 2 el registro eax, a 5 el ebx y los sume quedando su resultdo en eax

include 'C:\Documents and Settings\Owner\Desktop\Programming\Asm\Fasm\INCLUDE\win32ax.inc'

.code

codigo:

mov eax,2
mov ebx,5

add eax,ebx

call [ExitProcess]

.end codigo