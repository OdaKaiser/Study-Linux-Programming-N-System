#include <stdio.h>
#include <string.h>
#include <mqueue.h>  
#include <errno.h> 
#include <stdlib.h>

#define MQ_MODE (S_IRUSR | S_IWUSR )
#define MESQUE_NAME "/mesque" 


typedef struct Person 
{
    char Name[50];
    int Age;
    char HomeTown[100];
    char PhoneNo[100];
} Person;

typedef struct Message 
{
    long Priority_Id;
    Person Person;
}Message;

void inputData(Message *infoData, int msg_id)
{
    mq_receive(msg_id, (char *)&infoData, sizeof(infoData),NULL);
    printf("Input your data ....\n");
    printf("Input your ID: ");
    scanf("%li", &infoData->Priority_Id);
    while (infoData->Priority_Id < 0)
    {
        printf("Invalid ID, try again: ");
        scanf("%li", &infoData->Priority_Id);
    }

    printf("Input your name: ");
    fgets(infoData->Person.Name, sizeof(infoData->Person.Name),stdin);
    printf("Input your Age: ");
    scanf("%i", &infoData->Person.Age);
    printf("Input your Phone Number: ");
    fgets(infoData->Person.PhoneNo, sizeof(infoData->Person.PhoneNo),stdin);
    printf("Input your Birth Place: ");
    fgets(infoData->Person.HomeTown, sizeof(infoData->Person.HomeTown),stdin);
    mq_send(msg_id, (char *)&infoData, sizeof(infoData),NULL);
}

void showDatabyID(Message *infoData, long info_ID, int msg_id)
{
    
    mq_receive(msg_id, (char *)&infoData, sizeof(infoData),NULL);
    printf("Show all data by id %li\n", info_ID);
    if (info_ID == infoData->Priority_Id)
    {
        printf("Your name is: %s\n", infoData->Person.Name);
        printf("Your YoB is: %d\n", infoData->Person.Age);
        printf("Your Phone Number is: %s\n", infoData->Person.PhoneNo);
        printf("Your Birth Place is: %s\n", infoData->Person.HomeTown);
    }
    else
    {
        printf("Not matched!");
    }
    mq_send(msg_id, (char *)&infoData, sizeof(infoData),NULL);
}

void showAllData()
{
    printf("Show all data\n");
}

void deleteData(Message *infoData, long info_ID, int msg_id)
{
    printf("Delete data\n");
    if (info_ID == infoData->Priority_Id)
    {
        printf("Matched! Deleting...\n");
        mq_receive(msg_id, (char *)&infoData, sizeof(infoData),NULL);
        mq_send(msg_id, (char *)&infoData, sizeof(infoData),NULL);
    }
    else
    {
        printf("Not matched! Skip\n");
    }
}

int main(int argc, char *argv[])  
{   
    //show menu
    printf("########################\n");
    printf("##_MESSAGE QUEUE DEMO_##\n");
    printf("########################\n");
    printf("1.-----Input data-------\n");
    printf("2.-----Show data by ID--\n");
    printf("3.-----Show all data----\n");
    printf("4.-----Delete data------\n");
    printf("0.-----Exit-------------\n");
    
    Message mainMes;
    int status = 0;
    int choice;
    long id = 0;

    mqd_t message_queue_id = mq_open(MESQUE_NAME, O_RDWR | O_CREAT | O_NONBLOCK, MQ_MODE, NULL);
    if (message_queue_id == -1) 
    {
        perror("Unable to create queue");
        return 2;
    }

    scanf("%d", &choice);
    do
    {
        switch (choice)
        {
            case 0:
                printf("Exit program!\n");
                exit(EXIT_SUCCESS);
            case 1:
                inputData(&mainMes, message_queue_id); 
                break;
            case 2:
                printf("Input ID: ");
                scanf ("%li", &id);
                showDatabyID(&mainMes, id, message_queue_id);
                mq_send(message_queue_id, (char *)&mainMes, sizeof(mainMes),NULL);
                id = 0;
                break;
            case 3:
                //not completed
                showAllData();
                break;
            case 4:
                printf("Input ID: ");
                scanf ("%li", &id);
                deleteData(&mainMes, id, message_queue_id);
                id = 0;
                break;
            default:
                printf("Wrong Choice. Enter again\n");
                printf("########################\n");
                printf("##_MESSAGE QUEUE DEMO_##\n");
                printf("########################\n");
                printf("1.-----Input data-------\n");
                printf("2.-----Show data by ID--\n");
                printf("3.-----Show all data----\n");
                printf("4.-----Delete data------\n");
                printf("0.-----Exit-------------\n");
                scanf("%d", &choice);
                break;
        }
    } while (choice != 0);

    status = mq_close(message_queue_id);
    if (status == -1) {
        perror("Unable to close message queue");
        return 2;
    }
    
    status = mq_unlink(MESQUE_NAME);
    if (status == -1) 
    {
        printf("Unable to delete queue\n");
    }  
    return 0; 
}


