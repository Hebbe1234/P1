#include "../headers/CuTest.h"

#include "../headers/wait_time.h"

#include <stdlib.h>
#include <stdio.h>

void wait_test_one (CuTest *tc) {
    passenger p0;
    transition_system t;

    t.length = 1;
    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));
    t.seats_row = 6;

    p0.destination = 54;
    p0.location = 9;
    p0.finish = 1;
    p0.carry_on = 0;
    p0.wait_time = 1;
    p0.spotting = NULL;

    t.passengers[0] = p0;

    wait_time(&t);

    CuAssertTrue(tc, t.passengers[0].wait_time >= 1);
    CuAssertTrue(tc, t.passengers[0].wait_time = 0);
    
    free(t.passengers);
}

CuSuite *get_wait_time_suit (void) {
    CuSuite *suite = CuSuiteNew ();
    SUITE_ADD_TEST(suite, wait_test_one);

    return suite;
}
