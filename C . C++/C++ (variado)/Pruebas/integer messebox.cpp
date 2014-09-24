#include <iostream>
#include <windows.h>

 int main()
{
	int x;
	char buffer[20];

	std::cout<<"How old are you? "<<std::endl;
	std::cin>>x;
	itoa(x,buffer,10);
	MessageBox(NULL,buffer,"your age",MB_OK|MB_ICONINFORMATION);
	 
	return 0;
	}
