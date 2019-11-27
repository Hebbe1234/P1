#include "../headers/CuTest.h"

#include "../headers/rear.h"

#include <stdlib.h>
#include <stdio.h>

/* p1 looking at p2 going same way */
void test_rear_basic(CuTest *tc)
{
    passenger p1, p2;
    transition_system t;
    int result = 0;

    p1.destination = 20;
    p1.location = 4;
    p1.spotting = NULL;
    p1.finish = 0;

    p2.destination = 25;
    p2.location = 2;
    p2.spotting = &p1;
    p2.finish = 0;

    t.passengers[0] = p1;
    t.passengers[1] = p2;
    t.length = 2;
    t.entrance = 0;
    t.seats_row = 6;
    t.rows= 5;

    result = rear_function(&t, 1);

    CuAssertTrue(tc, result == 0);
}

/* both seeing no person */
void test_rear_noperson(CuTest *tc)
{
    passenger p1, p2;
    transition_system t;

    p1.destination = 20;
    p1.location = 4;
    p1.spotting = NULL;
    p1.finish = 0;

    p2.destination = 0;
    p2.location = 2;
    p2.spotting = NULL;
    p2.finish = 0;

    t.passengers[0] = p1;
    t.passengers[1] = p2;
    t.length = 2;
    t.entrance = 4;

    rear_function(&t, 0);

}


CuSuite *get_rear_suit(void) /*Dette skal op i toppen af alltests.c*/
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_rear_basic);
    /*SUITE_ADD_TEST(suite, test_rear_noperson); */
    return suite;
}
