#include <stdio.h>
#include <string.h>
#define MAX 1000


void imprStatus(char admin[],char adress[],char port[],char user[])
{
	printf("[admin]==>%s\n",admin);
	printf("[adress]=>%s\n",adress);
	printf("[port]===>%s\n",port);
	printf("[user]===>%s\n\n\n",user);
}

int main(int CantKey,char *PtrCharVec[])
{

	int i = 1;

	char admin[MAX]={"admin"},adress[MAX]={"127.0.0.1"},port[MAX]={"22"},user[MAX]={"user"};
	imprStatus(admin,adress,port,user);
    
    if(CantKey <= 8 )
   	{
    printf("Introde los parametros, salindo . . .");
    return 1;
    }

	while(i<=8)
    {
		
        if(!strncmp(PtrCharVec[i],"-adress", MAX) )
        {
                strncpy(adress,PtrCharVec[i+1], MAX);
		
		}
 		else if(!strncmp(PtrCharVec[i],"-port", MAX))
        {
             
                   	strncpy(port,PtrCharVec[i+1], MAX);
		}
		else if(!strncmp(PtrCharVec[i],"-admin", MAX))
        {
					
                    strncpy(admin,PtrCharVec[i+1], MAX);
		}
		else if(!strncmp(PtrCharVec[i],"-user", MAX))
         {
                                    
            strncpy(user,PtrCharVec[i+1], MAX);
		}
		
		
        i++;
        
        
	}
    
    imprStatus(admin,adress,port,user);
	
    getchar();
    return 0;
}
