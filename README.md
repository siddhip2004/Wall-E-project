# Multi-Tasking Bot

Making the bot peform in the manner user wants by providing it's own task/function

-------------------------------

 ## Table of Contents
 * [Multi-Functions](#multi-Functions)
     
    * [About The Project](#about-the-project)
      * [Tech Stack](#tech-stack)
      * [File Structure](#file-structure)
      * [Data Processing](#data-processing)
   
   * [How to Use](#how-to-use)
     * [Task's_Code](#Task's-Code)
     * [Switch_Function_Input](#Switch-Function-Input)
     * [Prerequisites](#prerequisites)
     

   * [Demonstration](#demonstration)

   * [Contributors](#contributors)

   * [Acknowledgement and Resources](#acknowledgement-and-resources)

-----------------

## About The Project :-

###  <li>Tech Stack :</li>
This project uses the [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/) development framework.

It uses [FreeRTOS](https://www.freertos.org/openrtos.html).


### <li>File Structure :</li>

```
├── CMakeLists.txt
├── include
│   └── tasks.h
├── main
│   ├── CMakeLists.txt
│   ├── component.mk
│   └── main.c
├── README.md
└── sdkconfig


```

### <li>Data Processing :</li>
1. After the user writes it's function,the task is created with help of xTaskCreate()

2. Structure stores user's data<br>
   typedef struct runfunc <br>
{<br>
    int s1,s2;
    <br>funcptr1 peformFunction1;
    <br>funcptr2 peformFunction2;<br>
}runtask;
<br>
<br>
The number of switches to use and address of functions that user gives are bound with the switches with help of structure
<br>

3. On flashing the commands are sent to ESP-32 to peform the required task

----------------

## How to Use :-
<li> Task's Code :</li>

In your required folder create a main.c file that contains the code of the function you want bot to peform

<li> Switch_Function_Input :</li>

In the main.c file already made, type Task_Handle() and
inside it's paranthesis provide switch number and address of function (two each) to be peformed

<li> Prerequisites :</li>
   
### Onto your terminal   

1. Install ESP-IDF : https://github.com/espressif/esp-idf

2. Clone the Project:
(Make a components directory in required folder and clone the below there)
```sh
git clone --recursive https://github.com/siddhip2004/Wall-E-project.git

git clone --recursive https://github.com/SRA-VJTI/sra-board-component.git
```
 Open the folder in your terminal 
 and follow the below command
```sh
$(folder) get_idf
```

like above use the following commands :

3. Building The Project :
```sh
idf.py build
```
4. Required USB port in use :
```sh
sudo chmod /dev/ttyUSBO
```
5. To Flash the code to ESP-32 :
```sh
idf.py -p /dev/tty(port into use) flash monitor
```

-----------------

## Demonstration :

1. Press the switches that you have given as input and see your two tasks getting implemented
------------------

## Contributors :
[Siddhi Parekh](#https://github.com/siddhip2004)

-----------------

## Acknowledgement and Resources :

* [SRA_VJTI](#https://github.com/SRA-VJTI)
* [SRA Wall-E Workshop](https://github.com/SRA-VJTI/Wall-E_v2.2)
* [FreeRTos](#https://www.freertos.org/)
* Grateful to [Zain Siddavatam](https://github.com/SuperChamp234/RISC)
-----------------------






    