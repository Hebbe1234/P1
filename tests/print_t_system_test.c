#include "../headers/CuTest.h"

#include "../headers/print_t_system.h"

#include <stdlib.h>
#include <stdio.h>



void test_t_system(CuTest *tc)
{
    transition_system t;

    t.length = 50;
    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));


    t.carryon_percentage = 70;
    t.entrance = 4;
    t.rows = 10;
    t.seats_per_row = 6;
    t.iterations = 100;
    t.destination_length = 60;
    t.wait.t_c = 1;
    t.wait.t_m = 2;
    t.wait.t_0 = 3;
    t.wait.t_1 = 4;
    t.wait.t_2 = 5;
    t.wait.t_3 = 6;


    printf("\n\n---------------------TEST---------------------\n");
    printf("Test of test_t_system in print_t_system_test.c\n");
    printf("----------------------------------------------\n");
    print_t_system(t);
    printf("-------------------TEST SLUT-------------------\n");

    CuAssertTrue(tc, 1);

    free(t.passengers);
}


CuSuite *get_test_t_system(void) 
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_t_system);
    return suite;
}
