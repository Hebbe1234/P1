#include "../headers/CuTest.h"

#include "../headers/initializing.h"

#include <stdlib.h>
#include <stdio.h>

/* If p1 is in queue and example is not in location of entrance */
void testInitializing_first(CuTest *tc) { 

    passenger example;
    passenger p1;
    aircraft plane;
    passenger test[2];

    int E = 4;

    p1.destination = 54;
    p1.location = -1;
    p1.finish = 0;
    p1.spotting = &example;

    example.destination = 55;
    example.location = E+1;
    example.finish = 0;
    example.spotting = NULL;

    plane.v_left = example;

    test[0] = p1;
    test[1] = example;
    plane.entrance = E;

    initialize_passenger(test, plane);

    CuAssertTrue(tc, test[0].location == 4);
    CuAssertTrue(tc, test[1].location == 5); 

}

/* If p1 is in queue and example is in location fo entrance */
void testInitializing_second(CuTest *tc) { 

    passenger example;
    passenger p1;
    aircraft plane;
    passenger test[2];

    int E = 4;

    p1.destination = 54;
    p1.location = -1;
    p1.finish = 0;
    p1.spotting = &example;

    example.destination = 55;
    example.location = E;
    example.finish = 0;
    example.spotting = NULL;

    plane.v_left = example;

    test[0] = p1;
    test[1] = example;
    plane.entrance = E;

    initialize_passenger(test, plane);

    CuAssertTrue(tc, test[0].location == -1);
    CuAssertTrue(tc, test[1].location == 4); 

}

/* If p1 is in the plane and example is in the plane */
void testInitializing_third(CuTest *tc) { 

    passenger example;
    passenger p1;
    aircraft plane;
    passenger test[2];

    int E = 4;

    p1.destination = 54;
    p1.location = E+1;
    p1.finish = 0;
    p1.spotting = &example;

    example.destination = 55;
    example.location = E+2;
    example.finish = 0;
    example.spotting = NULL;

    plane.v_left = example;

    test[0] = p1;
    test[1] = example;
    plane.entrance = E;

    initialize_passenger(test, plane);

    CuAssertTrue(tc, test[0].location == 5);
    CuAssertTrue(tc, test[1].location == 6); 

}

/* If p1 is in queue and example is in queue */
void testInitializing_fourth(CuTest *tc) { 

    passenger example;
    passenger p1;
    aircraft plane;
    passenger test[2];

    int E = 4;

    p1.destination = 54;
    p1.location = -1;
    p1.finish = 0;
    p1.spotting = &example;

    example.destination = 55;
    example.location = -1;
    example.finish = 0;
    example.spotting = NULL;

    plane.v_left = example;

    test[0] = p1;
    test[1] = example;
    plane.entrance = E;

    initialize_passenger(test, plane);

    CuAssertTrue(tc, test[0].location == -1);
    CuAssertTrue(tc, test[1].location == 4); 

}

CuSuite *get_initialization_suit(void) /*Dette skal op i toppen af alltests.c*/
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, testInitializing_first);
    SUITE_ADD_TEST(suite, testInitializing_second);
    SUITE_ADD_TEST(suite, testInitializing_third);
    SUITE_ADD_TEST(suite, testInitializing_fourth);
    return suite;
}