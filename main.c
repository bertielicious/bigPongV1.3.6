/*
 * File:   main.c
 * Author: Phil Glazzard
 *
 * Created on 13 November 2020, 18:52
 */


#include <pic16f1459.h>

#include "config.h"
#include "main.h"
#include "configPorts.h"
#include "configOsc.h"
#include "configSPI.h"
#include "configTMR1.h"
#include "configTMR0.h"
#include "init1_max7219.h"
#include "init2Max7219.h"
#include "configUsart.h"
#include "sendSPIbyte.h"
#include "sendNoSPIbyte.h"
#include "clearScreen.h"
#include "splashScreen.h"
#include "arrays.h"
#include "gameState.h"
#include "pong.h"
#include "writeMatrix.h"
#include "paddleMove.h"
#include "clearGameArray.h"
int main(void) 
{
    configPorts();
    configOsc();
    configSPI();
    init1_max7219();
    init2Max7219();
    configUsart();
    configTMR1();
    configTMR0();
    
    
   uchar paddlePos1 = 3; // Left paddle starting position - paddlePos can be 1-6, l lowest position, 6 highest position
   uchar paddlePos2 = 4; // Right paddle starting position 
   
   uchar state = 0;
   
   printf("Hello Phil\n");
    
   clearScreen();
 
    
 
while(1)
    {   
   // printf("%d\n", scoreL);
    while(state <6)
    {
        state = gameState(state);// sets plyr1 or plyr2 mode
        printf("state %d\n", state);
    }
    
   // if(scoreLeft != scoreLeft)
      //  printf("scoreLeft %d\n", scoreLeft);
    if(T1CONbits.TMR1ON == LO)
    {
        printf("scoreRight %d\n", scoreRight);
        clearGameArray();
        gameState(5);
    }
    
        paddleMove(paddlePos1, 0);  // display left paddle at column 0
        if(RPB1 ==LO && LPB1==HI && paddlePos1<6 && paddlePos1>=0)
        {
            while(RPB1!=HI);
           __delay_ms(1);
            paddlePos1++;            // paddle moves up
        }
        else if(LPB1 ==LO && RPB1==HI && paddlePos1<=6 && paddlePos1>1)
        {
            while(LPB1!=HI);
             __delay_ms(1);
            paddlePos1--;            // paddle moves down
        }
        if(plyrSelect == LO)
        {
            paddlePos2 = 8;
            paddleMove(paddlePos2, 15);
            continue;
        }
        else
        {
        paddleMove(paddlePos2, 15); // display right paddle at column 15
        if(RPB2 ==LO && LPB2==HI && paddlePos2<6 && paddlePos2>=0)
        {
            while(RPB2!=HI);
             __delay_ms(1);
            paddlePos2++;            // paddle moves up
        }
        else if(LPB2 ==LO && RPB2==HI && paddlePos2<=6 && paddlePos2>1)
        {
            while(LPB2!=HI);
             __delay_ms(1);
            paddlePos2--;            // paddle moves down
        }
        }
      
        
    
    }
    return 0;
}
    

   
