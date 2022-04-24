/* 
 * File:   led_driver.h
 * Author: shan9
 *
 * Created on March 16, 2021, 2:25 PM
 */

#ifndef LED_DRIVER_H
#define	LED_DRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif

    
/*
 */
void set_start_frame(void);

/*
 */
void set_end_frame(void);

/*
 */
void set_led_value(uint8_t led, uint8_t drive, uint8_t blue, uint8_t green, uint8_t red);

/*
 */
void write_leds(void);


#ifdef	__cplusplus
}
#endif

#endif	/* LED_DRIVER_H */

