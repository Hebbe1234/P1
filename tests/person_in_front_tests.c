#include "../headers/CuTest.h"

#include "../headers/person_in_front.h"

#include <stdlib.h>
#include <stdio.h>

/* If p1 is not in plane */
void person_in_front_first(CuTest *tc) {

    passenger p1, p2, p3;
    transition_system t;

    p1.destination = 54;
    p1.location = 9;
    p1.finish = 0;
    p1.carry_on = 0;
    p1.wait_time = 0;
    p1.interference_flag = 0;
    p1.spotting = NULL;

    p2.destination = 55;
    p2.location = 8;
    p2.finish = 1;
    p2.carry_on = 0;
    p2.wait_time = 0;
    p2.interference_flag = 0;
    p2.spotting = &p1;

    p3.destination = 56;
    p3.location = 7;
    p3.finish = 0;
    p3.carry_on = 0;
    p3.wait_time = 0;
    p3.interference_flag = 0;
    p3.spotting = &p2;


    t.passengers[0] = p1;
    t.passengers[1] = p2;
    t.passengers[2] = p3;
    
    person_in_front(&t, 3); 

    CuAssertTrue(tc, p3.spotting->destination == 55);
}

CuSuite *get_person_front_suit(void) /*Dette skal op i toppen af alltests.c*/
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, person_in_front_first);

    return suite;
}