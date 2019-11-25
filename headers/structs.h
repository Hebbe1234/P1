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


typedef struct wait_times {
    int t_c, t_m, t_0, t_1, t_2, t_3;
} wait_times;

typedef struct transition_system {

    passenger passengers[60];
    int *destinations;
    int entrance;
    wait_times wait;

} transition_system;
