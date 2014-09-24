#include <iostream>
#include <string> // For the 'opperation' variable.
using namespace std;

class calculator {
private:
	int x, y; // Reserved for opperations
public:
	double addition (double a, double b);
	double subtraction (double a, double b);
	double multiplication (double a, double b);
	double division (double a, double b);
	int modulus (int a, int b);
};
// Define the class functions:
double calculator::addition (double a, double b) {
	double sum = a + b;
	cout << a << " + " << b << " = " << sum;
	return sum;
}

double calculator::subtraction (double a, double b) {
	double sum = a - b;
	cout << a << " - " << b << " = " << sum;
	return sum;
}

double calculator::multiplication (double a, double b) {
	double sum = a * b;
	cout << a << " x " << b << " = " << sum;
	return sum;
}

double calculator::division (double a, double b) {
	try {
		if (a == 0 || b == 0) {
			throw 1;
		}
	
	}
	catch (int a){
		cout << "You can not divide by zero!" << endl;
		return 1;
	}
	double sum = a / b;
	cout << a << " / " << b << " = " << sum;
	return sum;
}

int calculator::modulus (int a, int b) {
	int sum = (a % b);
	cout << a << " (Remainder) " << b << " = " << sum;
	return sum;
}

int main () { 

	cout << endl;
	double num1,num2;
	int num3,num4;
	calculator user;
	string opperation;
	cout << "What opperation would you like to perform (from the list below)?";
	cout << endl << "1.) Addition\n2.) Subtraction\n3.) Multiplication\n4.) Division\n5.) Modulus\n";
	cout << "Opperation variable is case sensative! Check spelling!\nAlternativly you may also enter the corosponding number.\n\nOpperation: ";
	cin >> opperation;
	

	if (opperation == "addition" || opperation == "Addition" || opperation == "+" || opperation == "1"){
		cout << "Enter a number: ";
		cin >> num1;
		cout << "Enter another number: ";
		cin >> num2;
		user.addition(num1,num2);
}
	else if (opperation == "subtraction" || opperation == "Subtraction" || opperation == "-" || opperation == "2"){
		cout << "Enter a number: ";
		cin >> num1;
		cout << "Enter another number: ";
		cin >> num2;
		user.subtraction(num1,num2);
}
	else if (opperation == "multiplication" || opperation == "Multiplication" || opperation == "x" || opperation == "3"){
		cout << "Enter a number: ";
		cin >> num1;
		cout << "Enter another number: ";
		cin >> num2;
		user.multiplication(num1,num2);
}
	else if (opperation == "division" || opperation == "Division" || opperation == "/" || opperation == "4"){
		cout << "Enter a number: ";
		cin >> num1;
		cout << "Enter another number: ";
		cin >> num2;
		if(num1 == 0 || num2 == 0) {
			cout << endl << "You may not divide by zero!" << endl;
			num1 = 10;
			num2 = 2;
		}
		else {
		user.division(num1,num2);
		}
	}
	else if (opperation == "modulus" || opperation == "Modulus" || opperation == "%" || opperation == "5"){
		cout << "Enter a number: ";
		cin >> num3;
		cout << "Enter another number: ";
		cin >> num4;
		user.modulus(num3,num4);
}
	else {
		cout << "Sorry, but \"" << opperation << "\" is not an available opperation!";
}
	setbuf(stdin, NULL); // Remove for linux OS
    cin.get(); // Remove for linux OS
	return 0;
}
