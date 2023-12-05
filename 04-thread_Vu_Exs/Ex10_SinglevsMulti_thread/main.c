#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <fcntl.h>
#include <fcntl.h>

void *createFile(int maxcount)
{
    char databuffer[100]; 
    int fileDescriptor = open("a.txt", O_APPEND |O_RDWR | O_CREAT, 0667);

    if (fileDescriptor < -1)
    {
        printf("Opening file error!\n");
        exit(1);
    }
    else
    {
        int count;
        printf("Performing write operation...\n");
        for (count = 0; count < maxcount; count++)
        {
            sprintf(databuffer, "%d" , count);
            write(fileDescriptor, databuffer, strlen(databuffer));
            write(fileDescriptor, "\n", 1);
        }
        printf("Write operation completed\n");
        close(fileDescriptor);
    }
}

int main(int argc, char *argv[])
{
    int option;
    //handling user input
    if (argc != 2)
    {
        printf("Not a valid argument!\nUsage ./main <1/2>\n");
        printf("Arg = <1/2> 1 to run program with single thread, 2 to run program with multi-threads\n");
        exit(1);
    }
    else
    {
        option = atoi(argv[1]);
        printf("Option is : %d\n", option);
    }
    // 1 for 1 thread 2 for 2 thread
    switch (option)
    {
        case 1:
        {
            pthread_t thread_id; 
            printf("Run createFile with 1 thread...\n");
            clock_t start = clock(); //start timer
            
            pthread_create(&thread_id, NULL, &createFile, (int*)1000000);
            pthread_join(thread_id,NULL); 

            clock_t end = clock(); //end timer
            printf("Time taken: %f \n", (double)(end - start)/CLOCKS_PER_SEC); //cal time taken
            break;
        }
        case 2:
        {
            pthread_t thread_id1, thread_id2; 
            printf("Run createFile with 2 thread...\n");
            clock_t start = clock(); //start timer

            printf("Run createFile with 2 thread: In thread 1 ...\n");
            pthread_create(&thread_id1, NULL, &createFile, (int*)500000); 
            pthread_join(thread_id1,NULL);

            printf("Run createFile with 2 thread: In thread 2 ...\n");
            pthread_create(&thread_id2, NULL, &createFile, (int*)500000); 
            pthread_join(thread_id2,NULL);

            clock_t end = clock(); //end timer
            printf("Time taken: %f \n", (double)(end - start)/CLOCKS_PER_SEC); //cal time taken
            break;
        }
        default:
        {
            printf("Not a valid argument!\n"); //check arg is not valid
            exit(1);
        }
        return 0;
    }
}