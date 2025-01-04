#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int fd[2];
    if (pipe(fd) == -1)
    {
        perror("pipe");
        exit(1);
    }

    // Fork first child
    pid_t cpid1 = fork();
    if (cpid1 < 0)
    {
        perror("fork");
        exit(1);
    }
    if (cpid1 == 0)
    {
        // --- Child 1 process ---
        // We only write to the pipe here, so close the read end:
        close(fd[0]);

        // Redirect stdout to the write-end of the pipe:
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);

        // Example: child1 runs "ls -l"
        execlp("ls", "ls", "-l", (char *)NULL);

        // If execlp fails:
        perror("execlp child1");
        exit(1);
    }

    // Fork second child
    pid_t cpid2 = fork();
    if (cpid2 < 0)
    {
        perror("fork");
        exit(1);
    }
    if (cpid2 == 0)
    {
        // --- Child 2 process ---
        // We only read from the pipe here, so close the write end:
        close(fd[1]);

        // Redirect stdin to the read-end of the pipe:
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);

        // Example: child2 runs "wc -l"
        execlp("wc", "wc", "-l", (char *)NULL);

        // If execlp fails:
        perror("execlp child2");
        exit(1);
    }

    // --- Parent process ---
    // Close both ends of the pipe, no longer needed by parent:
    close(fd[0]);
    close(fd[1]);

    // Wait for both children to finish
    wait(NULL);
    wait(NULL);

    return 0;
}