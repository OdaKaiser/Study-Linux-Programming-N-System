#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigHandlerSigUsr1()
{
    printf("I'm SIGUSR 1\n!");
    printf("He he he \n!");
}

void sigHandlerSigUsr2()
{
    printf("I'm SIGUSR 2\n!");
    printf("Hi hi hi \n!");
}

void sigHandlerSigInt()
{
    printf("Ha ha ha \n!");
}

int main()
{
    signal(SIGINT, sigHandlerSigInt);
    signal(SIGUSR1, sigHandlerSigUsr1);
    signal(SIGUSR2, sigHandlerSigUsr2);
    while(1);
    return 0;
}