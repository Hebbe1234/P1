#include "../headers/CuTest.h"

#include "../headers/is_finished.h"

#include <stdlib.h>
#include <stdio.h>

/* if no one is finished */
void test_finished_first(CuTest *tc) {
    passenger example;
    passenger p1;
    transition_system t;
    int finished = 0;

    p1.finish = 0;
    example.finish = 0;

    t.passengers[0] = p1;
    t.passengers[1] = example;

    finished = is_finished(&t, 2);

    CuAssertTrue(tc, finished == 0);
}

/* if one passenger is finished */
void test_finished_second(CuTest *tc) {
    passenger example;
    passenger p1;
    transition_system t;
    int finished = 0;

    p1.finish = 1;
    example.finish = 0;

    t.passengers[0] = p1;
    t.passengers[1] = example;

    finished = is_finished(&t, 2);

    CuAssertTrue(tc, finished == 0);
}

/* if one passenger is not finished */
void test_finished_third(CuTest *tc) {
    passenger example;
    passenger p1;
    passenger p2;
    transition_system t;
    int finished = 0;

    p1.finish = 1;
    p2.finish = 1;
    example.finish = 0;

    t.passengers[0] = p1;
    t.passengers[1] = example;
    t.passengers[2] = p2;

    finished = is_finished(&t, 2);

    CuAssertTrue(tc, finished == 0);
}

/* if one passenger finish is wrong */
void test_finished_fourth(CuTest *tc) {
    passenger example;
    passenger p1;
    passenger p2;
    transition_system t;
    int finished = 0;

    p1.finish = 1;
    p2.finish = -4;
    example.finish = 0;

    t.passengers[0] = p1;
    t.passengers[1] = example;
    t.passengers[2] = p2;

    finished = is_finished(&t, 2);

    CuAssertTrue(tc, finished == 0);
}

/* if all passengers are finished */
void test_finished_fifth(CuTest *tc) {
    passenger example;
    passenger p1;
    passenger p2;
    transition_system t;
    int finished = 0;

    p1.finish = 1;
    p2.finish = 1;
    example.finish = 1;

    t.passengers[0] = p1;
    t.passengers[1] = example;
    t.passengers[2] = p2;

    finished = is_finished(&t, 2);

    CuAssertTrue(tc, finished == 1);
}

CuSuite *get_finished_suit(void) /*Dette skal op i toppen af alltests.c*/
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_finished_first);
    SUITE_ADD_TEST(suite, test_finished_second);
    SUITE_ADD_TEST(suite, test_finished_third);
    SUITE_ADD_TEST(suite, test_finished_fourth);
    SUITE_ADD_TEST(suite, test_finished_fifth);
    return suite;
}