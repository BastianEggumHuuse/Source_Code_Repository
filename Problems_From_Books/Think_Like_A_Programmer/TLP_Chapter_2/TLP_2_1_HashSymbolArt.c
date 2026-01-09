#include <stdio.h>

#define PRINTHASH putchar('#')
#define PRINTSPACE putchar(' ')
#define NEWLINE putchar('\n')

void HashTriangle(int numLines)
{
    for(int i = numLines; i > 0; i--)
    {
        int numSpaces = numLines-i;
        int numHashes = i * 2;
        int n = 0;

        for(n = 0; n < numSpaces; n++)
        {
            PRINTSPACE;
        }
        for(int n = 0; n < numHashes; n++)
        {
            PRINTHASH;
        }
        for(n = 0; n < numSpaces; n++)
        {
            PRINTSPACE;
        }

        NEWLINE;
    }
}

void InvertedHashTriangle(int numLines)
{
    for(int i = 1; i <= numLines; i++)
    {
        int numSpaces = numLines-i;
        int numHashes = i * 2;
        int n = 0;

        for(n = 0; n < numSpaces; n++)
        {
            PRINTSPACE;
        }
        for(int n = 0; n < numHashes; n++)
        {
            PRINTHASH;
        }
        for(n = 0; n < numSpaces; n++)
        {
            PRINTSPACE;
        }

        NEWLINE;
    }
}

void HashDiamond(int numLines)
{
    // We split this operation in two, creating a hashtriangle pointing up
    // and then a hashtriangle pointing down.

    int triangleHeight = numLines/2; //We assume that the number of lines is even.

    InvertedHashTriangle(triangleHeight);
    HashTriangle(triangleHeight);
}

void HashV(int numLines)
{
    for(int i = 1; i <= numLines; i++)   
    {
        int outerSpaces = i-1;
        int innerSpaces = (numLines-i)*2;
        int numHashes   = i;

        int n = 0;

        for(n = 0; n < outerSpaces; n++) {PRINTSPACE;}
        for(n = 0; n < numHashes; n++) {PRINTHASH;}
        for(n = 0; n < innerSpaces; n++) {PRINTSPACE;}

        for(n = 0; n < innerSpaces; n++) {PRINTSPACE;}
        for(n = 0; n < numHashes; n++) {PRINTHASH;}
        for(n = 0; n < outerSpaces; n++) {PRINTSPACE;}
        
        NEWLINE;
    }
}

void InvertedHashV(int numLines)
{
    for(int i = numLines; i > 0; i--)   
    {
        int outerSpaces = i-1;
        int innerSpaces = (numLines-i)*2;
        int numHashes   = i;

        int n = 0;

        for(n = 0; n < outerSpaces; n++) {PRINTSPACE;}
        for(n = 0; n < numHashes; n++) {PRINTHASH;}
        for(n = 0; n < innerSpaces; n++) {PRINTSPACE;}

        for(n = 0; n < innerSpaces; n++) {PRINTSPACE;}
        for(n = 0; n < numHashes; n++) {PRINTHASH;}
        for(n = 0; n < outerSpaces; n++) {PRINTSPACE;}
        
        NEWLINE;
    }
}

void HashCross(int numLines)
{
    // Again, we split this into creating a v, and then a reverse v.

    int vHeight = numLines/2; // Once again, we assume an even number of lines.

    HashV(vHeight);
    InvertedHashV(vHeight);
}

int main()
{
    //HashTriangle(4);

    //InvertedHashTriangle(4);

    //HashDiamond(8);

    HashCross(8);
}