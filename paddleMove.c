#include "config.h"
#include "copyArrayData.h"
void paddleMove(uchar padPos, uchar column)
{
uchar padRow;
bool pad1[8]={0,0,0,0,0,1,1,1};     // paddle at bottom position
bool pad2[8]={0,0,0,0,1,1,1,0};
bool pad3[8]={0,0,0,1,1,1,0,0};
bool pad4[8]={0,0,1,1,1,0,0,0};
bool pad5[8]={0,1,1,1,0,0,0,0};
bool pad6[8]={1,1,1,0,0,0,0,0};     // paddle at top position
bool clear[8]={0,0,0,0,0,0,0,0};
bool wall[8]={1,1,1,1,1,1,1,1};     // RHS wall
        switch(padPos)
        {
                case 1:
                    
                    for(padRow=0; padRow<8; padRow++)
                    {
                        copyArrayData(pad1[padRow],padRow, column);
                    }
                    
                    break;

                case 2:
                    
                    for(padRow=0; padRow<8; padRow++)
                    {
                        copyArrayData(pad2[padRow],padRow, column);
                    }
                    
                    break;
                case 3:
                    
                    for(padRow=0; padRow<8; padRow++)
                    {
                        copyArrayData(pad3[padRow],padRow, column);
                    }
                    
                    break;
                case 4:
                    
                    for(padRow=0; padRow<8; padRow++)
                    {
                        copyArrayData(pad4[padRow],padRow, column);
                    }
                    
                    break;
                case 5:
                    
                    for(padRow=0; padRow<8; padRow++)
                    {
                        copyArrayData(pad5[padRow],padRow, column);
                    }
                   
                    break;
                case 6:
                    
                    for(padRow=0; padRow<8; padRow++)
                    {
                        copyArrayData(pad6[padRow],padRow, column);
                    }
                   
                    break;
                    
                case 7:
                    
                    for(padRow=0; padRow<8; padRow++)
                    {
                        copyArrayData(clear[padRow],padRow, column);
                    }
                   
                    break;
                case 8:
                    
                    for(padRow=0; padRow<8; padRow++)
                    {
                        copyArrayData(wall[padRow],padRow, column);
                    }
                   
                    break;
        }
}
