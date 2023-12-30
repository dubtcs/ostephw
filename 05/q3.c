
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

static bool gSayBye = true;
void HandleGoodbye(int sig)
{
    gSayBye = false;
    return;
}

int main(int ac, char* av[])
{
    struct sigaction sa;
    int id = getpid();

    sa.sa_handler = HandleGoodbye;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    sigaction(SIGUSR1, &sa, NULL);

    int cid = fork();
    if (cid == 0)
    {
        printf("Hello from [%d]!\n", (int)(getpid()));
        sigqueue(getppid(), SIGUSR1, (union sigval){  });
        exit(0);
    }
    while(gSayBye) {} // bruh
    printf("Goodbye from [%d]\n", (int)(getpid()));
    return 0;
}
