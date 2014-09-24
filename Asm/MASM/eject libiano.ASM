;.186
.model tiny

Codigo segment 'code'
org 0100h
main: 
 mov ax, cs
 mov ds, ax 
   
 mov si, offset msg
 call prints
ret

putchar:
 pusha
   mov ah, 0Eh
   xor bh, bh
   int 10h
 popa
ret

prints:
 prints_bucle:
 lodsb
 cmp al, 0
 jz prints_fin
 call putchar
 jmp prints_bucle
 prints_fin:
ret

msg db "Esto es de verdad con la BIOS", 0

Codigo ends
End Main
