#include "../TCP_reuse.h"

#define DASHCHAR '-'

int expand(char s[], char t[])
{
    // We want to expand all situations where we have a string like
    // a-d. We also want to allow -e, and a-e-h, and a-h0-4.

    // We want to allow a-z, A-Z, and 0-9.

    int i;
    int j; 
    
    char firstChar;
    char lastChar;
    
    for(i = j = 0; s[i] != '\0'; i++)
    {
        if(s[i] == DASHCHAR)
        {
            // We have found a dash! If there is no previous or next character, we simply skip this one 
            if(i == 0 || s[i+1] == '\0')
            {
                continue;  
            }

            firstChar = s[i-1];
            lastChar  = s[i+1];

            // Remember that chars are just numbers!
            for(char c = firstChar + 1; c < lastChar; c++)
            {
                t[j++] = c;
            }
        }
        else
        {
            // We want to add all non - characters.
            t[j++] = s[i];
        }
    }

    // Finishing the string
    t[j] = '\0';
    // Returning the length of the expanded array
    return j;
}

void main()
{
    char s[] = "a-e 0-9 A-E";
    char t[100];

    expand(s,t);

    printf("\nUnexpanded:\n");
    writeString(s);
    printf("\nExpanded  :\n");
    writeString(t);
    printf("\n ");
}