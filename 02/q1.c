
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    printf("Process ID: %d\n", (int)(getpid()));
    int rc = fork(); // if successful, the fork will pick up here
    int x = 55;
    if(rc < 0)
    {
        printf("Fork failure.");
        exit(1); // non zero exit failure
    }
    else if(rc == 0)
    {
        printf("Child var: %d\n", x);
        x = 120;
        printf("Child var: %d\n", x);
        exit(0);
        // can now call exec() to transform this process into a different program
    }
    else // parent of child fork
    {
        int rw = wait(NULL);
        printf("Parent var %d\n", x);
    }
    return 0;
}
