#include "../headers/CuTest.h"
#include "../headers/initialize_passenger_array.h"
#include "../headers/boarding_generator.h"
#include <stdlib.h>
#include <stdio.h>

/*Tests that the number generated is between the limits*/
void test_get_random_number_80(CuTest *tc) {
    int k, j, i;
    transition_system t;
    t.destination_length = 80;
    
    for (i = 0; i < 100; ++i) {
        get_random_number(&k, &j, &t);
        CuAssertTrue(tc, (k >= 0) && (k < 80));
        CuAssertTrue(tc, (j >= 0) && (j < 80));
    }
}

/*Tests that the number generated is between the limits*/
void test_get_random_number_15(CuTest *tc) {
    int k, j, i;
    
    transition_system t;
    t.destination_length = 18;

    for (i = 0; i < 100; ++i) {
        get_random_number(&k, &j, &t);
        CuAssertTrue(tc, (k >= 0) && (k < 18));
        CuAssertTrue(tc, (j >= 0) && (j < 18));
    }
}
/*Tests that when the entrance is 4 and we tests seat 0, 1, 2 is legal*/
void test_is_legal_seat_E4(CuTest *tc) {
    int result, i;
    
    transition_system t;
    t.seats_per_row = 6; 
    t.length = 80;
    t.entrance = 4;
    for (i = 0, t.entrance = 4; i < 3; ++i) {
        result = is_legal_seat(i, &t);
        CuAssertTrue(tc, result==1);
    }
}

/*Tests that when the entrance is 0 and we tests seat 3,4,5 they are illegal*/
void test_is_legal_seat_E0(CuTest *tc) {
   int result, i;
    transition_system t;
    t.seats_per_row = 6; 
    t.length = 80;
    t.entrance = 0;
   
   for (i = 3, t.entrance = 0; i < 6; ++i) {
        result = is_legal_seat(i, &t);
        CuAssertTrue(tc, result == 0);
    }
}

/*Tests that a passenger either gets carry on 1, or 0*/
void test_get_carryon_A57_CP50(CuTest *tc) {
    transition_system t;
    int i, flag0;
    t.passengers = (struct passenger*)calloc(57, sizeof(passenger));
    
    t.seats_per_row = 6; 
    t.length = 57;
    t.carryon_percentage = 50;

    get_carryon(&t);
    
    for(i=0, flag0=1; (i<57) && (flag0==1); i++) {
        if ((t.passengers[i].carry_on != 0) && (t.passengers[i].carry_on !=1))
            flag0=0;
    }
    free(t.passengers);
    CuAssertTrue(tc, flag0 == 1);
}

/*Tests that when carryon percentage is 100, everyone has carryon*/
void test_get_carryon_A51_CP100(CuTest *tc) {
    int i, flag1;
    transition_system t;
    t.passengers = (struct passenger*)calloc(51, sizeof(passenger));
    
    t.seats_per_row = 6; 
    t.length = 51;
    t.carryon_percentage = 100;

    get_carryon(&t);
    for(i=0, flag1=1; (i<51) && (flag1==1); i++) {
        if (t.passengers[i].carry_on !=1)
            flag1=0;
    }    
    free(t.passengers);

    CuAssertTrue(tc, flag1 == 1);
}

/*Tests that when carryon percentage is 0, noone has carryon*/
void test_get_carryon_A51_CP0(CuTest *tc) {
    int i, flag2;
    transition_system t;
    t.passengers = (struct passenger*)calloc(51, sizeof(passenger));
    
    t.seats_per_row = 6; 
    t.length = 51;
    t.carryon_percentage = 0;
    
    get_carryon(&t);
    for(i=0, flag2=1; (i<51) && (flag2==1); i++) {
        if (t.passengers[i].carry_on !=0)
            flag2=0;
    }    
    free(t.passengers);

    CuAssertTrue(tc, flag2 == 1);
}


/*Der produceres et passenger array. 
  Der gives destination fra 0 til 57 til passasgerene. 
  Initialize spotting kaldes. 
  Der testes at den forreste kigger på ingen
  Der testes at alle andre passasgere, kigger på den rigtige, 
  ved at tjekke at destinationen på den de kigger på, er korrekt*/
void test_initialize_spotting(CuTest *tc) {
    int i, flag1=1;
    transition_system t;
    t.passengers = (struct passenger*)calloc(57, sizeof(passenger));
    t.length = 57;

    for (i = 0; i < 57; i++) {
        t.passengers[i].destination = i;
    }

    initialize_spotting(&t);

    if(t.passengers[0].spotting!=NULL)
        flag1=0;

    for(i=1; i < 57; i=i+1) {
        if(t.passengers[i].spotting->destination != t.passengers[i-1].destination)
            flag1=0;
    }
    free(t.passengers);
    CuAssertTrue(tc, flag1 == 1);
}

/* Tests that the 3 illegal seats dosent becomes a passengers destination*/
/*And noone has the same destination*/
void test_passenger_get_random_destinations_array57_entrance4(CuTest *tc) {
    int i, j, flag0 = 1;
    int destination[60] = {0};
    transition_system t;
    t.length = 57;

    for(i=0; i<60; i++) {
        destination[i] = i;
    }
    destination[10] = -1;
    destination[53] = -1;
    destination[0] = -1;

    t.passengers = (struct passenger*)calloc(57, sizeof(passenger));

    initialize_destination(destination, &t);
    for(i=0, flag0=1; i<57; i++){
        if((t.passengers[i].destination == -1)) {
            flag0=0;
        }
        for(j=0; j<57; j++){
            if(i==j)
                j++;
            if (t.passengers[i].destination == t.passengers[j].destination)
                flag0=0;
        }
    }
    free(t.passengers);

    CuAssertTrue(tc, flag0 == 1);
}


/* Tests that the 3 illegal seats dosent becomes a passengers destination, by using 
get_random_array, and noone has the same destination*/
void test_passenger_get_random_destinations_array51_entrance0(CuTest *tc){
    int i, j, flag1=1;
    int destination1[54] = {0};
    transition_system t;
    t.passengers = (struct passenger*)calloc(51, sizeof(passenger));
    t.length = 51;
    t.seats_per_row = 6;
    t.entrance = 0; 
    t.destination_length = 54;

    for(i=0; i<54; i++) {
        destination1[i] = i;
    }

    random_boarding_generator(&t, destination1);

    initialize_destination(destination1, &t);

    for(i=0, flag1=1; i<51; i++) {
        if((t.passengers[i].destination == -1)) {
            flag1=0;
        }
        for(j=0; j<51; j++) {
            if(i==j)
                j++;
            if (j<51 && (t.passengers[i].destination !=-1) && (t.passengers[j].destination !=-1) 
                     && (t.passengers[i].destination == t.passengers[j].destination)){
                flag1=0;
            }
        }        
    }
    CuAssertTrue(tc, flag1 == 1);
    free(t.passengers);
}

/*Tests that the reset array is correct*/
void test_reset_passenger_array(CuTest *tc){
    int i, flag0=1;
    transition_system t;
    t.passengers = (struct passenger*)calloc(57, sizeof(passenger));
    t.length = 57;
    reset_passenger_array(&t);

    for (i = 0, flag0=1; i < 57; i++) {
        if (t.passengers [i].destination !=0)
            flag0=0;
        if (t.passengers [i].location != -1)
            flag0=0;
        if(t.passengers [i].carry_on != 0)
            flag0=0;
        if(t.passengers [i].wait_time != 0)
            flag0=0;
        if(t.passengers [i].finish != 0)
            flag0=0;
        if(t.passengers [i].interference_flag != 0)
            flag0=0;
        if(t.passengers [i].spotting != NULL)
            flag0=0;
    }


    CuAssertTrue(tc, flag0 == 1);
    free(t.passengers);
}

/*tests that the destinations is between the legal seats
  and no to destinations are the same */
void test_get_random_array_array57(CuTest *tc){
    int i, j, flag0=1;
    int destination[60] = {0};
    transition_system t;
    t.seats_per_row = 6;
    t.length = 57;
    t.entrance = 4;
    t.destination_length = 60;

    random_boarding_generator(&t, destination);

    for(i = 0, flag0 = 1; i < 60; i++){
        while(destination[i] == -1){
            i++;
        }
        if(!(destination[i] >= 0 && destination[i] < 60)) {
            flag0 = 0;
        }
            while(destination[i] == -1) {
                i++;
            }
        for(j = 0; j < 60; j++){

            if(i == j){
                j++;
            }
            if ((destination[i] == destination[j]) && destination[i] != -1 && destination[j] != -1){
                flag0 = 0;
            }
        }
    }
    CuAssertTrue(tc, flag0 == 1);
}

/*tests that the destinations is between the legal seats
  and no to destinations are the same */
void test_get_random_array_array15(CuTest *tc){
    int i, j, flag0=1;
    int destination[18] = {0};
    transition_system t;
    t.seats_per_row = 6;
    t.length = 15;
    t.entrance = 4;
    t.destination_length = 18;

    random_boarding_generator(&t, destination);

    for(i = 0, flag0 = 1; i < 18; i++){
        while(destination[i] == -1){
            i++;
        }
        if(!(destination[i] >= 0 && destination[i] < 18)) {
            flag0 = 0;
        }
            while(destination[i] == -1) {
                i++;
            }
        for(j = 0; j < 18; j++){

            if(i == j){
                j++;
            }
            if ((destination[i] == destination[j]) && destination[i] != -1 && destination[j] != -1){
                flag0 = 0;
            }
        }
    }
    CuAssertTrue(tc, flag0 == 1);
}


CuSuite *get_generator_suit(void) { /*Dette skal op i toppen af alltests.c*/
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_get_random_number_80);
    SUITE_ADD_TEST(suite, test_is_legal_seat_E4);
    SUITE_ADD_TEST(suite, test_is_legal_seat_E0);
    SUITE_ADD_TEST(suite, test_get_carryon_A57_CP50);
    SUITE_ADD_TEST(suite, test_get_carryon_A51_CP100);
    SUITE_ADD_TEST(suite, test_get_carryon_A51_CP0);
    SUITE_ADD_TEST(suite, test_initialize_spotting);
    SUITE_ADD_TEST(suite, test_passenger_get_random_destinations_array51_entrance0);
    SUITE_ADD_TEST(suite, test_passenger_get_random_destinations_array57_entrance4);
    SUITE_ADD_TEST(suite, test_reset_passenger_array);
    SUITE_ADD_TEST(suite, test_get_random_array_array15);
    SUITE_ADD_TEST(suite, test_get_random_array_array57);
    SUITE_ADD_TEST(suite, test_get_random_number_15);

    return suite;
}
