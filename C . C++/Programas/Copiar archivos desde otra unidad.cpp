#include <windows.h>
#include <dirent.h> 
#include <iostream>

using namespace std;

int main(void)
{
  DIR           *d;
  struct dirent *dir;
  d = opendir("D:\\");

  
  char dir1[FILENAME_MAX] = "Dz:\\";
  char dir2[FILENAME_MAX] = "C:\\Datos\\";
  
  for(int i; (dir = readdir(d)) != NULL; i++)
  {
  strcat(dir1, dir->d_name);
  strcat(dir2, dir->d_name);
  Sleep(10);
  //cout << dir1 << '\n';
  //cout << dir2 << '\n';
   if (CopyFile(dir1, dir2, FALSE)==1)
    {
        cout << dir1 << "\t\t Se copio\n";
    }
    else 
    {   
        cout << dir1 << "\t\t No se copio\n";
    } 
    
  strcpy( dir1,   "D:\\" );
  strcpy( dir2,   "C:\\Datos\\" );
}
   
 
 
  closedir(d);
  cin.get();
  return(0);
}

