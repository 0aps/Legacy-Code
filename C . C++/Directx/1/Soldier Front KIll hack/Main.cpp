#include "stdafx.h"
using namespace std;
#include <iostream>
//==================================Defines============================================
#define ForceRecon (nNumVertices == 83 && nPrimitiveCount == 137 || nNumVertices == 79 && nPrimitiveCount == 105 || nNumVertices == 142 && nPrimitiveCount == 174 || nNumVertices == 278 && nPrimitiveCount == 462 || nNumVertices == 263 && nPrimitiveCount == 290 || nNumVertices == 316 && nPrimitiveCount == 556)
#define ForceReconAddons (nNumVertices == 432 && nPrimitiveCount == 354 || nNumVertices == 144 && nPrimitiveCount == 136 || nNumVertices == 299 && nPrimitiveCount == 311 || nNumVertices == 167 && nPrimitiveCount == 252 || nNumVertices == 298 && nPrimitiveCount == 506 || nNumVertices == 168 && nPrimitiveCount == 254 || nNumVertices == 860 && nNumVertices == 778 || nNumVertices == 648 && nPrimitiveCount == 710 || nNumVertices == 113 && nPrimitiveCount == 189 || nNumVertices == 142 && nPrimitiveCount == 172 || nNumVertices == 87 && nPrimitiveCount == 90 || nNumVertices == 79 && nPrimitiveCount == 105 || nNumVertices == 84 && nPrimitiveCount == 110 || nNumVertices == 70 && nPrimitiveCount == 70 || nNumVertices == 860 && nPrimitiveCount == 778 || nNumVertices == 85 && nPrimitiveCount == 137)
#define Mulan (nNumVertices == 118 && nPrimitiveCount == 126|| nNumVertices == 121 && nPrimitiveCount == 180|| nNumVertices == 124 && nPrimitiveCount == 126|| nNumVertices == 295 && nPrimitiveCount == 482|| nNumVertices == 299 && nPrimitiveCount == 452|| nNumVertices == 474 && nPrimitiveCount == 728)
#define MulanAddons (nNumVertices == 162 && nPrimitiveCount == 200|| nNumVertices == 120 && nPrimitiveCount == 188|| nNumVertices == 167 && nPrimitiveCount == 276|| nNumVertices == 108 && nPrimitiveCount == 198|| nNumVertices == 512 && nPrimitiveCount == 728|| nNumVertices == 790 && nPrimitiveCount == 881|| nNumVertices == 619 && nPrimitiveCount == 800|| nNumVertices == 399 && nPrimitiveCount == 532|| nNumVertices == 402 && nPrimitiveCount == 580|| nNumVertices == 102 && nPrimitiveCount == 170|| nNumVertices == 125 && nPrimitiveCount == 98|| nNumVertices == 116 && nPrimitiveCount == 128|| nNumVertices == 160 && nPrimitiveCount == 174) 
//=====================================================================================================================================================================================================================================================================================================================//
#pragma warning(disable:4305)
//=====================================================================================
int nofog; 
int XQZ;
int m_Stride;
int FullBright;
int texnum;
int nNumVertices;
int nPrimitiveCount;
LPDIRECT3DTEXTURE8 texRed,texGreen,texYellow,texOrange,texBlue,texCyan,texPink,texPurple,texWhite,texBlack,texSteelBlue,texBrown,texTeal,texLightSteelBlue,texLightBlue,texSalmon,texLime,texElectricLime,texGold,texOrangeRed,texGreenYellow,texAquaMarine,texSkyBlue,texSlateBlue,texCrimson,texDarkOliveGreen,texPaleGreen,texDarkGoldenRod,texFireBrick,texDarkBlue,texDarkerBlue,texDarkYellow,texLightYellow;
float ScreenCenterX = 0.0f;
float ScreenCenterY = 0.0f;
int xhair;
int chams;
bool Color = true;
D3DCOLOR redt = D3DCOLOR_XRGB( 255, 0, 0 );
int NoSmoke;
int NoFlash;
int WhiteWalls;
int AsusWalls;
int GlassWalls;
int ClearScope;
int Red;
int Orange;
int Green;
int Yellow;
int Blue;
int Cyan;
int Pink;
int Purple;
int White;
int Black;
int SteelBlue;
int LightSteelBlue;
int Brown;
int Teal;
int LightBlue;
int Salmon;
int Lime;
int ElectricLime;
int Gold;
int OrangeRed;
int GreenYellow;
int AquaMarine;
int SkyBlue;
int SlateBlue;
int Crimson;
int DarkOliveGreen;
int PaleGreen;
int DarkGoldenRod;
int FireBrick;
int DarkBlue;
int DarkerBlue;
int DarkYellow;
int LightYellow;
int Red2;
int Orange2;
int Green2;
int Yellow2;
int Blue2;
int Cyan2;
int Pink2;
int Purple2;
int White2;
int Black2;
int SteelBlue2;
int LightSteelBlue2;
int Brown2;
int Teal2;
int LightBlue2;
int Salmon2;
int Lime2;
int ElectricLime2;
int Gold2;
int OrangeRed2;
int GreenYellow2;
int AquaMarine2;
int SkyBlue2;
int SlateBlue2;
int Crimson2;
int DarkOliveGreen2;
int PaleGreen2;
int DarkGoldenRod2;
int FireBrick2;
int DarkBlue2;
int DarkerBlue2;
int DarkYellow2;
int LightYellow2;
//=====================================================================================
HRESULT GenerateTexture(IDirect3DDevice8 *pD3Ddev, IDirect3DTexture8 **ppD3Dtex, DWORD colour32)
{
if( FAILED(pD3Ddev->CreateTexture(8, 8, 1, 0, D3DFMT_A4R4G4B4, D3DPOOL_MANAGED, ppD3Dtex)) )
return E_FAIL;
 
WORD colour16 = ((WORD)((colour32>>28)&0xF)<<12)
|(WORD)(((colour32>>20)&0xF)<<8)
|(WORD)(((colour32>>12)&0xF)<<4)
|(WORD)(((colour32>>4)&0xF)<<0);
 
D3DLOCKED_RECT d3dlr; 
(*ppD3Dtex)->LockRect(0, &d3dlr, 0, 0);
WORD *pDst16 = (WORD*)d3dlr.pBits;
 
for(int xy=0; xy < 8*8; xy++)
*pDst16++ = colour16;
 
(*ppD3Dtex)->UnlockRect(0);
 
return S_OK;
}
//=====================================================================================
typedef HRESULT (WINAPI* CreateDevice_Prototype) (LPDIRECT3D8, UINT, D3DDEVTYPE, HWND, DWORD, D3DPRESENT_PARAMETERS*, LPDIRECT3DDEVICE8*);
typedef HRESULT (WINAPI* Reset_Prototype) (LPDIRECT3DDEVICE8, D3DPRESENT_PARAMETERS*);
typedef HRESULT (WINAPI* EndScene_Prototype) (LPDIRECT3DDEVICE8);
typedef HRESULT (WINAPI* DrawIndexedPrimitive_Prototype)(LPDIRECT3DDEVICE8, D3DPRIMITIVETYPE, UINT, UINT, UINT, UINT);
typedef HRESULT (WINAPI* SetViewport_Prototype) (LPDIRECT3DDEVICE8 ,CONST D3DVIEWPORT8*);
CreateDevice_Prototype CreateDevice_Pointer ;
Reset_Prototype Reset_Pointer ;
EndScene_Prototype EndScene_Pointer ;
DrawIndexedPrimitive_Prototype DrawIndexedPrimitive_Pointer ;
SetViewport_Prototype SetViewport_Pointer ;
HRESULT WINAPI Direct3DCreate8_VMTable (VOID);
HRESULT WINAPI CreateDevice_Detour (LPDIRECT3D8, UINT, D3DDEVTYPE, HWND, DWORD, D3DPRESENT_PARAMETERS*, LPDIRECT3DDEVICE8*);
HRESULT WINAPI Reset_Detour (LPDIRECT3DDEVICE8, D3DPRESENT_PARAMETERS*);
HRESULT WINAPI EndScene_Detour (LPDIRECT3DDEVICE8);
HRESULT WINAPI DrawIndexedPrimitive_Detour(LPDIRECT3DDEVICE8, D3DPRIMITIVETYPE, UINT, UINT, UINT, UINT);
HRESULT WINAPI SetViewport_Detour (LPDIRECT3DDEVICE8 ,CONST D3DVIEWPORT8*);
PDWORD Direct3D_VMTable = NULL;
//=====================================================================================
 
BOOL WINAPI DllMain(HINSTANCE hinstModule, DWORD dwReason, LPVOID lpvReserved)
{
if(dwReason == DLL_PROCESS_ATTACH)
{
DisableThreadLibraryCalls(hinstModule);
 
if(Direct3DCreate8_VMTable() == D3D_OK)
return TRUE;
}
 
return FALSE;
}
 
//=====================================================================================
//=====================================================================================
CD3DFont *pFont=NULL;
 
void PreReset(LPDIRECT3DDEVICE8 Device_Interface)
{
if (pFont) {
pFont->InvalidateDeviceObjects();
pFont->DeleteDeviceObjects();
pFont = NULL;
}
}
void PostReset(LPDIRECT3DDEVICE8 Device_Interface)
{
pFont = new CD3DFont("Arial", 10, D3DFONT_BOLD);
if (pFont) {
pFont->InitDeviceObjects(Device_Interface);
pFont->RestoreDeviceObjects();
}
}
 
//=====================================================================================
//=====================================================================================
HRESULT WINAPI Reset_Detour(LPDIRECT3DDEVICE8 Device_Interface, D3DPRESENT_PARAMETERS* PresentationParameters)
{
PreReset(Device_Interface);
return Reset_Pointer(Device_Interface, PresentationParameters);
}
//=====================================================================================
HRESULT WINAPI EndScene_Detour(LPDIRECT3DDEVICE8 Device_Interface)
{
if(Color)
{ 
GenerateTexture(Device_Interface, &texGreen , D3DCOLOR_ARGB(255,0,255,0));
GenerateTexture(Device_Interface, &texRed , D3DCOLOR_ARGB(255,255,0,0));
GenerateTexture(Device_Interface, &texBlue , D3DCOLOR_ARGB(255,0,0,255));
GenerateTexture(Device_Interface, &texOrange , D3DCOLOR_ARGB(255,255,165,0));
GenerateTexture(Device_Interface, &texYellow , D3DCOLOR_ARGB(255,255,255,0));
GenerateTexture(Device_Interface, &texPink , D3DCOLOR_ARGB(255,255,192,203));
GenerateTexture(Device_Interface, &texCyan , D3DCOLOR_ARGB(255,0,255,255));
GenerateTexture(Device_Interface, &texPurple , D3DCOLOR_ARGB(255,160,32,240));
GenerateTexture(Device_Interface, &texBlack , D3DCOLOR_ARGB(255,0,0,0));
GenerateTexture(Device_Interface, &texWhite , D3DCOLOR_ARGB(255,255,255,255));
GenerateTexture(Device_Interface, &texSteelBlue , D3DCOLOR_ARGB(255,33,104,140));
GenerateTexture(Device_Interface, &texLightSteelBlue, D3DCOLOR_ARGB(255,201,255,255));
GenerateTexture(Device_Interface, &texLightBlue , D3DCOLOR_ARGB(255,26,140,306));
GenerateTexture(Device_Interface, &texSalmon , D3DCOLOR_ARGB(255,196,112,112));
GenerateTexture(Device_Interface, &texBrown , D3DCOLOR_ARGB(255,168,99,20));
GenerateTexture(Device_Interface, &texTeal , D3DCOLOR_ARGB(255,38,140,140));
GenerateTexture(Device_Interface, &texLime , D3DCOLOR_ARGB(255,50,205,50));
GenerateTexture(Device_Interface, &texElectricLime , D3DCOLOR_ARGB(255,204,255,0));
GenerateTexture(Device_Interface, &texGold , D3DCOLOR_ARGB(255,255, 215, 0));
GenerateTexture(Device_Interface, &texOrangeRed , D3DCOLOR_ARGB(255,255,69,0));
GenerateTexture(Device_Interface, &texGreenYellow , D3DCOLOR_ARGB(255,173,255,47));
GenerateTexture(Device_Interface, &texAquaMarine , D3DCOLOR_ARGB(255,127,255,212));
GenerateTexture(Device_Interface, &texSkyBlue , D3DCOLOR_ARGB(255,0,191,255));
GenerateTexture(Device_Interface, &texSlateBlue , D3DCOLOR_ARGB(255,132, 112, 255));
GenerateTexture(Device_Interface, &texCrimson , D3DCOLOR_ARGB(255,220,20,60));
GenerateTexture(Device_Interface, &texDarkOliveGreen, D3DCOLOR_ARGB(255,188,238,104 ));
GenerateTexture(Device_Interface, &texPaleGreen , D3DCOLOR_ARGB(255,154,255, 154));
GenerateTexture(Device_Interface, &texDarkGoldenRod , D3DCOLOR_ARGB(255,255, 185, 15 ));
GenerateTexture(Device_Interface, &texFireBrick , D3DCOLOR_ARGB(255,255,48,48));
GenerateTexture(Device_Interface, &texDarkBlue , D3DCOLOR_ARGB(255,0,0,204));
GenerateTexture(Device_Interface, &texDarkerBlue , D3DCOLOR_ARGB(255,0,0,153));
GenerateTexture(Device_Interface, &texDarkYellow , D3DCOLOR_ARGB(255,255,204,0));
GenerateTexture(Device_Interface, &texLightYellow , D3DCOLOR_ARGB(255,255,255,153));
Color=false;
}
if(xhair)
{
D3DRECT rec4 = {ScreenCenterX-35, ScreenCenterY, ScreenCenterX+ 35, ScreenCenterY+1};
D3DRECT rec5 = {ScreenCenterX, ScreenCenterY-35, ScreenCenterX+ 1,ScreenCenterY+35}; 
Device_Interface->Clear( 1, &rec4, D3DCLEAR_TARGET, D3DXCOLOR(0.62745098, 0.125490, 0.959999, 1.0), 0, 0 );//purple
Device_Interface->Clear( 1, &rec5, D3DCLEAR_TARGET, D3DXCOLOR(0.62745098, 0.125490, 0.959999, 1.0), 0, 0 ); 
D3DRECT rec6 = {ScreenCenterX-30, ScreenCenterY, ScreenCenterX+ 30, ScreenCenterY+1};
D3DRECT rec7 = {ScreenCenterX, ScreenCenterY-30, ScreenCenterX+ 1,ScreenCenterY+30}; 
Device_Interface->Clear( 1, &rec6, D3DCLEAR_TARGET, D3DXCOLOR(0.0, 0.0, 1.0, 1.0), 0, 0 );//blue
Device_Interface->Clear( 1, &rec7, D3DCLEAR_TARGET, D3DXCOLOR(0.0, 0.0, 1.0, 1.0), 0, 0 ); 
D3DRECT rec8 = {ScreenCenterX-25, ScreenCenterY, ScreenCenterX+ 25, ScreenCenterY+1};
D3DRECT rec9 = {ScreenCenterX, ScreenCenterY-25, ScreenCenterX+ 1,ScreenCenterY+25}; 
Device_Interface->Clear( 1, &rec8, D3DCLEAR_TARGET, D3DXCOLOR(0.0, 1.0, 1.0, 1.0), 0, 0 );//cyan
Device_Interface->Clear( 1, &rec9, D3DCLEAR_TARGET, D3DXCOLOR(0.0, 1.0, 1.0, 1.0), 0, 0 );
D3DRECT rec10 = {ScreenCenterX-20, ScreenCenterY, ScreenCenterX+ 20, ScreenCenterY+1};
D3DRECT rec11 = {ScreenCenterX, ScreenCenterY-20, ScreenCenterX+ 1,ScreenCenterY+20}; 
Device_Interface->Clear( 1, &rec10, D3DCLEAR_TARGET, D3DXCOLOR(0.0, 1.0, 0.0, 1.0), 0, 0 );// green
Device_Interface->Clear( 1, &rec11, D3DCLEAR_TARGET, D3DXCOLOR(0.0, 1.0, 0.0, 1.0), 0, 0 );
D3DRECT rec12 = {ScreenCenterX-15, ScreenCenterY, ScreenCenterX+ 15, ScreenCenterY+1};
D3DRECT rec13 = {ScreenCenterX, ScreenCenterY-15, ScreenCenterX+ 1,ScreenCenterY+15}; 
Device_Interface->Clear( 1, &rec12, D3DCLEAR_TARGET, D3DXCOLOR(1.0, 1.0, 0.0, 1.0), 0, 0 );// yellow
Device_Interface->Clear( 1, &rec13, D3DCLEAR_TARGET, D3DXCOLOR(1.0, 1.0, 0.0, 1.0), 0, 0 );
 
D3DRECT rec14 = {ScreenCenterX-10, ScreenCenterY, ScreenCenterX+ 10, ScreenCenterY+1};
D3DRECT rec15 = {ScreenCenterX, ScreenCenterY-10, ScreenCenterX+ 1,ScreenCenterY+10}; 
Device_Interface->Clear( 1, &rec14, D3DCLEAR_TARGET, D3DXCOLOR(1.0, 0.549019608, 0.0, 1.0), 0, 0 );// orange
Device_Interface->Clear( 1, &rec15, D3DCLEAR_TARGET, D3DXCOLOR(1.0, 0.549019608, 0.0, 1.0), 0, 0 );
D3DRECT rec16 = {ScreenCenterX-5, ScreenCenterY, ScreenCenterX+ 5, ScreenCenterY+1};
D3DRECT rec17 = {ScreenCenterX, ScreenCenterY-5, ScreenCenterX+ 1,ScreenCenterY+5}; 
Device_Interface->Clear( 1, &rec16, D3DCLEAR_TARGET, D3DXCOLOR(1.0, 0.0, 0.0, 1.0), 0, 0 );//red
Device_Interface->Clear( 1, &rec17, D3DCLEAR_TARGET, D3DXCOLOR(1.0, 0.0, 0.0, 1.0), 0, 0 );
} 
 
/*
if (GetAsyncKeyState(VK_F8)&1) // if we click f8
{ xhair = !xhair; } // xhair = on
if (GetAsyncKeyState(VK_F1)&1) // if we click f1
{ chams = !chams; } // chams = on
if (GetAsyncKeyState(VK_F2)&1) // if we click f2
{ //then
nofog = !nofog; //nofog = on
} //end of then
if (GetAsyncKeyState(VK_F3)&1) // if we click f1
{ XQZ = !XQZ; } // XQZ = on
*/
 
if (pFont==NULL) 
PostReset(Device_Interface); // Create font
else
DoMenu(Device_Interface);
return EndScene_Pointer(Device_Interface);
}
//=====================================================================================
void DrawBox(LPDIRECT3DDEVICE8 Device_Interface, int x, int y, int w, int h, D3DCOLOR col)
{
struct {
float x,y,z,rhw;
DWORD dwColor;
} qV[4] = { { (float)x , (float)(y+h), 0.0f, 0.0f, col},
{ (float)x , (float)y , 0.0f, 0.0f, col},
{ (float)(x+w), (float)(y+h), 0.0f, 0.0f, col},
{ (float)(x+w), (float)y , 0.0f, 0.0f, col} };
Device_Interface->SetPixelShader(NULL);
Device_Interface->SetRenderState(D3DRS_ALPHABLENDENABLE,true);
Device_Interface->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_INVSRCALPHA);
Device_Interface->SetTexture(0, NULL);
Device_Interface->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP,2,qV,sizeof(qV[0]));
}
//=====================================================================================
HRESULT WINAPI DrawIndexedPrimitive_Detour(LPDIRECT3DDEVICE8 Device_Interface, D3DPRIMITIVETYPE pType, 
UINT nMinIndex, UINT nNumVertices, UINT nStartIndex, UINT nPrimitiveCount)
{
 
if(nofog) 
{ 
Device_Interface->SetRenderState(D3DRS_FOGENABLE, false); // Disable the Fog
} 
 
LPDIRECT3DVERTEXBUFFER8 Stream_Data;
UINT Stride = 40;
if(Device_Interface->GetStreamSource(0, &Stream_Data, &Stride) == D3D_OK)
Stream_Data->Release();
if(chams)
{
texnum = (nNumVertices*100000)+nPrimitiveCount; 
if(Stride == 40 &&
 
(texnum==34900580)|| // Delta Force Head
(texnum==36100604)|| // Spetsnaz Head
(texnum==38000658)|| // Spetsnaz Legs
(texnum==18300268)|| // Spetsnaz Body
(texnum==36200604)|| // GIGN Head
(texnum==21200306)|| // GIGN Body
(texnum==35500568)|| // GSG9 Head
(texnum==2200024)|| // GSG9 Bangs
(texnum==8800105)|| // GSG9 Feet
(texnum==36900650)|| // GSG9 Legs
(texnum==19600314)|| // GSG9 Body
(texnum==36700612)|| // SAS Head
(texnum==8500105)|| // SAS Feet
(texnum==37000650)|| // SAS Legs
(texnum==18000274)|| // SAS Body
(texnum==35300556)|| // KSF Head
(texnum==7500121)|| // KSF Arms
(texnum==9200115)|| // KSF Feet
(texnum==12400168)|| // KSF Hands
(texnum==30100522)|| // KSF Legs
(texnum==18700288)|| // KSF Body
(texnum==40900594)|| // ARTC Head
(texnum==11700190)|| // ARTC Arms
(texnum==9100118)|| // ARTC Feet
(texnum==12500170)|| // ARTC Hands
(texnum==37000634)|| // ARTC Legs
(texnum==41700516)|| // ARTC Body
(texnum==19400260)|| // ROKMC Body
(texnum==37900592)|| // ROKMC Head
(texnum==36500642)|| // ROKMC Legs
(texnum==44800776)|| // SRG Head
(texnum==15900200)|| // SRG Left Arm
(texnum==10500168)|| // SRG Right Arm
(texnum==80401016)|| // SRG Body
(texnum==10000121)|| // SRG Feet
(texnum==13200180)|| // SRG Hands
(ForceRecon)|| // ForceRecon
(Mulan)||
(texnum==33800534)|| // SRG Leg
(texnum==13200212)|| // Delta Force Helmet
(texnum==13200212)|| // Delta Force Helmet 2
(texnum==34700538)|| // Delta Force Gas Mask
(texnum==19500352)|| // Delta Force Balaclava
(texnum==84900778)|| // Delta Force Clan BDU
(texnum==27500442)|| // Delta Force Body Armor
(texnum==42800576)|| // Delta Force Body Armor 2
(texnum==52100658)|| // Delta Force Tactical Vest
(texnum==12200196)|| // Spetsnaz Helmet
(texnum==27100464)|| // Spetsnaz Gas Mask
(texnum==33600552)|| // Spetsnaz Body Armor
(texnum==44100646)|| // Spetsnaz Tactical Vest
(texnum==17800292)|| // GIGN Red Bandana
(texnum==21300290)|| // GIGN Helmet
(texnum==2800036)|| // GIGN Helmet Lens
(texnum==35700558)|| // GIGN Gas Mask
(texnum==22100396)|| // GIGN Balaclava
(texnum==29700492)|| // GIGN Body Armor
(texnum==11200188)|| // ROKMC Beret
(texnum==12000194)|| // ROKMC Helmet
(texnum==29800450)|| // ROKMC Gas Mask
(texnum==27100394)|| // ROKMC Body Armor
(texnum==28700374)|| // ROKMC X Harness
(texnum==34700470)|| // ROKMC X Harness
(texnum==5100056)|| // ROKMC Pouch
(texnum==9900163)|| // ROKMC Left Arm
(texnum==18300163)|| // ROKMC Right Arm
(texnum==16400266)|| // GSG9 Red Bandana
(texnum==16200243)|| // GSG9 Helmet
(texnum==31900466)|| // GSG9 Gas Mask
(texnum==19300342)|| // GSG9 Balaclava
(texnum==83600752)|| // GSG9 Clan BDU
(texnum==33400477)|| // GSG9 Body Armor
(texnum==10500163)|| // GSG9 Rolled Up Sleeves
(texnum==38100666)|| // GSG9 Tactical Knee Pads
(texnum==9600172)|| // SAS Boonie Hat
(texnum==14200236)|| // SAS Helmet
(texnum==37800552)|| // SAS Gas Mask
(texnum==28100486)|| // SAS Balaclava
(texnum==62400752)|| // SAS Clan BDU
(texnum==27900456)|| // SAS Body Armor
(texnum==45700654)|| // SAS Tactical Vest
(texnum==39800532)|| // SAS Tactical Vest 2
(texnum==9200100)|| // SAS Holster
(texnum==4800040)|| // SAS Magazine Pouch
(texnum==4000044)|| // SAS Pouch
(texnum==6500110) || // KSF Boonie Hat
(texnum==12900208)|| // KSF Helmet
(texnum==29600448)|| // KSF Gas Mask
(texnum==31100398)|| // KSF Sunglasses
(texnum==84700776)|| // KSF Clan BDU
(texnum==600004)|| // KSF Clan BDU Logo
(texnum==36500606)|| // KSF Body Armor
(texnum==63100646)|| // KSF Tactical Vest
(texnum==19800163)|| // KSF Rolled Up Sleeves
(texnum==7000066)|| // KSF Holster
(texnum==10400190)|| // SRG Beret
(texnum==23800294)|| // SRG Deer Head
(texnum==11600180)|| // SRG NIJ IIIA Helmet
(texnum==17100278)|| // SRG Red Bandana
(texnum==14600198)|| // SRG Battle Cap
(texnum==18200266)|| // SRG Helmet
(texnum==19100106)|| // SRG Gas Mask
(texnum==54300350)|| // SRG Sunglasses
(texnum==30800380)|| // SRG Mid Class Sunglasses
(texnum==79300995)|| // SRG Clan BDU 1
(texnum==13300138)|| // SRG Clan BDU 2
(texnum==300001)|| // SRG Clan BDU 3
(texnum==1200012)|| // SRG Clan BDU Logo
(texnum==10900110)|| // SRG Bulletproof Vest
(texnum==6200064)|| // SRG Holster
(ForceReconAddons)||
(MulanAddons)||
(texnum==22700250)) // SRG Pouch
{
Device_Interface->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
Device_Interface->SetRenderState(D3DRS_ZFUNC,D3DCMP_NEVER);
if(Red)
{
Device_Interface->SetTexture(0, texRed);
}
if(Green)
{
Device_Interface->SetTexture(0, texGreen);
}
if(Orange)
{
Device_Interface->SetTexture(0, texOrange);
}
if(Yellow)
{
Device_Interface->SetTexture(0, texYellow);
}
if(Blue)
{
Device_Interface->SetTexture(0, texBlue);
}
if(Cyan)
{
Device_Interface->SetTexture(0, texCyan);
}
if(Pink)
{
Device_Interface->SetTexture(0, texPink);
}
if(Purple)
{
Device_Interface->SetTexture(0, texPurple);
}
if(White)
{
Device_Interface->SetTexture(0, texWhite);
}
if(Black)
{
Device_Interface->SetTexture(0, texBlack);
}
if(LightSteelBlue)
{
Device_Interface->SetTexture(0, texLightSteelBlue);
}
if(SteelBlue)
{
Device_Interface->SetTexture(0, texSteelBlue);
}
if(LightBlue)
{
Device_Interface->SetTexture(0, texLightBlue);
}
if(Brown)
{
Device_Interface->SetTexture(0, texBrown);
}
if(Teal)
{
Device_Interface->SetTexture(0, texTeal);
}
if(Salmon)
{
Device_Interface->SetTexture(0, texSalmon);
}
if(Lime)
{
Device_Interface->SetTexture(0, texLime);
}
if(ElectricLime)
{
Device_Interface->SetTexture(0, texElectricLime);
}
if(Gold)
{
Device_Interface->SetTexture(0, texGold);
}
if(OrangeRed)
{
Device_Interface->SetTexture(0, texOrangeRed);
}
if(GreenYellow)
{
Device_Interface->SetTexture(0, texGreenYellow);
}
if(AquaMarine)
{
Device_Interface->SetTexture(0, texAquaMarine);
}
if(SkyBlue)
{
Device_Interface->SetTexture(0, texSkyBlue);
}
if(SlateBlue)
{
Device_Interface->SetTexture(0, texSlateBlue);
}
if(Crimson)
{
Device_Interface->SetTexture(0, texCrimson);
}
if(DarkOliveGreen)
{
Device_Interface->SetTexture(0, texDarkOliveGreen);
}
if(PaleGreen)
{
Device_Interface->SetTexture(0, texPaleGreen);
}
if(DarkGoldenRod)
{
Device_Interface->SetTexture(0, texDarkGoldenRod);
}
if(FireBrick)
{
Device_Interface->SetTexture(0, texFireBrick);
}
if(DarkBlue)
{
Device_Interface->SetTexture(0, texDarkBlue);
}
if(DarkerBlue)
{
Device_Interface->SetTexture(0, texDarkerBlue);
}
if(LightYellow)
{
Device_Interface->SetTexture(0, texLightYellow);
}
if(DarkYellow)
{
Device_Interface->SetTexture(0, texDarkYellow);
}
Device_Interface->SetRenderState(D3DRS_LIGHTING, false);
DrawIndexedPrimitive_Pointer(Device_Interface, pType, nMinIndex, nNumVertices, nStartIndex, nPrimitiveCount);
Device_Interface->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
Device_Interface->SetRenderState(D3DRS_ZFUNC,D3DCMP_LESSEQUAL);
if(Red2)
{
Device_Interface->SetTexture(0, texRed);
}
if(Green2)
{
Device_Interface->SetTexture(0, texGreen);
}
if(Orange2)
{
Device_Interface->SetTexture(0, texOrange);
}
if(Yellow2)
{
Device_Interface->SetTexture(0, texYellow);
}
if(Blue2)
{
Device_Interface->SetTexture(0, texBlue);
}
if(Cyan2)
{
Device_Interface->SetTexture(0, texCyan);
}
if(Pink2)
{
Device_Interface->SetTexture(0, texPink);
}
if(Purple2)
{
Device_Interface->SetTexture(0, texPurple);
}
if(White2)
{
Device_Interface->SetTexture(0, texWhite);
}
if(Black2)
{
Device_Interface->SetTexture(0, texBlack);
}
if(LightSteelBlue2)
{
Device_Interface->SetTexture(0, texLightSteelBlue);
}
if(SteelBlue2)
{
Device_Interface->SetTexture(0, texSteelBlue);
}
if(LightBlue2)
{
Device_Interface->SetTexture(0, texLightBlue);
}
if(Brown2)
{
Device_Interface->SetTexture(0, texBrown);
}
if(Teal2)
{
Device_Interface->SetTexture(0, texTeal);
}
if(Salmon2)
{
Device_Interface->SetTexture(0, texSalmon);
}
if(Red)
{
Device_Interface->SetTexture(0, texRed);
}
if(Green)
{
Device_Interface->SetTexture(0, texGreen);
}
if(Orange)
{
Device_Interface->SetTexture(0, texOrange);
}
if(Yellow)
{
Device_Interface->SetTexture(0, texYellow);
}
if(Blue)
{
Device_Interface->SetTexture(0, texBlue);
}
if(Cyan)
{
Device_Interface->SetTexture(0, texCyan);
}
if(Pink)
{
Device_Interface->SetTexture(0, texPink);
}
if(Purple)
{
Device_Interface->SetTexture(0, texPurple);
}
if(White)
{
Device_Interface->SetTexture(0, texWhite);
}
if(Black)
{
Device_Interface->SetTexture(0, texBlack);
}
if(LightSteelBlue)
{
Device_Interface->SetTexture(0, texLightSteelBlue);
}
if(SteelBlue)
{
Device_Interface->SetTexture(0, texSteelBlue);
}
if(LightBlue)
{
Device_Interface->SetTexture(0, texLightBlue);
}
if(Brown)
{
Device_Interface->SetTexture(0, texBrown);
}
if(Teal)
{
Device_Interface->SetTexture(0, texTeal);
}
if(Salmon)
{
Device_Interface->SetTexture(0, texSalmon);
}
if(Lime2)
{
Device_Interface->SetTexture(0, texLime);
}
if(ElectricLime2)
{
Device_Interface->SetTexture(0, texElectricLime);
}
if(Gold2)
{
Device_Interface->SetTexture(0, texGold);
}
if(OrangeRed2)
{
Device_Interface->SetTexture(0, texOrangeRed);
}
if(GreenYellow2)
{
Device_Interface->SetTexture(0, texGreenYellow);
}
if(AquaMarine2)
{
Device_Interface->SetTexture(0, texAquaMarine);
}
if(SkyBlue2)
{
Device_Interface->SetTexture(0, texSkyBlue);
}
if(SlateBlue2)
{
Device_Interface->SetTexture(0, texSlateBlue);
}
if(Crimson2)
{
Device_Interface->SetTexture(0, texCrimson);
}
if(DarkOliveGreen2)
{
Device_Interface->SetTexture(0, texDarkOliveGreen);
}
if(PaleGreen2)
{
Device_Interface->SetTexture(0, texPaleGreen);
}
if(DarkGoldenRod2)
{
Device_Interface->SetTexture(0, texDarkGoldenRod);
}
if(FireBrick2)
{
Device_Interface->SetTexture(0, texFireBrick);
}
if(DarkBlue2)
{
Device_Interface->SetTexture(0, texDarkBlue);
}
if(DarkerBlue2)
{
Device_Interface->SetTexture(0, texDarkerBlue);
}
if(LightYellow2)
{
Device_Interface->SetTexture(0, texLightYellow);
}
if(DarkYellow2)
{
Device_Interface->SetTexture(0, texDarkYellow);
} 
}
if (nNumVertices == 213 && nPrimitiveCount == 174) // M67 Grenade =============== //
{
Device_Interface->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
Device_Interface->SetRenderState(D3DRS_ZFUNC,D3DCMP_NEVER);
Device_Interface->SetTexture(0,texRed);
DrawIndexedPrimitive_Pointer(Device_Interface, pType, nMinIndex, nNumVertices, nStartIndex, nPrimitiveCount);
Device_Interface->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
Device_Interface->SetRenderState(D3DRS_ZFUNC,D3DCMP_LESSEQUAL);
Device_Interface->SetTexture(0,texGreen);
}
if (nNumVertices == 158 && nPrimitiveCount == 131) // Flashbang =============== //
{
Device_Interface->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
Device_Interface->SetRenderState(D3DRS_ZFUNC,D3DCMP_NEVER);
Device_Interface->SetTexture(0,texRed);
DrawIndexedPrimitive_Pointer(Device_Interface, pType, nMinIndex, nNumVertices, nStartIndex, nPrimitiveCount);
Device_Interface->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
Device_Interface->SetRenderState(D3DRS_ZFUNC,D3DCMP_LESSEQUAL);
Device_Interface->SetTexture(0,texGreen);
}
if (nNumVertices == 171 && nPrimitiveCount == 143) // Smoke Grenade =============== //
{
Device_Interface->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
Device_Interface->SetRenderState(D3DRS_ZFUNC,D3DCMP_NEVER);
Device_Interface->SetTexture(0,texRed);
DrawIndexedPrimitive_Pointer(Device_Interface, pType, nMinIndex, nNumVertices, nStartIndex, nPrimitiveCount);
Device_Interface->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
Device_Interface->SetRenderState(D3DRS_ZFUNC,D3DCMP_LESSEQUAL);
Device_Interface->SetTexture(0,texBlue);
}
if (nNumVertices == 271 && nPrimitiveCount == 257) // VX Grenade =============== //
{
Device_Interface->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
Device_Interface->SetRenderState(D3DRS_ZFUNC,D3DCMP_NEVER);
Device_Interface->SetTexture(0,texRed);
DrawIndexedPrimitive_Pointer(Device_Interface, pType, nMinIndex, nNumVertices, nStartIndex, nPrimitiveCount);
Device_Interface->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
Device_Interface->SetRenderState(D3DRS_ZFUNC,D3DCMP_LESSEQUAL);
Device_Interface->SetTexture(0,texBlue);
}
if (nNumVertices == 338 && nPrimitiveCount == 339) // RGD-5 Grenade =============== //
{
Device_Interface->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
Device_Interface->SetRenderState(D3DRS_ZFUNC,D3DCMP_NEVER);
Device_Interface->SetTexture(0,texRed);
DrawIndexedPrimitive_Pointer(Device_Interface, pType, nMinIndex, nNumVertices, nStartIndex, nPrimitiveCount);
Device_Interface->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
Device_Interface->SetRenderState(D3DRS_ZFUNC,D3DCMP_LESSEQUAL);
Device_Interface->SetTexture(0,texYellow);
}
 
 
if (Stride==40 && // Guns =============== //
(texnum==187200968)|| // GALIL
(texnum==187200968)|| // GALIL 2
(texnum==149701124)|| // UZI
(texnum==193701304)|| // M249
(texnum==232501431)|| // SIG551
(texnum==161500751)|| // FA-MAS
(texnum==107400724)|| // FR-F2
(texnum==141600900)|| // AN94
(texnum==145900805)|| // G36C
(texnum==42200339)|| // K1
(texnum==23400116)|| // K1 2
(texnum==17500073)|| // K1 3
(texnum==3200012)|| // K1 4
(texnum==2300012)|| // K1 5
(texnum==71900459)|| // MP5
(texnum==1800008)|| // MP5 2
(texnum==20300084)|| // MP5 3
(texnum==16700083)|| // MP5 4
(texnum==79100469)|| // M4A1
(texnum==12000044)|| // M4A1 2
(texnum==16800062)|| // M4A1 3
(texnum==2400008)|| // M4A1 4
(texnum==600002)|| // M4A1 5
(texnum==12800050)|| // M4A1 6
(texnum==2600010)|| // M4A1 7
(texnum==4200014)|| // M4A1 8
(texnum==1400008)|| // M4A1 9
(texnum==80600442)|| // M16A2
(texnum==13400052)|| // M16A2 2
(texnum==17600066)|| // M16A2 3
(texnum==5400018)|| // M16A2 4
(texnum==46200348)|| // STEYR_AUG 
(texnum==27000133)|| // STEYR_AUG 2
(texnum==4100025)|| // STEYR_AUG 3
(texnum==1200006)|| // STEYR_AUG 4
(texnum==400002)|| // STEYR_AUG 5
(texnum==46800367)|| // PSG-1
(texnum==9600042)|| // PSG-1 2
(texnum==18800092)|| // PSG-1 3
(texnum==16900071)|| // PSG-1 4
(texnum==3400012)|| // PSG-1 5
(texnum==800004)|| // PSG-1 6
(texnum==40500383)|| // K2
(texnum==15800089)|| // K2 2
(texnum==2200012)|| // K2 3
(texnum==7000034)|| // K2 4
(texnum==60700349)|| // P90
(texnum==5500033)|| // P90 2
(texnum==47700227)|| // P90 3
(texnum==10300047)|| // P90 4
(texnum==3800014)|| // P90 5
(texnum==50300349)|| // AK-74
(texnum==14700071)|| // AK-74 2
(texnum==13100061)|| // AK-74 3
(texnum==194501145)|| // MG36
(texnum==116000670)|| // DESERT EAGLE
(texnum==182101089)|| // MR73
(texnum==62500454)|| // REMINGTON M870
(texnum==95200571)|| // BENELLI M1
(texnum==40700334)|| // GLOCK 23
(texnum==71500449)|| // BERETTA M92F
(texnum==11000044)|| // BERETTA M92F 2
(texnum==16500075)|| // BERETTA M92F 3
(texnum==4400020)|| // BERETTA M92F 4
(texnum==2800014)|| // BERETTA M92F 5
(texnum==92000543)|| // COLT 45
(texnum==239001276)) // DRAGONUV
{
Device_Interface->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
Device_Interface->SetRenderState(D3DRS_ZFUNC,D3DCMP_NEVER);
Device_Interface->SetTexture(0,texBlue);
DrawIndexedPrimitive_Pointer(Device_Interface, pType, nMinIndex, nNumVertices, nStartIndex, nPrimitiveCount);
Device_Interface->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
Device_Interface->SetRenderState(D3DRS_ZFUNC,D3DCMP_LESSEQUAL);
Device_Interface->SetTexture(0,texOrange);
}
}
//============================================================================================================
if(XQZ)
{
texnum = (nNumVertices*100000)+nPrimitiveCount; 
if(Stride == 40 &&
 
(texnum==34900580)|| // Delta Force Head
(texnum==36100604)|| // Spetsnaz Head
(texnum==38000658)|| // Spetsnaz Legs
(texnum==18300268)|| // Spetsnaz Body
(texnum==36200604)|| // GIGN Head
(texnum==21200306)|| // GIGN Body
(texnum==35500568)|| // GSG9 Head
(texnum==2200024)|| // GSG9 Bangs
(texnum==8800105)|| // GSG9 Feet
(texnum==36900650)|| // GSG9 Legs
(texnum==19600314)|| // GSG9 Body
(texnum==36700612)|| // SAS Head
(texnum==8500105)|| // SAS Feet
(texnum==37000650)|| // SAS Legs
(texnum==18000274)|| // SAS Body
(texnum==35300556)|| // KSF Head
(texnum==7500121)|| // KSF Arms
(texnum==9200115)|| // KSF Feet
(texnum==12400168)|| // KSF Hands
(texnum==30100522)|| // KSF Legs
(texnum==18700288)|| // KSF Body
(texnum==40900594)|| // ARTC Head
(texnum==11700190)|| // ARTC Arms
(texnum==9100118)|| // ARTC Feet
(texnum==12500170)|| // ARTC Hands
(texnum==37000634)|| // ARTC Legs
(texnum==41700516)|| // ARTC Body
(texnum==19400260)|| // ROKMC Body
(texnum==37900592)|| // ROKMC Head
(texnum==36500642)|| // ROKMC Legs
(texnum==44800776)|| // SRG Head
(texnum==15900200)|| // SRG Left Arm
(texnum==10500168)|| // SRG Right Arm
(texnum==80401016)|| // SRG Body
(texnum==10000121)|| // SRG Feet
(texnum==13200180)|| // SRG Hands
(ForceRecon)|| // ForceRecon
(Mulan)||
(texnum==33800534)) // SRG Leg
{
Device_Interface->SetRenderState(D3DRS_LIGHTING, false); 
Device_Interface->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE); 
}
if (nNumVertices == 213 && nPrimitiveCount == 174) // M67 Grenade =============== //
{
Device_Interface->SetRenderState(D3DRS_LIGHTING, false); 
Device_Interface->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
}
if (nNumVertices == 158 && nPrimitiveCount == 131) // Flashbang =============== //
{
Device_Interface->SetRenderState(D3DRS_LIGHTING, false);
Device_Interface->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
}
if (nNumVertices == 171 && nPrimitiveCount == 143) // Smoke Grenade =============== //
{
Device_Interface->SetRenderState(D3DRS_LIGHTING, false);
Device_Interface->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
}
if (nNumVertices == 271 && nPrimitiveCount == 257) // VX Grenade =============== //
{
Device_Interface->SetRenderState(D3DRS_LIGHTING, false); 
Device_Interface->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
}
if (nNumVertices == 338 && nPrimitiveCount == 339) // RGD-5 Grenade =============== //
{
Device_Interface->SetRenderState(D3DRS_LIGHTING, false); 
Device_Interface->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
}
 
 
 
if (Stride==40 && // Equipment =============== //
(texnum==13200212)|| // Delta Force Helmet
(texnum==13200212)|| // Delta Force Helmet 2
(texnum==34700538)|| // Delta Force Gas Mask
(texnum==19500352)|| // Delta Force Balaclava
(texnum==84900778)|| // Delta Force Clan BDU
(texnum==27500442)|| // Delta Force Body Armor
(texnum==42800576)|| // Delta Force Body Armor 2
(texnum==52100658)|| // Delta Force Tactical Vest
(texnum==12200196)|| // Spetsnaz Helmet
(texnum==27100464)|| // Spetsnaz Gas Mask
(texnum==33600552)|| // Spetsnaz Body Armor
(texnum==44100646)|| // Spetsnaz Tactical Vest
(texnum==17800292)|| // GIGN Red Bandana
(texnum==21300290)|| // GIGN Helmet
(texnum==2800036)|| // GIGN Helmet Lens
(texnum==35700558)|| // GIGN Gas Mask
(texnum==22100396)|| // GIGN Balaclava
(texnum==29700492)|| // GIGN Body Armor
(texnum==11200188)|| // ROKMC Beret
(texnum==12000194)|| // ROKMC Helmet
(texnum==29800450)|| // ROKMC Gas Mask
(texnum==27100394)|| // ROKMC Body Armor
(texnum==28700374)|| // ROKMC X Harness
(texnum==34700470)|| // ROKMC X Harness
(texnum==5100056)|| // ROKMC Pouch
(texnum==9900163)|| // ROKMC Left Arm
(texnum==18300163)|| // ROKMC Right Arm
(texnum==16400266)|| // GSG9 Red Bandana
(texnum==16200243)|| // GSG9 Helmet
(texnum==31900466)|| // GSG9 Gas Mask
(texnum==19300342)|| // GSG9 Balaclava
(texnum==83600752)|| // GSG9 Clan BDU
(texnum==33400477)|| // GSG9 Body Armor
(texnum==10500163)|| // GSG9 Rolled Up Sleeves
(texnum==38100666)|| // GSG9 Tactical Knee Pads
(texnum==9600172)|| // SAS Boonie Hat
(texnum==14200236)|| // SAS Helmet
(texnum==37800552)|| // SAS Gas Mask
(texnum==28100486)|| // SAS Balaclava
(texnum==62400752)|| // SAS Clan BDU
(texnum==27900456)|| // SAS Body Armor
(texnum==45700654)|| // SAS Tactical Vest
(texnum==39800532)|| // SAS Tactical Vest 2
(texnum==9200100)|| // SAS Holster
(texnum==4800040)|| // SAS Magazine Pouch
(texnum==4000044)|| // SAS Pouch
(texnum==6500110) || // KSF Boonie Hat
(texnum==12900208)|| // KSF Helmet
(texnum==29600448)|| // KSF Gas Mask
(texnum==31100398)|| // KSF Sunglasses
(texnum==84700776)|| // KSF Clan BDU
(texnum==600004)|| // KSF Clan BDU Logo
(texnum==36500606)|| // KSF Body Armor
(texnum==63100646)|| // KSF Tactical Vest
(texnum==19800163)|| // KSF Rolled Up Sleeves
(texnum==7000066)|| // KSF Holster
(texnum==10400190)|| // SRG Beret
(texnum==23800294)|| // SRG Deer Head
(texnum==11600180)|| // SRG NIJ IIIA Helmet
(texnum==17100278)|| // SRG Red Bandana
(texnum==14600198)|| // SRG Battle Cap
(texnum==18200266)|| // SRG Helmet
(texnum==19100106)|| // SRG Gas Mask
(texnum==54300350)|| // SRG Sunglasses
(texnum==30800380)|| // SRG Mid Class Sunglasses
(texnum==79300995)|| // SRG Clan BDU 1
(texnum==13300138)|| // SRG Clan BDU 2
(texnum==300001)|| // SRG Clan BDU 3
(texnum==1200012)|| // SRG Clan BDU Logo
(texnum==10900110)|| // SRG Bulletproof Vest
(texnum==6200064)|| // SRG Holster
(ForceReconAddons)||
(MulanAddons)||
(texnum==22700250)) // SRG Pouch
{
Device_Interface->SetRenderState(D3DRS_LIGHTING, false); 
Device_Interface->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
}
if (Stride==40 && // Guns =============== //
(texnum==187200968)|| // GALIL
(texnum==187200968)|| // GALIL 2
(texnum==149701124)|| // UZI
(texnum==193701304)|| // M249
(texnum==232501431)|| // SIG551
(texnum==161500751)|| // FA-MAS
(texnum==107400724)|| // FR-F2
(texnum==141600900)|| // AN94
(texnum==145900805)|| // G36C
(texnum==42200339)|| // K1
(texnum==23400116)|| // K1 2
(texnum==17500073)|| // K1 3
(texnum==3200012)|| // K1 4
(texnum==2300012)|| // K1 5
(texnum==71900459)|| // MP5
(texnum==1800008)|| // MP5 2
(texnum==20300084)|| // MP5 3
(texnum==16700083)|| // MP5 4
(texnum==79100469)|| // M4A1
(texnum==12000044)|| // M4A1 2
(texnum==16800062)|| // M4A1 3
(texnum==2400008)|| // M4A1 4
(texnum==600002)|| // M4A1 5
(texnum==12800050)|| // M4A1 6
(texnum==2600010)|| // M4A1 7
(texnum==4200014)|| // M4A1 8
(texnum==1400008)|| // M4A1 9
(texnum==80600442)|| // M16A2
(texnum==13400052)|| // M16A2 2
(texnum==17600066)|| // M16A2 3
(texnum==5400018)|| // M16A2 4
(texnum==46200348)|| // STEYR_AUG 
(texnum==27000133)|| // STEYR_AUG 2
(texnum==4100025)|| // STEYR_AUG 3
(texnum==1200006)|| // STEYR_AUG 4
(texnum==400002)|| // STEYR_AUG 5
(texnum==46800367)|| // PSG-1
(texnum==9600042)|| // PSG-1 2
(texnum==18800092)|| // PSG-1 3
(texnum==16900071)|| // PSG-1 4
(texnum==3400012)|| // PSG-1 5
(texnum==800004)|| // PSG-1 6
(texnum==40500383)|| // K2
(texnum==15800089)|| // K2 2
(texnum==2200012)|| // K2 3
(texnum==7000034)|| // K2 4
(texnum==60700349)|| // P90
(texnum==5500033)|| // P90 2
(texnum==47700227)|| // P90 3
(texnum==10300047)|| // P90 4
(texnum==3800014)|| // P90 5
(texnum==50300349)|| // AK-74
(texnum==14700071)|| // AK-74 2
(texnum==13100061)|| // AK-74 3
(texnum==194501145)|| // MG36
(texnum==116000670)|| // DESERT EAGLE
(texnum==182101089)|| // MR73
(texnum==62500454)|| // REMINGTON M870
(texnum==95200571)|| // BENELLI M1
(texnum==40700334)|| // GLOCK 23
(texnum==71500449)|| // BERETTA M92F
(texnum==11000044)|| // BERETTA M92F 2
(texnum==16500075)|| // BERETTA M92F 3
(texnum==4400020)|| // BERETTA M92F 4
(texnum==2800014)|| // BERETTA M92F 5
(texnum==92000543)|| // COLT 45
(texnum==239001276)) // DRAGONUV
{
Device_Interface->SetRenderState(D3DRS_LIGHTING, false); 
Device_Interface->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
}
}
if(FullBright)
{
if(Stride == 40)
{
Device_Interface->SetRenderState(D3DRS_LIGHTING, false);
}
 
}
if(NoSmoke)
{
if(nPrimitiveCount=4)
{
return D3D_OK;
}
}
if(NoFlash)
{
if(nNumVertices == 158 && nPrimitiveCount == 131)
{
return D3D_OK;
}
}
if(ClearScope)
{
if(texnum==40200000 && Stride == 28)
{
return D3D_OK;
}
}
if(AsusWalls)
{
if(Stride == 40)
{
Device_Interface->SetRenderState( D3DRS_SRCBLEND, 3 );
Device_Interface->SetRenderState( D3DRS_DESTBLEND, 4 );
Device_Interface->SetRenderState( D3DRS_ALPHABLENDENABLE, true );
}
}
if(WhiteWalls)
{
if(Stride == 40)
{
Device_Interface->SetTexture(0, texWhite);
}
}
if(GlassWalls)
{
if(Stride == 40)
{
return D3D_OK;
}
}
return DrawIndexedPrimitive_Pointer(Device_Interface, pType, nMinIndex, nNumVertices, nStartIndex, nPrimitiveCount);
}
 
//=====================================================================================
//========================================================================================
HRESULT WINAPI SetViewport_Detour(LPDIRECT3DDEVICE8 Device_Interface,CONST D3DVIEWPORT8* pViewport)
{
ScreenCenterX = ( float )pViewport->Width / 2;
ScreenCenterY = ( float )pViewport->Height / 2; 
 
return SetViewport_Pointer(Device_Interface,pViewport);
}
//=====================================================================================
//=====================================================================================
char sFPS[20]="xxx Fps";
int CH_back = 2; // 40%
// group states
int CH_cheats = 1;
int CH_Chams = 0;
int CH_Chams2 = 0;
// item states
 
 
// none standard options
char *opt_Grp[] = { "+","-" };
char *opt_OffOn[] = { "Off","On" };
char *opt_Stamina[] = { "Off","Stealth","Full" };
char *opt_Back[] = { "Off","20%","40%","60%","80%","Solid" };
D3DMenu *pMenu=NULL;
 
// Change this to make your own menu 
void RebuildMenu(void)
{
pMenu->AddItem("Background" , &CH_back , opt_Back, 6);
pMenu->AddText("Framerate", sFPS);
pMenu->AddGroup("[Cham Colors 1]" , &CH_Chams, opt_Grp);
pMenu->AddGroup("[Cham Colors 2]" , &CH_Chams2, opt_Grp);
pMenu->AddGroup("[Cheats]" , &CH_cheats, opt_Grp);
if (CH_cheats) 
{
pMenu->AddItem("Chams" , &chams , opt_OffOn);
pMenu->AddItem("XQZ" , &XQZ , opt_OffOn);
pMenu->AddItem("NoFog" , &nofog , opt_OffOn);
pMenu->AddItem("Rainbow Crosshair" , &xhair , opt_OffOn);
pMenu->AddItem("FullBright" , &FullBright , opt_OffOn);
pMenu->AddItem("NoSmoke" , &NoSmoke , opt_OffOn);
pMenu->AddItem("NoFlash" , &NoFlash , opt_OffOn);
pMenu->AddItem("ClearScope" , &ClearScope , opt_OffOn);
pMenu->AddItem("AsusWallHack" , &AsusWalls , opt_OffOn);
pMenu->AddItem("GlassWalls" , &GlassWalls , opt_OffOn);
pMenu->AddItem("WhiteWalls" , &WhiteWalls , opt_OffOn);
}
 
if (CH_Chams) 
{
pMenu->AddItem("Red" , &Red , opt_OffOn);
pMenu->AddItem("Yellow" , &Yellow , opt_OffOn);
pMenu->AddItem("Orange" , &Orange , opt_OffOn);
pMenu->AddItem("Green" , &Green , opt_OffOn);
pMenu->AddItem("Blue" , &Blue , opt_OffOn);
pMenu->AddItem("Cyan" , &Cyan , opt_OffOn);
pMenu->AddItem("Pink" , &Pink , opt_OffOn);
pMenu->AddItem("Purple" , &Purple , opt_OffOn);
pMenu->AddItem("White" , &White , opt_OffOn);
pMenu->AddItem("Black" , &Black , opt_OffOn);
pMenu->AddItem("SteelBlue" , &SteelBlue , opt_OffOn);
pMenu->AddItem("LightSteelBlue" , &LightSteelBlue , opt_OffOn);
pMenu->AddItem("LightBlue" , &LightBlue , opt_OffOn);
pMenu->AddItem("Salmon" , &Salmon , opt_OffOn);
pMenu->AddItem("Teal" , &Teal , opt_OffOn);
pMenu->AddItem("Brown" , &Brown , opt_OffOn);
pMenu->AddItem("Lime" , &Lime , opt_OffOn);
pMenu->AddItem("ElectricLime" , &ElectricLime , opt_OffOn);
pMenu->AddItem("Gold" , &Gold , opt_OffOn);
pMenu->AddItem("OrangeRed" , &OrangeRed , opt_OffOn);
pMenu->AddItem("GreenYellow" , &GreenYellow , opt_OffOn);
pMenu->AddItem("AquaMarine" , &AquaMarine , opt_OffOn);
pMenu->AddItem("SkyBlue" , &SkyBlue , opt_OffOn);
pMenu->AddItem("SlateBlue" , &SlateBlue , opt_OffOn);
pMenu->AddItem("Crimson" , &Crimson , opt_OffOn);
pMenu->AddItem("DarkOliveGreen" , &DarkOliveGreen , opt_OffOn);
pMenu->AddItem("PaleGreen" , &PaleGreen , opt_OffOn);
pMenu->AddItem("DarkGoldenRod" , &DarkGoldenRod , opt_OffOn);
pMenu->AddItem("FireBrick" , &FireBrick , opt_OffOn);
pMenu->AddItem("DarkBlue" , &DarkBlue , opt_OffOn);
pMenu->AddItem("DarkerBlue" , &DarkerBlue , opt_OffOn);
pMenu->AddItem("DarkYellow" , &DarkYellow , opt_OffOn);
pMenu->AddItem("LightYellow" , &LightYellow , opt_OffOn);
}
 
if (CH_Chams2) 
{
pMenu->AddItem("Red" , &Red2 , opt_OffOn);
pMenu->AddItem("Yellow" , &Yellow2 , opt_OffOn);
pMenu->AddItem("Orange" , &Orange2 , opt_OffOn);
pMenu->AddItem("Green" , &Green2 , opt_OffOn);
pMenu->AddItem("Blue" , &Blue2 , opt_OffOn);
pMenu->AddItem("Cyan" , &Cyan2 , opt_OffOn);
pMenu->AddItem("Pink" , &Pink2 , opt_OffOn);
pMenu->AddItem("Purple" , &Purple2 , opt_OffOn);
pMenu->AddItem("White" , &White2 , opt_OffOn);
pMenu->AddItem("Black" , &Black2 , opt_OffOn);
pMenu->AddItem("SteelBlue" , &SteelBlue2 , opt_OffOn);
pMenu->AddItem("LightSteelBlue" , &LightSteelBlue2 , opt_OffOn);
pMenu->AddItem("LightBlue" , &LightBlue2 , opt_OffOn);
pMenu->AddItem("Salmon" , &Salmon2 , opt_OffOn);
pMenu->AddItem("Teal" , &Teal2 , opt_OffOn);
pMenu->AddItem("Brown" , &Brown2 , opt_OffOn);
pMenu->AddItem("Lime" , &Lime2 , opt_OffOn);
pMenu->AddItem("ElectricLime" , &ElectricLime2 , opt_OffOn);
pMenu->AddItem("Gold" , &Gold2 , opt_OffOn);
pMenu->AddItem("OrangeRed" , &OrangeRed2 , opt_OffOn);
pMenu->AddItem("GreenYellow" , &GreenYellow2 , opt_OffOn);
pMenu->AddItem("AquaMarine" , &AquaMarine2 , opt_OffOn);
pMenu->AddItem("SkyBlue" , &SkyBlue2 , opt_OffOn);
pMenu->AddItem("SlateBlue" , &SlateBlue2 , opt_OffOn);
pMenu->AddItem("Crimson" , &Crimson2 , opt_OffOn);
pMenu->AddItem("DarkOliveGreen" , &DarkOliveGreen2 , opt_OffOn);
pMenu->AddItem("PaleGreen" , &PaleGreen2 , opt_OffOn);
pMenu->AddItem("DarkGoldenRod" , &DarkGoldenRod2 , opt_OffOn);
pMenu->AddItem("FireBrick" , &FireBrick2 , opt_OffOn);
pMenu->AddItem("DarkBlue" , &DarkBlue2 , opt_OffOn);
pMenu->AddItem("DarkerBlue" , &DarkerBlue2 , opt_OffOn);
pMenu->AddItem("DarkYellow" , &DarkYellow2 , opt_OffOn);
pMenu->AddItem("LightYellow" , &LightYellow2 , opt_OffOn);
}
}
// --- simple FPS vars and function
int FPScounter = 0;
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
void DrawGui(LPDIRECT3DDEVICE8 Device_Interface, DWORD col)
{
if (CH_back==5) // solid
col|=0xff000000;
else
col|=CH_back*0x30000000; // transparency
DrawBox(Device_Interface,pMenu->x-3,pMenu->y-2,pMenu->totwidth+6,pMenu->totheight+4 ,col);
DrawBox(Device_Interface,pMenu->x-3,pMenu->y-2,pMenu->totwidth+6,pMenu->titleheight+1,col|0xff000000);
}
// called with every EndScene
void DoMenu(LPDIRECT3DDEVICE8 Device_Interface)
{
if (pMenu==0) { // first time , create the menu
pMenu = new D3DMenu("== DarkApallow ==",100,160); // title, maxitems,width
pMenu->visible=1; // make it visible
pMenu->col_title=0xffffffff; // change title color to white
} else {
FPScheck(sFPS,"%d Fps");
if (pMenu->noitems==0) RebuildMenu();
if (pMenu->visible && CH_back) DrawGui(Device_Interface,0x000000); // black background
pMenu->Show(pFont);
pMenu->Nav();
}
}
//=======================================================================================
HRESULT WINAPI Direct3DCreate8_VMTable(VOID)
{
LPDIRECT3D8 Direct3D_Object = Direct3DCreate8(D3D_SDK_VERSION);
 
if(Direct3D_Object == NULL)
return D3DERR_INVALIDCALL;
 
Direct3D_VMTable = (PDWORD)*(PDWORD)Direct3D_Object;
Direct3D_Object->Release();
 
DWORD dwProtect;
 
if(VirtualProtect(&Direct3D_VMTable[15], sizeof(DWORD), PAGE_READWRITE, &dwProtect) != 0)
{
*(PDWORD)&CreateDevice_Pointer = Direct3D_VMTable[15];
*(PDWORD)&Direct3D_VMTable[15] = (DWORD)CreateDevice_Detour;
 
if(VirtualProtect(&Direct3D_VMTable[15], sizeof(DWORD), dwProtect, &dwProtect) == 0)
return D3DERR_INVALIDCALL;
}
else
return D3DERR_INVALIDCALL;
 
return D3D_OK;
}
 
//=====================================================================================
 
HRESULT WINAPI CreateDevice_Detour(LPDIRECT3D8 Direct3D_Object, UINT Adapter, D3DDEVTYPE DeviceType, HWND FocusWindow, 
DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* PresentationParameters, 
LPDIRECT3DDEVICE8* Returned_Device_Interface)
{
HRESULT Returned_Result = CreateDevice_Pointer(Direct3D_Object, Adapter, DeviceType, FocusWindow, BehaviorFlags, 
PresentationParameters, Returned_Device_Interface);
 
DWORD dwProtect;
 
if(VirtualProtect(&Direct3D_VMTable[15], sizeof(DWORD), PAGE_READWRITE, &dwProtect) != 0)
{
*(PDWORD)&Direct3D_VMTable[15] = *(PDWORD)&CreateDevice_Pointer;
CreateDevice_Pointer = NULL;
 
if(VirtualProtect(&Direct3D_VMTable[15], sizeof(DWORD), dwProtect, &dwProtect) == 0)
return D3DERR_INVALIDCALL;
}
else
return D3DERR_INVALIDCALL;
 
if(Returned_Result == D3D_OK)
{
Direct3D_VMTable = (PDWORD)*(PDWORD)*Returned_Device_Interface;
 
*(PDWORD)&Reset_Pointer = (DWORD)Direct3D_VMTable[14];
*(PDWORD)&EndScene_Pointer = (DWORD)Direct3D_VMTable[35];
*(PDWORD)&DrawIndexedPrimitive_Pointer = (DWORD)Direct3D_VMTable[71];
*(PDWORD)&SetViewport_Pointer = (DWORD)Direct3D_VMTable[40];
 
*(PDWORD)&Direct3D_VMTable[14] = (DWORD)Reset_Detour;
*(PDWORD)&Direct3D_VMTable[35] = (DWORD)EndScene_Detour;
*(PDWORD)&Direct3D_VMTable[71] = (DWORD)DrawIndexedPrimitive_Detour;
*(PDWORD)&Direct3D_VMTable[40] = (DWORD)SetViewport_Detour;
}
 
return Returned_Result;
}
