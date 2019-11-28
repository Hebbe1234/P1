#include "../headers/CuTest.h"

#include "../headers/wait_time.h"

#include <stdlib.h>
#include <stdio.h>

void wait_test_1 (CuTest *tc) {
    passenger p0;
    transition_system t;

    p0.destination = 54;
    p0.location = 9;
    p0.finish = 1;
    p0.carry_on = 1;
    p0.wait_time = 3;
    p0.spotting = NULL;

    wait_time(&t);
    CuAssertTrue(tc, t.passengers[0].wait_time == 1);
}

CuSuite *get_wait_time_suit (void) {
    CuSuite *suite = CuSuiteNew ();
    SUITE_ADD_TEST(suite, wait_test_1);

    return suite;
}
