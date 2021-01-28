#define TRUE 1
#define FALSE 0

typedef struct Statistics{
  float min;
  float max;
  float average; 
}stats_s;

stats_s compute_statistics(float* numberset, int setlength);

typedef void (*alerter_funcptr)();
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);

extern int emailAlertCallCount;
extern int ledAlertCallCount;
