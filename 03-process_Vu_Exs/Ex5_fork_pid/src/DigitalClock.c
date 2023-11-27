#include <stdio.h>
#include <time.h>

void digitalClock()
{
    //get current system time assign to 3 int variables 
    time_t time_tPointer = time(NULL); //struct tm localtime use *time_t
    struct tm cTime = *localtime(&time_tPointer); //we can get time as primitive type form here
    int hour = cTime.tm_hour;
    int min = cTime.tm_min;
    int sec = cTime.tm_sec;

    //output to terminal format bellow
    while(1)
    {
        // print to stdout each seccond and clear stdout
        system("clear");
        printf("--DIGITALCLOCK--\n");
        printf("|--|%02d:%02d:%02d|--|\n",hour,min,sec);
        printf("----------------\n");
        fflush(stdin);     
        
        //handling logic for clock
        sec++;

        if(sec == 60)
        {
            min +=1;
            sec = 0;
        }
        
        if(min == 60)
        {
            hour +=1;
            min = 0;
        }

        if(hour == 24)
        {
            hour = 0;
            min = 0;
            sec = 0;
        }
    
        sleep(1);
    }
}   