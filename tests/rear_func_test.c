#include "../headers/CuTest.h"

double gange(double a, double b)
{
    return a * b;
}

void testgange(CuTest *tc)
{
    double result;
    result = gange(3, 0);
    CuAssertTrue(tc, result == 0);
}

void testgange0(CuTest *tc)
{
    double result;
    result = gange(3, 3);
    CuAssertTrue(tc, result == 9);
}

CuSuite *get_example_suit(void) /*Dette skal op i toppen af alltests.c*/
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, testgange);
    SUITE_ADD_TEST(suite, testgange0);
    return suite;
}
