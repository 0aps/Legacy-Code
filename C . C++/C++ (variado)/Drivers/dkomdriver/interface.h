#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#define IOCTL_DRV_HIDE (ULONG) CTL_CODE(FILE_DEVICE_UNKNOWN,0x801,METHOD_BUFFERED,FILE_WRITE_ACCESS)

const WCHAR dkomDeviceName[] = L"\\Device\\dkomdriver";
const WCHAR dkomDeviceLink[] = L"\\DosDevices\\dkomdriver";

typedef struct typeProc2Hide{
   int iPid;
   int iFlinkOffset;
}proc2Hide;

#endif //__INTERFACE_H__
