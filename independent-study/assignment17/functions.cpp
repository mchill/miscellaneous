#include <iostream>
using namespace std;

#include "classes.h"

inline Student::Student()
{
    last_name = "Default";
    first_name = "Default";
    street_address = "Default";
    city = "Default";
    state = "Default";
    zip_code = 0;
    area_code = 0;
    phone_num = 0;
}

inline Student::Student(char *char1,char *char2)
{
    last_name = char1;
    first_name = char2;
    street_address = "Default";
    city = "Default";
    state = "Default";
    zip_code = 0;
    area_code = 0;
    phone_num = 0;
}

inline Student::Student(char *char1,char *char2,char *char3,char *char4,char *char5,unsigned long int lint1,int int1,unsigned long int lint2)
{
    last_name = char1;
    first_name = char2;
    street_address = char3;
    city = char4;
    state = char5;
    zip_code = lint1;
    area_code = int1;
    phone_num = lint2;
}

inline Student::~Student()  //Deletes memory pointed to by the pointer members of objects
{
    delete last_name;
    delete first_name;
    delete street_address;
    delete city;
    delete state;
}

//Sets members to specified values
inline void Student::set_last_name(char* input) {last_name = input;}
inline void Student::set_first_name(char* input) {first_name = input;}
inline void Student::set_street_address(char* input) {street_address = input;}
inline void Student::set_city(char* input) {city = input;}
inline void Student::set_state(char* input) {state = input;}
inline void Student::set_zip_code(unsigned long int input) {zip_code = input;}
inline void Student::set_area_code(int input) {area_code = input;}
inline void Student::set_phone_num(unsigned long int input) {phone_num = input;}

//Gets members
inline char* Student::get_last_name() {return last_name;}
inline char* Student::get_first_name() {return first_name;}
inline char* Student::get_street_address() {return street_address;}
inline char* Student::get_city() {return city;}
inline char* Student::get_state() {return state;}
inline unsigned long int Student::get_zip_code() {return zip_code;}
inline int Student::get_area_code() {return area_code;}
inline unsigned long int Student::get_phone_num() {return phone_num;}

//Displays members
inline void Student::display()
{
    cout << "My name is " << first_name << " " << last_name << ".\n";
    cout << "I live at " << street_address << " in " << city << ", " << state << ".\n";
    cout << "My zip code and area code are " << zip_code << " and " << area_code << ".\n";
    cout << "My phone number is " << phone_num << ".  Call me soon!\n\n";
}
