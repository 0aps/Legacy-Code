#include <windows.h>
 
HANDLE m_hThread;
HANDLE hSemaphore;UINT av;
DWORD thid;CHAR msg[60];
 
typedef struct minfo{
    HANDLE hsSemaphore;
    UINT thident;
}TypeSemInfo;
 
DWORD WINAPI myarraythreadproc(LPVOID params){
    TypeSemInfo *SemaphI;
    SemaphI=(TypeSemInfo*)params;
    //Esperamos indefinidamente hasta que se active el sem�foro...
    switch(WaitForSingleObject(SemaphI->hsSemaphore,INFINITE)){
        case WAIT_OBJECT_0:
            //Mostramos el argumento...
            sprintf(msg,"Sa Activ� el Hilo %d",SemaphI->thident+1);
            MessageBox(NULL,msg,"Hilo",MB_ICONEXCLAMATION | MB_OK);
        break;
        default:
            //Ocurri� un error...
        break;
    }
    //Contin�a ejecuci�n
 
    MessageBox(NULL,"Contin�a Ejecuci�n del Hilo, Desbloqueamos el Sem�foro." ,"Hilo",MB_ICONEXCLAMATION | MB_OK);
    //Incrementamos contador
    ReleaseSemaphore(SemaphI->hsSemaphore,1,NULL);
    //Finalizamos thread...
    ExitThread(0);
}
 
//Main Proc
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR CmdLine, INT nCmdShow){
    m_hThread=NULL;hSemaphore=NULL;
    TypeSemInfo SemInfo[10];
    //Creamos Objetos...
    hSemaphore=CreateSemaphore(NULL,3,3,"#1234#SEMAPHORE#1234#");
    if(!hSemaphore){
        MessageBox(NULL,"Error al crear Sem�foro...",0,MB_ICONEXCLAMATION | MB_OK);
        return -1;
    }
 
    //lanzamos threads...
    for(av=0;av<10;av++){
        SemInfo[av].hsSemaphore=hSemaphore;
        SemInfo[av].thident=av;
        if(!(m_hThread=CreateThread(NULL, 0, myarraythreadproc,(LPVOID)&SemInfo[av],0,&thid))){
            MessageBox(NULL,"Error al crear thread...",0,MB_ICONEXCLAMATION | MB_OK);
            return -1;
        }
    }
    //Esperamos indefinidamente hasta tener control del Sem�foro...
    switch(WaitForSingleObject(hSemaphore,INFINITE)){
        case WAIT_OBJECT_0:
            //Mostramos el mensaje...
            MessageBox(NULL,"Obtubimos el control del Sem�foro","Main",MB_ICONEXCLAMATION | MB_OK);
        break;
        default:
            //Ocurri� un error...
        break;
    }
    ReleaseSemaphore(hSemaphore,1,NULL);
    //Esperamos fin...
    MessageBox(NULL,"Presione aceptar para continuar...","Salir",MB_ICONEXCLAMATION | MB_OK);
    //Eliminamos Sem�foro...
    CloseHandle(hSemaphore);
    return 0;
}
