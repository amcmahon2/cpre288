
#include "Timer.h"
#include "lcd.h"
#include <string.h>
#include "open_interface.h"
#include "movement.h"
#include "cyBot_uart.h"
#include "cyBot_Scan.h"
#include <stdlib.h>
#include <stdint.h>
#include <inc/tm4c123gh6pm.h>
#include <stdbool.h>
#include "driverlib/interrupt.h"
#include "uart.h"
#include <math.h>
#include "ADC.h"


int main (void) {

    uint32_t i;
    float j;
    timer_init();
    lcd_init();
    ADC0_InitSWTriggerSeq3_Ch9();
    //lcd_printf("Ready");


    while(1){
       i = ADC0_InSeq3();
       j = 3.62*pow(10,6)*pow(i,-1.72);
       lcd_printf("%u  %f",i,j);
       timer_waitMillis(1000);
    }
    //1/raw input value against distance to get a linear relationship


    return 0;

}

