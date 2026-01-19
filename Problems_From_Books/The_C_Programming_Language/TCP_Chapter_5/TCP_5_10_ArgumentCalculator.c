#include "../TCP_Chapter_4/TCP_4_B_CalculatorBase.h"

#define MAXLENGTH 1000

int main(int argc, char* argv[])
{
    if(argc <= 1)
    {
        printf("Please submit at least three operands and operations");
    }

    char* s = malloc(sizeof(char) * MAXLENGTH);

    // Let's format these arguments into a string, separated by whitespace.
    int s_i = 0;
    for(int i = 1; i < argc; i++)
    {
        // We loop through pointers.
        for(int j = 0; *(argv[i] + j) != '\0'; j++)    
        {
            *(s + s_i++) = *(argv[i] + j);
        }
        *(s + s_i++) = (' ');
    }
    *(s + s_i - 1) = '\0';

    // The rest is the same as before :)
    double result = calculator(s);
    printf("\nResult: %f\n",result);
}