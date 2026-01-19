#include <stdio.h>

#define swap(t,a,b) t s = a; (a = b); (b = s);

void main()
{
    int a = 10;
    int b = 4;

    printf("\na = %d, b = %d\n",a,b);

    swap(int,a,b);

    printf("\na = %d, b = %d\n",a,b);
}