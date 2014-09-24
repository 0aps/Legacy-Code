Format PE GUI 4.0
entry start
include 'C:\Documents and Settings\Owner\Desktop\Programming\Asm\Fasm\INCLUDE\win32ax.inc'

calc db 'c:\windows\system32\calc.exe',0
pi PROCESS_INFORMATION ?
sin STARTUPINFO ?
TamFun dd ?  ;tamaño de la funcion...
DirFun dd ? ; dirección de la funcion
DirUser dd ?

start:
	invoke CreateProcessA,0,calc,0,0,0,0,0,0,sin,pi
	invoke Sleep,2000
	invoke LoadLibrary,"user32.dll"
	mov [DirUser],eax

	invoke GetProcAddress,[DirUser],"MessageBoxA"
	mov [mMessageBoxA],eax
	invoke GetProcAddress,[DirUser],"FindWindowA"
	mov [mFindWindow],eax
	invoke GetProcAddress,[DirUser],"SetWindowTextA"
	mov [mSetWindowTextA],eax

	mov ebx,final  ;obtenemos el Tamaño de la función
	sub ebx,Inyectada
	mov [TamFun],ebx

	invoke VirtualAllocEx,[pi.hProcess],0,[TamFun],MEM_COMMIT+MEM_RESERVE,PAGE_EXECUTE_READWRITE
	mov [DirFun],eax
	invoke WriteProcessMemory,[pi.hProcess],eax,Inyectada,[TamFun],0
	invoke CreateRemoteThread,[pi.hProcess],0,0,[DirFun],0,0,0
	ret

	proc Inyectada
		call offset
		offset:
		pop ebx
		sub ebx,offset
		push ebx
		pop ecx

		add ecx,Calculadora

		push ecx
		push NULL
		call [ebx+mFindWindow]

		push ebx
		pop ecx

		add ecx, TituloVen

		push ecx
		push eax
		call [ebx+mSetWindowTextA]

		push ebx ebx
		pop edx ecx

		add ecx,TituloMsg
		add edx,CuerpoMsg

		push 0
		push ecx
		push edx
		push 0

		call [ebx+mMessageBoxA]
		ret

		TituloMsg db 'Inyectado!',0
		CuerpoMsg db 'El código inyectado Cambio el nombre a la ventana',0
		TituloVen db 'Este es un título falso',0
		Calculadora db 'Calculator',0

		mMessageBoxA dd ?  ;Dirección MessageBox
		mFindWindow dd ?   ;dirección fundwindow
		mSetWindowTextA  dd ? ;Dirección de SetWindowText
	endp
	final:
data import
     library kernel32,'kernel32.dll'

     import kernel32,CreateProcessA,'CreateProcessA',\
	    Sleep,'Sleep',\
	    GetModuleHandle,'GetModuleHandleA',\
	    GetProcAddress,'GetProcAddress',\
	    VirtualAllocEx,'VirtualAllocEx',\
	    WriteProcessMemory,'WriteProcessMemory',\
	    CreateRemoteThread,'CreateRemoteThread',\
	    LoadLibrary,'LoadLibraryA'
end data