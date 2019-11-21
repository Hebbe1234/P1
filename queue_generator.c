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
        inteference_flag;
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




int main(void){
    int i;
    passenger boarding[NUMBER_OF_PASSENGERS_BOARDING];
    int random_destination[60];
    srand(time(0));

    get_random_array(random_destination);

    passenger_get_random_destination(random_destination, boarding);

    printf("\n\n\n");
    for(i=0; i<57; i=i+1) {
        printf("%d , %d \n", boarding[i].destination, i);
    }
    return (0);
}



void passenger_get_random_destination(int *random_destination, passenger boarding[]) {
    int *pointer_array, i;

    pointer_array = random_destination;

    for(i=0; i<57; i=i+1)
    {
        if(*(pointer_array+i)== (find_illegal_seat(0)) || *(pointer_array+i) == (find_illegal_seat(1)) || *(pointer_array+i) == (find_illegal_seat(2))) {
            pointer_array = pointer_array+1;

            if(*(pointer_array+i)==(find_illegal_seat(0)) || *(pointer_array+i) == (find_illegal_seat(1)) || *(pointer_array+i) == (find_illegal_seat(2))) {
                pointer_array = pointer_array+1;

                if(*(pointer_array+i)==(find_illegal_seat(0)) || *(pointer_array+i) == (find_illegal_seat(1)) || *(pointer_array+i) == (find_illegal_seat(2))) {
                    pointer_array = pointer_array+1;
                }
            }
        }
        boarding[i].destination = *(pointer_array+i);
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





