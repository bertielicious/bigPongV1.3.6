#include "config.h"

void configTMR1(void)
{
   TMR1H = 0x00;
   TMR1L = 0x00;
   T1CONbits.TMR1CS0 = LO;
   T1CONbits.TMR1CS1 = LO;    // instruction clock is source Fosc/4 = 250kHz
    
   T1CONbits.T1CKPS1 = LO;      //prescaler 1:1 16.3ms between interrupts 60Hz frame rate
   T1CONbits.T1CKPS0 = LO; 
   
   PIE1bits.TMR1IE = HI;
   INTCONbits.PEIE = HI;
   INTCONbits.GIE = HI;
   PIR1bits.TMR1IF = LO;      // clear TMR1 interrupt flag
   T1CONbits.TMR1ON = LO;
}
