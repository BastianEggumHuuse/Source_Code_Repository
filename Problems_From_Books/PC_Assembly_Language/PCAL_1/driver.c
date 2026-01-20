#include <stdio.h>
// Extremely simple C code that simply runs an assembly script
int main()
{
    int ret_status; 
    ret_status = asm_main(); // Running assembly function

    printf("\nReturn status: %d\n",ret_status);
    return ret_status;
}