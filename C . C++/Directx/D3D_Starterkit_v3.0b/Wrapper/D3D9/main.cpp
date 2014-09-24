/************************************************\
**	Project : TatniumD3D (d3d9 hook) v2.1		**
**	Author	: Matthew L (Azorbix)				**
**	Date	: September 29, 2004				**
\************************************************/
/*******************************************************\
*	Credits:											*
*		Tetsuo:			Help with hooking the device	*
*		LanceVorgin:	His name is funny				*
*		p47r!ck:		Hes German						*
*		Hybrid:			Knows DirectX9					*
*		Dom1n1k:		Helped with detourfunc			*
*		Da_BuzZ:		Helped alot with d3d8			*
*														*
*	Tools used:											*
*		MSVC++ 6.0 (w/out CORE-SDK)						*
*		DirectX9 SDK Update (summer 2003)				*
\*******************************************************/

#include <windows.h>
#include <fstream.h>
#include <stdio.h>

#include "main.h"
#include "d3d9.h"

//Globals
ofstream ofile;	
char dlldir[320];

bool WINAPI DllMain(HMODULE hDll, DWORD dwReason, PVOID pvReserved)
{
	if(dwReason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hDll);

		GetModuleFileName(hDll, dlldir, 512);
		for(int i = strlen(dlldir); i > 0; i--) { if(dlldir[i] == '\\') { dlldir[i+1] = 0; break; } }
		ofile.open(GetDirectoryFile("ttnlog.txt"), ios::app);

		add_log("\n---------------------\nTatniumD3D Started...\n---------------------");

		char sysd3d[320];
		GetSystemDirectory(sysd3d, 320);
		strcat(sysd3d, "\\d3d9.dll");
	
		add_log("Library: %s", sysd3d);
		HMODULE hMod = LoadLibrary(sysd3d);		
		oDirect3DCreate9 = (tDirect3DCreate9)GetProcAddress(hMod, "Direct3DCreate9");

		return true;
	}

	else if(dwReason == DLL_PROCESS_DETACH)
	{
		add_log("---------------------\nTatniumD3D Exiting...\n---------------------\n");
		if(ofile) { ofile.close(); }
	}

    return false;
}

char *GetDirectoryFile(char *filename)
{
	static char path[320];
	strcpy(path, dlldir);
	strcat(path, filename);
	return path;
}

void *DetourFunc(BYTE *src, const BYTE *dst, const int len)
{
	BYTE *jmp = (BYTE*)malloc(len+5);
	DWORD dwback;

	VirtualProtect(src, len, PAGE_READWRITE, &dwback);

	memcpy(jmp, src, len);	jmp += len;
	
	jmp[0] = 0xE9;
	*(DWORD*)(jmp+1) = (DWORD)(src+len - jmp) - 5;

	src[0] = 0xE9;
	*(DWORD*)(src+1) = (DWORD)(dst - src) - 5;

	VirtualProtect(src, len, dwback, &dwback);

	return (jmp-len);
}

bool RetourFunc(BYTE *src, BYTE *restore, const int len)
{
	DWORD dwback;
		
	if(!VirtualProtect(src, len, PAGE_READWRITE, &dwback))	{ return false; }
	if(!memcpy(src, restore, len))							{ return false; }

	restore[0] = 0xE9;
	*(DWORD*)(restore+1) = (DWORD)(src - restore) - 5;

	if(!VirtualProtect(src, len, dwback, &dwback))			{ return false; }
	
	return true;
}	

void __cdecl add_log (const char *fmt, ...)
{
	if(ofile != NULL)
	{
		if(!fmt) { return; }

		va_list va_alist;
		char logbuf[256] = {0};

		va_start (va_alist, fmt);
		_vsnprintf (logbuf+strlen(logbuf), sizeof(logbuf) - strlen(logbuf), fmt, va_alist);
		va_end (va_alist);

		ofile << logbuf << endl;
	}
}
