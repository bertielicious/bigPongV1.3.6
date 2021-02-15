#include "config.h"
void configTMR0(void)
{
    INTCONbits.GIE = HI;        // enable interrupts
    OPTION_REGbits.TMR0CS = LO; //Timer mode
    OPTION_REGbits.PSA = LO;    // enable pre-scaler
    OPTION_REGbits.PS0 = HI;
    OPTION_REGbits.PS1 = HI;
    OPTION_REGbits.PS2 = HI;
    INTCONbits.TMR0IE = HI;     // enables TMR0 interrupt
    TMR0=0x00;                  // TMR0 starts counting from 0
    INTCONbits.TMR0IF = LO;     // 
    
}
