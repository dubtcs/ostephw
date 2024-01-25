#include <stdio.h>

#include "common_threads.h"

pthread_mutex_t gLock;

int balance = 0;

void* worker(void* arg) {
    pthread_mutex_lock(&gLock);
    balance++; // unprotected access 
    pthread_mutex_unlock(&gLock);
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t p;
    Pthread_create(&p, NULL, worker, NULL);
    worker(NULL);
    Pthread_join(p, NULL);
    printf("Balance: %d\n", balance);
    return 0;
}
