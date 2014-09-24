#include <stdio.h>
#include <windows.h>

/* 
USOS:
Para obtener el valor de otro registro 
cambiar donde dice con.Eax por
con.Registro_que_quieras
Indetectables.net/foro
funcion-linkgl.blogspot.com
*/

DWORD ObtenerRegistro(LPSTR szProcessName)
{
       /* Linkgl - Funcion-linkgl.blogspot.com */
    //Estructura startup requerida para createprocess
    //estructura process information requerida para el pid
    //estructura context contiene los valores de los registros
    STARTUPINFO si;
   PROCESS_INFORMATION pi;
   CONTEXT con;
   // limpiamos la estructura si
   memset(&si, 0, sizeof(si));
   //indicamos el tamaño de la estructura
   //en el flag como indica la msdn
   si.cb = sizeof(STARTUPINFO);
   con.ContextFlags = CONTEXT_FULL;
   CreateProcess(NULL, szProcessName, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &si, &pi);
   //obtenemos el contexto y con ello se obtienen los registros
    GetThreadContext(pi.hThread, &con);
    //continuamos el hilo
    ResumeThread(pi.hThread);
    //mandamos el registro
    return con.Eax;
}

BOOL EscribirRegistro(LPSTR szProcessName,DWORD valor)
{
    /* Linkgl - Funcion-linkgl.blogspot.com */
    //Estructura startup requerida para createprocess
    //estructura process information requerida para el pid
    //estructura context contiene los valores de los registros
    STARTUPINFO si;
   PROCESS_INFORMATION pi;
   CONTEXT con;
   // limpiamos la estructura si
   memset(&si, 0, sizeof(si));
   //indicamos el tamaño de la estructura
   //en el flag como indica la msdn
   si.cb = sizeof(STARTUPINFO);
   con.ContextFlags = CONTEXT_FULL;
   //creamos el proceso
   CreateProcess(NULL, szProcessName, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &si, &pi);
   //obtenemos el contexto y con ello se obtienen los registros
    GetThreadContext(pi.hThread, &con);
    //ponemos el nuevo valor
   con.Eax = valor;
   //lo guardamos en el hilo
   SetThreadContext(pi.hThread,&con);
   //continuamos el hilo
    ResumeThread(pi.hThread);
    return TRUE;
}

//->EJEMPLO DE USO
int main()
{
DWORD eax;
//Cambiamos el valor eax (osea vamos a cambiar el entrypoint)
EscribirRegistro("c:\\final.exe",0x413b72f);
//Obtenemos el registro aver si se cambio
eax=ObtenerRegistro("c:\\final.exe");
//Imprimimos el nuevo registro o entrypoint
printf("%x",eax);
getchar();
return 0;
}
