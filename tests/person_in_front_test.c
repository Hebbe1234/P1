#include "../headers/CuTest.h"

#include "../headers/person_in_front.h"

#include <stdlib.h>
#include <stdio.h>


void test_person_in_front(CuTest *tc) {
    passenger p0, p1, p2, p3, p4;
    transition_system t;
    t.length = 5;

    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));


    p0.destination = 54;
    p0.location = 9;
    p0.finish = 1;
    p0.carry_on = 0;
    p0.wait_time = 0;
    p0.spotting = NULL;

    p1.destination = 55;
    p1.location = 8;
    p1.finish = 0;
    p1.carry_on = 0;
    p1.wait_time = 0;
    p1.spotting = &p0;
    
    p2.destination = 56;
    p2.location = 7;
    p2.finish = 1;
    p2.carry_on = 0;
    p2.wait_time = 0;
    p2.spotting = &p1;

    p3.destination = 45;
    p3.location = 6;
    p3.finish = 1;
    p3.carry_on = 0;
    p3.wait_time = 0;
    p3.spotting = &p2;

    p4.destination = 45;
    p4.location = 6;
    p4.finish = 0;
    p4.carry_on = 0;
    p4.wait_time = 0;
    p4.spotting = &p3;
    

    t.passengers[0] = p0;
    t.passengers[1] = p1;
    t.passengers[2] = p2;
    t.passengers[3] = p3;
    t.passengers[4] = p4;

    person_in_front(&t);
    
    
    CuAssertTrue(tc, t.passengers[4].spotting->destination == 56);
    CuAssertTrue(tc, t.passengers[3].spotting->destination == 55);
    CuAssertTrue(tc, t.passengers[2].spotting->destination == 55);
    CuAssertTrue(tc, t.passengers[1].spotting == NULL); 
    free(t.passengers);

}


CuSuite *get_person_in_front(void) { /*Dette skal op i toppen af alltests.c*/
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_person_in_front);
    return suite;
}