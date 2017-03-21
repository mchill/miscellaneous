//Matthew Hill
//Assignment 2
/*Objectives:
    1. Use the cin object
    2. Define a constant
    3. Use the cast operator
    4. Reinforce Assignment 1 objectives
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    //------------------------------------PART A-----------------------------------------//
    cout << "PART A" << "\n";

    float radius;   //Variable to hold user-entered radius
    float circumference;    //Variable to hold calculated circumference
    float area; //Variable to hold calculated area

    const float PI = 3.14;  //Constant integer used to easily calculate with PI
    const int TRIPLE = 3;   //Constant integer used for tripling circumference

    cout << "Enter a radius: ";
    cin >> radius;  //Obtains user-entered radius

    circumference = 2 * PI * radius;    //Calculates circumference
    area = PI * pow(radius, 2); //Uses pow function to calculate area

    cout << "Circumference of circle with the entered radius: " << circumference << "\n";
    cout << "Area of circle with the entered radius: " << area << "\n";

    circumference = circumference * TRIPLE; //3 times radius causes 3 times circumference
    area = area * TRIPLE * TRIPLE;  //3 times radius causes 9 times area

    cout << "Circumference of circle with triple the entered radius: " << circumference << "\n";
    cout << "Area of circle with triple the entered radius: " << area << "\n\n";

    //------------------------------------PART B-----------------------------------------//
    cout << "PART B" << "\n";

    int iNum1 = 4+9;
    int iNum2 = 46/7;
    int iNum3 = 46%7;
    int iNum4 = 2*3.0;
    float fNum5 = float(25)/14;
    int iNum6 = int(7.75) + 2;

    cout << "4 + 9 = " << iNum1 << "\n";
    cout << "46 / 7 = " << iNum2 << "\n";
    cout << "46 % 7 = " << iNum3 << "\n";
    cout << "2 * 3.0 = " << iNum4 << "\n";
    cout << "Float(25) / 14 = " << setprecision(3) << fNum5 << "\n";    //Uses setprecision to limit number of digits
    cout << "Int(7.75) + 2 = " << iNum6 << "\n";

    cout << "ASCII code for the letter 'P': " << int('P') << "\n";  //Converts a char to an int
    cout << "Character represented by ASCII code 105: " << char(105) << "\n";   //Converts an int to a char

    return 0;   //End program
}
