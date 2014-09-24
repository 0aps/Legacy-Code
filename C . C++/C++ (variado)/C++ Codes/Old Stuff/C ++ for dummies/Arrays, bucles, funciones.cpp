// ArrayDemo - demonstrate the use of arrays 
// by reading a sequence of integers 
// and then displaying them in order 
#include <cstdio> 
#include <cstdlib> 
#include <iostream> 
using namespace std; 
// prototype declarations 
int sumArray(int integerArray[], int sizeOfArray); 
void displayArray(int integerArray[], int sizeOfFloatArray); 
int main(int nNumberofArgs, char* pszArgs[]) 
{ 
// input the loop count 
int nAccumulator = 0; 
cout << "This program sums values entered " 
<< "by the user\n"; 
cout << "Terminate the loop by entering "
<< "a negative number\n"; 
cout << endl; 
// store numbers into an array 
int inputValues[128]; 
int numberOfValues; 
for(numberOfValues = 0; 
numberOfValues < 128; 
numberOfValues++) 
{ 
// fetch another number 
int integerValue; 
cout << "Enter next number: "; 
cin >> integerValue; 
// if it’s negative... 
if (integerValue < 0)
{ 
// ...then exit 
break; 
} 
// ... otherwise store the number 
// into the storage array 
inputValues[numberOfValues] = integerValue; 
} 
// now output the values and the sum of the values 
displayArray(inputValues, numberOfValues); 
cout << "The sum is " 
<< sumArray(inputValues, numberOfValues) 
<< endl; 
// wait until user is ready before terminating program 
// to allow the user to see the program results 
system("PAUSE"); 
return 0; 
} 
// displayArray - display the members of an 
// array of length sizeOfloatArray 
void displayArray(int integerArray[], int sizeOfArray) 
{ 
cout << "The value of the array is:" << endl; 
for (int i = 0; i < sizeOfArray; i++) 
{ 
cout.width(3); 
cout << i << ": " << integerArray[i] << endl; 
} 
cout << endl; 
} 
// sumArray - return the sum of the members of an 
// integer array 
int sumArray(int integerArray[], int sizeOfArray) 
{ 
int accumulator = 0; 
for (int i = 0; i < sizeOfArray; i++) 
{ 
accumulator += integerArray[i]; 
} 
return accumulator; 
}
