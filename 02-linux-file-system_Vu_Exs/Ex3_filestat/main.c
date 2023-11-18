#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <libgen.h>
#include <time.h>
#include <unistd.h>

#define FILE_NAME "test_file"

int main (void)
{
    struct stat fileStat;
    
    int fileDescriptor = open(FILE_NAME, O_CREAT|O_RDWR|O_TRUNC, S_IRUSR| S_IWUSR | S_IXUSR);

    char *file = FILE_NAME;
    
    stat(file, &fileStat);

    if (fileDescriptor > -1 )
    {
        write(fileDescriptor,"Data",4);
    }
    else
    {
        printf("Creating file in \"%s\" error!\n", FILE_NAME);
    }

    printf("File name             : %s\n", FILE_NAME);
    printf("File Type             : ");
    switch (fileStat.st_mode & S_IFMT) {
        case S_IFBLK:   printf("block device\n");       break;
        case S_IFCHR:   printf("character device\n");   break;
        case S_IFDIR:   printf("directory\n");          break;
        case S_IFIFO:   printf("FIFO/pipe\n");          break;
        case S_IFLNK:   printf("symlink\n");            break;
        case S_IFREG:   printf("regular file\n");       break;
        case S_IFSOCK:  printf("socket\n");             break;
        default:        printf("unknown?\n");
    }  
    printf("File I-node number    : %ld\n", fileStat.st_ino);
    printf("File Size             : %ld\n", fileStat.st_size);
    printf("Last access           : %s\n", ctime(&fileStat.st_atim.tv_sec));
    printf("Last status change    : %s\n", ctime(&fileStat.st_mtim.tv_sec));
    printf("Last file modification: %s\n", ctime(&fileStat.st_ctim.tv_sec));
    
    close(fileDescriptor);
    return 1;
}