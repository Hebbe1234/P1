#include "../headers/CuTest.h"
#include <stdio.h>

CuSuite* get_example_suit(void); 
CuSuite *get_initialization_suit(void);
CuSuite *get_finalizing_suit(void);



void runalltest(void)
{
    CuString *output = CuStringNew();
    CuSuite *suite   = CuSuiteNew();

    CuSuiteAddSuite(suite, get_example_suit());
    CuSuiteAddSuite(suite, get_initialization_suit());
    CuSuiteAddSuite(suite, get_finalizing_suit());


    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}

int main(void)
{
    runalltest();
    return(0);
}

