// -----------------------------------------------------------------------------
// Project : D3DBase v1.0
// Author  : Hans211
// Date    : 11 April 2009
//
// A basic D3D framework:
// - D3D menu with folders
// - Optimized d3dfont, center and right aligned text
// - Works for d3d8 or d3d9  (define it in D3Dbase.h)
// -----------------------------------------------------------------------------
#include "d3dbase.h"

#ifdef FOR_D3D8
#include "d3dfont8.cpp"
#else
#include "d3dfont9.cpp"
#endif

oEndScene	pEndScene;
oReset		pReset;

CD3DFont	*pFont=NULL;


void PreReset(pD3DdeviceX pDevice)
{
	if (pFont) {
		pFont->InvalidateDeviceObjects();
		pFont->DeleteDeviceObjects();
		pFont = NULL;
	}
}

void PostReset(pD3DdeviceX pDevice)
{
	pFont = new CD3DFont("Arial", 10, D3DFONT_BOLD);
	if (pFont) {
		pFont->InitDeviceObjects(pDevice);
		pFont->RestoreDeviceObjects();
	}
}

HRESULT WINAPI myReset ( pD3DdeviceX pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters )
{
    PreReset(pDevice);
    return pReset(pDevice, pPresentationParameters);
}

HRESULT WINAPI myEndScene (pD3DdeviceX pDevice)
{
	if (pFont==NULL) 
	    PostReset(pDevice);			// Create font
	else 
		DoMenu(pDevice);
	return pEndScene(pDevice);
}

void DrawBox(pD3DdeviceX pDevice, int x, int y, int w, int h, D3DCOLOR col)
{
	struct {
		float x,y,z,rhw;
		DWORD dwColor;
	} qV[4] = { { (float)x    , (float)(y+h), 0.0f, 0.0f, col},
				{ (float)x    , (float)y    , 0.0f, 0.0f, col},
				{ (float)(x+w), (float)(y+h), 0.0f, 0.0f, col},
				{ (float)(x+w), (float)y    , 0.0f, 0.0f, col} };

	pDevice->SetPixelShader(NULL);
    pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE,true);
    pDevice->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_INVSRCALPHA);
    pDevice->SetTexture(0, NULL);
    pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP,2,qV,sizeof(qV[0]));
}

bool bCompare(const BYTE* pData, const BYTE* bMask, const char* szMask)
{
	for(;*szMask;++szMask,++pData,++bMask)
		if(*szMask=='x' && *pData!=*bMask)   return 0;
	return (*szMask) == NULL;
}

DWORD FindPattern(DWORD dwAddress,DWORD dwLen,BYTE *bMask,char * szMask)
{
	for(DWORD i=0; i<dwLen; i++)
		if (bCompare((BYTE*)(dwAddress+i),bMask,szMask))  return (DWORD)(dwAddress+i);
	return 0;
}

void *DetourCreate(BYTE *src, const BYTE *dst, const int len)
{
	BYTE *jmp = (BYTE*)malloc(len+5);
	DWORD dwBack;

	VirtualProtect(src, len, PAGE_EXECUTE_READWRITE, &dwBack);
	memcpy(jmp, src, len);	
	jmp += len;
	jmp[0] = 0xE9;
	*(DWORD*)(jmp+1) = (DWORD)(src+len - jmp) - 5;
	src[0] = 0xE9;
	*(DWORD*)(src+1) = (DWORD)(dst - src) - 5;
	for (int i=5; i<len; i++)  src[i]=0x90;
	VirtualProtect(src, len, dwBack, &dwBack);
	return (jmp-len);
}

int D3Dinit(void)
{
	DWORD		hD3D, adr, *vtbl;

	// wait for the d3dx dll
	hD3D=0;
	do {
		hD3D = (DWORD)GetModuleHandle(D3Ddllname);
		Sleep(10);
	} while(!hD3D);
	adr = FindPattern(hD3D, 0x128000, (PBYTE)"\xC7\x06\x00\x00\x00\x00\x89\x86\x00\x00\x00\x00\x89\x86", "xx????xx????xx");
	if (adr) {
		memcpy(&vtbl,(void *)(adr+2),4);
		pReset	  = (oReset)	DetourCreate((PBYTE)vtbl[RESET]   , (PBYTE)myReset   ,5);
 		pEndScene = (oEndScene)	DetourCreate((PBYTE)vtbl[ENDSCENE], (PBYTE)myEndScene,5);
 	}
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)HACKthread, NULL, NULL, NULL);
	return 0;
}

BOOL WINAPI DllMain ( HMODULE hDll, DWORD dwReason, LPVOID lpReserved )
{
	DisableThreadLibraryCalls(hDll);
	if (dwReason == DLL_PROCESS_ATTACH) {		
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)D3Dinit, NULL, NULL, NULL);
	}
	return TRUE;
}
