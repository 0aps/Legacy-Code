include 'C:\Documents and Settings\Owner\Desktop\Programming\Asm\Fasm\INCLUDE\win32ax.inc'

;- Hacer un programa que halle la media de los valores 7, 8, 5, 2 ,9 ,1 ,0  y 3

.code
codigo:

xor edx,edx
xor eax,eax

add eax,7
add eax,8
add eax,5
add eax,2
add eax,9
add eax,1
add eax,0
add eax,3

mov al,8
div eax

invoke ExitProcess, 0	   ; asi no tengo que meter los parametros con push (0) y luego llamar a call. lo hago directo :)

.end codigo






