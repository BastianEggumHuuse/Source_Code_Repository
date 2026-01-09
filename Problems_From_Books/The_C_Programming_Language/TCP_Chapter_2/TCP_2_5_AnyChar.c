#include "../TCP_reuse.h"

int any(char s1[], char s2[])
{
    int i;
    for(i = 0; !charInString(s1[i],s2); i++);
    return i;
}

void main()
{
    char s1[] = "Hello world!";
    char s2[] = "Jump_far_Jay!";

    int pos = any(s1,s2);
    printf("A shared character is found at position %d",pos);
}