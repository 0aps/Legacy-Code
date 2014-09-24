#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i=0, x=0 , *buffer;
	buffer = (int *)malloc(30);
	
	while(i != 42 && i < 100 && i > -100)
	{
		scanf("%i", &i );
	
    	x++;
		*buffer = i;
		buffer++;
	
	    printf("%i - %i - %p - %i\n", x, i , buffer, (int)buffer);
	    getchar();
	
    };
	
	for(i=0,buffer-=x; i != x; i++) printf("%i", *buffer);		

	return 0;
}
