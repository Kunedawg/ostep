#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
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
        printf("hello from child!\n");
    }
    else
    {
        // parent goes down this path (main)
        wait(NULL);
        printf("goodbye from parent!\n");
    }
    return 0;
}