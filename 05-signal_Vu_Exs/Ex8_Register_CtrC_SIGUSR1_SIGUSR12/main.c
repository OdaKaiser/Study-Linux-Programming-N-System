#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

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
    kill(getpid(),SIGINT); 

    signal(SIGUSR1, sigHandlerSigUsr);
    kill(getpid(),SIGUSR1);

    signal(SIGUSR2, sigHandlerSigUsr);
    kill(getpid(),SIGUSR2);
    
    return 0;
}