#include "../headers/CuTest.h"

#include "../headers/finalizing.h"

#include <stdlib.h>
#include <stdio.h>


void testFinalizing_first(CuTest *tc) {

    passenger p1;
    passenger p2; 
    passenger test[2];

    int E = 4;

    p1.destination = 31;
    p1.location = 5;
    p1.finish = 0;
    p1.carry_on = 0;
    p1.wait_time = 0;
    /*p1.inteference_flag = 2;*/
    p1.spotting = NULL;

    p2.destination = 24;
    p2.location = 4;
    p2.finish = 0;
    p2.carry_on = 0;
    p2.wait_time = 0;
    /*p2.inteference_flag = 0;*/
    p2.spotting = NULL;

    test[0] = p1;
    test[1] = p2;
    
    finalising_passenger(test);

    CuAssertTrue(tc, test[0].location == 5);
    CuAssertTrue(tc, test[1].location == 4);


/*  plane.v_left = p1;

    test[0] = p1;

    finalising(&p1);

    CuAssertTrue(tc, p1.finish == 1); */

}

CuSuite *get_finalizing_suit(void) /*Dette skal op i toppen af alltests.c*/
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, testFinalizing_first);
    return suite;
}
