#include <windows.h>

#include "main.h"
#include "d3d8.h"

tDirect3DCreate8 oDirect3DCreate8;

IDirect3D8 *APIENTRY hkDirect3DCreate8(UINT SDKVersion)
{
	IDirect3D8 *d3dint = oDirect3DCreate8(SDKVersion);

	if( d3dint != NULL )
	{
		hkIDirect3D8 *ret = new hkIDirect3D8(&d3dint);
		add_log("Direct3DCreate8(%i) succeeded...", SDKVersion);
		add_log("Hooked Direct3D8 interface: 0x%x -> 0x%x", ret->m_pD3Dint, ret);
	}
	else
		add_log("Direct3DCreate8(%i) failed...", SDKVersion);

	return d3dint;
}
