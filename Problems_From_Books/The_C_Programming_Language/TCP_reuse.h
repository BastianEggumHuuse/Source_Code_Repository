#include <stdio.h>
#include <math.h>

int readSingleLine(char s[])
{
    // We read a line into s, and return it's length
    // We assume that enough memory is allocated for s.

    char c;
    int l;

    for(l = 0; (c = getchar()) != '\n'; l++)
    {
        s[l] = c;
    }

    return l;
}

void writeStringWithLength(char s[], int l)
{
    // writes a single string, with length l. (note how it doesn't check for the \0 escape sequence)
    for(int i = 0; i < l; i++)
    {
        putchar(s[i]);
    }
}

void writeString(char s[])
{
    // Writes a single string, by checking for the \0 escape sequence
    for(int i = 0; s[i] != '\0'; i++)
    {
        putchar(s[i]);
    }
}

int hexCharToDecInt(char c)
{
    // converts a single char in hex format into it's corresponding decimal integer
    // note that it's no longer in the ascii format, but simply an integer when returned
    // (the returned integer is obviously in decimal)

    if(c >= '0' && c <= '9')
    {
        // Operate Normally
        return(c - '0');
    }
    if(c >= 'A' && c <= 'F')
    {
        // Remove 7, which removes all the elements between 9 and A
        return(c - 7 - '0');
    }

    printf("\n");
    putchar(c);
    printf(" is not a hex character!!!\n");

    return c;
}

int charInString(char c, char s[])
{
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == c)
        {
            return 1;
        }
    }

    return 0;
}
    
int decToBinaryString(int d,char s[])   
{
    // Firstly, find the amount of bits that are active.
    int numBits;
    for(numBits = 0; pow(2.0,numBits) - 1 <= d; numBits++);
    
    // Creating a number which in binary is simply a 1 followed by numBits - 1 zeros.
    int comparison = pow(2.0,numBits) - pow(2.0,numBits - 1);

    // we assume that s has the amount of memory necessary.
    int i;
    for(i = 0; i < numBits; i++) 
    {
        /* Ok so this is some bit manipulation magic. We shift the bits to the left i times
        which means that the bit in position number numBits (counted from the right) will be bit number
        i (counted from the left). We will call this element i.
        We then use the & operator on this number and our comparison integer, which will return 0 if bit i
        is 0, and comparison if bit i is 1 (all bits are compared, and set to 1 if they match,
        and the only bit that is set to 1 in comparison is the bit on position number numBits)
        we then finally divide by comparison, to get 1 or 0, and put that char in the array. */

        // Since we check the bits from the right, to the left, we can add them in the order we check them!
        s[i] = '0' + ((d << i) & comparison)/comparison;
    }

    s[i] = '\0';

    return numBits;
}

void printBinary(int d)
{
    char s[100];
    decToBinaryString(d,s);
    writeString(s);
    printf("\n");
}