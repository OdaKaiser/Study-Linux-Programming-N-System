#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

pthread_t thread_id1, thread_id2; 
//define struct
typedef struct PersonalInfo
{
    char Name[20];
    int YofBirth;
    char PhoneNumber[20];
    char BirthPlace[20];
} PersonalInfo;

//threadHandler definition
void *threadHandler(void *infoPrecast)
{
    pthread_t tid = pthread_self(); //get current tid using *threadHandler()
    PersonalInfo *infoData = (PersonalInfo*) infoPrecast; // parametter of *threadHandler() is a void pointer => cast to PersonalInfo type pointer
    if (pthread_equal(tid, thread_id1)) //condition for thread_id1 
    {
        printf("This is thread 1 ID: %ld\n", tid);
        sleep(1);
    }
    else if (pthread_equal(tid, thread_id2)) //condition for thread_id1 
    {
        printf("This is thread 2 ID: %ld\n", tid);
        printf("Info bellow:\n-Name: %s\n-Year of Birth: %d\n-Phone Number: %s\n-Birth Place: %s\n", infoData->Name, infoData->YofBirth, infoData->PhoneNumber, infoData->BirthPlace);
    }
}

int main(void)
{
    //init data 
    PersonalInfo VuInfo = {"VU", 1997, "0987654321", "Nam Dinh"};
    //start thread1
    pthread_create(&thread_id1, NULL, &threadHandler, &VuInfo);
    //start thread2
    pthread_create(&thread_id2, NULL, &threadHandler, &VuInfo);
    //terminated all threads
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    
    return 0;
}