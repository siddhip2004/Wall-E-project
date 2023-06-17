#include "declaration.h"


static TaskHandle_t first_func;
static TaskHandle_t second_func;


static runtask p;

void Task_Handle(int s1, int s2, void (*func1)(), void (*func2)())
{

    enable_switches();
    if (p.s1 == 1)
    {
        p.s1 = SWITCH_1;
    }

    else if(p.s1 == 2)
    {
        p.s1 = SWITCH_2;
    }

    else if(p.s1 == 3)
    {
        p.s1 = SWITCH_3;
    }

    else if(p.s1 == 4)
    {
        p.s1 = SWITCH_4;
    }

    if (p.s2 == 1)
    {
        p.s2 = SWITCH_1;
    }

    else if(p.s2 == 2)
    {
        p.s2 = SWITCH_2;
    }

    else if(p.s2 == 3)
    {
        p.s2 = SWITCH_3;
    }

    else if(p.s2 == 4)
    {
        p.s2 = SWITCH_4;
    }
    

    p.peformFunction1 = func1;
    p.peformFunction2 = func2;

    xTaskCreate(p.peformFunction1, "first_func" , 4096, NULL, 1, &first_func);
    vTaskSuspend(first_func);

    xTaskCreate(p.peformFunction2, "second_func" , 4096, NULL, 1, &second_func);
    vTaskSuspend(second_func);
    
    
 
    while(1){

    if(read_switch(p.s1)){
    vTaskSuspend(second_func);
    vTaskResume(first_func);   
    }

    if (read_switch(p.s2)){
    vTaskSuspend(first_func);
    vTaskResume(second_func);   
    }
    
 }
    
    
}
