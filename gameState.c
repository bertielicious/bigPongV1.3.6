#include "config.h"
#include "clearScreen.h"
#include "clearGameArray.h"
#include "arrays.h"
#include "splashScreen.h"
#include "writeMatrix.h"
#include "printDigit.h"
#include "paddleMove.h"
#include "configTMR0.h"
#include "configTMR1.h"
#include <stdio.h>
uchar gameState(uchar state)// PONG FSM
{                                           
   
    switch(state)
    {
        case 0:
            state = 1;// reset state
            break;
        case 1:
            clearScreen();
            splashScreen(splishR, splishL);// display "PONG" for 2 sec
            __delay_ms(200);
             clearScreen();
            state = 2;
            break;
            
        case 2 :
            splashScreen(plyL, plyR);// display L 1 R 2 player
            while(LPB1&&RPB1==HI);     // wait for player selection button press
            if(LPB1==LO&&RPB1==HI)     // L = 1 plyr, R = 2 plyr
            {
                state = 3;
            }
            else if(LPB1==HI&&RPB1==LO)
            {
                state = 4;
            }
            clearScreen();
            break;
            
        case 3:
            plyrSelect = LO;    // single player mode enabled         
            state = 5;
            break;
           
        case 4:
            plyrSelect = HI;    // dual player mode enabled      
            state = 5;
            break;
            
        case 5:
            
            printDigit(6,8,tres);
            __delay_ms(100);
            printDigit(6,8,dos);
            __delay_ms(100);
            printDigit(6,8,uno);
            __delay_ms(100);
            printDigit(6,8,cero);
            __delay_ms(100);
            printDigit(6,8,null);
            clearScreen();
            INTCONbits.GIE = HI;
            T1CONbits.TMR1ON = HI;// start interrupt routine (bouncing ball))
            state = 6;
            break;
        case 6:
            
             // return control to main function
           
            break;
    }   
    return state;
}