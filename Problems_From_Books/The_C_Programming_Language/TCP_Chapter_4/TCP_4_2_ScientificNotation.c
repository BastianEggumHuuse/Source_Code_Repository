#include "../TCP_reuse.h"

int isNumber(char c)
{
    return ('0' <= c && c <= '9');
}

double stringToFloat(char s[])
{
    double mantissa = 0.0;
    double exponent = 0.0;
    double sign;
    
    // We will abuse the fact that numbers using scientific notation only have two separators:
    // the dot, which separates the int from the fraction, and the e, which separates the
    // mantissa from the exponent. We will therefore perform this function in three parts,
    // one for each side of the separators. First we do the int:

    // our iterators
    int i;
    int j;

    // Repeat until we get a char that isn't a number 
    for(i = 0; isNumber(s[i]); i++)
    {
        mantissa = mantissa * 10 + s[i] - '0';
    }
    i++; // Move away from the dot :)

    // We now have the int portion. time to add the fraction

    // Repeat until we get a char that isn't a number 
    for(j = i; isNumber(s[j]); j++)
    {
        mantissa += (float)(s[j] - '0') * pow(10.0,-1*(j-i+1));
    }
    j++;

    // We now also have the fraction. Time to add the exponent
    // s[j] is now either a number, or the sign.
    sign = isNumber(s[j]) ? -1.0 : 1.0;

    // Repeat until we get a char that isn't a number 
    for(j; isNumber(s[j]); j++)
    {
        exponent = exponent * 10 + s[j] - '0';
    }

    // Calculating the final result
    return mantissa * pow(10.0,exponent);
}

void main()
{
    char s[] = "104.34e3";

    double number = stringToFloat(s);
    printf("%f",number);
}