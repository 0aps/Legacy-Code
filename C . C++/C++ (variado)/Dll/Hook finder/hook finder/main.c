#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>

#define MakePtr(cast,ptr,addValue) (cast)((DWORD)(ptr)+(DWORD)(addValue))

void DbgPrint(const char *form, ...){
  static char tmp[2048];va_list p;
  va_start(p, form);
  vsprintf(tmp,form,p);
  OutputDebugString(tmp);
  va_end(p);
}

PIMAGE_SECTION_HEADER RVA2Section(PIMAGE_NT_HEADERS pNTHeader,DWORD dwRVA){
  PIMAGE_SECTION_HEADER pimage_section_header;int i;
  for(i=0;i<pNTHeader->FileHeader.NumberOfSections;i++){
    pimage_section_header=(PIMAGE_SECTION_HEADER)(
    (LPBYTE)&pNTHeader->OptionalHeader+pNTHeader->FileHeader.SizeOfOptionalHeader+
    (i*sizeof(IMAGE_SECTION_HEADER)));
    if((dwRVA>=pimage_section_header->VirtualAddress)&&(dwRVA<=(pimage_section_header->VirtualAddress+pimage_section_header->SizeOfRawData)))
      return ((PIMAGE_SECTION_HEADER)pimage_section_header);
  }
  return(NULL);
}

DWORD RVA2Offset(PIMAGE_NT_HEADERS pNTHeader,DWORD dwRVA){
  PIMAGE_SECTION_HEADER section;
  if((section=RVA2Section(pNTHeader,dwRVA)))
    return (dwRVA+section->PointerToRawData-section->VirtualAddress);
  return 0;
}

PBYTE RVAValue(PBYTE pBuf,PIMAGE_NT_HEADERS pNTHeader,DWORD dwRVA){
  return &pBuf[RVA2Offset(pNTHeader,dwRVA)];
}

DWORD WINAPI FindHooks(LPVOID lpParam){
  PBYTE pBuf;DWORD dwRead;
  MODULEENTRY32 pEntry32;HANDLE hFile;DWORD dwFileSize;
  PIMAGE_DOS_HEADER pDosHeaderMem,pDosHeaderDisk;
  PIMAGE_NT_HEADERS pNTHeaderMem,pNTHeaderDisk;
  PIMAGE_EXPORT_DIRECTORY pExportDescMem,pExportDescDisk;
  PIMAGE_THUNK_DATA pThunkMem,pThunkDisk;

  MessageBox(0,"Press OK to Start",0,0);

  DbgPrint(" **** Start Finding Hooks **** ");

  pEntry32.dwSize=sizeof(MODULEENTRY32);
  HANDLE hSnapshot=CreateToolhelp32Snapshot(TH32CS_SNAPMODULE,0);
  if(hSnapshot==INVALID_HANDLE_VALUE)
    return;
  if(!Module32First(hSnapshot,&pEntry32)){
    CloseHandle(hSnapshot);
    return;
  }
  do{
    hFile=CreateFile(pEntry32.szExePath,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,0,NULL);
    if(hFile!=INVALID_HANDLE_VALUE){
      dwFileSize=GetFileSize(hFile,NULL);
      if(dwFileSize!=0xFFFFFFFF){
        pBuf=(PBYTE)GlobalAlloc(GPTR, dwFileSize + 1);
        if(pBuf!=NULL){
          if(ReadFile(hFile,pBuf,dwFileSize,&dwRead,NULL)){
            DbgPrint(" **** Finding Hooks in Module: [%s] [%X] **** ",pEntry32.szExePath,pEntry32.hModule);
            pDosHeaderMem=(PIMAGE_DOS_HEADER)pEntry32.hModule;
            if(pDosHeaderMem->e_magic==IMAGE_DOS_SIGNATURE){
              pDosHeaderDisk=(PIMAGE_DOS_HEADER)pBuf;
              pNTHeaderMem=MakePtr(PIMAGE_NT_HEADERS,pDosHeaderMem,pDosHeaderMem->e_lfanew);
      	      if(pNTHeaderMem->Signature==IMAGE_NT_SIGNATURE){
                pNTHeaderDisk=MakePtr(PIMAGE_NT_HEADERS,pDosHeaderDisk,pDosHeaderDisk->e_lfanew);
                pExportDescMem=MakePtr(PIMAGE_EXPORT_DIRECTORY,pDosHeaderMem,pNTHeaderMem->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress);
                if(pExportDescMem!=(PIMAGE_EXPORT_DIRECTORY)pDosHeaderMem){
                  pExportDescDisk=(PIMAGE_EXPORT_DIRECTORY)RVAValue((PBYTE)pDosHeaderDisk,pNTHeaderDisk,(DWORD)pNTHeaderDisk->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress);
                  DWORD ImageBase=(DWORD)pNTHeaderMem->OptionalHeader.ImageBase;

                  PDWORD Memfuncs=MakePtr(PDWORD,pDosHeaderMem,pExportDescMem->AddressOfFunctions);
                  PDWORD Memapinames=MakePtr(PDWORD,pDosHeaderMem,pExportDescMem->AddressOfNames);
                  PWORD  Memordls=MakePtr(PWORD,pDosHeaderMem,pExportDescMem->AddressOfNameOrdinals);

                  PDWORD Diskfuncs=(PDWORD)RVAValue((PBYTE)pDosHeaderDisk,pNTHeaderDisk,pExportDescDisk->AddressOfFunctions);
                  PDWORD Diskapinames=(PDWORD)RVAValue((PBYTE)pDosHeaderDisk,pNTHeaderDisk,pExportDescDisk->AddressOfNames);
                  PWORD  Diskordls=(PWORD)RVAValue((PBYTE)pDosHeaderDisk,pNTHeaderDisk,pExportDescDisk->AddressOfNameOrdinals);
                  int i,j;
                  for(i=0;i<pExportDescMem->NumberOfFunctions;i++){
                    for(j=0;j<pExportDescMem->NumberOfNames;j++){
                      if(i==Memordls[j]){
                        DWORD dwback;
                        if(VirtualProtect((LPVOID)(ImageBase+Memfuncs[i]),4,PAGE_EXECUTE_READWRITE,&dwback)){
                          if(RVA2Offset(pNTHeaderDisk,Diskfuncs[i])&&(ImageBase+Memfuncs[i])&&!IsBadReadPtr((LPVOID)ImageBase+Memfuncs[i],4)&&
                          *(DWORD*)(ImageBase+Memfuncs[i])&&*(DWORD*)RVAValue((PBYTE)pDosHeaderDisk,pNTHeaderDisk,Diskfuncs[i])&&
                          *(DWORD*)(ImageBase+Memfuncs[i])!=*(DWORD*)RVAValue((PBYTE)pDosHeaderDisk,pNTHeaderDisk,Diskfuncs[i]))
                            DbgPrint("Difference found in: [%s] address -> [0x%X] offset -> [0x%X] values[0x%X][0x%X]",MakePtr(PCHAR,pDosHeaderMem,Memapinames[j]),ImageBase+Memfuncs[i],RVA2Offset(pNTHeaderDisk,Diskfuncs[i]),
                            *(DWORD*)(ImageBase+Memfuncs[i]),*(DWORD*)RVAValue((PBYTE)pDosHeaderDisk,pNTHeaderDisk,Diskfuncs[i]));
                          VirtualProtect((LPVOID)(ImageBase+Memfuncs[i]),4,dwback,&dwback);
                        }
                        break;
                      }
                    }
                  }
                }
              }
            }
          }
          GlobalFree(pBuf);
        }
      }
      CloseHandle(hFile);
    }
  }while(Module32Next(hSnapshot,&pEntry32));
  DbgPrint(" **** Finish **** ");
  CloseHandle(hSnapshot);
  return 0;
}

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved){
  if(fdwReason==DLL_PROCESS_ATTACH)
    CreateThread(NULL,0,FindHooks,NULL,0,NULL);
  return TRUE;
}
