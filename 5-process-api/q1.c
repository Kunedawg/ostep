#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int x = 100;
    int rc = fork();
    if (rc < 0)
    {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // child (new process)
        printf("child x: %d\n", x);
    }
    else
    {
        // parent goes down this path (main)
        x = 101;
        printf("parent x: %d\n", x);
    }
    return 0;
}