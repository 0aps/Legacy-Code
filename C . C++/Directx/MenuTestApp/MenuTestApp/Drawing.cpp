/*
	Made by Credzis
	Only posted on UnknownCheats
	Credit me if you use this
*/

#include "Drawing.h"
#include "Main.h"
#include "cMenu.h"
#include "cVars.h"

cDrawing Drawing;


void cDrawing::StartSceneDrawing( void )
{
	Render.DrawString(10, 10, D3DCOLOR_ARGB(255, 255, 255, 255), Main.pFont, "[*UnknownCheats Example Menu*]");
	m_Menu.DrawMenu();

	if(cVar.Aimbot)
	{
		Render.DrawString(300, 50, D3DCOLOR_ARGB(255, 255, 0, 0), Main.pFont, "[Aimbot Enabled !]");
	}
	if(cVar.NoFlash)
	{
		Render.DrawString(300, 70, D3DCOLOR_ARGB(255, 255, 0, 0), Main.pFont, "[NoFlash Enabled !]");
	}
	if(cVar.NoSmoke)
	{
		Render.DrawString(300, 90, D3DCOLOR_ARGB(255, 255, 0, 0), Main.pFont, "[NoSmoke Enabled !]");
	}
	if(cVar.FoV)
	{
		Render.DrawString(300, 110, D3DCOLOR_ARGB(255, 255, 0, 0), Main.pFont, "[FoV : %2.2f !]", cVar.FoV);
	}
	if(cVar.Meeeh)
	{
		Render.DrawString(300, 130, D3DCOLOR_ARGB(255, 255, 0, 0), Main.pFont, "[Meeh : %2.2f !]", cVar.Meeeh);
	}
}