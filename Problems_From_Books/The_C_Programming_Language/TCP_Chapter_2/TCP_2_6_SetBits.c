#include "../TCP_reuse.h"

int setBits(int x,int p,int n,int y)
{
    // firstly, isolate the n rightmost bits of y:
    y = y & (int)pow(2,n) - 1;
    // Then, shift these p spots to the left, to line them up with where we want them in x
    y = y << p-1;

    // Now, let's isolate everything but the bits we want to replace in x:
    x = x & ~((int)pow(2,n)-1 << p-1);

    // Finally, we simply add the two together:
    return x += y;
}

void main()
{
    int p = 2; int n = 3;

    int d1 = 36;
    int d2 = 43;
    int d3 = setBits(d1,p,n,d2);

    printf("\n Combining numbers with p = %d, and n = %d",p,n);

    char s[10];
    // First number:
    printf("\n first number    | DEC: %d, BIN: ",d1);
    decToBinaryString(d1,s);
    writeString(s);
    
    printf("\n second number   | DEC: %d, BIN: ",d2);
    decToBinaryString(d2,s);
    writeString(s);

    printf("\n combined number | DEC: %d, BIN: ",d3);
    decToBinaryString(d3,s);
    writeString(s);
}