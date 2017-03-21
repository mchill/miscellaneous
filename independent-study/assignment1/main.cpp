//Matthew Hill
//Assignment 1
/*Objectives:
    1. Declare variables of different types
    2. Assign values to variables
    3. Do some simple math
    4. Print variables using the "cout" object
*/

#include <iostream>
using namespace std;

int main()
{
    //Creates 7 integer variables
    int iNum1;
    int iNum2;
    int iNum3;
    int iNum4;
    int iNum5;
    int iNum6;
    int iNum7;

    //Creates 2 float variables
    float fNum8 = 129.546;
    float fNum9 = 0;

    //Creates 1 char variable
    char cAnyChar = 'T';

    iNum1 = 135;
    iNum2 = 6;

    //Do some math and store answers in variables
    iNum3 = iNum1 - iNum2;
    iNum4 = iNum1 + iNum2;
    iNum5 = iNum1 / iNum2;
    fNum9 = iNum1 / iNum2;
    iNum6 = iNum1 % iNum2;
    iNum7 = iNum1 * iNum2;

    //Display results
    cout << "iNum1: " << iNum1 << "\n";
    cout << "iNum2: " << iNum2 << "\n";
    cout << "iNum3: " << iNum3 << "\n";
    cout << "iNum4: " << iNum4 << "\n";
    cout << "iNum5: " << iNum5 << "\n";
    cout << "iNum6: " << iNum6 << "\n";
    cout << "iNum7: " << iNum7 << "\n";
    cout << "fNum8: " << fNum8 << "\n";
    cout << "fNum9: " << fNum9 << "\n";
    cout << "cAnyChar: " << cAnyChar;

    return 0;   //End program
}
