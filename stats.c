#include "stats.h"

int i, key, j, sum = 0;

stats_s compute_statistics(const float* numberset, int setlength)
{
    stats_s statisticalData;
    
    /* Sorting range of numbers */
    for (i = 1; i < n; i++) 
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
        
    /* Average of numbers */
    for(i=0;i<setlength;i++)
    {
        sum += numberset[i];
    }
    statisticalData.average = sum/setlength;

}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
