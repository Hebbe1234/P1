#include "../headers/CuTest.h"

#include "../headers/interference.h"

#include <stdlib.h>
#include <stdio.h>

/* nobody moves anywhere */
void test_interference_nothing(CuTest *tc) {
    transition_system t;
    
    t.passengers = (struct passenger*)calloc(3, sizeof(passenger));
    t.seats_per_row = 2;
    t.length = 3;
    t.wait.t_0 = 0;
    t.wait.t_1 = 1;
    t.wait.t_2 = 2;
    t.wait.t_3 = 3;

    t.passengers[0].wait_time = 0;
    t.passengers[0].destination = 10;
    t.passengers[0].location = 5;
    t.passengers[0].interference_flag = 1;

    t.passengers[1].wait_time = 0;
    t.passengers[1].destination = 8;
    t.passengers[1].location = 4;
    t.passengers[1].interference_flag = 0;

    t.passengers[2].wait_time = 0;
    t.passengers[2].destination = 4;
    t.passengers[2].location = 2;
    t.passengers[2].interference_flag = 0;

    interference_function(&t);

    CuAssertTrue(tc, t.passengers[0].wait_time == 0);
    CuAssertTrue(tc, t.passengers[1].wait_time == 0);
    CuAssertTrue(tc, t.passengers[2].wait_time == 0);

    free(t.passengers);
}

/* Interference if one passenger is in the way */
void test_interference_one_passenger(CuTest *tc) {
    transition_system t;
    
    t.passengers = (struct passenger*)calloc(3, sizeof(passenger));
    t.seats_per_row = 6;
    t.length = 3;
    t.wait.t_0 = 0;
    t.wait.t_1 = 1;
    t.wait.t_2 = 2;
    t.wait.t_3 = 3;

    t.passengers[0].wait_time = 0;
    t.passengers[0].destination = 10;
    t.passengers[0].location = 1;
    t.passengers[0].interference_flag = 1;
    t.passengers[0].finish = 1;

    t.passengers[1].wait_time = 0;
    t.passengers[1].destination = 11;
    t.passengers[1].location = 1;
    t.passengers[1].interference_flag = 0;
    t.passengers[1].finish = 0;

    t.passengers[2].wait_time = 0;
    t.passengers[2].destination = 4;
    t.passengers[2].location = 0;
    t.passengers[2].interference_flag = 0;
    t.passengers[2].finish = 0;

    interference_function(&t);

    CuAssertTrue(tc, t.passengers[0].wait_time == 0);
    CuAssertTrue(tc, t.passengers[1].wait_time == 2);
    CuAssertTrue(tc, t.passengers[2].wait_time == 0);

    free(t.passengers);
}

/* passenger to window, but two passengers blocking */
void test_interference_two_passengers(CuTest *tc) {
    transition_system t;
    
    t.passengers = (struct passenger*)calloc(3, sizeof(passenger));
    t.seats_per_row = 6;
    t.length = 3;
    t.wait.t_0 = 0;
    t.wait.t_1 = 1;
    t.wait.t_2 = 2;
    t.wait.t_3 = 3;

    t.passengers[0].wait_time = 0;
    t.passengers[0].destination = 9;
    t.passengers[0].location = 1;
    t.passengers[0].interference_flag = 1;
    t.passengers[0].finish = 1;

    t.passengers[1].wait_time = 0;
    t.passengers[1].destination = 10;
    t.passengers[1].location = 1;
    t.passengers[1].interference_flag = 1;
    t.passengers[1].finish = 1;

    t.passengers[2].wait_time = 0;
    t.passengers[2].destination = 11;
    t.passengers[2].location = 1;
    t.passengers[2].interference_flag = 0;
    t.passengers[2].finish = 0;

    interference_function(&t);

    CuAssertTrue(tc, t.passengers[0].wait_time == 0);
    CuAssertTrue(tc, t.passengers[1].wait_time == 0);
    CuAssertTrue(tc, t.passengers[2].wait_time == 3);

    free(t.passengers);
}

/* passenger to window seat but middle blockers */
void test_interference_middle_passenger_alone(CuTest *tc) {
    transition_system t;
    
    t.passengers = (struct passenger*)calloc(3, sizeof(passenger));
    t.seats_per_row = 6;
    t.length = 3;
    t.wait.t_0 = 0;
    t.wait.t_1 = 1;
    t.wait.t_2 = 2;
    t.wait.t_3 = 3;

    t.passengers[0].wait_time = 0;
    t.passengers[0].destination = 9;
    t.passengers[0].location = 1;
    t.passengers[0].interference_flag = 0;
    t.passengers[0].finish = 0;

    t.passengers[1].wait_time = 0;
    t.passengers[1].destination = 10;
    t.passengers[1].location = 1;
    t.passengers[1].interference_flag = 1;
    t.passengers[1].finish = 1;

    t.passengers[2].wait_time = 0;
    t.passengers[2].destination = 11;
    t.passengers[2].location = 1;
    t.passengers[2].interference_flag = 0;
    t.passengers[2].finish = 0;

    interference_function(&t);

    CuAssertTrue(tc, t.passengers[0].wait_time == 0);
    CuAssertTrue(tc, t.passengers[1].wait_time == 0);
    CuAssertTrue(tc, t.passengers[2].wait_time == 2);

    free(t.passengers);
}

/* passenger to window but aisle blockers */
void test_interference_aisle_passenger(CuTest *tc) {
    transition_system t;
    
    t.passengers = (struct passenger*)calloc(3, sizeof(passenger));
    t.seats_per_row = 6;
    t.length = 3;
    t.wait.t_0 = 0;
    t.wait.t_1 = 1;
    t.wait.t_2 = 2;
    t.wait.t_3 = 3;

    t.passengers[0].wait_time = 0;
    t.passengers[0].destination = 9;
    t.passengers[0].location = 1;
    t.passengers[0].interference_flag = 1;
    t.passengers[0].finish = 1;

    t.passengers[1].wait_time = 0;
    t.passengers[1].destination = 10;
    t.passengers[1].location = 1;
    t.passengers[1].interference_flag = 0;
    t.passengers[1].finish = 0;

    t.passengers[2].wait_time = 0;
    t.passengers[2].destination = 11;
    t.passengers[2].location = 1;
    t.passengers[2].interference_flag = 1;
    t.passengers[2].finish = 1;

    interference_function(&t);

    CuAssertTrue(tc, t.passengers[0].wait_time == 0);
    CuAssertTrue(tc, t.passengers[1].wait_time == 1);
    CuAssertTrue(tc, t.passengers[2].wait_time == 0);

    free(t.passengers);
}

CuSuite *get_interference_suit(void) /*Dette skal op i toppen af alltests.c*/
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_interference_nothing);
    SUITE_ADD_TEST(suite, test_interference_one_passenger);
    SUITE_ADD_TEST(suite, test_interference_two_passengers);
    SUITE_ADD_TEST(suite, test_interference_middle_passenger_alone);
    SUITE_ADD_TEST(suite, test_interference_aisle_passenger);
    return suite;
}
