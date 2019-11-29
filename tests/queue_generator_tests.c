#include "../headers/CuTest.h"
#include "../headers/queue.generator.h"
#include <stdlib.h>
#include <stdio.h>

/*Tests that the number generated is between the limits*/
void test_get_random_number_80(CuTest *tc) {
    int k, j, i;
    
    for (i = 0; i < 100; ++i) {
        get_random_number(&k, &j, 80, 6);
        CuAssertTrue(tc, (k >= 0) && (k < 83));
        CuAssertTrue(tc, (j >= 0) && (j < 83));
    }
}

/*Tests that the number generated is between the limits*/
void test_get_random_number_15(CuTest *tc) {
    int k, j, i;
    
    for (i = 0; i < 100; ++i) {
        get_random_number(&k, &j, 15, 6);
        CuAssertTrue(tc, (k >= 0) && (k < 18));
        CuAssertTrue(tc, (j >= 0) && (j < 18));
    }
}
/*Tests that when the entrance is 4 and we tests seat 0, 1, 2 is legal*/
void test_is_legal_seat_E4(CuTest *tc) {
    int result, j, i;
    
    for (i = 0, j = 4; i < 3; ++i) {
        result = is_legal_seat(i, j, 6);
        CuAssertTrue(tc, result==1);
    }
}

/*Tests that when the entrance is 0 and we tests seat 3,4,5 they are illegal*/
void test_is_legal_seat_E0(CuTest *tc) {
   int result, j, i;

   for (i = 3, j = 0; i < 6; ++i) {
        result = is_legal_seat(i, j, 6);
        CuAssertTrue(tc, result == 0);
    }
}

/*Tests that a passenger either gets carry on 1, or 0*/
void test_get_carryon_A57_CP50(CuTest *tc) {
    struct passenger *passengers;
    int i, flag0;
    passengers = (struct passenger*)calloc(57, sizeof(passenger));

    get_carryon(passengers, 57, 50);
    
    for(i=0, flag0=1; (i<57) && (flag0==1); i++) {
        if ((passengers[i].carry_on != 0) && (passengers[i].carry_on !=1))
            flag0=0;
    }
    free(passengers);
    CuAssertTrue(tc, flag0 == 1);
}

/*Tests that when carryon percentage is 100, everyone has carryon*/
void test_get_carryon_A51_CP100(CuTest *tc) {
    struct passenger *passengers;
    int i, flag1;

    passengers = (struct passenger*)calloc(51, sizeof(passenger));

    get_carryon(passengers, 51, 100);
    for(i=0, flag1=1; (i<51) && (flag1==1); i++) {
        if (passengers[i].carry_on !=1)
            flag1=0;
    }    
    free(passengers);

    CuAssertTrue(tc, flag1 == 1);
}

/*Tests that when carryon percentage is 0, noone has carryon*/
void test_get_carryon_A51_CP0(CuTest *tc) {
    struct passenger *passengers;
    int i, flag2;

    passengers = (struct passenger*)calloc(51, sizeof(passenger));

    get_carryon(passengers, 51, 0);
    for(i=0, flag2=1; (i<51) && (flag2==1); i++) {
        if (passengers[i].carry_on !=0)
            flag2=0;
    }    
    free(passengers);

    CuAssertTrue(tc, flag2 == 1);
}


/*Der produceres et passenger array. 
  Der gives destination fra 0 til 57 til passasgerene. 
  Initialize spotting kaldes. 
  Der testes at den forreste kigger på ingen
  Der testes at alle andre passasgere, kigger på den rigtige, 
  ved at tjekke at destinationen på den de kigger på, er korrekt*/
void test_initialize_spotting(CuTest *tc) {
    struct passenger *passengers;
    int i, flag1=1;

    passengers = (struct passenger*)calloc(57, sizeof(passenger));

    for (i = 0; i < 57; i++) {
        passengers[i].destination = i;
    }

    initialize_spotting(passengers, 57);

    if(passengers[0].spotting!=NULL)
        flag1=0;

    for(i=1; i < 57; i=i+1) {
        if(passengers[i].spotting->destination != passengers[i-1].destination)
            flag1=0;
    }

    CuAssertTrue(tc, flag1 == 1);
}

/* Tests that the 3 illegal seats dosent becomes a passengers destination*/
/*And noone has the same destination*/
void test_passenger_get_random_destinations_array57_entrance4(CuTest *tc) {
    struct passenger *passengers;
    int i, j, flag0 = 1;
    int destination[60] = {0};

    for(i=0; i<60; i++) {
        destination[i] = i;
    }
    destination[10] = -1;
    destination[53] = -1;
    destination[0] = -1;

    passengers = (struct passenger*)calloc(57, sizeof(passenger));

    passenger_get_random_destinations(destination, passengers, 57, 4, 6);
    for(i=0, flag0=1; i<57; i++){
        if((passengers[i].destination == -1)) {
            flag0=0;
        }
        for(j=0; j<57; j++){
            if(i==j)
                j++;
            if (passengers[i].destination == passengers[j].destination)
                flag0=0;
        }
    }
    free(passengers);

    CuAssertTrue(tc, flag0 == 1);
}


/* Tests that the 3 illegal seats dosent becomes a passengers destination, by using 
get_random_array, and noone has the same destination*/
void test_passenger_get_random_destinations_array51_entrance0(CuTest *tc){
    struct passenger *passengers;
    int i, j, flag1=1;
    int destination1[54] = {0};

    passengers = (struct passenger*)calloc(51, sizeof(passenger));

    for(i=0; i<54; i++) {
        destination1[i] = i;
    }

    get_random_array(destination1,51, 6, 0);

    passenger_get_random_destinations(destination1, passengers, 51, 0, 6);

    for(i=0, flag1=1; i<51; i++) {
        if((passengers[i].destination == -1)) {
            flag1=0;
        }
        for(j=0; j<51; j++) {
            if(i==j)
                j++;
            if (j<51 && (passengers[i].destination !=-1) && (passengers[j].destination !=-1) 
                     && (passengers[i].destination == passengers[j].destination)){
                flag1=0;
            }
        }        
    }
    CuAssertTrue(tc, flag1 == 1);
}

/*Tests that the reset array is correct*/
void test_reset_passenger_array(CuTest *tc){

    struct passenger *passengers;
    int i, flag0=1;

    passengers = (struct passenger*)calloc(57, sizeof(passenger));

    reset_passenger_array(passengers, 57);

    for (i = 0, flag0=1; i < 57; i++) {
        if (passengers [i].destination !=0)
            flag0=0;
        if (passengers [i].location != -1)
            flag0=0;
        if(passengers [i].carry_on != 0)
            flag0=0;
        if(passengers [i].wait_time != 0)
            flag0=0;
        if(passengers [i].finish != 0)
            flag0=0;
        if(passengers [i].interference_flag != 0)
            flag0=0;
        if(passengers [i].spotting != NULL)
            flag0=0;
    }


    CuAssertTrue(tc, flag0 == 1);
}

/*tests that the destinations is between the legal seats
  and no to destinations are the same */
void test_get_random_array_array57(CuTest *tc){
    int i, j, flag0;
    int destination[60] = {0};

    get_random_array(destination, 57,6, 4);

    for(i=0, flag0=1; i<60; i++){
        if(!(destination[i]>=0 && destination[i]<60))
            flag0=0;

        for(j=0; j<60; j++){
            if(i==j)
                j++;
            if (destination[i] == destination[j])
                flag0=0;
        }
    }

    CuAssertTrue(tc, flag0 == 1);
}

/*tests that the destinations is between the legal seats
  and no to destinations are the same */
void test_get_random_array_array15(CuTest *tc){
    int i, j, flag1;
    int destination1[18] = {0};

    get_random_array(destination1, 15, 6, 4);

    for(i=0, flag1=1; i<18; i++){
        if(!(destination1[i]>=0 && destination1[i]<18))
            flag1=0;
        for(j=0; j<18; j++){
            if(i==j)
                j++;
            if (destination1[i] == destination1[j])
                flag1=0;
        }
    }
    CuAssertTrue(tc, flag1 == 1);
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
