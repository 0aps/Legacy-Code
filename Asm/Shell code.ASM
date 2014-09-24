include 'C:\Documents and Settings\Owner\Desktop\Programming\Asm\Fasm\INCLUDE\win32ax.inc'

.data

      dll db 'msvcrt.dll', 0


.code

start:

		push dll
		call [LoadLibrary]

		push ebp
		mov ebp,esp
		xor edi,edi
		push edi

		sub esp,04h

		mov byte  [ebp-08h],63h
		mov byte  [ebp-07h],6Dh
		mov byte  [ebp-06h],64h
		mov byte  [ebp-05h],2Eh
		mov byte  [ebp-04h],65h
		mov byte  [ebp-03h],78h
		mov byte  [ebp-02h],65h
		lea eax,  [ebp-08h]

		lea eax,[ebp-08h]
		push eax
		mov ebx,0x77bf8044

		call ebx

.end start