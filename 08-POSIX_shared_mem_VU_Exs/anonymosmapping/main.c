#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    //data buffer 
    char* shared_mem = mmap(0, 1, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (shared_mem == MAP_FAILED)
    {
        printf("Creating share memmory error!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(shared_mem, "Original Message");
    //process fork
    pid_t child_pid;
    child_pid = fork();
    if (child_pid >= 0)
    {
        if (child_pid == 0)
        {
            printf("This is child process\n");
            printf("Process ID is: %d\n", getpid());
            strcat(shared_mem, " Child Message");
            printf("Data in child: %s\n",shared_mem);
            if (munmap(shared_mem, sizeof(shared_mem)) == -1)
            {
               printf("munmap fail\n");
            }
            exit(EXIT_SUCCESS);
        }
        else
        {
            printf("This is parent process\n");
            printf("Process ID is: %d\n", getpid());
            strcat(shared_mem, " Parent Message");
            printf("Data in parent: %s\n", shared_mem);
            if (munmap(shared_mem, sizeof(shared_mem)) == -1)
            {
                printf("munmap fail\n");
            }
            exit(EXIT_SUCCESS);
    
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
