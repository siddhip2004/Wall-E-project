#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sra_board.h"


static TaskHandle_t series_blink;
static TaskHandle_t fib_blink;

static TaskHandle_t task_handle;

void Task_Handle()
{
    enable_switches();
 
    while(1){

    if(read_switch(SWITCH_1)){

    vTaskSuspend(fib_blink);
    vTaskResume(series_blink);
     
    }
    
    else if(read_switch(SWITCH_4)){

    vTaskSuspend(series_blink);
    vTaskResume(fib_blink);
    
    }
 }
    
    vTaskDelete(NULL);
}

    
    

void SERIES_LED_BLINK()
{

    ESP_ERROR_CHECK(enable_bar_graph());
    // enable_bar_graph() turns on the gpio pins, if it succeeds it returns ESP_OK else it returns ESP_FAIL 
    // If the argument of ESP_ERROR_CHECK() is not equal ESP_OK, then an error message is printed on the console, and abort() is called. 
    

     while(1){
   
        uint8_t var = 0x01;
        //0x01 = 0000 0001(only 8th led is on)
        // After left-shifting 0x01 8-times, we end up with 0x00. To recover the var variable, we initialise it with 0x01.

        
          while(1){

          
            // After left-shifting 0x01 8-times, we end up with 0x00. To recover the var variable, we initialise it with 0x01.
            if (var == 0x00)
            //if variable var is  0x00(i.e, all leds are off)
            //it checks whether the value of var has changed from 0x01 to 0x00.
            {
                var = 0x01;
           //setting var to  0x01(8th led is on)
            }         
            ESP_ERROR_CHECK(set_bar_graph(var));
            // var contains the data for the LEDs and it's been passed as an argument to set_bar_graph() function.
            
            
            var = var << 1;
            // It left shifts the values of var eg. from 0x01(means only the 8th led is on) it changes to 
            // 0x02 (means only the 7th LED is on). Similarly, the LED's are turned on one by one from the 8th to the 1st.
            vTaskDelay(1000 / portTICK_PERIOD_MS);
            //delay of 1s
        }

     }
  

    vTaskDelete(NULL);
}

void FIB_LED_BLINK()
{
    ESP_ERROR_CHECK(enable_bar_graph());
    // enable_bar_graph() turns on the gpio pins, if it succeeds it returns ESP_OK else it returns ESP_FAIL
    // If the argument of ESP_ERROR_CHECK() is not equal ESP_OK, then an error message is printed on the console, and abort() is called. 


     int a = 0;                            // first 2 no.s of fibonacci are 0 and 1 so initialising them with a and b
     int b = 1;
     int c = a+b;                         //Acc. to fibonacci series, current term is = sum of previous 2 terms
     uint8_t var = 0xFF;                  //keeping initial condition as: all 8 LEDs are blinking
     
    while(1)
    {
        var = var<<b;                    //0xFF = 1111 1111...initially b is 1, so var<<1 we get  1111 1110
        var = ~var;                      //here from 1111 1110 it gets converted to 0000 0001, so new var is 0000 0001
        
          
            ESP_ERROR_CHECK(set_bar_graph(var));               
            //0x01 = 0000 0001(only 8th led is on)
            vTaskDelay(1000 / portTICK_RATE_MS);
                                                            
            ESP_ERROR_CHECK(set_bar_graph(0x00));            
            //0x00 = 0000 0000(all leds are off)
            // setting values of all 8 leds to 0
            vTaskDelay(1000 / portTICK_RATE_MS);
            
      
        a=b;                              //incrementing the values of a,b,c to get LEDs displayed in required fibonacci series.
        b=c;
        c=a+b;
        
        var=0xFF;

        if(b>8)                            // since we have only 8 LEDs so after all 8 blink once...reseting all variables to their initial value so that it blinks in required fibonacci series again... 
        {
            a=0;
            b=1;
            c=a+b;
        }
    }
    
    vTaskDelete(NULL);
}


void app_main()
{
   
   
    xTaskCreate(&SERIES_LED_BLINK, "series_blink", 4096, NULL, 1, &series_blink);
    vTaskSuspend(series_blink);
   
    xTaskCreate(&FIB_LED_BLINK, "fib_blink" , 4096, NULL, 1, &fib_blink);
    vTaskSuspend(fib_blink);
    
    xTaskCreate(&Task_Handle , "task_handle" , 4096, NULL, 0, &task_handle);
    
}


