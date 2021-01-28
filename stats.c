#include "stats.h"

stats_s compute_statistics(float* numberset, int setlength)
{
    int i, j;
    float key = 0, sum = 0;
    stats_s statisticalData;
    
    /* Average of numbers */
    for(i=0;i<setlength;i++)
    {
        sum += numberset[i];
    }
    statisticalData.average = sum/setlength;
    
    /* Sorting range of numbers */
    for (i = 1; i < setlength; i++) 
    { 
        key = numberset[i]; 
        j = i - 1; 
        while (j >= 0 && numberset[j] > key) { 
            numberset[j + 1] = numberset[j]; 
            j = j - 1; 
        } 
        numberset[j + 1] = key; 
    }
    
    statisticalData.min = numberset[0];
    statisticalData.max = numberset[setlength-1]; 

    return statisticalData;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
