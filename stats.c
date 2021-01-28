/******************************************************* INCLUDES *******************************************************/
#include "stats.h"

/******************************************************* VARIABES & TYPES ********************************************/
int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

/*************************************************** FUNCTION DEFINITIONS ********************************************/
stats_s compute_statistics(float* numberset, int setlength)
{
    int index, swapIndex;
    float keyValue = 0, sum = 0;
    stats_s statisticalData;
    
    /* Average of numbers */
    for(index=0;index<setlength;index++)
    {
        sum += numberset[index];
    }
    statisticalData.average = sum/setlength;
    
    /* Sorting range of numbers */
    for (index = 1; index < setlength; index++) 
    { 
        keyValue = numberset[index]; 
        swapIndex = index - 1; 
        while (swapIndex >= 0 && numberset[swapIndex] > keyValue) { 
            numberset[swapIndex + 1] = numberset[swapIndex]; 
            swapIndex = swapIndex - 1; 
        } 
        numberset[swapIndex + 1] = keyValue; 
    }
    
    statisticalData.min = numberset[0];
    statisticalData.max = numberset[setlength-1]; 

    return statisticalData;
}



void check_and_alert(float maxThreshold, alerter_funcptr alerters[], stats_s computedStats)
{
    if(computedStats.max > maxThreshold)
    {
        if(alerters[0] != NULL)
        {
            (*alerters[0])();
        }
        if(alerters[1] != NULL)
        {
            (*alerters[1])();
        }
    }
}
