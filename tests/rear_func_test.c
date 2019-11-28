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
    p1.finish = 0;

    p2.destination = 25;
    p2.location = 0;
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
    int result;

    passenger p1, p2;
    transition_system t;

    p1.destination = 20;
    p1.location = 4;
    p1.finish = 0;

    p2.destination = 8;
    p2.location = 3;
    p2.finish = 0;

    t.passengers[0] = p1;
    t.passengers[1] = p2;
    t.length = 2;
    t.entrance = 3;
    t.seats_row = 2;
    t.rows= 7;
    
    result = rear_function(&t, 1);
    CuAssertTrue(tc, result == 0);

}
/* Tests if function gets passenger closest to entrance and ignores passengers in the wrong direction */
void test_rear_manyperson(CuTest *tc)
{
    int result;

    passenger p0, p1, p2, p3, p4;
    transition_system t;

    p0.destination = 2;
    p0.location = 3;
    p0.finish = 0;

    p1.destination = 0;
    p1.location = 2;
    p1.finish = 0;

    p2.destination = 2;
    p2.location = 1;
    p2.finish = 0;

    p3.destination = 1;
    p3.location = 0;
    p3.finish = 0;

    p4.destination = 8;
    p4.location = 4;
    p4.finish = 0;


    t.passengers[0] = p0;
    t.passengers[1] = p1;
    t.passengers[2] = p2;
    t.passengers[3] = p3;
    t.passengers[4] = p4;

    t.length = 5;
    t.entrance = 3;
    t.seats_row = 2;
    t.rows= 7;
    
    result = rear_function(&t, 0);
    CuAssertTrue(tc, result == 1);

}
/* tests if both passengers went wrong way from entrance and have to pass eachother */
void test_rear_weird(CuTest *tc)
{
    passenger p1, p2;
    transition_system t;
    int result = 0;

    p1.destination = 2;
    p1.location = 1;
    p1.finish = 0;

    p2.destination = 0;
    p2.location = 5;
    p2.finish = 0;

    t.passengers[0] = p1;
    t.passengers[1] = p2;
    t.length = 2;
    t.entrance = 2;
    t.seats_row = 2;
    t.rows= 7;

    result = rear_function(&t, 1);

    CuAssertTrue(tc, result == 0);
}

/* if passengers destination is entrance */
void test_rear_forward(CuTest *tc)
{
    passenger p1, p2, p3;
    transition_system t;
    int result = 0;

    p1.destination = 2;
    p1.location = 2;
    p1.finish = 0;

    p2.destination = 0;
    p2.location = 5;
    p2.finish = 0;

    p3.destination = 0;
    p3.location = 5;
    p3.spotting = &p1;
    p3.finish = 0;

    t.passengers[0] = p1;
    t.passengers[1] = p2;
    t.passengers[2] = p3;
    t.length = 2;
    t.entrance = 2;
    t.seats_row = 2;
    t.rows= 7;

    result = rear_function(&t, 0);

    CuAssertTrue(tc, result == -1);
}

/* if locations are wrong ( -1 or -4) */
void test_rear_wronglocations(CuTest *tc)
{
    int result;

    passenger p0, p1, p2, p3, p4;
    transition_system t;

    p0.destination = 2;
    p0.location = 3;
    p0.finish = 0;

    p1.destination = 0;
    p1.location = 2;
    p1.finish = 0;

    p2.destination = 2;
    p2.location = -1;
    p2.finish = 0;

    p3.destination = 1;
    p3.location = 0;
    p3.finish = 0;

    p4.destination = 8;
    p4.location = -4;
    p4.finish = 0;


    t.passengers[0] = p0;
    t.passengers[1] = p1;
    t.passengers[2] = p2;
    t.passengers[3] = p3;
    t.passengers[4] = p4;

    t.length = 5;
    t.entrance = 3;
    t.seats_row = 2;
    t.rows= 7;
    
    result = rear_function(&t, 0);
    CuAssertTrue(tc, result == 1);

}
/* If passengers to the left but initialized passenger must go to the right where there are no passengers */
void test_rear_manyperson_but_noperson_to_right(CuTest *tc)
{
    int result;

    passenger p0, p1, p2, p3;
    transition_system t;

    p0.destination = 10;
    p0.location = 3;
    p0.finish = 0;

    p1.destination = 0;
    p1.location = 2;
    p1.finish = 0;

    p2.destination = 2;
    p2.location = 1;
    p2.finish = 0;

    p3.destination = 1;
    p3.location = 0;
    p3.finish = 0;

    t.passengers[0] = p0;
    t.passengers[1] = p1;
    t.passengers[2] = p2;
    t.passengers[3] = p3;
 

    t.length = 5;
    t.entrance = 3;
    t.seats_row = 2;
    t.rows= 7;
    
    result = rear_function(&t, 0);
    CuAssertTrue(tc, result == -1);

}

CuSuite *get_rear_suit(void) /*Dette skal op i toppen af alltests.c*/
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_rear_basic);
    SUITE_ADD_TEST(suite, test_rear_noperson); 
    SUITE_ADD_TEST(suite, test_rear_manyperson); 
    SUITE_ADD_TEST(suite, test_rear_weird);
    SUITE_ADD_TEST(suite, test_rear_forward);
    SUITE_ADD_TEST(suite, test_rear_wronglocations);
    SUITE_ADD_TEST(suite, test_rear_manyperson_but_noperson_to_right);
    return suite;
}
