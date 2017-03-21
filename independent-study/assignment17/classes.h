class Student {
    private:
        //Object members that can only be accessed by functions declared in student1
        char *last_name;
        char *first_name;
        char *street_address;
        char *city;
        char *state;
        unsigned long int zip_code;
        int area_code;
        unsigned long int phone_num;

    public:
        //Constructors
        Student();  //Instantiate everything to default
        Student(char*,char*);   //Instantiate first and last name to specified, rest to default
        Student(char*,char*,char*,char*,char*,unsigned long int,int,unsigned long int);   //Instantiate everything to default

        //Destructor
        ~Student();

        //Functions to set passed variables to object members
        void set_last_name(char*);
        void set_first_name(char*);
        void set_street_address(char*);
        void set_city(char*);
        void set_state(char*);
        void set_zip_code(unsigned long int);
        void set_area_code(int);
        void set_phone_num(unsigned long int);

        //Functions to return object members
        char* get_last_name();
        char* get_first_name();
        char* get_street_address();
        char* get_city();
        char* get_state();
        unsigned long int get_zip_code();
        int get_area_code();
        unsigned long int get_phone_num();

        //Display members
        void display();
    };
