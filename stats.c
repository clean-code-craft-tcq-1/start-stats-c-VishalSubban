#include "stats.h"

int i, key, j, sum = 0;

struct Stats compute_statistics(const float* numberset, int setlength)
{
    struct Stats s;
    
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
    
    s.min = numberset[0];
    s.max = numberset[setlength-1]; 
        
    /* Average of numbers */
    for(i=0;i<setlength;i++)
    {
        sum += numberset[i];
    }
    s.average = sum/setlength;

}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
