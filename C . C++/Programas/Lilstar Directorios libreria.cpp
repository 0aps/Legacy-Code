
#include <stdio.h> 
#include <dirent.h> 

int main()
{
  DIR           *d;
  struct dirent *dir;
  d = opendir("C:\\");
  if (d)
  {
    while ( (dir = readdir(d)) )
    {
          printf("%s\n", dir->d_name);
    }
    closedir(d);
  }
  getchar();
  return 0;
}

