#include "TCP_4_A_StackBase.h"

// Ok let's take this from the top. The point is to read lines, skipping whitespace,
// and process numbers and operations. I'm not going to tackle the logic here, as it's already
// given by the book

// 1) If the input is a number, push it onto the stack
// 2) If the input is an operation, pop the two highest items from the stack,
//    and perform the operation. Then push the number back onto the stack.

// Let's define a max number size.
#define MAXNUMBERSIZE 100

// First a short function that checks if a char is whitespace:
int isWhiteSpace(char c)
{
    return (c == ' ' || c == '\t');
}

// The calculator method. We might override this later.
// Note that it takes the string with whitespace as input, and returns the double calculated.
double calculator(char s[])
{
    // Used for when operations aren't commutative
    double secondOperand;
    // Used to "collect" numbers.
    char number[MAXNUMBERSIZE];

    for(int i = 0; s[i] != '\0'; i++)
    {
        // First let's handle numbers. We assume no negatives (those can be constructed)
        if(isNumber(s[i]))
        { 
            // Iterator for the array number
            int j = 0;
            while(!isWhiteSpace(s[i]))
            {
                number[j++] = s[i++];
            }
            // Capping off the string
            number[j] = '\0';

            // Pushing the collected number to the stack
            pushToStack(atof(number));
            continue; // Nothing else happens.
        }

        // Then we handle whitespace
        if(isWhiteSpace(s[i]))
        {
            continue;
        }

        // Switch statement time!!! 
        // In theory we could write every operation as a function but i don't want to right now
        // We also assume that the line is written correctly
        switch(s[i])
        {
            case '+' :  
                // We have commutativity, so no ordering is required.
                pushToStack(popFromStack() + popFromStack());
                break;
            case '-' :
                // - is not commutative, and we want to subtrack the first number on the stack from the second.
                // We use a temporary variable:
                secondOperand = popFromStack();
                pushToStack(popFromStack() - secondOperand);
                break;
            case '*' :
                // Commutative operation
                pushToStack(popFromStack() * popFromStack());
                break;
            case '/' :
                // Non-commutative operation
                secondOperand = popFromStack();
                if(secondOperand != 0)
                {
                    pushToStack(popFromStack() / secondOperand);
                }
                else
                {
                    printf("\nerror: cannot divide by 0.\n");
                }
                break;
            default :
                // Unknown command.
                printf("\nerror: unknown operation: %c\n",s[i]);
                break;
        }
    }

    // Finally, return the final element on the stack
    return popFromStack();
}
