#include "../TCP_reuse.h"

// Declaring some functions haha
double doubleFunc(char s[]);

void main()
{
    // 4: Functions and program structure

    // Welcome to chapter 4! This chapter details functions mainly :)

    // 4.1) The basics of functions
    // Not much to see here

    // 4.2) Functions returning non integers
    // We can declare a function explicitly before we use it, even if we nab it from an #include
    // In fact you should! or the compiler will struggle to catch errors.
    double doubleFunc(char []);
    // The compiler now knows that this function takes a char[], and that it returns a double

    // 4.6) Static variables
    // A static variable is only visible within this source file. No other files
    // can view or access it. (unlike in other languages)
    static int a = 2; // for example

    // 4.7) Register variables
    // A register variable advises the compiler that it should store this variable in registers.
    // This makes the code faster. 
    register double b = 1.4;
    // They have limits however, as registers are small, and can only hold numbers.


    // 4.11) C Preprossessing
    // Includes and definitions are examples of C preprossessing. It happens before the compilation!
    // Includes are already known to you

    // Definitions, or Macro-substitutions, give a piece of text a name, which can be repeated:
    #define INTEGERCONSTANT 1
    // They are by tradition capitalized, but they don't have to.
    // They can also have variables!
    #define INTEGERADDITION(A,B) A + B
    // Why do this? Function calls are expensive! Certain functions from stdio.h are actually macros,
    // to avoid spending processing power on calling.
    
    // If we want to represent some variables in a string, a macro can be handy. Let's say we have a variable
    // x:
    int x = 3;
    // We want to check what x is, for debugging purposes. We can then do
    #define debugPrint(s) printf(#s " = %d",s)
    // (note that the capitalization is mostly a tradition for symbolic constants)
    // The # expands the argument s into "s". This gives us a macro that will print :
    // > x = 3
    // at which point we can debug. Neat!
    
}