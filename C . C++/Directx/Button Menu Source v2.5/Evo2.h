#ifndef EVO2_H 
#define EVO2_H 
#pragma once 

#include "stdafx.h"
#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

//Menu
#define MENU_BACKGROUND_COLOR						D3DCOLOR_ARGB(127, 107, 177, 228)//lightblue
#define MENU_INNER_BORDER_COLOR						D3DCOLOR_ARGB(127, 0, 0, 0)//black
#define MENU_OUTER_BORDER_COLOR						D3DCOLOR_ARGB(127, 255, 255, 255)//white
#define MENU_TEXT_COLOR								D3DCOLOR_ARGB(127, 107, 177, 228)//lightblue
//Button
#define MENU_BUTTON_TEXT_COLOR						D3DCOLOR_ARGB(127, 255, 255, 255)//white
#define MENU_BUTTON_OVERLAY_COLOR					D3DCOLOR_ARGB(85, 255, 255, 255)//white
#define MENU_BUTTON_SELECTED_COLOR					D3DCOLOR_ARGB(127, 0, 68, 111)//darkblue
#define MENU_BUTTON_NOSELECTED_COLOR				D3DCOLOR_ARGB(127, 107, 177, 228)//lightblue

#define COLOR_WHITE									D3DCOLOR_ARGB(255, 255, 255, 255) 


typedef D3DXMATRIX* (WINAPI* D3DXMatrixMultiply_t) (
		D3DXMATRIX*                          pOut,  
        CONST D3DXMATRIX*              pM1,  
        CONST D3DXMATRIX*              pM2); 

typedef D3DXMATRIX* (WINAPI* D3DXMatrixTransformation2D_t) ( 
        D3DXMATRIX*                          pOut,  
        CONST D3DXVECTOR2*           pScalingCenter,  
        FLOAT                                      ScalingRotation,  
        CONST D3DXVECTOR2*           pScaling,  
        CONST D3DXVECTOR2*           pRotationCenter,  
        FLOAT                                      Rotation,  
        CONST D3DXVECTOR2*           pTranslation);

struct pMenu
{
    char title[16]; 
    float* value;
	int xPos, yPos;
    int max, min, name;
};

struct pMouse
{
	int xPos, yPos;
};

class evoMenu 
{ 
public: 
     evoMenu( int MAX_MENU ); 
    ~evoMenu( ); 

    void    OnLostDevice( ); 
    void    OnResetDevice( ); 

    bool    InitRendering(char *strFontName, char *strFontPath, int size, UINT Thick, bool Italic, LPDIRECT3DDEVICE9 pDevice, bool IsTTF);
    void    FillRectD3D( int x, int y, int iWidth, int iHeight, DWORD dwColor ); 
	void	DrawTextD3D( int x, int y, DWORD dwColor, bool bEspFont, char* szText, ... );

    void    DrawNormalLineD3D( int iStartX, int iStartY, int iEndX, int iEndY, DWORD dwColor );
	void	FillPolarD3D(int iStartX, int iStartY, int width, float flLength, float flAngle, DWORD dwColor);
	void	DrawPolarLineD3DEx(int iStartX, int iStartY, float flLength, float flAngle, int a, int r, int g, int b);
    void    DrawPolarLineD3D( int iStartX, int iStartY, float flLength, float flAngle, DWORD dwColor ); 


	void	zEndScene(IDirect3DDevice9* pD3Ddev);
	bool	MouseIsOver(int x, int y, int w, int h);
	void	GradientBox(int x, int y, int w, int h, int r, int g, int b, LPDIRECT3DDEVICE9 pDevice);
	void	DrawButton( char* title, int txtPos, int x, int y, int w, int h, int px, int r, int g, int b, bool IsOverlay, DWORD Buttontext, DWORD overlay, DWORD InnerBorder, LPDIRECT3DDEVICE9 pDevice );
	void	DrawWindow( char* title, int x, int y, int w, int h, DWORD InnerBorder, DWORD OuterBorder, LPDIRECT3DDEVICE9 pDevice );

	void	DrawMouse();
	void	CheckGui( int wKey );
	void	MovableMenu(int wKey, int x, int y);
	void	AddButton(char title[16], float *cvar, int min, int max);
	void	DrawRectangle(int x, int y, int w, int h, DWORD Color, LPDIRECT3DDEVICE9 pDevice);
	void	DrawMenu(char* text, int x, int y, DWORD dwSelected, DWORD dwNonSelected, DWORD dwEnabled, DWORD dwValues, LPDIRECT3DDEVICE9 pDevice );

    static HRESULT    GenerateTexture( IDirect3DDevice9 *pD3Ddev, IDirect3DTexture9 **ppD3Dtex, DWORD colour32 ); 
    static bool       GetD3DXFunctions( ); 
    static HMODULE    FindD3DXModule( ); 
	bool   bMenu;
private:
	int						MAX_ITEMS, MAX_WINDOW;
    LPD3DXFONT				m_pFont; 
    LPD3DXFONT				m_pEspFont; 
    LPD3DXSPRITE			m_pSprite; 
    LPDIRECT3DTEXTURE9		m_pTexWhite; 
    LPDIRECT3DDEVICE9		m_pDevice;
	pMenu*					mainMenu;
}; 

#endif 