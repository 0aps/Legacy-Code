#include <windows.h> //Some of you may never get this far.
#include <iostream>

int main()
{
     std::cout << "Enter the name of a file: ";
     char szFileName[32];
     std::cin.getline(szFileName, 32);
     char szFilePath[256];
     GetCurrentDirectory(256, szFilePath); //Gets the path of the application, notes below.
     strcat(szFilePath, "\\");
     strcat(szFilePath, szFileName);
     if (GetFileAttributes(szFilePath) == INVALID_FILE_ATTRIBUTES)
          std::cout << "Error:  Cannot find " << szFileName << std::endl;
          else
          std::cout << "\t\tEncontrado!\n";
     std::cout << "Press the ENTER key to exit..." << std::endl;
     std::getchar();
     return EXIT_SUCCESS;
     /* When you debug build in MSVC++, the application path will be C:\\Owner's Documents\\Visual Studios 2008\\Projects\\__PROJECT__\\__PROJECT__

     I didn;t bother explaining this because I know if you need me to explain it, you will probably never get it, and if you don't need me to explain it, you already got it.*/
}
