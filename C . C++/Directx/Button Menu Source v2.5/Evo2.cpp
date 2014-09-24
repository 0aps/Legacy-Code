////////////////////////////////////////////////////////////////////////////////
//////////////// Maker - Stefan thisgamesux.net | ghbsys.net ///////////////////
///////////////// Credits to: Monster for his Sprite base //////////////////////
/////////////////// Credits to: NeoIII for the CheckGui ////////////////////////
///////////////// Original Base - cLTFX - Credits to them //////////////////////
////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h" 
#include <windows.h>
#include "Evo2.h" 
#include <tchar.h>
#include <math.h>
#include "d3d9dev.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <Tlhelp32.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma warning(disable: 4244)
#pragma warning(disable: 4305) 

typedef HRESULT (WINAPI* D3DXCreateFont_t) ( 
        LPDIRECT3DDEVICE9       pDevice,   
        INT                     Height, 
        UINT                    Width, 
        UINT                    Weight, 
        UINT                    MipLevels, 
        BOOL                    Italic, 
        DWORD                   CharSet, 
        DWORD                   OutputPrecision, 
        DWORD                   Quality, 
        DWORD                   PitchAndFamily, 
        LPCSTR                  pFaceName, 
        LPD3DXFONT*             ppFont); 

typedef HRESULT (WINAPI* D3DXCreateSprite_t) ( 
        LPDIRECT3DDEVICE9       pDevice, 
        LPD3DXSPRITE*           ppSprite); 

D3DXMatrixMultiply_t            pD3DXMatrixMultiply; 
D3DXCreateFont_t                pD3DXCreateFont;  
D3DXCreateSprite_t				pD3DXCreateSprite; 
D3DXMatrixTransformation2D_t    pD3DXMatrixTransformation2D;

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEY_UP(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)

/*Font Thinkness defines
FW_DONTCARE 0 
FW_THIN 100 
FW_ULTRALIGHT 200 
FW_LIGHT 300 
FW_REGULAR 400 
FW_MEDIUM 500 
FW_DEMIBOLD 600 
FW_BOLD 700 
FW_ULTRABOLD 800 
FW_BLACK 900*/

#define DRAWLINE_LR		0.00//right to left
#define DRAWLINE_TB		1.57//top to bottom
#define DRAWLINE_RL		3.14//right to left
#define DRAWLINE_BT		4.71//bottim to top

#define BUTTON_WIDTH	15
#define BUTTON_HEIGHT	15

int TEXT_SIZE;
pMouse Mouse;

evoMenu::evoMenu( int MAX_MENU )
{ 
	MAX_ITEMS = 0;
    mainMenu = new pMenu[MAX_MENU];
    bMenu = false;
    m_pFont      = 0; 
    m_pEspFont   = 0; 
    m_pSprite    = 0; 
    m_pTexWhite  = 0; 
} 

evoMenu::~evoMenu() 
{ 
	MAX_ITEMS = 0;
    delete[] mainMenu;
    m_pSprite->Release(); 
    m_pFont->Release(); 
    m_pEspFont->Release(); 
	m_pTexWhite->Release();
} 

HRESULT evoMenu::GenerateTexture(IDirect3DDevice9 *pD3Ddev, IDirect3DTexture9 **ppD3Dtex, DWORD colour32)
{
	if( FAILED(pD3Ddev->CreateTexture(8, 8, 1, 0, D3DFMT_A4R4G4B4, D3DPOOL_MANAGED, ppD3Dtex, NULL)) )return E_FAIL;
	WORD colour16 =	((WORD)((colour32>>28)&0xF)<<12)
			|(WORD)(((colour32>>20)&0xF)<<8)
			|(WORD)(((colour32>>12)&0xF)<<4)
			|(WORD)(((colour32>>4)&0xF)<<0);
	D3DLOCKED_RECT d3dlr;    
	(*ppD3Dtex)->LockRect(0, &d3dlr, 0, 0);
	WORD *pDst16 = (WORD*)d3dlr.pBits;
	for(int xy=0; xy < 8*8; xy++)*pDst16++ = colour16;
	(*ppD3Dtex)->UnlockRect(0);
	return S_OK;
}

HMODULE evoMenu::FindD3DXModule() 
{ 
    HANDLE hSnap; 
    MODULEENTRY32 xModule; 
    hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, GetCurrentProcessId()); 
    xModule.dwSize = sizeof(MODULEENTRY32); 
    if(Module32First(hSnap, &xModule)) 
    { 
        while(Module32Next(hSnap, &xModule)) 
        { 
            if(strstr(xModule.szModule, "d3dx9_")) 
            { 
                CloseHandle(hSnap); 
                return xModule.hModule; 
            } 
        } 
    } 
    CloseHandle(hSnap); 
    return NULL; 
} 

bool evoMenu::GetD3DXFunctions() 
{ 
    HMODULE hMod = FindD3DXModule(); 

    if(!hMod) 
        hMod = LoadLibrary("d3dx9_25.dll"); 

    pD3DXCreateFont                = (D3DXCreateFont_t)                GetProcAddress(hMod, "D3DXCreateFontA"); 
    pD3DXCreateSprite              = (D3DXCreateSprite_t)              GetProcAddress(hMod, "D3DXCreateSprite"); 
    pD3DXMatrixMultiply            = (D3DXMatrixMultiply_t)            GetProcAddress(hMod, "D3DXMatrixMultiply"); 
    pD3DXMatrixTransformation2D    = (D3DXMatrixTransformation2D_t)    GetProcAddress(hMod, "D3DXMatrixTransformation2D"); 

    return (pD3DXCreateFont != 0); 
} 

bool evoMenu::InitRendering(char *strFontName, char *strFontPath, int size, UINT Thick, bool Italic, LPDIRECT3DDEVICE9 pDevice, bool IsTTF)
{  
    m_pDevice = pDevice; 
	TCHAR   m_strFontName[ 80 ];
	TCHAR	m_strFontPath[ 260 ];
	TEXT_SIZE = size;

	_tcscpy( m_strFontName, strFontName );
	if( IsTTF )
	{
		_tcscpy( m_strFontPath, strFontPath );
		AddFontResource( m_strFontPath );
	}
    if(evoMenu::GetD3DXFunctions()) 
    { 
        evoMenu::GenerateTexture(pDevice, &m_pTexWhite, COLOR_WHITE); 

        pD3DXCreateSprite(pDevice, &m_pSprite); 
        pD3DXCreateFont(pDevice, size, 0, Thick, 0, Italic, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, m_strFontName, &m_pFont); 
        pD3DXCreateFont(pDevice, size, 0, Thick, 0, Italic, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, m_strFontName, &m_pEspFont);

        return true; 
    } 

    return false; 
} 

void evoMenu::OnLostDevice() 
{ 
    m_pSprite->OnLostDevice(); 
    m_pFont->OnLostDevice(); 
    m_pEspFont->OnLostDevice(); 
} 

void evoMenu::OnResetDevice() 
{ 
    m_pSprite->OnResetDevice(); 
    m_pFont->OnResetDevice(); 
    m_pEspFont->OnResetDevice(); 
} 
void evoMenu::FillRectD3D(int x, int y, int iWidth, int iHeight, DWORD dwColor) 
{     
    RECT rct;
	D3DXVECTOR3 pos;
    rct.left     = 0; 
    rct.top      = 0; 
    rct.right    = iWidth; 
    rct.bottom   = iHeight; 

    pos.x = x; 
    pos.y = y; 
    pos.z = 0; 

    m_pSprite->Draw(m_pTexWhite, &rct, NULL, &pos, dwColor);     
} 

void evoMenu::DrawNormalLineD3D(int iStartX, int iStartY, int iEndX, int iEndY, DWORD dwColor) 
{     
    float flLength    = sqrt(pow(iEndX-iStartX,2) + pow(iEndY-iStartY,2)); 
    float flAngle     = atan((float)(iEndY - iStartY) / (iEndX - iStartX)); 

    DrawPolarLineD3D(iStartX, iStartY, flLength, flAngle, dwColor); 
}

void evoMenu::DrawPolarLineD3DEx(int iStartX, int iStartY, float flLength, float flAngle, int a, int r, int g, int b)
{
	DrawPolarLineD3D(iStartX, iStartY, flLength, flAngle, D3DCOLOR_ARGB(a, r, g, b)); 
}

void evoMenu::FillPolarD3D(int iStartX, int iStartY, int width, float flLength, float flAngle, DWORD dwColor)
{
	for( int i = 0; i < width; i++ ) 
    { 
		DrawPolarLineD3D(iStartX+i, iStartY, flLength, flAngle, dwColor); 
	}
}

void evoMenu::DrawPolarLineD3D(int iStartX, int iStartY, float flLength, float flAngle, DWORD dwColor)
{
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND); 
    D3DXMATRIX      d3dMatrix, d3dOldMatrix;
	RECT			rct;

	D3DXVECTOR2        vCenter(iStartX, iStartY);
    D3DXVECTOR3        vPos(iStartX, iStartY, 0); 
    rct.left     = 0;
    rct.top      = 0; 
    rct.right    = flLength;
    rct.bottom   = 1;

    pD3DXMatrixTransformation2D(&d3dMatrix, NULL, NULL, NULL, &vCenter, flAngle, NULL);
    m_pSprite->GetTransform(&d3dOldMatrix);
    m_pSprite->SetTransform(&d3dMatrix);
    m_pSprite->Draw(m_pTexWhite, &rct, NULL, &vPos, dwColor);
    m_pSprite->SetTransform(&d3dOldMatrix);
	m_pSprite->End();
} 

void evoMenu::DrawTextD3D(int x, int y, DWORD dwColor, bool bEspFont, char* szText, ...) 
{ 
	m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
    LPD3DXFONT pFont = 0;     
    RECT rct;   
    rct.left     = x - 1;   
    rct.right    = x + 1;   
    rct.top      = y - 1 ;   
    rct.bottom   = y + 1; 

	if(!szText) { return; }
    va_list va_alist;
    char logbuf[256] = {0};
    va_start (va_alist, szText);
    _vsnprintf (logbuf+strlen(logbuf), sizeof(logbuf) - strlen(logbuf), szText, va_alist);
    va_end (va_alist);
    RECT FontRect = { x, y, x, y };
    pFont = bEspFont ? m_pEspFont : m_pFont;
    pFont->DrawText(m_pSprite, logbuf, -1, &rct, DT_NOCLIP, dwColor); 
	m_pSprite->End();
} 
/////////////////////////////////////////////////////////////////////////////////////////////////////////

void evoMenu::GradientBox(int x, int y, int w, int h, int r, int g, int b, LPDIRECT3DDEVICE9 pDevice) 
{ 
    float Alpha = 20; 
    float Step = ((255 - Alpha) / h); 

    for( int i = 0; i < h; i++ ) 
    { 
        Alpha = Alpha + Step;     
		DrawPolarLineD3DEx(x, y+i, w, DRAWLINE_LR, (int)Alpha, r, g, b);
    } 
} 

bool evoMenu::MouseIsOver(int x, int y, int w, int h) 
{ 
    POINT cur; 
    GetCursorPos(&cur); 
    bool bover; 

    if(cur.x >= x && cur.x <= x + w && cur.y >= y && cur.y <= y + h){ bover = true; }else{ bover = false; } 
    return bover; 
}

void evoMenu::DrawMouse()
{
	POINT cur; 
    GetCursorPos(&cur);
	int PointX = cur.x;
	int PointY = cur.y;
	Mouse.xPos = cur.x;
	Mouse.yPos = cur.y;
	int Length = 12;

	#define MOUSE_BACKGROUND_COLOR							D3DCOLOR_ARGB(255, 107, 177, 228)//lightblue
	#define MOUSE_INNER_BORDER_COLOR						D3DCOLOR_ARGB(255, 0, 0, 0)//black

	for( int i = 0; i < Length; i++ )
    {

		if(i < (Length-4)) DrawPolarLineD3D((PointX+9)+i, PointY+i, 1, DRAWLINE_LR, MOUSE_INNER_BORDER_COLOR);//Right Mouse Boarder
		if(i < (Length-4)) DrawPolarLineD3D((PointX+8)+i, PointY+i, 1, DRAWLINE_LR, MOUSE_BACKGROUND_COLOR);
		if(i < (Length-3)) DrawPolarLineD3D((PointX+7)+i, PointY+i, 1, DRAWLINE_LR, MOUSE_BACKGROUND_COLOR);
		if(i < (Length-3)) DrawPolarLineD3D((PointX+6)+i, PointY+i, 1, DRAWLINE_LR, MOUSE_BACKGROUND_COLOR);
		if(i < (Length-2)) DrawPolarLineD3D((PointX+5)+i, PointY+i, 1, DRAWLINE_LR, MOUSE_BACKGROUND_COLOR);
		if(i < (Length-2)) DrawPolarLineD3D((PointX+4)+i, PointY+i, 1, DRAWLINE_LR, MOUSE_BACKGROUND_COLOR);
		if(i < (Length-1)) DrawPolarLineD3D((PointX+3)+i, PointY+i, 1, DRAWLINE_LR, MOUSE_BACKGROUND_COLOR);
		if(i < (Length-1)) DrawPolarLineD3D((PointX+2)+i, PointY+i, 1, DRAWLINE_LR, MOUSE_BACKGROUND_COLOR);
		DrawPolarLineD3D((PointX+1)+i, PointY+i, 1, DRAWLINE_LR, MOUSE_BACKGROUND_COLOR);
		DrawPolarLineD3D(PointX+i, PointY+i, 1, DRAWLINE_LR, MOUSE_BACKGROUND_COLOR);
		DrawPolarLineD3D(PointX+i, (PointY+1)+i, 1, DRAWLINE_LR, MOUSE_BACKGROUND_COLOR);
		if(i < (Length-1)) DrawPolarLineD3D(PointX+i, (PointY+2)+i, 1, DRAWLINE_LR, MOUSE_BACKGROUND_COLOR);
		if(i < (Length-1)) DrawPolarLineD3D(PointX+i, (PointY+3)+i, 1, DRAWLINE_LR, MOUSE_BACKGROUND_COLOR);
		if(i < (Length-2)) DrawPolarLineD3D(PointX+i, (PointY+4)+i, 1, DRAWLINE_LR, MOUSE_BACKGROUND_COLOR);
		if(i < (Length-2)) DrawPolarLineD3D(PointX+i, (PointY+5)+i, 1, DRAWLINE_LR, MOUSE_BACKGROUND_COLOR);
		if(i < (Length-3)) DrawPolarLineD3D(PointX+i, (PointY+6)+i, 1, DRAWLINE_LR, MOUSE_BACKGROUND_COLOR);
		if(i < (Length-3)) DrawPolarLineD3D(PointX+i, (PointY+7)+i, 1, DRAWLINE_LR, MOUSE_BACKGROUND_COLOR);
		if(i < (Length-4)) DrawPolarLineD3D(PointX+i, (PointY+8)+i, 1, DRAWLINE_LR, MOUSE_BACKGROUND_COLOR);
		if(i < (Length-4)) DrawPolarLineD3D(PointX+i, (PointY+9)+i, 1, DRAWLINE_LR, MOUSE_INNER_BORDER_COLOR);//Left Mouse Border

		if(i < (Length-2)) DrawPolarLineD3D(PointX+1, PointY+i, 1, DRAWLINE_TB, MOUSE_INNER_BORDER_COLOR);//Left Wing point
		if(i < (Length-2)) DrawPolarLineD3D(PointX+i, PointY, 1, DRAWLINE_LR, MOUSE_INNER_BORDER_COLOR);//Right Wing point

		if(i < (Length/2))
		{
			if(i < (Length/2-1)) DrawPolarLineD3D((PointX+Length)+i, (PointY+Length)-i, 1, DRAWLINE_LR, MOUSE_INNER_BORDER_COLOR);//Right Base
			if(i < (Length/2-1)) DrawPolarLineD3D((PointX+Length)-i, (PointY+Length)+i, 1, DRAWLINE_LR, MOUSE_INNER_BORDER_COLOR);//left base

			DrawPolarLineD3D((PointX+Length+1)+i, (PointY+Length)+i, 1, DRAWLINE_LR, MOUSE_INNER_BORDER_COLOR);//innter tail
			DrawPolarLineD3D((PointX+Length+1)+i, (PointY+Length+1)+i, 1, DRAWLINE_LR, MOUSE_BACKGROUND_COLOR);//tail
			DrawPolarLineD3D((PointX+Length)+i, (PointY+Length+1)+i, 1, DRAWLINE_LR, MOUSE_INNER_BORDER_COLOR);//innter tail
		}
	}
}

void evoMenu::MovableMenu(int wKey, int x, int y)
{
	static bool Bfullbright = false;
	if( !Bfullbright) { 
		mainMenu[NULL].xPos = x;
		mainMenu[NULL].yPos = y;
		Bfullbright = true;
	}

	//FillPolarD3D((mainMenu[NULL].xPos+20), (mainMenu[NULL].yPos-20), 137, 70, DRAWLINE_TB, D3DCOLOR_ARGB(170, 107, 177, 228));

	if( GetAsyncKeyState(wKey) )
	{
		if( MouseIsOver((mainMenu[NULL].xPos+20), (mainMenu[NULL].yPos-20), 137, 70) )
		{
			mainMenu[NULL].xPos = (Mouse.xPos-135/2);
			mainMenu[NULL].yPos = (Mouse.yPos-10);
		}
	}
}

void evoMenu::DrawRectangle(int x, int y, int w, int h, DWORD Color, LPDIRECT3DDEVICE9 pDevice)
{
	DrawPolarLineD3D(x, (y + h-1), (w-1), DRAWLINE_LR, Color);//bottom
	DrawPolarLineD3D(x, y, h, DRAWLINE_TB, Color);//left
	DrawPolarLineD3D(x, y, (w-1), DRAWLINE_LR, Color);//top
	DrawPolarLineD3D((x + w), y, h, DRAWLINE_TB, Color);//right
}

void evoMenu::DrawWindow( char* title, int x, int y, int w, int h, DWORD InnerBorder, DWORD OuterBorder, LPDIRECT3DDEVICE9 pDevice )
{
	DrawTextD3D(x, (y-TEXT_SIZE), MENU_TEXT_COLOR, false, title);
	FillPolarD3D((x-5), y, w, h, DRAWLINE_TB, MENU_BACKGROUND_COLOR);

	DrawPolarLineD3D((x-5), (y + h - 1), w, DRAWLINE_LR, InnerBorder);//bottom
	DrawPolarLineD3D((x-4), y, h, DRAWLINE_TB, InnerBorder);//left
	DrawPolarLineD3D((x-5), y, w, DRAWLINE_LR, InnerBorder);//top
	DrawPolarLineD3D((x + w)-5, (y-1), h, DRAWLINE_TB, InnerBorder);//right

	DrawPolarLineD3D((x-5), (y + h - 1)+1, w, DRAWLINE_LR, OuterBorder);//bottom
	DrawPolarLineD3D((x-5), y, h, DRAWLINE_TB, OuterBorder);//left
	DrawPolarLineD3D((x-5), (y-1), w, DRAWLINE_LR, OuterBorder);//top
	DrawPolarLineD3D((x + w)-4, y, h, DRAWLINE_TB, OuterBorder);//right
}

void evoMenu::DrawButton( char* title, int txtPos, int x, int y, int w, int h, int px, int r, int g, int b, bool IsOverlay, DWORD Buttontext, DWORD overlay, DWORD InnerBorder, LPDIRECT3DDEVICE9 pDevice )
{
	GradientBox(x, y, w, h, r, g, b, pDevice);
	if( IsOverlay ){
		FillPolarD3D((x+1), y, w, (h/2.5), DRAWLINE_TB, overlay);
	}
	DrawPolarLineD3D((x-1), (y + h), (w+2), DRAWLINE_LR, InnerBorder);//bottom
	DrawPolarLineD3D(x, y, h, DRAWLINE_TB, InnerBorder);//left
	DrawPolarLineD3D(x, y, w, DRAWLINE_LR, InnerBorder);//top
	DrawPolarLineD3D((x + w +1), y, h, DRAWLINE_TB, InnerBorder);//right

	if( txtPos == 1 ){
		DrawTextD3D((x+w)+5, (y+5), Buttontext, false, title);
	} else if( txtPos == 2 ){
		float itextX = x+(w/2) - strlen(title)*5.0f/2; 
		DrawTextD3D(int(itextX), (y+5), Buttontext, false, title);
	}
}

void evoMenu::AddButton(char title[16], float *cvar, int min, int max)
{
	mainMenu[MAX_ITEMS].value = cvar;
    sprintf( mainMenu[MAX_ITEMS].title, title ); 
    mainMenu[MAX_ITEMS].max = max;
    mainMenu[MAX_ITEMS].min = min;
    MAX_ITEMS++;
}

void evoMenu::DrawMenu(char* text, int x, int y, DWORD dwSelected, DWORD dwNonSelected, DWORD dwEnabled, DWORD dwValues, LPDIRECT3DDEVICE9 pDevice )
{
	if( !bMenu )return;
	x = mainMenu[NULL].xPos;
	y = mainMenu[NULL].yPos;
	int Window_Width = 135;

	DrawWindow(text, x, (y-4), 135, (MAX_ITEMS * (BUTTON_HEIGHT+4))+5, MENU_INNER_BORDER_COLOR, MENU_OUTER_BORDER_COLOR, pDevice);//menu background
	for(int i = 0; i <= ( MAX_ITEMS - 1 ); i++)
    {
		if( mainMenu[i].value[0] > 0.00f ){
			DrawButton(mainMenu[i].title, 1, x, y + (i * (BUTTON_HEIGHT+4)), BUTTON_WIDTH, BUTTON_HEIGHT, 1, 0, 217, 54, true, MENU_BUTTON_TEXT_COLOR, MENU_BUTTON_OVERLAY_COLOR, MENU_INNER_BORDER_COLOR, pDevice);
		} else {
			DrawButton(mainMenu[i].title, 1, x, y + (i * (BUTTON_HEIGHT+4)), BUTTON_WIDTH, BUTTON_HEIGHT, 1, 255, 0, 0, true, MENU_BUTTON_TEXT_COLOR, MENU_BUTTON_OVERLAY_COLOR, MENU_INNER_BORDER_COLOR, pDevice);
		}
    }
}

void evoMenu::CheckGui( int wKey )
{
	if( GetAsyncKeyState( wKey )&1 ){ bMenu = !bMenu; }
	if( bMenu == false )return;

	for( int i = 0; i <= ( MAX_ITEMS - 1 ); i++ ) {
		if( MouseIsOver(mainMenu[NULL].xPos, mainMenu[NULL].yPos + (i * (BUTTON_HEIGHT+4)), BUTTON_WIDTH, BUTTON_HEIGHT) ){	
			if( KEY_DOWN(VK_LBUTTON) ){
				float iNextValue = ( mainMenu[i].value[0] + 1 );

				if( iNextValue <= mainMenu[i].max ){ mainMenu[i].value[0]++; }
				if( iNextValue > mainMenu[i].max ){ mainMenu[i].value[0] = ( float )mainMenu[i].min; }
				keybd_event( VK_LBUTTON, 0, KEYEVENTF_KEYUP, 0 );
			}
		}
	}
}