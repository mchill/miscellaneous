//Matthew Hill
//Assignment 8 - Revised Assignment 3
/*Objectives:
    1. Write over loaded funcions
    2. Use reference variables
    3. Modify a function to make it inline
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

inline void firstCalcFunc(int iNum);
inline int secondCalcFunc(int iNum1, int iNum2);
inline int thirdCalcFunc(int iNum1, int iNum2);

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

inline void firstCalcFunc(int iNum)    //Function to multiply an integer by two
{
    iNum *= 2;

    cout << iNum/2 << " * 2 = " << iNum << "\n";

    return;
}

inline int secondCalcFunc(int iNum1, int iNum2)    //Function to multiply two integers
{
    int iResult = iNum1 * iNum2;

    return iResult;
}

inline int thirdCalcFunc(int iNum1, int iNum2) //Function to multiply two integers without using a local variable
{
    return iNum1*iNum2;
}
