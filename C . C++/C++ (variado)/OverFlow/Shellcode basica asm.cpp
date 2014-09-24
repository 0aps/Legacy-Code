#include <stdio.h>
#include <windows.h>

int main() 
{
	LoadLibrary("msvcrt.dll");
	
    __asm(" push ebp                        ");
	__asm("	mov ebp,esp                     ");
	__asm("	xor edi,edi                     ");
	__asm("	push edi                        ");
	__asm("	sub esp,0x04                    ");
	__asm("	mov byte ptr [ebp-0x08],0x63    ");
	__asm("	mov byte ptr [ebp-0x07],0x6D    ");
	__asm("	mov byte ptr [ebp-0x06],0x64    ");
	__asm("	mov byte ptr [ebp-0x05],0x2E    ");
	__asm("	mov byte ptr [ebp-0x04],0x65    ");
	__asm("	mov byte ptr [ebp-0x03],0x78    ");
	__asm("	mov byte ptr [ebp-0x02],0x65    ");
	__asm("	lea eax,[ebp-0x08]              ");
	__asm("	push eax                        ");
	__asm("	mov ebx,0x77bf8044              ");
	__asm("	call ebx                        ");
		
}

