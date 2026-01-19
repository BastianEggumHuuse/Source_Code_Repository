#include "../TCP_reuse.h"

void concat(char* s, char* t)
{
    // Assume that s has the space to fit the entirity of t.

    // Incrementing s until we find the it's final element ('\0')
    while(*s)
    {
        s++;
    }

    // Setting *s equal to *t until they're both 0.
    for(;*s = *t;s++,t++);
}

void main()
{
    char s[100];
    strcpy(s,"Hello");
    char* t = " World!";

    concat(s,t);

    writeString(s);
}