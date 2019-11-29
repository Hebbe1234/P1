#include "../headers/CuTest.h"

#include "../headers/wait_time.h"

#include <stdlib.h>
#include <stdio.h>

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

void wait_test_two (CuTest *tc) {
    passenger p0;
    transition_system t;

    t.length = 1;
    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));

    p0.wait_time = 1;

    t.passengers[0] = p0;

    wait_time(&t);

    CuAssertTrue(tc, t.passengers[0].wait_time == 0);

    
    free(t.passengers);
}

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

void wait_test_four (CuTest *tc) {
    passenger p0, p1, p2;
    transition_system t;

    t.length = 3;
    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));

    p0.wait_time = -1;
    p1.wait_time = 0;
    p2.wait_time = 1;

    t.passengers[0] = p0;
    t.passengers[1] = p1;
    t.passengers[2] = p2;

    wait_time(&t);

    CuAssertTrue(tc, t.passengers[0].wait_time == -1);
    CuAssertTrue(tc, t.passengers[1].wait_time == 0);
    CuAssertTrue(tc, t.passengers[2].wait_time == 0);
    
    
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
