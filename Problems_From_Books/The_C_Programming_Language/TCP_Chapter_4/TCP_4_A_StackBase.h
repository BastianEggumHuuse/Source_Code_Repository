#include "../TCP_reuse.h"

#define MAXSTACKSIZE 1000

// We want to simulate a stack! 
double stack[MAXSTACKSIZE];
int stackPos = -1;

// Function for pushing
void pushToStack(double element)
{
    if(stackPos < MAXSTACKSIZE)
    {
        stack[++stackPos] = element; 
    }
}

// Function for popping
double popFromStack()
{
    if(stackPos < 0)
    {
        printf("\nTHE STACK IS EMPTY!!!\n");
        return 0;
    }

    double element = stack[stackPos];
    stack[stackPos--] = 0;
    return element;
}

void printStack()
{
    printf("\nPrinting stack: [");

    for(int i = 0; i < stackPos; i++)
    {
        printf("%f, ",stack[i]);
    }

    printf("%f]",stack[stackPos]);
}