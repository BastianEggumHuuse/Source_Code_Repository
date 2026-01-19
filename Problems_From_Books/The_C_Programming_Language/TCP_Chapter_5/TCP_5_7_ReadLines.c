#include "../TCP_reuse.h"

#define LONGESTLINE 100

// Used for escaping when quitting;
char null[0];

char* readLine()
{
    // Ok i am super out of my depth here
    char* line = malloc(LONGESTLINE * sizeof(char));

    int i;
    for(i = 0; (i < LONGESTLINE) && ((line[i] = getchar()) != '\n'); i++)
    {
        // We want to quit
        if(line[i] == EOF)
        {
            return null;
        }
    }
    
    // Replacing the \n with a \0
    line[i] = '\0';

    return line;
}

int readLines(char* lines[],int numLines)
{
    int i;
    for(i = 0; (i < numLines); i++)
    {
        lines[i] = readLine();
        if(lines[i] == null) 
        {
            return i;
        }
    }

    return i;
}

void printLine(char* line)
{
    for(;*line != '\0'; line++)
    {
        putchar(*line);
    }
}

void writeLines(char* lines[],int numLines)
{
    for(int i = 0; i < numLines; i++)
    {
        printLine(lines[i]);
        printf("\n");
    }
}

void main()
{
    int numLines = 3;
    char* lines[numLines];

    numLines = readLines(lines,numLines);

    printf("\n");
    writeLines(lines,numLines);
}