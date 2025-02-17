/**
 * @file lab9_template.c
 * @author
 * Template file for CprE 288 Lab 9
 */

#include <cyBot_uart.h>
#include <lcd.h>
#include <ping.h>
#include <Timer.h>
#include <servo.h>
#include <button.h>


// Uncomment or add any include directives that are needed

#warning "Possible unimplemented functions"
#define REPLACEME 0

int main(void) {
	timer_init(); // Must be called before lcd_init(), which uses timer functions
	lcd_init();
	servo_init();
	button_init();


	servo_move(0);
	timer_waitMillis(500);
	servo_move(50);
	timer_waitMillis(500);
	servo_move(90);
	timer_waitMillis(500);
	servo_move(120);
	timer_waitMillis(500);
	servo_move(180);

    timer_waitMillis(500);
    servo_move(180);

	while(1) {
	    button_move();
	}

	return 0;

}
