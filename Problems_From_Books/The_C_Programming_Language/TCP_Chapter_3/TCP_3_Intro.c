#include "../TCP_reuse.h"

void main()
{
    // Chapter 3!
    // This chapter focuses on control flow 
    // (We'll be learning switch statements later!!!!)

    // 3.1)
    // An expression becomes a statement once it has the semicolon!
    // Braces {} are used to group declarations and statements into a compound statement.

    // 3.2)
    // The if-else-statement! You know this one. We can learn some cool tricks however:
    // Since the if statement essentially just checks wether or not a value is 0, we have that:
    int a = 10;
    if(a != 0) {}
    // is the same as
    if(a) {}
    // since the if statement proceeds if and only if a != 0.

    // 3.3)
    // else if. This one is also familiar.
    // I can't be fucked to do the problem for this one.

    // 3.4)
    // Here we fucking go. Switch stament time baybee
    // The switch statement is a shortening of a long if-else chain:
    
    // First we open the statement with the switch keyword, along with the 
    // statement we wish to evaluate. 
    switch(a + 10) 
    {
        // Once in the block, we add different cases:
        case 20 : printf("THats a 20!!");
        case 10 : printf("Only 10?");
        default : printf("THats not 20 or 10....");
    }
    printf("\n");
    // The final default is optional, but is the else part of the chain. If nothing else happens,
    // the default case is run.

    // The switch statement has some interesting properties. Let's say we have a character:
    char c = 'A';

    switch(c)
    {
        case 'A' :
        case 'B' : 
        case 'C' : printf("ABC!!!");
        case 'D' : printf("D!!!");
        default  : printf("Nothin...");
    }
    printf("\n");
    
    // If we run this, it will print ABC!!!D!!!Nothin... , because if a case is entered, the next cases
    // are all entered as well. This means that the switch statement doesn't completely replicate the
    // if-else-chain. We can solve it!

    switch(c)
    {
        case 'A' :
        case 'B' : 
        case 'C' : 
        printf("ABC!!!");
        break;

        case 'D' : 
        printf("D!!!");
        break;

        default  :
        printf("Nothin...");
        break;
    }

    // The break keyword exits the switch statement forcefully, which solves this problem. 
    // (notice that we also put a break in the default case, even tho it always quits after it.
    // this is just good practice, in case we write a statement below it later)


    // I'm gonna skip a few uninteresting chapters, and move onto chapter
    // 3.8) goto and labels

    // the goto keyword instantly jumps from the current line to a specified "label"
    // , which is just a jumping point for the goto keyword. For instance:

    int a = 0;
    start:
        printf("HELLO!!");
        if(a < 10) {goto start;}
    
    // this is a adjusted while loop. gotos are very rarely used, since they mainly create clutter.
    // They do have a use for escaping nested loops, since break cannot do that.

    // That's the entire chapter!
}