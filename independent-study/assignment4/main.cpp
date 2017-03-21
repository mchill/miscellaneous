//Matthew Hill
//Assignment 4
/*Objectives:
    1. Use an "if" statment
    2. Process a simple strong
    3. Reinforce Assignment 1, 2, and 3 objectives
*/

#include <iostream>

using namespace std;

int get_employee_number(int employee_number);
float get_hours_worked(float hours_worked);
float get_hourly_rate(float hourly_rate);
void print_information(int employee_number, float hours_worked, float hourly_rate, char* employee_type, float employee_pay);

int main()
{
    int employee_number;    //Variable to contain user-entered employee number
    float hours_worked;     //Variable to contain user-entered hours worked
    float hourly_rate;      //Variable to contain user-entered hourly rate
    char employee_type[2];  //Variable to contain user-entered employee type
    float employee_pay;     //Variable to contain calculated employee pay

    for(static int i=0; i<7; i++)   //For loop, runs 7 times
    {
        employee_number = get_employee_number(employee_number); //Calls function get_employee_number
        hours_worked = get_hours_worked(hours_worked);  //Cals function get_hours_worked
        hourly_rate = get_hourly_rate(hourly_rate);     //Calls function get_hourly_rate

        cout << "Enter whether the employee is full time(FT, ft) or part time(PT, pt): ";   //Prompts user to enter employee type
        cin >> employee_type;   //Obtains user-entered employee type

        if((employee_type[0] == 'p' || employee_type[0] == 'P') && (employee_type[1] == 't' || employee_type[1] == 'T'))    //If the employee type is full time
        {
            if(hours_worked <= 30)  //If there is no overtime
            {
                employee_pay = hourly_rate * hours_worked;  //Calculate employee pay
            }
            else    //If there is overtime
            {
                employee_pay = hourly_rate * 30 + hourly_rate * 1.5 * (hours_worked-30);    //Calculate employee pay
            }
        }
        else if((employee_type[0] == 'f' || employee_type[0] == 'F') && (employee_type[1] == 't' || employee_type[1] == 'T'))   //If the employee type is part time
        {
            if(hours_worked <= 40)  //If there is not overtime
            {
                employee_pay = hourly_rate * hours_worked;  //Calculate employee pay
            }
            else    //If there is overtime
            {
                employee_pay = hourly_rate * 40 + hourly_rate * 2 * (hours_worked-40);  //Calculate employee pay
            }
        }
        else    //If the employee type is invalid
        {
            cout << "\nError: Invalid employee type";   //Print error message

            return 1;   //Return error
        }

        print_information(employee_number, hours_worked, hourly_rate, employee_type, employee_pay); //Calls function print_information
    }

    return 0;   //End program
}

int get_employee_number(int employee_number)    //Gets user_entered employee number
{
    cout << "Enter the employee number: ";
    cin >> employee_number;

    return employee_number; //Return employee_number
}

float get_hours_worked(float hours_worked)  //Gets user-entered hours worked
{
    cout << "Enter the number of hours worked this week: ";
    cin >> hours_worked;

    return hours_worked;    //Return hours_worked
}

float get_hourly_rate(float hourly_rate)    //Gets user-entered hourly rate
{
    cout << "Enter the hourly rate: ";
    cin >> hourly_rate;

    return hourly_rate; //Return hourly_rate
}

void print_information(int employee_number, float hours_worked, float hourly_rate, char* employee_type, float employee_pay) //Print all entered and calculated information
{
    cout << "\nEmployee Number: " << employee_number << "\n";
    cout << "Hours Worked: " << hours_worked << "\n";
    cout << "Hourly Rate: " << hourly_rate << "\n";
    cout << "Employee Type: " << employee_type << "\n";
    cout << "Gross pay: " << employee_pay << "\n\n";
}
