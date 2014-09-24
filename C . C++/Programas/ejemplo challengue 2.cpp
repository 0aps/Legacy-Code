#include <iostream>
#include <cstring>

using namespace std;

bool no_character(string input)
{
    for (unsigned int i=0; i < input.size(); i++)
        {
            if(isalpha(input[i]))
                return false;
        }
    return true;
}

int main()
{
    string input;
    string name;
    int age;
    int usrid;

    cout << "Welcome to Shae's solution to Programming Challenge 2." << endl;
    cout << "Type exit and press enter to close this program." << endl;

    // While loop to take the input for the name
    while(1)
    {
        cout << "Please type your forum name and press enter: ";
        getline (cin, input, '\n');

        if (input == "exit")
            return 0;
        else if (input.size() == 0)
            cout << "Your forum name cannot be blank, please try again." << endl;
        else if (input[0] == ' ')
            cout << "Your forum name cannot start with a space, please try again." << endl;
        else if (no_character(input))
            cout << "Your forum name must contain a non-numerical character, please try again." << endl;
        else
        {
            name = input;
            break;
        }
    }

    // While loop to take the input for the age
    while(1)
    {
        cout << "Please type your age and press enter: ";
        getline (cin, input, '\n');
        age = atoi(input.c_str());

        if (input == "exit")
            return 0;
        else if (input.size() == 0)
            cout << "Your age cannot be blank, please try again." << endl;
        else if (input[0] == ' ')
            cout << "Your age cannot start with a space, please try again." << endl;
        else if (age < 1 || age > 120)
            cout << "Your age cannot be less than 1, greater than 120, and must be a number, please try again." << endl;
        else
            break;
    }

    // While loop to take the input for the user id
    while(1)
    {
        cout << "Please type your user id and press enter: ";
        getline (cin, input, '\n');
        usrid = atoi(input.c_str());

        if (input == "exit")
            return 0;
        else if (input.size() == 0)
            cout << "Your user id cannot be blank, please try again." << endl;
        else if (input[0] == ' ')
            cout << "Your user id cannot start with a space, please try again." << endl;
        else if (usrid < 1 || usrid > 999999)
            cout << "Your user id cannot be less than 1, greater than 999999, and must be a number, please try again." << endl;
        else
            break;
    }

    cout << "You are " << name << ", aged " << age << " next year you will be " << age + 1 << ", with user id " << usrid << ", the next user is " << usrid + 1 << "." << endl;
    cin.get();
    return 0;
}  
