
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define SCO_ITERS 15

typedef struct __scount
{
    pthread_mutex_t lock;
    int val;
} scount;

void inc(scount* c)
{
    pthread_mutex_lock(&c->lock);
    c->val++;
    pthread_mutex_unlock(&c->lock);
}

void* workfn(void* c)
{
    for(int i = 0; i < SCO_ITERS; i++)
    {
        inc((scount*)c);
    }
}

int main(int argc, char* argv[])
{
    scount* counter = malloc(sizeof(scount));
    counter->val = 0;
    pthread_mutex_init(&counter->lock, NULL);

    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1, NULL, workfn, counter);
    pthread_create(&t2, NULL, workfn, counter);
    
    for(int i = 0; i < 5; i++)
    {
        inc(counter);
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // val should be (SCO_ITER * 2) + 5
    printf("%d\n", counter->val);
    
    free(counter);
    return EXIT_SUCCESS;
}
