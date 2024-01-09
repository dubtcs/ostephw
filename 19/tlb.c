
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <time.h>

int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        return EXIT_FAILURE;
    }
    
    int numberOfPages = atoi(argv[1]);
    int numberOfTrials = atoi(argv[2]);

    struct timespec timer1, timer2;

    int pageSize = sysconf(_SC_PAGESIZE);
    int pageJump = (pageSize / sizeof(int));

    printf("Number of pages: %d\n", numberOfPages);
    printf("TLB page size: %d\n", pageSize);
    // heap array
    int* arr = calloc(numberOfPages, pageSize);
    long avgTime = 0.0;

    for (int t = 0; t < numberOfTrials; t++)
    {
        clock_gettime(CLOCK_MONOTONIC, &timer1);
        for (int i = 0; i < numberOfPages * pageJump; i += pageJump)
        {
            arr[i] += 1;
        }
        clock_gettime(CLOCK_MONOTONIC, &timer2);
        avgTime += timer2.tv_nsec - timer1.tv_nsec;
    }

    printf("Time dif: \t\t%ld nanoseconds.\n", (avgTime / numberOfTrials));

}
