
#include <iostream>
#include <cstdlib>

using namespace std;

class Clase
{
	public:
		// class constructor
		Clase(int i);
		// class destructor
		~Clase();
		// Funcion
		int Funcion();
		
	private:
        int indice;
};

Clase::Clase(int i)
{
    indice = 1000+i;
}

// class destructor
Clase::~Clase()
{
}

int Clase::Funcion()
{
    return indice;
}


int main(int argc, char *argv[])
{
    Clase **Clases = new Clase* [sizeof(Clase)];
    cout << "INICIA" << endl;

    for (int i = 0; i < 5; i++)
    {
        Clases[i] = new Clase(i);
        cout << Clases[i]->Funcion() << endl;
    }
        cout << Clases[3]->Funcion() << endl;
    
    cout << "TERMINA" << endl;
    
    for (int i = 0; i < 5; i++)
      delete[] Clases[i];
      delete Clases;
    
    system("PAUSE");
    return 0;
}
