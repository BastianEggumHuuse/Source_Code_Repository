#include <stdio.h>

int readChar(int number)
{
    if(number > '@')
    {
        return(number - 7 - '0');
    }
    else
    {
        return(number - '0');
    }
}

int readNumber(int base)
{
    int currentChar = 0;
    int currentDig  = 0;
    int num         = 0;

    while((currentChar = getchar()) != '\n')
    {
        currentDig  = readChar(currentChar);
        num         = (num * base) + currentDig;
    }

    printf("\n");
    return num;
}

void writeChar(int number)
{
    if(number > 9)
    {
        putchar('0' + 7 + number);
    }
    else
    {
        putchar('0' + number);
    }
}

int writeRecursively(int base, int number)
{
    if(number < base)
    {
        putchar('0' + number);
        return(1);
    }

    int currentDigit = number % base;
    int numDigits = writeRecursively(base, (number - currentDigit) / base) + 1;

    // We call the method recursively, before printing the character.
    // This lets us print the characters with the highest digit first!
    writeChar(currentDigit);

    return numDigits;
}

void writeNumber(int base, int number)
{
    // Because of how we've already written readNumber, we can assume that number
    // is in base 10.

    int numDigits = writeRecursively(base,number);
    printf("\nWhich has %d digits.\n",numDigits);
    
}

void main()
{
    printf("Enter an input base between 1 and 16: ");
    int inputBase = readNumber(10);
    
    printf("Enter a number in base %d: ",inputBase);
    int inputNumber = readNumber(inputBase);

    printf("Enter an output base between 1 and 16: ");
    int outputBase = readNumber(10);

    writeNumber(outputBase,inputNumber);
}