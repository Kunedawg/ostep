#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    FILE *fp = fopen("q2.txt", "w");
    if (fp == NULL)
    {
        perror("Error opening q2.txt");
        return 1;
    }

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
        fprintf(fp, "Hello from child!\n");
    }
    else
    {
        // parent goes down this path (main)
        fprintf(fp, "Hello from parent!\n");
    }
    return 0;
}