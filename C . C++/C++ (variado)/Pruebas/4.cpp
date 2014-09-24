#include <iostream>
using namespace std;

int main(int argc, char *argv)
{
    int n[7], i;
    for(i=0; i<=6; i++)
    {
        cout << "Number " << i+1 << ": ";
        cin >> n[i];
    }
    double h = (n[0]+n[1]+n[2]+n[3]+n[4]+n[5]+n[6])/7.0;
    cout << "Average: " << h;
    setbuf(stdin, NULL);
    cin.get();
    return 0;
}

/*

int media=0;
for(i=0; i<4; i++) media+=notas[i];
media/=4;
printf("La media es %i", media);

*/

