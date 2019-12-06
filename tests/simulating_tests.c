#include "../headers/CuTest.h"

#include "../headers/simulation.h"
#include "../headers/print_t_system.h"

#include <stdlib.h>
#include <stdio.h>

/* Tests plane being split in two equally */
void split_plane_test(CuTest *tc) {
    transition_system t1, t2, t_input;

    t_input.entrance = 0;
    t_input.length = 114;
    t_input.rows = 20;
    t_input.seats_per_row = 6;
    t_input.destination_length = 120;

    split_plane(&t_input, &t1, &t2);

    CuAssertTrue(tc, t1.entrance == 0);
    CuAssertTrue(tc, t2.entrance == 9);
    CuAssertTrue(tc, t1.length == 57);
    CuAssertTrue(tc, t2.length == 57);
    CuAssertTrue(tc, t1.rows == 10);
    CuAssertTrue(tc, t2.rows == 10);
    CuAssertTrue(tc, t1.destination_length == 60);
    CuAssertTrue(tc, t2.destination_length == 60);
}

/* test passenger split when not equal */
void split_passengers_test(CuTest *tc) {
    transition_system t1, t2, t_input;

    t_input.entrance = 0;
    t_input.length = 101;
    t_input.rows = 20;
    t_input.seats_per_row = 6;
    t_input.destination_length = 120;

    split_plane(&t_input, &t1, &t2);

    CuAssertTrue(tc, t1.entrance == 0);
    CuAssertTrue(tc, t2.entrance == 9);
    CuAssertTrue(tc, t1.length == 50);
    CuAssertTrue(tc, t2.length == 51);
    CuAssertTrue(tc, t1.rows == 10);
    CuAssertTrue(tc, t2.rows == 10);
    CuAssertTrue(tc, t1.destination_length == 60);
    CuAssertTrue(tc, t2.destination_length == 60);
}

/* tests split of rows when unequal aswell as entrance */
void split_rows_test(CuTest *tc) {
    transition_system t1, t2, t_input;

    t_input.entrance = 0;
    t_input.length = 100;
    t_input.rows = 25;
    t_input.seats_per_row = 6;
    t_input.destination_length = 120;

    split_plane(&t_input, &t1, &t2);

    CuAssertTrue(tc, t1.entrance == 0);
    CuAssertTrue(tc, t2.entrance == 12);
    CuAssertTrue(tc, t1.length == 50);
    CuAssertTrue(tc, t2.length == 50);
    CuAssertTrue(tc, t1.rows == 12);
    CuAssertTrue(tc, t2.rows == 13);
    CuAssertTrue(tc, t1.destination_length == 60);
    CuAssertTrue(tc, t2.destination_length == 60);
}

CuSuite *get_simulation_suite(void) {

    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, split_plane_test);
    SUITE_ADD_TEST(suite, split_passengers_test);
    SUITE_ADD_TEST(suite, split_rows_test);
    return suite;
}