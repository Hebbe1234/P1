#include "../headers/CuTest.h"
#include "../headers/carry_on.h"
#include <stdlib.h>


/*Test one person with carryon and 0 waittime*/
void test_carry_on0(CuTest *tc)
{
    transition_system t;
    t.passengers = (struct passenger*)calloc(57, sizeof(passenger));

    t.passengers[0].carry_on = 1;
    t.passengers[0].wait_time = 0;
    t.passengers[0].location = 3;
    t.passengers[0].destination = 18;

    t.wait.t_c = 5;
    t.seats_per_row = 6;


    carry_on(&t);

    CuAssertTrue(tc, t.passengers[0].carry_on == 0);
    CuAssertTrue(tc, t.passengers[0].wait_time == 5);
}

/*Test 4 passengers having carry on or not, and having a waittime, or not*/
void test_carry_on1(CuTest *tc)
{
    transition_system t;
    t.passengers = (struct passenger*)calloc(57, sizeof(passenger));

    t.passengers[0].carry_on = 0;
    t.passengers[0].wait_time = 0;
    t.passengers[0].location = 3;
    t.passengers[0].destination = 18;

    t.passengers[1].carry_on = 1;
    t.passengers[1].wait_time = 3;
    t.passengers[0].location = 4;
    t.passengers[0].destination = 24;

    t.passengers[2].carry_on = 1;
    t.passengers[2].wait_time = 0;
    t.passengers[0].location = 5;
    t.passengers[0].destination = 31;

    t.passengers[3].carry_on = 0;
    t.passengers[3].wait_time = 3;
    t.passengers[0].location = 6;
    t.passengers[0].destination = 40;

    t.wait.t_c = 5;

    carry_on(&t);

    CuAssertTrue(tc, t.passengers[0].carry_on == 0);
    CuAssertTrue(tc, t.passengers[0].wait_time == 0);

    CuAssertTrue(tc, t.passengers[1].carry_on == 0);
    CuAssertTrue(tc, t.passengers[1].wait_time == 8);

    CuAssertTrue(tc, t.passengers[2].carry_on == 0);
    CuAssertTrue(tc, t.passengers[2].wait_time == 5);

    CuAssertTrue(tc, t.passengers[3].carry_on == 0);
    CuAssertTrue(tc, t.passengers[3].wait_time == 3);
}

/*Test one person being in the wrong place wait carry one, and a person without carry on in the wrong location*/
void test_carry_on2(CuTest *tc)
{
    transition_system t;
    t.passengers = (struct passenger*)calloc(57, sizeof(passenger));

    t.passengers[0].carry_on = 1;
    t.passengers[0].wait_time = 0;
    t.passengers[0].location = 1;
    t.passengers[0].destination = 18;

    t.passengers[1].carry_on = 0;
    t.passengers[1].wait_time = 3;
    t.passengers[1].location = 1;
    t.passengers[1].destination = 18;

    t.wait.t_c = 5;

    carry_on(&t);

    CuAssertTrue(tc, t.passengers[0].carry_on == 1);
    CuAssertTrue(tc, t.passengers[0].wait_time == 0);

    CuAssertTrue(tc, t.passengers[1].carry_on == 0);
    CuAssertTrue(tc, t.passengers[1].wait_time == 3);
}


CuSuite *get_carry_on_suite(void) /*Dette skal op i toppen af alltests.c*/
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_carry_on0);
    SUITE_ADD_TEST(suite, test_carry_on1);
    SUITE_ADD_TEST(suite, test_carry_on2);
    return suite;
}
