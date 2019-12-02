#include "../headers/CuTest.h"

#include "../headers/wait_time.h"

#include <stdlib.h>
#include <stdio.h>

/*Testing whether or not a person with wait-time 0 is finished*/
void wait_test_one (CuTest *tc) {
    passenger p0;
    transition_system t;

    t.length = 1;
    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));

    p0.wait_time = 0;

    t.passengers[0] = p0;

    wait_time(&t);

    CuAssertTrue(tc, t.passengers[0].wait_time == 0);
    free(t.passengers);
}

/*Testing if a person with a wait time above one can finsih*/
void wait_test_two (CuTest *tc) {
    passenger p0;
    transition_system t;

    t.length = 1;
    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));

    p0.wait_time = 3;

    t.passengers[0] = p0;

    wait_time(&t);

    CuAssertTrue(tc, t.passengers[0].wait_time == 2);

    
    free(t.passengers);
}

/*Checking what happens if a person have negative wait time*/
void wait_test_three (CuTest *tc) {
    passenger p0;
    transition_system t;

    t.length = 1;
    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));

    p0.wait_time = -1;

    t.passengers[0] = p0;

    wait_time(&t);

    CuAssertTrue(tc, t.passengers[0].wait_time == -1);
    
    free(t.passengers);
}

/*Checking how multiple people at once works*/
void wait_test_four (CuTest *tc) {
    passenger p0, p1, p2;
    transition_system t;

    t.length = 3;
    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));

    p0.wait_time = 0;
    p1.wait_time = 3;
    p2.wait_time = 11;

    t.passengers[0] = p0;
    t.passengers[1] = p1;
    t.passengers[2] = p2;

    wait_time(&t);

    CuAssertTrue(tc, t.passengers[0].wait_time == 0);
    CuAssertTrue(tc, t.passengers[1].wait_time == 2);
    CuAssertTrue(tc, t.passengers[2].wait_time == 10);
    
    free(t.passengers);
}

CuSuite *get_wait_time_suit (void) {
    CuSuite *suite = CuSuiteNew ();
    SUITE_ADD_TEST(suite, wait_test_one);
    SUITE_ADD_TEST(suite, wait_test_two);
    SUITE_ADD_TEST(suite, wait_test_three);
    SUITE_ADD_TEST(suite, wait_test_four);

    return suite;
}
