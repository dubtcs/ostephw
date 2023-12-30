
#include <stdlib.h>
#include <stdio.h>

/*
First, write a simple program called null.c that creates a pointer
to an integer, sets it to NULL, and then tries to dereference it. Compile this into an executable called null. What happens when you
run this program?
*/

int main(int argc, char* argv[])
{
    int* p = (int*)malloc(sizeof(int));
    p = NULL;
    printf("%d\n", *p);
    return 0;
}
