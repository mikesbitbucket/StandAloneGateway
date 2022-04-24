/* 
 * File:   usercode.h
 * Author: shan9
 *
 * Created on March 8, 2021, 5:59 PM
 */

#ifndef USERCODE_H
#define	USERCODE_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <xc.h>

#define NUM_LEDS    4  // number of LEDs
    

    void Write_LED_Array(uint8_t Red_Intensity, uint8_t Green_Intensity, uint8_t Blue_Intensity);
    void Write_LEDs(void);
    void Write_LEDs_Delay(void);
    void loop(void);


#ifdef	__cplusplus
}
#endif

#endif	/* USERCODE_H */

