#include "../headers/CuTest.h"

#include "../headers/initializing.h"

#include <stdlib.h>
#include <stdio.h>

/* If p1 is in queue and example is not in location of entrance */
void testInitializing_first(CuTest *tc) { 
    passenger example;
    passenger p1;
    transition_system t;
    passenger ps[2];
    int i;
    int queue = 2;
    int E = 4;


    p1.destination = 54;
    p1.location = -1;
    p1.finish = 0;
    p1.carry_on = 1;
    p1.wait_time = 0;
    p1.interference_flag = 0;
    p1.spotting = &example;

    example.destination = 55;
    example.location = E + 1;
    example.finish = 0;
    example.carry_on = 1;
    example.wait_time = 0;
    example.interference_flag = 0;
    example.spotting = NULL;

    ps[0] = p1;
    ps[1] = example;

    
    for(i = 0; i < queue; i++){
        t.passengers[i] = ps[i];
    }

    t.entrance = E;

    initialize_passenger(&t);

    CuAssertTrue(tc, t.passengers[0].location == 4);
    CuAssertTrue(tc, t.passengers[1].location == 5); 

}

/* If p1 is in queue and example is in location of entrance */
void testInitializing_second(CuTest *tc) { 

    passenger example;
    passenger p1;
    transition_system t;
    passenger ps[2];
    int i;
    int queue = 2;
    int E = 4;


    p1.destination = 54;
    p1.location = -1;
    p1.finish = 0;
    p1.spotting = &example;

    example.destination = 55;
    example.location = E;
    example.finish = 0;
    example.spotting = NULL;

    ps[0] = p1;
    ps[1] = example;

    
    for(i = 0; i < queue; i++){
        t.passengers[i] = ps[i];
    }

    t.entrance = E;

    initialize_passenger(&t);
   

    CuAssertTrue(tc, t.passengers[0].location == -1);
    CuAssertTrue(tc, t.passengers[1].location == 4); 

}

/* If p1 is in the plane and example is in the plane */
void testInitializing_third(CuTest *tc) { 

    passenger example;
    passenger p1;
    transition_system t;
    passenger ps[2];
    int i;
    int queue = 2;
    int E = 4;


    p1.destination = 54;
    p1.location = E+1;
    p1.finish = 0;
    p1.spotting = &example;

    example.destination = 55;
    example.location = E+2;
    example.finish = 0;
    example.spotting = NULL;

    ps[0] = p1;
    ps[1] = example;

    
    for(i = 0; i < queue; i++){
        t.passengers[i] = ps[i];
    }

    t.entrance = E;

    initialize_passenger(&t);

   

    CuAssertTrue(tc, t.passengers[0].location == 5);
    CuAssertTrue(tc, t.passengers[1].location == 6); 

}

/* If p1 is in queue and example is in queue */
void testInitializing_fourth(CuTest *tc) { 

    passenger example;
    passenger p1;
    transition_system t;
    passenger ps[2];
    int i;
    int queue = 2;
    int E = 4;

    p1.destination = 54;
    p1.location = -1;
    p1.finish = 0;
    p1.spotting = &example;

    example.destination = 55;
    example.location = -1;
    example.finish = 0;
    example.spotting = NULL;

    ps[0] = p1;
    ps[1] = example;

    
    for(i = 0; i < queue; i++){
        t.passengers[i] = ps[i];
    }

    t.entrance = E;

    initialize_passenger(&t);

    CuAssertTrue(tc, t.passengers[0].location == -1);
    CuAssertTrue(tc, t.passengers[1].location == 4); 

}

/* If p1 is in queue and example is in queue and both spotting NULL */
void testInitializing_fifth(CuTest *tc) { 
    
    passenger example;
    passenger p1;
    transition_system t;
    passenger ps[2];
    int i;
    int queue = 2;
    int E = 4;

    p1.destination = 54;
    p1.location = -1;
    p1.finish = 0;
    p1.spotting = NULL;

    example.destination = 55;
    example.location = -1;
    example.finish = 0;
    example.spotting = NULL;
    ps[0] = p1;
    ps[1] = example;

    
    for(i = 0; i < queue; i++){
        t.passengers[i] = ps[i];
    }

    t.entrance = E;

    initialize_passenger(&t);


    CuAssertTrue(tc, t.passengers[0].location == 4);
    CuAssertTrue(tc, t.passengers[1].location == 4); 

}

/* If p1 is in queue and example is in queue and seeing eachother */
void testInitializing_sixth(CuTest *tc) { 
    passenger example;
    passenger p1;
    transition_system t;
    passenger ps[2];
    int i;
    int queue = 2;
    int E = 4;

    p1.destination = 54;
    p1.location = -1;
    p1.finish = 0;
    p1.spotting = &example;

    example.destination = 55;
    example.location = -1;
    example.finish = 0;
    example.spotting = &p1;

    ps[0] = p1;
    ps[1] = example;
    
    for(i = 0; i < queue; i++){
        t.passengers[i] = ps[i];
    }

    t.entrance = E;

    initialize_passenger(&t);

    CuAssertTrue(tc, t.passengers[0].location == -1);
    CuAssertTrue(tc, t.passengers[1].location == -1); 

}

/* If p1 is in plane and example is in plane but finished */
void testInitializing_seventh(CuTest *tc) { 
    passenger example;
    passenger p1;
    transition_system t;
    passenger ps[2];
    int i;
    int queue = 2;
    int E = 4;

    p1.destination = 54;
    p1.location = -1;
    p1.finish = 0;
    p1.spotting = &example;

    example.destination = 55;
    example.location = E;
    example.finish = 1;
    example.spotting = NULL;

    ps[0] = p1;
    ps[1] = example;

    
    for(i = 0; i < queue; i++){
        t.passengers[i] = ps[i];
    }

    t.entrance = E;

    initialize_passenger(&t);

    CuAssertTrue(tc, t.passengers[0].location == -1);
    CuAssertTrue(tc, t.passengers[1].location == 4); 
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
    return suite;
}
