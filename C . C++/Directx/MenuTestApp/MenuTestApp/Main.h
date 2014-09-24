/*
Made by Credzis
Only posted on UnknownCheats
Credit me if you use this
*/

#pragma once

#include <d3dx9.h>

class cMain
{
public:
	LPDIRECT3D9 d3d;    // the pointer to our Direct3D interface
	LPDIRECT3DDEVICE9 d3ddev;    // the pointer to the device class
	LPD3DXFONT pFont;
	LPD3DXLINE pLiner;
	D3DVIEWPORT9 pViewPort;
};

extern cMain Main;