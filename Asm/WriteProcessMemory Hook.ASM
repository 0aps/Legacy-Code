Format PE GUI 4.0
entry start
include 'C:\Documents and Settings\Owner\Desktop\Programming\Asm\Fasm\INCLUDE\win32ax.inc'

 
;@HOOK WriteprocessMemory             |
;  @Coder: linkgl                     |
;    @Fecha: 10/08/11                 |
;      @Agradecimientos:              |
;         The swash, Drinky94         |
;         & Haker Zero/Yst            |
;_____________________________________|

proceso db 'c:\writeprocessmemory.exe',0
linkpi PROCESS_INFORMATION <>
linksi STARTUPINFO <>
temp dd ?,0
tempu dd ?,0
tam dd ?,0
handle dd ?,0
 
 
start:
  invoke CreateProcessA,0,addr proceso,0,0,0,CREATE_SUSPENDED,0,0,linksi,linkpi
  invoke LoadLibrary,"kernel32.dll"
  mov [temp],eax
  invoke GetProcAddress,[temp],"VirtualProtect"
  mov [mVP],eax
  invoke GetProcAddress,[temp],"GetProcAddress"
  mov [gpa],eax
  invoke GetProcAddress,[temp],"LoadLibraryA"
  mov [gmh],eax
  invoke GetProcAddress,[temp],"CreateFileA"
  mov [cfa],eax
  invoke GetProcAddress,[temp],"WriteFile"
  mov [wfa],eax
  invoke GetProcAddress,[temp],"SetFilePointer"
  mov [sfp],eax
  invoke GetProcAddress,[temp],"CloseHandle"
  mov [chl],eax
 
  invoke LoadLibrary,"user32.dll"
  mov [tempu],eax
  invoke GetProcAddress,[tempu],"MessageBoxA"
  mov [msgbox],eax
 
 
  mov ebx,final
  sub ebx,inyectame
  mov [tam],ebx
  invoke VirtualAllocEx,[linkpi.hProcess],0,[tam],MEM_COMMIT+MEM_RESERVE,PAGE_EXECUTE_READWRITE
  mov [handle],eax
  invoke WriteProcessMemory,[linkpi.hProcess],[handle],addr inyectame,[tam],0
  invoke CreateRemoteThread,[linkpi.hProcess],0,0,[handle],0,0,0
 ; invoke Sleep,3000
  invoke ResumeThread,[linkpi.hThread]
 ret
 
 proc inyectame
  ;EDX = DELTAOFFSET
  ;ESI = EBX
  ;EDI = CUALQUIEROTRACOSA
   call offset
   offset:
   pop edx
   sub edx,offset
   mov edi,edx
   mov esi,edx
   mov esi,edx
   mov edi,edx
   push edx
   ;getmodulehandle
   add edx,kernel
   push edx
   call [edi+gmh] ;getmodulehandle
   ;restaurar
   pop edx
   push edx
   ;getprocaddress
   add edx,wpm
   push edx
   push eax
   call [edi+gpa] ;getprocaddress
   mov ebx,eax
   ;restaura
   pop edx
   push edx
   ;virtualprotect
   add edi,originalp
   push edi
   push 0x40
   push 0x5
   push ebx
   call [edx+mVP]
   ;restaura
   pop edx
   mov edi,edx
   push edx
   ;dir.virtual guardada
   add edx,vwriteprocessmemory
   mov dword [edx],ebx
   ;restaura
   pop edx
   ;modifica bytes
   mov byte [ebx],0xE9
   inc ebx
   mov ecx,hook
   add ecx,edx
   sub ecx,ebx
   sub ecx,4
   mov dword [ebx],ecx
   ret
 
restaurar:
  mov edi,edi ;esto esta en la api al principio
  push ebp   ;esto tambien, fue lo que pisamos
  mov ebp,esp  ;y esto tambien se piso
  ;add edx,vwriteprocessmemory
  mov eax,[edx+vwriteprocessmemory] ;nos desplazamos a la posicion en memoria de la api
  add eax,5 ;y saltamos 5 bytes (los que habiamos escrito)
  jmp eax
 
hook:
  call ofdelta
  ofdelta:
  pop edx
  sub edx,ofdelta
  mov esi,edx
;->sacamoslos parametros y los pusheamos
  pop eax ;retorno :P
  pop ebx  ;parametros
  mov [edx+p1],ebx
  pop ebx
  mov [edx+p2],ebx
  pop ebx
  mov [edx+p3],ebx
  pop edi
  mov [edx+p4],edi
  push [edx+p4]
  push [edx+p3]
  push [edx+p2]
  push [edx+p1]
  push eax
  ; push eax
  ;Guardamos el delta para que no nos de errores al restaurar el api
  push edx
  ;createfilea
  add edx,ruta
  push 0
  push 0
  push 4
  push 0
  push 0
  push 0x40000000
  push edx
  call [esi+cfa];createfilea
  mov [esi+hndle],eax
  ;restauramos
  pop edx
  mov esi,edx
  push edx
  ;setfilepointer
  push 2
  push 0
  push 0
  push [esi+hndle]
  call [esi+sfp]  ;setfilepointer
  ;restauramos
  pop edx
  mov esi,edx
  push edx
  ;writefile
  add esi,leidos
  push 0
  push esi
  push edi
  push ebx
  push [edx+hndle]
  call [edx+wfa] ;writefile
  ;limpiamos
  pop edx
  mov esi,edx
  push edx
 
  push [esi+hndle]
  call [esi+chl]
 
  ;restauramos el offset delta
  pop edx
  mov ecx,edx
  add ecx,restaurar
  ;msgbox->
  jmp ecx
 
 
 
  vwriteprocessmemory dd ? ;Direccion WriteProcessMemory
  msgbox dd ?  ;Dirección MessageBox
  tit db "Inyectado",0
  msg db "Ya me inyecte",0
  mVP dd ? ;Direccion virtualprotect
  originalp dd ?
  kernel db "KERNEL32.DLL",0
  wpm db "WriteProcessMemory",0
  ruta db 'j:\salida.txt',0
  gpa dd ? ;Dir getprocaddress
  gmh dd ? ;Dir loadlibrary/getmodulehandle en su defecto
  cfa dd ? ;Dir createfilea
  wfa dd ? ;Dir writefilea
  sfp dd ? ;Dir setfilepointer
  hndle dd ?
  chl dd ?
  leidos dd ? ;puntero para writefile bytesleidos
  p1 dd ?
  p2 dd ?
  p3 dd ?
  p4 dd ?
 
  endp
  final:
data import
  library kernel32,'kernel32.dll'
  import kernel32,CreateProcessA,'CreateProcessA',\
  GetModuleHandle,'GetModuleHandleA',\
  GetProcAddress,'GetProcAddress',\
  VirtualAllocEx,'VirtualAllocEx',\
  WriteProcessMemory,'WriteProcessMemory',\
  CreateRemoteThread,'CreateRemoteThread',\
  LoadLibrary,'LoadLibraryA',\
  ResumeThread,'ResumeThread',\
  Sleep,'Sleep'
end data