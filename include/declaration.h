#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sra_board.h"

void Task_Handle();
typedef void (*funcptr1) ();
typedef void (*funcptr2) ();

typedef struct runfunc
{
    int s1,s2;
    funcptr1 peformFunction1;
    funcptr2 peformFunction2;
}runtask;