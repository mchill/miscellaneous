//Matthew Hill
//Assignment 3
/*Objectives:
    1. Write several functions, some of which return a value, and others which do not
    2. Reinforce Assignment 1 and 2 objectives
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void firstCalcFunc(int iNum);
int secondCalcFunc(int iNum1, int iNum2);
int thirdCalcFunc(int iNum1, int iNum2);

int main()
{
    int iNum1 = 5;
    int iNum2 = 13;
    int iResult;

    cout << "5 * 13 = " << iNum1*iNum2 << "\n"; //Display results without result variable

    firstCalcFunc(iNum1);   //Calls the firstCalcFunc function  with a variable integer
    firstCalcFunc(7);   //Calls the firstCalcFunc function with a literal integer

    iResult = secondCalcFunc(iNum1, iNum2); //Returns answer of function secondCalcFunc to iResult
    cout << iNum1 << " * " << iNum2 << " = " << iResult << "\n";

    cout << iNum1 << " * " << iNum2 << " = " << thirdCalcFunc(iNum1,iNum2) << "\n"; //Calls function thirdCalcFunc within cout

    return 0;   //End program
}

void firstCalcFunc(int iNum)    //Function to multiply an integer by two
{
    iNum *= 2;

    cout << iNum/2 << " * 2 = " << iNum << "\n";

    return;
}

int secondCalcFunc(int iNum1, int iNum2)    //Function to multiply two integers
{
    int iResult = iNum1 * iNum2;

    return iResult;
}

int thirdCalcFunc(int iNum1, int iNum2) //Function to multiply two integers without using a local variable
{
    return iNum1*iNum2;
}
