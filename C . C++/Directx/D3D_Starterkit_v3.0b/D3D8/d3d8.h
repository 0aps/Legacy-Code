#ifndef _D3D8_H
#define _D3D8_H

#pragma comment(lib, "d3d8.lib")
#pragma comment(lib, "d3dx8.lib")
#include <windows.h>
#include <d3d8.h>
#include <d3dx8.h>
#include "d3d8int.h"
#include "d3d8dev.h"
#include "d3d8tex.h"

typedef IDirect3D8 *(APIENTRY *tDirect3DCreate8)(UINT);
extern tDirect3DCreate8 oDirect3DCreate8;

IDirect3D8 *APIENTRY hkDirect3DCreate8(UINT SDKVersion);

#endif