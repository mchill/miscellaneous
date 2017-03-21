class Student {
    private:
        //Object members that can only be accessed by functions declared in Student
        char *last_name;
        char *first_name;
        char *street_address;
        char *city;
        char *state;
        long int zip_code;
        int area_code;
        long int phone_num;

    public:
        //Functions to set passed variables to object members
        void set_last_name(char*);
        void set_first_name(char*);
        void set_street_address(char*);
        void set_city(char*);
        void set_state(char*);
        void set_zip_code(long int);
        void set_area_code(int);
        void set_phone_num(long int);

        //Functions to return object members
        char* get_last_name();
        char* get_first_name();
        char* get_street_address();
        char* get_city();
        char* get_state();
        long int get_zip_code();
        int get_area_code();
        long int get_phone_num();
    };
