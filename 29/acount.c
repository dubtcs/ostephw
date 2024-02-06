
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define ACO_THRESH 50
#define ACO_LOOPS 150

typedef struct __acount
{
    pthread_mutex_t lock;
    int val;
} acount;

void* worker(void* args)
{
    acount* ac = (acount*)args;
    int threshold = 0;
    for(int i = 0; i < ACO_LOOPS; i++)
    {
        threshold++;
        if(threshold >= ACO_THRESH)
        {
            printf("Threshold pass: %d\n", getpid());
            pthread_mutex_lock(&ac->lock);
            ac->val += ACO_THRESH;
            pthread_mutex_unlock(&ac->lock);
            threshold = 0;
        }
    }
}

int main(int argc, char* argv[])
{
    acount* counter = malloc(sizeof(acount));
    pthread_mutex_init(&counter->lock, NULL);
    
    struct timespec timerStart, timerEnd;
    
    long numcpu = sysconf(_SC_NPROCESSORS_ONLN);

    long jcount = numcpu * 0.5;
    printf("Creating %ld threads.\n", jcount);

    pthread_t* jobs = malloc(sizeof(pthread_t) * jcount);

    clock_gettime(CLOCK_MONOTONIC, &timerStart);
    for(long i = 0; i < jcount; i++)
    {
        pthread_create((jobs + i), NULL, worker, counter);
    }

    for(long i = 0; i < jcount; i++)
    {
        pthread_join(*(jobs + i), NULL);
    }
    clock_gettime(CLOCK_MONOTONIC, &timerEnd);

    printf("%d\n", counter->val);
    printf("Time: %ldns\n", timerEnd.tv_nsec - timerStart.tv_nsec);
    
    free(counter);
    return EXIT_SUCCESS;
}
