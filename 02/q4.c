
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    int p[2]; // used for pipe descriptors

    char buffer[64];

    // create a 2 way pipe
    pipe(p);

    int c1 = fork();
    if(c1 == 0)
    {
        dup2(p[1], STDOUT_FILENO);
        close(p[1]);
        printf("THE DOLLAR\n");
        exit(0);
    }
    else
    {
        dup2(p[0], STDIN_FILENO);
        close(p[0]);
        read(STDIN_FILENO, &buffer, 11);
        printf("%s", buffer);
        exit(0);
    }

    return 0;
}
