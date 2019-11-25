#include "../headers/CuTest.h"

#include "../headers/is_finished.h"

#include <stdlib.h>
#include <stdio.h>

void test_finished_first(CuTest *tc) {
    passenger example;
    passenger p1;
    passenger test[2];

    p1.finish = 0;
    example.finish = 0;

    test[0] = p1;
    test[1] = example;

    is_finished(*t, 2);

    CuAssert(tc, finished == 0);

}

CuSuite *get_finished_suit(void) /*Dette skal op i toppen af alltests.c*/
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_finished_first);
    return suite;
}