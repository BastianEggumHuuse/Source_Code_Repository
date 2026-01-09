#include <stdio.h>

// This is a soloution to problem 1-13 in TCP

void horizontalHistogram(int array[])
{
    // Note that we are passing a pointer here!!!
    // This modifies the existing array

    for(int i = 0; i < 10; i++)
    {
        printf("\n%d |",i);

        for(int j = 0; j < array[i]; j++)
        {
            printf("[]");
        }
    }
}

void verticalHistogram(int array[],int arraySize)
{
    // First we find the greatest element in the array:
    int greatest = 0;
    for(int i = 0; i < arraySize; i++)
    {
        if(array[i] > greatest)
        {
            greatest = array[i];
        }
    }

    // Now we loop from this number down to zero.
    for(int i = greatest; i > 0; i--)
    {
        for(int j = 0; j < arraySize; j++)
        {
            if(array[j] >= i)
            {
                printf("[ ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }

    for(int i = 0; i < arraySize; i++)
    {
        printf("--");
    }
    printf("\n");
    for(int i = 0; i < arraySize; i++)
    {
        printf("%d|",i);
    }
}

void main()
{

    int c = 0;
    int wordLenghts[10];
    int lengthOfCurrentWord = 0;

    for(int i = 0; i < 10; i++)
    {
        wordLenghts[i] = 0;
    }

    while((c = getchar()) != '\n')
    {
        if(c == ' ')
        {
            wordLenghts[lengthOfCurrentWord] += 1;
            lengthOfCurrentWord = 0;
        }
        else
        {
            lengthOfCurrentWord += 1;
        }
    }
    wordLenghts[lengthOfCurrentWord] += 1;

    //horizontalHistogram(wordLenghts);
    verticalHistogram(wordLenghts,10);
}