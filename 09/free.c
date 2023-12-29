
#include <stdio.h>
#include <stdlib.h>

/*
Write a simple program that allocates memory using malloc() but
forgets to free it before exiting. What happens when this program
runs? Can you use gdb to find any problems with it? How about
valgrind (again with the --leak-check=yes flag)?
*/

int main(int argc, char* argv[])
{
    int* p = (int*)malloc(sizeof(int));
    *p = 1738;
    return EXIT_SUCCESS;
}
