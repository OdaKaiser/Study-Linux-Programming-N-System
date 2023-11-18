#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


#define FILE_NAME "ex4_filename"

int main(void)
{
    int fileDescriptor;

    fileDescriptor = open(FILE_NAME,O_CREAT|O_RDWR|O_APPEND,S_IRUSR|S_IXUSR|S_IWUSR);
    if (fileDescriptor > -1)
    {
        printf("The file \" %s \" has been created\n", FILE_NAME);
        write(fileDescriptor,"Original_data",13);    
    } 
    else
    {
        printf("Open file \"%s\" error!\n", FILE_NAME);
    }

    lseek(fileDescriptor,0,SEEK_SET);
    write(fileDescriptor," Additional_data1",17);    
    write(fileDescriptor," Additional_data2",17);  
    
    close(fileDescriptor);

    return 0;
}