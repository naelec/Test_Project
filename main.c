#include "msp430.h"

//******************************************************************************
//!
//!   Empty Project that includes driverlib
//!
//******************************************************************************
void main (void)
{
    WDTCTL = WDTPW | WDTHOLD; //Hold Watch dog
    P1DIR = 0x01; //PIN1.0 is output
    P4DIR = 0b10000000; //PIN4.7 is output
    P1REN  = 0b00000010; //Pull up resistor at P1.1
    P1OUT |= 0b00000010; //Pull up resistor at P1.1
   
   while (1) {
        P4OUT |= 0b10000000; //Output P4.7 (LED2) Off LED (active low)        
        if (!(P1IN & BIT1)) {   // If P1.1 is LOW (switch pressed)
            __delay_cycles(10000);  //Debouce delay
            while (!(P1IN & BIT1)); //Wait switch release
            P1OUT ^= BIT0;     // 
        }
        __delay_cycles(100000);
        P4OUT = 0x00;    //On LED
        __delay_cycles(100000);
   }      
}
