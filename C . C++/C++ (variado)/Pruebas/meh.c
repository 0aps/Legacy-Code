     #include<stdio.h>

    int main()
    {
    //Promagra para deterinar el ganador entre dos partidos
    int PRD,PLD, lec,i;
    for(i= PRD = PLD = 0; i<3; i++)
    {
    printf("Provincia #%d: ", i+1);
    printf("\n Votos PRD: ");
    scanf("%d", &lec);
    PRD+=lec;
    printf("Votos PLD: ");
    scanf("%d", &lec);
    PLD+=lec;
    }
    if(PLD > PRD)
    printf("Ganó el PLD las elecciones. ");
    else if( PRD > PLD)
    printf("Ganó el PRD las elecciones");
    else
    printf("Empate.");

    return 0;
    }
