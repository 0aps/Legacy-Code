#define _WIN32_WINNT  0x0501
#define NO_STRICT
#include <windows.h>
//#include <winternl.h>
#include <iostream>
#include <cassert>

typedef long NTSTATUS;
#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)

typedef enum _PROCESSINFOCLASS { ProcessBasicInformation } PROCESSINFOCLASS;

typedef struct _INFOBLOCK
{
unsigned long dwFiller[16];
unsigned short wLength;
unsigned short wMaxLength;
const unsigned short *dwCmdLineAddress;
const unsigned short *env;
} INFOBLOCK, *PINFOBLOCK;

typedef struct _PEB
{
unsigned long dwFiller[4];
PINFOBLOCK dwInfoBlockAddress;
} PEB, *PPEB;

typedef struct _PROCESS_BASIC_INFORMATION
{
NTSTATUS ExitStatus;
PPEB PebBaseAddress;
unsigned long AffinityMask;
long BasePriority;
unsigned long UniqueProcessId;
unsigned long InheritedFromUniqueProcessId;
} PBI;

wchar_t*  GetEnvironmentStringsW( HANDLE  hproc )
{
  void* p_ntdll = GetModuleHandle( "ntdll.dll" ) ;
  typedef NTSTATUS (__stdcall* tfn_qip ) ( HANDLE,
                    PROCESSINFOCLASS, void*, ULONG, PULONG ) ;
                    
  tfn_qip pfn_qip = tfn_qip( GetProcAddress( p_ntdll, 
                     "NtQueryInformationProcess" ) ) ;
  assert( pfn_qip ) ;
  
  PBI pbi ;
  ULONG res_len = 0 ;
  NTSTATUS status = pfn_qip( hproc,  ProcessBasicInformation,
                     &pbi, sizeof(pbi), &res_len ) ;
  assert( res_len == sizeof(pbi) ) ;
  size_t ppeb = size_t( pbi.PebBaseAddress ) ;

  char peb[ sizeof(PEB) ] ;
  DWORD read ;
  ReadProcessMemory( hproc, pbi.PebBaseAddress, 
                           peb, sizeof(peb), &read ) ; 
  assert( read == sizeof(peb) ) ;

  enum { OFFSET_PEB = 0x10, OFFSET_X = 0x48 };
  
  void* ptr = (void*) *(INT_PTR*)(peb + OFFSET_PEB ) ;
  char buffer[ OFFSET_X + sizeof(void*) ] ;
  ReadProcessMemory( hproc, ptr, buffer, sizeof(buffer), &read ) ; 
  assert( read == sizeof(buffer) ) ;
  
  void* penv = (void*) *(INT_PTR*)( buffer + OFFSET_X ) ;
  enum { MAX_ENV_SIZE = 4096 }; 
  wchar_t* env = new wchar_t[ MAX_ENV_SIZE ] ;
  ReadProcessMemory( hproc, penv, env, MAX_ENV_SIZE, &read ) ; 
  assert( read > 0 ) ;
  
  return env ;
}

// pequeña prueba
int main()
{
  HWND hwnd = FindWindow( 0, "Solitaire" ) ;
  assert( hwnd ) ;
  DWORD procid = 0 ;
  GetWindowThreadProcessId( hwnd, &procid ) ;
  assert( procid ) ;
  
  //Una manera de tener mas presicion al abrir el proceso. 
  //Practicamente se suman los flags
  DWORD amask = PROCESS_QUERY_INFORMATION | PROCESS_VM_READ ;
  
  HANDLE hproc = OpenProcess( amask, 0, procid ) ;
  assert( hproc ) ;
  
  wchar_t* env = GetEnvironmentStringsW( hproc ) ;

  wchar_t* pwstr = env  ;
  do
  {
    std::cout << pwstr << '\n' ;
    pwstr += wcslen(pwstr) + 1 ; //strlen
  }while( *pwstr ) ;

  delete[] env  ;
}
