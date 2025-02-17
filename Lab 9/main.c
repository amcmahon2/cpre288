/**
 * @file lab9_template.c
 * @author
 * Template file for CprE 288 Lab 9
 */

#include "Timer.h"
#include "lcd.h"
#include "ping.h"
#include "uart.h"
// Uncomment or add any include directives that are needed

#warning "Possible unimplemented functions"
#define REPLACEME 0

int main(void) {
    timer_init(); // Must be called before lcd_init(), which uses timer functions
    lcd_init();
    ping_init();
    uart_init();
    // YOUR CODE HERE
    char string[100];
    int j;
    while(1)
    {

      // YOUR CODE HERE
        sprintf(string, "%lf", ping_getDistance());
        lcd_printf(string);

        for(j=0; j < strlen(string); j++){
            uart_sendChar(string[j]);
        }
        uart_sendChar('\n');
        uart_sendChar('\r');

        timer_waitMillis(200);


    }

}
