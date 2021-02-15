#include "config.h"
#include "main.h"
#include "arrays.h"
#include "clearScreen.h"
#include "paddleMove.h"
#include "writeMatrix.h"
#include "gameState.h"
#include <stdio.h>
static volatile char icol = 7;
static volatile char irow = 4;
static volatile char xSpeed = 1;
static volatile char ySpeed = 1;
static volatile bool ballInt = HI;
static volatile bool eraseInt = LO;
static volatile uchar scoreL = 0;
static volatile uchar scoreR = 0;
char padCol, padRow;
void interrupt isr(void)
{   
    if(PIR1bits.TMR1IF == HI && ballInt == HI && eraseInt == LO)
    {
        
        icol = icol + xSpeed;
        irow = irow + ySpeed;
        
        gameArray[irow][icol]= 1;
        
        if((gameArray[irow][0] && gameArray[irow][1] == 1) || (gameArray[irow][14] && gameArray[irow][15] == 1))
        {
          xSpeed = -xSpeed;
        }
        
        if((icol == 1 && (gameArray[irow][0] && gameArray[irow][1]) == 0)) //|| (icol == 14 && (gameArray[irow][15] && gameArray[irow][14]) == 0))
        {
           
           T1CONbits.TMR1ON = LO;
           GIE = LO;
           scoreR = scoreR +1;
           scoreRight = scoreR;
           
           icol = 13;
           irow = 4;
        }
        if(irow <1 || irow>=7)
        {
            ySpeed = -ySpeed;   
        }

        writeMatrix();
        //printf("irow %d  icol %d\n", irow, icol);
                   
        ballInt = LO;
        eraseInt = HI;
    
    if(PIR1bits.TMR1IF == HI && ballInt == LO && eraseInt == HI)
    {
        
                    if(gameArray[irow][icol]==1)
                    { 
                        gameArray[irow][icol] = 0x00;// clear row 0 of previous paddle position data
                        
                    }
                 
         
        ballInt = HI;
        eraseInt = LO;
    }
    
    TMR1H = 0x00;
    TMR1L = 0x00;
    DIAGNOSTIC_LED = ~DIAGNOSTIC_LED;
    PIR1bits.TMR1IF = LO;
    } 
    if(INTCONbits.T0IF == 1)
    {
        padCol = 0;
        for(padRow = 0; padRow < 8; padRow++)
        {
            gameArray[padRow][padCol] = 0;
        }
        padCol = 15;
        for(padRow = 0; padRow < 8; padRow++)
        {
            gameArray[padRow][padCol] = 0;
        }
        
    }
    TMR0 = 0x00;
    INTCONbits.T0IF = 0;
}