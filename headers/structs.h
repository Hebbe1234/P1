/*Defining passenger as a struct type */
typedef struct passenger {
  int destination, location, finish, carry_on, wait_time, interference_flag;
  struct passenger *spotting;
} passenger;


typedef struct wait_times {
    int t_c, t_m, t_0, t_1, t_2, t_3;
} wait_times;

typedef struct transition_system {
    passenger *passengers;
    int destination_length;
    int entrance;
    int rows;
    int seats_per_row;
    int length;
    int carryon_percentage;
    int simulations;
    int iterations;
    wait_times wait;
} transition_system;
