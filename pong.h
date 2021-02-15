/* 
 * File:   pong.h
 * Author: Phil Glazzard
 *
 * Created on 19 November 2020, 20:42
 */

//#pragma once

     typedef struct
     {  bool padLeft[8];
        bool padRight[8];
        bool ballPosn[1][1];
        bool collisionLeft[8][1];
        bool collisionRight[8][1];
        uchar scoreLplyr;
        uchar scoreRplyr;   
    }game;
 game var;


