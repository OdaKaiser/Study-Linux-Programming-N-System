#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

#define SHARE_MEM_SIZE 2048
#define MEM_OBJ_NAME "share_mem_obj"

int main()
{
    const int sharedMemSize = SHARE_MEM_SIZE; // make memory a const type =>  stable
    char data[30] = "Data from producer ha ha ha";
    int sharedmem_fd = shm_open(MEM_OBJ_NAME, O_CREAT | O_RDWR, 0666);//creating a shared mem fd
    //check shared mem fd is created successfully
    if (sharedmem_fd < 0)
    {
        printf("Creating share memmory object error!\n");
        exit(EXIT_FAILURE);
    }

    // after shared mem fd is created SIZE = 0 => use ftruncate to set size
    ftruncate(sharedmem_fd, sharedMemSize);
    //map 
    mmap(0, sharedMemSize, PROT_READ | PROT_WRITE, MAP_SHARED, sharedMemSize, 0);
    printf("%s: Write data: %s\n", __FILE__, data);
    //unmap
    munmap(data, SHARE_MEM_SIZE);
    close(sharedMemSize);
    return 0;
}