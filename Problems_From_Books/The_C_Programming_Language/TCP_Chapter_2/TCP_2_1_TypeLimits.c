#include <stdio.h>
#include <limits.h>
#include <float.h>

void PrintLimitsHeader()
{
    printf("\nLimits harvested from stdlib headers: \n");
    printf("char limits : %d to %d\n",CHAR_MIN,CHAR_MAX);
    printf("int limits : %d to %d\n",INT_MIN,INT_MAX);
    printf("float limits : %f to %f\n",FLT_MIN,FLT_MAX);
    printf("double limits : %lf to %lf\n",DBL_MIN,DBL_MAX);
    printf("\n");
}

void main()
{
    PrintLimitsHeader();
}