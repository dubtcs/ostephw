#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "common_threads.h"

sem_t s; 

void *child(void *arg) {
    printf("child\n");
    sleep(1); // make sure it works, Q1
    sem_post(&s);
    printf("child 2\n");
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t p;
    printf("parent: begin\n");

    sem_init(&s, 1, 0); // init to zero so main thread waits for child to increment it
    Pthread_create(&p, NULL, child, NULL);
    sem_wait(&s);
    sem_close(&s);

    printf("parent: end\n");
    return 0;
}

