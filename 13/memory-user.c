
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Requires atleast argument -m");
        return 1;
    }

    uint64_t mem;
    void* adr;
    bool loop = false;

    for (int i = 1; i < argc; i++)
    {
        if(argv[i][0] == '-')
        {
            if(argv[i][1] == 'm')
            {
                mem = atoi(argv[i + 1]);
            }
            else if (argv[i][1] == 'l')
            {
                loop = (argv[i + 1][0] == '1');
            }
            i += 1;
        }
        else
        {
            printf("Malformed argument: %s\n", argv[i]);
            return 1;
        }
    }

    mem *= 1000000; // bytes
    adr = malloc(mem);
    printf("PID: %d\n", (int)(getpid()));
    printf("Byte size: %ld\n", mem);
    printf("Adr: %p\n", adr);
    
    while(loop)
    {
        // use free to check mem usage
    }

    free(adr);
    return 0;
}
