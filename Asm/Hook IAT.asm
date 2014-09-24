

include 'C:\Documents and Settings\Owner\Desktop\Programming\Asm\Fasm\INCLUDE\win32ax.inc'

.386
.model flat, stdcall
option casemap:none

assume fs:nothing

.data
	Process 				db 'asm001.exe',0
	Kernel					db 'kernel32.dll',0
	GetProc 				db 'GetProcAddress',0
.data?
	Function				dd ?
	FunctionLen				dd ?
	pInfo						PROCESS_INFORMATION <>
	sInfo						STARTUPINFO <>
function_start PROTO
.code
start:
		invoke CreateProcess,0,addr Process,0,0,0,0,0,0,addr sInfo,addr pInfo
		
		mov eax,offset function_end
		sub eax,offset function_start
		mov [FunctionLen],eax
		
		invoke VirtualAllocEx,[pInfo.hProcess],0,[FunctionLen],MEM_COMMIT+MEM_RESERVE,PAGE_EXECUTE_READWRITE
		mov [Function],eax
		
		invoke GetModuleHandle,offset Kernel
		mov [KernelBase],eax
		push offset GetProcAddressName
		
		invoke GetProcAddress,eax,offset GetProc
		mov [pGetProcAddress],eax
		mov ebx,offset function_start
		
		invoke WriteProcessMemory,[pInfo.hProcess],[Function],offset function_start,[FunctionLen],0
		invoke CreateRemoteThread,[pInfo.hProcess],0,0,[Function],0,0,0
		invoke ExitProcess,0

;Injecting Function
function_start PROC
    call delta
		delta:
			pop ebp
			sub ebp, offset delta
			mov ebx, fs:[030h]
			;Getting host process IAT address and its size
			mov eax,[ebx+08h]
			mov ebx,[eax+03Ch]
			add ebx,eax
			mov edx,[ebx+0D8h]
			add edx,eax
			mov [ebp+pIAT],edx
			mov edx,[ebx+0DCh]
			mov [ebp+IATsize],edx
			
			;Getting the needed API's
				;GetModuleHandle
			mov ebx,offset GetModuleHandleName
			add ebx,ebp
			push ebx
			push dword ptr [ebp+KernelBase]
			call [ebp+pGetProcAddress]
			mov [ebp+pGetModuleHandle],eax
				;VirtualProtect
			mov ebx,offset VirtualProtectName
			add ebx,ebp
			push ebx
			push dword ptr [ebp+KernelBase]
			call [ebp+pGetProcAddress]
			mov [ebp+pVirtualProtect],eax
			;Getting address of MessageBox
			mov ebx,offset user32name
			add ebx,ebp
			push ebx
			call [ebp+pGetModuleHandle]
			mov ebx,offset MessageBoxName
			add ebx,ebp
			push ebx
			push eax
			call [ebp+pGetProcAddress]
			mov [ebp+pMessageBox],eax
			;Showing a MessageBox
			push MB_OK + MB_ICONINFORMATION
			push 0
			mov ebx,offset MsgInjected
			add ebx,ebp
			push ebx
			push 0
			call [ebp+pMessageBox]
			;Finding pointing address
			xor edx,edx
			mov eax,[ebp+IATsize]
			mov ecx,04h
			div ecx
			mov ecx,eax
			mov eax,[ebp+pMessageBox]
			mov edi,[ebp+pIAT]
			repnz scasd
			sub edi,04h
			;Patching the IAT
			mov ebx,offset OldProtect
			add ebx,ebp
			push ebx
			push PAGE_EXECUTE_READWRITE
			push 04h
			push edi
			call [ebp+pVirtualProtect]
			mov ebx,offset Hook
			add ebx,ebp
			mov [edi],ebx
			ret

pIAT dd ?
IATsize dd ?
BaseImage dd ?
KernelBase dd ?
pGetProcAddress dd ?
GetProcAddressName db "GetProcAddress",0
user32name db "user32.dll",0
MessageBoxName db "MessageBoxA",0
pMessageBox dd ?
GetModuleHandleName db "GetModuleHandleA",0
pGetModuleHandle dd ?
VirtualProtectName db "VirtualProtect",0
pVirtualProtect dd ?
OldProtect dd ?
MsgInjected db "The function has been injected!",0

Hook: 
	;Delta offset
	call deltahook
		deltahook:
			pop ebp
			sub ebp,offset deltahook
			pop ebx 					;Saving to return after
			mov edi,offset msghook
			add edi,ebp
			mov [esp+04h],edi			;Changing the stack parameters
			call [ebp+pMessageBox]		;Calling the original address of MessageBox
			push ebx					;Setting the returning address
			ret
msghook 	db "MessageBox Hooked!", 0
function_start endp
function_end:
end start
