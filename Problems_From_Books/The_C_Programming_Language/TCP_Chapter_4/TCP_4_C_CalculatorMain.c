#include "TCP_4_B_CalculatorBase.h"

void main()
{
    char s[100];
    readSingleLine(s);

    double result = calculator(s);
    printf("\n%f\n",result);
}