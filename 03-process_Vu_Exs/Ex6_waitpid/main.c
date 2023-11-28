#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void)
{
    pid_t child_pid;
    int waitPid, waitStatus; 

    child_pid = fork();
    if (child_pid >= 0)
    {
        if (child_pid == 0)
        {
            printf("This is child process\n");
            printf("Process ID is: %d\nParent process ID is: %d\n", getpid(), getppid());   
            //while(1);//comment here to see the differences and keep  wait(&waitStatus); to see the differences           
        }
        else
        {         
            printf("This is parent process\n");
            printf("Process ID is: %d\n", getpid());
            
            wait(&waitStatus); //comment here to see the differences
            if(waitpid(child_pid, &waitStatus, 0) == -1) // waitpid return -1 when parent process successfully wait() 
            {
                printf("wait() successful\n");
            }
            else
            {
                printf("Child process is remain with pid: %d \n", child_pid);
            }
        }
    } 
    else 
    {
        printf("fork() error return -1\n");
    }
    return 0;
}
