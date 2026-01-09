#include <stdio.h>
#include "../TCP_reuse.h" // Here we learn something new! It's probably mentioned somewhere in the book tho...

int htoi(char s[], int l)
{
    // We do the same trick we have done earlier, by multiplying by 16 every
    // time we add another number to the integer. We will also have to read the numbers
    // differently, like we did for that one TLP problem.

    int result = 0;
    for(int i = 0; i < l; i++)
    {
        result = result * 16 + hexCharToDecInt(s[i]);
    }

    return result;
}

void main()
{
    char s[100];
    int l = readSingleLine(s);

    int decInt = htoi(s,l);
    printf("\nThe decimal variant of ");
    writeString(s);
    printf(" is %d\n",decInt);
}