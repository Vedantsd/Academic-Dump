#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    int fd[2];
    pid_t pid;

    char message[] = "Hello from Parent Process!";
    char buffer[100];

    if (pipe(fd) == -1)
    {
        printf("Pipe creation failed.\n");
        return 1;
    }

    pid = fork();

    if (pid < 0)
    {
        printf("Process creation failed.\n");
        return 1;
    }
    else if (pid > 0)
    {
        close(fd[0]);

        printf("Parent Process Started\n");
        printf("Parent Process ID: %d\n", getpid());

        write(fd[1], message, strlen(message) + 1);

        close(fd[1]);

        wait(NULL);

        printf("\nChild Process has terminated.\n");
        printf("Parent Process Terminated.\n");
    }
    else
    {
        close(fd[1]);

        printf("\nChild Process Started\n");
        printf("Child Process ID: %d\n", getpid());

        read(fd[0], buffer, sizeof(buffer));

        printf("Message received from Parent Process: %s\n", buffer);

        close(fd[0]);

        printf("Child Process Terminated.\n");

        exit(0);
    }

    return 0;
}