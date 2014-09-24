//semi-CALCULADORA por .::BLaCKHoLE::.

#include <iostream>

float esto=(1,2,3,4,5,6,7,8,9,0);
float esto1=(1,2,3,4,5,6,7,8,9,0);
using namespace std;

int main()
{ 
    system ("TITLE  semi-CALCULADORA  BY:   .::BLacKHoLE::.");
    system("COLOR B");
 cout<<"                       semi-CALCULADORA BY: .::BLacKHoLE::."<<endl<<endl<<endl;
 cout<<"                          ========================="<<endl;
 cout<<"                          [  introduce un numero  ]"<<endl;
 cout<<"                          ========================="<<endl;
 cout<<"PRIMER NUMERO:"<<endl;   
 cin>>esto;
     if (esto)  
    {                   
       cout<<"SEGUNDO NUMERO:"<<endl; 
    cin>>esto1;
  if (esto1)
  {
    system("color A");     
 cout<<"                          sumando: "<<esto<<"+"<<esto1<<" = ("<<esto+esto1<<")"<<endl<<endl;
 cout<<"                          multiplicando: "<< esto<<"x"<<esto1<<" = ("<<esto*esto1<<")"<<endl<<endl;
 cout<<"                          restando: "<<esto<<"-"<<esto1<<" = ("<<esto-esto1<<")"<<endl<<endl;
 cout<<"                          dividiendo: "<<esto<<"/"<<esto1<<" = ("<<esto/esto1<<")"<<endl<<endl; 
    
system("PAUSE");
 system("cls");
exit(0);
} 
 }

 else 
system("cls");
 system("color c");
 cout<<endl<<endl<<endl; 
 cout<<"                            ERROR AL INGRESAR EL NUMERO!!!\a"<<endl<<endl<<endl<<endl;
 cout<<"                          ================================="<<endl;
 cout<<"                          [  INTRODUCE UN NUMERO VALIDO:  ]"<<endl;
 cout<<"                          ================================="<<endl<<endl;

cin.get();


system ("PAUSE");
return 0;

}
