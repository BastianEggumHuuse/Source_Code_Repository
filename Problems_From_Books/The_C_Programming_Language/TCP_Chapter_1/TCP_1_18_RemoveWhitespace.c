#include <stdio.h>

// This is a solution to problem 1-18 in TCP

# define MAX 1000

int isText(int character)
{
    if('!' < character && character < '}')
    {
        return 1;
    }
    return 0;
}

void main()
{
    // Initializing arrays
    int word[MAX];
    for(int i = 0; i < MAX; i++) {word[i] = 0;};

    // Reading a line
    int c = 0;
    for(int i = 0; (c = getchar()) != '\n'; i++)
    {
        word[i] = c;
    }

    // We now have a word! Time to remove whitespace 

    // The state represents what we are currently doing.
    // 0 is searching for the beginning of the line, 1 is reading regular text,
    // 2 is in a space (either in the middle or at the end of the line)
    int state = 0;
    // I use the word Words below even tho i mean character (whoops)
    int totalWords = 0;
    int gapWords   = 0;
    for(int i = 0; word[i] != 0; i++)
    {
        if(state == 0)
        {
            if(isText(word[i]) == 1)
            {
                state = 1;
                totalWords += 1;
            }
        }
        else if (state == 1)
        {
            if(isText(word[i]) == 0)
            {
                state = 2;
                gapWords += 1;
            }
            else
            {
                totalWords += 1;
            }
        }
        else if (state == 2)
        {
            if(isText(word[i]) == 1)
            {
                state = 1;
                totalWords += gapWords + 1;
                gapWords = 0;
            }
            else
            {
                gapWords += 1;
            }
            
        }
    }

    int wordNoWhitespace[totalWords];
    for(int i = 0; i < totalWords; i++) {wordNoWhitespace[i] = 0;};
    
    int charactersCounted = 0;
    state = 0;
    for(int i = 0; charactersCounted < totalWords; i++)
    {
        if(state == 0)
        {
            if(isText(word[i]) == 1)
            {
                state = 1;
            }
        }
        if(state == 1)
        {
            wordNoWhitespace[charactersCounted] = word[i];
            charactersCounted++;
        }
    } 

    // We should now hopefully have a finished trimmed word.
    printf("\n");
    for(int i = 0; i < totalWords; i++)
    {
        putchar(wordNoWhitespace[i]);
    }
    printf("\n");
}