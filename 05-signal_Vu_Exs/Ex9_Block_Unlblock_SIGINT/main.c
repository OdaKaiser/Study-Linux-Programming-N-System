#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sigHandlerSigUsr(int signum)
{
    if (SIGUSR1 == signum )
    {
        printf("I'm SIGUSR 1\n!");
        printf("He he he \n!");
    }
    else if (SIGUSR2 == signum)
    {
        printf("I'm SIGUSR 2\n!");
        printf("Hi hi hi \n!");
    }
    else
    {
        printf("Error when Triger action for SIGUSR1/SIGUSR2\n");
        exit(1);
    }
}

void sigHandlerSigInt()
{
    printf("I'm SIGINT\n!");
    printf("Ha ha ha \n!");
}

int main()
{   
    if (signal(SIGINT, sigHandlerSigInt) == SIG_ERR)
    {
        printf("Error when register action for SIGINT\n");
        exit(1);
    }
    //making a mask to block/ unblock signal
    sigset_t block_mask;
    sigemptyset(&block_mask);
    sigaddset(&block_mask, SIGINT);
    //blocking SIGINT
    if (sigprocmask(SIG_BLOCK, &block_mask, NULL) == 0)
    {
        printf("Blocking SIGINT\n");  
        if (sigismember(&block_mask, SIGINT) == 1)
        {
            printf("SIGINT is blocked!\n");
            sleep(5); 
        }
    }
    if (sigprocmask(SIG_UNBLOCK, &block_mask, NULL) == 0)
    {
        printf("Unblocking SIGINT\n");  
        if (sigismember(&block_mask, SIGINT) == 1)
        {
            printf("SIGINT is unblocked!\n");
            sleep(3); 
        }
    }

    signal(SIGUSR1, sigHandlerSigUsr);
    kill(getpid(),SIGUSR1);
    sleep(1); 

    signal(SIGUSR2, sigHandlerSigUsr);
    kill(getpid(),SIGUSR2);
    sleep(1); 

    while(1);
    return 0;
}
