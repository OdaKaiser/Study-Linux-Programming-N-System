#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    //fifo path
    int cur_fd;
    char * vufifo = "./vufifo";
    if (mkfifo(vufifo, 0666) == -1)
    {
        printf("Creating pipe error!");
        exit(EXIT_FAILURE);
    }
    
    char data1[100] = "Data 1 Ha HA", data2[100] = "Data 2 Ha HA";
    
    while (1)
    {
        //write
        cur_fd = open(vufifo, O_WRONLY);
        write(cur_fd, data2,sizeof(data2));
        close(cur_fd);
        //read
        cur_fd = open(vufifo, O_RDONLY);
        read(cur_fd, data1,sizeof(data1));
        printf("Message: %s", data1);
        close(cur_fd);
    }
    return 0;
}