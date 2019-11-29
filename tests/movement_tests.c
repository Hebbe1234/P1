#include "../headers/CuTest.h"

#include "../headers/movement.h"

#include <stdlib.h>
#include <stdio.h>

/* If both passengers are standing outside the plane*/
void test_outside_plane(CuTest *tc){

    passenger p1, p2;
    transition_system t;
    t.length = 2;
    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));
    t.seats_per_row = 6;

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

    movement(&t);


    CuAssertTrue(tc, t.passengers[0].location == -1);
    CuAssertTrue(tc, t.passengers[1].location == -1);

    free(t.passengers);
}

/* One passenger is standing outside the plane and the other is inside */
void test_in_and_out(CuTest *tc){

    passenger p1, p2;
    transition_system t;
    t.length = 2;
    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));
    t.seats_per_row = 6;

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

    movement(&t);

    CuAssertTrue(tc, t.passengers[0].location == -1);
    CuAssertTrue(tc, t.passengers[1].location == 1);

    free(t.passengers);
}

/* Passenger two is standing one 'place' in front of passenger one, two can move, one can't*/
void test_in_front_of(CuTest *tc){

    passenger p1, p2;
    transition_system t;
    t.length = 2;
    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));
    t.seats_per_row = 6;

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

    movement(&t);

    CuAssertTrue(tc, t.passengers[0].location == 4);
    CuAssertTrue(tc, t.passengers[1].location == 6);

    free(t.passengers);
}

/*One passenger is able to move left, the other can move right*/
void test_different_direction(CuTest *tc){

    passenger p1, p2;
    transition_system t;
    t.length = 2;
    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));
    t.seats_per_row = 6;

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

    movement(&t);

    CuAssertTrue(tc, t.passengers[0].location == 9);
    CuAssertTrue(tc, t.passengers[1].location == 8);

    free(t.passengers);
}

/*Both being able to move right*/
void test_one_direction(CuTest *tc){

    passenger p1, p2;
    transition_system t;
    t.length = 2;
    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));
    t.seats_per_row = 6;

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

    movement(&t);


    CuAssertTrue(tc, t.passengers[0].location == 3);
    CuAssertTrue(tc, t.passengers[1].location == 6);

    free(t.passengers);
}

/*If location is wrong, jack shit happens*/
void test_location_wrong(CuTest *tc){
    passenger p1;
    transition_system t;
    t.length = 1;
    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));
    t.seats_per_row = 6;

    p1.destination = 54;
    p1.location = -5;
    p1.finish = 0;
    p1.spotting = NULL;


    t.passengers[0] = p1;

    movement(&t);


    CuAssertTrue(tc, t.passengers[0].location == -5);

    free(t.passengers);
}
/*testing if multiple passengers can move at once*/
void test_multiple_passengers(CuTest *tc){

    passenger p1, p2, p3;
    transition_system t;
    t.length = 3;
    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));
    t.seats_per_row = 6;

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

    movement(&t);


    CuAssertTrue(tc, t.passengers[0].location == 6);
    CuAssertTrue(tc, t.passengers[1].location == 4);
    CuAssertTrue(tc, t.passengers[2].location == 2);
    
    free(t.passengers);
}
/*Testing if it's possible for multiple people to move in different directions*/
void test_multiple_different_directions(CuTest *tc){

    passenger p1, p2, p3;
    transition_system t;
    t.length = 3;
    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));

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

    t.length = 3;

    movement(&t);


    CuAssertTrue(tc, t.passengers[0].location == 6);
    CuAssertTrue(tc, t.passengers[1].location == 4);
    CuAssertTrue(tc, t.passengers[2].location == 1);
    free(t.passengers);
}

CuSuite *get_movement_suit(void) /*Dette skal op i toppen af alltests.c*/
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_outside_plane);
    SUITE_ADD_TEST(suite, test_in_and_out);
    SUITE_ADD_TEST(suite, test_in_front_of);
    SUITE_ADD_TEST(suite, test_different_direction);
    SUITE_ADD_TEST(suite, test_one_direction);
    SUITE_ADD_TEST(suite, test_location_wrong);
    SUITE_ADD_TEST(suite, test_multiple_passengers);
    SUITE_ADD_TEST(suite, test_multiple_different_directions);
    return suite;
}