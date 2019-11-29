#include "../headers/CuTest.h"

#include "../headers/inter.h"

#include <stdlib.h>
#include <stdio.h>

/* going to aisle seat, only person */
void test_inter_aisle_only_person(CuTest *tc) {
    transition_system t;
    passenger p;
    int result = 1;
    
    t.passengers = (struct passenger*)calloc(57, sizeof(passenger));
    t.wait.t_0 = 0;
    t.wait.t_1 = 1;
    t.wait.t_2 = 2;
    t.wait.t_3 = 3;

    p.destination = 2;

    t.passengers[5].destination = 2;
    t.seats_per_row = 6;

    result = inter(&t, p);

    free(t.passengers);

    CuAssertTrue(tc, result == 0);
}

/* going to aisle seat person in middle */
void test_inter_aisle_person_in_middle(CuTest *tc) {
    transition_system t;
    passenger p;
    int result = 1;
    
    t.passengers = (struct passenger*)calloc(15, sizeof(passenger));
    t.wait.t_0 = 0;
    t.wait.t_1 = 1;
    t.wait.t_2 = 2;
    t.wait.t_3 = 3;

    p.destination = 2;

    t.passengers[5].destination = 2;
    t.passengers[4].destination = 1;
    t.passengers[4].finish = 1;
    t.seats_per_row = 6;
    
    result = inter(&t, p);

    free(t.passengers);
   
    CuAssertTrue(tc, result == 0);
}

/* going to aisle seat person in window */
void test_inter_aisle_person_in_window(CuTest *tc) {
    transition_system t;
    passenger p;
    int result = 1;
    
    t.passengers = (struct passenger*)calloc(15, sizeof(passenger));
    t.wait.t_0 = 0;
    t.wait.t_1 = 1;
    t.wait.t_2 = 2;
    t.wait.t_3 = 3;

    p.destination = 2;

    t.passengers[5].destination = 2;
    t.passengers[4].destination = 1;
    t.passengers[4].finish = 1;
    t.seats_per_row = 6;

    result = inter(&t, p);

    free(t.passengers);
    
    CuAssertTrue(tc, result == 0);
}

/* going to aisle seat person in middle and window */
void test_inter_aisle_person_in_middle_and_window(CuTest *tc) {
    transition_system t;
    passenger p;
    int result = 1;
    
    t.passengers = (struct passenger*)calloc(15, sizeof(passenger));
    t.wait.t_0 = 0;
    t.wait.t_1 = 1;
    t.wait.t_2 = 2;
    t.wait.t_3 = 3;

    p.destination = 2;

    t.passengers[5].destination = 2;
    t.passengers[4].destination = 1;
    t.passengers[3].destination = 0;
    t.passengers[4].finish = 1;
    t.passengers[3].finish = 1;
    t.seats_per_row = 6;

    result = inter(&t, p);

    free(t.passengers);

    CuAssertTrue(tc, result == 0);
}

/* going to middle seat, only person */
void test_inter_middle_only_person(CuTest *tc) {
    transition_system t;
    passenger p;
    int result = 1;
    
    t.passengers = (struct passenger*)calloc(57, sizeof(passenger));
    t.wait.t_0 = 0;
    t.wait.t_1 = 1;
    t.wait.t_2 = 2;
    t.wait.t_3 = 3;

    p.destination = 1;

    t.passengers[5].destination = 1;
    t.seats_per_row = 6;

    result = inter(&t, p);

    free(t.passengers);

    CuAssertTrue(tc, result == 0);
}

/* going to middle seat one person in aisle */
void test_inter_middle_person_in_aisle(CuTest *tc) {
    transition_system t;
    passenger p;
    int result = 1;
    
    t.passengers = (struct passenger*)calloc(15, sizeof(passenger));
    t.wait.t_0 = 0;
    t.wait.t_1 = 1;
    t.wait.t_2 = 2;
    t.wait.t_3 = 3;

    p.destination = 1;

    t.passengers[5].destination = 1;
    t.passengers[4].destination = 2;
    t.passengers[4].finish = 1;
    t.seats_per_row = 6;

    result = inter(&t, p);

    free(t.passengers);

    CuAssertTrue(tc, result == 2);
}

/* going to middle seat, one person in window */
void test_inter_middle_person_in_window(CuTest *tc) {
    transition_system t;
    passenger p;
    int result = 1;
    
    t.passengers = (struct passenger*)calloc(57, sizeof(passenger));
    t.wait.t_0 = 0;
    t.wait.t_1 = 1;
    t.wait.t_2 = 2;
    t.wait.t_3 = 3;

    p.destination = 1;

    t.passengers[5].destination = 1;
    t.passengers[4].destination = 0;
    t.passengers[4].finish = 1;
    t.seats_per_row = 6;

    result = inter(&t, p);

    free(t.passengers);

    CuAssertTrue(tc, result == 0);
}

/* going to middle seat, person in aisle and window */
void test_inter_middle_person_in_aisle_and_window(CuTest *tc) {
    transition_system t;
    passenger p;
    int result = 1;
    
    t.passengers = (struct passenger*)calloc(57, sizeof(passenger));
    t.wait.t_0 = 0;
    t.wait.t_1 = 1;
    t.wait.t_2 = 2;
    t.wait.t_3 = 3;

    p.destination = 1;

    t.passengers[5].destination = 1;
    t.passengers[4].destination = 0;
    t.passengers[3].destination = 2;
    t.passengers[4].finish = 1;
    t.passengers[3].finish = 1;
    t.seats_per_row = 6;

    result = inter(&t, p);

    free(t.passengers);

    CuAssertTrue(tc, result == 2);
}

/* going to window seat, only person */
void test_inter_window_only_person(CuTest *tc) {
    transition_system t;
    passenger p;
    int result = 1;
    
    t.passengers = (struct passenger*)calloc(57, sizeof(passenger));
    t.wait.t_0 = 0;
    t.wait.t_1 = 1;
    t.wait.t_2 = 2;
    t.wait.t_3 = 3;

    p.destination = 0;

    t.passengers[5].destination = 0;
    t.seats_per_row = 6;

    result = inter(&t, p);

    free(t.passengers);

    CuAssertTrue(tc, result == 0);
}

/* going to window seat one person in aisle */
void test_inter_window_person_in_aisle(CuTest *tc) {
    transition_system t;
    passenger p;
    int result = 1;
    
    t.passengers = (struct passenger*)calloc(15, sizeof(passenger));
    t.wait.t_0 = 0;
    t.wait.t_1 = 1;
    t.wait.t_2 = 2;
    t.wait.t_3 = 3;

    p.destination = 0;

    t.passengers[5].destination = 0;
    t.passengers[4].destination = 2;
    t.passengers[4].finish = 1;
    t.seats_per_row = 6;

    result = inter(&t, p);

    free(t.passengers);
    printf(" %d", result);
    CuAssertTrue(tc, result == 2);
}

/* going to window seat one person in middle */
void test_inter_window_person_in_middle(CuTest *tc) {
    transition_system t;
    passenger p;
    int result = 1;
    
    t.passengers = (struct passenger*)calloc(15, sizeof(passenger));
    t.wait.t_0 = 0;
    t.wait.t_1 = 1;
    t.wait.t_2 = 2;
    t.wait.t_3 = 3;

    p.destination = 0;

    t.passengers[5].destination = 0;
    t.passengers[4].destination = 1;
    t.passengers[4].finish = 1;
    t.seats_per_row = 6;

    result = inter(&t, p);

    free(t.passengers);

    CuAssertTrue(tc, result == 1);
}

/* going to window seat person in aisle and middle */
void test_inter_window_person_in_aisle_and_middle(CuTest *tc) {
    transition_system t;
    passenger p;
    int result = 1;
    
    t.passengers = (struct passenger*)calloc(15, sizeof(passenger));
    t.wait.t_0 = 0;
    t.wait.t_1 = 1;
    t.wait.t_2 = 2;
    t.wait.t_3 = 3;

    p.destination = 0;

    t.passengers[5].destination = 0;
    t.passengers[4].destination = 1;
    t.passengers[3].destination = 2;
    t.passengers[4].finish = 1;
    t.passengers[3].finish = 1;
    t.seats_per_row = 6;

    result = inter(&t, p);
    printf(" %d", result);
    free(t.passengers);

    CuAssertTrue(tc, result == 3);
}



CuSuite *get_inter_suit(void) /*Dette skal op i toppen af alltests.c*/
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_inter_aisle_only_person);
    SUITE_ADD_TEST(suite, test_inter_aisle_person_in_middle);
    SUITE_ADD_TEST(suite, test_inter_aisle_person_in_window);
    SUITE_ADD_TEST(suite, test_inter_aisle_person_in_middle_and_window);
    SUITE_ADD_TEST(suite, test_inter_middle_only_person);
    SUITE_ADD_TEST(suite, test_inter_middle_person_in_aisle);
    SUITE_ADD_TEST(suite, test_inter_middle_person_in_window);
    SUITE_ADD_TEST(suite, test_inter_middle_person_in_aisle_and_window);
    SUITE_ADD_TEST(suite, test_inter_window_only_person);
    SUITE_ADD_TEST(suite, test_inter_window_person_in_aisle);
    SUITE_ADD_TEST(suite, test_inter_window_person_in_middle);
    SUITE_ADD_TEST(suite, test_inter_window_person_in_aisle_and_middle);
    return suite;
}