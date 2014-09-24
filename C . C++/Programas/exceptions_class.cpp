// Demostración: try, throw y catch
 
#include <iostream>
#include <cmath>
 
using namespace std;
 
static const int EDOMINIO=100;
static const int ERANGO=101;
 
class ErrorMat
{
public:
    ErrorMat() : motivo(0) {};
    ErrorMat(int m) : motivo(m) {};
    const char* porque() const throw();
 
private:
    int motivo;
};
 
const char* ErrorMat::porque() const throw()
{
    switch (motivo)
    {
    case EDOMINIO: return "Error de Dominio ";break;
    case ERANGO:   return "Error de Rango ";break;
    default:       return "Error Desconocido";  //En rigor no debería ocurrir
    }   
}
 
double logaritmo(const double n)
{
    try {
        if (n < 0) throw(ErrorMat(EDOMINIO) );
        if (n == 0) throw(ErrorMat(ERANGO) );
        return log(n);
        }
    catch(ErrorMat& e) {
        cout << e.porque();
    }
    return 0;
}
 
int main()
{
    double r = 100;
    cout << "log(" << r << ") = " << logaritmo(r) << endl;
    cout << "log(-" << r << ") = " << logaritmo(-r) << endl;
    cin.get();
    return 0;
}
