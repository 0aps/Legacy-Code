/*
  Copyright: InExInferis Inc.
  URL: http://www.inexinferis.co.nr
  Author: Karman
  Date: 26/10/05 13:27
*/

///////////////////////////////////////////////////////////
//              Métodos de Nuestro Servidor
///////////////////////////////////////////////////////////
#ifndef __IMyMessageCOM_INTERFACE_DEFINED__
#define __IMyMessageCOM_INTERFACE_DEFINED__
#undef INTERFACE
#define INTERFACE IMyMessageCOM
DECLARE_INTERFACE_(IMyMessageCOM,IUnknown){
  // IUnknown
	STDMETHOD(QueryInterface)(THIS_ REFIID,PVOID*) PURE;
	STDMETHOD_(ULONG,AddRef)(THIS) PURE;
	STDMETHOD_(ULONG,Release)(THIS) PURE;
	
  // IMyMessageCOM
  STDMETHOD(MyMessageBox)(THIS_ BSTR,BSTR) PURE;
};
typedef IMyMessageCOM *LPMYMESSAGECOM;

GUID IID_IMyMessageCOM={0x11042006,0x1999,0x2006,0x0A,0x1B,0x2C,0x3D,0x4E,0x5F,0x6E,0x7D};
GUID CLSID_MyMessageCOM={0x11042006,0x1999,0x2006,0x1B,0x0A,0x2C,0x3D,0x4E,0x5F,0x6E,0x7D};

#endif
