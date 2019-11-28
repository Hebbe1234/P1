#include "../headers/CuTest.h"

#include "../headers/initializing.h"

#include <stdlib.h>
#include <stdio.h>

/* If p1 is in queue and example is not in location of entrance */
void testInitializing_first(CuTest *tc) { 
    passenger p1, p2;
    transition_system t;
    int E = 4;

    t.length = 2;
    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));

    p1.destination = 54;
    p1.location = -1;
    p1.finish = 0;
    p1.spotting = &p2;

    p2.destination = 55;
    p2.location = E + 1;
    p2.finish = 0;
    p2.spotting = NULL;

    t.passengers[0] = p1;
    t.passengers[1] = p2;

    t.entrance = E;


    initialize_passenger(&t);

    CuAssertTrue(tc, t.passengers[0].location == 4);
    CuAssertTrue(tc, t.passengers[1].location == 5); 

    free(t.passengers);

}

/* If p1 is in queue and example is in location of entrance */
void testInitializing_second(CuTest *tc) { 
    passenger p1, p2;
    transition_system t;
    int E = 4;
    
    t.length = 2;
    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));


    p1.destination = 54;
    p1.location = -1;
    p1.finish = 0;
    p1.spotting = &p2;

    p2.destination = 55;
    p2.location = E;
    p2.finish = 0;
    p2.spotting = NULL;

    t.passengers[0] = p1;
    t.passengers[1] = p2;

    t.entrance = E;


    initialize_passenger(&t);

    CuAssertTrue(tc, t.passengers[0].location == -1);
    CuAssertTrue(tc, t.passengers[1].location == 4); 
    free(t.passengers);

}

/* If p1 is in the plane and example is in the plane */
void testInitializing_third(CuTest *tc) { 
    passenger p1, p2;
    transition_system t;
    int E = 4;
    t.length = 2;
    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));


    p1.destination = 54;
    p1.location = E + 1;
    p1.finish = 0;
    p1.spotting = &p2;

    p2.destination = 55;
    p2.location = E + 2;
    p2.finish = 0;
    p2.spotting = NULL;

    t.passengers[0] = p1;
    t.passengers[1] = p2;

    t.entrance = E;


    initialize_passenger(&t);


    CuAssertTrue(tc, t.passengers[0].location == 5);
    CuAssertTrue(tc, t.passengers[1].location == 6); 
    free(t.passengers);
}

/* If p1 is in queue and example is in queue */
void testInitializing_fourth(CuTest *tc) { 
    passenger p1, p2;
    transition_system t;
    int E = 4;
    t.length = 2;
    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));


    p1.destination = 54;
    p1.location = -1;
    p1.finish = 0;
    p1.spotting = &p2;

    p2.destination = 55;
    p2.location = - 1;
    p2.finish = 0;
    p2.spotting = NULL;

    t.passengers[0] = p1;
    t.passengers[1] = p2;

    t.entrance = E;

    initialize_passenger(&t);

    CuAssertTrue(tc, t.passengers[0].location == -1);
    CuAssertTrue(tc, t.passengers[1].location == 4); 

    free(t.passengers);
}

/* If p1 is in queue and example is in queue and both spotting NULL */
void testInitializing_fifth(CuTest *tc) { 
    passenger p1, p2;
    transition_system t;
    int E = 4;
    t.length = 2;
    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));


    p1.destination = 54;
    p1.location = -1;
    p1.finish = 0;
    p1.spotting = NULL;

    p2.destination = 55;
    p2.location = -1;
    p2.finish = 0;
    p2.spotting = NULL;

    t.passengers[0] = p1;
    t.passengers[1] = p2;

    t.entrance = E;

    initialize_passenger(&t);


    CuAssertTrue(tc, t.passengers[0].location == 4);
    CuAssertTrue(tc, t.passengers[1].location == 4); 

    free(t.passengers);
}

/* If p1 is in queue and example is in queue and seeing eachother */
void testInitializing_sixth(CuTest *tc) {
    passenger p1, p2;
    transition_system t;
    int E = 4;
    t.length = 2;
    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));


    p1.destination = 54;
    p1.location = -1;
    p1.finish = 0;
    p1.spotting = &p2;

    p2.destination = 55;
    p2.location = -1;
    p2.finish = 0;
    p2.spotting = &p1;

    t.passengers[0] = p1;
    t.passengers[1] = p2;

    t.entrance = E;

    initialize_passenger(&t);

    CuAssertTrue(tc, t.passengers[0].location == -1);
    CuAssertTrue(tc, t.passengers[1].location == -1); 

    free(t.passengers);
}

/* If p1 is in plane and p2 is in plane but finished */
void testInitializing_seventh(CuTest *tc) { 
    passenger p1, p2;
    transition_system t;
    int E = 4;
    t.length = 2;
    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));


    p1.destination = 54;
    p1.location = -1;
    p1.finish = 0;
    p1.spotting = &p2;

    p2.destination = 55;
    p2.location = E;
    p2.finish = 1;
    p2.spotting = NULL;

    t.passengers[0] = p1;
    t.passengers[1] = p2;

    t.entrance = E;

    initialize_passenger(&t);

    CuAssertTrue(tc, t.passengers[0].location == -1);
    CuAssertTrue(tc, t.passengers[1].location == 4); 

    free(t.passengers);
}

/* tests for multiple passengers */
void testInitializing_eigth(CuTest *tc) { 
    passenger p1, p2, p3;
    transition_system t;
    int E = 4;
    t.length = 3;
    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));


    p1.destination = 54;
    p1.location = 7;
    p1.finish = 0;
    p1.spotting = NULL;

    p2.destination = 54;
    p2.location = 5;
    p2.finish = 0;
    p2.spotting = &p1;

    p3.destination = 54;
    p3.location = -1;
    p3.finish = 0;
    p3.spotting = &p2;

    t.passengers[0] = p1;
    t.passengers[1] = p2;
    t.passengers[2] = p3;

    t.entrance = E;

    initialize_passenger(&t);

    CuAssertTrue(tc, t.passengers[0].location == 7);
    CuAssertTrue(tc, t.passengers[1].location == 5); 
    CuAssertTrue(tc, t.passengers[2].location == 4);

    free(t.passengers);
}


CuSuite *get_initialization_suit(void) /*Dette skal op i toppen af alltests.c*/
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, testInitializing_first);
    SUITE_ADD_TEST(suite, testInitializing_second);
    SUITE_ADD_TEST(suite, testInitializing_third);
    SUITE_ADD_TEST(suite, testInitializing_fourth);
    SUITE_ADD_TEST(suite, testInitializing_fifth);
    SUITE_ADD_TEST(suite, testInitializing_sixth);
    SUITE_ADD_TEST(suite, testInitializing_seventh);
    SUITE_ADD_TEST(suite, testInitializing_eigth);
    return suite;
}
