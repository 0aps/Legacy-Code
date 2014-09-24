#include <stdio.h>
#include <windows.h>

int main()
{
    char cadena[2][15];
    strcpy(cadena[0],"C:\\hola.txt");
    strcpy(cadena[1],"C:\\WINDOWS");
    
    int x=0;
    WIN32_FIND_DATA findFileData;
    
    for(; x < 2; x++)
    {
    FindFirstFile(cadena[x], &findFileData);
    
    if(findFileData.dwFileAttributes  == FILE_ATTRIBUTE_DIRECTORY)
     printf("directorio - %d\n", x);
    
    if(findFileData.dwFileAttributes == FILE_ATTRIBUTE_ARCHIVE)
     printf("archivo - %d\n", x);
     }
     
     getchar();
     return 0;
} 
