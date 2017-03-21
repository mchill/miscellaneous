//Matthew Hill
//Assignment 18 - Revised Assignment 12
/*Objectives:
    1. Use an array of objects
*/

#include <iostream> //For input and output
#include <fstream>  //For file handling
#include <vector>   //For vectors
#include <iomanip>  //For output manipulation
#include <cstdlib>  //For atoi conversion
#include <sstream>  //For stringstream
using namespace std;

#include "functions.cpp"

//Functions that pass a reference to the vector of pointers to objects of Product <--Wow!
//Also passes a reference to the integer num_products
//Passes a reference to the string file_name in all functions that handle the file
void process_file(vector<Product*> &product_list, int &num_products, string &file_name);
void process_order(vector<Product*> &product_list, int &num_products);
void update_file(vector<Product*> &product_list, int &num_products, string &file_name);
void print_order(vector<Product*> &product_list, int &num_products);

int main()
{
    vector<Product*> product_list;    //A vector of pointers to objects of struct Product
    string file_name; //String to hold user-entered file name
    int num_products = 0;   //Variable to store number of products

    //Calls the file read, process, and print functions
    process_file(product_list, num_products, file_name);
    process_order(product_list, num_products);
    update_file(product_list, num_products, file_name);
    print_order(product_list, num_products);

    for(int i=0;i<num_products;i++) //For all products
        delete product_list[i]; //Delete the object

    return 0;   //End program
}

void process_file(vector<Product*> &product_list, int &num_products, string &file_name)
{
    string line;    //String that holds file lines
    vector<vector<string> > contents_of_file;   //Vector that holds contents of file

    while(1==1)
    {
        cout << "Enter the name of the file with employee numbers: ";
        getline(cin, file_name);  //Gets text file name

        fstream a_file ((file_name + ".txt").c_str());   //Opens file
        if(a_file.is_open())    //Tests if file opened properly
        {
            while(getline(a_file, line))  //Loops through each line
            {
                istringstream ss(line); //Stores current line in a stringstream
                string delimited_string;    //String to store delimited parts of current line

                contents_of_file.push_back(vector<string>());   //Create a new row in the content vector
                while(getline(ss, delimited_string, ','))   //For all sections of the current line until a ',' or NULL is encountered
                {
                    contents_of_file[num_products].push_back(delimited_string); //Stores the delimited string part in the contents vector
                }

                product_list.push_back(new Product());  //Creates a new object
                num_products++; //Add 1 product
            }
            a_file.close();     //Closes file
            break;  //Exits the while loop
        }
        else    //If the file did not open
        {
            cout << "That file does not exist.  Try again.\n";  //Error message
        }
    }

    for(int i=0;i<num_products;i++) //For all products
    {
        //Transfers data from the contents vector to the Product objects
        (*product_list[i]).set_number(atoi((contents_of_file[i][0]).c_str()));
        (*product_list[i]).set_description(contents_of_file[i][1]);
        (*product_list[i]).set_unit_price(atof((contents_of_file[i][2]).c_str()));
        (*product_list[i]).set_quantity(atoi((contents_of_file[i][3]).c_str()));
    }
}

void process_order(vector<Product*> &product_list, int &num_products)
{
    bool done = false;  //Sets while loop variable

    string user_choice; //A string to hold user-entered choices
    int product_number = -1;    //User-entered product number initialized to a null value
    int product_quantity = 0;   //User-entered product quanitity defaulted to 0 units

    while(!done)    //Until the loop variable is made true
    {
        cout << "Enter the number of the product that you wish to order,\nOR Enter E to finish: ";
        getline(cin, user_choice);  //Store the user's choice into a string
        if(tolower(user_choice[0])=='e' && user_choice[1]==NULL)    //If the user only entered 'e' or 'E'
        {
            done = true;    //End the while loop
            break;  //Exit the while loop
        }
        product_number = atoi(user_choice.c_str()); //Convert the entered string to an integer

        for(int i=0;i<num_products;i++) //Loop through all products
        {
            if((*product_list[i]).get_number() == product_number) //If the current product is the same as what the user entered
            {
                cout << "How many units would you like to order? ";
                getline(cin, user_choice);  //Store user choice into a string
                product_quantity = atoi(user_choice.c_str());   //Convert the string into an integer

                (*product_list[i]).update_quantity(product_quantity);    //Add the integer to the product's quantity member

                cout << "\n\nProduct Number: " << (*product_list[i]).get_number();
                cout << "\nProduct Description: " << (*product_list[i]).get_description();
                cout << "\nUnit Price: " << (*product_list[i]).get_unit_price();
                cout << "\nQuantity Ordered: " << product_quantity;
                cout << "\nPrice of this Order: " << (*product_list[i]).get_unit_price()*product_quantity;
                cout << "\nTotal Quantity Ordered: " << (*product_list[i]).get_quantity();
                cout << "\nTotal Price of this Product: " << (*product_list[i]).get_unit_price()*(*product_list[i]).get_quantity() << "\n\n";

                break;
            }
            else if(i==num_products-1)  //If all products have been checked
                cout << "\nYou entered an invalid product number. Please try again.\n"; //Print error
        }
    }
}

void update_file(vector<Product*> &product_list, int &num_products, string &file_name)
{
    fstream a_file ((file_name + ".txt").c_str());   //Opens file
    if(a_file.is_open())    //Tests if file opened properly
    {
        for(int i=0;i<num_products;i++) //For all products
        {
            //Outputs object members in correct format to file
            a_file << (*product_list[i]).get_number() << ",";
            a_file << (*product_list[i]).get_description() << ",";
            a_file << (*product_list[i]).get_unit_price() << ",";
            a_file << (*product_list[i]).get_quantity() << "\n";
        }

        a_file.close();     //Closes file
    }
    else    //If the file did not open
    {
        cout << "\nThe product file is missing.\n";  //Error message
        cout << "Now aborting file update.  This order is cancelled.\n";  //Error message
        cout << "The following is an unofficial record of the failed order.\n";  //Error message
    }
}

void print_order(vector<Product*> &product_list, int &num_products)
{
    int total = 0;  //Initializes total price to 0

    //Print headers
    cout << "\n";
    cout << setw(10) << "Product";
    cout << setw(20) << "Product";
    cout << setw(15) << "Unit";
    cout << setw(15) << "Quantity";
    cout << setw(15) << "Subtotal\n";
    cout << setw(10) << "Number";
    cout << setw(20) << "Description";
    cout << setw(15) << "Price";
    cout << setw(15) << "Ordered";
    cout << "\n\n";

    for(int i=0;i<num_products;i++) //Loops through all products
    {
        cout << setw(10) << (*product_list[i]).get_number();
        cout << setw(20) << (*product_list[i]).get_description();
        cout << setw(15) << (*product_list[i]).get_unit_price();
        cout << setw(15) << (*product_list[i]).get_quantity();
        cout << setw(15) << (*product_list[i]).get_unit_price()*(*product_list[i]).get_quantity();
        cout << "\n";

        total += (*product_list[i]).get_unit_price()*(*product_list[i]).get_quantity(); //Add the product's subtotal to the total
    }

    cout << "\n" << setw(60) << "Total:" << setw(15) << total << "\n";  //Print the total
}
