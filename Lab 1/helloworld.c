/// Simple 'Hello, world' program
/**
 * This program prints "Hello, world" to the LCD screen
 * @author Chad Nelson
 * @date 06/26/2012
 *
 * updated: phjones 9/3/2019
 * Description: Added timer_init call, and including Timer.h
 */

#include "Timer.h"
#include "lcd.h"


int main (void) {

timer_init(); // Initialize Timer, needed before any LCD screen functions can be called
             // and enables time functions (e.g. timer_waitMillis)

lcd_init();   // Initialize the LCD screen.  This also clears the screen.

// Print "Hello, world" on the LCD
//lcd_printf("Hello, world");

    char array1[100] = "Microcontrollers are fun!";
    char array2[100];
    int len = strlen(array1);
    int i = 0;
    int j = 19;
    int a = 0;
    for (i = 0; i < 100; i = i + 1) // array 2 stores all spaces
    {
        array2[i] = ' ';
    }
    for (i = 0; i < len + 1; i = i + 1) // array 2 is populated with array 1 string beginning at index 19
    {
        array2[j] = array1[i];
        j = j + 1;
    }
    //lcd_printf("%c\n",array2[20]); // test case to ensure array 2 is populated correctly
    while (a == 0)
    {
        for (i = 0; i < len + 21; i = i + 1)
        {
            lcd_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", array2[i],
                       array2[i + 1], array2[i + 2], array2[i + 3],
                       array2[i + 4], array2[i + 5], array2[i + 6],
                       array2[i + 7], array2[i + 8], array2[i + 9],
                       array2[i + 10], array2[i + 11], array2[i + 12],
                       array2[i + 13], array2[i + 14], array2[i + 15],
                       array2[i + 16], array2[i + 17], array2[i + 18],
                       array2[i + 19]);
            timer_waitMillis(300);
        }

    }
    return 0;
}
