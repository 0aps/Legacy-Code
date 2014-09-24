 #include <iostream> // << >>
 #include <windows.h>
 using namespace std;

  int main(int argc, char* argv[])
{ // Si se pone esto devuelve a A2.   
 // Si no se pone esto devuelve a A1. 
    cout.setf(cout.boolalpha); 
int a;                                                //--------------//
                                                        //   A1       //
cout << "Entre el valor de a: ";                       // 1 = True    //
cin >> a;                                              // 0 = False  //
                                                       //-----------//
int b;
cout << "Entre el valor de b: ";                       //--------------//
cin >> b;                                              //     A2        //
                                                       //    True      //
bool c;                                                //    False     //
c = a == b;                                            //---------------//

cout << "El valor de a es " << a
     << "\nEl Valor de b es " << b
     << "\nEstos dos valores son iguales? ";// << c;
     if(c == true)
     cout << "Si."; else cout << "No.";
     setbuf(stdin, NULL);
      cin.get();
return 0;
}
