//Matthew Hill
//Assignment 11 - Revised Assignment 7
/*Objectives:
    1. Use pointers
    2. Process strings
*/

#include <iostream>
#include <string>
using namespace std;

void enter_string(int &num_strings);
void process_string(string *user_string);

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
    process_string(&user_string);   //Calls the function process_string, passing the address of user_string
    cout << "\n\nNumber of strings entered: " << num_strings << "\n\n\n";
}

void process_string(string *user_string)
{
    int num_vowels = 0; //Initializes number of vowels at 0

    for(int i=0;(*user_string)[i]!='\0';i++)    //Loops through all characters of the string
    {
        switch (tolower((*user_string)[i])) //Switch statement based on the current character converted to lower case
        {
            case 'a':case 'e':case 'i':case 'o':case 'u':   //All cases where the character is a vowel
                num_vowels++;   //Add one vowel
                break;  //Leave switch statement
        }
    }

    cout << "\nIn this string there were " << num_vowels << " vowels.";
}
