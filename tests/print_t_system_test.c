#include "../headers/CuTest.h"

#include "../headers/print_t_system.h"

#include <stdlib.h>
#include <stdio.h>



void test_t_system(CuTest *tc)
{
    transition_system t;


    t.carryon_percentage = 70;
    t.entrance = 4;
    t.rows = 10;
    t.seats_per_row = 6;
    t.length = 50;
    t.iterations = 100;
    t.wait.t_c = 1;
    t.wait.t_m = 2;
    t.wait.t_0 = 3;
    t.wait.t_1 = 4;
    t.wait.t_2 = 5;
    t.wait.t_3 = 6;

    print_t_system(t);
    CuAssertTrue(tc, 1);
}


CuSuite *get_test_t_system(void) /*Dette skal op i toppen af alltests.c*/
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_t_system);
    return suite;
}
