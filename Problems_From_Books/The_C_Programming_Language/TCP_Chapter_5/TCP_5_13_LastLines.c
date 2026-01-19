#include "../TCP_reuse.h"

#define MAXLINES 1000
#define MAXCHARS 1000
#define ENDLINE  "\0"
#define ENDCHAR  '~'

// Function that transforms a line of input including \n characters
// into a list of strings (one string for each line). We do this with pointers.
char** getLines(char* input)
{
    // Declaring pointers to each (possible) line, and allocating memory.
    char** lines = malloc(sizeof(char*) * MAXLINES);
    
    // Creating iteration variables for line num and current line char num.
    // Also allocating memory for the first line.
    int currentLine = 0;
    int currentLineChar = 0;
    *(lines) = malloc(sizeof(char) * MAXCHARS); 

    int i;
    for(i = 0; *(input + i) != '\0'; i++)
    {
        // If we find a newline, we are finished with the current line.
        if(*(input + i) == '\n')
        {
            // Capping of the string
            *(*(lines + currentLine) + currentLineChar) = '\0';
            
            // Incrementing line number
            currentLine++;
            // Resetting current line char
            currentLineChar = 0;
            // Allocating memory for next line
            *(lines + currentLine) = malloc(sizeof(char) * MAXCHARS);

            continue;
        }

        // Adding the current character to the current line
        *(*(lines + currentLine) + currentLineChar++) = *(input + i);
    }

    // We don't increment the final line, since it has to end with ~
    // We do it here instead :)
    lines[++currentLine] = ENDLINE;

    return lines;
}

void main(int argc, char* argv[])
{
    // Allocating memory for input
    char* input = malloc(sizeof(char) * MAXLINES * MAXCHARS);

    // Reading input
    char c;
    for(int i = 0; (c = getchar()) != ENDCHAR; i++)
    {
        *(input + i) = c;
    }

    // Splitting input into N strings (here we have a pointer to the first)
    char** lines = getLines(input);

    // Getting total number of strings
    int stringNum;
    for(stringNum = 0; *(lines + stringNum) != ENDLINE; stringNum++);

    // Getting how many lines to print:
    int n = 10;
    if(argc > 1)
    {
        for(int argi = 0; argi < argc; argi++)
        {
            if(argv[argi][0] == '-')
            {
                n = 0;
                for(int i = 1; argv[argi][i] != '\0'; i++)
                {
                    if(!isNumber(argv[argi][i]))
                    {
                        n = 10;
                        break;
                    }

                    n = n*10 + (argv[argi][i] - '0');
                }
            }
        }
    }

    // Checking if we have the neccesary number of lines
    if(n > stringNum)
    {
        printf("\n%d was entered, but only %d lines exist!\n",n,stringNum);
        return;
    }

    // Printing the last n lines
    for(int i = stringNum - n; i < stringNum; i++)
    {
        printf("\n%s",*(lines + i));
    }
}