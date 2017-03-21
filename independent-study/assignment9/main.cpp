//Matthew Hill
//Assignment 9
/*Objectives:
    1. Process two parallel arrays
*/

#include <iostream>
#include <iomanip>
using namespace std;

void detail_processing(int iArray1[], int iArray2[]);
void print_information(int iArray1[], int iArray2[]);

const int NUM_EMPLOYEES = 8;    //Variable to easily change number of employees throughout program, defined constant to initialize arrays

int main()
{
    int iArray1[NUM_EMPLOYEES] = {6, 21, 43, 57, 7, 11, 29, 30};    //Array of employee numbers
    int iArray2[NUM_EMPLOYEES] = {0, 0, 0, 0, 0, 0, 0, 0};  //Array of hours worked

    detail_processing(iArray1, iArray2);    //Calls function detail_processing
    print_information(iArray1, iArray2);    //Calls function print_information

    return 0;   //End program
}

void detail_processing(int iArray1[], int iArray2[])    //Function to obtain user-entered information and make changes to hours worked
{
    bool done = false;  //Boolean variable to control while loop

    while(done == false)    //Repeat until done is true
    {
        int employee_number;
        int hours_worked;
        char user_choice;

        cout << "Do you want to enter an employee's hours? (Y,N) ";
        cin >> user_choice; //Gets user-entered value for user_choice
        user_choice = toupper(user_choice); //Converts user_choice to upper case to ensure 'y' and 'n' are valid

        if(user_choice == 'Y')  //If the user entered 'y' or 'Y'
        {
            cout << "Enter the employee number: ";
            cin >> employee_number; //Gets user-entered value for employee_number

            for(int i=0; i<NUM_EMPLOYEES+1; i++)    //Cycle through all employee numbers
            {
                if(i == NUM_EMPLOYEES)  //If all employee numbers have been cycled through
                    cout << "Invalid employee number.\n\n"; //Print error message
                else if(iArray1[i] == employee_number)  //If current employee number is equal to entered employee number
                {
                    cout << "Enter the hours worked: ";
                    cin >> hours_worked;    //Get user-entered hours_worked

                    iArray2[i] += hours_worked; //Add hours_worked to the proper part of the second array
                    cout << "\n";

                    break;  //Ends for loop
                }
            }
        }
        else if(user_choice == 'N') //If the user entered 'n' or 'N'
            done = true;    //Sets done to true, ends while loop
        else
            cout << "Invalid choice. Try again.\n\n";
    }

    return; //Return to main()
}

void print_information(int iArray1[], int iArray2[])    //Function to print the final employee numbers and hours worked
{
    cout << "\n";
    cout << setw(10) << "Employee" << setw(10) << "Hours\n";    //Print 1st row of both column headers
    cout << setw(10) << "Number" << setw(10) << "Worked\n\n";   //Print 2nd row of both column headers

    for(int i=0; i<NUM_EMPLOYEES; i++)  //Loop through all employees
    {
        cout << setw(8) << iArray1[i];  //Print employee number in 1st column
        cout << setw(8) << iArray2[i];  //Print hours worked in 2nd column
        cout << "\n";
    }
}
