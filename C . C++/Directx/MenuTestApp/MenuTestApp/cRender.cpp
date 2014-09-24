/*
Made by Credzis
Only posted on UnknownCheats
Credit me if you use this
*/

#include "cRender.h"
#include "Main.h"
#include <stdio.h>

RenderClass Render;

void RenderClass::DrawString(int x, int y, DWORD color, LPD3DXFONT g_pFont, const char *fmt, ...)
{
	RECT FontPos = { x, y, x + 120, y + 16 };
	char buf[1024] = {'\0'};
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf(buf, fmt, va_alist);
	va_end(va_alist);

	g_pFont->DrawText(NULL, buf, -1, &FontPos, DT_NOCLIP, color);
}

void RenderClass::DrawRectangle(float x, float y, float w, int h, LPD3DXLINE g_pLine)
{

	D3DXVECTOR2 vLine1[2];
	D3DXVECTOR2 vLine2[2];
	D3DXVECTOR2 vLine3[2];
	D3DXVECTOR2 vLine4[2];

	vLine1[0].x = x; 
	vLine1[0].y = y; 
	vLine1[1].x = x; 
	vLine1[1].y = y+h;

	vLine2[0].x = x+w; 
	vLine2[0].y = y; 
	vLine2[1].x = x+w; 
	vLine2[1].y = y+h;

	vLine3[0].x = x; 
	vLine3[0].y = y; 
	vLine3[1].x = x+w; 
	vLine3[1].y = y;

	vLine4[0].x = x; 
	vLine4[0].y = y+h; 
	vLine4[1].x = x+w; 
	vLine4[1].y = y+h;

	g_pLine->SetWidth(2);
	g_pLine->SetAntialias(false);
	g_pLine->SetGLLines(false);
	g_pLine->Begin();
	g_pLine->Draw(vLine1, 2, 0xFF0000FF);
	g_pLine->Draw(vLine2, 2, 0xFF0000FF);
	g_pLine->Draw(vLine3, 2, 0xFF0000FF);
	g_pLine->Draw(vLine4, 2, 0xFF0000FF);
	g_pLine->End();

}

void RenderClass::FillRGBA(int x, int y, int w, int h, int r, int g, int b, int a)
{
	D3DXVECTOR2 vLine[2];

	Main.pLiner->SetWidth( w );
	Main.pLiner->SetAntialias( true );
	Main.pLiner->SetGLLines( true );

	vLine[0].x = x + w/2;
	vLine[0].y = y;
	vLine[1].x = x + w/2;
	vLine[1].y = y + h;

	Main.pLiner->Begin();
	Main.pLiner->Draw(vLine, 2, D3DCOLOR_RGBA( r, g, b, a ));
	Main.pLiner->End();
}

void RenderClass::FillRGBA(int x, int y, int w, int h, DWORD Color)
{
	D3DXVECTOR2 vLine[2];

	Main.pLiner->SetWidth( w );
	Main.pLiner->SetAntialias( true );
	Main.pLiner->SetGLLines( true );

	vLine[0].x = x + w/2;
	vLine[0].y = y;
	vLine[1].x = x + w/2;
	vLine[1].y = y + h;

	Main.pLiner->Begin();
	Main.pLiner->Draw(vLine, 2, Color);
	Main.pLiner->End();
}

void RenderClass::DrawOPX(int x, int y, int width, int height, int r, int g, int b, int a, int line)
{
	FillRGBA(x,y+height,width,line,r,g,b,a);
	FillRGBA(x,y,line,height,r,g,b,a);
	FillRGBA(x,y,width,line,r,g,b,a);
	FillRGBA(x+width,y,line,height,r,g,b,a);
}

void RenderClass::DrawStatsBox(int x, int y, int w, int h, int r, int g, int b, int a,int rr, int gg, int bb, int aa, int l)
{
	DrawOPX(x,y,w,h,r,g,b,a,l); 
	FillRGBA(x,y,w,h,rr,gg,bb,aa); 
}

void RenderClass::DrawBox(int x, int y, int w, int h, int r, int g, int b, int a,int rr, int gg, int bb, int aa, int l)
{
	DrawOPX(x,y,w,h,r,g,b,a,l); 
	FillRGBA(x,y,w,h,rr,gg,bb,aa); 
}