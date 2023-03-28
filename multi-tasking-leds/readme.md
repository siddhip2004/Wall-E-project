# Multi-Tasking LEDs

Blinking LEDs as per user's wish  using the switches on SRA board in two formats: 
 * ***Series*** blinking
 * ***Fibonacci*** blinking

-------------------------------

 ## Table of Contents
 * [Multi-Tasking LEDs](#multi-tasking-leds)
     
    * [About The Project](#about-the-project)
      * [Tech Stack](#tech-stack)
      * [File Structure](#file-structure)
      * [Data Processing](#data-processing)
   
   * [How to Use](#how-to-use)
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
~~build

~~components
    -sra-board-component

~~front-end
    -index.html

~~CMakeLists.txt

~~readme.md

~~main
   -CMakeLists.txt
   -component.mk
   -main.c

~~sdkconfig
```

### <li>Data Processing :</li>
On flashing the code to ESP-32 the commands are sent to the leds and the switches

----------------

## How to Use :-

<li> Prerequisites :</li>
   
### Onto your terminal   

1. Install ESP-IDF : https://github.com/espressif/esp-idf

2. Clone the Project:
```sh
git clone https://github.com/siddhip2004/Wall-E-project.git
```


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

1. Press the switch  **1** on SRA board to see leds blink in the **series** pattern
2. Press the switch **4** on SRA board to see leds blink in the **fibonacci** pattern

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






    