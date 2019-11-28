#include "../headers/CuTest.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

CuSuite *get_example_suit(void); 
CuSuite *get_initialization_suit(void);
CuSuite *get_generator_suit(void);
CuSuite *get_finished_suit(void);
CuSuite *get_finalizing_suit(void);
CuSuite *get_movement_suit(void);
CuSuite *get_person_in_front(void);
CuSuite *get_test_t_system(void);

int runalltest(void)
{
    CuString *output = CuStringNew();
    CuSuite *suite   = CuSuiteNew();

    CuSuiteAddSuite(suite, get_example_suit());
    CuSuiteAddSuite(suite, get_initialization_suit());
    CuSuiteAddSuite(suite, get_generator_suit());
    CuSuiteAddSuite(suite, get_finalizing_suit());
    CuSuiteAddSuite(suite, get_movement_suit());/*
    CuSuiteAddSuite(suite, get_person_in_front());*//*
    CuSuiteAddSuite(suite, get_test_t_system());*/


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

