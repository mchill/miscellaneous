//Matthew Hill
//Assignment 12
/*Objectives:
    1. Define structures using a global template
    2. Use structures and structure pointers
    3. Pass structures to functions by using structure pointers
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

const int NUM_PRODUCTS = 8; //Number of products

struct Product{ //Struct for products
    int number;
    string description;
    float unit_price;
    int quantity;
};

void process_order(Product product_list[]);
void print_order(Product product_list[]);

int main()
{
    Product product_list[NUM_PRODUCTS] =   {{1,"ShamWow",19.95,0},
                                            {2,"Puppy",52.00,0},
                                            {3,"Test Answers",59.99,0},
                                            {4,"Mystery Meat",78.90,0},
                                            {5,"Bike",199.99,0},
                                            {6,"Concert Tickets",250.50,0},
                                            {7,"Love",1233.33,0},
                                            {8,"A NEW CAR!",21999.99,0}
                                            };                  //An array of size number of products of objects of struct Product

    //Calls the initialize, process, and print functions, passing the array of objects
    process_order(product_list);
    print_order(product_list);

    return 0;   //End program
}

void process_order(Product product_list[])
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

        for(int i=0;i<NUM_PRODUCTS;i++) //Loop through all products
        {
            if(product_list[i].number == product_number) //If the current product is the same as what the user entered
            {
                cout << "How many units would you like to order? ";
                getline(cin, user_choice);  //Store user choice into a string
                product_quantity = atoi(user_choice.c_str());   //Convert the string into an integer

                product_list[i].quantity += product_quantity;    //Add the integer to the product's quantity member

                cout << "\n\nProduct Number: " << product_list[i].number;
                cout << "\nProduct Description: " << product_list[i].description;
                cout << "\nUnit Price: " << product_list[i].unit_price;
                cout << "\nQuantity Ordered: " << product_quantity;
                cout << "\nPrice of this Order: " << product_list[i].unit_price*product_quantity;
                cout << "\nTotal Quantity Ordered: " << product_list[i].quantity;
                cout << "\nTotal Price of this Product: " << product_list[i].unit_price*product_list[i].quantity << "\n\n";

                break;
            }
            else if(i==NUM_PRODUCTS-1)  //If all products have been checked
                cout << "\nYou entered an invalid product number. Please try again.\n"; //Print error
        }
    }
}

void print_order(Product product_list[])
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

    for(int i=0;i<NUM_PRODUCTS;i++) //Loops through all products
    {
        cout << setw(10) << product_list[i].number;
        cout << setw(20) << product_list[i].description;
        cout << setw(15) << product_list[i].unit_price;
        cout << setw(15) << product_list[i].quantity;
        cout << setw(15) << product_list[i].unit_price*product_list[i].quantity;
        cout << "\n";

        total += product_list[i].unit_price*product_list[i].quantity; //Add the product's subtotal to the total
    }

    cout << "\n" << setw(60) << "Total:" << setw(15) << total << "\n";  //Print the total
}
