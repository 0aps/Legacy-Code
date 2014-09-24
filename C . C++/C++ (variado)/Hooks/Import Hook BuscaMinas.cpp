#include <windows.h>
#include <Tlhelp32.h>
#include <iostream>

using namespace std;

void HookImport();
int Buscar_Proceso();

HPEN __stdcall CreatePenF( int , int , COLORREF  );

HANDLE CProc;              //Para crear la captura de la lista de procesos
HANDLE hProc;           //Para guardar el manejador del proceso
PROCESSENTRY32 Proceso;    //Necesario para realizar la captura de procesos
DWORD   pid;

int main()
{
    
     if(Buscar_Proceso() == 0)
     {
                       cout << "Se encontro el proceso. " << endl;
                       cout << "El pid es : " << hex << pid << endl;
     }else cout << "No se encontro el proceso." ;  
    
     if( (hProc = OpenProcess(PROCESS_ALL_ACCESS, false, pid) ) == NULL)
                {    
                  cout << "No se pudo abrir el proceso. " << endl;
                }else cout << "Se abrio el proceso." << endl;
                
    HookImport();
    
    setbuf(stdin, NULL);
    cin.get();
    return 0;
}



void HookImport()
{
     
    HANDLE hFile = CreateFileA("C:\\WINDOWS\\system32\\winmine.exe", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_WRITE | FILE_SHARE_READ, 0, OPEN_EXISTING, 0,0);
    DWORD tam = GetFileSize(hFile,0);
    
    HANDLE    FileMap  =  CreateFileMapping(hFile, 0, PAGE_READWRITE, 0, tam, 0);
    HMODULE   Proc    = (HMODULE)MapViewOfFile(FileMap, FILE_MAP_ALL_ACCESS, 0, 0, 0); 
       
  HMODULE Gdi32   = LoadLibrary("Gdi32.dll");
  DWORD CreatePen = (DWORD)GetProcAddress(Gdi32, "CreatePen");
  
  PIMAGE_DOS_HEADER Img = (PIMAGE_DOS_HEADER)Proc;
  
  cout << "hFile = " << hFile << endl;  
  cout << "Tam   = " << tam << endl;
  cout << "FleMap= " << FileMap << endl;
  cout << "Proc  = " << Proc  << endl;
  
  cout << "hProc = " << hProc << endl;
  cout << "Gdi32 = " << Gdi32 << endl;
  cout << "CreatePen = " << CreatePen << endl;
  cout << "Img = " << Img << endl;
  
  
  cin.get(); 
  
   
  //e lfanew apunta a donde empieza el encabezado nt
  PIMAGE_NT_HEADERS Pe  = (PIMAGE_NT_HEADERS) ( (BYTE*)Img + Img->e_lfanew ); 
 
  // obtengo la direccion del import table el principio
  LPDWORD ImportAddr = (LPDWORD)( (DWORD)Pe->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress + (DWORD)Img);
  
  cout << "PE  = " << Pe << endl;
  cout << "ImportAddr = " << ImportAddr << endl;
  
  cin.get();
       
 // IMAGE_DATA_DIRECTOR Y DataDirector, 
 // esta estructura que contiene la direccion de las secciones en el archivo 
 // y los tamaños de estas secciones.
 
  //le cambio los privilegios a toda la import table
  DWORD old;
  
  VirtualProtect(ImportAddr, 
  Pe->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size, PAGE_READWRITE, &old); 
       
  for (int x = 0; x < Pe->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size; x += 4, ImportAddr++)
  {
      //funcion dentro del import table
      //para obternerla se suma el contenido de la import table mas el modulo del programa 
      //actual
       LPDWORD ImportFnc = (LPDWORD)((DWORD)*ImportAddr + (DWORD)Proc);
   
   
 cin.get();
   //si la funcion es messageboxa
      if (*ImportFnc == CreatePen)
     {
        //cambio los primeros cuatro bytes que apuntan a la direccion de memoria de messagebox
        //por los de mi funcion
       *ImportFnc = (DWORD)&CreatePenF;
       cout << "Cambie la import table" << endl;
        break;
      }		
    
   }
}


HPEN __stdcall CreatePenF( int fnPenStyle, int nWidth, COLORREF crColor )
{
     HPEN hpen;
}


int Buscar_Proceso()
{
   
    //Con esto creamos una captura de la lista de procesos y la guardamos en CProc
    CProc          =   CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);   
	
    Proceso.dwSize =   sizeof(PROCESSENTRY32);
    
    Process32First(CProc,&Proceso);    //Leemos el primer proceso

    //Mientras haya procesos para leer leemos el siguiente
	while(Process32Next(CProc,&Proceso))   
	{
                                           
	  if(!strcmp(Proceso.szExeFile, "winmine.exe") )
         {
           pid = Proceso.th32ProcessID;
                
	       return 0;
         }
    }
    
    pid    = 0; 
    return   1;
}

