#include <iostream>
#include <string>

using namespace std;

struct Fecha
{
    int dia;
    string mes;
};

int main()
{
    int n;
    cin >> n;

    Fecha fechas[n];
    for (int i=0;i<n;i++)
    {
        string basura;
        cin >> fechas[i].dia >> basura >> fechas[i].mes;
    }
    for (int i=0;i<n;i++)
    {
        if (fechas[i].mes=="enero")
        {
            if (fechas[i].dia==31) cout << "1 de febrero" << endl;
            else cout << ++fechas[i].dia << " de " << fechas[i].mes << endl;
        }
        else if (fechas[i].mes=="febrero")
        {
            if (fechas[i].dia==28) cout << "1 de marzo" << endl;
            else cout << ++fechas[i].dia << " de " << fechas[i].mes << endl;
        }
        else if (fechas[i].mes=="marzo")
        {
            if (fechas[i].dia==31) cout << "1 de abril" << endl;
            else cout << ++fechas[i].dia << " de " << fechas[i].mes << endl;
        }
        else if (fechas[i].mes=="abril")
        {
            if (fechas[i].dia==30) cout << "1 de mayo" << endl;
            else cout << ++fechas[i].dia << " de " << fechas[i].mes << endl;
        }
        else if (fechas[i].mes=="mayo")
        {
            if (fechas[i].dia==31) cout << "1 de junio" << endl;
            else cout << ++fechas[i].dia << " de " << fechas[i].mes << endl;
        }
        else if (fechas[i].mes=="junio")
        {
            if (fechas[i].dia==30) cout << "1 de julio" << endl;
            else cout << ++fechas[i].dia << " de " << fechas[i].mes << endl;
        }
        else if (fechas[i].mes=="julio")
        {
            if (fechas[i].dia==31) cout << "1 de agosto" << endl;
            else cout << ++fechas[i].dia << " de " << fechas[i].mes << endl;
        }
        else if (fechas[i].mes=="agosto")
        {
            if (fechas[i].dia==31) cout << "1 de septiembre" << endl;
            else cout << ++fechas[i].dia << " de " << fechas[i].mes << endl;
        }
        else if (fechas[i].mes=="septiembre")
        {
            if (fechas[i].dia==30) cout << "1 de octubre" << endl;
            else cout << ++fechas[i].dia << " de " << fechas[i].mes << endl;
        }
        else if (fechas[i].mes=="octubre")
        {
            if (fechas[i].dia==31) cout << "1 de noviembre" << endl;
            else cout << ++fechas[i].dia << " de " << fechas[i].mes << endl;
        }
        else if (fechas[i].mes=="noviembre")
        {
            if (fechas[i].dia==30) cout << "1 de diciembre" << endl;
            else cout << ++fechas[i].dia << " de " << fechas[i].mes << endl;
        }
        else if (fechas[i].mes=="diciembre")
        {
            if (fechas[i].dia==31) cout << "1 de enero" << endl;
            else cout << ++fechas[i].dia << " de " << fechas[i].mes << endl;
        }
    }
}
