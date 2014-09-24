 
//menu2.h
 
// Project : Basic D3D Menu v1.4
// Author : Hans211
// Date : 11 April 2009
#ifndef _D3DMENU_H
#define _D3DMENU_H
#include "Soldierfront.h"
 
#ifndef D3DFONT_RIGHT
#define D3DFONT_RIGHT 0x0008
#endif
#ifndef D3DFONT_SHADOW
#define D3DFONT_SHADOW 0x0010
#endif
#define MENUGROUP 1
#define MENUTEXT 2
#define MENUITEM 3
#define MCOLOR_TITLE 0xffff1111
#define MCOLOR_CURRENT 0xffff0000
#define MCOLOR_GROUP 0xffffff00
#define MCOLOR_TEXT 0xffe0e0e0
#define MCOLOR_OFF 0xffa0a0a0
#define MCOLOR_ON 0xffffffff
typedef struct {
int typ; // type of menuline, folder, item
char *txt; // text to show
char **opt; // array of options
int *var; // variable containing current status
int maxval; // maximumvalue, normally 1 gives 0=off 1=on
} tMENU;
class D3DMenu
{
public:
D3DMenu(char *Name=0, int maxentries=99, int maxwidth=160)
{
title=Name;
maxitems=maxentries;
cur=noitems=visible=0;
x=y=15;
totwidth=ofs=maxwidth;
height=15;
titleheight=totheight=height+4;
col_title =MCOLOR_TITLE;
col_group =MCOLOR_GROUP;
col_text =MCOLOR_TEXT;
col_off =MCOLOR_OFF;
col_on =MCOLOR_ON;
col_current=MCOLOR_CURRENT;
// allocate menu array
MENU=(tMENU **)malloc(4*maxitems);
for (int i=0; i<maxitems; i++) MENU[i]=(tMENU *)malloc(sizeof(tMENU));
}
~D3DMenu() {
for (int i=0; i<maxitems; i++) free(MENU[i]);
free(MENU);
}
// colors
DWORD col_title;
DWORD col_group;
DWORD col_text;
DWORD col_off;
DWORD col_on;
DWORD col_current;
// position and sizes
int x,y; // current position of the menu
int totwidth,totheight; // total width and height of menu
int height; // height of 1 menuline
int titleheight; // some extra height for a title
int ofs; // offset for option text
// menu vars
char *title; // some menu title
int cur; // current highlighted menuitem 
int noitems; // number of menu items
int visible; // 1 = menu is visible
tMENU **MENU;
 
void AddItem (char *txt, int *var, char **opt, int maxvalue=2, int typ=MENUITEM);
void AddGroup(char *txt, int *var, char **opt, int maxvalue=2);
void AddText (char *txt, char *opt="");
void Show(CD3DFont *pFont);
void Nav(void);
private:
int maxitems;
};
#endif
