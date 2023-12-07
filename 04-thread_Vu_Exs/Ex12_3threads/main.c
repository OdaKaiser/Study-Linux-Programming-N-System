#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define FILE_NAME "information.txt"

pthread_mutex_t lock; 
pthread_t thread_1, thread_2, thread_3; 
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;
int condition_Var = 1;

//define struct
typedef struct PersonalInfo
{
    char Name[20];
    int YofBirth;
    char PhoneNumber[20];
    char BirthPlace[20];
} PersonalInfo;

void *func_StdInputHanler(void *infoPrecast)
{
    while (1)
    {
        pthread_mutex_lock(&lock);
        pthread_t ctid = pthread_self();

        while (condition_Var != 1)
        {
            pthread_cond_wait(&condition, &lock);
        } 
        
        PersonalInfo *infoData = (PersonalInfo*) infoPrecast;
        char charBirthYear[10];       
        printf("This is thread 1 ID: %ld\n", ctid);
        printf("This is thread 1 is obtaning data from stdin... \n");
        printf("Input your name: \n");
        fgets(infoData->Name, sizeof(infoData->Name),stdin);
        printf("Input your YoB: \n");
        fgets(charBirthYear, sizeof(charBirthYear),stdin);
        infoData->YofBirth = atoi(charBirthYear);
        printf("Input your Phone Number: \n");
        fgets(infoData->PhoneNumber, sizeof(infoData->PhoneNumber),stdin);
        printf("Input your Birth Place: \n");
        fgets(infoData->BirthPlace, sizeof(infoData->BirthPlace),stdin);

        condition_Var = 2;
        printf("~~~~~~~~~~~~Condition Var Value: %d~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", condition_Var);
        pthread_cond_signal(&condition);
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL);
}

void *func_StdOutputHanler(void *infoPrecast)
{
    while (1)
    {
        pthread_mutex_lock(&lock);
        pthread_t ctid = pthread_self();

        while (condition_Var != 2)
        {
            pthread_cond_wait(&condition, &lock);
        }

        PersonalInfo *infoData = (PersonalInfo*) infoPrecast;
        printf("This is thread 2 ID: %ld\n", ctid);
        printf("This is thread 2 is printing data to stdout... \n");
        printf("Your name is: %s\n", infoData->Name);
        printf("Your YoB is: %d\n", infoData->YofBirth);
        printf("Your Phone Number is: %s\n", infoData->PhoneNumber);
        printf("Your Birth Place is: %s\n", infoData->BirthPlace);
        
        condition_Var = 3;
        printf("~~~~~~~~~~~~Condition Var Value: %d~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", condition_Var);
        pthread_cond_signal(&condition);
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL);
}

void *func_FileStreamHander(void *infoPrecast)
{
    while (1)
    {
    pthread_mutex_lock(&lock);
    pthread_t ctid = pthread_self();

        while (condition_Var != 3)
        {
            pthread_cond_wait(&condition, &lock);
        }

        PersonalInfo *infoData = (PersonalInfo*) infoPrecast;
        printf("This is thread 3 ID: %ld\n", ctid);
        printf("This is thread 3 is writing data to file...\n");
        int fileDescriptor = open(FILE_NAME, O_APPEND | O_CREAT | O_RDWR, 0666);
        if (fileDescriptor > -1)
        {
            char charBirthYear[10]; 
            write(fileDescriptor, infoData->Name, strlen(infoData->Name));
            sprintf(charBirthYear,"%d", infoData->YofBirth);
            write(fileDescriptor, charBirthYear, strlen(charBirthYear));
            write(fileDescriptor, "\n", 1);
            write(fileDescriptor, infoData->PhoneNumber, strlen(infoData->PhoneNumber));
            write(fileDescriptor, infoData->BirthPlace, strlen(infoData->BirthPlace));
            write(fileDescriptor, "------", 6);
        } 
        else
        {
            printf("Open file \"%s\" error!\n", FILE_NAME);
        }
        close(fileDescriptor);

        condition_Var = 1;
        printf ("###########Continue with other student infos###################\n"); 
        printf("~~~~~~~~~~~~Condition Var Value: %d~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", condition_Var);
        pthread_cond_signal(&condition);
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL);
}

int main(void)
{
    //init data 
    PersonalInfo VuInfo;

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("Mutex init failed\n");
        exit(1);
    }
 
    pthread_create(&thread_1, NULL, func_StdInputHanler, &VuInfo);
    pthread_create(&thread_2, NULL, func_StdOutputHanler, &VuInfo);
    pthread_create(&thread_3, NULL, func_FileStreamHander, &VuInfo);

    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    pthread_join(thread_3, NULL);
    
    return 0;
}
