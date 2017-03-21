//Matthew Hill
//Assignment 14
/*Objectives:
    1. Use recursion
*/

#include <iostream>
#include <iomanip>
using namespace std;

void print(string *str, int i){ //str now holds the address of main's str
    if (i == 0) //If all characters have been printed
        return; //Triggers the turnaround of the recursivity
    else
    {
        cout << (*str).at(0);   //Prints the first character of the string

        string new_str = (*str).substr(1,(*str).length()-1)+(*str).at(0);   //Creates a new string by placing the first character at the end
        print(&new_str,--i);    //Calls the print function with the new string, subtracts number of characters left by 1

        if(i==0)    //If the recursion has just started to unravel
        {
            i++;    //Ensure that this code is not executed again
            cout << "\nReversed String: ";
        }

        cout << (*str).at(0);   //Prints the first  character of the string

        return; //Returns to the last call of the print function, and eventually to main
    }
}

int main()
{
    char char1[] = "Hello world.";
    string str = char1;    //The string to be printed
    int i = str.length();   //The length of string str

    cout << "String: ";

    print(&str,i);  //Calls the print function

    cout << "\n";

    return 0;   //End program
}
