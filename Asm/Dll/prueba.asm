format PE GUI 4.0 DLL
entry DllEntryPoint			   ;aqui se define la funcion que tratara el attach

include 'C:\Documents and Settings\Owner\Desktop\Programming\Asm\Fasm\INCLUDE\win32ax.inc'

section '.code' code readable executable

proc DllEntryPoint hinstDLL,fdwReason,lpvReserved
	cmp [fdwReason],1
	JE mensage
	mensage:
	invoke MessageBox,0,mensajito,titulo,MB_OK
	ret
endp

; VOID ShowErrorMessage(HWND hWnd,DWORD dwError);

proc ShowErrorMessage hWnd,dwError
  local lpBuffer:DWORD
	lea	eax,[lpBuffer]
	invoke	FormatMessage,FORMAT_MESSAGE_ALLOCATE_BUFFER+FORMAT_MESSAGE_FROM_SYSTEM,0,[dwError],LANG_NEUTRAL,eax,0,0
	invoke	MessageBox,[hWnd],[lpBuffer],NULL,MB_ICONERROR+MB_OK
	invoke	LocalFree,[lpBuffer]
	ret
endp

; VOID ShowLastError(HWND hWnd);

proc ShowLastError hWnd
	invoke	GetLastError
	stdcall ShowErrorMessage,[hWnd],eax
	ret
endp
section '.data' data readable writeable
	mensajito db 'Dll Inyectada con exito',0
	titulo db ' Exito!!',0


section '.idata' import data readable writeable

  library kernel,'KERNEL32.DLL',\
	  user,'USER32.DLL'

  import kernel,\
	 GetLastError,'GetLastError',\
	 SetLastError,'SetLastError',\
	 FormatMessage,'FormatMessageA',\
	 LocalFree,'LocalFree'

  import user,\
	 MessageBox,'MessageBoxA'

section '.edata' export data readable

  export 'ERRORMSG.DLL',\
	 ShowErrorMessage,'ShowErrorMessage',\
	 ShowLastError,'ShowLastError'

section '.reloc' fixups data discardable
