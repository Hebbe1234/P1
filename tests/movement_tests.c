#include "../headers/CuTest.h"

#include "../headers/movement.h"

#include <stdlib.h>
#include <stdio.h>

/* If both passengers are standing outside the plane*/
void movement_test_first(CuTest *tc){

    passenger p1, p2;
    transition_system t;

    p1.destination = 54;
    p1.location = -1;
    p1.finish = 0;
    p1.spotting = &p2;

    p2.destination = 52;
    p2.location = -1;
    p2.finish = 0;
    p2.spotting = NULL;

    t.passengers[0] = p1;
    t.passengers[1] = p2;

    movement(&t, 2);

    CuAssertTrue(tc, t.passengers[0].location == -1);
    CuAssertTrue(tc, t.passengers[1].location == -1);
}

/* One passenger is standing outside the plane and the other is inside */
void movement_test_second(CuTest *tc){

    passenger p1, p2;
    transition_system t;

    p1.destination = 54;
    p1.location = -1;
    p1.finish = 0;
    p1.spotting = &p2;

    p2.destination = 52;
    p2.location = 0;
    p2.finish = 0;
    p2.spotting = NULL;

    t.passengers[0] = p1;
    t.passengers[1] = p2;

    movement(&t, 2);

    CuAssertTrue(tc, t.passengers[0].location == -1);
    CuAssertTrue(tc, t.passengers[1].location == 1);
}

/* Passenger two is standing one 'place' in front of passenger one, two can move, one can't*/
void movement_test_third(CuTest *tc){

    passenger p1, p2;
    transition_system t;

    p1.destination = 54;
    p1.location = 4;
    p1.finish = 0;
    p1.spotting = &p2;

    p2.destination = 52;
    p2.location = 5;
    p2.finish = 0;
    p2.spotting = NULL;

    t.passengers[0] = p1;
    t.passengers[1] = p2;

    movement(&t, 2);

    CuAssertTrue(tc, t.passengers[0].location == 4);
    CuAssertTrue(tc, t.passengers[1].location == 6);
}

/*One passenger is able to move left, the other can move right*/
void movement_test_fourth(CuTest *tc){

    passenger p1, p2;
    transition_system t;

    p1.destination = 6;
    p1.location = 10;
    p1.finish = 0;
    p1.spotting = &p2;

    p2.destination = 54;
    p2.location = 7;
    p2.finish = 0;
    p2.spotting = NULL;

    t.passengers[0] = p1;
    t.passengers[1] = p2;

    movement(&t, 2);

    CuAssertTrue(tc, t.passengers[0].location == 9);
    CuAssertTrue(tc, t.passengers[1].location == 8);
}

/*Both being able to move right*/
void movement_test_fifth(CuTest *tc){

    passenger p1, p2;
    transition_system t;

    p1.destination = 54;
    p1.location = 2;
    p1.finish = 0;
    p1.spotting = &p2;

    p2.destination = 56;
    p2.location = 5;
    p2.finish = 0;
    p2.spotting = NULL;

    t.passengers[0] = p1;
    t.passengers[1] = p2;

    movement(&t, 2);

    CuAssertTrue(tc, t.passengers[0].location == 3);
    CuAssertTrue(tc, t.passengers[1].location == 6);
}

/*If location is wrong, jack shit happens*/
void movement_test_sixth(CuTest *tc){
    passenger p1;
    transition_system t;

    p1.destination = 54;
    p1.location = -5;
    p1.finish = 0;
    p1.spotting = NULL;


    t.passengers[0] = p1;

    movement(&t, 1);

    CuAssertTrue(tc, t.passengers[0].location == -5);
}

void movement_test_seventh(CuTest *tc){

    passenger p1, p2, p3;
    transition_system t;

    p1.destination = 50;
    p1.location = 5;
    p1.finish = 0;
    p1.spotting = NULL;

    p2.destination = 54;
    p2.location = 3;
    p2.finish = 0;
    p2.spotting = &p1;

    p3.destination = 5;
    p3.location = 2;
    p3.finish = 0;
    p3.spotting = &p2;

    t.passengers[0] = p1;
    t.passengers[1] = p2;
    t.passengers[2] = p3;

    movement(&t, 3);

    CuAssertTrue(tc, t.passengers[0].location == 6);
    CuAssertTrue(tc, t.passengers[1].location == 4);
    CuAssertTrue(tc, t.passengers[2].location == 2);
}

void movement_test_eigth(CuTest *tc){

    passenger p1, p2, p3;
    transition_system t;

    p1.destination = 50;
    p1.location = 5;
    p1.finish = 0;
    p1.spotting = NULL;

    p2.destination = 54;
    p2.location = 3;
    p2.finish = 0;
    p2.spotting = &p1;

    p3.destination = 5;
    p3.location = 2;
    p3.finish = 0;
    p3.spotting = NULL;

    t.passengers[0] = p1;
    t.passengers[1] = p2;
    t.passengers[2] = p3;

    movement(&t, 3);

    CuAssertTrue(tc, t.passengers[0].location == 6);
    CuAssertTrue(tc, t.passengers[1].location == 4);
    CuAssertTrue(tc, t.passengers[2].location == 1);
}

CuSuite *get_movement_suit(void) /*Dette skal op i toppen af alltests.c*/
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, movement_test_first);
    SUITE_ADD_TEST(suite, movement_test_second);
    SUITE_ADD_TEST(suite, movement_test_third);
    SUITE_ADD_TEST(suite, movement_test_fourth);
    SUITE_ADD_TEST(suite, movement_test_fifth);
    SUITE_ADD_TEST(suite, movement_test_sixth);
    SUITE_ADD_TEST(suite, movement_test_seventh);
    SUITE_ADD_TEST(suite, movement_test_eigth);
    return suite;
}