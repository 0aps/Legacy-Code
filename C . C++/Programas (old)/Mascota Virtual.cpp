#include<iostream>
using namespace std;




int abr=4,hmb=3,lmp=7,mp,store,saldo_act=10000,pl,die=0,bath,ptj=0;






class juego
{ 
    
    public:
           
           void intro(); //Deluxe
           void empezar();
           void error();
           void hungry();
           void bore();
           void dirty();
           void feed();
           void play();
           void clean();
           void stadis();
           void finish();
           
           
           
};



//******************Introduccion al juego***************************



void juego::intro()
{
     
     juego j;
     
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                                  ";
    cout<<"LuX Incorporated inc Presents"<<endl; 
    
    system ("pause > nul");
    system ("cls");
    
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                                             ";
    cout<<"A KeY eSt Software";
    
    
    system ("pause > nul");
    system ("cls");
    
     
    cout<<"                      ";
    cout<<"************************************"<<endl;
    cout<<"                                 Mascota virtual"<<endl;
    cout<<"                      ";
    cout<<"************************************"<<endl<<endl<<endl;
    
    
    system ("pause > nul");
    system ("cls");
    
    
    cout<<"                      ";
    cout<<"************************************"<<endl;
    cout<<"                                 Mascota virtual"<<endl;
    cout<<"                      ";
    cout<<"************************************"<<endl<<endl<<endl<<endl;
    
    
    cout<<"Bienvenidos a este maravilloso juego";
    
    system ("pause > nul");
    system ("cls");
    
    cout<<"                      ";
    cout<<"************************************"<<endl;
    cout<<"                                 Mascota virtual"<<endl;
    cout<<"                      ";
    cout<<"************************************"<<endl<<endl<<endl<<endl;
    
    cout<<"Aprenderas todo lo necesario para ser un buen cuidador";
    
    system ("pause > nul");
    system ("cls");
    
    cout<<"                      ";
    cout<<"************************************"<<endl;
    cout<<"                                 Mascota virtual"<<endl;
    cout<<"                      ";
    cout<<"************************************"<<endl<<endl<<endl<<endl;
    
    cout<<"El juego es simple :";
    
    system ("pause > nul");
    system ("cls");
    
    cout<<"                      ";
    cout<<"************************************"<<endl;
    cout<<"                                 Mascota virtual"<<endl;
    cout<<"                      ";
    cout<<"************************************"<<endl<<endl<<endl<<endl;
    
    cout<<"1) Debes cuidar la mascota de tu amigo mientras el no esta";
    
    system ("pause > nul");
    system ("cls");
    
    cout<<"                      ";
    cout<<"************************************"<<endl;
    cout<<"                                 Mascota virtual"<<endl;
    cout<<"                      ";
    cout<<"************************************"<<endl<<endl<<endl<<endl;
    
    cout<<"2) Debes cuidarla, alimentarla, jugar con ella etc.";
    
    system ("pause > nul");
    system ("cls");
    
    cout<<"                      ";
    cout<<"************************************"<<endl;
    cout<<"                                 Mascota virtual"<<endl;
    cout<<"                      ";
    cout<<"************************************"<<endl<<endl<<endl<<endl;
    
    cout<<"Si se queja demasiado su dueno vendra y terminara el juego";
    
    system ("pause > nul");
    system ("cls");
    
    cout<<"                      ";
    cout<<"************************************"<<endl;
    cout<<"                                 Mascota virtual"<<endl;
    cout<<"                      ";
    cout<<"************************************"<<endl<<endl<<endl<<endl;
    
    cout<<"Estas listo?";
    
    system ("pause > nul");


    j.empezar();
    
    
    
    
}



//***********************Empieza el juego******************


void juego::empezar()
{
     system ("cls");
     
     juego j;
     
     
     
     
     
        for(int a=1;a<=100;a++)
    {
         
            system ("cls");
            
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;

            cout<<"                                    ";
            cout<<"Cargando "<<a<<"%"<<endl<<endl;
              
    }
     
     
    system ("cls");
    
    
    if (saldo_act<=0)
    saldo_act=0;
    
    if (die==5)
    {
    j.finish();
    system ("exit");
    }
     
     
     
     ptj+=450;
    
    

    cout<<"                      ";
    cout<<"************************************"<<endl;
    cout<<"                                 Mascota virtual"<<endl;
    cout<<"                      ";
    cout<<"************************************"<<endl<<endl<<endl;
    
    
    
  
     
     
     
     cout<<"Menu principal"<<endl<<endl<<endl;
     cout<<"1)Alimentarlo"<<endl;
     cout<<"2)Jugar con el"<<endl;
     cout<<"3)Limpiarlo"<<endl;
     cout<<"4)Estadisticas"<<endl;
     cout<<"5)Comprame algo"<<endl;
     cout<<endl<<"----} ";
     cin>>mp;
     
     
     if ((mp<1) &&(mp>5))
     j.error();
     
     
    //Condiciones principales
    abr--;
    if (abr<0)
    {abr=0;}
    if (abr==0)
    {

    j.bore();
    }
    
    hmb--;
    if (hmb<0)
    {hmb=0;}
    if (hmb==0)
    {

    j.hungry();
    }
    
    lmp--;
    if (lmp<0)
    {lmp=0;}
    if (lmp==0)
    {

    j.dirty();
    }
    
    
    //fin del juego
    if (die==10)
    j.finish();


     
     
     
     switch (mp)
     {
            
            case 1:j.feed();break;
            case 2:j.play();break;
            case 3:j.clean();break;
            default:j.error();break;
     }
     
     
     
     
     
     
     
     
}
     
     
     
     
//**********************Para los errores**************
     
     
void juego::error()
{
     system ("cls");
     juego j;
     cout<<"                      ";
     cout<<"************************************"<<endl;
     cout<<"                                 Mascota virtual"<<endl;
     cout<<"                      ";
     cout<<"************************************"<<endl<<endl<<endl<<endl;
     cout<<"Al parecer has cometido un error";
     system ("pause > nul");
     j.empezar();
     
}
    
    
    
//********************En caso de aburrimiento**************


    
void juego::bore()
{
     system ("cls");
     juego j;
     die++;
     cout<<"Estoy aburrido, has algo conmigo!";
     system ("pause > nul");
     j.play();
}
     
     
     
//*******************En caso de hambre*********************
     

void juego::hungry()
{
     system ("cls");
     juego j;
     die++;
     cout<<"Estoy hambriento, por favor alimentame rapido!";
     system ("pause > nul");
     j.feed();
}


//********************En caso de suciedad*******************


void juego::dirty()
{
     system ("cls");
     juego j;
     die++;
     cout<<"Me siento sucio, Baname!";
     system ("pause > nul");
     j.clean();
}
    


//*******************Alimentacion*****************************


void juego::feed()
{
     system ("cls");
     juego j;
     
     
     if (saldo_act<=0)
     {
     cout<<"Lo sentimos, tu cuenta es de $0"<<endl;
     saldo_act=0;
     system ("pause > nul");
     j.empezar();
     }
     
     
     
     cout<<"                      ";
     cout<<"************************************"<<endl;
     cout<<"                                 Mascota virtual"<<endl;
     cout<<"                      ";
     cout<<"************************************"<<endl<<endl<<endl<<endl;
     
     cout<<"1) Comprar"<<endl;
     cout<<"2) Ver saldo"<<endl<<endl;
     cout<<"---} ";
     cin>>store;
     if ((store!=1) && (store!=2))
     j.error();
     
     
     
     
     
     if (store==1)
     {
                  
     
     system ("cls");   
     
     
     if (saldo_act<1200)
     {
     cout<<"Lo sentimos, tu cuenta es demasiado baja"<<endl;
     system ("pause > nul");
     j.empezar();
     }
     
             
     cout<<"                      ";
     cout<<"************************************"<<endl;
     cout<<"                                 Mascota virtual"<<endl;
     cout<<"                      ";
     cout<<"************************************"<<endl<<endl<<endl<<endl;
     
     cout<<"Comida especial = $1200"<<endl;
     cout<<"Su saldo actual era de "<<saldo_act<<endl;
     cout<<"Con esta compra se reduce a "<<saldo_act-1200<<endl<<endl;
     saldo_act-=1200;
     cout<<"*Recuerda que debes conseguir dinero jugando";
     hmb+=3;
     
     system ("pause > nul");
     
     j.empezar();
     
     }
     
     
     if (store==2)
     {
          
     system ("cls");        
     cout<<"                      ";
     cout<<"************************************"<<endl;
     cout<<"                                 Mascota virtual"<<endl;
     cout<<"                      ";
     cout<<"************************************"<<endl<<endl<<endl<<endl;
     
     cout<<"Saldo actual = $"<<saldo_act<<endl;
     cout<<"*Recuerda que debes conseguir dinero jugando";  
     system ("pause > nul");
        
           
     j.empezar();
     
     }
     
     
     
     }
     


void juego::play()
{
     system ("cls");
     juego j;
     
     
     cout<<"                      ";
     cout<<"************************************"<<endl;
     cout<<"                                 Mascota virtual"<<endl;
     cout<<"                      ";
     cout<<"************************************"<<endl<<endl<<endl<<endl;
     
     
     cout<<"1)Adivina el numero ($500)"<<endl;
     cout<<"2)Juegate a la suerte ($300)"<<endl<<endl;
     cout<<"---} ";
     cin>>pl;
     
     abr+=3;
     
     if (pl==1)
     {
               
     if (saldo_act<500)
     {
     cout<<"Lo sentimos, tu cuenta es demasiado baja"<<endl;
     system ("pause > nul");
     j.empezar();
     }          
     
     cout<<"Jugando . . ."<<endl;
     system ("pause > nul");
     saldo_act+=500;
     j.empezar();
     }

     if (pl==2)
     {
               
        if (saldo_act<300)
     {
     cout<<"Lo sentimos, tu cuenta es demasiado baja"<<endl;
     system ("pause > nul");
     j.empezar();
     } 
     
     cout<<"Jugando . . ."<<endl;
     system ("pause > nul");
     saldo_act+=300;
     j.empezar();
     }
     
     if ((pl!=1) && (pl!=2))
     j.error();
     
     
     
      
        
                 
}
     
     
     

void juego::clean()
{
     system ("cls");
     juego j;
     
     
     cout<<"                      ";
     cout<<"************************************"<<endl;
     cout<<"                                 Mascota virtual"<<endl;
     cout<<"                      ";
     cout<<"************************************"<<endl<<endl<<endl<<endl;
     
     
     cout<<"1)Tomar un bano ($500)"<<endl;
     cout<<"2)Ver saldo"<<endl<<endl;
     cout<<"---}";
     cin>>bath;
     lmp+=3;
     
     if (bath==1)
     {
               
     if (saldo_act<500)
     {
     cout<<"Lo sentimos, tu cuenta es demasiado baja"<<endl;
     system ("pause > nul");
     j.empezar();
     }           
     
     cout<<"Banando . . ."<<endl;
     system ("pause > nul");
     saldo_act-=500;
     j.empezar();
     }

     if (bath==2)
     {
     system ("cls");        
     cout<<"                      ";
     cout<<"************************************"<<endl;
     cout<<"                                 Mascota virtual"<<endl;
     cout<<"                      ";
     cout<<"************************************"<<endl<<endl<<endl<<endl;
     
     cout<<"Saldo actual = $"<<saldo_act<<endl;
     cout<<"*Recuerda que debes conseguir dinero jugando";  
     system ("pause > nul");
        
           
     j.empezar();
     }
     
     if ((bath!=1) && (bath!=2))
     j.error();
     
     
     
     system ("pause > nul");
     
     j.empezar();
     

     
}



void juego::finish()
{
     system ("cls");
     juego j;
     
     
     cout<<"                      ";
     cout<<"************************************"<<endl;
     cout<<"                                 Mascota virtual"<<endl;
     cout<<"                      ";
     cout<<"************************************"<<endl<<endl<<endl<<endl;
     
     
     cout<<"Lo sentimos, tu mascota se quejo demasiado"<<endl<<endl;
     cout<<"Puntaje final : "<<ptj<<" puntos";
     
     system ("pause > nul ");
     

     

     
     
}
     







//***************Obligatorio**************************

int main()
{
    juego j;
    
    
    system ("color f1");
    system ("title KeY eSt   -   Mascota virtual");
    
    
    j.intro();
    
    return 0;
    
}
