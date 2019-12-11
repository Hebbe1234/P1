#include "../headers/CuTest.h"

#include "../headers/wait_time.h"

#include <stdlib.h>
#include <stdio.h>
#include "../headers/boarding_generator.h"


/*tests that the destinations is between the legal seats
  and no to destinations are the same */
void test_get_outside_in_array_array57(CuTest *tc){
    int i, j, flag0=1;
    int destination[60] = {0};
    transition_system t;
    t.seats_per_row = 6;
    t.rows = 10;
    t.length = 57;
    t.entrance = 4;
    t.destination_length = 60;

    outsidein_boarding_generator(&t, destination);

    for(i = 0, flag0 = 1; i < 60; i++){
        while(destination[i] == -1){
            i++;
        }
        if(!(destination[i] >= 0 && destination[i] < 60)) {
            flag0 = 0;
        }
        for(j = 0; j < 60; j++){

            if(i == j){
                j++;
            }
            if ((destination[i] == destination[j]) && destination[i] != -1 && destination[j] != -1){
                flag0 = 0;
            }
        }
    }
    CuAssertTrue(tc, flag0 == 1);
}

void tests_for_three_illegal_seats(CuTest *tc){

    int i, illegal_seats = 0;
    int destination[60] = {0};
    transition_system t;
    t.seats_per_row = 6;
    t.rows = 10;
    t.length = 57;
    t.entrance = 4;
    t.destination_length = 60;

    outsidein_boarding_generator(&t, destination);

    for(i = 0; i < t.destination_length; i++){
        if(destination[i] == -1){
            illegal_seats++;
        }
    }

    CuAssertTrue(tc, illegal_seats == 3);

}


CuSuite *get_outside_in_suite(void) {
    CuSuite *suite = CuSuiteNew ();
    
    SUITE_ADD_TEST(suite, test_get_outside_in_array_array57);
    SUITE_ADD_TEST(suite, tests_for_three_illegal_seats);
    return suite;
}
