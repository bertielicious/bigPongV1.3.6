#include "config.h"
#include "sendNoSPIbyte.h"
#include "sendSPIbyte.h"
void printDigit(uchar rowL, uchar rowH, uchar *ptr)
{
    uchar row;
    for(row = rowL; row<=rowH; row++)
    {
        CS = LO;
        sendNoSPIbyte();
    
        sendSPIbyte(row, *ptr);
        CS = HI;
    ptr++;
    }  
}
