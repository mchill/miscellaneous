#include "classes.h"

//Set members to specified values
inline void Product::set_number(int input) {number = input;}
inline void Product::set_description(string input) {description = input;}
inline void Product::set_unit_price(float input) {unit_price = input;}
inline void Product::set_quantity(int input) {quantity = input;}

//Gets members
inline int Product::get_number() {return number;}
inline string Product::get_description() {return description;}
inline float Product::get_unit_price() {return unit_price;}
inline int Product::get_quantity() {return quantity;}

//Update quantity
inline void Product::update_quantity(int input)
{
    quantity += input;
}
