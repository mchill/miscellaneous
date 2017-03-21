//Matthew Hill
//Assignment 13 - Revised Assignment 9
/*Objectives:
    1. Use File Operators to fill an array
*/

#include <iostream> //For input and output
#include <fstream>  //For file handling
#include <vector>   //For vectors
#include <iomanip>  //For output manipulation
#include <cstdlib>  //For atoi() conversion
using namespace std;

//Functions that pass the addresses of the vector employee_data and the integer num_employees
void process_file(vector<vector<int> > &employee_data, int &num_employees);
void detail_processing(vector<vector<int> > &employee_data, int &num_employees);
void print_information(vector<vector<int> > &employee_data, int &num_employees);

int main()
{
    vector<vector<int> > employee_data; //Two dimensional vector to hold employee data
    /*I use a vector because their size can be dynamically changed.
      This allows the user to enter any number of employee numbers in the text file,
      and the program will be able to handle all of them, rather than only a predetermined
      number such as 8.*/
    int num_employees = 0;    //Variable to hold number of employees

    process_file(employee_data, num_employees);         //Calls function process_file
    detail_processing(employee_data, num_employees);    //Calls function detail_processing
    print_information(employee_data, num_employees);    //Calls function print_information

    return 0;   //End program
}

void process_file(vector<vector<int> > &employee_data, int &num_employees)
{
    string line;    //String that holds file lines
    vector<string> contents_of_file;  //Vector of file lines
    string user_choice; //String to hold user-entered file name

    while(1==1)
    {
        cout << "Enter the name of the file with employee numbers: ";
        getline(cin, user_choice);  //Gets text file name

        fstream a_file ((user_choice + ".txt").c_str());   //Opens file
        if(a_file.is_open())    //Tests if file opened properly
        {
            while(getline(a_file, line))  //Loops through each line
            {
                employee_data.push_back(vector<int>()); //Expands first dimension of vector
                employee_data[num_employees].push_back(0);  //Expands second dimension of vector, initializes to 0
                employee_data[num_employees].push_back(0);  //Expands second dimension of vector again, initializes to 0

                contents_of_file.push_back(line);   //Stores lines in dynamically sized vector

                const char * employee_num_char = contents_of_file[num_employees].c_str();    //Converts contents_of_file to const char*
                employee_data[num_employees][0] = atoi(employee_num_char);  //Store the file line, now converted to an integer, into the employee_data vector

                num_employees++;    //Increases the number of employees by 1
            }
            a_file.close();     //Closes save file
            break;  //Exits the while loop and function
        }
        else    //If the file did not open
        {
            cout << "That file does not exist.  Try again.\n";  //Error message
        }
    }

    return; //Return to main()
}

void detail_processing(vector<vector<int> > &employee_data, int &num_employees)    //Function to obtain user-entered information and make changes to hours worked
{
    bool done = false;  //Boolean variable to control while loop

    while(1==1)    //Repeat until done is true
    {
        int employee_number;
        int hours_worked;
        char user_choice;

        cout << "\nDo you want to enter an employee's hours? (Y,N) ";
        cin >> user_choice; //Gets user-entered value for user_choice
        user_choice = toupper(user_choice); //Converts user_choice to upper case to ensure 'y' and 'n' are valid

        if(user_choice == 'Y')  //If the user entered 'y' or 'Y'
        {
            cout << "Enter the employee number: ";
            cin >> employee_number; //Gets user-entered value for employee_number

            for(int i=0; i<num_employees+1; i++)    //Cycle through all employee numbers
            {
                if(i == num_employees)  //If all employee numbers have been cycled through
                    cout << "Invalid employee number.\n\n"; //Print error message
                else if(employee_data[i][0] == employee_number)  //If current employee number is equal to entered employee number
                {
                    cout << "Enter the hours worked: ";
                    cin >> hours_worked;    //Get user-entered hours_worked

                    employee_data[i][1] += hours_worked; //Add hours_worked to the vector

                    break;  //Ends for loop
                }
            }
        }
        else if(user_choice == 'N') //If the user entered 'n' or 'N'
            break;  //Exit while loop and function
        else
            cout << "Invalid choice. Try again.\n";
    }

    return; //Return to main()
}

void print_information(vector<vector<int> > &employee_data, int &num_employees)    //Function to print the final employee numbers and hours worked
{
    cout << "\n";
    cout << setw(10) << "Employee" << setw(10) << "Hours\n";    //Print 1st row of both column headers
    cout << setw(10) << "Number" << setw(10) << "Worked\n\n";   //Print 2nd row of both column headers

    for(int i=0; i<num_employees; i++)  //Loop through all employees
    {
        cout << setw(8) << employee_data[i][0];  //Print employee number in 1st column
        cout << setw(8) << employee_data[i][1];  //Print hours worked in 2nd column
        cout << "\n";
    }

    return; //Return to main()
}
