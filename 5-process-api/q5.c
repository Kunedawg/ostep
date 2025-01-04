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
        int child_pid = getpid();
        printf("hello from child (pid: %d)!\n", child_pid);
        printf("Child start wait\n");
        int wait_pid = wait(NULL);
        printf("Child finished waiting on: %d\n", wait_pid);
    }
    else
    {
        // parent goes down this path (main)
        int wait_pid = wait(NULL);
        int parent_pid = getpid();
        printf("goodbye from parent (pid: %d)! Waited on: %d\n", parent_pid, wait_pid);
    }
    return 0;
}