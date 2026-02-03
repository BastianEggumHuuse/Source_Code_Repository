#include "../TCP_reuse.h"

void main()
{
    // Chapter 6: Structures
    // This is what we've been waiting for. Our own datastructures!

    
    // 6.1) Basics of structures
    // Let's declare a struct:
    struct vector2 
    {
        double x;
        double y;
    };
    // This defines a new struct called vector2, which holds two doubles.
    // The elements within the struct are called members.

    // We can now create a variable with the new type we have declared:
    struct vector2 v;
    // It can also be initialized:
    struct vector2 v2 = {10.0,17.0};

    // This is actually a shortcut. We can do the entire declaration and initalization at once!
    struct vector3
    {
        double x;
        double y;
        double z;
    } v3 = {10.0, 17.0, 3.0};
    // This let's us also forego the struct label (the name), in the case this struct is only used once
    // (Particularily useful for automatic variables)
    struct {double x; double y; double z; double w;} v4 = {1,2,3,4};

    // Just like in other languages, we refer to struct members with a dot:
    double x_1 = v2.x;

    // A struct is just a type (I think), so we can nest them:
    struct rect 
    {
        struct vector2 start;
        struct vector2 end;
    };
    // This lets us create more advanced structures.

    // We frequently refer to structs with pointers, since copying the entire struct is costly.
    // We do
    struct rect r = {{1,2},{2,1}};
    struct rect* pr = &r;
    // We can refer to members through usual pointer notation:
    printf("\n%d\n",(*pr).start.x);
    // But we can also use the provided struct pointer notation:
    printf("\n%d\n",pr -> start.x);
    // The arrow gives us a quick and easy way to refer to members without getting the struct instance first


    // 6.5) Self referential structures
    // Structures cannot contain themselves as members, but they can contain pointers!
    struct binarySearchNode
    {
        char* string;
        struct binarySearchNode* left;
        struct binarySearchNode* right;
    };
    // It's illegal to put values to the struct, but pointers are ok.


}
