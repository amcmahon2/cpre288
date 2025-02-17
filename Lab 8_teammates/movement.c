/*
 * movement.c
 *
 *  Created on: Feb 1, 2023
 *      Author: lgossman
 */
#include "Timer.h"
#include "lcd.h"
#include <string.h>
#include "open_interface.h"

//void double move_forward(oi_t *sensor_data, double distance_mm)

double move_forward(oi_t *sensor_data, double distance_mm){
    double sum = 0;
    oi_setWheels(200,200);
    while (sum < distance_mm) {
        oi_update(sensor_data);
        sum += sensor_data -> distance;
    }
    oi_setWheels(0,0);
    return sum;
}

double move_backward(oi_t *sensor_data, double distance_mm){
    double sum = 0;
    oi_setWheels(-200,-200);
    while (sum > distance_mm) {
        oi_update(sensor_data);
        sum += sensor_data -> distance;
    }
    oi_setWheels(0,0);
    return sum;
}

void turn_right(oi_t *sensor_data, double degrees){
    double sum = 0;
    oi_setWheels(-200,200);
    while (sum > -degrees) {
        oi_update(sensor_data);
        sum += sensor_data -> angle;
    }
    oi_setWheels(0,0);
}

void turn_left(oi_t*sensor_data, double degrees) {
    double sum = 0;
    oi_setWheels(200,-200);
    while (sum < degrees) {
        oi_update(sensor_data);
        sum += sensor_data -> angle;
    }
    oi_setWheels(0,0);
}

double obstacle(oi_t*sensor_data, double distance_mm) {
    int sum = 0;
    while (sum < distance_mm) {
        oi_setWheels(200,200);
        oi_update(sensor_data);
        sum += sensor_data -> distance;
        if(sensor_data->bumpLeft){
            //sum += move_backward(sensor_data, -150);
            turn_right(sensor_data,90);
            move_forward(sensor_data, 250);
            turn_left(sensor_data, 90);
            move_forward(sensor_data, 450);
            turn_left(sensor_data, 90);
            move_forward(sensor_data, 250);
            turn_right(sensor_data,90);
            sum = sum + 450;
        }
        if(sensor_data->bumpRight){
            //sum += move_backward(sensor_data, -150);
            turn_left(sensor_data,90);
            move_forward(sensor_data, 250);
            turn_right(sensor_data, 90);
            move_forward(sensor_data, 450);
            turn_right(sensor_data, 90);
            move_forward(sensor_data, 250);
            turn_left(sensor_data,90);
            sum = sum + 450;
        }
    oi_setWheels(0,0);
    }
return sum;
}


