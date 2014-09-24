// -----------------------------------------------------------------------------
// Project : HackBase v1.0
// Author  : Hans211
// Date    : 11 April 2009
//
// A basic D3D framework:
// - D3D menu with folders
// - Optimized d3dfont, right aligned text
// - Works for d3d8 or d3d9  (define it in main.h)
// -----------------------------------------------------------------------------
#include "d3dbase.h"
#include <stdio.h>


char	sFPS[20]="xxx Fps";
int     CH_back       = 2;		// 40%

// group states
int		CH_cheats	  = 1;
int		CH_weap	      = 1;
// item  states
int		CH_stamina	  = 1;		// stealth as default
int		CH_fastammo   = 1;
int		CH_fasthealth = 0;
int		CH_fastrepair = 0;
int		CH_fastflag   = 1;
int		CH_nospread   = 1;
int		CH_norecoil   = 1;
int		CH_unlammo	  = 1;

// none standard options
char	*opt_Grp[]     = { "+","-" };
char	*opt_OffOn[]   = { "Off","On" };
char	*opt_Stamina[] = { "Off","Stealth","Full" };
char	*opt_Back[]    = { "Off","20%","40%","60%","80%","Solid" };

D3DMenu	*pMenu=NULL;


// Change this to make your own menu	
void RebuildMenu(void)
{
  pMenu->AddItem("Background"        , &CH_back      , opt_Back, 6);
  pMenu->AddText("Framerate", sFPS);
 
  pMenu->AddGroup("[Cheats]" , &CH_cheats, opt_Grp);
  if (CH_cheats) {
	  pMenu->AddItem("Stamina"       , &CH_stamina   , opt_Stamina, 3);
	  pMenu->AddItem("Fast ammo"     , &CH_fastammo  , opt_OffOn);
	  pMenu->AddItem("Fast health"   , &CH_fasthealth, opt_OffOn);
	  pMenu->AddItem("Fast repair"   , &CH_fastrepair, opt_OffOn);
	  pMenu->AddItem("Fast flag"     , &CH_fastflag  , opt_OffOn);
  }
  pMenu->AddGroup("[Weapons]", &CH_weap  , opt_Grp);
  if (CH_weap) {
	  pMenu->AddItem("No spread"	 , &CH_nospread  , opt_OffOn);
	  pMenu->AddItem("No recoil"	 , &CH_norecoil  , opt_OffOn);
	  pMenu->AddItem("Unlimited ammo", &CH_unlammo   , opt_OffOn);
  }
}

// --- simple FPS vars and function
int	  FPScounter = 0;
float FPSfLastTickCount = 0.0f;
float FPSfCurrentTickCount;

void FPScheck(char *str, char *format)
{
	FPSfCurrentTickCount = clock() * 0.001f;
	FPScounter++;

	if((FPSfCurrentTickCount - FPSfLastTickCount) > 1.0f) {
	    FPSfLastTickCount = FPSfCurrentTickCount;
		sprintf(str,format,FPScounter);
	    FPScounter = 0;
	} 
}

// Draw a background
void DrawGui(pD3DdeviceX pDevice, DWORD col)
{
	if (CH_back==5)					// solid
		col|=0xff000000;
	else
		col|=CH_back*0x30000000;	// transparency
	DrawBox(pDevice,pMenu->x-3,pMenu->y-2,pMenu->totwidth+6,pMenu->totheight+4  ,col);
	DrawBox(pDevice,pMenu->x-3,pMenu->y-2,pMenu->totwidth+6,pMenu->titleheight+1,col|0xff000000);
}

// called with every EndScene
void DoMenu(pD3DdeviceX pDevice)
{
	if (pMenu==0) {												// first time , create the menu
	    pMenu = new D3DMenu("== Hans211 D3D Base ==",100,160);	// title, maxitems,width
		pMenu->visible=1;										// make it visible
		pMenu->col_title=0xffffffff;							// change title color to white
	} else {
		FPScheck(sFPS,"%d Fps");
		if (pMenu->noitems==0) RebuildMenu();
		if (pMenu->visible && CH_back) DrawGui(pDevice,0x000000);  // black background
	    pMenu->Show(pFont);
		pMenu->Nav();
	}
}


// Seperate thread for making hacks
DWORD WINAPI HACKthread( LPVOID param )
{
    // --- hack loop
	while (1) {
		
		// ..if (CH_stamina)   ....
		// ..
		
		// ..
		// ..
		
		Sleep(50);
    }
	return 0;
}