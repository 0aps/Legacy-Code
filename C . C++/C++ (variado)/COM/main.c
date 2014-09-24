/*
  Copyright: InExInferis Inc.
  URL: http://www.inexinferis.co.nr
  Author: Karman
  Date: 26/10/05 13:27
*/

#include <windows.h>

GUID CLSID_MyServerCOM={0x11042006,0x1999,0x2006,0x1B,0x0A,0x2C,0x3D,0x4E,0x5F,0x6E,0x7D};
GUID IID_IMyMessageCOM={0x11042006,0x1999,0x2006,0x0A,0x1B,0x2C,0x3D,0x4E,0x5F,0x6E,0x7D};
HINSTANCE g_hinstThisDll=NULL;
UINT g_uDllRefCount=0;

//***************************************************************
//                    My C Classes
//***************************************************************

#ifndef __IMyMessageBox__
#define __IMyMessageBox__

typedef struct IMyMessageBox { 
  struct IMyMessageBoxVtbl *lpVtbl;
  UINT uRefCount;
}IMyMessageBox;

typedef struct IMyMessageBoxVtbl IMyMessageBoxVtbl;

struct IMyMessageBoxVtbl{
	STDMETHOD(QueryInterface)(IMyMessageBox*, REFIID,PVOID*);
	STDMETHOD_(ULONG,AddRef)(IMyMessageBox*);
	STDMETHOD_(ULONG,Release)(IMyMessageBox*);
	STDMETHOD(MyMessageBox)(IMyMessageBox*, BSTR,BSTR);
};
typedef IMyMessageBox *LPIMYMESSAGEBOX;

#endif //__IMyMessageBox__

//***************************************************************
//                    My COM Implementation
//***************************************************************

STDMETHODIMP MyMessageBoxImp(IMyMessageBox *this, BSTR bsMessageTitle, BSTR bsMessageText){
  MessageBoxW(NULL,(WCHAR*)bsMessageText,(WCHAR*)bsMessageTitle,MB_ICONEXCLAMATION|MB_OK);
  return S_OK;
}

STDMETHODIMP_(ULONG) MyAddRefImp(IMyMessageBox *this){
  return ++(this->uRefCount);
}

STDMETHODIMP_(ULONG) MyReleaseImp(IMyMessageBox *this){
  UINT refs=--(this->uRefCount);
  if (!refs){g_uDllRefCount--;GlobalFree(this);}
  return refs;
}

STDMETHODIMP MyQueryInterfaceImp(IMyMessageBox *this,REFIID riid,PVOID *ppv){
  if(IsBadWritePtr(ppv,sizeof(void*)))return E_POINTER;*ppv=NULL;
  if(IsEqualGUID(riid,&IID_IMyMessageCOM)||IsEqualGUID(riid,&IID_IUnknown)){ 
    *ppv= this;
    this->lpVtbl->AddRef(this);
    return S_OK;
  }else return E_NOINTERFACE;
}

static IMyMessageBoxVtbl IMyMessageBox_Vtbl = {MyQueryInterfaceImp,
MyAddRefImp,MyReleaseImp,MyMessageBoxImp};

//*******************************************************************
//                       MyClassFactory Implementation
//*******************************************************************

STDMETHODIMP_(ULONG) AddRefImp(IClassFactory *this){
  return 1;
}

STDMETHODIMP_(ULONG) ReleaseImp(IClassFactory *this){
  return 1;
}

STDMETHODIMP QueryInterfaceImp(IClassFactory *this,REFIID riid,PVOID *ppv){
  if(IsBadWritePtr(ppv,sizeof(void*)))return E_POINTER;*ppv = NULL;
  if(IsEqualGUID(riid,&IID_IUnknown)||IsEqualGUID(riid,&IID_IClassFactory)){
    *ppv= this;return S_OK;
  }else return E_NOINTERFACE;
}

STDMETHODIMP CreateInstanceImp(IClassFactory *this,LPUNKNOWN pUnkOuter,REFIID riid,PVOID *ppv){
  HRESULT hrRet;IMyMessageBox *pObject;
  if(pUnkOuter)return CLASS_E_NOAGGREGATION;
  pObject = (IMyMessageBox *)GlobalAlloc(GPTR, sizeof(IMyMessageBox));
  if(!pObject)return E_OUTOFMEMORY;
  //constructor pMyObject
  g_uDllRefCount++;pObject->uRefCount=0;
  pObject->lpVtbl = &IMyMessageBox_Vtbl;
  //*********************
  pObject->lpVtbl->AddRef(pObject);
  hrRet = pObject->lpVtbl->QueryInterface(pObject,riid,ppv);
  pObject->lpVtbl->Release(pObject);
  return hrRet;
}

STDMETHODIMP LockServerImp(IClassFactory *this,BOOL fLock){
  fLock?g_uDllRefCount++:g_uDllRefCount--;
  return S_OK;
}

static IClassFactoryVtbl IClassFactory_Vtbl = {QueryInterfaceImp,
AddRefImp,ReleaseImp,CreateInstanceImp,LockServerImp};
static IClassFactory MyFactory={&IClassFactory_Vtbl};
//***********************************************************************
//                      DLL FUNC'S
//***********************************************************************

BOOL APIENTRY DllMain (HINSTANCE hInstance,DWORD dwReason,LPVOID reserved){
  if (dwReason == DLL_PROCESS_ATTACH){
    g_hinstThisDll = hInstance;
    DisableThreadLibraryCalls(hInstance);
  }return TRUE;
}

// DllRegisterServer - Adds entries to the system registry
STDAPI DllRegisterServer(void){
  return S_OK;//Implementado en COMServer C++
}

// DllUnregisterServer - Removes entries from the system registry
STDAPI DllUnregisterServer(void){
  return S_OK;//Implementado en COMServer C++
}

// Podemos Descargar la DLL?
STDAPI DllCanUnloadNow(void){
  return (g_uDllRefCount>0)?S_FALSE:S_OK;
}

// Devolvemos la Intefaz de la  Fábrica de Clases...
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv){
  if(!IsEqualGUID(rclsid,&CLSID_MyServerCOM))return CLASS_E_CLASSNOTAVAILABLE;    
  return MyFactory.lpVtbl->QueryInterface(&MyFactory,riid,ppv); 
}
