/*
 * movement.c
 *
 *  Created on: Feb 1, 2023
 *      Author: abrahimt
 */
#include "open_interface.h"
#include "Timer.h"
#include "lcd.h"

void move_forward(oi_t *sensor_data, double millimeters) {
    double sum = 0; // distance member in oi_t struct is type double
    double distances = millimeters;
    oi_setWheels(250,250); //move forward at full speed
    int leftCheckHit = 0;
    int rightCheckHit = 0;


    while (sum < distances)
        {
            //sum += remainingDist
            oi_update(sensor_data);
            oi_setWheels(100, 100);

            if (sensor_data->bumpLeft == 1)
            {
                leftCheckHit = 1;
            }
            if (sensor_data->bumpRight == 1)
            {
                rightCheckHit = 1;
            }

            sum += sensor_data->distance;

            if (leftCheckHit == 1)
            {
                move_backwards(sensor_data);
                turn_clockwise(sensor_data, 90);
                move_forward(sensor_data, 250);
                turn_counterclockwise(sensor_data, 90);
                move_forward(sensor_data, (distances - sum));
                leftCheckHit = 0;
                sum -= 150;
                continue;
            }

            if (rightCheckHit == 1)
        {
                move_backwards(sensor_data);
                turn_counterclockwise(sensor_data, 90);
                move_forward(sensor_data, 250);
                turn_clockwise(sensor_data, 90);
                move_forward(sensor_data, (distances - sum));
                rightCheckHit = 0;
                sum -= 150;
                continue;
        }
    }

    oi_setWheels(0,0); //stop

}

void turn_clockwise(oi_t *sensor, short degrees) {
    double sumTurnRight = 0.0;
    oi_setWheels(-50, 50);
    degrees *= -1;

    while ((short) sumTurnRight > degrees) {
        oi_update(sensor);
        sumTurnRight += sensor->angle;
    }

    oi_setWheels(0, 0);
}

void turn_counterclockwise(oi_t *sensor, short degrees) {
    double sumTurnLeft = 0;
    oi_setWheels(50, -50);

    while ((short) sumTurnLeft < degrees) {
        oi_update(sensor);
        sumTurnLeft += sensor->angle;
    }

    oi_setWheels(0, 0);
}

void move_backward(oi_t *sensor, double distance_back) {
    double sumBack = 0.0;

    //Move backwards 150mm
    oi_setWheels(-100,-100);
    while (sumBack > -distance_back) {
        oi_update(sensor);
        sumBack += sensor->distance;
    }
}



