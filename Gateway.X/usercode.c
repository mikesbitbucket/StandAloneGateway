/*
 * User Code
 */

#include "usercode.h"
#include "mcc_generated_files\mcc.h"
#include "led_driver.h"
#include <xc.h>

// Note: Some defines in .h file so it can be used in other modules


//#define LOOP_COLORS
//#define DELAY_TIME   6000   // in milliseconds - this is max for the delay funciton, so we loop 10 times to get to 60 seconds
//#define DRIVE        15     /* 0 = min, 31 = Max, <31 = 31 */
//#define BLUE        150     /* 0 to 255 */
//#define GREEN       150     /* 0 to 255 */
//#define RED         150     /* 0 to 255 */

#define LED11    0b11101110
#define LED10    0b11101000
#define LED01    0b10001110
#define LED00    0b10001000
#define ARRAY_SIZE  (NUM_LEDS*12)  // number of array elements needed

const uint8_t LEDVALS[4] = {LED00, LED01, LED10, LED11};

uint8_t LED_Array[ARRAY_SIZE];  // Need 48 bytes - 2 bits are packed in each byte, 24 bits per LED, 96 bits need to be sent for 4 LEDs
                        // Could do some define stuff here to take into account different number of LEDs

void Write_LED_Array(uint8_t Red_Intensity, uint8_t Green_Intensity, uint8_t Blue_Intensity)
{
    uint8_t i,j,mult;  // GP counters
    uint8_t RedVal, GrnVal, BluVal;
    
    for(i=0; i < NUM_LEDS; i++)
    {
        // loop through each LED
        // Red first - 4 bytes per R-G-B Value = 8 bits in the actual LED
        // Have to go from MSBs to LSBs - that's why it goes backwards into array...
        mult = i*12; // only do this mult once per color - saves time
        RedVal = Red_Intensity; GrnVal = Green_Intensity; BluVal = Blue_Intensity;
        
        for(j=3; j<255; j--) // Relies on rolling under to 255 on decrement
        {
            LED_Array[mult+j] = LEDVALS[RedVal & 0x03]; // Mask lower 2 bits, index into arrary
            RedVal = RedVal >> 2;
        }
        // Green LED
        mult += 4; // add offset
        for(j=3; j<255; j--) // Relies on rolling under to 255 on decrement
        {
            LED_Array[mult+j] = LEDVALS[GrnVal & 0x03]; // Mask lower 2 bits, index into arrary
            GrnVal = GrnVal >> 2;
        }
        // Blue LED
        mult += 4;
        for(j=3; j<255; j--) // Relies on rolling under to 255 on decrement
        {
            LED_Array[mult+j] = LEDVALS[BluVal & 0x03]; // Mask lower 2 bits, index into arrary
            BluVal = BluVal >> 2;
        }
        
//        for(j=0,k=3; j<4; j++, k--)
//        {
//            LED_Array[mult+j] = LEDVALS[((uint8_t)(Red_Intensity >> (k*2)) & 0x03)]; // Mask lower 2 bits, index into array 
//        }
//        // Green LED
//        mult = i*12; // only do this mult once per color - saves time
//        for(j=0,k=3; j<4; j++, k--)
//        {
//            LED_Array[mult+j] = LEDVALS[((uint8_t)(Red_Intensity >> (k*2)) & 0x03)]; // Mask lower 2 bits, index into array 
//        }
//        // Blue LED
//        mult = i*12; // only do this mult once per color - saves time
//        for(j=0,k=3; j<4; j++, k--)
//        {
//            LED_Array[mult+j] = LEDVALS[((uint8_t)(Red_Intensity >> (k*2)) & 0x03)]; // Mask lower 2 bits, index into array 
//        }
    }
    
} // End Write LED Array

void Write_LEDs(void)
{
    uint8_t i;
    
    // Write out array values to LEDs
    SPI1CON0bits.EN = 1;
    //SPI1TCNTL = (uint8_t)(NUM_LEDS*12);  // With packed bytes, we only need half  (4 leds = 48 byes)
    SPI1TCNTL = 48  ;  // With packed bytes, we only need half  (4 leds = 48 byes)
    for(i=0; i<48; i++)  // Write Array
    {
        while(!SPI1TXIF) continue; // wait for room in the buffer. 1 = OK to write, 0 = full
        SPI1TXB = LED_Array[i];
    }
    __delay_us(4);  // Wait for final xmission
    SPI1CON0bits.EN = 0;
}  // end Write LEDs

void Write_LEDs_Delay(void)
// This routine adds a 250us delay at the end to latch the data - use it if you are not sure you will have 250us between updates
{
    uint8_t i;
    
    // Write out array values to LEDs
    SPI1CON0bits.EN = 1;
    //SPI1TCNTL = (uint8_t)(NUM_LEDS*12);  // With packed bytes, we only need half  (4 leds = 48 bytes)
    SPI1TCNTL = 48;  // With packed bytes, we only need half  (4 leds = 48 bytes)
    for(i=0; i<NUM_LEDS; i++)  // Write Array
    {
        while(!SPI1TXIF) continue; // wait for room in the buffer. 1 = OK to write, 0 = full
        SPI1TXB = LED_Array[i];
    }
    __delay_us(4);  // Wait for final xmission
    SPI1CON0bits.EN = 0;
    __delay_us(250);
}  // end Write LEDs

void loop(void)
{
    /* just loop */
}