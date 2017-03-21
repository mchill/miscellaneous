//Matthew Hill
//Assignment 17
/*Objectives:
    1. Write member functions for a C++ class.
    2. Write a program which instantiates class objects.
*/

#include <iostream>
using namespace std;

#include "functions.cpp"

void display(Student &student);

int main()
{
    //Create three students, using each of the constructors
    Student student1;
    Student student2("Bob","Joe");
    Student student3("Bob","Joe");
    Student student4("Hill","Matthew","9 Vandalia Place","Durham","North Carolina",11111,111,1111111111);

    //Setting members of student 3 by using the set member functions
    student3.set_street_address("Down the road");
    student3.set_city("Pleasantville");
    student3.set_state("One of the 50");
    student3.set_zip_code(22222);
    student3.set_area_code(222);
    student3.set_phone_num(2222222222);

    //Uses get member variables to print out each students information
    cout << "---------------------------NOW PRINTING FROM MAIN-------------------------------\n";
    cout << "My name is " << student1.get_first_name() << " " << student1.get_last_name() << ".\n";
    cout << "I live at " << student1.get_street_address() << " in " << student1.get_city() << ", " << student1.get_state() << ".\n";
    cout << "My zip code and area code are " << student1.get_zip_code() << " and " << student1.get_area_code() << ".\n";
    cout << "My phone number is " << student1.get_phone_num() << ".  Call me soon!\n\n";
    cout << "My name is " << student2.get_first_name() << " " << student2.get_last_name() << ".\n";
    cout << "I live at " << student2.get_street_address() << " in " << student2.get_city() << ", " << student2.get_state() << ".\n";
    cout << "My zip code and area code are " << student2.get_zip_code() << " and " << student2.get_area_code() << ".\n";
    cout << "My phone number is " << student2.get_phone_num() << ".  Call me soon!\n\n";
    cout << "My name is " << student3.get_first_name() << " " << student3.get_last_name() << ".\n";
    cout << "I live at " << student3.get_street_address() << " in " << student3.get_city() << ", " << student3.get_state() << ".\n";
    cout << "My zip code and area code are " << student3.get_zip_code() << " and " << student3.get_area_code() << ".\n";
    cout << "My phone number is " << student3.get_phone_num() << ".  Call me soon!\n\n";
    cout << "My name is " << student4.get_first_name() << " " << student4.get_last_name() << ".\n";
    cout << "I live at " << student4.get_street_address() << " in " << student4.get_city() << ", " << student4.get_state() << ".\n";
    cout << "My zip code and area code are " << student4.get_zip_code() << " and " << student4.get_area_code() << ".\n";
    cout << "My phone number is " << student4.get_phone_num() << ".  Call me soon!\n\n";

    //Uses the member function display to print out student information
    cout << "------------------NOW PRINTING FROM MEMBER FUNCTION DISPLAY---------------------\n";
    student1.display();
    student2.display();
    student3.display();
    student4.display();

    //Uses the display function, passing a reference of each student, to print out each student's information
    cout << "---------------------NOW PRINTING FROM FUNCTION DISPLAY-------------------------\n";
    display(student1);
    display(student2);
    display(student3);
    display(student4);

    return 0;   //End program
}

void display(Student &student)
{
    cout << "My name is " << student.get_first_name() << " " << student.get_last_name() << ".\n";
    cout << "I live at " << student.get_street_address() << " in " << student.get_city() << ", " << student.get_state() << ".\n";
    cout << "My zip code and area code are " << student.get_zip_code() << " and " << student.get_area_code() << ".\n";
    cout << "My phone number is " << student.get_phone_num() << ".  Call me soon!\n\n";
}
