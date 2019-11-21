#include "../headers/CuTest.h"

#include "../headers/initializing.h"

#include <stdlib.h>
#include <stdio.h>


void testInitializing_first(CuTest *tc) {

    passenger example;
    passenger p1;
    aircraft plane;
    passenger test[2];

    int E = 4;

    p1.destination = 54;
    p1.location = -1;
    p1.finish = 0;
    p1.carry_on = 1;
    p1.wait_time = 0;
    p1.inteference_flag = 0;
    p1.spotting = &example;

    example.destination = 55;
    example.location = E+1;
    example.finish = 0;
    example.carry_on = 1;
    example.wait_time = 0;
    example.inteference_flag = 0;
    example.spotting = NULL;

    plane.v_left = example;

    test[0] = p1;
    test[1] = example;
    plane.entrance = E;

    initialize_passenger(test, plane);

    CuAssertTrue(tc, test[0].location == 4);
    CuAssertTrue(tc, test[1].location == 5); 

}

CuSuite *get_initialization_suit(void) /*Dette skal op i toppen af alltests.c*/
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, testInitializing_first);
    return suite;
}