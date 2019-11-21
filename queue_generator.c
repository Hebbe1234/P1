#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "headers/main.h"
#include <time.h>
#define NUMBER_OF_PASSENGERS_BOARDING 60
#define NUMBER_OF_ROWS 10
#define ENTRANCE_PLACEMENT 4 

void get_random_number(int *k,int *j);
void get_random_array(int random_destination[]);

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














int main(void){

    passenger boarding[NUMBER_OF_PASSENGERS_BOARDING];
    int random_destination[60];
    srand(time(0));

    get_random_array(random_destination);







    return (0);
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

    for(i=0, plads=0; i<60; i=i+1, plads=plads+1) {
        printf("%d , %d \n", random_destination[i], plads);
    }
}

void get_random_number(int *k,int *j) {
    *k = (rand() % 60);
    *j = (rand() % 60);
}





