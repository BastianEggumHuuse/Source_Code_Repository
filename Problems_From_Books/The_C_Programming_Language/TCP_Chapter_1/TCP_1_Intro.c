// Including other files at the top of this one
// This file is a standard library IO header
#include <stdio.h>

// Symbolic names / constants
#define NAME "Bastian"
#define AGE 20
#define FUNCTION printf(NAME); printf("\n")


void HelloWorld()
{
    printf("\"");
    printf("Hello world!");
    printf("\"\n");
}

int Add(int a, int b)
{
    int c = a + b;

    return c;
}

void ForLoop(float low, float high, float step)
{
    for(float iter = low; iter <= high; iter += step)
    {
        printf("%.2f\n",iter);
    }
}

void CopyText(int Num)
{
    for(int iter = 0; iter < Num; iter += 1)
    {
        int c = getchar();

        while(c == 10)
        {
            c = getchar();
        }
        putchar(c);
        printf("\n");
    }
}

int CountLetters()
{
    // Very naive letter counting function
    // Will also count escape sequences like \n, giving a very strange result
    // (the result is completely accurate tho...)
    int lettercount = 0;

    for(lettercount = 0; getchar() != EOF; ++lettercount);

    return lettercount;
}

void CountLines()
{
    // Slightly less naive line (and letter) counting function.

    // Variables counting letters and lines 
    int letterCount = 0;
    int lineCount   = 0;

    // Variable containing the current character
    int c = 0;

    while((c = getchar()) != EOF)
    {
        if(c == '\n')
        {
            lineCount += 1;
        }
        else
        {
            letterCount += 1;
        }
    }

    printf("We've observed %d letters\n",letterCount);
    printf("Spread over %d lines.",lineCount);
}



void main()
{
    // Comments!
    HelloWorld();

    int sum = Add(2,2);
    printf("%d\n",sum);

    ForLoop(0.0,1.1,0.1);

    printf(NAME);
    printf("\n");
    FUNCTION;

    //CopyText(5);
    //printf("Amount of characters : %d",CountLetters());
    CountLines();
}