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
        close(STDOUT_FILENO);
        printf("Hello from child!\n"); // You won't see this in the terminal
    }
    else
    {
        // parent goes down this path (main)
        int wait_pid = waitpid(0, NULL, 0);
        int parent_pid = getpid();
        printf("goodbye from parent (pid: %d)! Waited on: %d\n", parent_pid, wait_pid);
    }
    return 0;
}