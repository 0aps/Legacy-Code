Format PE console

;include 'C:\Asm\Fasm\INCLUDE\win32ax.inc'

include 'C:\Documents and Settings\Owner\Desktop\Programming\Asm\Fasm\INCLUDE\win32ax.inc'

.data

 escribe dd ?, 0
 lee	 dd ?, 0
 hwnd	 dd ?, 0

.code

start:

invoke GetStdHandle, STD_INPUT_HANDLE
mov [hwnd], eax

invoke ReadConsole, [hwnd], escribe, 30, lee, NULL
invoke MessageBoxA,0,escribe,'titulo',MB_OK

ret

.end start
