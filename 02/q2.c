
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/wait.h>

int main(int ac, char* av[])
{
    int desc = open("opener.txt", O_RDWR);
    int cid = fork();
    char ch;
    if(cid > 0)
    {
        read(desc, &ch, 1);
        printf("Child char: %c\n", ch);
        write(desc, "1 add", 5);
        read(desc, &ch, 1);
        printf("Child char 2: %c\n", ch);
    }
    else
    {
        int cw = wait(NULL);
        read(desc, &ch, 1);
        printf("Parent char: %c\n", ch);
        write(desc, "2 add", 5);
        read(desc, &ch, 1);
        printf("Parent char 2: %c\n", ch);
    }
    return 0;
}
