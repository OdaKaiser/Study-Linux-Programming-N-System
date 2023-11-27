#include "inc/DigitalClock.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    pid_t child_pid;
    child_pid = fork();
    if (child_pid >= 0)
    {
        if (child_pid == 0)
        {
            printf("This is child process running digital clock \n");
            printf("Child process ID is: %d\n Parent process ID is: %d", getpid(), getppid());
            digitalClock();
        }
        else
        {
            printf("This is prent process\n");
            printf("Process ID is: %d", getpid());
        }
    } 
    else 
    {
        printf("fork() error return -1");
    }
    return 0;
}
