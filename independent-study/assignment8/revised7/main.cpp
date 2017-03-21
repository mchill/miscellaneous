//Matthew Hill
//Assignment 8 - Revised Assignment 7
/*Objectives:
    1. Write over loaded functions
    2. Use reference variables
    3. Modify a function to make it inline
*/

#include <iostream>
#include <string>
using namespace std;

void enter_string(int &num_strings);

int main()
{
    string user_choice;     //Variable to hold user-entered choice
    int num_strings = 0;    //Initializes variable num_strings

    for (int i=0; i<1;) //Loops until i is over 0, which never occurs
    {
        cout << "Do you have a string to enter? (Yes, Y, No, N): ";
        getline(cin,user_choice); //User enters their choice

        if(user_choice == "Yes" || user_choice == "Y")  //If the user does have a string to enter
            {
                enter_string(num_strings); //Calls function enter_string()
            }
        else if(user_choice == "No" || user_choice == "N")  //If the user is sick of entering random strings
            {
                cout << "\nFinal number of strings entered: " << num_strings << "\n";   //Print final number of strings

                break;  //Exits infinite for loop
            }
        else    //If the user doesn't know how to either read or type
            cout << "\nInvalid choice. Enter Yes, Y, No, or N.\n\n\n";  //Prints error message
    }

    return 0;   //End program
}

void enter_string(int &num_strings) //Function to obtain and handle string
{
    num_strings++;  //Increment num_strings, which is a reference to num_strings from main

    cout << "\nEnter your string: ";
    string user_string;     //Variable to contain user's string
    getline(cin,user_string);     //Obtain user-entered string

    if(user_string.size() > 80) //If the string is above the max character limit
        user_string.erase(80,string::npos); //Truncate the string

    cout << "\nLast string entered: " << user_string;
    cout << "\n\nNumber of strings entered: " << num_strings << "\n\n\n";
}
