#include "../headers/CuTest.h"

#include "../headers/finalizing.h"

#include <stdlib.h>
#include <stdio.h>

/* If p1 is not in plane */
void finalizingtest_first(CuTest *tc) {

    passenger p1;
    transition_system t;

    p1.destination = 54;
    p1.location = -1;
    p1.finish = 0;
    p1.carry_on = 0;
    p1.wait_time = 0;
    p1.interference_flag = 0;

    t.passengers[0] = p1;
    
    finalising_passenger(&t);

    CuAssertTrue(tc, t.passengers[0].location == -1);
    CuAssertTrue(tc, t.passengers[0].finish == 0);

}

/* in destination is true but carry on is 1 */
void finalizingtest_second(CuTest *tc) {
    passenger p1;
    transition_system t;

    p1.destination = 54;
    p1.location = 0;
    p1.finish = 0;
    p1.carry_on = 1;
    p1.wait_time = 0;
    p1.interference_flag = 1;

    t.passengers[0] = p1;
    
    finalising_passenger(&t);

    CuAssertTrue(tc, t.passengers[0].finish == 0);

}

/* in destination is true but carry on is 1 and wait is > 0*/
void finalizingtest_third(CuTest *tc) {
    passenger p1;
    transition_system t;

    p1.destination = 54;
    p1.location = 0;
    p1.finish = 0;
    p1.carry_on = 1;
    p1.wait_time = 2;
    p1.interference_flag = 1;

    t.passengers[0] = p1;
    
    finalising_passenger(&t);

    CuAssertTrue(tc, t.passengers[0].finish == 0);

}

/* in destination and carry on is 0 but wait is > 0*/
void finalizingtest_fourth(CuTest *tc) {
    passenger p1;
    transition_system t;

    p1.destination = 54;
    p1.location = 0;
    p1.finish = 0;
    p1.carry_on = 0;
    p1.wait_time = 2;
    p1.interference_flag = 1;

    t.passengers[0] = p1;
    
    finalising_passenger(&t);

    CuAssertTrue(tc, t.passengers[0].finish == 0);

}

/* in destination but carry on and wait is 0 */
void finalizingtest_fifth(CuTest *tc) {
    passenger p1;
    transition_system t;

    p1.destination = 54;
    p1.location = 9;
    p1.finish = 0;
    p1.carry_on = 0;
    p1.wait_time = 0;
    p1.interference_flag = 1;
    
    t.passengers[0] = p1;
    
    finalising_passenger(&t);

    CuAssertTrue(tc, t.passengers[0].finish == 1);

}

/* not in destination but carry on and wait is 0 */
void finalizingtest_sixth(CuTest *tc) {
    passenger p1;
    transition_system t;

    p1.destination = 54;
    p1.location = 2;
    p1.finish = 0;
    p1.carry_on = 0;
    p1.wait_time = 0;
    p1.interference_flag = 1;

    t.passengers[0] = p1;
    
    finalising_passenger(&t);

    CuAssertTrue(tc, t.passengers[0].finish == 0);

}

/* not in destination but carry on and wait is 0 */
void finalizingtest_seventh(CuTest *tc) {
    passenger p1;
    transition_system t;

    p1.destination = 13;
    p1.location = 2;
    p1.finish = 0;
    p1.carry_on = 1;
    p1.wait_time = 0;
    p1.interference_flag = 0;

    t.passengers[0] = p1;
    
    finalising_passenger(&t);

    CuAssertTrue(tc, t.passengers[0].finish == 0);

}

CuSuite *get_finalizing_suit(void) /*Dette skal op i toppen af alltests.c*/
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, finalizingtest_first);
    SUITE_ADD_TEST(suite, finalizingtest_second);
    SUITE_ADD_TEST(suite, finalizingtest_third);
    SUITE_ADD_TEST(suite, finalizingtest_fourth);
    SUITE_ADD_TEST(suite, finalizingtest_fifth);
    SUITE_ADD_TEST(suite, finalizingtest_sixth);
    SUITE_ADD_TEST(suite, finalizingtest_seventh);

    return suite;
}
