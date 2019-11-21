#include "../headers/CuTest.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

CuSuite* get_example_suit(void); 
CuSuite *get_initialization_suit(void);


int runalltest(void)
{
    CuString *output = CuStringNew();
    CuSuite *suite   = CuSuiteNew();

    CuSuiteAddSuite(suite, get_example_suit());
    CuSuiteAddSuite(suite, get_initialization_suit());

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

