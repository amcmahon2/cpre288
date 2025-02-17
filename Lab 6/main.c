/**
 * lab6_template.c
 *
 * Template file for CprE 288 Lab 6
 *
 * @author Diane Rover, 2/15/2020
 *
 */
#include "uart-interrupt.h"

// Uncomment or add any include directives that are needed
#include "lcd.h"
#include "open_interface.h"
#include "Timer.h"
#include "movement.h"
#include "cyBot_uart.h"
#include "cyBot_Scan.h"
// #include "movement.h"
// #include "button.h"


//#warning "Possible unimplemented functions"
#define REPLACEME 0


int main(void) {
  timer_init(); // Must be called before lcd_init(), which uses timer functions
  lcd_init();
  uart_interrupt_init();
  cyBOT_Scan_t scanData;

  // YOUR CODE HERE
    cyBOT_init_Scan(0b0111);
    right_calibration_value = 285259;
    left_calibration_value = 1272250;

    cyBOT_Scan_t scan;

    cyBOT_Scan(0, &scan);
    timer_waitMillis(300);

    int i = 0, k = 0, j = 0;
    int degrees;
    char title[] = "Angle PING Distance IR raw value\n";
    char data;
    char dist[] = "";

  while(1)
  {
//    if(uart_receive() == 'g'){
//        while(1){
////            if(uart_receive() == 's'){
////                //uart_interrupt();
////            }
//
//            else {
//                if(i > 180){
//                    i = 0;
//                }
//
//                cyBOT_Scan(i, &scan);
//                i++;
//
//                data = cyBot_getByte_blocking();
//                cyBot_sendByte(data);
//
//                for (j=0; j<strlen(title); j++)
//                cyBot_sendByte(title[j]);
//
//                cyBot_sendByte('\n\r'); // start a new line
//
//                for(degrees = 0; degrees <= 180; degrees +=5)
//                {
//                    cyBOT_Scan(degrees, &scanData); //scan every 5 degrees
//                    sprintf(dist, "%d \t %f \t %i \n\r", degrees, scanData.sound_dist, scanData.IR_raw_val); //take scan and make char array
//
//                    for (k=0; k<strlen(dist); k++){
//                        cyBot_sendByte(dist[k]); // print char array to putty
//                    }
//
//                }
//            }
//        }

//    }

  }

}
