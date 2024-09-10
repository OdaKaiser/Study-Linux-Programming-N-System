#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    //data write to files
    char databuffer[100];
    int count;
    //fds for each file
    int fileDescriptorA, fileDescriptorB;
    fileDescriptorA = open("A.txt",O_RDWR|O_CREAT,0667);
    fileDescriptorB = open("B.txt",O_RDWR|O_CREAT,0667);
    //check error
    if (fileDescriptorA == -1 || fileDescriptorB == -1)
    {
        printf("Opening file error!\n");
        exit(0);
    }

    //start to save begin time
    clock_t start = clock();
    for (count = 0; count <=50000; count++)
    {
        printf("Performing write operation %d \n",count);
        sprintf(databuffer, "%d\n" , count);
        write(fileDescriptorA, databuffer,strlen(databuffer));
        write(fileDescriptorB, databuffer,strlen(databuffer));
    }
    //end to save end time
    clock_t end = clock();
    //calculate performing time
    printf("Time taken: %f \n", (double)(end - start)/CLOCKS_PER_SEC);
    //close fds
    close(fileDescriptorA);
    close(fileDescriptorB);
    return 0;
}