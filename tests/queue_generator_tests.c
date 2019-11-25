#include "../headers/CuTest.h"
#include "../headers/queue.generator.h"
#include <stdlib.h>
#include <stdio.h>

void testget_random_number(CuTest *tc) {
    int k, j, i;
    
    for (i = 0; i < 100; ++i) {
        get_random_number(&k, &j, 80);
        CuAssertTrue(tc, (k >= 0) && (k < 83));
        CuAssertTrue(tc, (j >= 0) && (j < 83));
    }
    for (i = 0; i < 100; ++i) {
        get_random_number(&k, &j, 15);
        CuAssertTrue(tc, (k >= 0) && (k < 18));
        CuAssertTrue(tc, (j >= 0) && (j < 18));
    }
}

void testis_illegal_seat(CuTest *tc) {
    int result, j, i;
    
    for (i = 0, j = 4; i < 3; ++i) {
        result = is_illegal_seat(i, j);
        CuAssertTrue(tc, result-i == 27);
    }
    for (i = 0, j = 0; i < 3; ++i) {
        result = is_illegal_seat(i, j);
        CuAssertTrue(tc, result-i == 3);
    }
}

void test_get_carryon(CuTest *tc) {
    struct passenger *passengers;
    int i, flag0, flag1, flag2;
    passengers = (struct passenger*)calloc(57, sizeof(passenger));

    get_carryon(passengers, 57, 50);
    
    for(i=0, flag0=1; (i<57) && (flag0==1); i++){
        if ((passengers[i].carry_on != 0) && (passengers[i].carry_on !=1))
            flag0=0;
    }
    free(passengers);

    passengers = (struct passenger*)calloc(51, sizeof(passenger));

    get_carryon(passengers, 51, 100);
    for(i=0, flag1=1; (i<51) && (flag1==1); i++){
        if (passengers[i].carry_on !=1)
            flag1=0;
    }    
    free(passengers);

    passengers = (struct passenger*)calloc(51, sizeof(passenger));

    get_carryon(passengers, 51, 0);
    for(i=0, flag2=1; (i<51) && (flag2==1); i++){
        if (passengers[i].carry_on !=0)
            flag2=0;
    }    
    free(passengers);
    CuAssertTrue(tc, flag0 == 1);
    CuAssertTrue(tc, flag1 == 1);
    CuAssertTrue(tc, flag2 == 1);

}

/*Der produceres et passenger array. 
  Der gives destination fra 0 til 57 til passasgerene. 
  Initialize spotting kaldes. 
  Der testes at den forreste kigger på ingen
  Der testes at alle andre passasgere, kigger på den rigtige, 
  ved at tjekke at destinationen på den de kigger på, er korrekt*/
void test_initialize_spotting(CuTest *tc){
    struct passenger *passengers;
    int i, flag0=1, flag1=1;

    passengers = (struct passenger*)calloc(57, sizeof(passenger));

    for (i = 0; i < 57; i++) {
        passengers[i].destination = i;
    }

    initialize_spotting(passengers, 57);

    if(passengers[0].spotting!=NULL)
        flag0=0;

    for(i=1; i < 57; i=i+1) {
        if(passengers[i].spotting->destination != passengers[i-1].destination)
            flag1=0;
    }

    CuAssertTrue(tc, flag0 == 1);
    CuAssertTrue(tc, flag1 == 1);


}


void test_get_random_destinations(CuTest *tc){
    struct passenger *passengers;
    int i, j, flag0=1, flag1=1;
    int destination[60] = {0};
    int destination1[54] = {0};

    for(i=0; i<60; i++){
        destination[i] = i;
    }
    passengers = (struct passenger*)calloc(57, sizeof(passenger));
    passenger_get_random_destinations(destination, passengers, 57, 4);
    for(i=0, flag0=1; i<57; i++){
        if((passengers[i].destination == 27) ||
          (passengers[i].destination == 28) ||
          (passengers[i].destination == 29)){
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

    passengers = (struct passenger*)calloc(51, sizeof(passenger));


    get_random_array(destination1,51);


    passenger_get_random_destinations(destination, passengers, 51, 0);

    for(i=0, flag1=1; i<51; i++){
        if((passengers[i].destination == 3) ||
          (passengers[i].destination == 4) ||
          (passengers[i].destination == 5)){
            flag1=0;
        }
        for(j=0; j<51; j++){
            if(i==j)
                j++;
            if (passengers[i].destination == passengers[j].destination)
                flag1=0;
        }        
    }

    CuAssertTrue(tc, flag0 == 1);
    CuAssertTrue(tc, flag1 == 1);
}

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


void test_get_random_array(CuTest *tc){
    int i, j, flag0=1, flag1=0;
    int destination[60] = {0};
    int destination1[18] = {0};

    get_random_array(destination, 57);

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

    get_random_array(destination1, 15);

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

    CuAssertTrue(tc, flag0 == 1);
    CuAssertTrue(tc, flag1 == 1);

}



CuSuite *get_generator_suit(void) { /*Dette skal op i toppen af alltests.c*/
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, testget_random_number);
    SUITE_ADD_TEST(suite, testis_illegal_seat);
    SUITE_ADD_TEST(suite, test_get_carryon);
    SUITE_ADD_TEST(suite, test_initialize_spotting);
    SUITE_ADD_TEST(suite, test_get_random_destinations);
    SUITE_ADD_TEST(suite, test_reset_passenger_array);
    SUITE_ADD_TEST(suite, test_get_random_array);


    return suite;
}
