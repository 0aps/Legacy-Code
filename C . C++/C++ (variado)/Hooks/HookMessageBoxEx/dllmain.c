/* Replace "dll.h" with the name of your header */
#include "dll.h"
#include <windows.h>

//Puntero al buffer donde guardaremos las instrucciones copiadas de la api y
//el salto a la api+5
BYTE *Buffer;

//Ésta es la dll donde reside la api MessageBoxExA
char Libreria[]="user32.dll";

//El api en qüestión
char NomApi[]="MessageBoxExA";

//Funcion a la que llamará el programa principal creiendo que es la api original
int WINAPI FuncioRep(HWND hWnd,LPCSTR lpText,LPCTSTR lpCaption,UINT uType,UINT LangId);

void Hookear(void);

//Puntero a función, utilizando este puntero conseguiremos ejecutar el código contenido en el buffer
int (__stdcall *pBuff)(HWND hWnd,LPCSTR lpText,LPCTSTR lpCaption,UINT uType,UINT LangId);
//La función de reemplazo explicada arriba
int WINAPI FuncioRep(HWND hWnd,LPCTSTR lpText,LPCTSTR lpCaption,UINT uType,UINT LangId){

  //Cadena que le pegará vacilada al programa principal xD
  char texto[]="Te acabo de hookear mwahahahaha";

  int Resultado;

  //Hacemos la llamada al puntero a buffer (api original) cambiandole el parametro texto
  Resultado=pBuff(hWnd,texto,lpCaption,uType,LangId);

  //Le damos el resultado que daría la api original al programa principal
  return Resultado;
}
 
void Hookear(void){

  DWORD ProteVieja;
  BYTE *DirApi;
  BYTE *DirYo;

  //Cojemos la dirección de memoria de la api
  DirApi=(BYTE *) GetProcAddress(GetModuleHandle(Libreria),NomApi);

  //Creamos 10bytes de memoria para nuestro Buffer
  Buffer=(BYTE *)malloc(10);

  //Le damos todos los permisos a los 10 bytes de nuestro Buffer
  VirtualProtect((void *) Buffer, 12, PAGE_EXECUTE_READWRITE, &ProteVieja);

  //copiamos los 5 primeros bytes originales de la api antes de machacarlos
  memcpy(Buffer,DirApi,5);
  Buffer+=5;

  //En el sexto introducimos E9 que corresponde a jmp(salto
  //incondicional) en código máquina para que salte a la api original
  *Buffer=0xE9;
   Buffer++;

  //A partir del septimo metemos 4 bytes que determinan la distancia del salto
  //desde el buffer hasta la Dirección de la api+5
  //se convierte a signed int para que tome cuadro bytes 

  *((signed int *) Buffer)=(DirApi+1)-Buffer;

  //Asignamos al puntero a funcion pBuff el inicio del Buffer
  //buffer menos 6 es el inicio del buffer
  //aqui se le asigna una direccion de memoria al MALDITO BUFFER
  //se hace una convencion a buffer
  //apunta a los cuatro primeros bytes de buffer
  
  pBuff = (int (__stdcall *)(HWND,LPCTSTR,LPCTSTR,UINT,UINT) ) (Buffer-6);

  //Le damos todos los permisos a los 5 primeros bytes de la api original
  VirtualProtect((void *) DirApi,5,PAGE_EXECUTE_READWRITE,&ProteVieja);

  //Cambiamos el tipo a puntero a byte para facilitar el trabajo
  DirYo=(BYTE *) FuncioRep;

  //En el inicio de la api metemos un salto incondicional hacia nuestro código
  //E9=jmp
  *DirApi=0xE9;
  DirApi++;
  //Los 4 siguientes bytes determinan la distancia del salto desde la api hasta
  //la función de reemplazo en nuestro código, fijate que en este caso el
  //resultado tiene que ser negativo, puesto que las apis corren en direcciones
  //de memória mucho mas altas y el salto deberá ser "hacia atrás"
  *((signed int *) DirApi)=DirYo-(DirApi+4);

  //libermos las librerias de cache
  FlushInstructionCache(GetCurrentProcess(),0,0);
}
 
BOOL APIENTRY DllMain (HINSTANCE hInst     /* Library instance handle. */ ,
                       DWORD reason        /* Reason this function is being called. */ ,
                       LPVOID reserved     /* Not used. */ )
{
    switch (reason)
    {
      case DLL_PROCESS_ATTACH:
       
       MessageBox(NULL, "me iyecte!", "titulo", 0); 
       
       Hookear();
        
        break;

      case DLL_PROCESS_DETACH:
        break;

      case DLL_THREAD_ATTACH:
        break;

      case DLL_THREAD_DETACH:
        break;
    }

    /* Returns TRUE on success, FALSE on failure */
    return TRUE;
}
