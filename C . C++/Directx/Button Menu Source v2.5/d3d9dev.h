#include "stdafx.h"
#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

typedef LPDIRECT3D9 ( WINAPI *Direct3DCreate9_t )( unsigned int SDKVersion );
typedef HRESULT ( WINAPI* CreateDevice_t)(void* pDirect3D, unsigned int uiAdapter, D3DDEVTYPE pDeviceType, HWND hFocusWindow, unsigned long ulBehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, LPDIRECT3DDEVICE9* ppReturnedDeviceInterface);
typedef HRESULT ( WINAPI* Present_t )( LPDIRECT3DDEVICE9 pDevice, CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion );
typedef HRESULT ( WINAPI* Reset_t )( LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters );
typedef HRESULT	( WINAPI* Scene_t )( LPDIRECT3DDEVICE9 pDevice );
typedef HRESULT	( WINAPI* Clear_t )( LPDIRECT3DDEVICE9 pDevice, DWORD Count, CONST D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil );
typedef HRESULT	( WINAPI* DrawIndexedPrimitive_t )( LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE pType, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount );
typedef HRESULT	( WINAPI* GetViewport_t )( LPDIRECT3DDEVICE9 pDevice, D3DVIEWPORT9 *pViewport );
typedef HRESULT ( WINAPI* SetViewport_t )( LPDIRECT3DDEVICE9 pDevice, CONST D3DVIEWPORT9 *pViewport );
typedef HRESULT ( WINAPI* SetStreamSource_t )( LPDIRECT3DDEVICE9 pDevice, UINT StreamNumber, IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride );
typedef HRESULT	( WINAPI* SetVertexShaderConstantF_t )( LPDIRECT3DDEVICE9 pDevice, UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount );

extern Direct3DCreate9_t pDirect3DCreate9;
extern CreateDevice_t pCreateDevice;
extern Reset_t pReset;
extern Present_t pPresent;
extern Scene_t pBeginScene;
extern Scene_t pEndScene;
extern Clear_t pClear;
extern DrawIndexedPrimitive_t pDrawIndexedPrimitive;
extern GetViewport_t pGetViewport;
extern SetViewport_t pSetViewport;
extern SetStreamSource_t pSetStreamSource;
extern SetVertexShaderConstantF_t pSetVertexShaderConstantF;

HRESULT WINAPI nPresent( LPDIRECT3DDEVICE9 pDevice, CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion );
HRESULT APIENTRY nReset( LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters );
HRESULT APIENTRY nBeginScene( LPDIRECT3DDEVICE9 pDevice );
HRESULT APIENTRY nEndScene( LPDIRECT3DDEVICE9 pDevice );
HRESULT	APIENTRY nClear( LPDIRECT3DDEVICE9 pDevice, DWORD Count, CONST D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil );
HRESULT APIENTRY nDrawIndexedPrimitive( LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE pType, INT BaseVertexIndex, UINT minIndex, UINT NumVertices, UINT startIndex, UINT primCount);
HRESULT APIENTRY nGetViewport( LPDIRECT3DDEVICE9 pDevice, D3DVIEWPORT9 *pViewport );
HRESULT APIENTRY nSetViewport( LPDIRECT3DDEVICE9 pDevice, CONST D3DVIEWPORT9 *pViewport );
HRESULT APIENTRY nSetStreamSource( LPDIRECT3DDEVICE9 pDevice, UINT StreamNumber, IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride );
HRESULT	APIENTRY nSetVertexShaderConstantF( LPDIRECT3DDEVICE9 pDevice, UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount );

void __cdecl add_log (const char * fmt, ...);
char *GetDirectoryFile(char *filename);
char* GetFrameRate( );
char* GetTime( int type );