#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <iostream>
using namespace std;

const int ABRIR=1025;
const int GUARDAR=1026;
const int SALIR=1027;

const int ACERCA=1028;



/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
char szClassName[ ] = "WindowsApp";
HINSTANCE instancia;
char texto[10000];
int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)

{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */
    instancia=hThisInstance;
    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (instancia, "ICONO");
    wincl.hIconSm = LoadIcon (instancia, "ICONO");
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default color as the background of the window */
    wincl.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(216,216,0));


    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           WS_EX_OVERLAPPEDWINDOW,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "Practica FULL",       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           550,                 /* The programs width */
           280,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nFunsterStil);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_CREATE:
            
            static HWND hButton2 = CreateWindowEx(0, "BUTTON", "Elegir archivo", WS_CHILD|WS_VISIBLE|WS_TABSTOP, 400, 100, 100, 20, hwnd, NULL,
            instancia, 0);
            
            
              static  HWND hButton = CreateWindowEx(0, "BUTTON", "OK", WS_CHILD|WS_VISIBLE|WS_TABSTOP, 195, 200, 100, 20, hwnd, NULL,
                instancia, 0);
                //Horizontal Abajo
                static  HWND Static1 = CreateWindowEx(0, "static", "", WS_CHILD|WS_VISIBLE|WS_TABSTOP, 0, 226, 540, 20, hwnd, NULL,
                instancia, 0);
                //Horizontal Arriba
                 static  HWND Static2 = CreateWindowEx(0, "static", "", WS_CHILD|WS_VISIBLE|WS_TABSTOP, 0, 0, 540, 20, hwnd, NULL,
                instancia, 0);
                //Vertical Derecha
                 static  HWND Static3 = CreateWindowEx(0, "static", "", WS_CHILD|WS_VISIBLE|WS_TABSTOP, 0, 20, 20, 220, hwnd, NULL,
                instancia, 0);
                //Vertical Izquierda
                 static  HWND Static4 = CreateWindowEx(0, "static", "", WS_CHILD|WS_VISIBLE|WS_TABSTOP, 520, 20, 20, 220, hwnd, NULL,
                instancia, 0);
                
              static  HWND hEdit = CreateWindowEx(0x00000200L, "EDIT", "", WS_CHILD|WS_VISIBLE | WS_HSCROLL | WS_VSCROLL | ES_MULTILINE,
              140, 30, 250, 150, hwnd, NULL, 
            instancia, 0);
            
            HMENU menu1,menu2,menu3;
            menu1 = CreateMenu();
            menu2 = CreateMenu();
            menu3 = CreateMenu();
            AppendMenu(menu1,/*1*/ MF_STRING, ABRIR, "&Abrir");
            AppendMenu(menu1,/*3*/ MF_STRING | MF_CHECKED | MF_GRAYED, GUARDAR, "&Guardar");
            AppendMenu(menu1, MF_SEPARATOR, 0, NULL);
            AppendMenu(menu1,/*2*/ MF_STRING, SALIR, "&Salir");
            AppendMenu(menu2, MF_STRING , ACERCA, "&Acerca De");
            AppendMenu(menu3/*1*/, MF_STRING | MF_POPUP, (UINT)menu1, "&Archivo");
            AppendMenu(menu3 /*3*/, MF_STRING | MF_POPUP, (UINT)menu2, "&Ayuda");
          
              SetMenu(hwnd, menu3);
              
              break;
              
                   
            case WM_COMMAND:
            switch(LOWORD(wParam))
                {
                    case SALIR: 
                        {
                        PostQuitMessage (0); 
                        break;
                        }
                    case ACERCA:
                        {
                        MessageBox(0, "Nombre: Ángel\nApellido: Piña Santana\nEdad: 14 años\nColegio: Cardenal Sancha\nUbicación: República Dominicana\n\n Este Programa se realizó bajo el lenguaje C++ y usando las APIs de WINDOWS.\n\n\n ;)", "Acerca De", MB_OK | MB_ICONEXCLAMATION);
                        break;
                        }
                    case ABRIR:
                        {
                              char archivo[MAX_PATH];
                OPENFILENAME  openfn;
 
                ZeroMemory(&openfn, sizeof(openfn));
                openfn.lStructSize = sizeof(openfn);
                openfn.hwndOwner = hwnd;
                openfn.lpstrFile = archivo;
                *openfn.lpstrFile = 0;
                openfn.nMaxFile = MAX_PATH;
                openfn.lpstrFilter = "Archivos de texto .txt\0*.txt\0Cualquier archivo\0*.*\0";
                openfn.nFilterIndex = 1;
                openfn.lpstrInitialDir = "%homedrive%";
                openfn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
 
                GetOpenFileName(&openfn);
 
                char s;
                long lSize;
                size_t result;
                char *buffer;
 
 
                FILE * pFile;
                pFile = fopen ( archivo, "r+");
                if (pFile==NULL) {SetWindowText(hEdit, "Error al abrir archivo");}
               else{
 
                 // obtiene el tamanyo de el archivo       
                 fseek (pFile , 0 , SEEK_END);
                 lSize = ftell (pFile);
                 rewind (pFile);
 
 
                 //reserva memoria para contener el archivo completo            
                 buffer = (char*) malloc (sizeof(char)*lSize);
                 if (buffer == NULL) {SetWindowText(hEdit,"error de memoria");}
 
                 result = fread (buffer,1,lSize,pFile);
 	             SetWindowText(hEdit, buffer );
 
 	            //if (result != lSize) {SetWindowText(edit,"error de lectura");}
                fclose (pFile);
                free (buffer);
                }
            break;
            }
                break;
            }
                
                 if((HWND)lParam==hButton2)
            {
                char str_archivo[MAX_PATH];
                OPENFILENAME  ofn;

                ZeroMemory(&ofn, sizeof(ofn));
                ofn.lStructSize = sizeof(ofn);
                ofn.hwndOwner = hwnd;
                ofn.lpstrFile = str_archivo;
                *ofn.lpstrFile = 0;
                ofn.nMaxFile = MAX_PATH;
                ofn.lpstrFilter = "Codigos fuentes de c/c++\0*.c;*.cpp\0Archivos de texto\0*.TXT\0Cualquier archivo\0*.*\0";
                ofn.nFilterIndex = 1;
                ofn.lpstrInitialDir = "%homepath%";
                ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

                GetOpenFileName(&ofn) ?
                SendMessage(hEdit, WM_SETTEXT, false, (long int) ofn.lpstrFile):  //Es lo mismo poner ofn.lpstrFile y str_archivo
                SendMessage(hEdit, WM_SETTEXT, false, (long int) "Error al obtener el archivo");
            }
                
            if((HWND)lParam == hButton)
            {
            GetWindowText(hEdit, texto, 9999);
            MessageBox(0, texto, "Escribiste", MB_OK| MB_ICONEXCLAMATION);
            SendMessage(hEdit, WM_SETTEXT, false, (long int) "");
            }
            break;
/*            
            //////////////////////////////// 
            Inabilitar teclas Maximizar, Cerrar, etc...
            case WM_SYSCOMMAND:
            switch(wParam)
            {
                case SC_CLOSE:
                    return 0;
                    break;
                    case SC_MAXIMIZE:
                        return 0;
                        break;
                    case SC_MINIMIZE:
                            return 0;
                break;
                default:
                    return DefWindowProc (hwnd, message, wParam, lParam);
                    break;
                }
            //////////////////////////////////////////////////////////*/
            /*
            case WM_KEYUP:
               char tecla[64];
               cout << tecla << "Se presiono (y solto) la tecla numero: " << wParam;
               MessageBox(0, tecla, "---", MB_OK);
            break; 
        */
        ////////////////////////////////////////////////////////////
        case WM_CTLCOLOREDIT:
            SetTextColor((HDC)wParam, RGB(0,0,255));
            break;
            
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}







