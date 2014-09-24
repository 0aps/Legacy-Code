/*
Made by Credzis
Only posted on UnknownCheats
Credit me if you use this
*/

#ifndef _RENDER_H_
#define _RENDER_H_

#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>

class RenderClass
{
public:
	void DrawString (int x, int y, DWORD color, LPD3DXFONT g_pFont, const char *fmt, ...);
	void DrawRectangle(float x, float y, float w, int h, LPD3DXLINE g_pLine);
	void FillRGBA(int x, int y, int w, int h, int r, int g, int b, int a);
	void FillRGBA(int x, int y, int w, int h, DWORD Color);
	void Border(LPDIRECT3DDEVICE9 pDevice, int baseX, int baseY, int baseW, int baseH , D3DCOLOR Color );
	void DrawOPX(int x, int y, int width, int height, int r, int g, int b, int a, int line);
	void DrawStatsBox(int x, int y, int w, int h, int r, int g, int b, int a,int rr, int gg, int bb, int aa, int l);
	void DrawBox(int x, int y, int w, int h, int r, int g, int b, int a,int rr, int gg, int bb, int aa, int l);
};

#endif

extern RenderClass Render;