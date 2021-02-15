/*
 * File:   clearGameArray.c
 * Author: Phil Glazzard
 *
 * Created on 06 December 2020, 19:52
 */


#include "config.h"
#include "arrays.h"

void clearGameArray(void) {
    uchar row, col = 0;
    for(row=0; row<8;row++)
    {
        for(col=0;col<16;col++)
        {
            gameArray[row][col]=0;
        }       
    }
}
