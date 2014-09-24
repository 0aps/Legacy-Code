#include <iostream>
#include <windows.h>

using namespace std;

int main()
{

    int a = 3;
    int p(a+2+2), q(2*a+1+2+2+2);
    int **plantilla = new int*[p];

        for(int i=0; i< p; i++)
                plantilla[i] = new int[q];

    for(int i=0; i <p; i++)
        for(int j=0; j < q; j++)
                {
                 plantilla[i][j] = 0;
                }

        //linea horizontal superior
    for(int i=0; i < q; i++)
            plantilla[0][i] = 220;

    //linea horizontal inferior
    for(int i=0; i < q; i++)
            plantilla[p-1][i] = 220;

    //linea vertical izquierda
    for(int i=0; i < p; i++)
            plantilla[i][0] = 220;

    //linea vertical derecha
    for(int i=0; i < p; i++)
            plantilla[i][q-1] = 220;

    //lineas verticales paralelas
    for(int i=2; i<=a+1; i++)
                for(int j=4; j< q-5; j+=2)
                    plantilla[i][j] = 284;

  for(int i=0; i <p; i++)
        {
            for(int j=0; j < q; j++)
            {
                if(plantilla[i][j] == 220)
                    cout << "#";
                else if(plantilla[i][j] == 284)
                    cout << "|";
                else
                    cout << " ";
            }
            cout << endl;
        }

    while(1)
    if(GetAsyncKeyState(VK_DOWN) && GetAsyncKeyState(VK_LEFT))
    {
        cout << endl << "se presionaron ambas teclas" << endl;

    }

    //cout << plantilla[1][1];


    cin.get();
    return 0;
}
