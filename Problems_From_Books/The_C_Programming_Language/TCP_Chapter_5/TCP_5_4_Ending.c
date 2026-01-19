#include "../TCP_reuse.h"

int strend(char* s, char* t)
{
    // We're gonna do a loop
    for(char* ps = s; *ps; ps++)
    {
        if(*ps != *t) {continue;}
        
        // And then we're gonna do another loop 
        for(char* pt = t; (*ps == *pt); ps++,pt++)
        {
            if(!(*pt))
            {
                return 1;
            }
        }
    }

    return 0;
}

void main()
{
    char s[] = "Hello world!!";
    char t[] = "world!!";

    char b[100];
    strcpy(b, (strend(s,t) ? "true" : "false"));
    printf("%s",b);
}