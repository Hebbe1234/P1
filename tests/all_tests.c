#include "../headers/CuTest.h"
#include <stdio.h>

CuSuite* get_example_suit(); 



void runalltest(void)
{
    CuString *output = CuStringNew();
    CuSuite *suite   = CuSuiteNew();

    CuSuiteAddSuite(suite, get_example_suit());

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

