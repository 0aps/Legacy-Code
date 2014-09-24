 
#include "menu2.h"
#include "stdafx.h"
extern CD3DFont *pFont;
void DrawBox(LPDIRECT3DDEVICE8 pDevice, int x, int y, int w, int h, D3DCOLOR color);
void PreReset (LPDIRECT3DDEVICE8 pDevice);
void PostReset(LPDIRECT3DDEVICE8 pDevice);
extern int noFPS;
void RebuildMenu(void);
void DoMenu(LPDIRECT3DDEVICE8 pDevice);
