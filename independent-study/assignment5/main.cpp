//Matthew Hill
//Assignment 5
/*Objectives:
    1. Create a simple menu
    2. Use the "switch" statement
    3. Reinforce Assignment 1-4 objectives
*/

#include <iostream>
using namespace std;

void build_menu();
void process_choice(char user_choice);

int main()
{
    char user_choice;   //Variable to contain user entered character

    build_menu();   //Calls function build_menu

    cin >> user_choice;     //Obtain user entered character
    user_choice = toupper(user_choice);     //Convert user_choice to upper-case (has no effect on upper-case or digits)

    if(user_choice == '0' || user_choice == 'Q')  //If user_choice is equal to the character 0
    {
        cout << "\nProgram Ending\n"; //Print error message
        return 1;   //Return error
    }

    process_choice(user_choice);    //Calls function process_choise

    return 0;   //End program
}

void build_menu()   //Prints a menu
{
    cout << "1 - Add a record\n";
    cout << "2 - Edit a record\n";
    cout << "3 - Reports\n";
    cout << "4 - Utilities\n";
    cout << "5 - Tools\n";
    cout << "6 - Help\n\n";
    cout << "0 - Quit\n\n";

    return;
}

void process_choice(char user_choice)   //Outputs a message depending on user_choice
{
    cout << "\n";

    switch (user_choice)    //A switch based on user_choice
    {
        case '1':
            cout << "You selected Add a record";
            break;
        case 'A':
            cout << "You selected Add a record";
            break;
        case '2':
            cout << "You selected Edit a record";
            break;
        case 'E':
            cout << "You selected Edit a record";
            break;
        case '3':
            cout << "You selected Reports";
            break;
        case 'R':
            cout << "You selected Reports";
            break;
        case '4':
            cout << "You selected Utilities";
            break;
        case 'U':
            cout << "You selected Utilities";
            break;
        case '5':
            cout << "You selected Tools";
            break;
        case 'T':
            cout << "You selected Tools";
            break;
        case '6':
            cout << "You selected Help";
            break;
        case 'H':
            cout << "You selected Help";
            break;
        default:
            cout << "You entered an invalid choice.";
            break;
    }

    cout << "\n";
}
