#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "headers/main.h"
#include <time.h>
#define NUMBER_OF_PASSENGERS_BOARDING 57
#define NUMBER_OF_ROWS 10
#define ENTRANCE_PLACEMENT 4 
#define SEATS_PER_ROW 6

/* Der er brug for flyets indgang som input for at få dette til at virke*/



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
    passenger boarding[NUMBER_OF_PASSENGERS_BOARDING];
    passenger v_left;
    passenger h_right;
    int entrance;
    /*
        TODO: This should not be statically sized. 
        Use int* instead and dynamically allocate memory from a parameter given by the user
    */
    int inteference[2*NUMBER_OF_ROWS];
} aircraft ;



void get_random_number(int *k,int *j);
void get_random_array(int random_destination[]);
void passenger_get_random_destination(int *random_destination, passenger boarding[]);
int find_illegal_seat(int i);
void initialize_passenger_array(passenger boarding[]);
void reset_passenger_array(passenger boarding[]);



int main(void){
    int i, random_destination[60];
    passenger boarding[NUMBER_OF_PASSENGERS_BOARDING];

    srand(time(0));

    reset_passenger_array(boarding);

    initialize_passenger_array(boarding);








    get_random_array(random_destination);

    passenger_get_random_destination(random_destination, boarding);

    printf("\n\n\n");
    for(i=0; i<57; i=i+1) {
        printf("%d , %d \n", boarding[i].destination, i);
    }
    return (0);
}


/* Every passenger in boarding gets set to 0*/
void reset_passenger_array(passenger boarding[]) {
    int i;
    for (i = 0; i < 57; i=i+1) {
        boarding[i].destination = 0;
        boarding[i].location = 0;
        boarding[i].carry_on = 0;
        boarding[i].wait_time = 0;
        boarding[i].finish = 0;
        boarding[i].interference_flag = 0;
        boarding[i].spotting = NULL;
    }
}


/*Passengers look at each other, P0 looks a nothing, P1 looks at P0...*/
void initialize_passenger_array(passenger boarding[]) {
    int i = 0;

    boarding[0].spotting = NULL;
    for(i=1; i<57; i=i+1)
    {
        boarding[i].spotting = &(boarding[i-1]);    
    }
}


void passenger_get_random_destination(int *random_destination, passenger boarding[]) {
    int *p_array, i;

    p_array = random_destination;

    for(i=0; i<57; i=i+1)
    {
        while(*(p_array+i)== (find_illegal_seat(0)) || *(p_array+i) == (find_illegal_seat(1)) || *(p_array+i) == (find_illegal_seat(2))) {
            p_array = p_array+1;
        }
        boarding[i].destination = *(p_array+i);
    }
}



int find_illegal_seat(int i) {
    return ((ENTRANCE_PLACEMENT * SEATS_PER_ROW) + (SEATS_PER_ROW/2) + i);
}



void get_random_array(int random_destination[]) {
    int i, j, k, plads;
    i=j=k=plads=0;

    for(i=0; i<60; i=i+1)
        random_destination[i]=i;

    for(i=0; i<1000000; i=i+1) {
        get_random_number(&k,&j);
        plads = random_destination[k];
        random_destination[k] = random_destination[j];
        random_destination[j] = plads;
    }
}

void get_random_number(int *k,int *j) {
    *k = (rand() % 60);
    *j = (rand() % 60);
}





