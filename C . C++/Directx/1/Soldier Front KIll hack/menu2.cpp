#include "stdafx.h"
#include "menu2.h"
// Adding items, group, text to the menu
void D3DMenu::AddItem(char *txt, int *var, char **opt, int maxval, int typ)
{
if (noitems>=(maxitems-1)) return;
MENU[noitems]->typ=typ;
MENU[noitems]->txt=txt;
MENU[noitems]->opt=opt;
MENU[noitems]->var=var;
MENU[noitems]->maxval=maxval;
noitems++;
totheight=(noitems*height)+titleheight;
}
void D3DMenu::AddGroup(char *txt, int *var, char **opt, int maxval)
{
AddItem(txt, var, opt, maxval, MENUGROUP);
}
void D3DMenu::AddText(char *txt, char *opt)
{
AddItem(txt,0,(char **)opt,0,MENUTEXT);
}
// Show the Menu
void D3DMenu::Show(CD3DFont *pFont)
{
int i,val,cy;
DWORD color;
 
if (!visible) return;
cy=y;
if (title) {
pFont->DrawText((float)(x+totwidth/2), (float)cy+1, col_title,title,D3DFONT_SHADOW|D3DFONT_CENTERED);
cy+=titleheight;
}
for (i=0; i<noitems; i++) {
if (MENU[i]->typ==MENUTEXT) {
pFont->DrawText((float)x, (float)cy, col_text,MENU[i]->txt,D3DFONT_SHADOW);
if (MENU[i]->opt) {
pFont->DrawText((float)(x+ofs), (float)cy, col_text,(char *)MENU[i]->opt, D3DFONT_RIGHT|D3DFONT_SHADOW);
}
} else {
val=(MENU[i]->var)?(*MENU[i]->var):0;
// determine color
if (i==cur)
color=col_current;
else if (MENU[i]->typ==MENUGROUP)
color=col_group;
else
color=(val)?col_on:col_off;
pFont->DrawText((float)x, (float)cy, color,MENU[i]->txt,D3DFONT_SHADOW);
if (MENU[i]->opt) {
pFont->DrawText((float)(x+ofs), (float)cy, color,(char *)MENU[i]->opt[val],D3DFONT_RIGHT|D3DFONT_SHADOW);
}
}
cy+=height;
}
}
// check for Menu navigation keys
void D3DMenu::Nav(void)
{
if (GetAsyncKeyState(VK_INSERT)&1) visible=(!visible);
if (!visible) return;
if (GetAsyncKeyState(VK_CONTROL) ) {
if (GetAsyncKeyState(VK_UP)&1 ) y-=10;
if (GetAsyncKeyState(VK_DOWN)&1 ) y+=10;
if (GetAsyncKeyState(VK_LEFT)&1 ) x-=10;
if (GetAsyncKeyState(VK_RIGHT)&1) x+=10;
} else {
if (GetAsyncKeyState(VK_UP)&1) {
do {
cur--;
if (cur<0) cur=noitems-1;
} while (MENU[cur]->typ==MENUTEXT); // skip textitems
} else if (GetAsyncKeyState(VK_DOWN)&1) {
do {
cur++;
if (cur==noitems) cur=0;
} while (MENU[cur]->typ==MENUTEXT); // skip textitems
} else if (MENU[cur]->var) {
int dir=0;
// bugfix: thx to Dxt-Wieter20
if (GetAsyncKeyState(VK_LEFT )&1 && *MENU[cur]->var > 0 ) dir=-1;
if (GetAsyncKeyState(VK_RIGHT)&1 && *MENU[cur]->var < (MENU[cur]->maxval-1)) dir=1;
if (dir) {
*MENU[cur]->var += dir;
if (MENU[cur]->typ==MENUGROUP) noitems=0; // change on menufolder, force a rebuild
}
}
}
}
