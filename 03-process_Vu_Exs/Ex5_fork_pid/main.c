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
                digitalClock();  
        }
        else
        {
            printf("This is parent process\n");
            printf("Process ID is: %d", getpid());
        }
    } 
    else 
    {
        printf("fork() error return -1\n");
    }
    return 0;
}
