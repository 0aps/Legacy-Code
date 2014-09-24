#include <iostream>
#include <windows.h> 
using namespace std;

void telnet();
void ftp();
void trace();
void ping();
int op,p;
static string a;

int main(int argc, char *argv)
{
    for(;;)
    {
     SetConsoleTitle("Mini Consola");
    // -- Telnet  -- Ftp -- Trace -- Ping 

system("cls");
cout << "\n1.Telnet"
     << "\n2.Ftp"
     << "\n3.Trace"
     << "\n4.Ping   "
     << "\n\nSeleccione: ";
     cin >> op;
switch(op)
{
    case 1:
        telnet();
        break;
    case 2:
        ftp();
        break;
    case 3:    
        trace ();
        break;
    case 4: 
        ping ();
        break;
    default:
        cout << "Opción Invalida ";
        cout << "\nDesea salir?\n";
        char *a;
        cin >> a;
        if(a=="s" || a=="S")
        {
        exit(1);}
        else 
        break;
}
}
}
void telnet()
{
    
cout <<"\n++++++++++++    ++++++   +          + +        +  ++++++   +++++++++++++\n";
cout <<"     +          +        +          +  +       +  +              +      \n";
cout <<"     +          +        +          +    +     +  +              +      \n";
cout <<"     +          +        +          +     +    +  +              +      \n";
cout <<"     +          +++++    +          +      +   +  ++++++         +      \n";
cout <<"     +          +        +          +       +  +  +              +      \n";
cout <<"     +          +        +          +        + +  +              +      \n";
cout <<"     +          ++++++   +++++++++  +         ++  +++++++        +      \n\n";


    cout << "Ingrese la IP o URL:  ";
    cin  >> a;
    cout << "Ingrese el puerto: ";
    if(p='\0')
    {
        p=23;
    }
    cin >> p;
    system(("telnet " + a).c_str());
    cin.get();
    cin.get();
}
void ftp()
{    
cout <<"\n  ***********   ***********   ****** *    \n";
cout <<"  *                  *        *      *    \n";
cout <<"  *                  *        *      *    \n";
cout <<"  *******            *        *******     \n";
cout <<"  *                  *        *           \n";
cout <<"  *                  *        *           \n";
cout <<"  *                  *        *           \n";
cout <<"  *                  *        *           \n\n";

    cout << "Ingrese la IP o URL: ";
    cin  >> a;
    cout << "Iniciando seccion ftp a "<< a << ". . . " << "\n"; 
    Sleep(5);
    system(("ftp " + a).c_str());    
    cin.get();
    cin.get();
}
void ping()
{
cout <<"\n  ****** *   *********  **       *   ++++++++++    \n";
cout <<"  *      *       *      * *      *   *             \n";
cout <<"  *      *       *      *  *     *   *             \n";
cout <<"  ******         *      *   *    *   *  *+*  *     \n";
cout <<"  *              *      *    *   *   *        *    \n";
cout <<"  *              *      *     *  *   *         *   \n";
cout <<"  *              *      *      * *   *          *  \n";
cout <<"  *          *********  *       **   +++++++++++   \n\n";

    cout << "Ingrese la IP o URL: ";
    cin >> a;
    cout << "\n";
    system (("ping " + a).c_str());
    cin.get();
    cin.get();
}
void trace()
{
cout<<"\n     ***********  * * * *         *          * * * *  * * * * \n"
    <<"          *       *      *       * *        *         *       \n"
    <<"          *       *     *       *   *      *          *       \n"
    <<"          *       *    *       * --- *     *          * * * * \n"
    <<"          *       *     *     *       *    *          *       \n"
    <<"          *       *      *   *         *    *         *       \n"
    <<"          *       *      *  *           *    * * * *  * * * * \n\n"; 

    cout << "Ingrese la IP o URL: ";
    cin >> a;
    cout << "\n";
    system(("tracert " + a).c_str());
    cin.get();
    cin.get();
}   
//66.249.91.104






