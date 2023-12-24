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
    mkfifo(vufifo, 0666);

    
    char data1[100], data2[100];
    
    while (1)
    {
        //read
        cur_fd = open(vufifo, O_RDONLY);
        read(cur_fd, data1,sizeof(data1));
        printf("Message: %s", data2);
        close(cur_fd);
        //write
        cur_fd = open(vufifo, O_WRONLY);
        write(cur_fd, data2,sizeof(data2));
        close(cur_fd);
    }
    return 0;
}