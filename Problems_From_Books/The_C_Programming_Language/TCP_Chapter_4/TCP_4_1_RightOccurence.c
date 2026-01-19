#include "../TCP_reuse.h"

int strindex(char s[],char t[])
{
    int i;
    int j;
    int currentRightIndex;
    int rightIndex = -1;
    for(i = j = 0; s[i] != '\0'; i++)
    {
        // Checking if the entries match
        if(s[i] == t[j])
        {
            // Checking if it's the first char of t, at which point we temporarily store the index:
            if(j == 0) {currentRightIndex = i;} 
            // Checking if it's the final char of t, at which point we have found an occurence
            if(t[++j] == '\0') {rightIndex = currentRightIndex; j = 0;}
            // Note that this can happen more than once, so we will find the final occurance,
            // which is the rightmost one
        }
    }

    // Note that this could also have been done with an array to find all occurences, or we could loop backwards
    // if we knew the lenght of s and t (which we do most of the time)
    return rightIndex;
}

void main()
{
    char s[] = "Hello Hello Hello!!!";
    char t[] = "Hello";

    // Expected output is 12, which is the final H
    int rightIndex = strindex(s,t);
    printf("The rightmost occurence begins at index %d",rightIndex);
}