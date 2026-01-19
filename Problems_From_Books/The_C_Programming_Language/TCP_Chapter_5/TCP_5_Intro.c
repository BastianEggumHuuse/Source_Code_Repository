#include <stdio.h>
#include <stdlib.h>

void main()
{
    // Chapter 5: Pointers and Arrays

    // 5.1) Pointers and adresses
    // Let's assume that we have a variable a
    int a = 3;
    // We can use the unary operator & to find the address of a:

    //int p = &a;

    // The way we have done this above is bad practice, as it turns a pointer into an integer.
    // We should instead use a pointer, notet by the *:
    int *p = &a;
    printf("\nAdress of a: %d\n",p);

    // We can then use the unary operator * to find the value that is stored in p:
    int b = *p; // This should now be equal to a
    printf("\na = %d, b = %d\n",a,b);

    // Note that writing *p is THE SAME as writing a. Meaning we can do something like
    (*p)++;
    // with no issues at all. (we need the parentheses tho)


    // 5.2) Pointers and function arguments
    // Pointers allow functions to alter variables that exist outside of it's scope.
    // This is the same as with pointers in something like Java; instead of passing a value, 
    // we pass the adress of the value, which lets us change the variable by dereferencing.

    // 5.3) Pointers and Arrays
    // Arrays are just pointers!!!
    int arrayOfIntegers[10];
    arrayOfIntegers[0] = 10;
    arrayOfIntegers[1] = 17;
    
    // We can get the pointer to the first element of the array.
    p = &(arrayOfIntegers[0]);
    // To get the second element, we simply add 1 to p!!! (this is so elegant oh my god)
    printf("\nGetting the second integer through array   : %d", arrayOfIntegers[1]);
    printf("\nGetting the second integer through pointer : %d\n",*(p+1));
    // Not only do these print the same numbers, they print THE SAME VALUES!!!!
    // This naturally works the other way, with *(p-1) (not in this case tho)

    // This makes a lot of sense, since the array allocates memory in a sequence, placing
    // each element along said sequence.

    // The array itself (arrayOfIntegers) is just the address of arrayOfIntegers[0]. This gives us
    printf("\n%d\n",arrayOfIntegers == &(arrayOfIntegers[0]));
    // They're the same!!! (note that you cannot do arithmetic with an array name, so they're not completely alike)


    // 5.10) Command line arguments
    // We can do them!
    // They're accessed through main like this:
    // void main(int argc, char* argv[])

    // the names are up to me ofc.
    // argc contains the amount of arguments. The first argument is the name of the file,
    // so anything above 1 means arguments were passed.
    // argv contains argc pointers, each of which being a string (an argument).

    // 
}