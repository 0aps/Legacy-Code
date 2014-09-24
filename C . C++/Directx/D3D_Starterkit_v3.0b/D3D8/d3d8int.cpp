/*	Direct3D8 Interface */

#include <windows.h>
#include "main.h"
#include "d3d8.h"

HRESULT APIENTRY hkIDirect3D8::QueryInterface(REFIID riid, void** ppvObj)
{
	return m_pD3Dint->QueryInterface(riid, ppvObj);
}

ULONG APIENTRY hkIDirect3D8::AddRef(void)
{
	return m_pD3Dint->AddRef();
}

ULONG APIENTRY hkIDirect3D8::Release(void)
{
	return m_pD3Dint->Release();
}

HRESULT APIENTRY hkIDirect3D8::RegisterSoftwareDevice(void* pInitializeFunction)
{
	return m_pD3Dint->RegisterSoftwareDevice(pInitializeFunction);
}

UINT APIENTRY hkIDirect3D8::GetAdapterCount(void)
{
	return m_pD3Dint->GetAdapterCount();
}

HRESULT APIENTRY hkIDirect3D8::GetAdapterIdentifier(UINT Adapter,DWORD Flags,D3DADAPTER_IDENTIFIER8* pIdentifier)
{
	return m_pD3Dint->GetAdapterIdentifier(Adapter, Flags, pIdentifier);
}

UINT APIENTRY hkIDirect3D8::GetAdapterModeCount(UINT Adapter)
{
	return m_pD3Dint->GetAdapterModeCount(Adapter);
}

HRESULT APIENTRY hkIDirect3D8::EnumAdapterModes(UINT Adapter,UINT Mode,D3DDISPLAYMODE* pMode)
{
	return m_pD3Dint->EnumAdapterModes(Adapter, Mode, pMode);
}

HRESULT APIENTRY hkIDirect3D8::GetAdapterDisplayMode(UINT Adapter,D3DDISPLAYMODE* pMode)
{
	return m_pD3Dint->GetAdapterDisplayMode(Adapter, pMode);
}

HRESULT APIENTRY hkIDirect3D8::CheckDeviceType(UINT Adapter,D3DDEVTYPE CheckType,D3DFORMAT DisplayFormat,D3DFORMAT BackBufferFormat,BOOL Windowed)
{
	return m_pD3Dint->CheckDeviceType(Adapter, CheckType, DisplayFormat, BackBufferFormat, Windowed);
}

HRESULT APIENTRY hkIDirect3D8::CheckDeviceFormat(UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT AdapterFormat,DWORD Usage,D3DRESOURCETYPE RType,D3DFORMAT CheckFormat)
{
	return m_pD3Dint->CheckDeviceFormat(Adapter, DeviceType, AdapterFormat, Usage, RType, CheckFormat);
}

HRESULT APIENTRY hkIDirect3D8::CheckDeviceMultiSampleType(UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT SurfaceFormat,BOOL Windowed,D3DMULTISAMPLE_TYPE MultiSampleType)
{
	return m_pD3Dint->CheckDeviceMultiSampleType(Adapter, DeviceType, SurfaceFormat, Windowed, MultiSampleType);
}

HRESULT APIENTRY hkIDirect3D8::CheckDepthStencilMatch(UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT AdapterFormat,D3DFORMAT RenderTargetFormat,D3DFORMAT DepthStencilFormat)
{
	return m_pD3Dint->CheckDepthStencilMatch(Adapter, DeviceType, AdapterFormat, RenderTargetFormat, DepthStencilFormat);
}

HRESULT APIENTRY hkIDirect3D8::GetDeviceCaps(UINT Adapter,D3DDEVTYPE DeviceType,D3DCAPS8* pCaps)
{
	return m_pD3Dint->GetDeviceCaps(Adapter, DeviceType, pCaps);
}

HMONITOR APIENTRY hkIDirect3D8::GetAdapterMonitor(UINT Adapter)
{
	return m_pD3Dint->GetAdapterMonitor(Adapter);
}

HRESULT APIENTRY hkIDirect3D8::CreateDevice(UINT Adapter,D3DDEVTYPE DeviceType,HWND hFocusWindow,DWORD BehaviorFlags,D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DDevice8** ppReturnedDeviceInterface)
{
	HRESULT hRet = m_pD3Dint->CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface);
	
	if( SUCCEEDED(hRet) )
	{
		hkIDirect3DDevice8 *ret = new hkIDirect3DDevice8(ppReturnedDeviceInterface, pPresentationParameters, this);
		add_log("Hooked Direct3D8 device: 0x%x -> 0x%x", ret->m_pD3Ddev, ret);
	}

	return hRet;
}