/*
 * movement.h
 *
 *  Created on: Feb 1, 2023
 *      Author: lgossman
 */

#ifndef MOVEMENT_H_
#define MOVEMENT_H_

double move_forward(oi_t *sensor_data, double distance_mm);

double move_backward(oi_t *sensor_data, double distance_mm);

void turn_right(oi_t *sensor_data, double degrees);

void turn_left(oi_t*sensor_data, double degrees);

double obstacle(oi_t*sensor_data, double distance_mm);

#endif /* MOVEMENT_H_ */
