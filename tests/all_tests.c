#include "../headers/CuTest.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

CuSuite *get_example_suit(void); 
CuSuite *get_initialization_suit(void);
CuSuite *get_generator_suit(void);
CuSuite *get_finished_suit(void);
CuSuite *get_finalizing_suit(void);
CuSuite *get_rear_suit(void);
CuSuite *get_movement_suit(void);
CuSuite *get_person_in_front(void);
CuSuite *get_wait_time_suit(void);
CuSuite *get_test_t_system(void);
CuSuite *get_inter_suit(void);
CuSuite *get_interference_suit(void);
CuSuite *get_carry_on_suite(void);
CuSuite *get_simulation_suite(void);
CuSuite *get_outside_in_suite(void);

int silence = 0;

int runalltest(void)
{
    CuString *output = CuStringNew();
    CuSuite *suite   = CuSuiteNew();

    CuSuiteAddSuite(suite, get_example_suit());
    CuSuiteAddSuite(suite, get_initialization_suit());
    CuSuiteAddSuite(suite, get_generator_suit());
    CuSuiteAddSuite(suite, get_finished_suit());
    CuSuiteAddSuite(suite, get_finalizing_suit());
    CuSuiteAddSuite(suite, get_movement_suit()); 
    CuSuiteAddSuite(suite, get_person_in_front());
    CuSuiteAddSuite(suite, get_wait_time_suit()); 
    CuSuiteAddSuite(suite, get_rear_suit());
    CuSuiteAddSuite(suite, get_person_in_front());
    CuSuiteAddSuite(suite, get_test_t_system());
    CuSuiteAddSuite(suite, get_inter_suit());
    CuSuiteAddSuite(suite, get_interference_suit());
    CuSuiteAddSuite(suite, get_carry_on_suite());
    CuSuiteAddSuite(suite, get_simulation_suite());
    CuSuiteAddSuite(suite, get_outside_in_suite());
    

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);

    if (strstr(output->buffer, "!!!FAILURES!!!") != NULL) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int main(void)
{
    return runalltest();
}

