#include <stdio.h>
#include <math.h>

/*Dette er en simulering af tallene fra 0 til uendelig*/

int main (void)
{
    int n;
    n=0;
start:
    printf("%d\n", n);
    n=n+1;
    goto start;




    return(0);
}