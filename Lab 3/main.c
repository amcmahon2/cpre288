

/**
 * main.c
 */


#include "open_interface.h"
#include "cyBot_uart.h"
#include "cyBot_Scan.h"
#include <stdio.h>

#include "Timer.h"
#include "lcd.h"



void cyBOT_sendString(char *input) {
    int i;
    for (i = 0; i < strlen(input); i++) {
        cyBot_sendByte(input[i]);
    }
}



float getDistance(int i, cyBOT_Scan_t *scan_data) {
    float sum = 0;
   cyBOT_Scan(i, scan_data);
   sum += scan_data -> sound_dist;
   cyBOT_Scan(i, scan_data);
   sum += scan_data -> sound_dist;
   cyBOT_Scan(i, scan_data);
   sum += scan_data -> sound_dist;
   return sum / 3;
}



int getSmallestObject(cyBOT_Scan_t *scan_data) {
    int currAngle = 0;
    int objCounter = 0;
    int objWidth = 0;
    int smallestWidth = -1;
    int smallestAngle = -1;
    float lastDist = getDistance(0, scan_data);
    int objectDetected = 0;
    while (currAngle < 180) {
        float currDist = getDistance(currAngle, scan_data);

        if (objectDetected == 1) {
            if (currDist > lastDist + 10) {
                objectDetected = 0;
                if (objWidth == 0) {
                    objCounter--;
                } else {
                    char *buffer;
                    asprintf(&buffer, "%d \t %d \t %f \t %d\n\r", objCounter, currAngle - (objWidth / 2), lastDist, objWidth);
                    cyBOT_sendString(buffer);

                    if (smallestWidth > objWidth || smallestWidth == -1){
                        smallestWidth = objWidth;
                        smallestAngle = currAngle - (objWidth / 2);
                    }
                }

                objWidth = 0;
            } else {
                objWidth += 2;
            }
        } else {
            if (currDist < lastDist - 10) {
                objectDetected = 1;
                objCounter++;
            }
        }
        currAngle += 2;
        lastDist = currDist;
    }


    return smallestAngle;
}



int main(void)
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            {
    oi_t *sensor_data = oi_alloc(); // do this only once at start of main()
    oi_init(sensor_data); // do this only once at start of main()

    cyBot_uart_init();
    cyBOT_init_Scan(0b0011);

    right_calibration_value = 311500;
    left_calibration_value = 1309000;

    cyBOT_Scan_t *scan_data = calloc(1,sizeof(cyBOT_Scan_t));




    char *formatted_data = (char*) malloc(sizeof(char) * 100);
    int i;
    float sum;

    int angle;
    while (1) {
        char received = (char) cyBot_getByte();
        switch(received) {
        case 'w' :
            oi_setWheels(50, 50);
            break;
        case 'x' :
            oi_setWheels(-50, -50);
            break;
        case 'a' :
            oi_setWheels(50, -50);
            break;
        case 'd' :
            oi_setWheels(-50, 50);
            break;
        case 's' :
            oi_setWheels(0, 0);
            break;
        case 'm' :
            cyBOT_sendString("Degrees PING Distance \t (cm) \n\r");
            for (i = 45; i <= 135; i += 2) {
               sum = 0;
               cyBOT_Scan(i, scan_data);
               sum += scan_data -> sound_dist;
               cyBOT_Scan(i, scan_data);
               sum += scan_data -> sound_dist;
               cyBOT_Scan(i, scan_data);
               sum += scan_data -> sound_dist;
               sprintf(formatted_data, "%d \t %f \n\r", i, sum/3);
               cyBOT_sendString(formatted_data);
            }
            break;
        case 'q' :
            cyBOT_sendString("Num \t angle \t dist \t width \n\r");
            angle = getSmallestObject(scan_data);
            cyBOT_Scan(angle, scan_data);
            cyBot_sendByte(angle);
            break;
        }
        cyBot_sendByte(received);
    }

//     oi_free(sensor_data);  // do this once at end of main()
     return 0;

}


