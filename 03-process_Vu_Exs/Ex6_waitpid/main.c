#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{

    
    //process the user input check for invalid arguments
    int i;
    if (argc != 2)
    {
        printf("Not a valid argument!\nUsage ./main <int number>\n");
        printf("Arg = <number> to terminarted child process after <number> secconds\n");
        exit(1);
    }
    else if(argc > 2 || argc < 2) 
    {
       printf("Too many or few arguments supplied.\n"); 
       exit(1);
    }
    else
    {
        i = atoi(argv[1]);
        if ( i <= 0 )
        {
            printf("Not a valid argument (>=0).\n"); // non negative number make program hang 
            exit(1);
        }
    }

    //fork the parent process
    pid_t child_pid;
    int waitPid, waitStatus; 
    child_pid = fork();
    if (child_pid >= 0)
    {
        if (child_pid == 0) //child process
        {
            printf("This is Child process\n");
            printf("Process ID is: %d\nParent process ID is: %d\n", getpid(), getppid());   
            if (i != 0)
            {
                do
                {
                    printf("Child process will terminated in %d sec\n", i); // get second from 2nd argument 
                    i--;
                    sleep(1);
                } while (i > 0);

                if (i == 0)
                {
                    exit(1);
                }
            }
        }
        else //parent process
        {         
            printf("This is Parent process\n");
            printf("Process ID is: %d\n", getpid());
            
            //comment 1 block and keep 2 blocks to see result
            /*BLOCK 1*/ 
            if(waitpid(child_pid, &waitStatus, 0) == -1) // waitpid() return -1 when error
            {
                printf("wait_pid() Unsuccessful\n");
            }
            else
            {
                printf("Parent waits for Child process Succesfully (pid: %d)\n", child_pid);
            }

            /*BLOCK 2*/
            if(wait(&waitStatus) == -1) // wait() return -1 when error
            {
                printf("wait() Unsuccessful\n");
            }
            else
            {
                printf("Parent waits for Child process Succesfully (pid: %d)\n", child_pid);
            }
            
            /*BLOCK 3*/
            if(waitpid(child_pid, &waitStatus, 0) == -1) // waitpid() return -1 when error
            {
                printf("wait_pid() Unsuccessful\n");
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
