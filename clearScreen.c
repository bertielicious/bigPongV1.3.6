/*
 * File:   clearScreen.c
 * Author: Phil Glazzard
 *
 * Created on 26 October 2020, 21:19
 */


#include "config.h"
#include "sendSPIbyte.h"
#include "sendNoSPIbyte.h"

void clearScreen(void) 
{
    uchar row, col;
        for(row = 1; row <9; row++)
        {
         col = 0;  
         CS = LO;
         sendNoSPIbyte();           // write to left LED matrix
         sendSPIbyte(row, col);      
         CS = HI;
         
         CS = LO;
         sendSPIbyte(row, col);    
         sendNoSPIbyte();           // write to right LED matrix  
         CS = HI; 
        }   
}
