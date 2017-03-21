#include <string>
using namespace std;

class Product{ //Struct for products
    private:
        int number;
        string description;
        float unit_price;
        int quantity;
    public:
        //Functions to set passed variables to object members
        void set_number(int);
        void set_description(string);
        void set_unit_price(float);
        void set_quantity(int);

        //Funtions to return object members
        int get_number();
        string get_description();
        float get_unit_price();
        int get_quantity();

        //Updates quantity by adding, not setting
        void update_quantity(int);
};
