#include "stdafx.h"
#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "CDetour.h"
#include <fstream>
#include "d3d9dev.h"
#include <stdio.h>
#include <time.h>

#pragma comment( lib, "d3d9.lib" )
#pragma comment( lib, "d3dx9.lib" )
using namespace std;


Direct3DCreate9_t pDirect3DCreate9;
CreateDevice_t pCreateDevice;
Reset_t pReset;
Present_t pPresent;
Scene_t pBeginScene;
Scene_t pEndScene;
Clear_t pClear;
DrawIndexedPrimitive_t pDrawIndexedPrimitive;
GetViewport_t pGetViewport;
SetViewport_t pSetViewport;
SetStreamSource_t pSetStreamSource;
SetVertexShaderConstantF_t pSetVertexShaderConstantF;

struct sDetourInfo{
	BYTE* orig;
	BYTE* jmp;
	CDetour detour;
};

struct sDetours{
	sDetourInfo dtDirect3DCreate9;
	sDetourInfo dtCreateDevice;
	sDetourInfo dtPresent;
	sDetourInfo dtReset;
	sDetourInfo dtBeginScene;
	sDetourInfo dtEndScene;
	sDetourInfo dtClear;
	sDetourInfo dtDrawIndexedPrimitive;
	sDetourInfo dtGetViewport;
	sDetourInfo dtSetViewport;
	sDetourInfo dtSetStreamSource;
	sDetourInfo dtSetVertexShaderConstantF;
};sDetours dt;

DWORD* dwDevice;

#define HookChildFunc( x, t )x.detour.Create( x.orig, x.jmp, t )

////////////////////////////////////////////////////
ofstream ofile;	
char dlldir[320];
////////////////////////////////////////////////////

HRESULT WINAPI nCreateDevice( void* pDirect3D, unsigned int uiAdapter, D3DDEVTYPE pDeviceType, HWND hFocusWindow, unsigned long ulBehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, LPDIRECT3DDEVICE9* ppReturnedDeviceInterface )
{
	add_log( "CreateDevice Called" );

	HRESULT hrReturn = pCreateDevice( pDirect3D, uiAdapter, pDeviceType, 
		hFocusWindow, ulBehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface );

	if( hrReturn == D3D_OK )
	{
		DWORD* dwDevice = ( DWORD* )*( DWORD* )*ppReturnedDeviceInterface;

		add_log( "DirectX Device Hooked [0x%X]", dwDevice );

		dt.dtReset.orig = ( BYTE* )dwDevice[16];
		dt.dtReset.jmp = ( BYTE* )nReset;

		dt.dtPresent.orig = ( BYTE* )dwDevice[17];
		dt.dtPresent.jmp = ( BYTE* )nPresent;

		dt.dtBeginScene.orig = ( BYTE* )dwDevice[41];
		dt.dtBeginScene.jmp = ( BYTE* )nBeginScene;

		dt.dtEndScene.orig = ( BYTE* )dwDevice[42];
		dt.dtEndScene.jmp = ( BYTE* )nEndScene;

		dt.dtClear.orig = ( BYTE* )dwDevice[43];
		dt.dtClear.jmp = ( BYTE* )nClear;

		dt.dtSetStreamSource.orig = ( BYTE* )dwDevice[25];
		dt.dtSetStreamSource.jmp = ( BYTE* )nSetStreamSource;

		dt.dtGetViewport.orig = ( BYTE* )dwDevice[21];
		dt.dtGetViewport.jmp = ( BYTE* )nGetViewport;

		dt.dtSetViewport.orig = ( BYTE* )dwDevice[21];
		dt.dtSetViewport.jmp = ( BYTE* )nSetViewport;

		dt.dtDrawIndexedPrimitive.orig = ( BYTE* )dwDevice[82];
		dt.dtDrawIndexedPrimitive.jmp = ( BYTE* )nDrawIndexedPrimitive;

		dt.dtSetVertexShaderConstantF.orig = ( BYTE* )dwDevice[94];
		dt.dtSetVertexShaderConstantF.jmp = ( BYTE* )nSetVertexShaderConstantF;

		pReset = ( Reset_t )HookChildFunc( dt.dtReset, DETOUR_TYPE_JMP );
		pPresent = ( Present_t )HookChildFunc( dt.dtPresent, DETOUR_TYPE_JMP );
		pBeginScene = ( Scene_t )HookChildFunc( dt.dtBeginScene, DETOUR_TYPE_JMP );
		pEndScene = ( Scene_t )HookChildFunc( dt.dtEndScene, DETOUR_TYPE_JMP );
		pClear = ( Clear_t )HookChildFunc( dt.dtClear, DETOUR_TYPE_JMP );
		pDrawIndexedPrimitive = ( DrawIndexedPrimitive_t )HookChildFunc( dt.dtDrawIndexedPrimitive, DETOUR_TYPE_JMP );
		pGetViewport = ( GetViewport_t )HookChildFunc( dt.dtGetViewport, DETOUR_TYPE_JMP );
		pSetViewport = ( SetViewport_t )HookChildFunc( dt.dtSetViewport, DETOUR_TYPE_JMP );
		pSetStreamSource = ( SetStreamSource_t )HookChildFunc( dt.dtSetStreamSource, DETOUR_TYPE_JMP );
		pSetVertexShaderConstantF = ( SetVertexShaderConstantF_t )HookChildFunc( dt.dtSetVertexShaderConstantF, DETOUR_TYPE_JMP );
	}

	dt.dtCreateDevice.detour.RestoreFunction( dt.dtCreateDevice.orig, 20 );

	return hrReturn;
}

LPDIRECT3D9 WINAPI nDirect3DCreate9( unsigned int SDKVersion )
{
	LPDIRECT3D9 pDirect3D = pDirect3DCreate9( SDKVersion );

	add_log( "DirectX Hooked [ Direct3DCreate9: 0x%X ] - [ SDKVersion: 0x%X ]", pDirect3D, SDKVersion );

	if( pDirect3D != NULL )
	{
		unsigned long* ulObject = ( unsigned long* )pDirect3D;
		ulObject = ( unsigned long* )ulObject[0];

		dt.dtCreateDevice.orig = ( BYTE* )ulObject[16];
		dt.dtCreateDevice.jmp = ( BYTE* )nCreateDevice;

		dt.dtCreateDevice.detour.BackupFunction( dt.dtCreateDevice.orig, 20 );

		pCreateDevice = ( CreateDevice_t )dt.dtCreateDevice.detour.Create(
			dt.dtCreateDevice.orig, dt.dtCreateDevice.jmp, DETOUR_TYPE_PUSH_RET );
	}

	dt.dtDirect3DCreate9.detour.RestoreFunction( dt.dtDirect3DCreate9.orig, 20 );

	return pDirect3D;
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ulReason, LPVOID lpReserved )
{
	if( ulReason == DLL_PROCESS_ATTACH )
	{
		GetModuleFileName( hModule, dlldir, 512 );
		for(int i = ( int )strlen( dlldir ); i > 0; i--) 
		{ 
			if(dlldir[i] == '\\') { dlldir[i+1] = 0; break; } 
		}

		add_log( "Hook initialized!" );

		HMODULE hMod = LoadLibrary("d3d9.dll");

		dt.dtDirect3DCreate9.orig = ( BYTE* )GetProcAddress( hMod, "Direct3DCreate9" );
		dt.dtDirect3DCreate9.jmp = ( BYTE* )nDirect3DCreate9;

		dt.dtDirect3DCreate9.detour.BackupFunction( dt.dtDirect3DCreate9.orig, 20 );

		pDirect3DCreate9 = ( Direct3DCreate9_t )dt.dtDirect3DCreate9.detour.Create( dt.dtDirect3DCreate9.orig, dt.dtDirect3DCreate9.jmp, DETOUR_TYPE_PUSH_RET );

	} else if( ulReason == DLL_PROCESS_DETACH ){
		add_log( "Hook exiting process ..." );
		add_log( "---------------------------------------------------------------------------" );
		ofile.close( );
	}
    return TRUE;
}

char *GetDirectoryFile(char *filename)
{
	static char path[320];
	strcpy(path, dlldir);
	strcat(path, filename);
	return path;
}

void __cdecl add_log (const char * fmt, ...)
{
	va_list va_alist;
	char logbuf[256];
	FILE * fp;
	struct tm * current_tm;
	time_t current_time;

	time (&current_time);
	current_tm = localtime (&current_time);

	sprintf (logbuf, "[%02d:%02d:%02d]: ", current_tm->tm_hour, current_tm->tm_min, current_tm->tm_sec);

	va_start (va_alist, fmt);
	_vsnprintf (logbuf+strlen(logbuf), sizeof(logbuf) - strlen(logbuf), fmt, va_alist);
	va_end (va_alist);

	if ( (fp = fopen ( GetDirectoryFile("logs\\Hook.txt"), "a")) != NULL )
	{
		fprintf ( fp, "%s\n", logbuf );
		fclose (fp);
	}
}