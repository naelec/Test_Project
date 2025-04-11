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
   
    while (1) {
    P1OUT |= 0x01;  // P1.0 High
    __delay_cycles(100000);
    P1OUT &= 0xFE; //P1.0 Low
    __delay_cycles(100000);
    }
}
