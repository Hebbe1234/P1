/*Defining passenger as a struct type */
<<<<<<< HEAD
typedef struct passenger
{
    int destination, 
        location, 
        finish, 
        carry_on, 
        wait_time, 
        interference_flag;
    struct passenger* spotting;
=======
typedef struct passenger {
  int destination, location, finish, carry_on, wait_time, interference_flag;
  struct passenger *spotting;
>>>>>>> master
} passenger;


typedef struct wait_times {
    int t_c, t_m, t_0, t_1, t_2, t_3;
} wait_times;

typedef struct transition_system {

    passenger passengers[60];
    int *destinations;
    int entrance;

} transition_system;
