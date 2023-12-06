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
    printf("Ha ha ha \n!");
}

int main()
{
    sigset_t block_mask, current_mask;

    if (signal(SIGINT, sigHandlerSigInt) == SIG_ERR)
    {
        printf("Error when register action for SIGINT\n");
        exit(1);
    }

    sigemptyset(&block_mask);
    sigemptyset(&current_mask);
    sigprocmask(SIG_BLOCK, NULL, &block_mask);

    if (sigprocmask(SIG_SETMASK, &block_mask, &current_mask) == 0)
    {
        if (sigismember(&block_mask, SIG_IGN) == 1)
        {
            printf("SIGINT exist, unblock signal\n");
        }
        else if (sigismember(&block_mask, SIG_IGN) == 0)
        {
            printf("SIGINT does not exist, blocked signal\n");
        }
    }

    signal(SIGUSR1, sigHandlerSigUsr);  
    signal(SIGUSR2, sigHandlerSigUsr);

    while(1);
    return 0;
}
