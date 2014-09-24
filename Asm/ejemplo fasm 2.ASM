format PE console			;forma del programa

include 'C:\Documents and Settings\Owner\Desktop\Programming\Asm\Fasm\INCLUDE\win32ax.inc'
 
.data
	doble	 rd 4  ; Reservamos 4 dwords
	cadena	 rb 50 ; Reservamos 50 bytes
	palabra  rw 2  ; Reservamos 2 words
 
.code
start:
 
       mov [doble+4], 5
       leave
       ret
 
.end start 

