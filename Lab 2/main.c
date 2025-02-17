
/**
 * main.c
 */
#include "open_interface.h"
#include "Timer.h"
#include "lcd.h"
#include "movement.h"

void main()
{
    timer_init(); // Initialize Timer, needed before any LCD screen functions can be called
                  // and enables time functions (e.g. timer_waitMillis)

    lcd_init();   // Initialize the LCD screen.  This also clears the screen.

    oi_t *sensor_data = oi_alloc(); // do this only once at start of main()
    oi_init(sensor_data); // do this only once at start of main()

    move_forward(sensor_data, 2000);
    /*
    char current_direction[1] = " ";
    int total_distance_straight = 0;
    int left_bump = 0;
    int right_bump = 0;




 //Flag for if bumpers are hit
 if (sensor_data->bumpLeft) {
 int left_bump = 1;
 } else if (sensor_data->bumpRight) {
 int right_bump = 1;
 }

 //while the sensor is clear, keep moving forward
 while ((left_bump + right_bump) < 1) {
 oi_update(sensor_data);
 //go forward for 2 m
 move_forward(sensor_data, 2000.0);
 //record how far the bot has moved in a straight line
 total_distance_straight += sensor_data -> distance;
 }

 //turn 90 degrees opposite direction (if both are hit then just go right)
 if (sensor_data->bumpLeft) {
 //move back 15 cm
 move_backward(sensor_data, 150.0);
 //turn right
 turn_clockwise(sensor_data, 90);
 //
 char current_direction = 'r';
 }
 else if (sensor_data->bumpRight || (sensor_data->bumpLeft & sensor_data->bumpRight)) {
 move_backward(sensor_data, 150.0);
 turn_counterclockwise(sensor_data, 90);
 char direction = 'l';
 }

 //move forward 25 cm
 move_forward(sensor_data, 250.0);

 //turn 90 degrees back
 if (current_direction == 'l') {
 turn_clockwise(sensor_data, 90);
 }
 else if (current_direction == 'r') {
 turn_counterclockwise(sensor_data, 90);
 }

 //resume traveling the 2 m
 move_forward(sensor_data, (2000 - total_distance_straight));
 */

oi_free(sensor_data);  // do this once at end of main()
}

