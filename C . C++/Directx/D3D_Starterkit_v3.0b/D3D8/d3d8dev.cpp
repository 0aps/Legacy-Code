/*	Direct3D8 Device */

#include <windows.h>
#include "main.h"
#include "d3d8.h"

#define D3DHOOK_TEXTURES //comment this to disable texture hooking

HRESULT CD3DManager::Initialize()
{
	/*
	initialize Resources such as textures 
	(managed and unmanaged [D3DPOOL]), 
	vertex buffers, and other D3D rendering resources
	...
	m_pD3Ddev->CreateTexture(..., ..., &m_pD3Dtexture);
	*/
	return S_OK;
}

HRESULT CD3DManager::PreReset()
{
	/*
	release all UNMANAGED [D3DPOOL_DEFAULT] 
	textures, vertex buffers, and other 
	volitile resources
	...
	_SAFE_RELEASE(m_pD3Dtexture);
	*/
	return S_OK;
}

HRESULT CD3DManager::PostReset()
{
	/*
	re-initialize all UNMANAGED [D3DPOOL_DEFAULT]
	textures, vertex buffers, and other volitile 
	resources
	...
	m_pD3Ddev->CreateTexture(..., ..., &m_pD3Dtexture);
	*/
	return S_OK;
}

HRESULT CD3DManager::Release()
{
	/*
	Release all textures, vertex buffers, and 
	other resources
	...
	_SAFE_RELEASE(m_pD3Dtexture);
	*/
	return S_OK;
}

//-----------------------------------------------------------------------------

HRESULT APIENTRY hkIDirect3DDevice8::QueryInterface(REFIID riid, void** ppvObj)
{
	return m_pD3Ddev->QueryInterface(riid, ppvObj);
}

ULONG APIENTRY hkIDirect3DDevice8::AddRef(void)
{
	m_refCount++;
	return m_pD3Ddev->AddRef();
}

ULONG APIENTRY hkIDirect3DDevice8::Release(void)
{
	if( --m_refCount == 0 )
		m_pManager->Release();

	return m_pD3Ddev->Release();
}

HRESULT APIENTRY hkIDirect3DDevice8::TestCooperativeLevel(void)
{
	return m_pD3Ddev->TestCooperativeLevel();
}

UINT APIENTRY hkIDirect3DDevice8::GetAvailableTextureMem(void)
{
	return m_pD3Ddev->GetAvailableTextureMem();
}

HRESULT APIENTRY hkIDirect3DDevice8::ResourceManagerDiscardBytes(DWORD Bytes)
{
	return m_pD3Ddev->ResourceManagerDiscardBytes(Bytes);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetDirect3D(IDirect3D8** ppD3D8)
{
	HRESULT hRet = m_pD3Ddev->GetDirect3D(ppD3D8);
	if( SUCCEEDED(hRet) )
		*ppD3D8 = m_pD3Dint;
	return hRet;
}

HRESULT APIENTRY hkIDirect3DDevice8::GetDeviceCaps(D3DCAPS8* pCaps)
{
	return m_pD3Ddev->GetDeviceCaps(pCaps);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetDisplayMode(D3DDISPLAYMODE* pMode)
{
	return m_pD3Ddev->GetDisplayMode(pMode);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS *pParameters)
{
	return m_pD3Ddev->GetCreationParameters(pParameters);
}

HRESULT APIENTRY hkIDirect3DDevice8::SetCursorProperties(UINT XHotSpot,UINT YHotSpot,IDirect3DSurface8* pCursorBitmap)
{
	return m_pD3Ddev->SetCursorProperties(XHotSpot, YHotSpot, pCursorBitmap);
}

void APIENTRY hkIDirect3DDevice8::SetCursorPosition(int X,int Y,DWORD Flags)
{
	m_pD3Ddev->SetCursorPosition(X, Y, Flags);
}

BOOL APIENTRY hkIDirect3DDevice8::ShowCursor(BOOL bShow)
{
	return m_pD3Ddev->ShowCursor(bShow);
}

HRESULT APIENTRY hkIDirect3DDevice8::CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DSwapChain8** pSwapChain)
{
	return m_pD3Ddev->CreateAdditionalSwapChain(pPresentationParameters, pSwapChain);
}

HRESULT APIENTRY hkIDirect3DDevice8::Reset(D3DPRESENT_PARAMETERS* pPresentationParameters)
{
	m_pManager->PreReset();

	HRESULT hRet = m_pD3Ddev->Reset(pPresentationParameters);

	if( SUCCEEDED(hRet) )
	{
		m_PresentParam = *pPresentationParameters;
		m_pManager->PostReset();
	}

	return hRet;
}

HRESULT APIENTRY hkIDirect3DDevice8::Present(CONST RECT* pSourceRect,CONST RECT* pDestRect,HWND hDestWindowOverride,CONST RGNDATA* pDirtyRegion)
{
	return m_pD3Ddev->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetBackBuffer(UINT BackBuffer,D3DBACKBUFFER_TYPE Type,IDirect3DSurface8** ppBackBuffer)
{
	return m_pD3Ddev->GetBackBuffer(BackBuffer, Type, ppBackBuffer);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetRasterStatus(D3DRASTER_STATUS* pRasterStatus)
{
	return m_pD3Ddev->GetRasterStatus(pRasterStatus);
}

void APIENTRY hkIDirect3DDevice8::SetGammaRamp(DWORD Flags,CONST D3DGAMMARAMP* pRamp)
{
	m_pD3Ddev->SetGammaRamp(Flags, pRamp);
}

void APIENTRY hkIDirect3DDevice8::GetGammaRamp(D3DGAMMARAMP* pRamp)
{
	m_pD3Ddev->GetGammaRamp(pRamp);
}

HRESULT APIENTRY hkIDirect3DDevice8::CreateTexture(UINT Width,UINT Height,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DTexture8** ppTexture)
{
	HRESULT hRet = m_pD3Ddev->CreateTexture(Width, Height, Levels, Usage, Format, Pool, ppTexture);

#ifdef D3DHOOK_TEXTURES
	if(hRet == D3D_OK) { *ppTexture = new hkIDirect3DTexture8(ppTexture, this, Width, Height, Format); }
#endif

	return hRet;
}

HRESULT APIENTRY hkIDirect3DDevice8::CreateVolumeTexture(UINT Width,UINT Height,UINT Depth,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DVolumeTexture8** ppVolumeTexture)
{
	return m_pD3Ddev->CreateVolumeTexture(Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture);
}

HRESULT APIENTRY hkIDirect3DDevice8::CreateCubeTexture(UINT EdgeLength,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DCubeTexture8** ppCubeTexture)
{
	return m_pD3Ddev->CreateCubeTexture(EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture);
}

HRESULT APIENTRY hkIDirect3DDevice8::CreateVertexBuffer(UINT Length,DWORD Usage,DWORD FVF,D3DPOOL Pool,IDirect3DVertexBuffer8** ppVertexBuffer)
{
	return m_pD3Ddev->CreateVertexBuffer(Length, Usage, FVF, Pool, ppVertexBuffer);
}

HRESULT APIENTRY hkIDirect3DDevice8::CreateIndexBuffer(UINT Length,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DIndexBuffer8** ppIndexBuffer)
{
	return m_pD3Ddev->CreateIndexBuffer(Length, Usage, Format, Pool, ppIndexBuffer);
}

HRESULT APIENTRY hkIDirect3DDevice8::CreateRenderTarget(UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,BOOL Lockable,IDirect3DSurface8** ppSurface)
{
	return m_pD3Ddev->CreateRenderTarget(Width, Height, Format, MultiSample, Lockable, ppSurface);
}

HRESULT APIENTRY hkIDirect3DDevice8::CreateDepthStencilSurface(UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,IDirect3DSurface8** ppSurface)
{
	return m_pD3Ddev->CreateDepthStencilSurface(Width, Height, Format, MultiSample, ppSurface);
}

HRESULT APIENTRY hkIDirect3DDevice8::CreateImageSurface(UINT Width,UINT Height,D3DFORMAT Format,IDirect3DSurface8** ppSurface)
{
	return m_pD3Ddev->CreateImageSurface(Width, Height, Format, ppSurface);
}

HRESULT APIENTRY hkIDirect3DDevice8::CopyRects(IDirect3DSurface8* pSourceSurface,CONST RECT* pSourceRectsArray,UINT cRects,IDirect3DSurface8* pDestinationSurface,CONST POINT* pDestPointsArray)
{
	return m_pD3Ddev->CopyRects(pSourceSurface, pSourceRectsArray, cRects, pDestinationSurface, pDestPointsArray);
}

HRESULT APIENTRY hkIDirect3DDevice8::UpdateTexture(IDirect3DBaseTexture8* pSourceTexture,IDirect3DBaseTexture8* pDestinationTexture)
{
	return m_pD3Ddev->UpdateTexture(pSourceTexture, pDestinationTexture);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetFrontBuffer(IDirect3DSurface8* pDestSurface)
{
	return m_pD3Ddev->GetFrontBuffer(pDestSurface);
}

HRESULT APIENTRY hkIDirect3DDevice8::SetRenderTarget(IDirect3DSurface8* pRenderTarget,IDirect3DSurface8* pNewZStencil)
{
	return m_pD3Ddev->SetRenderTarget(pRenderTarget, pNewZStencil);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetRenderTarget(IDirect3DSurface8** ppRenderTarget)
{
	return m_pD3Ddev->GetRenderTarget(ppRenderTarget);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetDepthStencilSurface(IDirect3DSurface8** ppZStencilSurface)
{
	return m_pD3Ddev->GetDepthStencilSurface(ppZStencilSurface);
}

HRESULT APIENTRY hkIDirect3DDevice8::BeginScene(void)
{
	return m_pD3Ddev->BeginScene();
}

HRESULT APIENTRY hkIDirect3DDevice8::EndScene(void)
{
	return m_pD3Ddev->EndScene();
}

HRESULT APIENTRY hkIDirect3DDevice8::Clear(DWORD Count,CONST D3DRECT* pRects,DWORD Flags,D3DCOLOR Color,float Z,DWORD Stencil)
{
	return m_pD3Ddev->Clear(Count, pRects, Flags, Color, Z, Stencil);
}

HRESULT APIENTRY hkIDirect3DDevice8::SetTransform(D3DTRANSFORMSTATETYPE State,CONST D3DMATRIX* pMatrix)
{
	return m_pD3Ddev->SetTransform(State, pMatrix);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetTransform(D3DTRANSFORMSTATETYPE State,D3DMATRIX* pMatrix)
{
	return m_pD3Ddev->GetTransform(State, pMatrix);
}

HRESULT APIENTRY hkIDirect3DDevice8::MultiplyTransform( D3DTRANSFORMSTATETYPE State,CONST D3DMATRIX* pMatrix)
{
	return m_pD3Ddev->MultiplyTransform(State,pMatrix);
}

HRESULT APIENTRY hkIDirect3DDevice8::SetViewport( CONST D3DVIEWPORT8* pViewport)
{
	return m_pD3Ddev->SetViewport(pViewport);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetViewport( D3DVIEWPORT8* pViewport)
{
	return m_pD3Ddev->GetViewport(pViewport);
}

HRESULT APIENTRY hkIDirect3DDevice8::SetMaterial( CONST D3DMATERIAL8* pMaterial)
{
	return m_pD3Ddev->SetMaterial(pMaterial);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetMaterial( D3DMATERIAL8* pMaterial)
{
	return m_pD3Ddev->GetMaterial(pMaterial);
}

HRESULT APIENTRY hkIDirect3DDevice8::SetLight( DWORD Index,CONST D3DLIGHT8* pLight)
{
	return m_pD3Ddev->SetLight(Index,pLight);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetLight( DWORD Index,D3DLIGHT8* pLight)
{
	return m_pD3Ddev->GetLight(Index,pLight);
}

HRESULT APIENTRY hkIDirect3DDevice8::LightEnable( DWORD Index,BOOL Enable)
{
	return m_pD3Ddev->LightEnable(Index,Enable);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetLightEnable( DWORD Index,BOOL* pEnable)
{
	return m_pD3Ddev->GetLightEnable(Index,pEnable);
}

HRESULT APIENTRY hkIDirect3DDevice8::SetClipPlane( DWORD Index,CONST float* pPlane)
{
	return m_pD3Ddev->SetClipPlane(Index,pPlane);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetClipPlane( DWORD Index,float* pPlane)
{
	return m_pD3Ddev->GetClipPlane(Index,pPlane);
}

HRESULT APIENTRY hkIDirect3DDevice8::SetRenderState( D3DRENDERSTATETYPE State,DWORD Value)
{
	return m_pD3Ddev->SetRenderState(State,Value);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetRenderState( D3DRENDERSTATETYPE State,DWORD* pValue)
{
	return m_pD3Ddev->GetRenderState(State,pValue);
}

HRESULT APIENTRY hkIDirect3DDevice8::BeginStateBlock(void)
{
	return m_pD3Ddev->BeginStateBlock();
}

HRESULT APIENTRY hkIDirect3DDevice8::EndStateBlock( DWORD* pToken)
{
	return m_pD3Ddev->EndStateBlock(pToken);
}

HRESULT APIENTRY hkIDirect3DDevice8::ApplyStateBlock( DWORD Token)
{
	return m_pD3Ddev->ApplyStateBlock(Token);
}

HRESULT APIENTRY hkIDirect3DDevice8::CaptureStateBlock( DWORD Token)
{
	return m_pD3Ddev->CaptureStateBlock(Token);
}

HRESULT APIENTRY hkIDirect3DDevice8::DeleteStateBlock( DWORD Token)
{
	return m_pD3Ddev->DeleteStateBlock(Token);
}

HRESULT APIENTRY hkIDirect3DDevice8::CreateStateBlock( D3DSTATEBLOCKTYPE Type,DWORD* pToken)
{
	return m_pD3Ddev->CreateStateBlock(Type,pToken);
}

HRESULT APIENTRY hkIDirect3DDevice8::SetClipStatus( CONST D3DCLIPSTATUS8* pClipStatus)
{
	return m_pD3Ddev->SetClipStatus(pClipStatus);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetClipStatus( D3DCLIPSTATUS8* pClipStatus)
{
	return m_pD3Ddev->GetClipStatus(pClipStatus);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetTexture( DWORD Stage,IDirect3DBaseTexture8** ppTexture)
{
	return m_pD3Ddev->GetTexture(Stage,ppTexture);
}

HRESULT APIENTRY hkIDirect3DDevice8::SetTexture(DWORD Stage,IDirect3DBaseTexture8* pTexture)
{
#ifdef D3DHOOK_TEXTURES
	IDirect3DDevice8 *dev = NULL;
	if(pTexture != NULL && ((hkIDirect3DTexture8*)(pTexture))->GetDevice(&dev) == D3D_OK)
	{
		if(dev == this)
			return m_pD3Ddev->SetTexture(Stage, ((hkIDirect3DTexture8*)(pTexture))->m_D3Dtex);
	}
#endif

	return m_pD3Ddev->SetTexture(Stage,pTexture);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetTextureStageState( DWORD Stage,D3DTEXTURESTAGESTATETYPE Type,DWORD* pValue)
{
	return m_pD3Ddev->GetTextureStageState(Stage,Type,pValue);
}

HRESULT APIENTRY hkIDirect3DDevice8::SetTextureStageState( DWORD Stage,D3DTEXTURESTAGESTATETYPE Type,DWORD Value)
{
	return m_pD3Ddev->SetTextureStageState(Stage,Type,Value);
}

HRESULT APIENTRY hkIDirect3DDevice8::ValidateDevice( DWORD* pNumPasses)
{
	return m_pD3Ddev->ValidateDevice(pNumPasses);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetInfo( DWORD DevInfoID,void* pDevInfoStruct,DWORD DevInfoStructSize)
{
	return m_pD3Ddev->GetInfo(DevInfoID,pDevInfoStruct,DevInfoStructSize);
}

HRESULT APIENTRY hkIDirect3DDevice8::SetPaletteEntries( UINT PaletteNumber,CONST PALETTEENTRY* pEntries)
{
	return m_pD3Ddev->SetPaletteEntries(PaletteNumber,pEntries);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetPaletteEntries(UINT PaletteNumber,PALETTEENTRY* pEntries)
{
	return m_pD3Ddev->GetPaletteEntries(PaletteNumber, pEntries);
}

HRESULT APIENTRY hkIDirect3DDevice8::SetCurrentTexturePalette(UINT PaletteNumber)
{
	return m_pD3Ddev->SetCurrentTexturePalette(PaletteNumber);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetCurrentTexturePalette(UINT *PaletteNumber)
{
	return m_pD3Ddev->GetCurrentTexturePalette(PaletteNumber);
}

HRESULT APIENTRY hkIDirect3DDevice8::DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType,UINT StartVertex,UINT PrimitiveCount)
{
	return m_pD3Ddev->DrawPrimitive(PrimitiveType, StartVertex, PrimitiveCount);
}

HRESULT APIENTRY hkIDirect3DDevice8::DrawIndexedPrimitive(D3DPRIMITIVETYPE PrimitiveType,UINT minIndex,UINT NumVertices,UINT startIndex,UINT primCount)
{
	return m_pD3Ddev->DrawIndexedPrimitive(PrimitiveType, minIndex, NumVertices, startIndex, primCount);
}

HRESULT APIENTRY hkIDirect3DDevice8::DrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType,UINT PrimitiveCount,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride)
{
	return m_pD3Ddev->DrawPrimitiveUP(PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride);
}

HRESULT APIENTRY hkIDirect3DDevice8::DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType,UINT MinVertexIndex,UINT NumVertexIndices,UINT PrimitiveCount,CONST void* pIndexData,D3DFORMAT IndexDataFormat,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride)
{
	return m_pD3Ddev->DrawIndexedPrimitiveUP(PrimitiveType, MinVertexIndex, NumVertexIndices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride);
}

HRESULT APIENTRY hkIDirect3DDevice8::ProcessVertices(UINT SrcStartIndex,UINT DestIndex,UINT VertexCount,IDirect3DVertexBuffer8* pDestBuffer,DWORD Flags)
{
	return m_pD3Ddev->ProcessVertices(SrcStartIndex, DestIndex, VertexCount, pDestBuffer, Flags);
}

HRESULT APIENTRY hkIDirect3DDevice8::CreateVertexShader(CONST DWORD* pDeclaration,CONST DWORD* pFunction,DWORD* pHandle,DWORD Usage)
{
	return m_pD3Ddev->CreateVertexShader(pDeclaration, pFunction, pHandle, Usage);
}

HRESULT APIENTRY hkIDirect3DDevice8::SetVertexShader(DWORD Handle)
{
	return m_pD3Ddev->SetVertexShader(Handle);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetVertexShader(DWORD* pHandle)
{
	return m_pD3Ddev->GetVertexShader(pHandle);
}

HRESULT APIENTRY hkIDirect3DDevice8::DeleteVertexShader(DWORD Handle)
{
	return m_pD3Ddev->DeleteVertexShader(Handle);
}

HRESULT APIENTRY hkIDirect3DDevice8::SetVertexShaderConstant(DWORD Register,CONST void* pConstantData,DWORD ConstantCount)
{
	return m_pD3Ddev->SetVertexShaderConstant(Register, pConstantData, ConstantCount);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetVertexShaderConstant(DWORD Register,void* pConstantData,DWORD ConstantCount)
{
	return m_pD3Ddev->GetVertexShaderConstant(Register, pConstantData, ConstantCount);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetVertexShaderDeclaration(DWORD Handle,void* pData,DWORD* pSizeOfData)
{
	return m_pD3Ddev->GetVertexShaderDeclaration(Handle, pData, pSizeOfData);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetVertexShaderFunction(DWORD Handle,void* pData,DWORD* pSizeOfData)
{
	return m_pD3Ddev->GetVertexShaderFunction(Handle, pData, pSizeOfData);
}

HRESULT APIENTRY hkIDirect3DDevice8::SetStreamSource(UINT StreamNumber,IDirect3DVertexBuffer8* pStreamData,UINT Stride)
{
	return m_pD3Ddev->SetStreamSource(StreamNumber, pStreamData, Stride);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetStreamSource(UINT StreamNumber,IDirect3DVertexBuffer8** ppStreamData,UINT* pStride)
{
	return m_pD3Ddev->GetStreamSource(StreamNumber, ppStreamData, pStride);
}

HRESULT APIENTRY hkIDirect3DDevice8::SetIndices(IDirect3DIndexBuffer8* pIndexData,UINT BaseVertexIndex)
{
	return m_pD3Ddev->SetIndices(pIndexData, BaseVertexIndex);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetIndices(IDirect3DIndexBuffer8** ppIndexData,UINT* pBaseVertexIndex)
{
	return m_pD3Ddev->GetIndices(ppIndexData, pBaseVertexIndex);
}

HRESULT APIENTRY hkIDirect3DDevice8::CreatePixelShader(CONST DWORD* pFunction,DWORD* pHandle)
{
	return m_pD3Ddev->CreatePixelShader(pFunction, pHandle);
}

HRESULT APIENTRY hkIDirect3DDevice8::SetPixelShader(DWORD Handle)
{
	return m_pD3Ddev->SetPixelShader(Handle);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetPixelShader(DWORD* pHandle)
{
	return m_pD3Ddev->GetPixelShader(pHandle);
}

HRESULT APIENTRY hkIDirect3DDevice8::DeletePixelShader(DWORD Handle)
{
	return m_pD3Ddev->DeletePixelShader(Handle);
}

HRESULT APIENTRY hkIDirect3DDevice8::SetPixelShaderConstant(DWORD Register,CONST void* pConstantData,DWORD ConstantCount)
{
	return m_pD3Ddev->SetPixelShaderConstant(Register, pConstantData, ConstantCount);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetPixelShaderConstant(DWORD Register,void* pConstantData,DWORD ConstantCount)
{
	return m_pD3Ddev->GetPixelShaderConstant(Register, pConstantData, ConstantCount);
}

HRESULT APIENTRY hkIDirect3DDevice8::GetPixelShaderFunction(DWORD Handle,void* pData,DWORD* pSizeOfData)
{
	return m_pD3Ddev->GetPixelShaderFunction(Handle, pData, pSizeOfData);
}

HRESULT APIENTRY hkIDirect3DDevice8::DrawRectPatch(UINT Handle,CONST float* pNumSegs,CONST D3DRECTPATCH_INFO* pRectPatchInfo)
{
	return m_pD3Ddev->DrawRectPatch(Handle, pNumSegs, pRectPatchInfo);
}

HRESULT APIENTRY hkIDirect3DDevice8::DrawTriPatch(UINT Handle,CONST float* pNumSegs,CONST D3DTRIPATCH_INFO* pTriPatchInfo)
{
	return m_pD3Ddev->DrawTriPatch(Handle, pNumSegs, pTriPatchInfo);
}

HRESULT APIENTRY hkIDirect3DDevice8::DeletePatch(UINT Handle)
{
	return m_pD3Ddev->DeletePatch(Handle);
}