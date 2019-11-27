#include "../headers/CuTest.h"
#include "../headers/input.h"

void test_input_t_system(CuTest *tc){
    transition_system t_system;

    t_system = input_t_system();

    CuAssertTrue(tc, t_system.entrance==4);
}



CuSuite *get_input_t_system_suit(void) /*Dette skal op i toppen af alltests.c*/
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_input_t_system);
    return suite;
}
