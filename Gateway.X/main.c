/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F15Q41
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "usercode.h"



uint8_t i,j,k;


/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

 //   i = SPI1_Open(0);
    
    SPI1INTFbits.TCZIF = 0; // Reset Zero Flag
    
 //   SPI1CON0bits.EN = 1;
    
    while (1)
    {
        // Add your application code
        
        
        Write_LED_Array(255, 0, 0);
        Write_LEDs();
        __delay_ms(500);
//        //__delay_ms(500);
        Write_LED_Array(255, 255, 0);
        Write_LEDs();
        __delay_ms(500);
        //__delay_ms(500);
        Write_LED_Array(0, 255, 0);
        Write_LEDs();
        __delay_ms(500);
//       // __delay_ms(500);
        Write_LED_Array(0, 255, 255);
        Write_LEDs();
        __delay_ms(500);
        //__delay_ms(500);
        Write_LED_Array(0, 0, 255);
        Write_LEDs();
        __delay_ms(500);
        //__delay_ms(500);
        Write_LED_Array(255, 0, 255);
        Write_LEDs();
        __delay_ms(500);
//        //__delay_ms(500);
        
        
//        // Try using the buffer full, etc.
//        SPI1CON0bits.EN = 1;
//        SPI1TCNTL = 48;  // With packed bytes, we only need half
//        for(j=0; j<4; j++) // Led loop
//        {
//            for(i=0; i<4; i++)  // Red Loop
//            {
//                while(!SPI1TXIF) continue; // wait for room in the buffer. 1 = OK to write, 0 = full
//                SPI1TXB = LED0;
//            }
//            for(i=0; i<4; i++)  // Green Loop
//            {
//                while(!SPI1TXIF) continue; // wait for room in the buffer. 1 = OK to write, 0 = full
//                SPI1TXB = LED0;
//            }
//            for(i=0; i<4; i++)  // Blue Loop
//            {
//                while(!SPI1TXIF) continue; // wait for room in the buffer. 1 = OK to write, 0 = full
//                SPI1TXB = LED1;
//            }
//        }
//        SPI1CON0bits.EN = 0;
//        __delay_us(500);  // Latch it
        
        
        
//        // This works - still has the data left in weird mode
//        SPI1CON0bits.EN = 1;
//        //i = SPI1RXB;
//        while(SPI1STATUSbits.TXBE == 0) continue;
//        SPI1TCNTL = 1;
//        SPI1TXB = 0x55;
//        //while(SPI1INTFbits.TCZIF == 0) continue;  // wait for flag to be set saying it is empty
//        //SPI1INTFbits.TCZIF = 0; // Reset Zero Flag
//        //i = SPI1RXB;
//        while(SPI1STATUSbits.TXBE == 0) continue;
//        SPI1TCNTL = 1;
//        SPI1TXB = 0xAA;
//        //while(SPI1INTFbits.TCZIF == 0) continue;  // wait for flag to be set saying it is empty
//        //SPI1INTFbits.TCZIF = 0; // Reset Zero Flag
//        //i = SPI1RXB;
//        while(SPI1STATUSbits.TXBE == 0) continue;
//        SPI1TCNTL = 1;
//        SPI1TXB = 0x81;
//        //while(SPI1INTFbits.TCZIF == 0) continue;  // wait for flag to be set saying it is empty
//        //SPI1INTFbits.TCZIF = 0; // Reset Zero Flag
//        //i = SPI1RXB;
//        while(SPI1STATUSbits.TXBE == 0) continue;
//        SPI1TCNTL = 1;
//        SPI1TXB = 0x81;
//        //while(SPI1INTFbits.TCZIF == 0) continue;  // wait for flag to be set saying it is empty
//        //SPI1INTFbits.TCZIF = 0; // Reset Zero Flag
//        SPI1CON0bits.EN = 0;
        
        
        
        
        
//        //i = SPI1RXB;
//        //while(SPI1STATUSbits.TXBE == 0) continue;
//        SPI1TCNTL = 1;
//        SPI1TXB = 0x55;
//        while(SPI1INTFbits.TCZIF == 0) continue;  // wait for flag to be set saying it is empty
//        SPI1INTFbits.TCZIF = 0; // Reset Zero Flag
//        //i = SPI1RXB;
//        //while(SPI1STATUSbits.TXBE == 0) continue;
//        SPI1TCNTL = 1;
//        SPI1TXB = 0xAA;
//        while(SPI1INTFbits.TCZIF == 0) continue;  // wait for flag to be set saying it is empty
//        SPI1INTFbits.TCZIF = 0; // Reset Zero Flag
//        //i = SPI1RXB;
//        //while(SPI1STATUSbits.TXBE == 0) continue;
//        SPI1TCNTL = 1;
//        SPI1TXB = 0x81;
//        while(SPI1INTFbits.TCZIF == 0) continue;  // wait for flag to be set saying it is empty
//        SPI1INTFbits.TCZIF = 0; // Reset Zero Flag
//        //i = SPI1RXB;
//        //while(SPI1STATUSbits.TXBE == 0) continue;
//        SPI1TCNTL = 1;
//        SPI1TXB = 0x81;
//        while(SPI1INTFbits.TCZIF == 0) continue;  // wait for flag to be set saying it is empty
//        SPI1INTFbits.TCZIF = 0; // Reset Zero Flag
        

//        i = SPI1_ExchangeByte(0x55);
//        i = SPI1_ExchangeByte(0xAA);
//        i = SPI1_ExchangeByte(0x55);
//        i = SPI1_ExchangeByte(0xAA);
//        i = SPI1_ExchangeByte(0x55);
//        i = SPI1_ExchangeByte(0xAA);
        
//        while(SPI1CON2bits.BUSY) continue;
//        SPI1TCNTL = 1;
//        SPI1TXB = 0x55;
//        while(SPI1CON2bits.BUSY) continue;
//        SPI1TCNTL = 1;
//        SPI1TXB = 0xAA;
        
    }
}
/**
 End of File
*/