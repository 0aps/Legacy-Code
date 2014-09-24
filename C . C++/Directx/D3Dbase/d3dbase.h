// -----------------------------------------------------------------------------
// IMPORTANT: make your choice  D3D8 or D3D9
// -----------------------------------------------------------------------------
#ifndef _D3DBASE_H
#define _D3DBASE_H




// SELECT FOR WHICH DIRECTX VERSION !!!!!


//#define FOR_D3D8
#define FOR_D3D9






#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <time.h>

#pragma comment(linker, "/OPT:NOWIN98")

#ifdef FOR_D3D8

#include <d3d8.h>
#include "d3dfont8.h"

#define D3Ddllname		"d3d8.dll"
#define pD3DdeviceX		LPDIRECT3DDEVICE8
#define pD3DvertexX		LPDIRECT3DVERTEXBUFFER8

#pragma comment (lib, "d3d8.lib")
#pragma message("main.h : Building for D3D8")

#define RESET		14
#define ENDSCENE	35

#else

#include <d3d9.h>
#include "d3dfont9.h"
#define D3Ddllname		"d3d9.dll"
#define pD3DdeviceX		LPDIRECT3DDEVICE9
#define pD3DvertexX		LPDIRECT3DVERTEXBUFFER9

#pragma comment (lib, "d3d9.lib")
#pragma message("main.h : Building for D3D9")

#define RESET		16
#define ENDSCENE	42

#endif

#include "D3Dmenu.h"


typedef HRESULT (WINAPI* oEndScene)            (pD3DdeviceX pDevice);
typedef HRESULT (WINAPI* oReset)               (pD3DdeviceX pDevice,D3DPRESENT_PARAMETERS* pPresentationParameters);

// D3Dbase functions and vars
extern CD3DFont	*pFont;

void DrawBox(pD3DdeviceX pDevice, int x, int y, int w, int h, D3DCOLOR color);
void PreReset (pD3DdeviceX pDevice);
void PostReset(pD3DdeviceX pDevice);
bool bCompare(const BYTE* pData, const BYTE* bMask, const char* szMask);
DWORD FindPattern(DWORD dwAddress,DWORD dwLen,BYTE *bMask,char * szMask);
void *DetourCreate(BYTE *src, const BYTE *dst, const int len);

// hackbase functions and vars

extern int noFPS;
void RebuildMenu(void);
void DoMenu(pD3DdeviceX pDevice);
DWORD WINAPI HACKthread(LPVOID param);


#endif
