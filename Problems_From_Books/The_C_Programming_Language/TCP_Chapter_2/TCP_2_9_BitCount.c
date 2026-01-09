#include "../TCP_reuse.h"

int bitCount(unsigned int d)
{
    // As mentioned in the book, d &= (d-1) simply removes the rightmost one bit from d (remember why?)
    // we simply remove bits until there's none left! then we return the amount of times we had to remove.

    // This assumes that d isn't 0, so we put a special check for that:
    if(d == 0) {return 0;};

    int i;
    for(i = 1; (d &= (d-1)) != 0; i++);
    return i;
}

void main()
{
    unsigned int d = 444;
    int b = bitCount(d);

    printf("The number %d, contains %d ones.\nIn binary it looks like this: ",d,b);
    printBinary(d);
}
