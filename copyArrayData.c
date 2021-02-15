#include "config.h"
#include "arrays.h"
void copyArrayData(uchar data, uchar rowx, uchar column)
{
    gameArray[rowx][column] = gameArray[rowx][column]|data;
   // printf("%d  %d    %d\n", data, row, gameArray[row][col]);
}

