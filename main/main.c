#include "tasks.h"


static TaskHandle_t first_func;
static TaskHandle_t second_func;


static runtask p;
 
void Task_Handle(int s1, int s2, void (*func1)(), void (*func2)())
{
    ESP_LOGI("tasks", "run_func");

    enable_switches();
    if (s1 == 1)
    {
        p.s1 = SWITCH_1;
    }

    else if(s1 == 2)
    {
        p.s1 = SWITCH_2;
    }

    else if(s1 == 3)
    {
        p.s1 = SWITCH_3;
    }

    else if(s1 == 4)
    {
        p.s1 = SWITCH_4;
    }

    if (s2 == 1)
    {
        p.s2 = SWITCH_1;
    }

    else if(s2 == 2)
    {
        p.s2 = SWITCH_2;
    }

    else if(s2 == 3)
    {
        p.s2 = SWITCH_3;
    }

    else if(s2 == 4)
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
    ESP_LOGI("tasks", "func1"); 
    vTaskResume(first_func);   
    }


    else if (read_switch(p.s2)){
    ESP_LOGI("tasks", "func2"); 
    vTaskResume(second_func);   
    }

    vTaskDelay(1000 / portTICK_PERIOD_MS);
    
 }
    
    
}
