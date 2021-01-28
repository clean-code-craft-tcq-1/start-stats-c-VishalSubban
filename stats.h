/******************************************************* INCLUDES *******************************************************/
#include <stdlib.h>
#include "alerters.h"

/******************************************************* MACROS *******************************************************/
#define TRUE 1
#define FALSE 0

/******************************************************* VARIABES & TYPES ********************************************/
extern int emailAlertCallCount;
extern int ledAlertCallCount;

typedef struct Statistics{
  float min;
  float max;
  float average; 
}stats_s;


/*************************************************** FUNCTION PROTOTYPES ********************************************/
/* Func Name: compute_statistics
   Description: computes average, maximum and minimum values from the given set of numbers
   Parameters: float, int
   Return Type: structure
*/
stats_s compute_statistics(float* numberset, int setlength);

/* Func Name: alerter_funcptr
   Description: Pointer to functions which raises email and LED alerts
   Parameters: None
   Return Type: void
*/
typedef void (*alerter_funcptr)();

/* Func Name: check_and_alert
   Description: checks whether the maximum number from the set is greater than the threshold
                and raises alerts if maximum number is greater than threshold
   Parameters: float, function_ptr, structure
   Return Type: void
*/
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], stats_s computedStats);
