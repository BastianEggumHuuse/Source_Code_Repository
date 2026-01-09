#include <stdio.h>

void main()
{
    // The basic datatypes are as follows:

    char   c; // Integer with a single byte of memory, nice for storing local characters (ASCII)
    int    i; // Integer with 16 or 32 bits of memory (depends on the system)
    float  f; // Float with standard precision (32 bits)
    double d; // Float with double precision (64 bits)

    // Integers have some different types

    short i_s; // Short integer, takes up 16 bits of memory
    long  i_l; // long integer, takes up 32 bits of memory

    // You can even further modify these!

    long long i_ll; // 64 bits of memory for an integer!

    // Newer versions of C have symbolic parameters that are easier to understand

    __int8  c;    // Equivalent to char, 8 bits
    __int16 i_s;  // Equivalent to short, 16 bits
    __int32 i_l;  // Equivalent to long, 32 bits
    __int64 i_ll; // Equivalent to long long, 64 bits

    // There exists other symbolic parameters like these, but I'll skip them for now.

    // these datatypes can be signed or unsigned, essentially deciding if you want
    // to spend memory to get negative numbers:

    unsigned char c_u; // Can contain values from 0 to 255
    signed char c_s;   // Can contain values from -128 to 127

    // (this naturally works for the other datatypes as well)



    // Strings are just shorthands for creating char arrays (this makes a lot of sense)
    char testString[] = "Hello!!";
    // Since char is just an integer, this works as well!
    int testString2[] = "Hello 2!!";
    // (This is a bit strange, but it means that every string is just a list of integers!)
    // Every string is ended by the null character \0

    // Remember that 'a' is NOT "a"! One is an integer, the other an array.

    // Enumerations! These are familiar :)
    enum numbers {ONE = 1, TWO = 2, THREE = 3};
    // They are referenced a bit differently though, as they have no relation to the enumeration container:
    printf("%d",ONE);
    // Enums will count up automatically from the last element you define.
    // These will contain 9,10,11, and 12:
    enum lastMonths {SEPTEMBER = 9, OCTOBER,NOVEMBER,DECEMBER};

    
    // In C, we separate Declarations and Definitions. Declarations are when you first dedicate some 
    // memory to a given variable:

    int firstNumber; // Single declaration
    int secondNumber, thirdNumber; // Multiple declarations
    // The only thing that binds these together is type. They must be the same!

    // You only define a variable once you give it a value!
    // (This can also be done when declaring)
    int ninthNumber = SEPTEMBER;

    // A value can be declared const (constant), which means it doesn't change:
    const int tenthNumber = OCTOBER;



    // We have 5 regular arithmetic operators:
    // +, -, *, /, %
    // If we try to divide integers, the result is truncated towards 0
    // (You've already experienced this)

    // Note that % cannot be used on doubles or floats!

    
    // Time for some insanity.
    // the increment (and decrement) operation can be written as a prefix or a postfix, which
    // changes it's function. The prefix applies the addition before the variable is used, and the
    // postfix applies it after. In most situations this doesn't matter, but look at this:
    int n = 5;
    int x;

    x = n++; // x is now 5, n is now 6
    n = 5;
    x = ++n; // x is now 6, n is now 6

    // notice how one of them defines x to be the value of n, and THEN increments n!
    // in some implementations, one is preferred! for example, imagine looping through a list:
    char s[10];
    char c;
    int i = 0;
    while((c = getchar()) != '\0')
    {   
        // getting the element at index i, and THEN incrementing i.
        // this means we begin at index 0, and then move upward.
        // had we used the prefix variant, we would have begun at 1!
        char s_i = s[i++];
        // do something with s_i here.
    }
    // This is a very stupid example, since it could be simplified as a for-loop, but it's quite cool!
    // (it does also have actual uses, like the squeeze function, where we have to keep track of two indexes)
    


    // Conditional expressions!
    // an alternative to the basic if check:
    int a = 1;
    int b = 3;
    int c;
    // Let's say we want c to be the max of a and b (and we can't use any functions)
    // we can do
    c = (a > b) ? a : b;
    // what does this do? First we evaluate the expression on the right (a > b). If this is true,
    // we set c to the middle expression (a), and if it is false, we set it to the expression on the
    // right (b). We have now skipped an if statement!
    
}
