#ifndef _D3D8TEX_H
#define _D3D8TEX_H

#include "d3d8.h"

DWORD QuickChecksum(DWORD *pData, int size);

interface hkIDirect3DTexture8 : public IDirect3DTexture8
{
	hkIDirect3DTexture8(IDirect3DTexture8 **ppTex, IDirect3DDevice8 *pIDirect3DDevice8, UINT Width, UINT Height, D3DFORMAT Format)
	{
		m_D3Dtex = *ppTex;
		m_D3Ddev = pIDirect3DDevice8;
		m_Width = Width;
		m_Height = Height;
		m_Format = Format;
	}
	
	UINT m_Width, m_Height;
	D3DFORMAT m_Format;

	// callback interface
	IDirect3DTexture8 *m_D3Dtex;
	IDirect3DDevice8 *m_D3Ddev;

	// original interface
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj);
    STDMETHOD_(ULONG,AddRef)(THIS);
    STDMETHOD_(ULONG,Release)(THIS);
    STDMETHOD(GetDevice)(THIS_ IDirect3DDevice8** ppDevice);
    STDMETHOD(SetPrivateData)(THIS_ REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags);
    STDMETHOD(GetPrivateData)(THIS_ REFGUID refguid,void* pData,DWORD* pSizeOfData);
    STDMETHOD(FreePrivateData)(THIS_ REFGUID refguid);
    STDMETHOD_(DWORD, SetPriority)(THIS_ DWORD PriorityNew);
    STDMETHOD_(DWORD, GetPriority)(THIS);
    STDMETHOD_(void, PreLoad)(THIS);
    STDMETHOD_(D3DRESOURCETYPE, GetType)(THIS);
    STDMETHOD_(DWORD, SetLOD)(THIS_ DWORD LODNew);
    STDMETHOD_(DWORD, GetLOD)(THIS);
    STDMETHOD_(DWORD, GetLevelCount)(THIS);
    STDMETHOD(GetLevelDesc)(THIS_ UINT Level,D3DSURFACE_DESC *pDesc);
    STDMETHOD(GetSurfaceLevel)(THIS_ UINT Level,IDirect3DSurface8** ppSurfaceLevel);
    STDMETHOD(LockRect)(THIS_ UINT Level,D3DLOCKED_RECT* pLockedRect,CONST RECT* pRect,DWORD Flags);
    STDMETHOD(UnlockRect)(THIS_ UINT Level);
    STDMETHOD(AddDirtyRect)(THIS_ CONST RECT* pDirtyRect);
};

#endif