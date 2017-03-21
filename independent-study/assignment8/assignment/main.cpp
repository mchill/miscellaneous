//Matthew Hill
//Assignment 8
/*Objectives:
    1. Write over loaded functions
    2. Use reference variables
    3. Modify a function to make it inline
*/

#include <iostream>
using namespace std;

void Swap(char &char1, char &char2);
void Swap(int &int1, int &int2);
void Swap(float &float1, float &float2);

int main()
{
    //Variable declarations
    char char1;
    char char2;
    int int1;
    int int2;
    float float1;
    float float2;

    //Obtain user-entered variables
    cout << "Enter char1: ";
    cin >> char1;
    cout << "Enter char2: ";
    cin >> char2;
    cout << "Enter int1: ";
    cin >> int1;
    cout << "Enter int2: ";
    cin >> int2;
    cout << "Enter float1: ";
    cin >> float1;
    cout << "Enter float2: ";
    cin >> float2;

    //Display user-entered variables
    cout << "\nchar1 = " << char1 << "\n";
    cout << "char2 = " << char2 << "\n";
    cout << "int1 = " << int1 << "\n";
    cout << "int2 = " << int2 << "\n";
    cout << "float1 = " << float1 << "\n";
    cout << "float2 = " << float2 << "\n\n";

    //Calls 1 of the 3 Swap functions depending on the variable type of the inputs
    Swap(char1, char2);
    Swap(int1, int2);
    Swap(float1, float2);

    //Displays the now swapped variables
    cout << "\nchar1 = " << char1 << "\n";
    cout << "char2 = " << char2 << "\n";
    cout << "int1 = " << int1 << "\n";
    cout << "int2 = " << int2 << "\n";
    cout << "float1 = " << float1 << "\n";
    cout << "float2 = " << float2 << "\n";

    return 0;   //End program
}

void Swap(char &char1, char &char2) //Function to swap variables of type char
{
    char chartemp = char1;
    char1 = char2;
    char2 = chartemp;
}

void Swap(int &int1, int &int2) //Function to swap variables of type int
{
    int inttemp = int1;
    int1 = int2;
    int2 = inttemp;
}

void Swap(float &float1, float &float2) //Function to swap variables of type float
{
    float floattemp = float1;
    float1 = float2;
    float2 = floattemp;
}
