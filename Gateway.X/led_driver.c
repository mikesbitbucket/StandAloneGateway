/*
 * File:   led_driver.c
 * Author: Matthew Shannon
 *
 * Created on March 16, 2021
 */
#include <stdint.h>
#include "mcc_generated_files\mcc.h"

#define DRIVE_OFFSET        0
#define BLUE_OFFSET         1
#define GREEN_OFFSET        2
#define RED_OFFSET          3
#define BLOCK_SIZE          28
#define START_FRAME_SIZE    4
#define END_FRAME_SIZE      4
#define START_FRAME_VALUE   0x00
#define END_FRAME_VALUE     0xFF
#define MAX_DRIVE_VALUE     31
#define GLOBAL_HEADER_MASK  0b11100000

uint8_t block[BLOCK_SIZE];

uint8_t led_offsets[] = {
    4,  /* LED 1 */
    8,  /* LED 2 */
    12, /* LED 3 */
    16, /* LED 4 */
    20, /* LED 5 */
};

/*
 */
void set_start_frame(void)
{
    uint8_t i;
    
    for (i = 0; i < START_FRAME_SIZE; i++ ){
        block[i] = START_FRAME_VALUE;
    }
}


/*
 */
void set_end_frame(void)
{
    uint8_t i;
    
    for (i = BLOCK_SIZE - END_FRAME_SIZE; i < BLOCK_SIZE; i++){
        block[i] = END_FRAME_VALUE;
    }
}


/*
 */
void set_led_value(uint8_t led, uint8_t drive, uint8_t blue, uint8_t green, uint8_t red)
{
    uint8_t led_offset = led_offsets[led - 1];
    
    if(drive > MAX_DRIVE_VALUE) drive = MAX_DRIVE_VALUE;
    drive = drive | GLOBAL_HEADER_MASK;
    
    block[led_offset + DRIVE_OFFSET] = drive;
    block[led_offset + BLUE_OFFSET]  = blue;
    block[led_offset + GREEN_OFFSET] = green;
    block[led_offset + RED_OFFSET]   = red;
}

/*
 */
void write_leds(void)
{
    //SPI1_WriteBlock(block, BLOCK_SIZE);
}