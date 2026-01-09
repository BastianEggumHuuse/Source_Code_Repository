#include <stdio.h>

// This is a solution to problem 1-19 in TCP

#define MAXLINELENGTH 1000

int ReadSingleLine(char String[])
{
    // Filling the array with zeros
    for(int i = 0; i < MAXLINELENGTH; i++)
    {
        String[i] = 0;
    }

    // Printing input message
    printf("Please enter a string:\n> ");

    // Reading
    int charCount;
    char c;
    for(charCount = 0; (c = getchar()) != '\n'; charCount++)
    {
        String[charCount] = c;
    }

    return charCount;
}

void CopyString(char From[], char To[], int Length)
{
    // This function assumes both arrays can fit everything
    for(int i = 0; i < Length; i++)
    {
        To[i] = From[i];
    }
}

void PrintSingleLine(char String[],int Length)
{
    printf("\nPrinting string:\n");
    for(int i = 0; i < Length; i++)
    {
        putchar(String[i]);
    }
}

void ReverseCharString(char String[],char Target[],int Length)
{
    // We assume that String and Target are both of length Length

    // Finding the last index we want to see. This is the floored half index.
    // We are gonna use the basic reversal algorithm here. We swap elements with an
    // element from the other side of the array.
    int maxIndex = (Length / 2); // Turns out dividing ints truncates toward 0! for positive numbers it floors :)

    for(int i = 0; i < maxIndex; ++i)
    {
        Target[i] = String[Length - 1 - i];
        Target[Length - 1 - i] = String[i];
    }

    // If there is an odd number of characters, we also want to move the middle element
    if(Length % 2 == 1)
    {
        Target[maxIndex] = String[maxIndex];
    }
}

void main()
{
    char String[MAXLINELENGTH];
    // Using a trick from the book. Since arrays are just pointers, we can generate an array
    // using a function even though we can't return arrays. We simply pass an array in, and then edit it!
    int StringLength = ReadSingleLine(String);
    // Cutting the array down to a more apropriate size
    char CutString[StringLength];
    CopyString(String,CutString,StringLength);

    // Printing regular string
    PrintSingleLine(CutString,StringLength);

    // Reversing the string, again using the same trick as above
    char ReversedString[StringLength];
    ReverseCharString(String,ReversedString,StringLength);

    //Printing reversed string
    printf("\n");
    PrintSingleLine(ReversedString,StringLength);
}