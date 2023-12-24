#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void)
{
    //data buffer
    char readMesssage [100];
    char writeMesssage [100] = "Message from Parent!"; 
    char writeData [100] = "Data from Parent!";
    //creating pipe fd and check status
    int pipe_fd[2];
    if (pipe(pipe_fd) != 0)
    {
        printf("Creating pipe error!");
        exit(EXIT_FAILURE);
    }
    //process fork
    pid_t child_pid;
    child_pid = fork();
    if (child_pid >= 0)
    {
        if (child_pid == 0)
        {
            read(pipe_fd[0], readMesssage, sizeof(readMesssage));
            printf("This is child process\n");
            printf("Process ID is: %d\n", getpid());
            printf("Child is reading from pipe – Message is: %s\n", readMesssage);
            read(pipe_fd[0], readMesssage, sizeof(readMesssage));
            printf("Child is reading from pipe – Message is: %s\n", readMesssage);
        }
        else
        {
            printf("This is parent process\n");
            printf("Process ID is: %d\n", getpid());
            printf("Parent is writing to pipe – Message is: %s\n", writeMesssage);
            write(pipe_fd[1], writeMesssage, sizeof(writeMesssage));
            printf("Parent is writing to pipe – Message is: %s\n", writeData);
            write(pipe_fd[1], writeData, sizeof(writeData));
            
            int waitStatus;
            if(wait(&waitStatus) == -1) // wait() return -1 when error
            {
                printf("wait() Unsuccessful\n");
            }
            else
            {
                printf("Parent waits for Child process Succesfully (pid: %d)\n", child_pid);
            }
    }
    } 
    else 
    {
        printf("fork() error return -1\n");
    }
    return 0;
}
