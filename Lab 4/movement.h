/*
 * movement.h
 *
 *  Created on: Feb 1, 2023
 *      Author: abrahimt
 */

#ifndef MOVEMENT_H_
#define MOVEMENT_H_
#include "open_interface.h"
#include "Timer.h"
#include "lcd.h"


void move_forward(oi_t *sensor_data, double millimeters);
void turn_clockwise(oi_t *sensor, short degrees);
void turn_counterclockwise(oi_t *sensor, short degrees);
void move_backwards(oi_t *sensor);

#endif /* MOVEMENT_H_ */
