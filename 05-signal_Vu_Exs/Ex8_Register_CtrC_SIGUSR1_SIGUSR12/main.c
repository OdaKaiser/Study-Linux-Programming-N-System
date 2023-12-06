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
    printf("Ha ha ha \n!");
}

int main()
{
    if (signal(SIGINT, sigHandlerSigInt) == SIG_ERR)
    {
        printf("Error when register action for SIGINT\n");
        exit(1);
    }
    signal(SIGUSR1, sigHandlerSigUsr);  
    signal(SIGUSR2, sigHandlerSigUsr);

    while(1);
    return 0;
}