#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <bits/signum.h>
 
int main(int argc, char *argv[])
{
    int i;
    if (argc != 2)
    {
        printf("Not a valid argument!\nUsage ./main <int number>\n");
        printf("Arg = <1/2> to prvent zombie process by calling wait()/waitpid or SIGCHLD\n");
        exit(1);
    }
    else
    {
        i = atoi(argv[1]);
        printf("i = %d\n",i);
    }
      
    //fork the parent process
    int child_pid = fork();
    if (child_pid >= 0)
    {
        if (child_pid == 0) //child process
        {
            printf("This is Child process\n");
            printf("Process ID is: %d\nParent process ID is: %d\n", getpid(), getppid());   
        }
        else //parent process
        {
            printf("This is Parent process\n");
            printf("Process ID is: %d\n", getpid());

            if (i == 1) //prevent by wait()
            {
                printf("PREVENT BY CALLING WAIT\n");

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
            else if (i == 2) //prevent by SIGCHLD
            {
                printf("PREVENT BY CALLING WAIT\n");
                signal(SIGCHLD,SIG_IGN);
            }
            else // check argument is not valid
            {
                printf("ARG ERROR ONLY 1 OR 2!\n");
                exit(1);
            }

        }
    }
    else 
    {
        printf("fork() error return -1\n");
    }
    return 0;
}