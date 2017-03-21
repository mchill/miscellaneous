//Matthew Hill
//Assignment 6
/*Objectives:
    1. Use the increment and decrement operators
    2. Use a "do-while" loop
    3. Reinforce Assignment 1-5 objectives
*/

#include <iostream>

using namespace std;

void print_vars(int iNum1, int iNum2);

int main()
{
    int iNum1;  //Variable to contain first user-entered integer
    int iNum2;  //Variable to contain second user-entered integer

    cout << "Enter a value for iNum1: ";
    cin >> iNum1;   //Obtain iNum1 from user
    cout << "Enter a value for iNum2: ";
    cin >> iNum2;   //Obtain iNum2 from user
    print_vars(iNum1, iNum2);   //Call print_vars function

    //Do some math and call function print_vars for each operation
    iNum1 += iNum2++;
    cout << "iNum1 += iNum2++";
    print_vars(iNum1, iNum2);

    iNum1 -= ++iNum2;
    cout << "iNum1 -= ++iNum2";
    print_vars(iNum1, iNum2);

    iNum1 *= --iNum2;
    cout << "iNum1 *= --iNum2";
    print_vars(iNum1, iNum2);

    iNum1 /= iNum2--;
    cout << "iNum1 /= iNum2--";
    print_vars(iNum1, iNum2);

    iNum1 %= iNum2;
    cout << "iNum1 %= iNum2";
    print_vars(iNum1, iNum2);

    return 0;   //End program
}

void print_vars(int iNum1, int iNum2)   //Prints iNum1 and iNum2 after each operation
{
    cout << "\niNum1 = " << iNum1;
    cout << "\niNum2 = " << iNum2 << "\n\n";
}
