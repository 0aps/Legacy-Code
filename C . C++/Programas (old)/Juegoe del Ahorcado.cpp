#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>

#define USADO 1
#define LIBRE 0

//   J U E G O             E L    A H O R C A D O  (por GRIB JR.)


int MostrarPozo(char* Cadena, int N)
{    
     int i, asd=0;
     printf("\n\n\n\n\tPozo:\n\t");
     textcolor( BLUE );
     for(i=0;i<N;i++)
     {
     if(Cadena[i]!= ' ')
     printf("%c ", Cadena[i]);
     else
     asd++;        
     }
     textcolor( BLACK );
     
}
void MostrarAutor()
     {
     gotoxy(1,24);
     textcolor( LIGHTGRAY );
     printf("\t\t\t\t\t\t\t       Por Grib Jr");
     textcolor( BLACK );            
     }
                                                                            
int MostrarAhorcado(int Vida)                                               //   ____ 
{                                                                           //  |   o
     char PV= 179, PC= 218, PH= 196, PT= 194;                               //  |  /|\
                                                                            //  |  / \
     
     textcolor( LIGHTBLUE );
     if(Vida==10)
     { /* COLOR              ESCRITO              COLOR 2          ESCRITO 2 */    
     textcolor( RED ); printf("\n\n\n\t%c%c%c%c\n", PC,PH,PH,PT); textcolor( LIGHTBLUE );
     textcolor( RED ); printf("\t%c",PV); textcolor( LIGHTBLUE ); printf("  o\n");
     textcolor( RED ); printf("\t%c",PV); textcolor( LIGHTBLUE ); printf(" /%c\\\n", PV);
     textcolor( RED ); printf("\t%c",PV); textcolor( LIGHTBLUE ); printf(" / "); textcolor( RED ); printf("\\\n"); textcolor( LIGHTBLUE );
     textcolor( RED ); printf("\t%c",PV); textcolor( LIGHTBLUE );    
     }
     if(Vida==9)
     {
     textcolor( RED ); printf("\n\n\n\t%c%c%c%c\n", PC,PH,PH,PT); textcolor( LIGHTBLUE );
     textcolor( RED ); printf("\t%c",PV); textcolor( LIGHTBLUE ); printf("  o\n");
     textcolor( RED ); printf("\t%c",PV); textcolor( LIGHTBLUE ); printf(" /%c\\\n", PV);
     textcolor( RED ); printf("\t%c",PV); textcolor( LIGHTBLUE ); textcolor( RED ); printf(" / \\\n"); textcolor( LIGHTBLUE );
     textcolor( RED ); printf("\t%c",PV); textcolor( LIGHTBLUE ); 
     }
     if(Vida==8)
     {
     textcolor( RED ); printf("\n\n\n\t%c%c%c%c\n", PC,PH,PH,PT); textcolor( LIGHTBLUE );
     textcolor( RED ); printf("\t%c",PV); textcolor( LIGHTBLUE ); printf("  o\n");
     textcolor( RED ); printf("\t%c",PV); textcolor( LIGHTBLUE ); printf(" /%c", PV); textcolor( RED ); printf("\\\n"); textcolor( LIGHTBLUE );
     textcolor( RED ); printf("\t%c",PV); textcolor( LIGHTBLUE ); textcolor( RED ); printf(" / \\\n"); textcolor( LIGHTBLUE );
     textcolor( RED ); printf("\t%c",PV); textcolor( LIGHTBLUE );
     }
     if(Vida==7)
     {
     textcolor( RED ); printf("\n\n\n\t%c%c%c%c\n", PC,PH,PH,PT); textcolor( LIGHTBLUE );
     textcolor( RED ); printf("\t%c",PV); textcolor( LIGHTBLUE ); printf("  o\n");
     textcolor( RED ); printf("\t%c",PV); printf(" /", PV); textcolor( LIGHTBLUE ); printf("%c", PV) ;textcolor( RED ); printf("\\\n"); textcolor( LIGHTBLUE );
     textcolor( RED ); printf("\t%c",PV); textcolor( LIGHTBLUE ); textcolor( RED ); printf(" / \\\n"); textcolor( LIGHTBLUE );
     textcolor( RED ); printf("\t%c",PV); textcolor( LIGHTBLUE );
     }
     if(Vida==6)
     {
     textcolor( RED ); printf("\n\n\n\t%c%c%c%c\n", PC,PH,PH,PT); textcolor( LIGHTBLUE );
     textcolor( RED ); printf("\t%c",PV); textcolor( LIGHTBLUE ); printf("  o\n");
     textcolor( RED ); printf("\t%c",PV); printf(" /%c\\\n", PV); textcolor( LIGHTBLUE );
     textcolor( RED ); printf("\t%c",PV); textcolor( LIGHTBLUE ); textcolor( RED ); printf(" / \\\n"); textcolor( LIGHTBLUE );
     textcolor( RED ); printf("\t%c",PV); textcolor( LIGHTBLUE );
     }
     if(Vida==11)                                                           
     {
     textcolor( RED ); printf("\n\n\n\t%c%c%c%c\n", PC,PH,PH,PT); textcolor( LIGHTBLUE );
     textcolor( RED ); printf("\t%c",PV); textcolor( LIGHTBLUE ); printf("  o\n");
     textcolor( RED ); printf("\t%c",PV); textcolor( LIGHTBLUE ); printf(" /%c\\\n", PV);
     textcolor( RED ); printf("\t%c",PV); textcolor( LIGHTBLUE ); printf(" / \\\n"); textcolor( LIGHTBLUE );
     textcolor( RED ); printf("\t%c",PV); textcolor( LIGHTBLUE ); 
     }    
     textcolor( RED );
     if(Vida==4)
     {
     printf("\n\n\n\t%c%c%c%c\n", PC,PH,PH,PT);
     printf("\t%c  o\n", PV);
     printf("\t%c /%c\\\n", PV, PV);
     printf("\t%c /\n", PV);
     printf("\t%c", PV);   
     }
     if(Vida==3)
     {
     printf("\n\n\n\t%c%c%c%c\n", PC,PH,PH,PT);
     printf("\t%c  o\n", PV);
     printf("\t%c /%c\\\n", PV, PV);
     printf("\t%c\n", PV);
     printf("\t%c", PV);
     }
     if(Vida==2)
     {
     printf("\n\n\n\t%c%c%c%c\n", PC,PH,PH,PT);
     printf("\t%c  o\n", PV);
     printf("\t%c /%c\n", PV, PV);
     printf("\t%c\n", PV);
     printf("\t%c", PV);
     }
     if(Vida==1)
     {
     printf("\n\n\n\t%c%c%c%c\n", PC,PH,PH,PT);
     printf("\t%c  o\n", PV);
     printf("\t%c  %c\n", PV, PV);
     printf("\t%c\n", PV);
     printf("\t%c", PV);
     }
     if(Vida<=0)
     {
     printf("\n\n\n\t%c%c%c%c\n", PC,PH,PH,PT);
     printf("\t%c  o\n", PV);
     printf("\t%c\n", PV, PV);
     printf("\t%c\n", PV);
     printf("\t%c ", PV);
     }
     if(Vida==5)                                                           
     {
     printf("\n\n\n\t%c%c%c%c\n", PC,PH,PH,PT);
     printf("\t%c  o\n", PV);
     printf("\t%c /%c\\\n", PV, PV);
     printf("\t%c / \\\n", PV);
     printf("\t%c", PV);
     }
     if(Vida<=-1)
     {return 1;}
     
     return 0;
                                                 
}


//                                  I N I C I O    M A I N 
int main()
{   
    int Points=0,WLIFE=1200,GaOv=0;
    START:
    if(GaOv==1)
    {    
    Points=0;
    WLIFE=1200;
    GaOv=0;
    }
    char Palabras[100][14]=
{   "lechugas     ", "chocapic     ", "alimento     ", "acoplado     ", "auxiliar     ", //1
    "avaricia     ", "langosta     ", "soldados     ", "monarcas     ", "maldecir     ", //2
    "motociclista ", "movilizacion ", "santificador ", "ejercitacion ", "incapasitado ", //3
    "laboriosidad ", "legalizacion ", "nacionalidad ", "calculatorio ", "cardiografia ", //4
    "besuqueadora ", "bibliografia ", "comer        ", "aparente     ", "fechoria     ", //5
    "bienhaciente ", "bienviviente ", "billaristico ", "bizantinismo ", "orientar     ", //6
    "cebolla      ", "repollo      ", "carne        ", "aminoacidos  ", "sopaipilla   ", //7
    "citofono     ", "manguera     ", "vacuno       ", "television   ", "basura       ", //8
    "antipatico   ", "animal       ", "elefante     ", "dinosaurio   ", "programar    ", //9
    "ahorcado     ", "queso        ", "tomate       ", "vacaciones   ", "amistad      ", //10
    "estupidez    ", "verde        ", "amarillo     ", "pelicano     ", "enigma       ", //11
    "aleacion     ", "patogenico   ", "huevon       ", "emparedado   ", "ortografia   ", //12
    "marihuana    ", "bebida       ", "idiolatria   ", "carabinero   ", "hormiga      ", //13
    "Array        ", "Retorno      ", "Herida       ", "ventana      ", "cuchara      ", //14
    "ganador      ", "protector    ", "contorno     ", "ayudenme     ", "tararear     ", //15
    "lombriz      ", "misil        ", "Silo         ", "nuclear      ", "radioactivo  ", //16
    "teclado      ", "empanada     ", "pepino       ", "austral      ", "poderoso     ", //17
    "elogiar      ", "estampilla   ", "analogo      ", "control      ", "consola      ", //18
    "mensaje      ", "modificar    ", "lineas       ", "insertar     ", "compilador   ", //19
    "resultado    ", "depurar      ", "observar     ", "pulsera      ", "religion     "};//20
                           
    // SE PUEDE IR AGRANDANDO PERO POR AHORA LO DEJARE ASI, OTRO DIA LO AGRANDARE
    
    int Comprobar[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0 };        
    char Palabra[14]="_____________", Guionbajo[14] = "_____________";
    char Al_Agua[30]="                             ", letra, AA;
    int Array, i, Vida, Retorno, A, Herida, auxiliar, o=0;
    
    system("color f0");
    _setcursortype(_NOCURSOR);
    srand(GetTickCount());
    Array = rand()%100; 
    for(i=0;i<14;i++)
    if(Palabras[Array][i]!=' ')
    Palabra[i]=Palabras[Array][i];
    if(Vida <= 5||Vida>=12)
    Vida=5;
    
    A=0; Herida=0;
    
    HERE: //////////////////////////
    textcolor( RED );
    printf("\n\t\t   \"El Ahorcado\"\t\t\t\t");
    textcolor( BLACK );
    printf("Puntaje: ");
    textcolor( BLUE );
    printf("%i", Points);
    textcolor( LIGHTBLUE);
    Retorno = MostrarAhorcado(Vida);
    textcolor( BLACK );
    gotoxy(20,8);
    for(i=0;i<=13;i++)
    {
    
    Palabra[i] = toupper(Palabra[i]);
    if(Palabra[i]!= '_')
    {
    printf("%c ", Guionbajo[i]);
}

    }
    MostrarPozo(Al_Agua,A);
    if(Retorno==1)
    {
    system("cls");          
    textcolor( RED );
    printf("\n\n\tLo siento, el Ahorcado ha muerto...\n\tLa Palabra era ");
    GaOv=1;
    i=0;
    while(Palabra[i]!='_')
    {    
    printf("%c", Palabra[i]);    
    i++;
    }
    printf("\n\n\tTeclee ENTER para volver a jugar...");
    system("pause>NULL");
    system("cls");
    goto START;
    }
    if(0 == strcmp(Palabra,Guionbajo))
    {    
         Points+=100;
         textcolor ( GREEN );
         printf("\n\n Felicitaciones, el Ahorcado ha sobrevivido!!");
         if(Vida==5||Vida==11)
         {
         textcolor( LIGHTGREEN);
         printf("\n Y ha salido ileso!! +500 puntos!!");
         o=1;
         }
         if(Points>=WLIFE && Vida<=5)
         {
         auxiliar=0;
         textcolor( BLUE);
         printf("\n\n Tienes mas de %i puntos, por lo que has ganado:\n   ...", WLIFE);
         _sleep(4000);
         for(i=0;i<=51;i++)
         {
         gotoxy(1,19);
         if(auxiliar==0) 
         {
         textbackground (LIGHTBLUE);
         textcolor( WHITE);
         auxiliar=1;
         }
         else
         {
         textbackground (WHITE);
         textcolor( LIGHTBLUE );
         auxiliar=0;
         }
         printf(" -Un Ahorcado con doble vida !!");
         _sleep(60);
         }
         WLIFE+=1800;
         Vida=11;
         
         }         
         if(o==1)
         {
         Points+=500;
         o=0;
         }
         textcolor( GREEN);         
         
    printf("\n\n     Teclee ENTER para continuar...");
    system("pause>NULL");
    system("cls");
    goto START;
    }
    MostrarAutor();
    gotoxy(10,12);
    printf("\n\n\n\tIngrese Letra: ");
    scanf("%s", &AA);
    
    AA = toupper(AA);
    Herida=15;
    
    for(i=0;i<30;i++)
    {
    Al_Agua[A]=AA;
    
    if(AA==Al_Agua[i] && i!=A)
    {
    AA=' ';
    }
    Al_Agua[A]=AA;
    }
    
    if(AA==' ')
    Vida++;
    
    for(i=0;i<=14;i++)
    {        
    if(AA==Palabra[i])
      {      
      if(Comprobar[i]==LIBRE)
      {       
      Guionbajo[i] = Palabra[i];
      Points+=20;
      Comprobar[i] = USADO;
      }
            
      }
    else
      {
      Herida--;
      }
    if(Herida==0)
    {
    Vida--;
    }
}
    A++;
    system("cls");
    goto HERE;
    getch();
    
    
    
}                        
