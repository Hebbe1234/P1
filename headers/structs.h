/*Defining passenger as a struct type */
typedef struct passenger
{
    int destination, 
        location, 
        finish, 
        carry_on, 
        wait_time, 
        interference_flag;
    struct passenger* spotting;
} passenger;

/*Defining the aircraft as a struct type */
typedef struct aircraft 
{
    passenger boarding[60];
    passenger v_left;
    passenger h_right;
    int entrance;
    /*
        TODO: This should not be statically sized. 
        Use int* instead and dynamically allocate memory from a parameter given by the user
    */
    int inteference[2*10];
} aircraft;
