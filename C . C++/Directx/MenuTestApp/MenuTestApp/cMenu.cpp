/*
Made by Credzis
Only posted on UnknownCheats
Credit me if you use this
*/

#include "cMenu.h"
#include "cVars.h"
#include "cRender.h"
#include "Main.h"

cMenu m_Menu;
cVars cVar;

static bool bDoOnce = false;

void cMenu::InitItems()
{
	if(!bDoOnce)
	{
		AddMenuItem("Aimbot", &cVar.Aimbot, 1, 0, 1);
		AddMenuItem("NoFlash", &cVar.NoFlash, 1, 0, 1);
		AddMenuItem("NoSmoke", &cVar.NoSmoke, 1, 0, 1);
		AddMenuItem("FoV", &cVar.FoV, 1, 0, 360);
		AddMenuItem("Meeh", &cVar.Meeeh, 5, 0, 50);	
		bDoOnce = true;
	}
}

void cMenu::DrawMenuBackground()
{
	if(bMenu)
	{
		Render.DrawBox(20, 20, 125, 20, 184, 184, 184, 255, 255, 255, 255, 100,1);	// Title Box
		Render.DrawString(40, 25, D3DCOLOR_ARGB(255,255,204,51), Main.pFont, "[**Menu**]");	// Title Text
		Render.DrawBox(20, 45, 125, 300, 184, 184, 184, 255, 255, 255, 255, 100, 1); // Menu Box
	}
}

void cMenu::AddMenuItem(std::string Label, float *cVar, int step, int min, int max)
{
	std::vector<MenuPtr>::iterator itMenuItem;

	MenuPtr menu_ptr(new tMenuItem(Label));
	vMenuItems.push_back(menu_ptr);
	itMenuItem = vMenuItems.end() - 1;

	(*itMenuItem)->cVar = cVar;
	(*itMenuItem)->Step = step;
	(*itMenuItem)->Min = min;
	(*itMenuItem)->Max = max;
}

void cMenu::DrawMenu()
{
	InitItems();
	DrawMenuBackground();
	DrawMenuItems();
}

void cMenu::DrawMenuItems()
{
	std::vector<MenuPtr>::iterator itMenuItem;

	if(GetAsyncKeyState(VK_DELETE)&1)
		bMenu = !bMenu;
	if(!bMenu)
		return;

	if(this->vMenuItems.empty() == true)
	{
		::MessageBox(NULL, "Error occured ! No menu item's found !", "UnknownCheats KeyMenu", MB_OK);
		return;
	}

	KeyMenuEvent();
	
	int valItems = -1;

	for(itMenuItem = this->vMenuItems.begin(); itMenuItem < this->vMenuItems.end(); itMenuItem++)
	{
		valItems++;
		if(valItems == MenuIndex)
		{
			Render.DrawString(25, 50+(16*valItems), D3DCOLOR_ARGB(255, 0, 255, 0), Main.pFont, (*itMenuItem)->title.c_str());
			Render.DrawString(50, 50+(16*valItems), D3DCOLOR_ARGB(255, 0, 255, 0), Main.pFont, "               %2.2f", (*itMenuItem)->cVar[0]);
		}
		else
		{
			Render.DrawString(25, 50+(16*valItems), D3DCOLOR_ARGB(255, 255, 0, 0), Main.pFont, (*itMenuItem)->title.c_str());
			Render.DrawString(50, 50+(16*valItems), D3DCOLOR_ARGB(255, 255, 0, 0), Main.pFont, "               %2.2f", (*itMenuItem)->cVar[0]);
		}
	}
}

bool cMenu::KeyMenuEvent()
{
	if( GetAsyncKeyState(VK_UP) & 1) 
	{
		if( MenuIndex>0 ) MenuIndex--;
		else MenuIndex = vMenuItems.size() - 1;
		return 0;
	}
	else if( GetAsyncKeyState(VK_DOWN) & 1) 
	{
		if( MenuIndex<vMenuItems.size() -1 ) MenuIndex++;
		else MenuIndex = 0;
		return 0;
	}
	else if( GetAsyncKeyState(VK_LEFT) & 1) 
	{
		if( vMenuItems[MenuIndex]->cVar )
		{
			vMenuItems[MenuIndex]->cVar[0] -= vMenuItems[MenuIndex]->Step;
			if( vMenuItems[MenuIndex]->cVar[0] < vMenuItems[MenuIndex]->Min )
				vMenuItems[MenuIndex]->cVar[0] = vMenuItems[MenuIndex]->Max;
		}
		return 0;
	}
	else if( GetAsyncKeyState(VK_RIGHT) & 1) 
	{
		if( vMenuItems[MenuIndex]->cVar )
		{
			vMenuItems[MenuIndex]->cVar[0] += vMenuItems[MenuIndex]->Step;
			if( vMenuItems[MenuIndex]->cVar[0] > vMenuItems[MenuIndex]->Max )
				vMenuItems[MenuIndex]->cVar[0] = vMenuItems[MenuIndex]->Min;
		}
		return 0;
	}
	return 1;
}