/*#include "../headers/CuTest.h"

#include "../headers/simulation.h"

#include <stdlib.h>
#include <stdio.h>

void test_simulation(CuTest *tc){
    passenger p0, p1, p2, p3;
    transition_system t;

    t.length = 4;
    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));

    p0.destination = 22;
    p1.destination = 43;
    p2.destination = 35;
    p3.destination = 42;

    t.passengers[0] = p0;
    t.passengers[1] = p1;
    t.passengers[2] = p2;
    t.passengers[3] = p3;
    t.entrance = 4;
    t.seats_per_row = 6;
    t.rows = 10;

    free(t.passengers);


}*/
