#include "stdafx.h"
#include <windows.h>
#include "Wingdi.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "D3d9types.h"
#include "CDetour.h"
#include "Evo2.h"
#include <fstream>
#include <stdio.h>
#include <time.h>
#include "d3d9dev.h"

struct cVars
{
    float hack1, hack2, ShowMouse, ShowInfo;//hack defines
};
cVars cvar;

evoMenu evo( 4 );
int m_Stride = NULL;
bool bSetup = false;
D3DVIEWPORT9 viewport;
float fFps = 0.0f;
float fLastTickCount = 0.0f;
float fCurrentTickCount;
char cFrameRate[50] = {0};

const D3DCOLOR txtRed      = D3DCOLOR_ARGB(255, 255, 0, 0);
const D3DCOLOR txtGreen    = D3DCOLOR_ARGB(255, 0, 255, 0);
const D3DCOLOR txtBlue     = D3DCOLOR_ARGB(255, 0, 0, 255);
const D3DCOLOR txtYellow   = D3DCOLOR_ARGB(255, 255, 255, 0);
const D3DCOLOR txtOrange   = D3DCOLOR_ARGB(255, 255, 100, 0);
const D3DCOLOR txtWhite    = D3DCOLOR_ARGB(255, 255, 255, 255);
const D3DCOLOR txtBlack    = D3DCOLOR_ARGB(255, 0, 0, 0);
const D3DCOLOR txtPink    = D3DCOLOR_ARGB(255, 255, 20, 147);
const D3DCOLOR txtGrey     = D3DCOLOR_ARGB(255, 86, 86, 86);
const D3DCOLOR SpecialBlue = D3DCOLOR_ARGB(255, 0, 124, 241 );


HRESULT PreReset( LPDIRECT3DDEVICE9 pDevice )
{
	return D3D_OK;
}

HRESULT PostReset( LPDIRECT3DDEVICE9 pDevice )
{
	return D3D_OK;
}

HRESULT APIENTRY nReset( LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters )
{
	_asm pushad;

	PreReset( pDevice );

	HRESULT hRet = pReset( pDevice, pPresentationParameters );

	if( SUCCEEDED( hRet ) )
	{
		PostReset( pDevice );
	}

	_asm popad;
	return hRet;
}

HRESULT APIENTRY nPresent( LPDIRECT3DDEVICE9 pDevice, CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion )
{
	return pPresent( pDevice, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion );
}

HRESULT APIENTRY nBeginScene( LPDIRECT3DDEVICE9 pDevice )
{
	if( !bSetup )
	{
		evo.InitRendering("Verdana", GetDirectoryFile("FONT_DIRECTORY"), 12, FW_NORMAL, false, pDevice, false);

		evo.AddButton("Chams", &cvar.hack1, 0, 1);
		evo.AddButton("Xhair", &cvar.hack2, 0, 1);
		evo.AddButton("Show Mouse", &cvar.ShowMouse, 0, 1);
		evo.AddButton("Show fps/time", &cvar.ShowInfo, 0, 1);
		bSetup = true;
	}

		if( cvar.hack1 == 1.00f ) {
		} else {
		}

		if( cvar.hack2 == 1.00f ) {
		} else {
		}


	return pBeginScene( pDevice );
}

HRESULT APIENTRY nEndScene( LPDIRECT3DDEVICE9 pDevice )
{
	evo.CheckGui( VK_INSERT );
	pDevice->GetViewport( &viewport );
	int X = viewport.Width /2;
	int Y = viewport.Height /2;

	evo.DrawMenu("Button Menu - By Stefan", 15, 20, D3DCOLOR_ARGB( 255, 0, 0, 255 ), D3DCOLOR_ARGB( 255, 255, 255, 255 ), D3DCOLOR_ARGB( 255, 127, 2, 255 ), D3DCOLOR_ARGB( 255, 255, 255, 255 ), pDevice );
	evo.MovableMenu(VK_LBUTTON, 15, 20);//If you enable Move Menu then it will take over the Menu coordinates and made the DrawMenu(x & y) unusable. So set your menu's X and Y within the MovableMenu Function

	if( cvar.ShowInfo == 1.00f ) {
		evo.DrawWindow("Spec menu", X, 15, 190, 40, MENU_INNER_BORDER_COLOR, MENU_OUTER_BORDER_COLOR, pDevice);
		evo.DrawTextD3D(X, 20, txtRed, false, "Resolution: [%ix%i] | Fps: %s", (X * 2), (Y * 2), GetFrameRate( ));
		evo.DrawTextD3D(X, 30, txtRed, false, GetTime( 2 ));
		evo.DrawTextD3D(X, 40, txtRed, false, "Credits: NeoIII, Monster, cltfx");
	}

	if( cvar.ShowMouse == 1.00f ){
		evo.DrawMouse();
	}
	return pEndScene( pDevice );
}

HRESULT	APIENTRY nClear( LPDIRECT3DDEVICE9 pDevice, DWORD Count, CONST D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil )
{
	return pClear( pDevice, Count, pRects, Flags, Color, Z, Stencil );
}

HRESULT	APIENTRY nDrawIndexedPrimitive( LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE pType, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount )
{
	return pDrawIndexedPrimitive( pDevice, pType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount );
}

HRESULT APIENTRY nGetViewport( LPDIRECT3DDEVICE9 pDevice, D3DVIEWPORT9 *pViewport ) 
{
	return pGetViewport( pDevice, pViewport);
}

HRESULT APIENTRY nSetViewport( LPDIRECT3DDEVICE9 pDevice, CONST D3DVIEWPORT9 *pViewport ) 
{
	return pSetViewport( pDevice, pViewport ) ;
}

HRESULT APIENTRY nSetStreamSource( LPDIRECT3DDEVICE9 pDevice, UINT StreamNumber, IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride )
{
	if( StreamNumber == 0 ) { m_Stride = Stride; }
	return pSetStreamSource( pDevice, StreamNumber, pStreamData, OffsetInBytes, Stride );
}

HRESULT	APIENTRY nSetVertexShaderConstantF( LPDIRECT3DDEVICE9 pDevice, UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount )
{
	return pSetVertexShaderConstantF( pDevice, StartRegister, pConstantData, Vector4fCount );
}

char* GetTime( int type )
{
	if( type == 1 )
	{
		char *logbuf = new char[ 256 ];
		struct tm * current_tm;
		time_t current_time;
		time (&current_time);
		current_tm = localtime (&current_time);
		char Datestruct[16];
		GetDateFormat(NULL,NULL,NULL,"Ddd':'MMM':'Dd",Datestruct,16); 
		sprintf(logbuf, "[%02d:%02d:%02d] - [%s]", current_tm->tm_hour, current_tm->tm_min, current_tm->tm_sec, Datestruct);
		return logbuf;
	} else if( type == 2 ){
		char *logbuf = new char[ 256 ];
		char Timestruct[16], Datestruct[25];
		GetTimeFormat(NULL,NULL,NULL,"h':'m tt",Timestruct,15);
		GetDateFormat(NULL,NULL,NULL,"ddd',' MMM dd yyyy",Datestruct,25); 
		sprintf(logbuf, "[%s] - [%s]", Timestruct, Datestruct);
		return logbuf;
	}
	return false;
}

char* GetFrameRate( )
{
  fCurrentTickCount = clock() * 0.001f;
  ++fFps;

  if((fCurrentTickCount - fLastTickCount) > 1.0f)
  {
    fLastTickCount = fCurrentTickCount;
    sprintf(cFrameRate, "%d", int(fFps));
    fFps = 0;
  }
  return cFrameRate;
}