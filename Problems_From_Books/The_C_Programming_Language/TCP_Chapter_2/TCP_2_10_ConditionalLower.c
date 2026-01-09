#include "../TCP_reuse.h"

#define CASEDIFF 'a' - 'A'

void lower(char s[])
{
    // We loop over all characters in s, and check if they are uppercase
    for(int i = 0; s[i] != '\0'; i++)
    {
        // We use a conditional to check if it's uppercase, and what to change it to.
        s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] + CASEDIFF : s[i];
    }
}

void main()
{
    char s[] = "Hello World!";

    lower(s);
    writeString(s);
}