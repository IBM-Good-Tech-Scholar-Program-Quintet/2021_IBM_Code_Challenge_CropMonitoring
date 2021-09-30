#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int sensorState=0,lastState=0;
int flag=0;
int fun(int moisture){
    lastState = sensorState;
    if(moisture<=10){
       sensorState=1;
    }
    else{
       sensorState=0;
    }
    if (sensorState == 1 && lastState == 0) {
        flag=0;
        return flag;
    } 
    
    else {
        flag=2;
        return flag;
    }
}
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}
int main(){
    int temperature[20];
    int humidity[20];
    int moisture[20];
    int i=0;
    FILE *file1 = fopen("Temperature.txt", "r");
    int num;
    while(fscanf(file1, "%d", &num) > 0) {
        temperature[i] = num;
        i++;
    }
    fclose(file1);
    i=0;
    FILE *file2 = fopen("Humidity.txt", "r");
    while(fscanf(file2, "%d", &num) > 0) {
        humidity[i] = num;
        i++;
    }
    fclose(file2);
    i=0;
    FILE *file3 = fopen("Moisture.txt", "r");
    while(fscanf(file3, "%d", &num) > 0) {
        moisture[i] = num;
        i++;
    }
    fclose(file3);
    int len = 20;

    while (len--)
    {
        printf("Temperature is: %d \n",temperature[len]);
        printf("Humidity is: %d \n",humidity[len]);
        printf("Moisture is: %d \n",moisture[len]);
        fun(moisture[len]);
        if(flag==0){
            printf("Crop needs water, send notification. \n");
            printf("Water your plants.\n");
        }
        
        else{
            printf("Crop is healthy.\n");
        }
        printf("\n");
        delay(3);
    }
    
    return 0;
}